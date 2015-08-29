#include <Arduino.h>

int DELTA_TIME = 10;
// Keys
static unsigned int ADC_KEY_VALUES[5] ={ 30, 150, 360, 535, 760 };
int NUM_KEYS = 5;
int oldkey=-1;
int keyDownTime = 0;

// Convert ADC value to key number
int get_key(unsigned int input){
  int k;
  for (k = 0; k < NUM_KEYS; k++){
    if (input < ADC_KEY_VALUES[k]){
      return k;
    }
  }
  if (k >= NUM_KEYS)
    k = -1;     // No valid key pressed
  return k;
}

int getPressedButton(){
  // skip debounce
  if(keyDownTime > 0){
    keyDownTime -= DELTA_TIME;
    return -1;
  }
  int adc_key_in = analogRead(7);
  int key = get_key(adc_key_in);
  if (key != oldkey) {
    oldkey = key;
    if(key >=0){
      keyDownTime = 100;
      return key;
    }
  }
  return -1;
}


class Behavior {
public:
  virtual void update() = 0;
};

class WaitBehavior : public Behavior {
public:
  WaitBehavior(){
    Serial.println("Wait");
  };

  void update() {};
};


Behavior* currentBehavior = NULL;
int lastTime = 0;
void setup() {
  Serial.begin(57600);
  Serial.println("Ready.");
  currentBehavior =  new WaitBehavior();
}

void loop(){
  int key = getPressedButton();
  Serial.print(millis()-lastTime);
  lastTime = millis();
  Serial.println(" (-255,-255), (-255,-255), (-255,-255), (-255,-255)");
  if(key >= 0){
    Serial.print(": Key=");
    Serial.println(key);
  }
  delay(10);
}
