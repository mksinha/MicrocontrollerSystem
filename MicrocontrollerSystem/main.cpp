#include <avr/io.h>
#include "drivers/DigitalOutput.h"
#include "drivers/PushButtonSwitch.h"
using namespace Integral;
int main(void)
{
	PushButtonSwitch pb(IOPINB0);
	DigitalOutput led(IOPINA0);
	while(1)
	{
		if (pb.isPressed())
			led.on();
		else
			led.off();
	}
}