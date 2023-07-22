#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/timer.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"

void test_monitor();
/*
Rozpoczyna transmisję szeregową
*/

void gpio_config();
/*
Konfiguracja wejść/wyjść
*/

void adc_config();
/*
Konfiguracja ADC
Napiecie odniesienia 1,1 V
Rozdzielczość 10 bit -> tak samo jak PWM
*/

uint16_t odczyt_adc();
/*
Zwraca wynik odczytu ADC z potencjometru sterującego silnikiem
*/

void dc_speed(uint16_t predkosc);
/*
Ustawia wartość PWM sterującą silnikiem na podstawie zmiennej predkosc
*/

void dc_pwm_config();
/*
Konfiguracja PWM dla silnika
Kanal 0 - silnik
PWM channel 0, 60 kHz, rozdzielczość 10 bit
*/
