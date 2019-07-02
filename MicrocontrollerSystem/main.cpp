#include "atmicro.h"

int main()
{
	SerialTextLCD lcd;
	while(1) 
	{
		lcd.print("Doughnut");
		delay(10000);
	}
} 