int led1=3;

void setup() {
  Serial.begin(9600);
  pinMode(led1,OUTPUT);

}

void loop() {
  for(int i=0;i<=10;i++)
  {
    digitalWrite(3,HIGH);
    Serial.println(i);
    delay(1000);
    digitalWrite(3,LOW);
    delay(1000);
  }
  

}
