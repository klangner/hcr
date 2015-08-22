#include <Arduino.h>
#include "driver.hpp"


// Keys 
static unsigned int ADC_KEY_VALUES[5] ={ 30, 150, 360, 535, 760 };
int NUM_KEYS = 5;
int oldkey=-1;
Driver driver;

void setup(void){ 
  pinMode(13, OUTPUT);  //we'll use the debug LED to output a heartbeat
  // Serial.begin(19200);      //Set Baud Rate
} 
 

// Convert ADC value to key number
int get_key(unsigned int input){   
  int k;
  for (k = 0; k < NUM_KEYS; k++)
  {
    if (input < ADC_KEY_VALUES[k])
    {  
      return k;  
    }
  }
  if (k >= NUM_KEYS)
    k = -1;     // No valid key pressed
  return k;
}



 
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

void loop() 
{
  int adc_key_in = analogRead(7);    // read the value from the sensor  
  digitalWrite(13, HIGH);
  /* get the key */
  int key = get_key(adc_key_in);    // convert into key press
  if (key != oldkey) {   // if keypress is detected
    delay(50);      // wait for debounce time
    adc_key_in = analogRead(7);    // read the value from the sensor  
    key = get_key(adc_key_in);    // convert into key press
    if (key != oldkey) {         
      oldkey = key;
      if (key >=0){
        executeAction(key);
      }
    }
  }
  digitalWrite(13, LOW);
}
