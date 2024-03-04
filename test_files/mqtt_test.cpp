/**
 * @file communication-mqtt-send.ino
 * @author Phil Schatzmann
 * @brief Send Audio File to MQTT.
 * I am using the ArduinoMQTTClient library from Arduino provided by the library manager.
 * We can just copy the audio data to the MQTT client!
 * @version 0.1
 * @date 2023-09-07
 * 
 * @copyright Copyright (c) 2023
 */

#include "WiFi.h"
#include "ArduinoMqttClient.h"
#include "AudioTools.h"
#define PLAY          13

#define SIZE 1024
#define N 100

// Communication
const char* ssid = "NUSRI-STU";    // your network SSID (name)
const char* password = "Nusri311";    // your network password (use for WPA, or use as key for WEP)
IPAddress ip = IPAddress(139, 155, 158, 174); // IP address of the MQTT broker (e.g.
const char* broker = "139.155.158.174"; 
const char* topic  = "/audio";
int        port     = 1883;
const char *mqtt_user = "ubuntu";
const char *mqtt_password = "1";
WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

// Audio
AudioInfo info(44100, 1, 16);
//AudioInfo info(8000, 1, 16);
// WhiteNoiseGenerator<int16_t> noise(32000);                        // subclass of SoundGenerator with max amplitude of 32000
// GeneratedSoundStream<int16_t> in_stream(noise);                   // Stream generated from noise
I2SStream i2s;  // Audio source
ConverterFillLeftAndRight<int16_t> filler(LeftIsEmpty); // fill both channels - or change to RightIsEmpty
EncodedAudioStream out_stream(&mqttClient, new WAVEncoder());     // encode as wav file
StreamCopy copier(out_stream, i2s, SIZE);                   // copies sound to MQTT client

// Connect to Wifi
void connectWIFI() {
  // attempt to connect to WiFi network:
  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }

  Serial.println("You're connected to the network");
  Serial.println();  
}

// Connect to MQTT Server
void connectMQTT() {
  // You can provide a unique client ID, if not set the library uses Arduino-millis()
  // Each client must have a unique client ID
  mqttClient.setId("AudioTools");
  mqttClient.setUsernamePassword(mqtt_user, mqtt_password);

  // You can provide a username and password for authentication
  // mqttClient.setUsernamePassword("username", "password");

  Serial.print("Attempting to connect to the MQTT broker: ");
  Serial.println(broker);

  if (!mqttClient.connect(broker, port)) {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());

    stop();
  }

  Serial.println("You're connected to the MQTT broker!");
  Serial.println();
}  

// Send audio to MQTT Server
void sendMQTT() {
    // make sure that we write wav header
      out_stream.begin(info);

      // send message, the Print interface can be used to set the message contents
       mqttClient.beginMessage(topic, SIZE * N, true);
      //mqttClient.beginMessage(topic, SIZE,false) ;

      // copy audio data to mqtt: 100 * 1024 bytes
      size_t copy_ture = copier.copy();

      Serial.print("data to copy!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!= =======================================");
      Serial.println(copy_ture);

      //copier.copyN(N);

      mqttClient.endMessage();
}


void setup() {
  // Initialize logger 
  Serial.begin(115200);
  AudioLogger::instance().begin(Serial, AudioLogger::Info);

  // connect
  connectWIFI();
  connectMQTT();

  // setup audio
//   noise.begin(info);
//   in_stream.begin(info);
  // start i2s input with default configuration
  Serial.println("starting I2S...");
  auto config = i2s.defaultConfig(RX_MODE);
  config.i2s_format = I2S_STD_FORMAT; // if quality is bad change to I2S_LSB_FORMAT https://github.com/pschatzmann/arduino-audio-tools/issues/23
  // config.sample_rate = 44100;
  // config.channels = 2;
  // config.bits_per_sample = 16;
  config.copyFrom(info); 
  config.pin_bck = 4;
  config.pin_ws = 22;
  config.pin_data = 34;
  i2s.begin(config);
  Serial.println("I2S started");

  pinMode(PLAY, INPUT_PULLUP);

  // send Audio
  //sendMQTT();

}

void loop() {
  // call poll() regularly to allow the library to send MQTT keep alives which
  // avoids being disconnected by the broker
  sendMQTT();
  mqttClient.poll();
  delay(100);
  if (digitalRead(PLAY) == LOW) {
        ESP.restart();
    }
}