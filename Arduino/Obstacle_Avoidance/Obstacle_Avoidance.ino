#include <Servo.h>
const int f2=3;
const int b2=4;
const int f1=5;
const int b1=6;
const int ser=8; 
const int tp=9;
const int ep=10;
float time,dist; 
Servo myservo; 

void setup() 
{
  Serial.begin(9600);
  myservo.attach(ser); 
  pinMode(tp,OUTPUT);
  pinMode(ep,INPUT);
  pinMode(f2,OUTPUT);
  pinMode(b2,OUTPUT);
  pinMode(f1,OUTPUT);
  pinMode(b1,OUTPUT);
}

void forward()
{
  digitalWrite(b1,LOW);
  digitalWrite(b2,LOW);
  digitalWrite(f1,HIGH);
  digitalWrite(f2,HIGH);
}

void reverse()
{
  digitalWrite(f1,LOW);
  digitalWrite(f2,LOW);
  digitalWrite(b1,HIGH);
  digitalWrite(b2,HIGH);
}

void left()
{
  digitalWrite(f1,HIGH);
  digitalWrite(f2,LOW);
  digitalWrite(b1,LOW);
  digitalWrite(b2,LOW);
}

void right()
{
  digitalWrite(f1,LOW);
  digitalWrite(f2,HIGH);
  digitalWrite(b1,LOW);
  digitalWrite(b2,LOW);
}

float distance()
{
  digitalWrite(tp,LOW);
  delayMicroseconds(2);
  digitalWrite(tp,HIGH);
  delayMicroseconds(10);
  digitalWrite(tp,LOW);
  time= pulseIn(ep,HIGH);
  dist= (0.034*time)/2;
  return(dist);
}


void loop() {
  if(Serial.available()>0)
  {
    incoming_value=Serial.read();
    Serial.println(incoming_value);
  }
}
