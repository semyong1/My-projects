#include <LiquidCrystal.h> // подключаем библиотеку
#include <Servo.h>
#include <DS3231.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // пины подключенные к контактам жк
DS3231 rtc(SDA, SCL); // Инициализация библиотеки, вывод подключения SDA-SCL пина
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

int check = 0;

void setup() {
  rtc.begin();
  //rtc.setDOW(TUESDAY); //день недели
  //rtc.setTime(22,06,45); //время
  //rtc.setDate(11,06,2019); //дата
  s.attach(2);
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  int button = detectButton();
  String timeNow = rtc.getTimeStr(); // Считать текущее время
  String dateNow = rtc.getDateStr();
  String dayNow = rtc.getDOWStr();
  int tempNow = rtc.getTemp();
  lcd.print(timeNow);   //вывод времени
  lcd.setCursor(9,0);   //установка курсора
  lcd.print(dayNow);    //вывод дня
  lcd.setCursor(0,1);   
  lcd.print(dateNow);
  delay(1000);
  lcd.setCursor(0,0);

  if(check==1)
    {  
     for(int a=0;a<=90;a++)
      {
        s.write(a);
        delay(2);
      }
    }

  switch (button) {
    case B_SELECT:
    check = 1;
    }else{
      check = 0;
    } 
      break;
    default:
      break;
  }
}
