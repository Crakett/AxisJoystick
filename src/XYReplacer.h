/**
	XYReplacer.h - class-wrapper implements methods of the Joystick.h
	interface, replacing X- and Y-axis signal of the delegate joystick.

	v.2.0:
	- created.

	https://github.com/YuriiSalimov/AxisJoystick

	Created by Yurii Salimov, December, 2018.
	Released into the public domain.
*/
#ifndef XY_REPLACER_H
#define XY_REPLACER_H

#include "DelegateJoystick.h"

// class
class XYReplacer final : public DelegateJoystick {

	public:
		XYReplacer(const Joystick* joystick);

		/**
			Single reading of the joystick controller.
			Replaces X- and Y-axis moves.
		*/
		Move singleRead() override;

		/**
			Multiple reading of the joystick controller.
			Replaces X- and Y-axis moves.
		*/
		Move multipleRead() override;

		/**
			Checks if the joystick is pressed up (X-axis).
			@return true - joystick is really pressed right (Y-axis),
			false - joystick is not pressed.
		*/
		boolean isUp() override;

		/**
			Checks if the joystick is pressed down (X-axis).
			@return true - joystick is really pressed left (Y-axis),
			false - joystick is not pressed.
		*/
		boolean isDown() override;

		/**
			Checks if the joystick is pressed right (Y-axis).
			@return true - joystick is really pressed up (X-axis),
			false - joystick is not pressed.
		*/
		boolean isRight() override;

		/**
			Checks if the joystick is pressed left (Y-axis).
			@return true - joystick is really pressed down (X-axis),
			false - joystick is not pressed.
		*/
		boolean isLeft() override;

		/**
			Returns the joystick X-axis coordinate
			(really Y-axis coordinate).
		*/
		int xAxis() override;

		/**
			Returns the joystick Y-axis coordinate
			(really X-axis coordinate).
		*/
		int yAxis() override;

  private:
		/**
			Replaces the input move from X- to Y-axis
			and from Y- to X-axis.
		*/
    Move replace(Move move);
};

#endif
