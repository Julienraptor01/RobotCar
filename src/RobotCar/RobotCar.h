#ifndef ROBOTCAR_H
#define ROBOTCAR_H

#define SPEED_LEFT 6
#define MOTORS_LEFT_FORWARD 7
#define MOTORS_LEFT_BACKWARD 8
#define SPEED_RIGHT 9
#define MOTORS_RIGHT_FORWARD 12
#define MOTORS_RIGHT_BACKWARD 11
#define MAX_SPEED 1500
#define LEFT false
#define RIGHT true

void setup();
void loop();

void initPins();
void setSpeed(int speedLeft = 0, int speedRight = 0);
void setSpeedLeft(int speedLeft = 0);
void setSpeedRight(int speedRight = 0);
void stopMotors();
void straight(int speed = 0, unsigned int time = 0);
void rotate(bool direction = false, unsigned int speed = 0, unsigned int time = 0);

#endif
