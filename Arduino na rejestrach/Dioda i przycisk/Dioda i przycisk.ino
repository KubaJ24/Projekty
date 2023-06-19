/* 
Pierwszy projekt Arduino na rejestrach
Miganie diodą na przycisk
*/

//Definicje wyprowadzeń
#define led 2
#define przycisk 3

void setup() {
  //Ustawienie we/wy
  DDRD = 1<<led;
  //Led zgaszony, rezystor podciągniety
  PORTD = 1<<przycisk;
}

void loop() {
  if((PIND & 1<<przycisk) == 0){
    while((PIND & 1<<przycisk) == 0){ };
    PORTD ^= 1<<led;
    _delay_ms(50);
  }
  _delay_ms(10);
}
