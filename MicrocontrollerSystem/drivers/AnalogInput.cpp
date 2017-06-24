/* 
* AnalogInput.cpp
*
* Created: 4/28/2016 10:58:39 PM
* Author: Manish Sinha
*/


#include "AnalogInput.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include "../drivers/AnalogInput.h"

namespace atmicro
{
	// default constructor
	AnalogInput::AnalogInput(ADCchannel pin)
	{
		this->pin = pin;
		value = 0;
		if (this->pin == ADCvoid) return;
		gInit();
	} //AnalogInput

	AnalogInput::AnalogInput(ADCchannel pin, void (*func)(AnalogInput))
	{
		this->pin = pin;
		value = 0;
		if (this->pin == ADCvoid) return;
		gInit();
		setEventListener(func);
	}

	AnalogInput::AnalogInput(ADCchannel pin, void (*func)(AnalogInput), ADCcontroller& c)
	{
		this->pin = pin;
		value = 0;
		if (this->pin == ADCvoid) return;
		gInit();
		setEventListener(func);
		c.registerADC(*this);
	}
	// default destructor
	AnalogInput::~AnalogInput()
	{
		if(isLive())
		{
			ADMUX &= (0b11100000);
			stopConversion();
		}
	} //~AnalogInput

	bool AnalogInput::isLive()
	{
		if (this->pin == ADCvoid) return false;
		return (ADMUX & 0b00011111) == pin;
	}

	void AnalogInput::gInit(ADCconf::VREF vref, ADCconf::ADPS adps)
	{
		ADMUX &= ~((1<<REFS0) | (1<<REFS1));
		ADCSRA &= ~((1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0));
		ADCSRA |= adps << ADPS0;
		ADMUX |= vref << REFS0;
		ADCSRA |= 1<<ADIE;
		ADCSRA |= 1<<ADEN;
		sei();
	}

	void AnalogInput::initialize()
	{
		if (this->pin == ADCvoid) return;
		ADMUX &= (0b11100000);
		ADMUX |= pin;
	}

	void AnalogInput::startConversion()
	{
		if (this->pin == ADCvoid) return;
		initialize();
		ADCSRA |= 1 << ADSC;
	}

	void AnalogInput::stopConversion()
	{
		ADCSRA &= ~(1 << ADSC);
	}

	void AnalogInput::setEventListener(void (*func)(AnalogInput))
	{
		callback = func;
	}

	void AnalogInput::process()
	{
		if (this->pin == ADCvoid) return;
		uint16_t value8bit = ADCL;
		this->value = (ADCH << 8) | value8bit;
		if(callback != NULL) callback(*this);
	}
}