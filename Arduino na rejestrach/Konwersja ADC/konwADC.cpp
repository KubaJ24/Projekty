#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "konwADC.h"

#define f_cpu 16000000
#define led 2                       //PD2

void timer2_ctc(int odczyt){
  //Presc. 1024
  TCCR2B = 1<<CS22 | 1<<CS21 | 1<<CS20;
  //W��czone przerwanie od przepe�nienia timera 0
  TIMSK2 = 1<<TOIE2;
  TIFR2 |= 1<<TOV2;
}

void io_config(){
  DDRD = 1<<led;
  //Led zgaszony
  PORTD = 0;
}

void adc_config(){
  ADCSRA = 0b10001111;
  //�r�d�o odniesienia i wyb�r kana�u
  ADMUX = 0b10000000;
}

void adc_start(){
  ADCSRA |= 1<<ADSC;
}

void led_blink(){
  PORTD ^= 1<<led;
}
