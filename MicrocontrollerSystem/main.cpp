#include <avr/io.h>
#include <util/delay.h>
#include "drivers/LED.h"
#include "controller/Pinset.h"
using namespace Integral; 

int main(void)
{
	PIN pinlist[4] = {IOPIND1, IOPIND3, IOPIND6, IOPIND4};
	Pinset pins(4, pinlist);
	while (1)
	{
		pins.putData(0b1010);
		_delay_ms(200);
		pins.putData(0b0110);
		_delay_ms(200);
		pins.putData(0b0101);
		_delay_ms(200);
		pins.putData(0b1001);
		_delay_ms(200);
	}
}