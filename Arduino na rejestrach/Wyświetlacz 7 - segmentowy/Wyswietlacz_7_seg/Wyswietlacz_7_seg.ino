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

  pinMode(A0, INPUT_PULLUP);

  Serial.begin(115200);
}

void loop() {
  odczyt = analogRead(A0);
  liczba = map(odczyt, 0, 850, 0, 99);
  number_extract(liczba, dz, jed);
  Serial.print(odczyt);
  Serial.print(" ");
  Serial.print(liczba);
  Serial.print(" ");
  Serial.print(*dz);
  Serial.print(" ");
  Serial.println(*jed);
  number_display(dz, jed);
  delay(5);
}