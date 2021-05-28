#include <LiquidCrystal.h>
#include <Servo.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
Servo servo;
void setup() {
  lcd.begin(16, 2);
  servo.attach(3);
}

void loop() {
    servo.write(50);
    lcd.setCursor(0,0);
  lcd.print("SERVO");
    lcd.setCursor(0,1);
  lcd.print("GRADUS: 50");
    delay(2000);
    servo.write(0);
    lcd.clear();
    lcd.setCursor(0,0);
  lcd.print("SERVO");
    lcd.setCursor(0,1);
  lcd.print("GRADUS: 0");
    delay(2000);
  lcd.clear();
 }
 
