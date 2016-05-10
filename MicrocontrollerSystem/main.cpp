#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "drivers/ParallelTextLCD.h"
#include "drivers/AnalogInput.h"
#include "drivers/LED.h"
#include "drivers/PushButtonSwitch.h"

using namespace Integral;

void display(int value, ADCchannel channel);

ParallelTextLCD lcd(IOPORTB, IOPORTD, IOPIN2, IOPIN7, IOPIN5);
AnalogInput adc(ADC0);
AnalogInput pot(ADC1);
PushButtonSwitch pbs(IOPORTC, IOPIN6, false, HIGH);
LED led(IOPORTC, IOPIN7);

int main(void)
{
	lcd.string(0, 0, "ADC Result:");
	lcd.string(0, 1, "POT Result:");
	adc.setCallback(display);
	pot.setCallback(display);
	adc.startConversion();
	while (1)
	{
		led.toggle();
		// Blink Speed
		if (pbs.state() == HIGH)
			_delay_ms(100);
		else if (pbs.state() == LOW)
			_delay_ms(1000);
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