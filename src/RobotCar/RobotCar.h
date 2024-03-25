#ifndef ROBOTCAR_H
#define ROBOTCAR_H

#define SPEED_LEFT 6
#define MOTORS_LEFT_FORWARD 7
#define MOTORS_LEFT_BACKWARD 8
#define SPEED_RIGHT 9
#define MOTORS_RIGHT_FORWARD 12
#define MOTORS_RIGHT_BACKWARD 11

#define MAX_SPEED 1500

#define DISTANCE_BETWEEN_WHEELS 14

#define LEFT false
#define RIGHT true

#define IR_REMOTE_PIN 10

#define IR_REMOTE_UP 0x18
#define IR_REMOTE_RIGHT 0x5A
#define IR_REMOTE_DOWN 0x52
#define IR_REMOTE_LEFT 0x08
#define IR_REMOTE_OK 0x1C
#define IR_REMOTE_0 0x19
#define IR_REMOTE_1 0x45
#define IR_REMOTE_2 0x46
#define IR_REMOTE_3 0x47
#define IR_REMOTE_4 0x44
#define IR_REMOTE_5 0x40
#define IR_REMOTE_6 0x43
#define IR_REMOTE_7 0x07
#define IR_REMOTE_8 0x15
#define IR_REMOTE_9 0x09
#define IR_REMOTE_STAR 0x16
#define IR_REMOTE_HASHTAG 0x0D

typedef enum state
{
	STOP,
	FORWARD,
	BACKWARD,
	LEFTWARD,
	RIGHTWARD
} state;

state currentState = STOP;

void setup();
void loop();

void initPins();
void setSpeed(int speedLeft = 0, int speedRight = 0);
void setSpeedLeft(int speedLeft = 0);
void setSpeedRight(int speedRight = 0);
void stopMotors();
void straight(int speed = 0, unsigned int time = 0);
void move(bool direction = false, int speed = 0, int ratio = 0, unsigned int time = 0);
void rotate(bool direction = false, unsigned int speed = 0, unsigned int time = 0);

#endif
