void setup()
{
  pinMode(3, OUTPUT);
}

void loop()
{
  int i;
  for(i=0;i<=180;i++)
  {
  	analogWrite(3,i);
    delay(1000);
  }
  for(i=180;i>=0;i--)
  {
  	analogWrite(3,i);
    delay(1000);
  }
}
