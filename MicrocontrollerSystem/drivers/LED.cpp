/* 
* LED.cpp
*
* Created: 4/10/2016 12:32:16 PM
* Author: Manish Sinha
*/


#include "LED.h"
#include <avr/io.h>

// default constructor
LED::LED()
{
	this->status = false;
	DDRB = 0xFF;
	PORTB = 0x00;
} //LED

// default destructor
LED::~LED()
{
} //~LED

void LED::on()
{
	PORTB=0xFF;
	this->status = true;
}

void LED::off()
{
	PORTB=0x00;
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