int pinl=6;
int pinl2=3;
int pot=A0;
void setup() {
  pinMode(pinl,OUTPUT);
  pinMode(pinl2,OUTPUT);
  pinMode(pot,INPUT);
  Serial.begin(9600);
}

void loop() {
  int pt=analogRead(pot);
  int value=map(pt,0,1023,0,255);
  Serial.println(value);
  analogWrite(pinl,value);
  analogWrite(pinl2,value);
 

}
