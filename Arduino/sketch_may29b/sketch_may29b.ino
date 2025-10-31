#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

#define tp D5
#define ep D6

WiFiClient client;

long myChannelNumber = 2564358;
const char myWriteAPIKey[] = "AB0IQ04IT6IECXLB";

float dist,t;

void setup() {
  Serial.begin(9600);
  pinMode(tp,OUTPUT);
  pinMode(ep,INPUT);
  WiFi.begin("M33 Gargi","gargi1234");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print("...");
    delay(200);
  }
  Serial.println();
  Serial.println("NodeMcu is connected");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
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
  ThingSpeak.writeField(myChannelNumber,1,dist,myWriteAPIKey);
  delay(2000);
}
