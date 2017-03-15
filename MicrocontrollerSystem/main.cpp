#include "atmicro.h"

DigitalOutput backlight = DigitalOutput(IOPIND5);
ParallelTextLCD lcd = ParallelTextLCD(IOPORTB, IOPIND4, IOPIND3, IOPIND2);
ADCcontroller mux;
int main(void)
{
	backlight.on();
	AnalogInput adca(ADC3,[](AnalogInput e){lcd.print(0,1,(int)e.value);lcd.print("   ");});
	AnalogInput adcb(ADC4,[](AnalogInput e){lcd.print(5,1,(int)e.value);lcd.print("   ");});
	AnalogInput adcc(ADC5,[](AnalogInput e){lcd.print(10,1,(int)e.value);lcd.print("   ");});
	AnalogInput adcx(ADC0,[](AnalogInput e){lcd.print(0,0,(int)e.value);lcd.print("   ");});
	AnalogInput adcy(ADC1,[](AnalogInput e){lcd.print(5,0,(int)e.value);lcd.print("   ");});
	AnalogInput adcz(ADC2,[](AnalogInput e){lcd.print(10,0,(int)e.value);lcd.print("   ");_delay_ms(500);});
	mux.registerADC(adca);
	mux.registerADC(adcb);
	mux.registerADC(adcc);
	mux.registerADC(adcx);
	mux.registerADC(adcy);
	mux.registerADC(adcz);
	mux.startADC();
	while (1);
}

ISR(ADC_vect)
{
	mux.processADC();
}