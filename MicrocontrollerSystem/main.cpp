#include <avr/io.h>
#include <util/delay.h>
#include "drivers/LED.h"
#include "drivers/ParallelTextLCD.h"
#include "drivers/PushButtonSwitch.h"
using namespace Integral;

int main(void)
{
	LED led(IOPIND0);
	ParallelTextLCD lcd(IOPORTB, IOPIND2, IOPIND7, IOPIND5);
	PushButtonSwitch swt(IOPINC0);
	led.on();
	lcd.string(0, 0, "Hello Control!");
	while (1)
	{
		led.toggle();
		_delay_ms(100);
	}
}