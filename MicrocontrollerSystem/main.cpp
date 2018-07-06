#include "atmicro.h"
#include "drivers/ParallelGraphicLCD.h"
using namespace atmicro;

ParallelGraphicLCD lcd = ParallelGraphicLCD(IOPORTB, IOPIND0, IOPIND1, IOPIND2);

int main(void)
{
	lcd.clear();
	for (int y = 0; y < 10; y++) {
		lcd.command(0b10000000 | y);
		lcd.command(0b10000000);
		for (int x = 0; x < 16; x++) {
			lcd.data(0xFF);
		}
	}
}