/* 
* LED.cpp
*
* Created: 4/10/2016 12:32:16 PM
* Author: Manish Sinha
*/


#include "LED.h"
#include <avr/io.h>

// default constructor
LED::LED(int port, int pin)
{
	this->port = port;
	this->pin = pin;
	this->status = false;
	DDRB |= 1 << this->pin;
	PORTB &= ~(1 << this->pin);
} //LED

// default destructor
LED::~LED()
{
} //~LED

void LED::on()
{
	if (this->port == IOPORTA)
		PORTA |= 1 << this->pin;
	if (this->port == IOPORTB)
		PORTB |= 1 << this->pin;
	if (this->port == IOPORTC)
		PORTC |= 1 << this->pin;
	if (this->port == IOPORTD)
		PORTD |= 1 << this->pin;
	this->status = true;
}

void LED::off()
{
	if (this->port == IOPORTA)
		PORTA &= ~(1 << this->pin);
	if (this->port == IOPORTB)
		PORTB &= ~(1 << this->pin);
	if (this->port == IOPORTC)
		PORTC &= ~(1 << this->pin);
	if (this->port == IOPORTD)
		PORTD &= ~(1 << this->pin);
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