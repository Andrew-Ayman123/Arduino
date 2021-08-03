#include "ArduinoC.h"


//#include<Arduino.h>
void CarMotors::setUp() {
	{
		pinMode(lMotorForward, OUTPUT);
		pinMode(lMotorSpeed, OUTPUT);
		pinMode(lMotorBackward, OUTPUT);
		pinMode(rMotorForward, OUTPUT);
		pinMode(rMotorSpeed, OUTPUT);
		pinMode(rMotorBackward, OUTPUT);
	}
}
void CarMotors::movaCar(const bool lf, const short ls, const bool lb, const bool rf, const short rs, const bool rb) {


	digitalWrite(lMotorForward, lf);
	analogWrite(lMotorSpeed, ls);
	digitalWrite(lMotorBackward, lb);
	digitalWrite(rMotorForward, rf);
	analogWrite(rMotorSpeed, rs);
	digitalWrite(rMotorBackward, rb);

}
