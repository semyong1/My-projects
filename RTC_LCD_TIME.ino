#include <LiquidCrystal.h>
#include <DS3231.h>

#define LED 14

DS3231 rtc(SDA, SCL);
LiquidCrystal lcd(8,9,4,5,6,7);

void setup() {
 // Serial.begin(115200);
  rtc.begin();
  lcd.begin(16,2);
  pinMode(LED, OUTPUT);

  //rtc.setDOW(TUESDAY); //день недели
  //rtc.setTime(22,06,45); //время
  //rtc.setDate(11,06,2019); //дата
  
}

void loop() {
  String timeNow = rtc.getTimeStr();
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
  
//  lcd.setCursor(1,1);

}