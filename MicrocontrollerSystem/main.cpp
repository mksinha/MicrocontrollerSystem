#include "atmicro.h"
#include "remote/parse.h"
int main(void)
{
	Keypad pad(IOPORTA);
	Istream inp;
	while (1)
	{
		inp.update(pad);
		parse(inp);
	}
}