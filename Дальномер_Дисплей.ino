#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
const int pinEcho = 2; 
const int pinTrig = 3; 
float v=331.5+0.6*20;
  
void setup() {
  lcd.begin(16,2);
  pinMode(pinEcho, INPUT);
  pinMode(pinTrig, OUTPUT);
}
 
float distanceSM(){
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(3);
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(5);
  digitalWrite(pinTrig, LOW);
 
  float t = pulseIn(pinEcho, HIGH);//mks
  t = t/1000.0/1000.0/2; //s
  return t*v*100; //cm
}
 
void loop()
{
  lcd.clear();
  lcd.print(distanceSM());
  lcd.print(" cm");
  
  delay(1000);
}
