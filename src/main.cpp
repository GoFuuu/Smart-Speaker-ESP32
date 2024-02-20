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
int32_t communicationData[1024];    //接收缓冲区 然而，int32_t 类型的元素的大小是 4 字节（32 位）。数组的总大小是 1024 * 4 = 4096 字节。
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


bool sendOver=1;//发送完成标志位
bool recOver=0;//接受完成标志位
bool speakOut;//0代表对外讲话，1代表收听
int32_t *samples_32bit;//读出来的原始32位数据，长度128
int16_t *samples_16bit;//转换后的16位数据，长度128
uint8_t *samples_8bit ;//转换后的8位数据，长度128
int16_t *recive_16bit;//接收后转换的16位数据，长度128
int16_t *output_16bit;//发送给扬声器的16位数据，长度256，因为传入数据是双声道所以*2


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
  //.channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,设置了左右声道分离
  //测试只更改only right时会导致声音变快，数据损失 
  /*
  typedef enum {
    I2S_CHANNEL_FMT_RIGHT_LEFT,         /*!< Separated left and right channel  正常
    I2S_CHANNEL_FMT_ALL_RIGHT,          /*!< Load right channel data in both two channels  正常
    I2S_CHANNEL_FMT_ALL_LEFT,           /*!< Load left channel data in both two channels 正常
    I2S_CHANNEL_FMT_ONLY_RIGHT,         /*!< Only load data in right channel (mono mode)  声音变快
    I2S_CHANNEL_FMT_ONLY_LEFT,          /*!< Only load data in left channel (mono mode) 无声音
  */
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
      if(i%2 == 0)  //这里获取到的数据第一个Int32是左声道 是左声道的样本。第二个Int32是右声道 是右声道的样本。
      {
        //I2S_BITS_PER_SAMPLE_32BIT下四个字节是一个数据位 在偶数条件下 p[4*i] 和 p[4*i + 1] 低位噪声p[4*i + 2] 和 p[4*i + 3]高位信息 
          partWavData[i] = p[4*i + 2 ];
          partWavData[i+1] = p[4*i + 3];
      }
    }
    file.write((const byte*)partWavData, 1024);
  }
  file.close();
  digitalWrite(LED, HIGH); 
  Serial.println("recordfinish");
  ESP.restart();//重启
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
  // if(!sd.begin(SdSpiConfig(5, DEDICATED_SPI, 18000000)))
  // {
  //   Serial.println("init sd card error");
  //   return;
  // }
  // 初始化I2S
  
  samples_16bit = (int16_t *)malloc(sizeof(int16_t) * 128);
  samples_8bit =  (uint8_t *)malloc(sizeof(uint8_t) * 128);
  if(!mi.InitInput(I2S_BITS_PER_SAMPLE_32BIT, ICS_SCK, ICS_WS, ICS_SD))
  {
    Serial.println("init i2s error");
    return;
  }
  // 初始化WiFi连接
  connectToWiFi();

  // 初始化MQTT连接
   client.setServer(mqtt_server, mqtt_port);
   client.setCallback(callback);
}

bool  BtnisPressed(void)//按键是否按下
{
  bool key=digitalRead(RECORD);
  if(1==key)
  {
    return 0;
  }
  else
  {
    return 1 ;
  }
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
      //client.publish("test", "hello world");
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

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  //unsigned long now = millis();
  // if (now - lastMsg > 2000) {
  //   lastMsg = now;
  //   ++value;
  //   snprintf (msg, MSG_BUFFER_SIZE, "hello world #%ld", value);
  //   Serial.print("Publish message: ");
  //   Serial.println(msg);
  //   client.publish("test", msg);
  // }
if(BtnisPressed())//按下按键发射数据
  {
    //Serial.println("Record_Pressed");
    digitalWrite(LED, LOW);
    speakOut=0;
    int samples_read = mi.I2Sread(samples_16bit,128);//读取数据
    mi.covert_bit(samples_16bit,samples_8bit,samples_read);//发送时转换为8位
   // Serial.println("recordfinish");
    //sendData(samples_8bit,samples_read);//发射数据
    //samples_read 为128
    boolean istrans = client.publish("test", samples_8bit,samples_read);
    if(istrans)
    {
      Serial.println("publish finish");
    }
    else
    {
      Serial.println("publish failed");
    }
    
  }
  else//接收数据，接受部分在回调函数中
  {
    digitalWrite(LED,HIGH);//发射时开灯
    // delay(28);//经过一段延时再判断，接收数据并且播放也需要时间
    // speakOut=1;
    // if(recOver)
    // {
    //   recOver=0;
    //   if(digitalRead(LED))//接受数据时闪烁LED
    //   {
    //       digitalWrite(LED,LOW);
    //   }
    //   else
    //   {
    //       digitalWrite(LED,HIGH);
    //   }
    // }
    // else
    // {
    //   digitalWrite(LED,LOW);//没有接收到消息，也没有发射，关灯
    //   i2s_zero_dma_buffer(SPK_I2S_PORT);//清空DMA中缓存的数据，你可以尝试一下不清空（注释这行）是什么效果
    // }
  }

}

