#include <avr/io.h>
#include <util/delay.h>
#include "drivers/LED.h"

using namespace Integral;

LED led(IOPIND0);

int main(void)
{
	led.on();
	while (1)
	{
		led.toggle();
		_delay_ms(100);
	}
}