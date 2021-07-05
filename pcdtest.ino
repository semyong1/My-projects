#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// Software SPI (slower updates, more flexible pin options):
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(8, 9, 10, 12, 11);
void setup(){
  Serial.begin(9600);
  display.begin();
  display.setContrast(60);
  display.clearDisplay();
}

void drawtext(void){
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Hello\nWorld!");
  display.display();
}

void loop() {
  drawtext();
  delay(1000);
  
}
