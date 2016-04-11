/* 
* Outputs.cpp
*
* Created: 4/11/2016 9:06:39 PM
* Author: Animesh Sinha
*/


#include "Outputs.h"
#include <avr/io.h>

// functions

void Outputs::pinStatus(int port, int pin, bool state)
{
	if (state == true)
	{
		if (port == IOPORTA)
		PORTA |= 1 << pin;
		else if (port == IOPORTB)
		PORTB |= 1 << pin;
		else if (port == IOPORTC)
		PORTC |= 1 << pin;
		else if (port == IOPORTD)
		PORTD |= 1 << pin;
	}
	else if (state == false)
	{
		if (port == IOPORTA)
			PORTA &= ~(1 << pin);
		if (port == IOPORTB)
			PORTB &= ~(1 << pin);
		if (port == IOPORTC)
			PORTC &= ~(1 << pin);
		if (port == IOPORTD)
			PORTD &= ~(1 << pin);
	}
}

void Outputs::pinDirection(int port, int pin, bool state)
{
	if (state == true)
	{
		if (port == IOPORTA)
			DDRA |= 1 << pin;
		else if (port == IOPORTB)
			DDRB |= 1 << pin;
		else if (port == IOPORTC)
			DDRC |= 1 << pin;
		else if (port == IOPORTD)
			DDRD |= 1 << pin;
	}
	else if (state == false)
	{
		if (port == IOPORTA)
			DDRA &= ~(1 << pin);
		if (port == IOPORTB)
			DDRB &= ~(1 << pin);
		if (port == IOPORTC)
			DDRC &= ~(1 << pin);
		if (port == IOPORTD)
			DDRD &= ~(1 << pin);
	}
}