// ArduinoC.h

#pragma once
#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class CarMotors
{
	uint8_t rMotorSpeed;
	uint8_t rMotorForward;
	uint8_t rMotorBackward;
	uint8_t lMotorSpeed;
	uint8_t lMotorForward;
	uint8_t lMotorBackward;

public:
	CarMotors(const uint8_t lf, const uint8_t ls, const uint8_t lb, const uint8_t rf, const uint8_t rs, const uint8_t rb) : lMotorForward{lf}, lMotorSpeed{ls}, lMotorBackward{lb},
																															rMotorForward{rf}, rMotorSpeed{rs}, rMotorBackward{rb} {}
	void setUp();
	void movaCar(const bool lf, const short ls, const bool lb, const bool rf, const short rs, const bool rb);
	void forward(const short speed)
	{
		movaCar(HIGH, speed, LOW, HIGH, speed, LOW);
	}
	void backward(const short speed)
	{
		movaCar(LOW, speed, HIGH, LOW, speed, HIGH);
	}
	void left(const short rs)
	{
		movaCar(LOW, 0, LOW, HIGH, rs, LOW);
	}
	void right(const short ls)
	{
		movaCar(HIGH, ls, LOW, LOW, 0, LOW);
	}
	void forwardRight(const short ls)
	{
		movaCar(HIGH, ls, LOW, HIGH, ls / 2, LOW);
	}
	void backwardRight(const short ls)
	{
		movaCar(LOW, ls, HIGH, LOW, ls / 2, HIGH);
	}
	void forwardLeft(const short rs)
	{
		movaCar(HIGH, rs / 2, LOW, HIGH, rs, LOW);
	}
	void backwardLeft(const short rs)
	{
		movaCar(LOW, rs / 2, HIGH, LOW, rs, HIGH);
	}
	void stop()
	{
		movaCar(LOW, 0, LOW, LOW, 0, LOW);
	}
	void rotate(const short ls, const short rs)
	{
		movaCar(LOW, ls, HIGH, HIGH, rs, LOW);
	}
};
