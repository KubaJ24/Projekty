#include "my_sev_seg.h"
#include <Wire.h>
#include <Arduino.h>

int a = 0;
int b = 0;
int liczba = 0;
int wynik = 0;

int* dz = &a;
int* jed = &b;

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
}

void loop() {
  wynik = analogRead(PC0);
  liczba = map(wynik, 0, 670, 0, 99);
  number_extract(liczba, dz, jed);
  number_display(dz, jed);
  delay(5);
}