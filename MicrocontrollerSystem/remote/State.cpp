/* 
* State.cpp
*
* Created: 11/25/2016 9:09:05 AM
* Author: Animesh Sinha
*/


#include "State.h"
#include <string.h>

// default constructor
State::State()
{
} //State

// default destructor
State::~State()
{
} //~State

bool State::setPasscode(int oldcode, int newcode)
{
	if (passcode != oldcode)
		return false;
	passcode = newcode;
	return true;
}

bool State::checkPasscode(int pass)
{
	return pass == passcode;
}