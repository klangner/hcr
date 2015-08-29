#ifndef __BEHAVIOR_H__
#define __BEHAVIOR_H__

struct State {
	float posX;
	float posY;
	float direction;
	float rightWheelSpeed;
	float leftWheelSpeed;
};

struct Actuator{
	float rightWheelSpeed;
	float leftWheelSpeed;
}

class Behavior {
public:
	virtual Actuator* update(State* state) = 0;
}

#endif
