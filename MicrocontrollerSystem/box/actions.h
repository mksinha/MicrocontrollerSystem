/*
 * actions.h
 *
 * Created: 11/25/2016 8:32:14 AM
 *  Author: Animesh Sinha
 */ 


#ifndef ACTIONS_H_
#define ACTIONS_H_

#include "State.h"

State state;

bool arm()
{	
	return false;
}

bool disarm(Istream& args)
{
	int passcode = 0;
	for (int i = 1; i < 5; i++)
		passcode = passcode*10 + (int)args.stream[i]-48;
	return state.checkPasscode(passcode);
}

bool changecode(Istream& args)
{
	int oldcode = 0, newcode = 0;
	for (int i = 1; i <= 4; i++)
		oldcode = oldcode*10 + (int)args.stream[i]-48;
	for (int i = 5; i <= 8; i++)
		newcode = newcode*10 + (int)args.stream[i]-48;
	return state.setPasscode(oldcode, newcode);
}

bool menuop(Istream& args)
{
	return false;
}

#endif /* ACTIONS_H_ */