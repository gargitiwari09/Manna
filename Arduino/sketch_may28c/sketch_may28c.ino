#include <ESP8266WiFi.h>
WiFiClient client;
WiFiServer server(80);

#define led D5

void setup() {
  Serial.begin(115200);
  WiFi.begin("M33 Gargi","gargi1234");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".....");
    delay(200);
  }
  Serial.println();
  Serial.println("nodemcu is connected");
  Serial.println(WiFi.localIP());
  server.begin();
  pinMode(led,OUTPUT);
}

void loop() {
  client= server.available();
  if (client==1)
  {
    String request = client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
    if (request=="GET /ledonn HTTP/1.1")
    {
      digitalWrite(led,HIGH);
    }
    if (request=="GET /ledoff HTTP/1.1")
    {
      digitalWrite(led,LOW);
    }
  }

}
