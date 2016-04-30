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
AnalogInput::AnalogInput(PIN pin)
{
} //AnalogInput

// default destructor
AnalogInput::~AnalogInput()
{
} //~AnalogInput

void AnalogInput::initialize()
{
	ADMUX |= 1 << REFS0;
	ADMUX &= ~(1 << REFS1);
	ADCSRA |= 1 << ADPS2;
	ADCSRA &= ~(1 << ADPS1);
	ADCSRA &= ~(1 << ADPS0);
	ADCSRA |= 1 << ADEN;
	ADCSRA |= 1 << ADIE;
	sei();
	ADCSRA |= 1 << ADSC;
}

void AnalogInput::setCallback(void (*func)(void))
{
	this->callback = func;
}

// Problem here
ISR(ADC_vect)
{
	uint16_t value = ADCL | (ADCH << 8);
	ADCSRA |= 1 << ADSC;
}