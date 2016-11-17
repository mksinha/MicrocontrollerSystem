#include <avr/io.h>
#include <util/delay.h>
#include "drivers/Keypad.h"
#include "interface/Istream.h"
#include "drivers/ParallelTextLCD.h"
using namespace Integral;
int main(void)
{
	Keypad pad(IOPORTA);
	Istream stream;
	ParallelTextLCD lcd(IOPORTB, IOPIND2, IOPIND7, IOPIND5);
	while (1)
	{
		stream.update(pad);
		lcd.string(0, 0, stream.getStream());
		_delay_ms(100);
	}
}