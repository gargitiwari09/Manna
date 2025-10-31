int pinb=2;
int pinl1=3;
int pinl2=4;
int pinl3=5;
int pinl4=6;
int pinl5=7;
int pinl6=8;
int pstate;
int state;
int count=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(pinl1,OUTPUT);
  pinMode(pinl2,OUTPUT);
  pinMode(pinl3,OUTPUT);
  pinMode(pinl4,OUTPUT);
  pinMode(pinl5,OUTPUT);
  pinMode(pinl6,OUTPUT);
  pinMode(pinb,INPUT_PULLUP);
}
void loop()
{
  pstate=state;
  state = digitalRead(pinb);
  if(pstate==HIGH && state==LOW)
  {
      count++;
      if (count%2==0)
      {
        digitalWrite(pinl6,HIGH);
        delay(1000);
        digitalWrite(pinl6,LOW);
        digitalWrite(pinl5,HIGH);
        delay(1000);
        digitalWrite(pinl5,LOW);
        digitalWrite(pinl4,HIGH);
        delay(1000);
        digitalWrite(pinl4,LOW);
        digitalWrite(pinl3,HIGH);
        delay(1000);
        digitalWrite(pinl3,LOW);
        digitalWrite(pinl2,HIGH);
        delay(1000);
        digitalWrite(pinl2,LOW);
        digitalWrite(pinl1,HIGH);
        delay(1000);
        digitalWrite(pinl1,LOW);
      }
      else
      {
        digitalWrite(pinl1,HIGH);
        delay(1000);
        digitalWrite(pinl1,LOW);
        digitalWrite(pinl2,HIGH);
        delay(1000);
        digitalWrite(pinl2,LOW);
        digitalWrite(pinl3,HIGH);
        delay(1000);
        digitalWrite(pinl3,LOW);
        digitalWrite(pinl4,HIGH);
        delay(1000);
        digitalWrite(pinl4,LOW);
        digitalWrite(pinl5,HIGH);
        delay(1000);
        digitalWrite(pinl5,LOW);
        digitalWrite(pinl6,HIGH);
        delay(1000);
        digitalWrite(pinl6,LOW);
      }
  }
}
