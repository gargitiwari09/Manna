#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ThingSpeak.h>

DHT dht(D5,DHT11);

WiFiClient client;

long myChannelNumber = 2564329;
const char myWriteAPIKey[] = "BHIT9TFBDP200Z1J";

void setup() {
  Serial.begin(9600);
  WiFi.begin("M33 Gargi","gargi1234");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print("...");
    delay(200);
  }
  Serial.println();
  Serial.println("NodeMcu is connected");
  Serial.println(WiFi.localIP());
  dht.begin();
  ThingSpeak.begin(client);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.println("Temperature: " + (String) t);
  Serial.println("Humidity: " + (String) h);
  //ThingSpeak.writeField(myChannelNumber,1,t,myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber,1,h,myWriteAPIKey);
  delay(2000);
}
