#include "atmicro.h"
#include "box/parse.h"
int main(void)
{
	ParallelTextLCD lcd(IOPORTB, IOPIND2, IOPIND7, IOPIND5);
	Keypad pad(IOPORTC);
	Istream inp;
	while (1)
	{
		inp.update(pad);
		parse(inp, lcd);
	}
}