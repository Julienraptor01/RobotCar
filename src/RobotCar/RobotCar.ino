#include "RobotCar.h"

/**
 * @author Julienraptor01
 * @brief First called function
 * @return void
 */
void setup()
{
	Serial.begin(115200);

	initPins();
	stopMotors();
	setSpeed();
}

/**
 * @author Julienraptor01
 * @brief Second repeatedly called function
 * @return void
 */
void loop()
{
}

/**
 * @author Julienraptor01
 * @brief Initialize the pins
 * @return void
 */
void initPins()
{
	pinMode(SPEED_LEFT, OUTPUT);

	pinMode(MOTORS_LEFT_FORWARD, OUTPUT);
	pinMode(MOTORS_LEFT_BACKWARD, OUTPUT);

	pinMode(SPEED_RIGHT, OUTPUT);

	pinMode(MOTORS_RIGHT_FORWARD, OUTPUT);
	pinMode(MOTORS_RIGHT_BACKWARD, OUTPUT);
}

/**
 * @author Julienraptor01
 * @brief Set the speed of the motors
 * @param speedLeft The speed of the left motor
 * @param speedRight The speed of the right motor
 * @return void
 */
void setSpeed(int speedLeft, int speedRight)
{
	setSpeedLeft(speedLeft);
	setSpeedRight(speedRight);
}

/**
 * @author Julienraptor01
 * @brief Set the speed of the left motor
 * @param speedLeft The speed of the left motor
 * @return void
 */
void setSpeedLeft(int speedLeft)
{
	analogWrite(SPEED_LEFT, speedLeft);
}

/**
 * @author Julienraptor01
 * @brief Set the speed of the right motor
 * @param speedRight The speed of the right motor
 * @return void
 */
void setSpeedRight(int speedRight)
{
	analogWrite(SPEED_RIGHT, speedRight);
}

/**
 * @author Julienraptor01
 * @brief Stop the motors
 * @return void
 */
void stopMotors()
{
	digitalWrite(MOTORS_LEFT_FORWARD, LOW);
	digitalWrite(MOTORS_LEFT_BACKWARD, LOW);
	digitalWrite(MOTORS_RIGHT_FORWARD, LOW);
	digitalWrite(MOTORS_RIGHT_BACKWARD, LOW);
}

/**
 * @author Julienraptor01
 * @brief Move the robot straight
 * @param time The time to move straight
 * @param speed The speed to move straight
 * @return void
 */
void straight(int speed, int time)
{
	switch (speed >= 0)
	{
	case true:
		digitalWrite(MOTORS_LEFT_BACKWARD, LOW);
		digitalWrite(MOTORS_RIGHT_BACKWARD, LOW);
		digitalWrite(MOTORS_LEFT_FORWARD, HIGH);
		digitalWrite(MOTORS_RIGHT_FORWARD, HIGH);
	case false:
		digitalWrite(MOTORS_LEFT_FORWARD, LOW);
		digitalWrite(MOTORS_RIGHT_FORWARD, LOW);
		digitalWrite(MOTORS_LEFT_BACKWARD, HIGH);
		digitalWrite(MOTORS_RIGHT_BACKWARD, HIGH);
	}
	setSpeed(abs(speed), abs(speed));
	delay(time);
	stopMotors();
}

