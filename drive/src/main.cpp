#include <Arduino.h>
#include "driver.hpp"
#include "buttons.h"


Driver driver;

void executeAction(int action){
  delay(1000);

  switch(action){
    case 0:
      driver.turnLeft(0.5f);
      break;
    case 1:
      driver.moveBackward(0.5f);
      break;
    case 2:
      driver.turnRight(0.5f);
      break;
    case 3:
      driver.moveForward(1);
      break;
  }

  delay(3000);
  driver.stop();
}

void setup(void){
  pinMode(13, OUTPUT);
  Serial.begin(19200);
  Serial.println("Ready.");
  digitalWrite(13, HIGH);
}

void loop()
{
  int key = getPressedButton();
  if (key >=0) executeAction(key);
}
