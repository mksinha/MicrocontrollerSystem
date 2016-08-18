#include <avr/io.h>
#include "drivers/USART.h"
#include <util/delay.h>
#include "drivers/LED.h"

using namespace Integral;

int main(void)
{
	_delay_ms(2000);
	USART usart(960);
	LED led(IOPINA0);
	usart.transmit(0xff);
//	if (usart.receive()==0xff)
	led.on();
	while (1)
	{	
	}
}