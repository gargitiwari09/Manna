const int sensor = D5;             
int val = LOW; 
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

WiFiClient client;

long myChannelNumber = 2564329;
const char myWriteAPIKey[] = "BHIT9TFBDP200Z1J";  

void setup() 
{
  pinMode(sensor,INPUT);
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
  ThingSpeak.begin(client);
}

void loop() 
{
  val = digitalRead(sensor);  
  Serial.println(val); 
  ThingSpeak.writeField(myChannelNumber,1,val,myWriteAPIKey);
  delay(1000);
}
