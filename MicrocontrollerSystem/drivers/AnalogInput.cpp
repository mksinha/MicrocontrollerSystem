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
AnalogInput::AnalogInput(ADCchannel pin)
{
	this->pin = pin;
	this->value = 0;
	this->globablInit();
} //AnalogInput

// default destructor
AnalogInput::~AnalogInput()
{
} //~AnalogInput

ADCchannel AnalogInput::getID()
{
	return pin;
}

void AnalogInput::globablInit()
{
	ADMUX |= (1<<REFS0) | (1<<REFS1);
	ADCSRA |= 1 << ADPS2;
	ADCSRA &= ~((1 << ADPS1) | (1 << ADPS0));
	ADCSRA |= 1<<ADIE;
	ADCSRA |= 1<<ADEN;
	sei();
}

void AnalogInput::initialize()
{
	ADMUX |= pin;
}

void AnalogInput::setCallback(void (*func)(void))
{
	this->callback = func;
}

void AnalogInput::readValue()
{
	uint16_t value8bit = ADCL;
	this->value = (ADCH << 8) | value8bit;
}

void AnalogInput::startConversion()
{
	ADCSRA |= 1 << ADSC;
}

void AnalogInput::stopConversion()
{
	ADCSRA &= ~(1 << ADSC);
}