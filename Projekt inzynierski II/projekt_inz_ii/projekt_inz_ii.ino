/*
DO ZROBIENIA
[v] zmiana na esp
[v] silnik DC
[ ] sterowanie serwo
[ ] czujnik kolorów
[ ] przyciski start stop
[ ] sygnalizacja led
[ ] regulacja prędkości
[ ] pomiar predkości
[ ] LCD
*/

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
//#define silnik_pot ADC1_CHANNEL_x                   //x - numer gpio, GPIO 32 - 39

void setup() { 
  test_monitor();
  gpio_config();

}

void loop() {
  
}