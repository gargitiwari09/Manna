#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int ch='a';

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
}

void loop() {
  if (ch=='n')
  {
    lcd.rightToLeft();
  }
  if (ch=='s')
  {
    lcd.leftToRight();
  }
  if (ch>'z')
  {
    lcd.home();
    ch='a';
  }
  lcd.write(ch);
  delay(1000);
  ch++;
}