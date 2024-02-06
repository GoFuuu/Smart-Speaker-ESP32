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

SdFs sd;      // sd卡
FsFile file;  // 录音文件

// 13录音，io14播放
#define PLAY 13
#define RECORD 14
#define LED 2

// 判断按钮是否被按过
int key1 = 0;
int key2 = 0;

MyI2S mi;
const char filename[] = "/my.wav";


const int record_time = 5;  // second录音5秒
const int waveDataSize = record_time * 88200;
int32_t communicationData[1024];     //接收缓冲区
char partWavData[1024];


int16_t buffer[1024];        //接收缓冲区
int16_t playData[2048];   //发往I2S的缓冲区

// WiFi配置
const char *ssid = "二楼";
const char *password = "1234567890";


// 服务器配置
const char *serverUrl = "http://139.155.158.174:8001/api/audio/";


// 其他定义
WiFiClient wifiClient;

void connectToWiFi() {
    Serial.println("Connecting to WiFi...");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
}

String sendAudioToServerAndGetUrl() {
    // 打开音频文件
    file = sd.open(filename, O_READ);
    if (!file) {
        Serial.println("Error opening audio file");
        return "";
    }


    HTTPClient http;
    Serial.println("init HTTP");
    http.begin(wifiClient, serverUrl);
    http.addHeader("content-type", "multipart/form-data");

    int bytesRead;
    uint8_t buffer[128];
    bytesRead = file.readBytes((char*)buffer, sizeof(buffer));
    Serial.println("Sending data...1");
    if (bytesRead > 0) {
        Serial.println("Sending data...2");
        http.POST(buffer, bytesRead);
      
    }
    delay(100);  

    file.close();
    String serverResponse = http.getString();
    Serial.println("Server Response: " + serverResponse);
    http.end();
    Serial.println("HTTP close");

    return serverResponse;
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

  if(!mi.InitInput(I2S_BITS_PER_SAMPLE_32BIT, 4, 22, 34))
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

void postTest(){
  file = sd.open(filename, O_READ);
  if(!file)
  {
    Serial.println("crate file error");
    return;
  }
  
  const size_t bufferSize = 1024;
HTTPClient http;

  // Specify the server endpoint
  http.begin(serverUrl);

  // Set the Content-Type header to indicate the type of data being sent
  http.addHeader("Content-Type", "multipart/form-data","boundary=--------------------------507255100017623358517301");

  // Allocate memory for a buffer to read chunks of the file
  uint8_t *buffer = (uint8_t *)malloc(bufferSize);

  if (!buffer) {
    Serial.println("Failed to allocate memory");
    http.end();
    return;
  }

  // Read and send the file in chunks
  size_t bytesRead;
  while ((bytesRead = file.read(buffer, bufferSize)) > 0) {
    // Send the chunk to the server
    int httpCode = http.POST(buffer, bytesRead);

    // Check for a successful response
  if (httpCode > 0) {
    Serial.printf("[HTTP] POST request successful, response code: %d\n", httpCode);
    String payload = http.getString();
    Serial.println("Response payload: " + payload);
  } else {
    Serial.printf("[HTTP] POST request failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  }

  // End the HTTP connection
  http.end();

  // Free the allocated memory
  free(buffer);

  

  
}

void sendFileToServer() {
  // Create an HTTPClient object
  HTTPClient http;

  // Specify the server endpoint
  http.begin(serverUrl);

  // Set the Content-Type header to indicate the type of data being sent
  http.addHeader("Content-Type", "multipart/form-data");

  // Create a buffer for reading file content
  uint8_t buffer[512];

  // Send the POST request with the file content as payload
  int httpCode = http.POST( buffer, file.size());

  // Check for a successful response
  if (httpCode > 0) {
    Serial.printf("[HTTP] POST request successful, response code: %d\n", httpCode);
    String payload = http.getString();
    Serial.println("Response payload: " + payload);
  } else {
    Serial.printf("[HTTP] POST request failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  // End the HTTP connection
  http.end();
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

}


void loop() {
  if (!digitalRead(PLAY)) {
    delay(5);//防抖
    if (!digitalRead(PLAY)) 
    {
        if (key1 == 0) {
          //getTest();
          postTest();
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

