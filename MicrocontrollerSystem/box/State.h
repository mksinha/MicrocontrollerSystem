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
enum AlarmMode {
		OFF, LOCAL, ON
	};
enum TravelMode {
		TRAIN, BUS, AIRPLANE, TAXI, WALK, STATION
	};

//variables
public:
protected:
private:
	int passcode = 0000;
	AlarmMode alarmMode;
	TravelMode travelMode;
	bool safe = true;
	int hardwareID = 0x000000FF;

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
