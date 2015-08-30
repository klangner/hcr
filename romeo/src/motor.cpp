#include <Arduino.h>
#include "motor.h"

Motor* motor2 = NULL;
Motor* motor3 = NULL;

void interrupt2(){
  if(motor2 != NULL)
    motor2->odoTick();
}

void interrupt3(){
  if(motor3 != NULL)
    motor3->odoTick();
}

Motor::Motor(int m, int e, int a, int b){
  pinM = m;
  pinE = e;
  phaseA = a;
  phaseB = b;
  odoCount = 0;
  pinMode(phaseB,INPUT);
  if(phaseA == 2){
    motor2 = this;
    attachInterrupt(0, interrupt2, CHANGE);
  }else{
    motor3 = this;
    attachInterrupt(1, interrupt3, CHANGE);
  }
  pinMode(pinM, OUTPUT);
  pinMode(pinE, OUTPUT);
  currentDirection = true;
  digitalWrite(pinM,LOW);
  analogWrite(pinE, 0);
}


void Motor::setSpeed(int speed){
  int dir = speed >=0;
  if(dir != currentDirection){
    if(dir) digitalWrite(pinM,LOW);
    else digitalWrite(pinM,HIGH);
    currentDirection = dir;
  }
  char level = char(max(255, abs(speed)));
  analogWrite (pinE, level);
}

int Motor::getNewTicks(){
  int ticks = odoCount;
  odoCount = 0;
  return ticks;
}

void Motor::odoTick(){
  int a = digitalRead(phaseA);
  if(a == HIGH){
    int b = digitalRead(phaseB);
    bool bExpected = phaseA == 2 ? HIGH : LOW;
    if(b == bExpected){
      odoCount++;
    }
    else{
      odoCount--;
    }
  }
}
