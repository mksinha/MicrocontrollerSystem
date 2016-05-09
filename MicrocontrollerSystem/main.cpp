#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "drivers/ParallelTextLCD.h"
#include "drivers/AnalogInput.h"

ParallelTextLCD lcd(IOPORTB, IOPORTD, IOPIN2, IOPIN7, IOPIN5);
AnalogInput adc(ADC0);
AnalogInput pot(ADC1);

int main(void)
{
	lcd.string(0, 0, "ADC Result:");
	lcd.string(0, 1, "POT Result:");
	adc.initialize();
	adc.startConversion();
	while (1)
	{
	}
}

ISR(ADC_vect)
{
	switch (ADMUX & 0b00011111)
	{
	case 0b00000000:
		adc.readValue();
		lcd.integer(11, 0, adc.value, 4);
		_delay_ms(500);
		pot.initialize();
		pot.startConversion();
		break;
	case 0b00000001:
		pot.readValue();
		lcd.integer(11, 1, pot.value, 4);
		_delay_ms(500);
		adc.initialize();
		adc.startConversion();
		break;
	}
}