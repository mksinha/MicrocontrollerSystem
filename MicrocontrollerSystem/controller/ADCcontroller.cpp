/* 
* ADCcontroller.cpp
*
* Created: 3/15/2017 4:28:12 PM
* Author: mksin
*/


#define InterruptADC ISR(ADC_vect)

#include "ADCcontroller.h"

namespace atmicro
{
	// default constructor
	ADCcontroller::ADCcontroller()
	{
		clearADC();
		stopADC();
	} //ADCcontroller

	// default destructor
	ADCcontroller::~ADCcontroller()
	{
		stopADC();
		clearADC();
	} //~ADCcontroller

	void ADCcontroller::registerADC(AnalogInput& adc)
	{
		for (int i = 0; i < 8; i++)
		{
			if (adc.pin == (ADCchannel)i)
			{
				listADC[i] = &adc;
				break;
			}
		}
	}

	void ADCcontroller::clearADC()
	{
		for (int i = 0; i < 8; i++)
		{
			listADC[i] = NULL;
		}
		ADCSRA &= ~(1 << ADSC);
	}

	void ADCcontroller::processADC()
	{
		if (!adcProcessRunning)	return;
		for (int i = 0; i < 8; i++)
		{
			if(listADC[i]->isLive())
			{
				listADC[i]->process();
				for (int j = 0; j < 8; j++)
				{
					if (listADC[(i+j+1)%8] != NULL)
					{
						listADC[(i+j+1)%8]->startConversion();
						break;
					}
				}
				break;
			}
		}
	}

	void ADCcontroller::startADC()
	{
		adcProcessRunning = true;
		for (int i = 0; i < 8; i++)
		{
			if (listADC[i] != NULL)
			{
				listADC[i]->startConversion();
				return;
			}
		}
	}

	void ADCcontroller::stopADC()
	{
		adcProcessRunning = false;
		ADCSRA &= ~(1 << ADSC);
	}
}