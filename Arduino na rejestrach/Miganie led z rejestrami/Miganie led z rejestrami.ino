/*
Programy migające led z wykorzystaniem timerów
*/

#include <avr/io.h>
#include <avr/interrupt.h>

#define f_cpu 16000000
#define led 2
#define przycisk 3

byte wypelnienie = 0;
byte licznik = 0;

//Procedura przerwania timera 2 od przepełnienia w trybie normal
ISR(TIMER2_OVF_vect){
  licznik++;
  if(licznik == 61){
    PORTD ^= 1<<led;
    licznik = 0;
  }
}

void prog1();

void io_config();
void timer2_normal();
void timer2_pwm(byte wypelnienie);
void timer2_on_off();

void setup() { }

void loop() {
  prog1();
}

void io_config(){
  DDRD = 1<<led;
  PORTD = 1<<przycisk;
}

void timer2_normal(){
  //Presc. 1024
  TCCR2B = 1<<CS22 | 1<<CS21 | 1<<CS20;
  //Włączone przerwanie od przepełnienia timera 0
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