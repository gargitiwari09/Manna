const int an=A0;

void setup() {
  Serial.begin(9600);
}

void loop()
{
  int val;
  val=analogRead(an);     
  Serial.println(val);        
  delay(500);
}