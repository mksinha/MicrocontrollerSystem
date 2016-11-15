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
		setDirection((PIN)(port + 0), HIGH);
		setDirection((PIN)(port + 1), HIGH);
		setDirection((PIN)(port + 2), HIGH);
		setDirection((PIN)(port + 3), HIGH);
		setDirection((PIN)(port + 4), LOW);
		setDirection((PIN)(port + 5), LOW);
		setDirection((PIN)(port + 6), LOW);
		setDirection((PIN)(port + 7), LOW);
		setStatus(port, HIGH);
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
		for (int i = 0; i < 4; i++)
		{
			setStatus((PIN)(port + i), LOW);
			for (int j = 0; j < 4; j++)
				status.set(i, j, switchPressed((PIN)(port + 4 + j)));
			setStatus((PIN)(port + i), HIGH);
		}
		return status;
	}

	bool Keypad::switchPressed(PIN pin)
	{
		return !getStatus(pin);
	}
}