#define F_CPU 1000000UL			/* Define CPU Frequency e.g. here 8MHz */
#include "atmicro.h"

int main()
{
	NibbleTextLCD lcd(IOPORTB);
	lcd.print(3, 0, "He eats Pizza !");
	lcd.print(3, 1, 3);
	lcd.print(8, 1, 9.45);
	while(1);
} 