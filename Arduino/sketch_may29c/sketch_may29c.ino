#define tp D5
#define ep D6

float dist,t;

void setup() {
  Serial.begin(9600);
  pinMode(tp,OUTPUT);
  pinMode(ep,INPUT);
}

void loop() {
  digitalWrite(tp,LOW);
  delayMicroseconds(2);
  digitalWrite(tp,HIGH);
  delayMicroseconds(10);
  digitalWrite(tp,LOW);
  t= pulseIn(ep,HIGH);
  dist= (0.034*t)/2;
  Serial.println(dist);
  delay(2000);
}
