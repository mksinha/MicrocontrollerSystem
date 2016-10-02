#include <avr/io.h>
#include <util/delay.h>
#include "drivers/USART.h"
#include "drivers/LED.h"

#define CODE_TXD // Currently programming the transmitter

using namespace Integral;

int main(void)
{
	USART usart(960);
	LED led(IOPINA0);
	#ifdef CODE_TXD
		_delay_ms(2000);
		usart.transmit(0xd3);
		led.on();
	#endif
	while (1)
	{
		#ifdef CODE_RXD
			if (usart.receive() == 0xd3)
				led.on();
		#endif
	}
}