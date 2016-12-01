/* 
* State.h
*
* Created: 11/25/2016 9:09:06 AM
* Author: Animesh Sinha
*/


#ifndef __STATE_H__
#define __STATE_H__


class State
{
//variables
public:
protected:
private:
	int passcode = 0000;
	short alarmMode, travelMode;
	bool safe = true;
	int hardwareID = 1;

//functions
public:
	State();
	~State();
	bool setPasscode(int oldcode, int newcode);
	bool checkPasscode(int pass);

protected:
private:
	State( const State &c );
	State& operator=( const State &c );

}; //State

#endif //__STATE_H__
