const int led = 9;         
const int sensor = 5;             
int val = LOW;                 

void  setup() 
{ 
  pinMode(led, OUTPUT);    
  pinMode(sensor, INPUT);  
  Serial.begin(9600);      
}

void loop()
{ 
  val = digitalRead(sensor);   
  if  (val == HIGH) 
  {           
    digitalWrite(led, HIGH);
    Serial.println("Detected");
  } 
  if(val==LOW) 
  {
    digitalWrite(led, LOW);
    Serial.println("Not detected");
  }
}
