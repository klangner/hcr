#include <Arduino.h>
#include "driver.hpp"
#include "buttons.h"


Driver driver;

void executeAction(int action){
  delay(1000);
  
  switch(action){
    case 0:
      driver.turnLeft(0.5f, 0);
      break;
    case 1:
      driver.moveBackward(0.5f);
      break;
    case 2:
      driver.turnRight(0.5f, 0);
      break;
    case 3:
      driver.moveForward(1);
      break;
  }

  delay(3000);
  driver.stop();
}

void setup(void){ 
  pinMode(13, OUTPUT);  //we'll use the debug LED to output a heartbeat
  // Serial.begin(19200);      //Set Baud Rate
} 

void loop() 
{
  digitalWrite(13, HIGH);
  int key = getPressedButton();
  if (key >=0) executeAction(key);
  digitalWrite(13, LOW);
}
