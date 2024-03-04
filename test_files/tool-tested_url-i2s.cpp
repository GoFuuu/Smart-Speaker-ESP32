/**
 * @file streams-url_mp3-i2s.ino
 * @author Phil Schatzmann
 * @brief decode MP3 stream from url and output it on I2S
 * @version 0.1
 * @date 2021-96-25
 * 
 * @copyright Copyright (c) 2021
 */

// install https://github.com/pschatzmann/arduino-libhelix.git

#include "AudioTools.h"
#include "AudioCodecs/CodecMP3Helix.h"

#define PLAY          13
URLStream url("NUSRI-STU","Nusri311");
I2SStream i2s; // final output of decoded stream
EncodedAudioStream dec(&i2s, new MP3DecoderHelix()); // Decoding stream
StreamCopy copier(dec, url); // copy url to decoder


void setup(){
  Serial.begin(115200);
  AudioLogger::instance().begin(Serial, AudioLogger::Info);  

  // setup i2s
  auto config = i2s.defaultConfig(TX_MODE);
  // you could define e.g your pins and change other settings
  config.pin_bck = 27;
  config.pin_ws = 32;
  config.pin_data = 33;
  //config.mode = I2S_STD_FORMAT;
  i2s.begin(config);

  // setup I2S based on sampling rate provided by decoder
  dec.setNotifyAudioChange(i2s);
  dec.begin();

// mp3 radio
  url.begin("http://139.155.158.174:8001/media/outaudio/apologies.mp3");
pinMode(PLAY, INPUT_PULLUP);
}

void loop(){
  copier.copy();
      if (digitalRead(PLAY) == LOW) {
        delay(5);
        if(digitalRead(PLAY) == LOW){
          ESP.restart();
        }

    }
}
