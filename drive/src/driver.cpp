#include <Arduino.h>
#include "driver.hpp"

// Encode pins
int ENCODER_RIGHT_A = 2;
int ENCODER_RIGHT_B = 4;
int ENCODER_LEFT_A = 3;
int ENCODER_LEFT_B = 8;
//Standard PWM DC control
int E1 = 5;     //M1 Speed Control
int E2 = 6;     //M2 Speed Control
int M1 = 4;    //M1 Direction Control
int M2 = 7;    //M1 Direction Control
// Robot size
float WHEEL_BASE = 0.285;
float WHEEL_RADIUS2 = 0.135;

int rightCount = 0;
int leftCount = 0;

void encoderRight()
{
  int state = digitalRead(ENCODER_RIGHT_A);
  digitalWrite(13, state);
  if(state == HIGH){
    // int val = digitalRead(ENCODER_RIGHT_B);
    // int direction = (val == HIGH);
    rightCount++;
  }
}

void encoderLeft()
{
  int state = digitalRead(ENCODER_LEFT_A);
  digitalWrite(13, state);
  if(state == HIGH){
    // int val = digitalRead(ENCODER_RIGHT_B);
    // int direction = (val == HIGH);
    leftCount++;
  }
}

Driver::Driver(){
  pinMode(ENCODER_RIGHT_B,INPUT);
  pinMode(ENCODER_LEFT_B,INPUT);
  attachInterrupt(0, encoderRight, CHANGE);
  attachInterrupt(1, encoderLeft, CHANGE);
  for(int i=4;i<=7;i++)
    pinMode(i, OUTPUT);
}

void Driver::move(float velocity, float angularVelocity){
  float velocityRight = (2*velocity+angularVelocity*WHEEL_BASE)/WHEEL_RADIUS2;
  float velocityLeft = (2*velocity-angularVelocity*WHEEL_BASE)/WHEEL_RADIUS2;
  if(velocityRight > 0){
    analogWrite (E1,velocityToPcm(velocityRight));
    digitalWrite(M1,LOW);
  }
  else {
    analogWrite (E1,velocityToPcm(-velocityRight));
    digitalWrite(M1,HIGH);
  }
  if(velocityLeft > 0){
    analogWrite (E2,velocityToPcm(velocityLeft));
    digitalWrite(M2,LOW);
  }
  else {
    analogWrite (E2,velocityToPcm(-velocityLeft));
    digitalWrite(M2,HIGH);
  }
}

void Driver::moveForward(float velocity){
  move(velocity, 0);
}

void Driver::moveBackward(float velocity){
  move(-velocity, 0);
}

void Driver::turnLeft(float angularVelocity){
  move(0, angularVelocity);
}

void Driver::turnRight(float angularVelocity){
  move(0, -angularVelocity);
}

void Driver::stop(){
  digitalWrite(E1,LOW);
  digitalWrite(E2,LOW);
}

char Driver::velocityToPcm(float velocity){
  return char(min(100*velocity, 255));
}
