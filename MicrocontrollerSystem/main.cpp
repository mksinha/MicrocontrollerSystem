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

int main(void)
{
	LED led(IOPORTC, IOPIN6);
	ParallelTextLCD lcd(IOPORTB, IOPORTD, IOPIN2, IOPIN7, IOPIN5);
	lcd.string(0, 0, "Test Z");
	lcd.integer(0, 1, 865, 5);
    while (1)
    {
		led.toggle();
		_delay_ms(200);
    }
	return 0;
}