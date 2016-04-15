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
#include "controller/Microcontroller.h"

void initSystem();

int main(void)
{
	Microcontroller atmega32;
	atmega32.createTask(initSystem);
	atmega32.execute();
	while (1)
    {
    }
	return 0;
}

void initSystem()
{
	LED led(IOPORTC, IOPIN6);
	ParallelTextLCD lcd(IOPORTB, IOPORTD, IOPIN2, IOPIN7, IOPIN5);
	led.on();
	lcd.string(0, 0, "Hello Controller");
	lcd.integer(5, 1, 1309, 5);
	lcd.cursor(true, true);
}