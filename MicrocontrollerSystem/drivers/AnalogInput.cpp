/* 
* AnalogInput.cpp
*
* Created: 4/28/2016 10:58:39 PM
* Author: Manish Sinha
*/


#include "AnalogInput.h"
#include <avr/interrupt.h>
#include <avr/io.h>

// default constructor
AnalogInput::AnalogInput(ADCPIN pin)
{
	this->pin = pin;
	this->value = 0;
	initialize();
} //AnalogInput

// default destructor
AnalogInput::~AnalogInput()
{
} //~AnalogInput

ADCPIN AnalogInput::getID()
{
	return pin;
}

void AnalogInput::initialize()
{
	ADMUX |= 1 << REFS0;
	ADMUX &= ~(1 << REFS1);
	ADMUX |= pin;
	ADCSRA |= 1 << ADPS2;
	ADCSRA &= ~((1 << ADPS1) | (1 << ADPS0));
	ADCSRA |= (1 << ADEN);
}

void AnalogInput::setCallback(void (*func)(void))
{
	this->callback = func;
}

void AnalogInput::readValue()
{
	this->value = (ADCH << 8) | ADCL;
}

void AnalogInput::startConversion()
{
	ADCSRA |= 1 << ADSC;
}

void AnalogInput::stopConversion()
{
	ADCSRA &= ~(1 << ADSC);
}