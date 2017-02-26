#include "atmicro.h"

int main(void)
{
	ParallelTextLCD lcd(IOPORTB, IOPIND4, IOPIND5, IOPIND6);
	DigitalOutput backlight(IOPIND7);
	AnalogInput pot(ADC0, 
		[](AnalogInput e) {
			ParallelTextLCD* lcd = (ParallelTextLCD*)DeviceController::getDevice("LCD");
			lcd->string(0, 0, "      ");
			lcd->integer(0, 0, e.value);
			_delay_ms(500);
		});
	AnalogInput adc(ADC1,
		[](AnalogInput e) {
			ParallelTextLCD* lcd = (ParallelTextLCD*)DeviceController::getDevice("lcd");
			lcd->string(0, 1, "      ");
			lcd->integer(0, 1, e.value);
			_delay_ms(500);
		});

	backlight.on();
	DeviceController::registerDevice(&lcd, "lcd");
	ADCcontroller::registerADC(pot);
	ADCcontroller::registerADC(adc);
	ADCcontroller::startADC();

	while (1)
	{		
	}
}