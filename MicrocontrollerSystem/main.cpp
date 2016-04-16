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
	PushButtonSwitch pbswitch(IOPORTA, IOPIN0, true, true, 100);
	ParallelTextLCD lcd(IOPORTB, IOPORTD, IOPIN2, IOPIN7, IOPIN5);
	lcd.string(0, 0, "Hello Debugger");
	lcd.integer(6, 1, 1309, 5);
	led.on();
	while (1)
    {
		led.toggle();
		if (pbswitch.state()) _delay_ms(100);
		else _delay_ms(1000);
	}
	return 0;
}