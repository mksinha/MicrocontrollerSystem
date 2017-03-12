#include "atmicro.h"
#include "remote/parse.h"
int main(void)
{
	ParallelTextLCD lcd(IOPORTB, IOPIND4, IOPIND3, IOPIND2);
	DigitalOutput backlight(IOPIND5); backlight.on();
	Istream in;
	Keypad pad(IOPORTC);
	while (1)
	{
		in.update(pad);
		parse(in, lcd);
	}
}