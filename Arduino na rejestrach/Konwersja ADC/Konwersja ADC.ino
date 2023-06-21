/*
Dodać opis
zmienic konfiguracje ctc timera 2
zamiast led_blink() toggle z timera?
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
  timer2_ctc(wynik);
}



void setup() { }

void loop() {
  io_config();
  adc_config();
  sei();
  adc_start();

  //Główna petla programu
  while(1){
    
  }
}