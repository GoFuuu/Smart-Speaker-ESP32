/*
 IO标注:
 io13（按钮1），io14（按钮2）
 io2（LED）
 io27（MAX98357-BCLK），io32（MAX98357-LRC），io33（MAX98357-DIN）
 io4（ICS-43434-SCK），io22（ICS-43434-WS），io34（ICS-43434-SD）
 io23（SD-MOSI），io19（SD-MISO），io18（SD-SCK），io5（SD-CS）
*/
#include <WiFi.h>
#include <PubSubClient.h>
#include <SPI.h>
#include <SdFat.h>
#include "MyI2S.h"
#include "wave.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <LittleFS.h>
#include <base64.h> 
#include <FS.h>
#include <SPIFFS.h> 

SdFs sd;      // sd卡
FsFile file;  // 录音文件

// 13录音，io14播放
#define PLAY 13
#define RECORD 14
#define LED 2
#define ICS_SCK 4
#define ICS_WS 22
#define ICS_SD 34
// 判断按钮是否被按过
int key1 = 0;
int key2 = 0;

MyI2S mi;
const char filename[] = "/my.wav";


const int record_time = 5;  // second录音5秒
//每秒的数据量就是 1（通道）* 44100 采样率（样本/秒）* 2（16位）（字节/样本）= 88200 字节/秒
const int waveDataSize = record_time * 88200;
int32_t communicationData[1024];     //接收缓冲区
char partWavData[1024];


int16_t buffer[1024];        //接收缓冲区
int16_t playData[2048];   //发往I2S的缓冲区

// WiFi配置
const char *ssid = "二楼";
const char *password = "1234567890";
// const char *ssid = "14pro";
// const char *password = "1234567890";

// 服务器配置
const char *serverUrl = "http://139.155.158.174:8001/api/audio/";
const char* mqtt_server = "139.155.158.174";
unsigned int mqtt_port = 1883;
const char *mqtt_user = "ubuntu";
const char *mqtt_password = "1";
// 其他定义
WiFiClient wifiClient;
PubSubClient client(wifiClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE	(50)
char msg[MSG_BUFFER_SIZE];
int value = 0;

void connectToWiFi() {
    Serial.println(ssid);
    Serial.println(password);
    Serial.println("Connecting to WiFi...");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
}

void play()
{
    //打开文件
  file = sd.open(filename, O_READ);
  if(!file)
  {
    Serial.println("crate file error");
    return;
  }

  //跳过WAV头部直接到数据部分
  file.seek(sizeof(WAV_HEADER));

  if(!mi.InitOutput(I2S_BITS_PER_SAMPLE_16BIT, 27, 32, 33))
  {
    Serial.println("init i2s error");
    return;
  }

  Serial.println("playstart");
  digitalWrite(LED, LOW); 

  int recvSize = 0;
  do
  {
    recvSize =  file.read((void*)buffer, 1024);
    for(int i = 0;i<recvSize/2;i++)
    {
      playData[2*i] = buffer[i];   //左声道
      playData[2*i+1] = buffer[i];  //右声道
    }

    mi.Write((char*)playData, recvSize*2);
  }while(recvSize>0);
  file.close();
  mi.End();
    digitalWrite(LED, HIGH); 
  Serial.println("playfinish");
}

void record()
{
  //删除并创建文件

  sd.remove(filename);
  file = sd.open(filename, O_WRITE|O_CREAT);
  if(!file)
  {
    Serial.println("crate file error");
    return;
  }

  auto header = CreateWaveHeader(1, 44100, 16);
  header.riffSize = waveDataSize + 44 - 8;
  header.dataSize = waveDataSize;
  file.write(&header, 44);

  if(!mi.InitInput(I2S_BITS_PER_SAMPLE_32BIT, ICS_SCK, ICS_WS, ICS_SD))
  {
    Serial.println("init i2s error");
    return;
  }

  Serial.println("recordstart");
   digitalWrite(LED, LOW);

  for (int j = 0; j < waveDataSize/1024; ++j) {
    auto sz = mi.Read((char*)communicationData, 4096);
    char*p =(char*)(communicationData);
    for(int i=0;i<sz/4;i++)
    {
      communicationData[i] *= 20;  //提高声音
      if(i%2 == 0)   //这里获取到的数据第一个Int32是右声道
      {
          partWavData[i] = p[4*i + 2];
          partWavData[i + 1] = p[4*i + 3];
      }
    }
    file.write((const byte*)partWavData, 1024);
  }
  file.close();
  digitalWrite(LED, HIGH); 
  Serial.println("recordfinish");
  ESP.restart();//重启
}

void getTest(){
  HTTPClient http;
  http.begin(serverUrl);
  int httpCode = http.GET();  
  if(httpCode > 0) {
            // HTTP header has been send and Server response header has been handled
            Serial.printf("[HTTP] GET... code: %d\n", httpCode);

            // file found at server
            if(httpCode == HTTP_CODE_OK) {
                String payload = http.getString();
                Serial.println(payload);
            }
        } else {
            Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();

}

void postTest() {

  // 打开WAV文件
  file = sd.open(filename, O_READ);
  if(!file)
  {
    Serial.println("crate file error");
    return;
  }
  // 获取WAV文件大小
  size_t wavFileSize = file.size();

  // 读取WAV文件内容到数组
  // 读取 WAV 文件内容到数组
uint8_t* wavData = new uint8_t[wavFileSize];
size_t bytesRead = file.read(wavData, wavFileSize);
file.close();

// 将二进制数据进行 Base64 编码
String base64WavData = base64::encode(wavData, wavFileSize);
delete[] wavData;

// 构建请求数据
String data = "{\"user_id\":\"wxl\",\"audio_type\":\"WAV\",\"audio_file\":\"" + base64WavData + "\"}";

// 开始 HTTP 请求
HTTPClient http;
http.begin(serverUrl);
http.addHeader("Content-Type", "application/json");

// 发送请求数据
int httpCode = http.POST(data);

// 处理服务器响应
if (httpCode > 0) {
  Serial.printf("HTTP POST request status code: %d\n", httpCode);

  if (httpCode == HTTP_CODE_OK) {
    String response = http.getString();
    Serial.println("Server response: " + response);
  }
} else {
  Serial.printf("HTTP POST request failed, error: %s\n", http.errorToString(httpCode).c_str());
}

// 关闭 HTTP 连接
http.end();
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') {
    digitalWrite(LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is active low on the ESP-01)
  } else {
    digitalWrite(LED, HIGH);  // Turn the LED off by making the voltage HIGH
  }

}

void setup() {
  Serial.begin(115200);
  pinMode(PLAY, INPUT_PULLUP);//定义按钮1
  pinMode(RECORD, INPUT_PULLUP);
  pinMode(LED,OUTPUT);
  digitalWrite(LED, HIGH);
  delay(500);

  // 初始化SD卡
  if(!sd.begin(SdSpiConfig(5, DEDICATED_SPI, 18000000)))
  {
    Serial.println("init sd card error");
    return;
  }

  // 初始化WiFi连接
  connectToWiFi();

  // 初始化MQTT连接
  // client.setServer(mqtt_server, mqtt_port);
  // client.setCallback(callback);
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str(),mqtt_user,mqtt_password)) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("test", "hello world");
      // ... and resubscribe
      client.subscribe("inTopic");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void loop() {

  //   if (!client.connected()) {
  //   reconnect();
  // }
  // client.loop();
  // unsigned long now = millis();
  // if (now - lastMsg > 2000) {
  //   lastMsg = now;
  //   ++value;
  //   snprintf (msg, MSG_BUFFER_SIZE, "hello world #%ld", value);
  //   Serial.print("Publish message: ");
  //   Serial.println(msg);
  //   client.publish("test", msg);
  // }
  
  if (!digitalRead(PLAY)) {
    delay(5);//防抖
    if (!digitalRead(PLAY)) 
    {
        if (key1 == 0) {
          //getTest();
          //postTest();
          //String audioUrl = sendAudioToServerAndGetUrl(); // 发送音频到服务器并获取URL
          play();
          key1 = 1;
        }
    }
  }
  else 
  {
    delay(5);
    key1=0;
  }


  if (!digitalRead(RECORD)) {
      delay(5);//防抖
      if (!digitalRead(RECORD)) {
        if (key2 == 0) {
          record();
          //sendAudioToTencentCloud(); // 发送音频到腾讯云
          key2 = 1;
        }
      }
  }
  else 
  {
    delay(5);
    key2=0;  
  }


}

