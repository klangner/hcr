#ifndef __DRIVER_H__
#define __DRIVER_H__

/*
	Driver for steering robot.
	Forward and backward speed is given in meters/second.
	turning speed is in radians/second with radius in meters
*/
class Driver {
public:
	Driver();
	void move(float velocity, float angularVelocity);
	void moveForward(float velocity);
	void moveBackward(float velocity);
	void turnRight(float angularVelocity);
	void turnLeft(float angularVelocity);
	void stop();

private:
	char velocityToPcm(float velocity);
};

#endif
