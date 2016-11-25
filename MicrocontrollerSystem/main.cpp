#include "atmicro.h"
#include "remote/parse.h"
int main(void)
{
	Keypad pad(IOPORTA);
	Istream inp;
	ParallelTextLCD lcd(IOPORTB, IOPIND2, IOPIND7, IOPIND5);
	while (1)
	{
		inp.update(pad);
		parse(inp, lcd);
	}
}