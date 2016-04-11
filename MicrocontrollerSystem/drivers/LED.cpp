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
	Outputs::pinDirection(this->port, this->pin, true);
	Outputs::pinStatus(this->port, this->pin, false);
} //LED

// default destructor
LED::~LED()
{
} //~LED

void LED::on()
{
	Outputs::pinStatus(this->port, this->pin, true);
	this->status = true;
}

void LED::off()
{
	Outputs::pinStatus(this->port, this->pin, false);
	this->status = false;
}

bool LED::toggle()
{
	if (this->status == false)
		this->on();
	else if(this->status == true)
		this->off();
	return this->status;
}

bool LED::test()
{
	for (int i = 0; i < 10; i++)
	{
		this->toggle();
		_delay_ms(500);
	}
	for (int i = 0; i < 10; i++)
	{
		this->toggle();
		_delay_ms(150);
	}
	return true;
}