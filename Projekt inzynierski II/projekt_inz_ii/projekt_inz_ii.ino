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
#include <Arduino.h>

#include "funkcje.h"

uint16_t wyn = 0;

void setup() { 
  test_monitor();
  gpio_config();
  adc_config();
}

void loop() {
  wyn = odczyt_adc();
  Serial.println(wyn);
  vTaskDelay(250 / portTICK_RATE_MS);
}