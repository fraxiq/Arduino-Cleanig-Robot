
#include <NewPing.h>
#include <Servo.h> 

#define TRIG_PIN 5
#define ECHO_PIN 4 
#define MAX_DISTANCE 200 
#define MAX_SPEED 190 
#define MAX_SPEED_OFFSET 20

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 

int motorPinLB = 12;     // define pin 12 
int motorPinLF = 3;     // define pin 3 
int motorPinRB = 13;    // define pin 13 
int motorPinRF = 11;    // define pin 11 

Servo myservo;   

boolean goesForward=false;
int distance = 100;
int speedSet = 0;

void setup() {

  myservo.attach(10);  
  myservo.write(90); 
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

void loop() {
 int distanceR = 0;
 int distanceL =  0;
 delay(40);
 
 if(distance<=15)
 {
  moveStop();
  delay(100);
  moveBackward();
  delay(2000);
  moveStop();
  delay(200);
  distanceR = lookRight();
  delay(200);
  distanceL = lookLeft();
  delay(200);

  if(distanceR>=distanceL)
  {
    
    turnRight();
    moveStop();
  }else
  {
   
    turnLeft();
    moveStop();
  }
 }else
 {
  moveForward();
 }
 
 distance = readPing();
}

int lookRight()
{
    myservo.write(50); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(90); 
    return distance;
}

int lookLeft()
{
    myservo.write(170); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(90); 
    return distance;
    delay(100);
}

int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 25;
  }
  return cm;
}

void moveStop() {
  digitalWrite(motorPinLB,LOW);
  digitalWrite(motorPinLF,LOW);
  digitalWrite(motorPinRB,LOW);
  digitalWrite(motorPinRF,LOW);
  } 
  
void moveForward() {

 if(!goesForward)
  {
    goesForward=true;
    digitalWrite(motorPinLB,LOW);
    digitalWrite(motorPinLF,HIGH);
    digitalWrite(motorPinRB,LOW);
    digitalWrite(motorPinRF,HIGH);
  }
}

void moveBackward() {
    goesForward=false;
    digitalWrite(motorPinLB,HIGH);
    digitalWrite(motorPinLF,LOW);
    digitalWrite(motorPinRB,HIGH);
    digitalWrite(motorPinRF,LOW);
}  

void turnRight() {
  digitalWrite(motorPinLB,LOW);
  digitalWrite(motorPinLF,HIGH);
  digitalWrite(motorPinRB,HIGH);
  digitalWrite(motorPinRF,LOW);    
  delay(500);
  digitalWrite(motorPinLB,LOW);
  digitalWrite(motorPinLF,HIGH);
  digitalWrite(motorPinRB,LOW);
  digitalWrite(motorPinRF,HIGH);      
} 
 
void turnLeft() {
  digitalWrite(motorPinLB,HIGH);
  digitalWrite(motorPinLF,LOW);
  digitalWrite(motorPinRB,LOW);
  digitalWrite(motorPinRF,HIGH);     
  delay(500);
  digitalWrite(motorPinLB,LOW);
  digitalWrite(motorPinLF,HIGH);
  digitalWrite(motorPinRB,LOW);
  digitalWrite(motorPinRF,HIGH);
}  
