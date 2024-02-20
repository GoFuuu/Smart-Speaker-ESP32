#include "MyI2S.h"

bool MyI2S::InitInput(i2s_bits_per_sample_t BPS,
                      int bckPin,
                      int wsPin,
                      int dataInPin)
{
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = SAMPLE_RATE,
    .bits_per_sample = BPS,
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    .communication_format = (i2s_comm_format_t)(I2S_COMM_FORMAT_I2S | I2S_COMM_FORMAT_I2S_MSB),
    .intr_alloc_flags = 0,
    .dma_buf_count = 16,
    .dma_buf_len = 60,
    .use_apll = false
  };

  i2s_pin_config_t pin_config;
  memset(&pin_config,0,sizeof(i2s_pin_config_t));
  pin_config.bck_io_num = bckPin;
  pin_config.ws_io_num = wsPin;
  pin_config.data_out_num = I2S_PIN_NO_CHANGE;
  pin_config.data_in_num = dataInPin;

  if(ESP_OK!=i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL))
  {
    Serial.println("install i2s driver failed");
    return false;
  }
  if(ESP_OK!=i2s_set_pin(I2S_NUM_0, &pin_config))
  {
    Serial.println("i2s set pin failed");
    return false;
  }

  samples_32bit = (int32_t *)malloc(sizeof(int32_t) * 128);

  return true;
}

bool MyI2S::InitOutput(i2s_bits_per_sample_t BPS,
                       int bckPin,
                       int wsPin,
                       int dataOutPin)
{
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
    .sample_rate = SAMPLE_RATE,
    .bits_per_sample = BPS,
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    .communication_format = (i2s_comm_format_t)(I2S_COMM_FORMAT_I2S | I2S_COMM_FORMAT_I2S_MSB),
    .intr_alloc_flags = 0,
    .dma_buf_count = 16,
    .dma_buf_len = 60,
    .use_apll = false
  };

  i2s_pin_config_t pin_config;
  memset(&pin_config,0,sizeof(i2s_pin_config_t));
  pin_config.bck_io_num = bckPin;
  pin_config.ws_io_num = wsPin;
  pin_config.data_out_num = dataOutPin;
  pin_config.data_in_num = I2S_PIN_NO_CHANGE;

  if(ESP_OK!=i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL))
  {
    Serial.println("install i2s driver failed");
    return false;
  }
  if(ESP_OK!=i2s_set_pin(I2S_NUM_0, &pin_config))
  {
    Serial.println("i2s set pin failed");
    return false;
  }
  return true;
}

bool MyI2S::InitAdcInput(i2s_bits_per_sample_t BPS, adc1_channel_t adcChannel)
{
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX | I2S_MODE_ADC_BUILT_IN),
    .sample_rate = SAMPLE_RATE,
    .bits_per_sample = BPS,
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    .communication_format = (i2s_comm_format_t)(I2S_COMM_FORMAT_I2S | I2S_COMM_FORMAT_I2S_MSB),
    .intr_alloc_flags = 0,
    .dma_buf_count = 16,
    .dma_buf_len = 60,
    .use_apll = false
  };

  if(ESP_OK!=i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL))
  {
    Serial.println("install i2s driver failed");
    return false;
  }
  i2s_set_pin(I2S_NUM_0, NULL);
  i2s_set_adc_mode(ADC_UNIT_1, adcChannel);
  adc1_config_channel_atten(adcChannel, ADC_ATTEN_DB_11);
  i2s_adc_enable(I2S_NUM_0);
  return true;
}

bool MyI2S::InitDacOutput(i2s_bits_per_sample_t BPS)
{
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_DAC_BUILT_IN),
    .sample_rate = SAMPLE_RATE,
    .bits_per_sample = BPS,
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    .communication_format = I2S_COMM_FORMAT_STAND_MSB,
    .intr_alloc_flags = 0,
    .dma_buf_count = 16,
    .dma_buf_len = 60,
    .use_apll = false
  };

  if(ESP_OK!=i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL))
  {
    Serial.println("install i2s driver failed");
    return false;
  }
  i2s_set_pin(I2S_NUM_0, NULL);
  i2s_set_dac_mode(I2S_DAC_CHANNEL_BOTH_EN);
  return true;
}

size_t MyI2S::Read(char* data, int numData)
{
  size_t recvSize;
  i2s_read(I2S_NUM_0, (void*)data, numData, &recvSize, portMAX_DELAY);
  return recvSize;
}
int MyI2S::I2Sread(int16_t *samples, int count)// read from i2s
{
    size_t bytes_read = 0;
    if (count>128)
    {
        count = 128;//最少读取128
    }
    
    i2s_read(I2S_NUM_0, (char *)samples_32bit, sizeof(int32_t) * count, &bytes_read, portMAX_DELAY);
    //Serial.println("read one");
    int samples_read = bytes_read / sizeof(int32_t);
    for (int i = 0; i < samples_read; i++)
    {
      //Serial.println("start to convert...1");
        int32_t temp = samples_32bit[i] >> 11;
        //Serial.println("start to convert....2");
        //samples[i] = (temp > INT16_MAX) ? INT16_MAX : (temp < -INT16_MAX) ? -INT16_MAX : (int16_t)temp;
        samples[i] = (temp > INT16_MAX) ? INT16_MAX : (temp < INT16_MIN) ? INT16_MIN : (int16_t)temp;
        //Serial.println("start to convert....3");
    }
    //delete[] samples_32bit;
    return samples_read;
}
void MyI2S::covert_bit(int16_t *temp_samples_16bit,uint8_t*temp_samples_8bit,uint8_t len )//16位数据转成8位
{
  for(uint8_t i=0;i<len;i++)
  {
    temp_samples_8bit[i]=(temp_samples_16bit[i] + 32768) >> 8;
  }
    
}
size_t MyI2S::Write(char* data, int numData)
{
  size_t sendSize;
  i2s_write(I2S_NUM_0, (void*)data, numData, &sendSize, portMAX_DELAY);
  return sendSize;
}

void MyI2S::End()
{
  i2s_driver_uninstall(I2S_NUM_0);
}