#include <Arduino.h>

int DELTA_TIME = 10;
char HEADER = 'H';


void setup() {
  Serial.begin(57600);
  Serial.println("Ready.");
}

void loop2(){
  if(Serial.available() == 5){
    if(Serial.read() == HEADER){
      char leftDir = Serial.read();
      int leftSpeed = int(Serial.read());
      if(leftDir == '-')
        leftSpeed = -leftSpeed;
      char rightDir = Serial.read();
      int rightSpeed = int(Serial.read());
      if(rightDir == '-')
        rightSpeed = -rightSpeed;

      Serial.print("Arduino: ");
      Serial.print(leftSpeed);
      Serial.print(" ");
      Serial.print(rightSpeed);
      Serial.println();
    }
  }

  delay(DELTA_TIME);
}


void loop(){
  String text = Serial.readStringUntil('\n');
  if(text.length() > 0){
    int i = text.indexOf(' ');
    if(i > 0){
      int left = text.substring(0, i).toInt();
      int right = text.substring(i+1).toInt();
      Serial.print("(");
      Serial.print(left);
      Serial.print(",");
      Serial.print(right);
      Serial.println(")");
    }
  }

  delay(DELTA_TIME);
}
