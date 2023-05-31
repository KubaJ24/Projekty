#include <Servo.h>

// Definicje
#define S0 2
#define S1 3
#define S2 10
#define S3 11
#define sensorOut 12
#define LED 9
#define silnikPWM 6
#define lewo 8
#define prawo 7

Servo serwo;

int R = 0;
int G = 0;
int B = 0;
byte kolor_flag = 0;

// Deklaracja funkcji
void odczyt();
void dcStart();
void kolor(int B);
void sortowanie(byte kolor_flag);
void serwo_powrot();

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(sensorOut, INPUT);
  // Skalowanie na 20% do czujnika kolorów
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  digitalWrite(LED,HIGH);
  Serial.begin(9600);
  // Start silnika
  dcStart();
  // Dołączanie serwa
  serwo.attach(5);
  // Początkowa pozycja serwa
  serwo.write(98);
}

void loop() {
  odczyt();
  kolor(B);
  Serial.println(B);
  // delay(50);
  delay(200);
  sortowanie(kolor_flag);
  serwo_powrot();
  delay(10);
}

void dcStart(){
  digitalWrite(lewo, LOW);
  digitalWrite(prawo, HIGH);
  analogWrite(silnikPWM, 100);
}

void odczyt(){
  // Odczyt R
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  R = pulseIn(sensorOut, LOW);
  // Odczyt G
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  G = pulseIn(sensorOut, LOW);
  // Odczyt B
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  B = pulseIn(sensorOut, LOW);
}

void kolor(int B){
  if(B > 151){
    kolor_flag = 1;        
  }
  if(B > 140 && B < 151){
    kolor_flag = 2;    
  }
  if(B < 140){
    kolor_flag = 0;    
  }
}

void sortowanie(byte kolor_flag){
  switch(kolor_flag){
    case 0: serwo.write(98); break;
    case 1: serwo.write(60); delay(1500); break;
    case 2: serwo.write(140); delay(1500); break;
    default: serwo.write(98); break;
  }
}

void serwo_powrot(){
  serwo.write(98);
}