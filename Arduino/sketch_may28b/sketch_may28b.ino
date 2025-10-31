#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);
  WiFi.begin("EC_LAB","Admin@123");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".....");
    delay(200);
  }
  Serial.println();
  Serial.println("nodemcu is connected");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
