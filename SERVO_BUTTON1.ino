#include <LiquidCrystal.h> // подключаем библиотеку
#include <Servo.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // пины подключенные к контактам жк
Servo s;

// директива, даем название кнопкам
#define B_SELECT 5
#define B_NONE 10

int detectButton() {  
  int keyAnalog =  analogRead(A0);  // аналоговое чтение с A0
 if (keyAnalog < 800) {
    return B_SELECT;
  } else {
    // все остальные значения до 1023 будут означать, что нажатий не было
    return B_NONE;
  }
}
void servo1(int servo1){
  int a=0;
  for(a=0;a<=90;a++)
  {
    s.write(a);
    delay(25);
  }
}

void setup() {
  s.attach(3);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(5,0);
  lcd.print("KNOPKA:");
}

void loop() {
  int button = detectButton();


  switch (button) {
    case B_SELECT:
      servo1(1);
      break;
    default:
      break;
  }
}