/* 
* LED.h
*
* Created: 4/10/2016 12:32:17 PM
* Author: Manish Sinha
*/


#ifndef __LED_H__
#define __LED_H__

#include "Output.h"

namespace Integral
{
	class LED : public Output
	{
	//variables
	protected:
		bool status; 
		PORT port;
		POSITION pin;

	//functions
	public:
		LED(PORT port, POSITION pin);
		~LED();
		void on(); // Switches the LED on
		void off(); // Switches the LED off
		bool toggle(); // Changes the state of LED from on to off or back
		void initialize(); // Initializes the LED port
	}; //LED
}

#endif //__LED_H__