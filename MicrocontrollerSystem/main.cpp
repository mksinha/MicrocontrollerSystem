#include "atmicro.h"
#include "drivers/Accelerometer.h"
Accelerometer ac;
ParallelTextLCD lcd = ParallelTextLCD(IOPORTB, IOPIND4, IOPIND3, IOPIND2);
int main(void)
{
	DigitalOutput backlight = DigitalOutput(IOPIND5);	backlight.on();
	AnalogInput adcx(ADC0);	ac.registerADC(adcx);
	AnalogInput adcy(ADC1);	ac.registerADC(adcy);
	AnalogInput adcz(ADC2);	ac.registerADC(adcz);
	ac.startADC();
	while(1);
}

ISR(ADCvector)
{
	ac.processADC();
	lcd.print( 0, 0, ac.x);
	lcd.print( 5, 0, ac.y);
	lcd.print(10, 0, ac.z);
}