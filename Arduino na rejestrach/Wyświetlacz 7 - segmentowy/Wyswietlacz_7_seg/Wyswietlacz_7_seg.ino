/*
Program testowy do wyświetlacza 7 segmentowego
Podpięta cyfra nr 1
Używany port D - piny od 0 do 7
A = 6;
B = 5;
C = 0;
D = 1;
E = 2;
F = 4;
G = 3;

Do multipleksowania:
Tranzystor NPN
1k Ohm kolektor
10k Ohm Baza
*/

#include "my_sev_seg.h"
#include <Wire.h>

int a = 0;
int b = 0;
int liczba = 0;
int odczyt = 0;

int* dz = &a;
int* jed = &b;

void setup() {
  //Wyjścia
  DDRD = 0xFF;
  DDRB = 0x03;
  //Wyzerowane
  PORTD = 0x00;
  PORTB = 0x00;
}

void loop() {
  for(char i = 0; i < 10; i++){
    *dz = i;
    digit_display(dz);
    delay(1000);
  }
}