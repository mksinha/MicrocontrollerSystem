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

void Outputs::portStatus(int port, int state)
{
	if (port == IOPORTA)
		PORTA = state;
	else if (port == IOPORTB)
		PORTB = state;
	else if (port == IOPORTC)
		PORTC = state;
	else if (port == IOPORTD)
		PORTD = state;
}

void Outputs::portDirection(int port, int state)
{
	if (port == IOPORTA)
		DDRA = state;
	else if (port == IOPORTB)
		DDRB = state;
	else if (port == IOPORTC)
		DDRC = state;
	else if (port == IOPORTD)
		DDRD = state;
}

bool Outputs::pinStatus(int port, int pin)
{
	if (port == IOPORTA)
		return (DDRA & (1 << pin)) != 0;
	else if (port == IOPORTB)
		return (DDRB & (1 << pin)) != 0;
	else if (port == IOPORTC)
		return (DDRC & (1 << pin)) != 0;
	else if (port == IOPORTD)
		return (DDRD & (1 << pin)) != 0;
	else
		return false;
}

bool Outputs::pinDirection(int port, int pin)
{
	if (port == IOPORTA)
		return (PORTA & (1 << pin)) != 0;
	else if (port == IOPORTB)
		return (PORTB & (1 << pin)) != 0;
	else if (port == IOPORTC)
		return (PORTC & (1 << pin)) != 0;
	else if (port == IOPORTD)
		return (PORTD & (1 << pin)) != 0;
	else
		return false;
}