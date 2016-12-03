/* 
* State.cpp
*
* Created: 11/25/2016 9:09:05 AM
* Author: Animesh Sinha
*/


#include "State.h"

// default constructor
State::State()
{
	if (memory.read(0x00) == 0xae)
	{
		retrieveFromMemory();
	}
	else
	{
		passcode = 0000;
		armstate = false;
		safe = true;
		alarmMode = ON;
		travelMode = TRAIN;
		hardwareID = 0x000000FF;
		saveToMemory();
	}
} //State

// default destructor
State::~State()
{
	saveToMemory();
} //~State

bool State::setPasscode(int oldcode, int newcode)
{
	if (passcode != oldcode)
		return false;
	passcode = newcode;
	saveToMemory();
	return true;
}

bool State::checkPasscode(int pass)
{
	return pass == passcode;
}

void State::saveToMemory()
{
	memory.write(0x00, 0xae);

	if (armstate == true)
		memory.write(BASEADDRESS_ARMSTATE, 0xFF);
	else
		memory.write(BASEADDRESS_ARMSTATE, 0x00);

	if (safe == true)
		memory.write(BASEADDRESS_SAFETY, 0xFF);
	else
		memory.write(BASEADDRESS_SAFETY, 0x00);

	memory.write(BASEADDRESS_PASSWORD, passcode/100);
	memory.write(BASEADDRESS_PASSWORD + 1, passcode%100);
	
	memory.write(BASEADDRESS_TRAVELMODE, travelMode);
	memory.write(BASEADDRESS_ALARMMODE, alarmMode);
}

void State::retrieveFromMemory()
{
	if (memory.read(BASEADDRESS_ARMSTATE) == 0xFF)
		armstate = true;
	else
		armstate = false;

	if (memory.read(BASEADDRESS_SAFETY) == 0xFF)
		safe = true;
	else
		safe = false;

	passcode = memory.read(BASEADDRESS_PASSWORD)*100 + memory.read(BASEADDRESS_PASSWORD + 1);
	
	travelMode = (TravelMode)memory.read(BASEADDRESS_TRAVELMODE);
	alarmMode = (AlarmMode)memory.read(BASEADDRESS_ALARMMODE);
}