
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define LED_PIN 3
byte readCard[4];
String MasterTag = "3696DE32";
String tagID = "";
// Create instances
MFRC522 mfrc522(SS_PIN, RST_PIN);



void setup() 
{
  Serial.begin(9600);
  pinMode(LED_PIN,OUTPUT);
  SPI.begin();
  mfrc522.PCD_Init();
  delay(4);
  mfrc522.PCD_DumpVersionToSerial();
  Serial.println("--------------------------");
  Serial.println(" Access Control ");
  Serial.println("Scan Your Card>>");
}

void loop() 
{

  while (getID()) {
    digitalWrite(LED_PIN,LOW);
    if (tagID == MasterTag){
      Serial.println(" Access Granted!");
      Serial.println("--------------------------");
      digitalWrite(LED_PIN,HIGH);
   
    }
    else{
      Serial.println(" Access Denied!");
      Serial.println("--------------------------");
      digitalWrite(LED_PIN,LOW);
    }
    delay(2000);
    Serial.println(" Access Control ");
    Serial.println("Scan Your Card>>");
  }
}




boolean getID() 
{
  
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return false;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {
  return false;
  }
  tagID = "";
  for ( uint8_t i = 0; i < 4; i++) {
  tagID.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  tagID.toUpperCase();
  mfrc522.PICC_HaltA(); // Stop reading
  return true;
}