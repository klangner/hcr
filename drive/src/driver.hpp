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
	void moveForward(float speed);
	void moveBackward(float speed);
	void turnRight(float speed, float radius);
	void turnLeft(float speed, float radius);
	void stop();
};

#endif