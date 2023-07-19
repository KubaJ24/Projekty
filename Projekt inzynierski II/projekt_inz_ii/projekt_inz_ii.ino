#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/timer.h"
//#include <analogWrite.h>                            //Problem z kompilacją
#include "driver/adc.h" 
#include "esp_adc_cal.h"

#define silnik_L GPIO_NUM_18
#define silnik_P GPIO_NUM_19
#define silnik_PWM GPIO_NUM_21
//#define silnik_pot ADC1_CHANNEL_x                   //x - numer gpio

void test_monitor();
void gpio_config();
void silnik_sterowanie();
void adc_config();
uint16_t odczyt_adc();

void setup() { 
  test_monitor();
  gpio_config();

  gpio_set_level(silnik_L, 0);
  gpio_set_level(silnik_P, 1);
  analogWrite(silnik_PWM, 100);                     //PWM ESP32 jest 10-bitowy, 0 - 1023
}

void loop() {
  
}

void test_monitor(){
  Serial.begin(9600);
}

void gpio_config(){
  //Silnik
  gpio_set_direction(silnik_L, GPIO_MODE_OUTPUT); gpio_set_level(silnik_L, 0);
  gpio_set_direction(silnik_P, GPIO_MODE_OUTPUT); gpio_set_level(silnik_P, 0);
  gpio_set_direction(silnik_PWM, GPIO_MODE_OUTPUT); gpio_set_level(silnik_PWM, 0);
}

void adc_config(){
  //Napiecie odniesienia 1,1 V
  //Ustawic attenuation po ustawieniu dzielnika z potencjometrem
  esp_adc_cal_characteristics_t adc;
  esp_adc_cal_characterize( ADC_UNIT_1, ADC_ATTEN_DB_0, ADC_WIDTH_BIT_12, 1100, &adc);
}

// uint16_t odczyt_adc(){
//   return adc1_get_raw(silnik_pot);
// }