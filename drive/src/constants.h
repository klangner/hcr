#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

// Length of time step in milliseconds
int TIME_STEP = 10;
// Encode pins
int ENCODER_RIGHT_A = 2;
int ENCODER_RIGHT_B = 4;
int ENCODER_LEFT_A = 3;
int ENCODER_LEFT_B = 8;
//Standard PWM DC control
int E1 = 5;     // Right Speed Control
int E2 = 6;     // Left Speed Control
int M1 = 4;    // Right Direction Control
int M2 = 7;    // Left Direction Control

// Robot size
float WHEEL_BASE = 0.285;
float WHEEL_RADIUS2 = 0.135;


#endif
