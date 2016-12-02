#include "atmicro.h"
#include "box/parse.h"

int main(void)
{
	ParallelTextLCD lcd(IOPORTB, IOPIND2, IOPIND7, IOPIND5);
	Keypad pad(IOPORTC);
	Istream inp;
	State state;
	while (1)
	{
		inp.update(pad);
		parse(inp, lcd, state);
	}
}