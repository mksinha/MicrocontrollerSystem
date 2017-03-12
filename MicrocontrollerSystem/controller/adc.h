/*
 * adc.h
 *
 * Created: 2/26/2017 10:17:08 AM
 *  Author: Animesh Sinha
 */ 


#ifndef ADCCONTROLLER_H_
#define ADCCONTROLLER_H_

#include <avr/interrupt.h>
#include "../drivers/AnalogInput.h"

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
	if(atmicro::ADCcontroller::nActive == atmicro::ADCcontroller::nAvailable)
	{
		atmicro::ADCcontroller::adcList[atmicro::ADCcontroller::nActive - 1]->process();
		atmicro::ADCcontroller::nActive = 1;
		atmicro::ADCcontroller::adcList[atmicro::ADCcontroller::nActive - 1]->startConversion();
	}
	else
	{
		atmicro::ADCcontroller::adcList[atmicro::ADCcontroller::nActive - 1]->process();
		atmicro::ADCcontroller::adcList[atmicro::ADCcontroller::nActive++]->startConversion();
	}
}

#endif