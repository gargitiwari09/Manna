int cv;
int lv ;
int toggle=0;
int pinb=3;
int pinl=2;
void setup() {
  // put your setup code here, to run once:
  pinMode(pinl,OUTPUT);
  pinMode(pinb,INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  lv=cv;
  cv=digitalRead(pinb);
  if (lv==HIGH && cv==LOW)
  {
    toggle=!toggle;
    digitalWrite(pinl,toggle);
  }

}
