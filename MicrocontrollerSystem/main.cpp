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
	lcd.string(0, 0, "Hello Controller");
	lcd.integer(5, 1, 1309, 5);
    lcd.cursor(true, true);
	while (1)
    {
		led.toggle();
		_delay_ms(500);
    }
	return 0;
}