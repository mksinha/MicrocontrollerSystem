/* 
* PushButtonSwitch.cpp
*
* Created: 4/16/2016 3:52:00 PM
* Author: Manish Sinha
*/


#include "PushButtonSwitch.h"

// default constructor
PushButtonSwitch::PushButtonSwitch(PORT port, PIN pin, bool no_nc, bool pullState, int debounceLimit)
{
	this->port = port;
	this->pin = pin;
	this->no_nc = no_nc;
	this->pullState = pullState;
	this->debounceLimit = debounceLimit;
	this->initialize();
} //PushButtonSwitch

// default destructor
PushButtonSwitch::~PushButtonSwitch()
{
} //~PushButtonSwitch

bool PushButtonSwitch::state()
{
	if(checkState() != status)
	{
		status = checkState();
		return status;
	}
	else
	{
		return status;
	}
}

void PushButtonSwitch::initialize()
{
	setDirection(port, pin, false);
	setStatus(port, pin, pullState);
	this->status = false;
}

bool PushButtonSwitch::checkState()
{
	if (pullState == true)
		return !getStatus(port, pin);
	else
		return getStatus(port, pin);
}