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
#include "drivers/PushButtonSwitch.h"

int main(void)
{
	LED led(IOPORTC, IOPIN6);
	PushButtonSwitch pbswitch(IOPORTA, IOPIN0, true, true);
	ParallelTextLCD lcd(IOPORTB, IOPORTD, IOPIN2, IOPIN7, IOPIN5);
	led.on();
	lcd.string(0, 0, "Hello Framework!");
	lcd.integer(7, 1, 1309, 5);
	_delay_ms(5000);
	lcd.clear();
	lcd.string("Value: ");
	int counter = 0;
	while (1)
    {
		lcd.integer(7, 0, ++counter, 5);
		led.toggle();
		if (pbswitch.state()) _delay_ms(100);
		else _delay_ms(1000);
	}
	return 0;
}