/*
 * actions.h
 *
 * Created: 11/25/2016 8:32:14 AM
 *  Author: Animesh Sinha
 */ 


#ifndef ACTIONS_H_
#define ACTIONS_H_

#include "State.h"

bool arm(State& state)
{
	if (state.armstate == false)
	{
		state.armstate = true;
		state.saveToMemory();
		return true;
	}
	else
	{
		return false;
	}
}

bool disarm(Istream& args, State& state)
{
	int passcode = 0;
	for (int i = 1; i < 5; i++)
		passcode = passcode*10 + (int)args.stream[i]-48;
	if(state.checkPasscode(passcode) && state.armstate == true)
	{
		state.armstate = false;
		state.saveToMemory();
		return true;
	}
	else
	{
		return false;
	}
}

bool changecode(Istream& args, State& state)
{
	int oldcode = 0, newcode = 0;
	for (int i = 1; i <= 4; i++)
		oldcode = oldcode*10 + (int)args.stream[i]-48;
	for (int i = 5; i <= 8; i++)
		newcode = newcode*10 + (int)args.stream[i]-48;
	return state.setPasscode(oldcode, newcode);
}

bool menuop(Istream& args, State& state)
{
	short value = args.stream[2] - 48;
	if (args.stream[1] == '1')
	{
		if (value >= 0 && value <= 2)
			state.alarmMode = (State::AlarmMode)value;
		else
			return false;
	} 
	else if (args.stream[1] == '2')
	{
		if(value >= 0 && value <= 5)
			state.travelMode = (State::TravelMode)value;
		else
			return false;
	}
	else
	{
		return false;
	}
	state.saveToMemory();
	return true;
}

#endif /* ACTIONS_H_ */