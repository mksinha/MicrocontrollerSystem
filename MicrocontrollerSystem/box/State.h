/* 
* State.h
*
* Created: 11/25/2016 9:09:06 AM
* Author: Animesh Sinha
*/


#ifndef __STATE_H__
#define __STATE_H__

#include "../atmicro.h"

#define BASEADDRESS_ARMSTATE	0x01
#define BASEADDRESS_SAFETY		0x02
#define BASEADDRESS_PASSWORD	0x03
#define BASEADDRESS_TRAVELMODE	0x05
#define BASEADDRESS_ALARMMODE	0x06

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
	bool safe = true;
	bool armstate = false;
	AlarmMode alarmMode;
	TravelMode travelMode;
protected:
private:
	int passcode = 0000;
	int hardwareID = 0x000000FF;
	EEPROM memory;

//functions
public:
	State();
	~State();
	bool setPasscode(int oldcode, int newcode);
	bool checkPasscode(int pass);
	void saveToMemory();
	void retrieveFromMemory();

protected:
private:
	State( const State &c );
	State& operator=( const State &c );

}; //State

#endif //__STATE_H__
