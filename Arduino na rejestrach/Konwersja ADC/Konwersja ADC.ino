/*
Miganie diodą z częst. prporcjonalną do napięcia na A0
Potencjometr podłączony do A0
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "konwADC.h"

#define led 2

int wynik = 0;
int loval, hival;

ISR(ADC_vect){
  loval = ADCL;
  hival = ADCH;
  wynik = (hival<<8) | loval; 
}

void setup() { }

void loop() {
  io_config();
  adc_config();
  sei();
  adc_start();

  //Główna petla programu
  while(1){
    led_blink();
    delay(wynik);
    adc_start();
  }
}