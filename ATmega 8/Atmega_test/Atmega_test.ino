/*
Program testowy do wgrania na ATmega 8
*/

#include <avr/io.h>

#define F_CPU 16000000UL;
const int led = 1;                             //0 - numer pinu w porcie B

void setup(){
  //Konfiguracja portu
  DDRB = 1 << led;
  //Dioda zgaszona
  PORTB = 0;
}

void loop(){
  PORTB ^= 1 << led;
  delay(1000);
}