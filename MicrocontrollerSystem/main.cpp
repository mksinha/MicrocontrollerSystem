#include <avr/io.h>
#include "drivers/DigitalOutput.h"
#include "drivers/PushButtonSwitch.h"
using namespace Integral;
int main(void)
{
	PushButtonSwitch pb(IOPIND6);
	DigitalOutput led(IOPIND5);
	
	DigitalOutput row0(IOPINA0); 
	DigitalOutput row1(IOPINA1);
	DigitalOutput row2(IOPINA2);
	DigitalOutput row3(IOPINA3);
	PushButtonSwitch col0(IOPINA4);
	PushButtonSwitch col1(IOPINA5);
	PushButtonSwitch col2(IOPINA6);
	PushButtonSwitch col3(IOPINA7);
	row0.on();
	row1.on();
	row2.on();
	row3.on();
	while(1)
	{
		row0.off();
		if (col1.pressed() || pb.pressed())
			led.on();
		else
			led.off();
	}
}