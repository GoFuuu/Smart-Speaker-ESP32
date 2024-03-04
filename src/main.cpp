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

//AudioEncodedServer server(new WAVEncoder(),"ssid","password");  
AudioWAVServer server("NUSRI-STU","Nusri311"); // the same a above
//MP3EncoderLAME mp3;
//AudioEncoderServer server(&mp3, "NUSRI-STU","Nusri311");
//AudioEncoderServer server(new MP3EncoderLAME(), "NUSRI-STU","Nusri311");
I2SStream i2sStream;    // Access I2S as stream
VolumeStream volume(i2sStream);
VolumeStreamConfig volumeConfig;
ConverterFillLeftAndRight<int16_t> filler(LeftIsEmpty); // fill both channels - or change to RightIsEmpty

void setup(){
  Serial.begin(115200);
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
  Serial.println("I2S started");

  // start data sink
  //server.begin(i2sStream, config, &filler);
  server.begin(volume, config, &filler);
pinMode(13, INPUT_PULLUP);
}

// Arduino loop  
void loop() {
  // Handle new connections
  server.copy();  
      if (digitalRead(13) == LOW) {
        ESP.restart();
    }
}
