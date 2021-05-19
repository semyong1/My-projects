#include <LiquidCrystal.h> // подключаем библиотеку
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // пины подключенные к контактам жк

#define B_UP   1  // директива, даем название кнопкам
#define B_DOWN 2
#define B_LEFT 3
#define B_RIGHT 4
#define B_SELECT 5
#define B_NONE 10

int detectButton() {  
  int keyAnalog =  analogRead(A0);  // аналоговое чтение с A0
  if (keyAnalog < 100) {            // 0 < 100 значит нажимается вправо
    return B_RIGHT;
  } else if (keyAnalog < 200) {     // 100 < 200 да, нажимается вверх
    return B_UP;
  } else if (keyAnalog < 400) {
    return B_DOWN;
  } else if (keyAnalog < 600) {
    return B_LEFT;
  } else if (keyAnalog < 800) {
    return B_SELECT;
  } else {
    // все остальные значения до 1023 будут означать, что нажатий не было
    return B_NONE;
  }
}
void clearLine(int line){       // переменная очистка строки
  lcd.setCursor(0, 1);          // устанавливаем курсор 
  lcd.print("                ");
}

void text(String message){
  Serial.println(message);
  lcd.setCursor(0, 1);
  lcd.print(message);
  delay(1000);
  clearLine(1);
}

void autoscrol(int autoscrol){
  
}

void sms(int sms){
  lcd.clear();
  lcd.setCursor(0, 0);
  for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }
  lcd.setCursor(16, 1);
  lcd.autoscroll();
  for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }
  lcd.noAutoscroll();

  lcd.clear();
}




void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(5,0);
  lcd.print("KNOPKA:");
}

void loop() {
  int button = detectButton();


  switch (button) {
    case B_UP:
    setup();
      text("UP");
      break;
    case B_DOWN:
    setup();
      text("DOWN");
      break;
    case B_LEFT:
    setup();
      text("LEFT");
      break;
    case B_RIGHT:
      setup();
      text("RIGHT");   
      break;
      
    case B_SELECT:
      sms(1);
      break;
   
    default:
   
      break;
  }
}
