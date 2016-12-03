#include "atmicro.h"
#include "box/parse.h"
#include <avr/interrupt.h>
#include <math.h>

#define COUNT 3
#define RANGE 400
#define NRLVL (max+min)/2
#define CBOOT 5000
Accelerometer ac(ADC2, ADC1, ADC0);
long loopCount = 0, disasterCount = 0;
int main(void)
{
	int max = 0, min = 999999, val = 0;
	ParallelTextLCD lcd(IOPORTB, IOPIND2, IOPIND7, IOPIND5);
	_delay_ms(300);
	while (1)
	{
		val = sqrt(pow(ac.x, 2) + pow(ac.y, 2) + pow(ac.z, 2));
		max = fmax(max, val);
		min = fmin(min, val);
		
		if(fabs(val - NRLVL) > RANGE)
			disasterCount++;
		else if (loopCount > CBOOT && disasterCount < COUNT)
		{
			loopCount = 0;
			disasterCount = 0;
			max = val; min = val;
		}

		if(disasterCount > COUNT)
			lcd.string(0, 0, "You Just Fell :(");
		else
			lcd.string(0, 0, "You Are Good :)");

		lcd.integer(0, 1, fabs(max - NRLVL));
		lcd.string("    ");
		lcd.integer(8, 1, disasterCount);
	}
}

ISR(ADC_vect)
{
	ac.update();
	if (disasterCount > 0) loopCount++;
}