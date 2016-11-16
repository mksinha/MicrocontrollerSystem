#include <avr/io.h>
#include <util/delay.h>
#include "drivers/ParallelTextLCD.h"
#include "drivers/Keypad.h"
using namespace Integral;
int main(void)
{
	ParallelTextLCD lcd(IOPORTB, IOPIND2, IOPIND7, IOPIND5);
	lcd.string(0, 1, "123A456B789C*0#D");
	Keypad pad(IOPORTA);
	while(1)
	{
		for (int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
			{
				if (pad.isPressed().get(i, j))
					lcd.string(i*4 + j, 0, "1");
				else
					lcd.string(i*4 + j, 0, "0");
			}
		_delay_ms(100);
	}
}