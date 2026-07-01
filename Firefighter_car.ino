#include <L298N.h>
#include <SoftwareSerial.h> 
#include <Servo.h> 

Servo myservo; 
SoftwareSerial BTserial(0, 1); 
int IN1 = 2;    // the control of DC motors
int IN2 = 4; 
int ENA = 3;
int IN3 = 7;
int IN4 = 8;
int ENB = 5; 
int flameSensor1 = 6;    // right flame sensor of car
int flameSensor2 = 10;   // left flame sensor of car 
int pumpDirection1Pin = 11; 
int pumpDirection2Pin = 12; 
int EN1= 13;             // pump speed control
int red = A0;            // Pin for red LED
int blue = A1;           // Pin for blue LED
int buzzer = A2;         // pin for buzzer alert 
int flame_pin1;          // state of sensor 1
int flame_pin2;          // atate of sensor 2
int pos = 90; 
bool hasTurned180 = false; // global variable to keep track of whether the servo has turned 180 degrees

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(flameSensor1, INPUT);
  pinMode(flameSensor2, INPUT);
  pinMode(pumpDirection1Pin, OUTPUT);
  pinMode(pumpDirection2Pin, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(buzzer, OUTPUT);
  myservo.attach(9); 

  
  Serial.begin(9600);
  Serial.println("Start Program");

  Serial.println("Start Connecting BT");
  BTserial.begin(9600); 
  Serial.print("flameSnsor1: "); //print value of sensor on serial monitor 
  Serial.println(digitalRead(flameSensor1));
  Serial.print("flameSnsor2: ");
  Serial.println(digitalRead(flameSensor2));
}

void loop() {
flame_pin1 = digitalRead(flameSensor1);  // reading from the sensor1
flame_pin2 = digitalRead(flameSensor2);  // reading from the sensor2 
unsigned long startTime = millis(); // record start time

  if (flame_pin1 == HIGH || flame_pin2 == HIGH) {
  digitalWrite(pumpDirection1Pin, HIGH);
  digitalWrite(pumpDirection2Pin, LOW);
  analogWrite(EN1, 255);
  while (millis() - startTime < 5000) {
  for (pos = 10; pos <= 170; pos += 10) { // repeat for 5 seconds
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(buzzer, HIGH);
    delay(150); 
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
    digitalWrite(buzzer, LOW);
    delay(150);  
    myservo.write(pos); 
    delay(20);
   }
  }
    }else {
  // If no flame is detected, turn off water pump and servo
  digitalWrite(pumpDirection1Pin, LOW);
  digitalWrite(pumpDirection2Pin, LOW);
  analogWrite(EN1, 0);
  myservo.write(90);
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);  
  digitalWrite(buzzer, LOW);
   }  
  if (BTserial.available()) { 
    char command = BTserial.read();
    // control the fire fighter car using the command received from Bluetooth

    if (command == 'F') { // move forward
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENA, 240);
      analogWrite(ENB, 240);    
    } else if (command == 'B') { // move backward
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, 240);
      analogWrite(ENB, 240);      
    } else if (command == 'S') { // stop
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, 0);
      analogWrite(ENB, 0);
    } else if (command == 'R'){// right
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENB, 240);
      analogWrite(ENA, 240);  
    } else if (command == 'L'){// left
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, 240);
      analogWrite(ENB, 240);      
    }
  }
}