#ifndef __DRIVER_H__
#define __DRIVER_H__


class Motor {
public:
  Motor(int m, int e, int a, int b);
  void setSpeed(int level);
  int getNewTicks();
  void odoTick();

private:
  int pinM;
  int pinE;
  int phaseA;
  int phaseB;
  int odoCount;
  bool currentDirection;
};

#endif
