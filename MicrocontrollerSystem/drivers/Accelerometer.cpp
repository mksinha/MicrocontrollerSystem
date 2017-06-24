/* 
* Accelerometer.cpp
*
* Created: 3/19/2017 1:34:22 PM
* Author: Animesh Sinha
*/


#include "Accelerometer.h"
#include "../drivers/AnalogInput.h"

#define STABILIZER_SIZE 10

namespace atmicro
{
	// default constructor
	Accelerometer::Accelerometer(ADCchannel x, ADCchannel y, ADCchannel z)
	{
		lineX = x;
		lineY = y;
		lineZ = z;
	} //ADCcontroller

	// default destructor
	Accelerometer::~Accelerometer()
	{
		stop();
	} //~ADCcontroller

	void Accelerometer::process()
	{
		if(lineX.isLive())
		{
			lineX.process();
			lineY.startConversion();
		}
		else if(lineY.isLive())
		{
			lineY.process();
			lineZ.startConversion();
		}
		else if(lineZ.isLive())
		{
			lineZ.process();
			lineX.startConversion();
		}
		x = lineX.value;
		y = lineY.value;
		z = lineZ.value;
	}

	void Accelerometer::start()
	{
		lineX.startConversion();
	}

	void Accelerometer::stop()
	{
		ADCSRA &= ~(1 << ADSC);
	}
}