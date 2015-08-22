#include <Arduino.h>
#include "buttons.h"

// Keys 
static unsigned int ADC_KEY_VALUES[5] ={ 30, 150, 360, 535, 760 };
int NUM_KEYS = 5;
int oldkey=-1;


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

int getPressedButton(){
  int adc_key_in = analogRead(7);    // read the value from the sensor  
  int key = get_key(adc_key_in);    // convert into key press
  if (key != oldkey) {   // if keypress is detected
    delay(50);      // wait for debounce time
    adc_key_in = analogRead(7);    // read the value from the sensor  
    key = get_key(adc_key_in);    // convert into key press
    if (key != oldkey) {         
      oldkey = key;
      if (key >=0) return key;
    }
  }
  return -1;
}
