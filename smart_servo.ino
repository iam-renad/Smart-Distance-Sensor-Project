#include <Servo.h>

Servo myServo;        
const int trigPin = 9;    
const int echoPin = 10;   
const int servoPin = 6;   
const int ledPin = 8;     

long duration;
int distance;

void setup() {
  myServo.attach(servoPin);   
  pinMode(trigPin, OUTPUT);   
  pinMode(echoPin, INPUT);    
  pinMode(ledPin, OUTPUT);    
  Serial.begin(9600);       
  
  myServo.write(0);         
  digitalWrite(ledPin, LOW);  
  delay(1000);              
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); 
  distance = duration * 0.034 / 2;   

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 10) {  
    myServo.write(90);        
    digitalWrite(ledPin, HIGH); 
  } 
  else {               
    myServo.write(0);         
    digitalWrite(ledPin, LOW);  
  }
  
  delay(100); 
}