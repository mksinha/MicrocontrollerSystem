#include "atmicro.h"

int main(void)
{
	ParallelTextLCD lcd(IOPORTB, IOPIND4, IOPIND5, IOPIND6);
	lcd.print(5, 0, "Hello!");
	while (1)
	{		
	}
}