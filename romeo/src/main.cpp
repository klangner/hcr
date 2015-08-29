#include <Arduino.h>
#include "driver.h"


const int DELTA_TIME = 10;

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
    if(left > 0){
      setLeftWheel(true, left);
    }else{
      setLeftWheel(false, -left);
    }
    if(right > 0){
      setRightWheel(true, right);
    }else{
      setRightWheel(false, right);
    }
  }
}


void setup(void){
  Serial.begin(57600);
  Serial.println("Ready.");
  initMotors();
}

void loop(){
  // Send state
  int leftEncoderCount = encoderLeftTicks();
  int rightEncoderCount = encoderRightTicks();
  sendState(leftEncoderCount, rightEncoderCount);
  updateMotors();
  delay(DELTA_TIME);
}
