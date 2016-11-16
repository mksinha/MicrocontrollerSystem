/* 
* Keypad.cpp
*
* Created: 11/15/2016 4:16:47 PM
* Author: Animesh Sinha
*/


#include "Keypad.h"
#include "../controller/registry.h"

namespace Integral
{
	// default constructor
	Keypad::Keypad(PORT port)
	{
		this->port = port;
		initialize();
	} //Keypad

	// default destructor
	Keypad::~Keypad()
	{
	} //~Keypad

	void Keypad::initialize()
	{
		setDirection(port, 0x0F);
		setStatus(port, 0xFF);
	}
	
	KeypadMatrix Keypad::undebouncedStatus()
	{
		KeypadMatrix result;
		for (int i = 0; i < 4; i++)
		{
			setStatus((PIN)(port + i), LOW);
			for (int j = 0; j < 4; j++)
				result.set(i, j, switchPressed((PIN)(port + 4 + j)));
			setStatus((PIN)(port + i), HIGH);			
		}
		return result;
	}

	KeypadMatrix Keypad::isPressed()
	{	
		KeypadMatrix result;
		for (int i = 0; i < 4; i++)
		{
			setStatus((PIN)(port + i), LOW);
			for (int j = 0; j < 4; j++)
			result.set(i, j, switchPressed((PIN)(port + 4 + j)));
			setStatus((PIN)(port + i), HIGH);
		}
		return result;
	}

	bool Keypad::switchPressed(PIN pin)
	{
		return !getStatus(pin);
	}
}