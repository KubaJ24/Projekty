#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void timer2_ctc(int odczyt);
/* 
Konfiguracja timera 2 w tryb ctc
*/

void io_config();
/*
Konfiguracja wej�� / wyj��
*/

void adc_config();
/*
Konfiguracja ADC
�r�d�o odniesienia AVcc, kana� A0, presc. 128
*/

void adc_start();
/*
Rozpocz�cie przetwarzania
*/

void led_blink();
/*
Zmiana stanu diody
*/
