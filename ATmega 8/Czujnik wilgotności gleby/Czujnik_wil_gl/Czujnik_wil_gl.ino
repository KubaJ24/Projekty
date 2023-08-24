#include "my_sev_seg.h"
#include "konwersjaADC.h"
#include <Arduino.h>

uint8_t a = 0;
uint8_t b = 0;
int liczba = 0;
int wynik = 0;

uint8_t* dz = &a;
uint8_t* jed = &b;

void setup() {
  //Wyjścia
  DDRD = 0xFF;
  DDRB = 0x03;
  //Wejście
  DDRC = 0x00;
  //Wyzerowane
  PORTD = 0x00;
  PORTB = 0x00;
  PORTC = 0x00;

  //Konfiguracja ADC
  adc_config();
}

void loop() {
  adc_start();
  while((ADCSRA & (1 << ADSC)) == 1){}
  wynik = adc_result();
  // 0 - 670 -> zakres wskazań czujnika dla 5V Vcc
  liczba = map(wynik, 0, 670, 0, 99);
  number_extract(liczba, dz, jed);
  number_display(dz, jed);
  delay(5);
}