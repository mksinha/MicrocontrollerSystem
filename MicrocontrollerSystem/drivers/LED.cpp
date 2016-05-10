/* 
* LED.cpp
*
* Created: 4/10/2016 12:32:16 PM
* Author: Manish Sinha
*/


#include "LED.h"

namespace Integral 
{
	// default constructor
	LED::LED(PORT port, PIN pin)
	{
		this->port = port;
		this->pin = pin;
		this->status = false;
		initialize();
	} //LED

	// default destructor
	LED::~LED()
	{
	} //~LED

	void LED::on()
	{
		setStatus(port, pin, HIGH);
		status = true;
	}

	void LED::off()
	{
		setStatus(port, pin, LOW);
		status = false;
	}

	bool LED::toggle()
	{
		if (status == false)
			on();
		else if(status == true)
			off();
		return status;
	}

	void LED::initialize()
	{
		setDirection(port, pin, HIGH);
		setStatus(port, pin, LOW);
	}
}