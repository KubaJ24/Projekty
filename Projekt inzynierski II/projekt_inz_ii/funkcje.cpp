#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/timer.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"

#include "funkcje.h"

#define silnik_L GPIO_NUM_18
#define silnik_P GPIO_NUM_19
#define silnik_PWM GPIO_NUM_21
//#define silnik_pot ADC1_CHANNEL_x                   //x - numer gpio

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
  //Wstepnie 11 dB attenuation - pomiar do 2,6 V
  //Dzielnik to potencjometr 10 kOhm i identyczny rezystor
  //Rozdzielczosc 10 bit -> PWM jest 10 bit
  esp_adc_cal_characteristics_t adc;
  esp_adc_cal_characterize( ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_10, 1100, &adc);
}

uint16_t odczyt_adc(){
  return adc1_get_raw(silnik_pot);
}

void dc_pwm_config(){
  //Kanal 0 - silnik

  //PWM channel 0, 60 kHz, 10 bit
  ledcSetup(0, 60000, 10);
  //PWM pin, PWM channel
  ledcAttachPin(silnik_PWM, 0);
}

void dc_speed(uint16_t predkosc){

  //Jezeli sie nie skompiluje - zmienic rzutowanie

  ledcWrite(0, predkosc);
}
