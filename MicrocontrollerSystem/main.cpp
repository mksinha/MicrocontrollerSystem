#include <avr/io.h>
#include <util/delay.h>
#include "drivers/DigitalOutput.h"
#include "drivers/PushButtonSwitch.h"
#include "drivers/Keypad.h"
#include "drivers/ParallelTextLCD.h"
using namespace Integral;
int main(void)
{
	DigitalOutput led(IOPIND5);
	Keypad pad(IOPORTA);
	ParallelTextLCD lcd(IOPORTB, IOPIND2, IOPIND7, IOPIND5);
	led.off();
	while(1)
	{
		if (pad.isPressed().get(0, 1))
			led.on();
		else
			led.off();
		_delay_ms(1000);
	}
}