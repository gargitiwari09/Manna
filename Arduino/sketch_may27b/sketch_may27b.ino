#include <LiquidCrystal.h>
int tp=9;
int ep=10;
float dist,time;
const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;  
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup() 
{
  lcd.begin(16,2);
  pinMode(tp,OUTPUT);
  pinMode(ep,INPUT);
  Serial.begin(9600);
}

void loop() 
{
  lcd.setCursor(0,0);
  digitalWrite(tp,LOW);
  delayMicroseconds(2);
  digitalWrite(tp,HIGH);
  delayMicroseconds(10);
  digitalWrite(tp,LOW);
  time= pulseIn(ep,HIGH);
  dist=(0.034*time)/2;
  lcd.print("Distance:");
  lcd.setCursor(0,1);
  lcd.print(dist);
}
