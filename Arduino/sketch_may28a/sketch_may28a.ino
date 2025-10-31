#include <Servo.h>. 
int tp = 9;
int ep = 10;
int lp = 6;
float time, dist;

float calDist()
{  
  digitalWrite(tp, LOW); 
  delayMicroseconds(2);
  digitalWrite(tp, HIGH); 
  delayMicroseconds(10);
  digitalWrite(tp, LOW);
  time = pulseIn(ep, HIGH); 
  dist= (time*0.034)/2;
  return dist;
}

void ledOn(float dist)
{
  if (dist<=40.0)
  {
    digitalWrite(lp,HIGH);
  }
  if (dist>40.0)
  {
    digitalWrite(lp,LOW);  
  }
}

Servo myServo; 

void setup() 
{
  pinMode(tp, OUTPUT); 
  pinMode(ep, INPUT); 
  pinMode(lp, OUTPUT);
  Serial.begin(9600);
  myServo.attach(3); 
}
void loop() 
{
  for(int i=0;i<=180;i++)
  {  
    myServo.write(i);
    delay(1);
    dist = calDist();
    Serial.println(dist);
    ledOn(dist);
  } 

  for(int i=180;i>=0;i--)
  {  
    myServo.write(i);
    delay(1);
    dist = calDist();
    Serial.println(dist);
    ledOn(dist);
  }
}