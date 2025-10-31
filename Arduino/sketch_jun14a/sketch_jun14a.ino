const int fp=6;
const int bp=7;
char incoming_value=0;

void setup() 
{
  Serial.begin(9600);
  pinMode(fp,OUTPUT);
  pinMode(bp,OUTPUT);
}

void loop() {
  if(Serial.available()>0)
  {
    incoming_value=Serial.read();
    Serial.println(incoming_value);
    if (incoming_value=='1')
    {
      digitalWrite(fp,HIGH);
    }
    if (incoming_value=='2')
    {
      digitalWrite(bp,HIGH);
    }
    if (incoming_value=='0')
    {
      digitalWrite(fp,LOW);
      digitalWrite(bp,LOW);
    }
  }
}

