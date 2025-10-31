#include <LiquidCrystal.h>
const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
const int sensor = 9;             
int val = LOW;   

void setup() 
{
  lcd.begin(16,2);
  lcd.cursor();
}

void loop() 
{
  lcd.home();
  val = digitalRead(sensor);   
  lcd.write("Not Detected");
  if(val == HIGH) 
  {           
    lcd.clear();
    lcd.write("Detected");
    delay(1000);
  } 
}
