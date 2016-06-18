#include <avr/io.h>
#include <util/delay.h>
#include "drivers/LED.h"
#include "controller/Pinset.h"
using namespace Integral; 

int main(void)
{
	PIN pinlist[4] = {IOPIND1, IOPIND3, IOPIND4, IOPIND6};
	Pinset pins(4, pinlist);
	pins.putData(14);
	while (1)
	{
	}
}