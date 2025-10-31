int tp=9;
int ep=10;
float dist,time;
int red=3;
int yell=4;

void setup()
{
  pinMode(tp,OUTPUT);
  pinMode(ep,INPUT);
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(yell,OUTPUT);
}

void loop()
{
  digitalWrite(tp,LOW);
  delayMicroseconds(2);
  digitalWrite(tp,HIGH);
  delayMicroseconds(10);
  digitalWrite(tp,LOW);
  time= pulseIn(ep,HIGH);
  dist=(0.034*time)/2;
  digitalWrite(red,LOW);
  digitalWrite(yell,LOW);
  if(dist<20.0)
  {
    digitalWrite(yell,LOW);
    digitalWrite(red,HIGH);
  }
  if(dist>40)
  {
    digitalWrite(red,LOW);
    digitalWrite(yell,HIGH);
  }
  
  Serial.println(dist);
  delay(100);
}

