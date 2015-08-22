#include <Arduino.h>
#include "driver.hpp"

//Standard PWM DC control
int E1 = 5;     //M1 Speed Control
int E2 = 6;     //M2 Speed Control
int M1 = 4;    //M1 Direction Control
int M2 = 7;    //M1 Direction Control


Driver::Driver(){
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
