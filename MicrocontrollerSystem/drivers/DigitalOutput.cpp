/* 
* DigitalOutput.cpp
*
* Created: 4/10/2016 12:32:16 PM
* Author: Manish Sinha
*/


#include "DigitalOutput.h"

namespace Integral 
{
	// default constructor
	DigitalOutput::DigitalOutput(PIN pin)
	{
		this->pin = pin;
		this->status = false;
		initialize();
	} //DigitalOutput

	// default destructor
	DigitalOutput::~DigitalOutput()
	{
	} //~DigitalOutput

	void DigitalOutput::on()
	{
		setStatus(pin, HIGH);
		status = true;
	}

	void DigitalOutput::off()
	{
		setStatus(pin, LOW);
		status = false;
	}

	bool DigitalOutput::toggle()
	{
		if (status == false)
			on();
		else if(status == true)
			off();
		return status;
	}

	void DigitalOutput::initialize()
	{
		setDirection(pin, HIGH);
		setStatus(pin, LOW);
	}
}