#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "drivers/ParallelTextLCD.h"
#include "drivers/AnalogInput.h"
// "drivers/LED.h" LED
// "drivers/PushButtonSwitch.h" PushButtonSwitch

void display(int value, ADCchannel channel);

ParallelTextLCD lcd(IOPORTB, IOPORTD, IOPIN2, IOPIN7, IOPIN5);
AnalogInput adc(ADC0);
AnalogInput pot(ADC1);

int main(void)
{
	lcd.string(0, 0, "ADC Result:");
	lcd.string(0, 1, "POT Result:");
	adc.setCallback(display);
	pot.setCallback(display);
	adc.startConversion();
	while (1)
	{
	}
}

ISR(ADC_vect)
{
	if (adc.isLive())
	{
		adc.process();
		pot.startConversion();
	}
	else if (pot.isLive())
	{
		pot.process();
		adc.startConversion();
	}
}

void display(int value, ADCchannel channel)
{
	lcd.integer(11, channel, value, 4);
	_delay_ms(500);
}