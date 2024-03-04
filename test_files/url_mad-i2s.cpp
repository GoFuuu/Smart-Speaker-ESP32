/**
 * @file streams-url_mp3-i2s.ino
 * @author Phil Schatzmann
 * @brief decode MP3 stream from url and output it on I2S
 * @version 0.1
 * @date 2021-96-25
 * 
 * @copyright Copyright (c) 2021
 */

// install https://github.com/pschatzmann/arduino-libmad.git

#include "AudioTools.h"
#include "AudioCodecs/CodecMP3MAD.h"


URLStream url("0329","C02329DD");
I2SStream i2s; // final output of decoded stream
EncodedAudioStream dec(&i2s, new MP3DecoderMAD()); // Decoding stream
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
  config.i2s_format = I2S_STD_FORMAT;
  i2s.begin(config);

  // setup I2S based on sampling rate provided by decoder
  dec.setNotifyAudioChange(i2s);
  dec.begin();

// mp3 radio
  //url.begin("http://stream.srg-ssr.ch/m/rsj/mp3_128","audio/mp3");
  url.begin("139.155.158.174:8001/media/outaudio/apologies.mp3");

}

void loop(){
  copier.copy();
}
