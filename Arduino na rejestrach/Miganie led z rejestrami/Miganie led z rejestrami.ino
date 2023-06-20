/*
Programy migające led z wykorzystaniem timerów
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "funkcje.h"

#define f_cpu 16000000
#define led 3                       //PB3
#define przycisk 3                  //PD3

void prog1();
void prog2();

byte wypelnienie = 0;
byte licznik = 0;
byte flag = 0;

//Procedura przerwania timera 2 od przepełnienia w trybie normal
ISR(TIMER2_OVF_vect){
  licznik++;
  if(licznik == 61){
    PORTB ^= 1<<led;
    licznik = 0;
  }
}

void setup() { }

void loop() {
  prog1();
}

void prog1(){
  //Led miga co 1s
  //Przycisk wyłącza i włącza program
  io_config();
  //Zezwolenie na przerwania 
  sei();
  timer2_normal();

  //Pętla główna programu
  while(1){
    timer2_on_off();
    _delay_ms(10);
  }
}

void prog2(){
  //Led świeci z różną jasnością, wsp. wypełnienia PWM rośnie i spada
  //Przycisk wyłącza i włącza program
  io_config();
  timer2_pwm(wypelnienie);

  //Pętla główna programu
  while(1){
    timer2_on_off();
    switch(flag){
      case false:
        if(wypelnienie < 255) { wypelnienie++; } else { flag = true; }
        OCR2A = wypelnienie;
        break;
      case true:
        if(wypelnienie > 0) { wypelnienie--; } else { flag = false; }
        OCR2A = wypelnienie;
    }
    _delay_ms(20);
  }
}