#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("Hello");
  lcd.setCursor(4,1);
  lcd.print("Gargi");
  delay(500);
  lcd.print("     ");
  delay(500);
}
