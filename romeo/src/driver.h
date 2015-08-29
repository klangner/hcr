#ifndef __DRIVER_H__
#define __DRIVER_H__


void initMotors();

void setRightWheel(bool direction, char level);
void setLeftWheel(bool direction, char level);

int encoderLeftTicks();
int encoderRightTicks();

#endif
