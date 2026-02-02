#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *rightMotor = AFMS.getMotor(4);
Adafruit_DCMotor *leftMotor = AFMS.getMotor(3);

long duration, distance;

void setup() {
  // put your setup code here, to run once:
  AFMS.begin();
  pinMode(7,OUTPUT);
  pinMode(8,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  forward();
  delay(500);
  turnLeft();
  delay(500):
  turnRight();
  delay(500);
  backward();
  delay(500);
}

void forward(){
  rightMotor->setSpeed(100);
  leftMotor->setSpeed(100);

  rightMotor->run(FORWARD);
  leftMotor->run(FORWARD);
}

void backward(){
  rightMotor->setSpeed(100);
  leftMotor->setSpeed(100);

  rightMotor->run(BACKWARD);
  leftMotor->run(BACKWARD);
}

void turnLeft(){
  rightMotor->setSpeed(100);
  leftMotor->setSpeed(0);

  rightMotor->run(FORWARD);
  leftMotor->run(BACKWARD);
}

void turnRight(){
  rightMotor->setSpeed(0);
  leftMotor->setSpeed(100);

  rightMotor->run(BACKWARD);
  leftMotor->run(FORWARD);
}

long distanceTest(){
  digitalWrite(7,LOW);
  delayMicroseconds(2);
  digitalWrite(7,HIGH);
  delayMicorseconds(10);
  digitalWrite(7,LOW);
  duration = pulseIn(8,HIGH);
  distance = duration * 0.0133 /2;
  Serial.print("Distance=");
  Serial.println(distance);
  return distance;
}

void 