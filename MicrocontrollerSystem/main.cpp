#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "drivers/ParallelTextLCD.h"
#include "drivers/AnalogInput.h"

ParallelTextLCD lcd(IOPORTB, IOPORTD, IOPIN2, IOPIN7, IOPIN5);
AnalogInput adc(ADC0);

int main(void)
{
	lcd.initialize();
	lcd.string(0, 0, "ADC Result:");
	adc.initialize();
	adc.startConversion();
	while (1)
	{
	}
	
}

ISR(ADC_vect)
{
	adc.readValue();
	lcd.integer(12, 0, adc.value, 4);
	_delay_ms(500);
	adc.startConversion();
}