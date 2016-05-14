/* 
* PushButtonSwitch.cpp
*
* Created: 4/16/2016 3:52:00 PM
* Author: Manish Sinha
*/


#include "PushButtonSwitch.h"

namespace Integral
{
	// default constructor
	PushButtonSwitch::PushButtonSwitch(PORT port, POSITION pin, bool no_nc, bool pullState)
	{
		this->port = port;
		this->pin = pin;
		this->no_nc = no_nc;
		this->pullState = pullState;
		this->initialize();
	} //PushButtonSwitch

	// default destructor
	PushButtonSwitch::~PushButtonSwitch()
	{
	} //~PushButtonSwitch

	bool PushButtonSwitch::state()
	{
		int minLimit = 50, maxLimit = 10000;
		double confirmPoint = 0.90;
		bool result = LOW;
		for (double i = 0.0, high = 0.0; i < maxLimit; i++)
		{
			if (checkState() == HIGH)
				high++;
			if (i > minLimit && high/i > confirmPoint)
			{
				result = HIGH;
				break;
			}
			if (i > minLimit && (1 - high/i) > confirmPoint)
			{
				result = LOW;
				break;
			}
			if (i == maxLimit - 1)
			{
				if (high/i > 0.5)
					result = HIGH;
				else
					result = LOW;
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
		setDirection(port, pin, LOW);
		setStatus(port, pin, pullState);
		this->status = false;
	}

	bool PushButtonSwitch::checkState()
	{
		if (pullState == HIGH)
			return !getStatus(port, pin);
		else
			return getStatus(port, pin);
	}
}