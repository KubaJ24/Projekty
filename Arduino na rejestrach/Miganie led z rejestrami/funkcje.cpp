#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "funkcje.h"

#define f_cpu 16000000
#define led 3                       //PB3
#define przycisk 3                  //PD3

void io_config(){
  DDRB = 1<<led;
  PORTD = 1<<przycisk;
}

void timer2_normal(){
  //Presc. 1024
  TCCR2B = 1<<CS22 | 1<<CS21 | 1<<CS20;
  //W��czone przerwanie od przepe�nienia timera 0
  TIMSK2 = 1<<TOIE2;
  TIFR2 |= 1<<TOV2;
}

void timer2_on_off(){
  if((PIND & 1<<przycisk) == 0){
    while((PIND & 1<<przycisk) == 0) { }
    TCCR2B ^= 0b00000111;
    _delay_ms(30);
  }
}

void timer2_pwm(char wypelnienie){
  //Fast PWM, non-inverting mode
  TCCR2A = 1<<WGM21 | 1<<WGM20 | 1<<COM2A1;
  //Presc. 1024
  TCCR2B = 1<<CS22 | 1<<CS21 | 1<<CS20;
  OCR2A = 0;
}