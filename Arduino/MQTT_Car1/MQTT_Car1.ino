#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Replace these with your network credentials
const char* ssid = "M33";
const char* password = "gargi1234";

// Replace with your MQTT Broker address
const char* mqtt_server = "test.mosquitto.org";

const int LeftMotorForward = D1;
const int LeftMotorBackward = D0;
const int RightMotorForward  = D2;
const int RightMotorBackward = D3;

// Initialize the WiFi and MQTT clients
WiFiClient espClient;
PubSubClient client(espClient);

// Function to handle received messages
void callback(char* topic, byte* payload, unsigned int length) 
{
  String message;
  for (unsigned int i = 0; i < length; i++) 
  {
    message += (char)payload[i];
  }

  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  Serial.println(message);

  if (message == "1") 
  {
    moveForward();
  } 
  else if (message == "2") 
  {
    moveBackward();
  } 
  else 
  {
    stop();
  }
}

// Function to reconnect to the MQTT broker
void reconnect() 
{
  while (!client.connected()) 
  {
    Serial.print("Attempting MQTT connection...");
     String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) 
    {
      Serial.println("connected");
      client.subscribe("car/control");
    } 
    else 
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

// Functions to control the car
void moveForward() 
{
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);  
  Serial.println("Car is moving forward");
}

void moveBackward() 
{
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  Serial.println("Car is moving backward");
}

void stop() 
{
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  Serial.println("Car is stopped");
}

void setup() 
{
  Serial.begin(115200);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  stop(); // Ensure the car is stopped initially

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) 
  {
    reconnect();
  }
  client.loop();
}
