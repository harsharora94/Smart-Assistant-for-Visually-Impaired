#include <Servo.h>

// 1st Ultrasonic Sensor
#define trigPin1 3
#define echoPin1 4

// 2nd Ultrasonic Sensor
#define trigPin2 5
#define echoPin2 6

// 3rd Ultrasonic Sensor
#define trigPin3 7
#define echoPin3 8

// 1st servo
#define servoPin1 9

// 2nd servo
#define servoPin2 10

// 3rd servo
#define servoPin3 11

int scaledServoValue = 0;
long duration, distance, RightSensor, FrontSensor, LeftSensor;
Servo servo1;
Servo servo2;
Servo servo3;
int i = 0;
void setup()
{
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
}

void loop() 
{
  delay(500);
  SonarSensor(trigPin1, echoPin1);
  RightSensor = distance;
  
  delay(500);
  SonarSensor(trigPin2, echoPin2);
  LeftSensor = distance;
  
  delay(500);
  SonarSensor(trigPin3, echoPin3);
  FrontSensor = distance;

  Serial.print("\nFirst Sensor Distance from Object = ");
  Serial.print(LeftSensor);
  Serial.print(" cm");
  
  Serial.print("\nSecond Sensor Distance from Object = ");
  Serial.print(FrontSensor);
  Serial.print(" cm");
  
  Serial.print("\nThird Sensor Distance from Object = ");
  Serial.print(RightSensor);
  Serial.print(" cm ");

  //**CONDITION FOR GUIDANCE**

  if (RightSensor < 50 || LeftSensor < 50 || FrontSensor < 50)/*if there's an obstacle in right&left&front do the following: */ 
 {   
  for (int i = 0; i < 180; i++) {
    servo1.write(i);             
    servo2.write(i);    
    servo3.write(i);
    delay(1);                     
  }
   for (i = 180; i > 0; i--) {
    servo1.write(i);               
    servo2.write(i);    
    servo3.write(i);
    delay(1);                     
  }
 }
 
  if (RightSensor < 100 || LeftSensor < 100 || FrontSensor < 100)/*if there's an obstacle in right&left&front do the following: */ 
 {   
  for (int i = 0; i < 180; i++) {
    servo1.write(i);             
    servo2.write(i);    
    servo3.write(i);
    delay(7);                     
  }
   for (i = 180; i > 0; i--) {
    servo1.write(i);               
    servo2.write(i);    
    servo3.write(i);
    delay(7);                     
  }
 }

  if (RightSensor < 150 || LeftSensor < 150 || FrontSensor < 150)/*if there's an obstacle in right&left&front do the following: */ 
 {   
  for (int i = 0; i < 180; i++) {
    servo1.write(i);             
    servo2.write(i);    
    servo3.write(i);
    delay(12);                     
  }
   for (i = 180; i > 0; i--) {
    servo1.write(i);               
    servo2.write(i);    
    servo3.write(i);
    delay(12);                     
  }
 }
}

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);

digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);

distance = (duration/2) / 29.1;

}