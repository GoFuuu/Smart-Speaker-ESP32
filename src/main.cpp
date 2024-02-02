/*
  本程序用于测试以太网模块的好坏，同时给买家编程做参考。
  板子类型：esp32
  淘宝店铺：https://mtools.taobao.com
  旺旺：亲亲雨甄
  ESP32编程环境：版本要2.0以上（2.0以下不工作）
  开发板：ESP32 Dev Module
  烧写模式：QIO
  测试流程：板子已烧写本程序，板子插上正版SD卡，尽量不要太大容量，用typec给板子供电，按下按钮1录音五秒自动停止，再按下按钮2播放。这样就测试了按钮、录音、播放、SD卡储存的功能。

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

// 腾讯云MQTT配置
const char *tencentCloudBroker = "your_broker_url";
const int tencentCloudPort = 1883;
const char *tencentCloudUsername = "your_username";
const char *tencentCloudPassword = "your_password";
const char *tencentCloudTopic = "your_topic";

// 其他定义
WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);
void connectToWiFi() {
    Serial.println("Connecting to WiFi...");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
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
  mqttClient.setServer(tencentCloudBroker, tencentCloudPort);
}



void sendAudioToTencentCloud() {
  // 打开音频文件
  file = sd.open(filename, O_READ);
  if (!file) {
    Serial.println("Error opening audio file");
    return;
  }

  // 连接到腾讯云MQTT
  if (mqttClient.connect("ESP32Client", tencentCloudUsername, tencentCloudPassword)) {
    Serial.println("Connected to MQTT broker");

    // 发布音频数据到指定主题
    while (file.available()) {
      char buffer[128];
      int bytesRead = file.readBytes(buffer, sizeof(buffer));
      mqttClient.publish(tencentCloudTopic, buffer, bytesRead);
      delay(100);  // 延迟确保数据发送完整
    }

    // 关闭音频文件
    file.close();
  } else {
    Serial.println("MQTT connection failed");
  }
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

void loop() {
  if (!digitalRead(PLAY)) {
    delay(5);//防抖
    if (!digitalRead(PLAY)) 
    {
        if (key1 == 0) {
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

  //dealMqtt();

}
void dealMqtt()
{
  // 处理MQTT消息
  if (mqttClient.connected()) {
    mqttClient.loop();
  } else {
  // 如果连接断开，尝试重新连接
    mqttClient.connect("ESP32Client", tencentCloudUsername, tencentCloudPassword);
  }
}
