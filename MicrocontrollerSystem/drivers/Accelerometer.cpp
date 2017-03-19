/* 
* Accelerometer.cpp
*
* Created: 3/19/2017 1:34:22 PM
* Author: Animesh Sinha
*/


#include "Accelerometer.h"
#include <stddef.h>
#include "../drivers/AnalogInput.h"

namespace atmicro
{
	// default constructor
	Accelerometer::Accelerometer()
	{
		clearADC();
		stopADC();
		for (int i = 0; i < 10; i++)
		{
			listX.enqueue(0);
			listY.enqueue(0);
			listZ.enqueue(0);
		}
	} //ADCcontroller

	// default destructor
	Accelerometer::~Accelerometer()
	{
		stopADC();
		clearADC();
	} //~ADCcontroller

	void Accelerometer::registerADC(AnalogInput& adc)
	{
		for (int i = 0; i < 3; i++)
		{
			if (adc.pin == (ADCchannel)i)
			{
				listADC[i] = &adc;
				break;
			}
		}
	}

	void Accelerometer::clearADC()
	{
		for (int i = 0; i < 3; i++)
		{
			listADC[i] = NULL;
		}
		ADCSRA &= ~(1 << ADSC);
	}

	void Accelerometer::processADC()
	{
		for (int i = 0; i < 3; i++)
		{
			if(listADC[i]->isLive())
			{
				listADC[i]->process();
				for (int j = 0; j < 3; j++)
				{
					if (listADC[(i+j+1)%3] != NULL)
					{
						listADC[(i+j+1)%3]->startConversion();
						break;
					}
				}
				break;
			}
		}
		x -= listX.dequeue()/10;
		y -= listY.dequeue()/10;
		z -= listZ.dequeue()/10;
		x += (listADC[0]->value)/10;
		y += (listADC[1]->value)/10;
		z += (listADC[2]->value)/10;
		listX.enqueue(listADC[0]->value);
		listY.enqueue(listADC[1]->value);
		listZ.enqueue(listADC[2]->value);
	}

	void Accelerometer::startADC()
	{
		for (int i = 0; i < 3; i++)
		{
			if (listADC[i] != NULL)
			{
				listADC[i]->startConversion();
				return;
			}
		}
	}

	void Accelerometer::stopADC()
	{
		ADCSRA &= ~(1 << ADSC);
	}
}