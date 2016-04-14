/* 
* LED.cpp
*
* Created: 4/10/2016 12:32:16 PM
* Author: Manish Sinha
*/


#include "LED.h"
#include <avr/io.h>
#include <util/delay.h>

// default constructor
LED::LED(int port, int pin)
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
	Output::pinStatus(port, pin, true);
	status = true;
}

void LED::off()
{
	Output::pinStatus(port, pin, false);
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
	Output::pinDirection(port, pin, true);
	Output::pinStatus(port, pin, false);
}