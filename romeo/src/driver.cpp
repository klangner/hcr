#include <Arduino.h>
#include "driver.h"

// Encode pins
const int ENCODER_RIGHT_A = 2;
const int ENCODER_RIGHT_B = 4;
const int ENCODER_LEFT_A = 3;
const int ENCODER_LEFT_B = 8;
//Standard PWM DC control
const int E1 = 5;
const int E2 = 6;
const int M1 = 4;
const int M2 = 7;

// Odometer ticks
int rightCount = 0;
int leftCount = 0;

void encoderRight()
{
  int state = digitalRead(ENCODER_RIGHT_A);
  if(state == HIGH){
    // int val = digitalRead(ENCODER_RIGHT_B);
    // int direction = (val == HIGH);
    rightCount++;
  }
}

void encoderLeft()
{
  int state = digitalRead(ENCODER_LEFT_A);
  if(state == HIGH){
    leftCount++;
  }
}

void initMotors(){
  pinMode(ENCODER_RIGHT_B,INPUT);
  pinMode(ENCODER_LEFT_B,INPUT);
  attachInterrupt(0, encoderRight, CHANGE);
  attachInterrupt(1, encoderLeft, CHANGE);
  for(int i=4;i<=7;i++)
    pinMode(i, OUTPUT);
}

void setRightWheel(bool direction, char level){
  if(direction) digitalWrite(M1,LOW);
  else digitalWrite(M1,HIGH);
  analogWrite (E1, level);
}

void setLeftWheel(bool direction, char level){
  if(direction) digitalWrite(M2,LOW);
  else digitalWrite(M2,HIGH);
  analogWrite (E2, level);
}

int encoderLeftTicks(){
  int ticks = leftCount;
  leftCount = 0;
  return ticks;
}

int encoderRightTicks(){
  int ticks = rightCount;
  rightCount = 0;
  return ticks;
}
