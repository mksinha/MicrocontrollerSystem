/*
 * adc.h
 *
 * Created: 2/26/2017 10:17:08 AM
 *  Author: Animesh Sinha
 */ 


#if(__OPTION_ADMUX)

#ifndef ADC_H_
#define ADC_H_

#include <avr/interrupt.h>
using namespace atmicro;

namespace atmicro
{
	namespace ADCcontroller
	{
		AnalogInput* adcList[8];
		short nAvailable = 0;
		short nActive = 0;

		void startADC()
 		{
			if(nActive == 0) return;
			adcList[nActive - 1]->startConversion();
		}

		void stopADC()
		{
			adcList[nActive - 1]->stopConversion();
		}

		void registerADC(AnalogInput &stream)
		{
			if(nAvailable == 0)
				nActive = 1;
			adcList[nAvailable] = &stream;
			nAvailable++;
		}

		void clearADClist()
		{
			nAvailable = 0;
			nActive = 0;
		}
	}
}

ISR(ADC_vect)
{
	if(ADCcontroller::nActive == ADCcontroller::nAvailable)
	{
		ADCcontroller::adcList[ADCcontroller::nActive - 1]->process();
		ADCcontroller::nActive = 1;
		ADCcontroller::adcList[ADCcontroller::nActive - 1]->startConversion();
	}
	else
	{
		ADCcontroller::adcList[ADCcontroller::nActive - 1]->process();
		ADCcontroller::adcList[ADCcontroller::nActive++]->startConversion();
	}
}

#endif

#endif