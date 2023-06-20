#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void io_config();
/*
Konfiguracja wej�� / wyj��
Led 11
Przycisk 3
*/

void timer2_normal();
/* 
Konfiguracja timera 2 w tryb normal
*/

void timer2_pwm(char wypelnienie);
/* 
Konfiguracja timera 2 w tryb fast PWM z wypelnieniem rownym warto�ci tej zmiennej
*/

void timer2_on_off();
/* 
W��czanie i wy��czanie timera za pomoc� przycisku
*/
