/* 
* PushButtonSwitch.h
*
* Created: 4/16/2016 10:02:02 AM
* Author: Manish Sinha
*/


#ifndef __PUSHBUTTONSWITCH_H__
#define __PUSHBUTTONSWITCH_H__

#include "Input.h"


class PushButtonSwitch : public Input
{
//variables
protected:
	bool status;
	PORT port;
	PIN pin;
	bool no_nc, pullState;

//functions
public:
	PushButtonSwitch(PORT port, PIN pin, bool no_nc, bool pullState);
	~PushButtonSwitch();
	bool state();  // debounced status
	void initialize();
protected:
	bool checkState();  // state without debouncing
private:
	PushButtonSwitch( const PushButtonSwitch &c );
	PushButtonSwitch& operator=( const PushButtonSwitch &c );
	
}; //PushButtonSwitch

#endif //__PUSHBUTTONSWITCH_H__