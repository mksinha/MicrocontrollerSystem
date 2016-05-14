/* 
* Device.cpp
*
* Created: 4/17/2016 10:32:48 AM
* Author: Animesh Sinha
*/

#include "Device.h"
#include <avr/io.h>
#include <avr/sfr_defs.h>

namespace Integral
{
	// functions
	void Device::setStatus(PIN pin, bool state)
	{
		if (state == true)
		{
			if (pin >= IOPINA0 && pin <= IOPINA7)
				PORTA |= 1 << (pin - IOPORTA);
			else if (pin >= IOPINB0 && pin <= IOPINB7)
				PORTB |= 1 << (pin - IOPORTB);
			else if (pin >= IOPINC0 && pin <= IOPINC7)
				PORTC |= 1 << (pin - IOPORTC);
			else if (pin >= IOPIND0 && pin <= IOPIND7)
				PORTD |= 1 << (pin - IOPORTD);
		}
		else if (state == false)
		{
			if (pin >= IOPINA0 && pin <= IOPINA7)
				PORTA &= ~(1 << (pin - IOPORTA));
			else if (pin >= IOPINB0 && pin <= IOPINB7)
				PORTB &= ~(1 << (pin - IOPORTB));
			else if (pin >= IOPINC0 && pin <= IOPINC7)
				PORTC &= ~(1 << (pin - IOPORTC));
			else if (pin >= IOPIND0 && pin <= IOPIND7)
				PORTD &= ~(1 << (pin - IOPORTD));
		}
	}
	
	void Device::setDirection(PIN pin, bool state)
	{
		if (state == true)
		{
			if (pin >= IOPINA0 && pin <= IOPINA7)
				DDRA |= 1 << (pin - IOPORTA);
			else if (pin >= IOPINB0 && pin <= IOPINB7)
				DDRB |= 1 << (pin - IOPORTB);
			else if (pin >= IOPINC0 && pin <= IOPINC7)
				DDRC |= 1 << (pin - IOPORTC);
			else if (pin >= IOPIND0 && pin <= IOPIND7)
				DDRD |= 1 << (pin - IOPORTD);
		}
		else if (state == false)
		{
			if (pin >= IOPINA0 && pin <= IOPINA7)
				DDRA &= ~(1 << (pin - IOPORTA));
			else if (pin >= IOPINB0 && pin <= IOPINB7)
				DDRB &= ~(1 << (pin - IOPORTB));
			else if (pin >= IOPINC0 && pin <= IOPINC7)
				DDRC &= ~(1 << (pin - IOPORTC));
			else if (pin >= IOPIND0 && pin <= IOPIND7)
				DDRD &= ~(1 << (pin - IOPORTD));
		}
	}

	bool Device::getStatus(PIN pin)
	{
		if (pin >= IOPINA0 && pin <= IOPINA7)
			return bit_is_set(PINA, pin - IOPORTA);
		else if (pin >= IOPINB0 && pin <= IOPINB7)
			return bit_is_set(PINB, pin - IOPORTB);
		else if (pin >= IOPINC0 && pin <= IOPINC7)
			return bit_is_set(PINC, pin - IOPORTC);
		else if (pin >= IOPIND0 && pin <= IOPIND7)
			return bit_is_set(PIND, pin - IOPORTD);
		else
			return false;
	}

	void Device::setStatus(PORT port, POSITION pin, bool state)
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

	void Device::setDirection(PORT port, POSITION pin, bool state)
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

	void Device::setStatus(PORT port, int state)
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

	void Device::setDirection(PORT port, int state)
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

	bool Device::getStatus(PORT port, POSITION pin)
	{
		switch(port)
		{
			case IOPORTA:
				return bit_is_set(PINA, pin);
			case IOPORTB:
				return bit_is_set(PINB, pin);
			case IOPORTC:
				return bit_is_set(PINC, pin);
			case IOPORTD:
				return bit_is_set(PIND, pin);
			default:
				return false;
		}
	}
}