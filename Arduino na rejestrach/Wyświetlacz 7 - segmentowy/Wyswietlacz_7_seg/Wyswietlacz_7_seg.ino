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
4,7k Ohm kolektor
10k Ohm Baza
*/

const char dig1 = 0;        //Port B PB0 i PB1
const char dig2 = 1;

void digit(char znak);
void dig_on(char dig_num);
void dig_off(char dig_num);

void setup() {
  //Wyjścia
  DDRD = 0xFF;
  DDRB = 0x01;
  //Wyzerowane
  PORTD = 0x00;
  PORTB = 0x00;
}

void loop() {
  dig_on(dig1);
  digit(8);
  delay(500);
  dig_off(dig1);
  delay(500);
}

void digit(char znak){
  switch(znak){
    case 0: PORTD = 0b0001000; break;
    case 1: PORTD = 0b1011110; break;
    case 2: PORTD = 0b0010001; break;
    case 3: PORTD = 0b0010100; break;
    case 4: PORTD = 0b1000110; break;
    case 5: PORTD = 0b0100100; break;
    case 6: PORTD = 0b0100000; break;
    case 7: PORTD = 0b0011110; break;
    case 8: PORTD = 0b0000000; break;
    case 9: PORTD = 0b0000100; break;
  }
}

void dig_on(char dig_num){
  
  PORTB = 1 << dig_num;
}

void dig_off(char dig_num){
  PORTB = ~(1 << dig_num);
}