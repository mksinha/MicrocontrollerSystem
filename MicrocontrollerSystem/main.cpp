/*
 * MicrocontrollerSystem.cpp
 *
 * Created: 4/10/2016 12:04:45 PM
 * Author : Manish Sinha
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "drivers/LED.h"
#include "drivers/ParallelTextLCD.h"
#include "drivers/AnalogInput.h"


int main(void)
{
	LED led(IOPORTC, IOPIN6);
	ParallelTextLCD lcd(IOPORTB, IOPORTD, IOPIN2, IOPIN7, IOPIN5);
	AnalogInput atod(ADCPIN0);
	lcd.string("Reading: ");
	while (1)
    {
		atod.startConversion();
		_delay_ms(5000);
		atod.readValue();
		lcd.integer(9, 0, atod.value, 6);
	}
	return 0;
}


/************************************************************************/
/*              Using the new Libraries on the old program              */
/*
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "drivers/ParallelTextLCD.h"
#include "drivers/AnalogInput.h"

ParallelTextLCD lcd(IOPORTB, IOPORTD, IOPIN2, IOPIN7, IOPIN5);

int main(void)
{
	lcd.string(0, 0, "ADC Result:");
	ADCSRA |= 1<<ADPS2;
	ADMUX |= (1<<REFS0);
	ADCSRA |= 1<<ADEN;
	ADCSRA |= 1<<ADIE;
	sei();
	ADCSRA |= 1<<ADSC;
	while (1)
	{
		_delay_ms(5000);
		uint16_t theTenBitResults = (ADCH << 8) | ADCL;
		lcd.integer(12, 0, theTenBitResults, 4);
		ADCSRA |= 1<<ADSC;
	}
}
*/
/************************************************************************/