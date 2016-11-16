#include <avr/io.h>
#include <util/delay.h>
#include "drivers/ParallelTextLCD.h"
#include "drivers/Keypad.h"
using namespace Integral;
int main(void)
{
	ParallelTextLCD lcd(IOPORTB, IOPIND2, IOPIND7, IOPIND5);
	lcd.string(0, 1, "123A456B789C*0#D");
	//initializing the pad
	DDRA = 0x0F;
	PORTA = 0xFF;
	while(1)
	{
		//scanning the pad
		KeypadMatrix mat;
		Device::setStatus(IOPINA0, LOW);
		for (int i = 0; i < 4; i++)
		{
			PORTA &= ~(1<<i);
			for(int j = 0; j < 4; j++)
				mat.set(i, j, Keypad::switchPressed((PIN)(IOPORTA + 4 + j)));
			PORTA |= (1<<i);
		}

		//Printing results of scan
		for (int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				if (mat.get(i, j))
					lcd.string(i*4 + j, 0, "1");
				else
					lcd.string(i*4 + j, 0, "0");
			}
		}
		_delay_ms(100);
	}
}