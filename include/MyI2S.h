#pragma once
#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2s.h"
#define SAMPLE_RATE (44100)

class MyI2S
{
public:
  int32_t *samples_32bit;//读出来的原始32位数据，长度128
  int16_t *samples_16bit;//转换后的16位数据，长度128
  uint8_t *samples_8bit ;//转换后的8位数据，长度128
  int16_t *recive_16bit;//接收后转换的16位数据，长度128
  int16_t *output_16bit;//发送给扬声器的16位数据，长度256，因为传入数据是双声道所以*2

  //以接收I2S的数据进行初始化
  bool InitInput(i2s_bits_per_sample_t BPS,
                 int bckPin,
                 int wsPin,
                 int dataInPin);

  //以发送I2S的数据进行初始化
  bool InitOutput(i2s_bits_per_sample_t BPS,
                 int bckPin,
                 int wsPin,
                 int dataOutPin);              

  //以接收ADC通道的数据进行初始化
  bool InitAdcInput(i2s_bits_per_sample_t BPS, adc1_channel_t adcChannel);

  //以接收DAC通道的数据进行初始化
  bool InitDacOutput(i2s_bits_per_sample_t BPS);

  size_t Read(char* data, int numData);
  int I2Sread(int16_t *samples, int count);
  void covert_bit(int16_t *temp_samples_16bit,uint8_t*temp_samples_8bit,uint8_t len );//16位数据转成8位
  size_t Write(char* data, int numData);

  void End();
};