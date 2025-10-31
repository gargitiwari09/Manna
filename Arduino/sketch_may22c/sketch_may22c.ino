int pinb=3;
int pinl=2;
int pstate;
int state;
int count=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinl,OUTPUT);
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
        digitalWrite(pinl,LOW);
      }
      else
      {
        digitalWrite(pinl,HIGH);
      }
  }
}