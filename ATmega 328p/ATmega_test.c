/*
Program testowy do wgrania na ATmega 328p
*/

#include <avr/io.h>

const int f_cpu 16000000;
const int led x                             //x - numer pinu w porcie B

int main(){
    //Konfiguracja portu
    DDRB = 1 << led;
    //Dioda zgaszona
    PORTB = 0;

    while(1){
        PORTB ^= 1 << led;
        _delay_ms(500);
    }
}
