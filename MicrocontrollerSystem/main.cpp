/*
 * MicrocontrollerSystem.cpp
 *
 * Created: 4/10/2016 12:04:45 PM
 * Author : Manish Sinha
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "drivers/LED.h"

int main(void)
{
	LED redled(IOPORTB, PIN1);
    while (1) 
    {
		redled.toggle();
		_delay_ms(200);
    }
	return 0;
}