#include "atmicro.h"
#include "box/parse.h"
int main(void)
{
	DigitalOutput backlight(IOPIND5); backlight.on();
	ParallelTextLCD lcd(IOPORTB, IOPIND4, IOPIND3, IOPIND2);
	Keypad pad(IOPORTC); Istream inp; State state;
	while (1)
	{
		inp.update(pad);
		parse(inp, lcd, state);
	}
}