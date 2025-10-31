#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int num=3;

byte ch1[8]=
{
  B00000,
  B00000,
  B00100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte ch2[8]=
{
  B00000,
  B00000,
  B00100,
  B01110,
  B00000,
  B00000,
  B00000,
  B00000
};

byte ch3[8]=
{
  B00000,
  B00000,
  B00100,
  B01110,
  B00000,
  B00000,
  B00000,
  B00000
};

void setup()
{
  lcd.init();
  lck.backlight();
  lcd.setCursor(0,0);
  lcd.createChar(1,ch1);
  lcd.createChar(2,ch2);
  lcd.createChar(3,ch3);
}

void loop()
{
  for(int i=1;i<=num;i++)
  {
    lcd.write(i);
    delay(1000);
    lcd.clear();
    delay(1000);
  }
}
