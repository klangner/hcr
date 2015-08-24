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

int r = 0;
void encoderRight()
{
  int state = digitalRead(ENCODER_RIGHT_A);
  digitalWrite(13, state);
  if(state == HIGH){
    // int val = digitalRead(ENCODER_RIGHT_B);
    // int direction = (val == HIGH);
    Serial.println(r++);
  }
}

int l = 0;
void encoderLeft()
{
  int state = digitalRead(ENCODER_LEFT_A);
  digitalWrite(13, state);
  if(state == HIGH){
    // int val = digitalRead(ENCODER_RIGHT_B);
    // int direction = (val == HIGH);
    Serial.println(l++);
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

void Driver::moveForward(float speed){
  char v = char(255*speed);
  analogWrite (E1,v);
  digitalWrite(M1,LOW);
  analogWrite (E2,v);
  digitalWrite(M2,LOW);
}

void Driver::moveBackward(float speed){
  char v = char(255*speed);
  analogWrite (E1,v);
  digitalWrite(M1,HIGH);
  analogWrite (E2,v);
  digitalWrite(M2,HIGH);
}

void Driver::turnLeft(float speed, float radius){
  char v = char(255*speed);
  analogWrite (E1,v);
  digitalWrite(M1,LOW);
  analogWrite (E2,v);
  digitalWrite(M2,HIGH);
}

void Driver::turnRight(float speed, float radius){
  char v = char(255*speed);
  analogWrite (E1,v);
  digitalWrite(M1,HIGH);
  analogWrite (E2,v);
  digitalWrite(M2,LOW);
}

void Driver::stop(){
  digitalWrite(E1,LOW);
  digitalWrite(E2,LOW);
}
