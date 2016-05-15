/* 
* PushButtonSwitch.h
*
* Created: 4/16/2016 10:02:02 AM
* Author: Manish Sinha
*/


#ifndef __PUSHBUTTONSWITCH_H__
#define __PUSHBUTTONSWITCH_H__

#include "Input.h"

namespace Integral
{
	class PushButtonSwitch : public Input
	{
	//variables
	protected:
		bool status;
		PIN pin;
		bool no_nc, pullState;

	//functions
	public:
		PushButtonSwitch(PIN pin, bool pullState = HIGH, bool no_nc = HIGH);
		~PushButtonSwitch();
		bool state();  // debounced status
		void initialize();
	protected:
		bool checkState();  // state without debouncing
	private:
		PushButtonSwitch( const PushButtonSwitch &c );
		PushButtonSwitch& operator=( const PushButtonSwitch &c );
	
	}; //PushButtonSwitch
}

#endif //__PUSHBUTTONSWITCH_H__