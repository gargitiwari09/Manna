#include <SoftwareSerial.h>

SoftwareSerial SIM7670Serial(2, 3); // RX, TX

void sendATCommand(const char* cmd, const char* expectedResponse, unsigned long timeout) 
{
  SIM7670Serial.println(cmd);
  String response = "";
  response.reserve(50);
  unsigned long startTime = millis();
  bool responseOK = false;

  while (millis() - startTime < timeout)
  {
    while (SIM7670Serial.available() > 0)
    {
      char c = SIM7670Serial.read();
      response += c;
    }
    if (response.indexOf(expectedResponse) != -1)
    {
      responseOK = true;
      break; // found it
    }
  }
  Serial.println(response);

  if (responseOK)
  {
    Serial.println("Response OK");
  }
  else
  {
    Serial.println("Timeout without expected Response");
  }
}

void setup() 
{
  Serial.begin(115200);
  SIM7670Serial.begin(9600);
  sendATCommand("AT", "OK", 1000); // check communication
}

void loop() {}
