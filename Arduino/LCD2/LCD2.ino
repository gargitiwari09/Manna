#include <LiquidCrystal.h>
const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;  
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int ch='a';
void setup() {
  lcd.begin(16,2);
  lcd.cursor();

}

void loop() {
  if (ch=='m')
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
