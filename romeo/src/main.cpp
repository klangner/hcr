#include <Arduino.h>
#include "motor.h"


const int DELTA_TIME = 10;
Motor* leftMotor;
Motor* rightMotor;

// Robot size in meters.
// #define WHEEL_BASE 0.285f
// #define WHEEL_RADIUS2 0.135f


void sendState(int l, int r){
  Serial.print("(");
  Serial.print(l);
  Serial.print(",");
  Serial.print(r);
  Serial.println(")");
}

void updateMotors(){
  if(Serial.available()){
    int left = Serial.parseInt();
    int right = Serial.parseInt();
    leftMotor->setSpeed(left);
    rightMotor->setSpeed(right);
  }
}


void setup(void){
  Serial.begin(57600);
  Serial.println("Ready.");
  leftMotor = new Motor(7, 6, 3, 9);
  rightMotor = new Motor(4, 5, 2, 8);
}

void loop(){
  // Send state
  int l = leftMotor->getNewTicks();
  int r = rightMotor->getNewTicks();
  sendState(l, r);
  updateMotors();
  delay(DELTA_TIME);
}
