#include "RobotCar.h"

#include <IRremote.h>

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
	if (IrReceiver.decode())
	{
		Serial.println(IrReceiver.decodedIRData.command, HEX);
		switch (IrReceiver.decodedIRData.command)
		{
		case IR_REMOTE_OK:
			currentState = STOP;
			break;
		case IR_REMOTE_UP:
			currentState = FORWARD;
			break;
		case IR_REMOTE_DOWN:
			currentState = BACKWARD;
			break;
		case IR_REMOTE_LEFT:
			currentState = LEFTWARD;
			break;
		case IR_REMOTE_RIGHT:
			currentState = RIGHTWARD;
			break;
		}
		IrReceiver.resume();
	}
	switch (currentState)
	{
	case STOP:
		stopMotors();
		break;
	case FORWARD:
		straight(MAX_SPEED, 1000);
		break;
	case BACKWARD:
		straight(-MAX_SPEED, 1000);
		break;
	case LEFTWARD:
		rotate(LEFT, MAX_SPEED, 1000);
		break;
	case RIGHTWARD:
		rotate(RIGHT, MAX_SPEED, 1000);
		break;
	}
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

	IrReceiver.begin(IR_REMOTE_PIN, ENABLE_LED_FEEDBACK);
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
	digitalWrite(MOTORS_RIGHT_FORWARD, LOW);
	digitalWrite(MOTORS_LEFT_BACKWARD, LOW);
	digitalWrite(MOTORS_RIGHT_BACKWARD, LOW);
}

/**
 * @author Julienraptor01
 * @brief Move straight
 * @param speed The speed to move at
 * @param time The delay it should move for in milliseconds
 * @return void
 */
void straight(int speed, unsigned int time)
{
	move(NULL, speed, 1, time);
}

/**
 * @author Julienraptor01
 * @brief Turn the robot
 * @param direction The direction where it should move
 * @param speed The speed to move at
 * @param ratio The ratio of the speed between the left and right motors
 * @param time The delay it should move for in milliseconds
 * @return void
 */
void move(bool direction, int speed, int ratio, unsigned int time)
{
	switch (((ratio >= 0) << 1) | (direction ^ (speed >= 0)))
	{
	case false << 1 | false:
		digitalWrite(MOTORS_LEFT_BACKWARD, LOW);
		digitalWrite(MOTORS_RIGHT_FORWARD, LOW);
		digitalWrite(MOTORS_LEFT_FORWARD, HIGH);
		digitalWrite(MOTORS_RIGHT_BACKWARD, HIGH);
		break;
	case false << 1 | true:
		digitalWrite(MOTORS_LEFT_FORWARD, LOW);
		digitalWrite(MOTORS_RIGHT_BACKWARD, LOW);
		digitalWrite(MOTORS_LEFT_BACKWARD, HIGH);
		digitalWrite(MOTORS_RIGHT_FORWARD, HIGH);
		break;
	case true << 1 | false:
		digitalWrite(MOTORS_LEFT_FORWARD, LOW);
		digitalWrite(MOTORS_RIGHT_FORWARD, LOW);
		digitalWrite(MOTORS_LEFT_BACKWARD, HIGH);
		digitalWrite(MOTORS_RIGHT_BACKWARD, HIGH);
		break;
	case true << 1 | true:
		digitalWrite(MOTORS_LEFT_BACKWARD, LOW);
		digitalWrite(MOTORS_RIGHT_BACKWARD, LOW);
		digitalWrite(MOTORS_LEFT_FORWARD, HIGH);
		digitalWrite(MOTORS_RIGHT_FORWARD, HIGH);
		break;
	}
	unsigned int cachedSpeed = abs(speed);
	setSpeed(
		(direction == LEFT) ? (ratio = 0) ? 0 : cachedSpeed / abs(ratio) : cachedSpeed,
		(direction == RIGHT) ? (ratio = 0) ? 0 : cachedSpeed / abs(ratio) : cachedSpeed);
	delay(time);
	stopMotors();
}

/**
 * @author Julienraptor01
 * @brief Rotate the robot on itself
 * @param direction The direction where it should rotate
 * @param speed The speed to rotate at
 * @param time The delay it should rotate for in milliseconds
 * @return void
 */
void rotate(bool direction, unsigned int speed, unsigned int time)
{
	move(direction, speed, -1, time);
}
