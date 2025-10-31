#include  <NewPing.h>       
#include  <Servo.h>     
#define trig_pin  A1 
#define echo_pin A2 

const  int LeftMotorForward = 4;
const int LeftMotorBackward = 3;
const int RightMotorForward  = 5;
const int RightMotorBackward = 6;



#define maximum_distance  200
int distance = 100;

NewPing sonar(trig_pin,  echo_pin, maximum_distance); 
Servo servo_motor; 

void setup(){
  Serial.begin(9600);
  servo_motor.attach(10); 
  servo_motor.write(110);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

int  readPing()
{
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  Serial.println(cm);
  return cm;
}

void moveStop()
{
  Serial.println("Stopped");
  digitalWrite(RightMotorForward,  LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward,  LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward()
{
  Serial.println("Forward");
  digitalWrite(LeftMotorForward,  HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward,  LOW);
  digitalWrite(RightMotorBackward, LOW); 
}

void moveBackward()
{
  Serial.println("Backward");
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward,  HIGH);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward,  LOW);
}

int  lookRight()
{  
  Serial.println("right");
  servo_motor.write(50);
  delay(1000);
  int distance = readPing();
  delay(100);
  servo_motor.write(110);
  return distance;
}

int  lookLeft(){
  Serial.println("left");
  servo_motor.write(170);
  delay(1000);
  int distance = readPing();
  delay(100);
  servo_motor.write(110);
  return distance;
}

void turnRight()
{
  Serial.println("Turned right");
  digitalWrite(LeftMotorForward,  HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorBackward,  LOW);
  digitalWrite(RightMotorForward, LOW);
  delay(500);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward,  LOW); 
}

void turnLeft()
{
  Serial.println("Turned left");
  digitalWrite(LeftMotorBackward,  HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorForward,  LOW);
  digitalWrite(RightMotorBackward, LOW);
  delay(500);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward,  LOW);
}

void loop()
{
  int distance=readPing();
  int distanceRight = 0;
  int  distanceLeft = 0;
  delay(50);
  if (distance>20)
  {
    moveForward();
  }

  else if(distance <= 20)
  {
    moveStop();
    moveBackward();
    delay(400);
    moveStop();
    distanceRight = lookRight();
    delay(300);
    distanceLeft  = lookLeft();
    delay(300);

    if (distanceRight >= distanceLeft)
    {
      turnRight();
      moveStop();
    }
    else 
    {
      turnLeft();
      moveStop();
    }
  }
}
