#include <Servo.h>
Servo myservo; 
int tp=9;
int ep=10;
float time,dist; 

void setup() 
{
  myservo.attach(3); 
  pinMode(tp,OUTPUT);
  pinMode(ep,INPUT);
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(tp,LOW);
  delayMicroseconds(2);
  digitalWrite(tp,HIGH);
  delayMicroseconds(10);
  digitalWrite(tp,LOW);
  time= pulseIn(ep,HIGH);
  dist= (0.034*time)/2;
  if (dist>=20.0)
  {
    myservo.write(90);
    Serial.println(dist);
  }
  if (dist<20)
  {
    myservo.write(0);
    Serial.println(dist);
  }
}
