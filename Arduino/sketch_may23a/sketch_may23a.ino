int pinb=3;
int pinl1=2;
int pinl2=4;
int pstate;
int state;
int count=0;
int l1;
int l2;
void setup() {
  // put your setup code here, to run once:
  pinMode(pinl1,OUTPUT);
  pinMode(pinl2,OUTPUT);
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
        l2++;
        if (l2%2==0)
        {
          digitalWrite(pinl2,LOW);
        }
        else
        {
          digitalWrite(pinl2,HIGH);
        }
      }
      else
      {
        l1++;
        if (l1%2==0)
        {
          digitalWrite(pinl1,LOW);
        }
        else
        {
          digitalWrite(pinl1,HIGH);
        }
      }
  }
}
