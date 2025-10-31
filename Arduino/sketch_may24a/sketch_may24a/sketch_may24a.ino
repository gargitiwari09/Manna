int pinb=2;
int pstate;
int state;
int count=0;
void setup() {
  // put your setup code here, to run once:
  for(int i=3;i<=8;i++)
  {
    pinMode(i,OUTPUT);
  }
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
        for(int i=8;i>=3;i--)
        {
          digitalWrite(i,HIGH);
          delay(1000);
          digitalWrite(i,LOW);
        }
      }
      else
      {
        for(int i=3;i<=8;i++)
        {
          digitalWrite(i,HIGH);
          delay(1000);
          digitalWrite(i,LOW);
        }
      }
  }
}
