const int irpin=D2;

void setup() 
{
  Serial.begin(9600);
  pinMode(irpin,INPUT);
}

void loop() 
{
  int val=digitalRead(irpin);
  if (val==0)
  {
    Serial.println("Object detected");
  }
  else if (val==1)
  {
    Serial.println("No Object detected");
  }
}
