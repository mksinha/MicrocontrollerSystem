/* 
* Input.cpp
*
* Created: 4/13/2016 1:07:43 AM
* Author: Animesh Sinha
*/


#include "Input.h"
#include <avr/io.h>
#include <avr/sfr_defs.h>

// functions

void Input::pinStatus(PORT port, PIN pin, bool state)
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

void Input::pinDirection(PORT port, PIN pin, bool state)
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

bool Input::pinStatus(PORT port, PIN pin)
{
	if (port == IOPORTA)
		return bit_is_set(PINA, pin);
	else if (port == IOPORTB)
		return bit_is_set(PINB, pin);
	else if (port == IOPORTC)
		return bit_is_set(PINC, pin);
	else if (port == IOPORTD)
		return bit_is_set(PIND, pin);
	else
		return false;
}