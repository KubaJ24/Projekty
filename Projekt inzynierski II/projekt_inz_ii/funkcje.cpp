#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/timer.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"
#include <Arduino.h>

#include "funkcje.h"

#define silnik_L GPIO_NUM_18
#define silnik_P GPIO_NUM_19
#define silnik_PWM GPIO_NUM_21
#define silnik_pot ADC1_CHANNEL_7                 //GPIO 32 - 39 - tutaj GPIO 35

void test_monitor(){
  Serial.begin(115200);
}

void gpio_config(){
  //Silnik
  gpio_set_direction(silnik_L, GPIO_MODE_OUTPUT); gpio_set_level(silnik_L, 0);
  gpio_set_direction(silnik_P, GPIO_MODE_OUTPUT); gpio_set_level(silnik_P, 0);
  gpio_set_direction(silnik_PWM, GPIO_MODE_OUTPUT); gpio_set_level(silnik_PWM, 0);

  //Potencjometr sterujący silnikiem
  //Bez pull up
  gpio_set_direction(GPIO_NUM_35, GPIO_MODE_INPUT);
}

void adc_config(){
  //Napiecie odniesienia 1,1 V
  //Ustawic attenuation po ustawieniu dzielnika z potencjometrem
  //Dzielnik to potencjometr 10 kOhm i identyczny rezystor
  //Rozdzielczosc 10 bit -> PWM jest 10 bit
  esp_adc_cal_characteristics_t adc;
  esp_adc_cal_characterize( ADC_UNIT_1, ADC_ATTEN_DB_2_5, ADC_WIDTH_BIT_10, 1100, &adc);
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
