#include "RobotCar.h"

/**
 * @author Julienraptor01
 * @brief First called function
 * @return void
 */
void setup()
{
	Serial.begin(115200);
	Serial.println("RobotCar Hello World!");

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
	Serial.println("RobotCar Loop");
	delay(1000);
}

/**
 * @author Julienraptor01
 * @brief Initialize the pins
 * @return void
 */
void initPins()
{
	pinMode(SPEED_LEFT, OUTPUT);

	pinMode(MOTOR_LEFT_1, OUTPUT);
	pinMode(MOTOR_LEFT_2, OUTPUT);

	pinMode(SPEED_RIGHT, OUTPUT);

	pinMode(MOTOR_RIGHT_1, OUTPUT);
	pinMode(MOTOR_RIGHT_2, OUTPUT);
}

/**
 * @author Julienraptor01
 * @brief Stop the motors
 * @return void
 */
void stopMotors()
{
	digitalWrite(MOTOR_LEFT_1, LOW);
	digitalWrite(MOTOR_LEFT_2, LOW);
	digitalWrite(MOTOR_RIGHT_1, LOW);
	digitalWrite(MOTOR_RIGHT_2, LOW);
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
