/**
	Created by Yurii Salimov, February, 2018.
	Released into the public domain.
*/
#include "AxisJoystick.h"

AxisJoystick::AxisJoystick(
	const int VRx_pin,
	const int VRy_pin
) {
	pinMode(this->VRx_pin = VRx_pin, INPUT);
	pinMode(this->VRy_pin = VRy_pin, INPUT);
}

Joystick::Move AxisJoystick::singleRead() {
	const Move currentMove = multipleRead();
	return (currentMove != this->previousMove) ?
		(this->previousMove = currentMove) :
		Move::NOT;
}

Joystick::Move AxisJoystick::multipleRead() {
	if (isPress()) {
		return Move::PRESS;
	} else if (isUp()) {
		return Move::UP;
	} else if (isDown()) {
		return Move::DOWN;
	} else if (isRight()) {
		return Move::RIGHT;
	} else if (isLeft()) {
		return Move::LEFT;
	}
	return Move::NOT;
}

boolean AxisJoystick::isPress() {
	return isSwitchHigh(readVRx());
}

boolean AxisJoystick::isUp() {
	return isHigh(readVRy());
}

boolean AxisJoystick::isDown() {
	return isLow(readVRy());
}

boolean AxisJoystick::isRight() {
	return isHigh(readVRx());
}

boolean AxisJoystick::isLeft() {
	return isLow(readVRx());
}

int AxisJoystick::readVRx() {
	return analogRead(this->VRx_pin);
}

int AxisJoystick::readVRy() {
	return analogRead(this->VRy_pin);
}

int AxisJoystick::xAxis() {
	return readVRx();
}

int AxisJoystick::yAxis() {
	return readVRy();
}

void AxisJoystick::calibrate(const int low, const int high) {
	this->min = low;
	this->max = high;
}

void AxisJoystick::calibrate(const int adcMin, const int adcMax, const int deviation) {
	calibrate(adcMin + deviation, adcMax - deviation);
}

void AxisJoystick::calibrate(const int adcMin, const int adcMax, const int deviation, const int switchDeviation) {
	calibrate(adcMin + deviation, adcMax - deviation);
	this->maxSW = adcMax - switchDeviation;
}

inline boolean AxisJoystick::isLow(const int value) {
	return (value <= this->min);
}

inline boolean AxisJoystick::isHigh(const int value) {
	return (value >= this->max);
}

inline boolean AxisJoystick::isSwitchHigh(const int value) {
	return (value >= this->maxSW);
}






