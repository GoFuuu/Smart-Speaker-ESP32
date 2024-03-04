/**
 * @file streams-i2s-webserver_wav.ino
 *
 *  This sketch reads sound data from I2S. The result is provided as WAV stream which can be listened to in a Web Browser
 *
 * @author Phil Schatzmann
 * @copyright GPLv3
 */

#include "AudioTools.h"
//#include "AudioCodecs/CodecMP3LAME.h"
#include "AudioCodecs/CodecMP3Helix.h"
#include <ArduinoMqttClient.h>
#define RESTART          13
const char* broker = "139.155.158.174"; 
int        port     = 1883;
const char *mqttUser = "ubuntu";
const char *mqttPassword = "1";
const char* topic  = "audio";
const char willTopic[] = "audio/will";
const char urlTopic[] = "audio/url";
uint8_t inPlay = 0;
WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);
//AudioEncodedServer server(new WAVEncoder(),"ssid","password");  
AudioWAVServer server("NUSRI-STU","Nusri311"); // the same a above
//MP3EncoderLAME mp3;
//AudioEncoderServer server(&mp3, "NUSRI-STU","Nusri311");
//AudioEncoderServer server(new MP3EncoderLAME(), "NUSRI-STU","Nusri311");
I2SStream i2sStream;    // Access I2S as stream
VolumeStream volume(i2sStream);
VolumeStreamConfig volumeConfig;
ConverterFillLeftAndRight<int16_t> filler(LeftIsEmpty); // fill both channels - or change to RightIsEmpty


URLStream url;
I2SStream i2sStreamOut; // final output of decoded stream
EncodedAudioStream dec(&i2sStreamOut, new MP3DecoderHelix()); // Decoding stream
StreamCopy copierOut(dec, url); // copy url to decoder

void setup(){
  Serial.begin(115200);
  pinMode(RESTART, INPUT_PULLUP);
  AudioLogger::instance().begin(Serial, AudioLogger::Info);

  // start i2s input with default configuration
  Serial.println("starting I2S...");
  auto config = i2sStream.defaultConfig(RX_MODE);
  config.i2s_format = I2S_STD_FORMAT; // if quality is bad change to I2S_LSB_FORMAT https://github.com/pschatzmann/arduino-audio-tools/issues/23
  config.sample_rate = 44100;
  config.channels = 1;
  config.bits_per_sample = 16;
  config.pin_bck = 4;
  config.pin_ws = 22;
  config.pin_data = 34;
  i2sStream.begin(config);
  auto volumeConfig =volume.defaultConfig();
  volumeConfig.allow_boost= true;
  volumeConfig.bits_per_sample = 16;
  volumeConfig.channels = 1;
  volumeConfig.sample_rate = 44100;
  volume.begin(volumeConfig);
  volume.setVolume(15);
  Serial.println("I2S_in started");

  
  // start data sink
  //server.begin(i2sStream, config, &filler);
  server.begin(volume, config, &filler);

  // setup i2s
  auto configOut = i2sStreamOut.defaultConfig(TX_MODE);
  // you could define e.g your pins and change other settings
  configOut.pin_bck = 27;
  configOut.pin_ws = 32;
  configOut.pin_data = 33;
  // configOut.sample_rate = 44100;
  // configOut.bits_per_sample = 16;
  // configOut.channels = 1;
  //config.mode = I2S_STD_FORMAT;
  i2sStreamOut.begin(config);
  Serial.println("I2S_out started");

  // setup I2S based on sampling rate provided by decoder
  dec.setNotifyAudioChange(i2sStreamOut);
  dec.begin();

  
}

// Arduino loop  
void loop() {
  // Handle new connections
  server.copy();  


      if (digitalRead(RESTART) == LOW) {
        ESP.restart();
    }
  if(inPlay == 1) {
    copierOut.copy();
  }
}
void connectMqtt() {
  //mqtt setup
  mqttClient.setId("esp32");
  mqttClient.setUsernamePassword(mqttUser, mqttPassword);

  //mqtt will message
  String willPayload = "connection lost";
  bool willRetain = true;
  int willQos = 1;
  mqttClient.beginWill(willTopic, willPayload.length(), willRetain, willQos);
  mqttClient.print(willPayload);
  mqttClient.endWill();

  Serial.print("Attempting to connect to the MQTT broker: ");
  Serial.println(broker);

  if (!mqttClient.connect(broker, port)) {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());

    while (1);
  }

  Serial.println("You're connected to the MQTT broker!");
  Serial.println();

  // set the message receive callback
  mqttClient.onMessage(onMqttMessage);

  Serial.print("Subscribing to topic: ");
  Serial.println(urlTopic);
  Serial.println();
  int subscribeQos = 2;
  mqttClient.subscribe(urlTopic, subscribeQos);

  // topics can be unsubscribed using:
  // mqttClient.unsubscribe(inTopic);

  Serial.print("Waiting for messages on topic: ");
  Serial.println(urlTopic);
  Serial.println();
}

void onMqttMessage(int messageSize) {
  // we received a message, print out the topic and contents
  Serial.print("Received a message with topic '");
  Serial.print(mqttClient.messageTopic());
  Serial.print("', duplicate = ");
  Serial.print(mqttClient.messageDup() ? "true" : "false");
  Serial.print(", QoS = ");
  Serial.print(mqttClient.messageQoS());
  Serial.print(", retained = ");
  Serial.print(mqttClient.messageRetain() ? "true" : "false");
  Serial.print("', length ");
  Serial.print(messageSize);
  Serial.println(" bytes:");
  // use the Stream interface to print the contents
  char* messageContent; 
  while (mqttClient.available()) {
    char c = (char)mqttClient.read(); 
    Serial.print(c);
    messageContent += c;  // 将字符添加到字符串的末尾
  }
  // 根据不同主题进行不同处理
    if(mqttClient.messageTopic() == urlTopic) {
        // 处理主题1的消息
        url.begin(messageContent);
        inPlay = 1;
    } 
  
  Serial.println();

  Serial.println();
}