//definiujemy sobie stałe i przypisujemy numery pinów arduino
#define S0 2
#define S1 3
#define S2 10
#define S3 11
#define sensorOut 12
#define LED 9

int odczyt = 0;

void setup() {
  // definiujemy czy pin jest wejściem czy wyjściem
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(sensorOut, INPUT);

  //ustawiamy skalowanie na 20% zgodnie z Tabela 1 - powszechnie stosowane dla Arduino
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  digitalWrite(LED,HIGH);
  Serial.begin(9600); //inicjalizujemy monitor portu szeregowego
}

void loop() {

//ustawiamy odczyt na fotodiody CZERWONE zgodnie z Tabela 2
 digitalWrite(S2,LOW);
 digitalWrite(S3,LOW);
 odczyt = pulseIn(sensorOut, LOW); // czytamy co zwraca czujnik
 //odczyt = map(odczyt, -60, 137, 0, 255); - sprawdzamy rozstrzał //pomiarów i skalujemy do RGB (dla chętnych)
 Serial.print("R= ");
 Serial.print(odczyt);
 Serial.print(" ");
 delay(2);

 //ustawiamy odczyt na fotodiody ZIELONE zgodnie z Tabela 2
 digitalWrite(S2,HIGH);
 digitalWrite(S3,HIGH);
 odczyt = pulseIn(sensorOut, LOW); // czytamy co zwraca czujnik
 //odczyt = map(odczyt, -60, 137, 0, 255); - sprawdzamy rozstrzał //pomiarów i skalujemy do RGB (dla chętnych)
 Serial.print("G= ");
 Serial.print(odczyt);
 Serial.print(" ");
 delay(2);

 //ustawiamy odczyt na fotodiody NIEBIESKIE zgodnie z Tabela 2
 digitalWrite(S2,LOW);
 digitalWrite(S3,HIGH);
 odczyt = pulseIn(sensorOut, LOW); // czytamy co zwraca czujnik
 //odczyt = map(odczyt, -60, 137, 0, 255); - sprawdzamy rozstrzał //pomiarów i skalujemy do RGB (dla chętnych)
 Serial.print("B= ");
 Serial.print(odczyt);
 Serial.println(" ");
 delay(200);
 
}
