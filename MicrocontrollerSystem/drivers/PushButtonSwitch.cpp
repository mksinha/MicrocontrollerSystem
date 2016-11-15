/* 
* PushButtonSwitch.cpp
*
* Created: 4/16/2016 3:52:00 PM
* Author: Manish Sinha
*/


#include "PushButtonSwitch.h"

#define DEBOUNCE_MINCYCLES 10
#define DEBOUNCE_MAXCYCLES 10000
#define DEBOUNCE_CONFIDFRAC 0.75

namespace Integral
{
	// default constructor
	PushButtonSwitch::PushButtonSwitch(PIN pin, bool pullState)
	{
		this->pin = pin;
		this->pullState = pullState;
		this->initialize();
	} //PushButtonSwitch

	// default destructor
	PushButtonSwitch::~PushButtonSwitch()
	{
	} //~PushButtonSwitch

	bool PushButtonSwitch::state()
	{
		bool result = LOW;
		for (double i = 0.0, high = 0.0; i < DEBOUNCE_MAXCYCLES; i++)
		{
			if (isPressed())
				high++;
			// conditions to break the loop and accept result
			if (i > DEBOUNCE_MINCYCLES && high/i > DEBOUNCE_CONFIDFRAC)
			{
				result = HIGH;
				break;
			}
			if (i > DEBOUNCE_MINCYCLES && (1 - high/i) > DEBOUNCE_CONFIDFRAC)
			{
				result = LOW;
				break;
			}
			if (i == DEBOUNCE_MAXCYCLES - 1)
			{
				if (high/i > 0.5)
					result = HIGH;
				else
					result = LOW;
				break;
			}
		}
		// Reporting the status and updating variables
		if (result != status)
		{
			status = result;
			return status;
		}
		else
			return status;
	}

	void PushButtonSwitch::initialize()
	{
		setDirection(pin, LOW);
		setStatus(pin, pullState);
		this->status = false;
	}

	bool PushButtonSwitch::isPressed()
	{
		if (pullState == HIGH)
			return !getStatus(pin);
		else
			return getStatus(pin);
	}
}