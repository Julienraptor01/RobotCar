#ifndef ROBOTCAR_H
#define ROBOTCAR_H

#define SPEED_LEFT 6
#define MOTOR_LEFT_1 7
#define MOTOR_LEFT_2 8
#define SPEED_RIGHT 9
#define MOTOR_RIGHT_1 12
#define MOTOR_RIGHT_2 11

void setup();
void loop();

void initPins();
void stopMotors();
void setSpeed(int speedLeft = 0, int speedRight = 0);
void setSpeedLeft(int speedLeft = 0);
void setSpeedRight(int speedRight = 0);

#endif
