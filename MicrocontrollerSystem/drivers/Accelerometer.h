/* 
* Accelerometer.h
*
* Created: 3/19/2017 1:34:23 PM
* Author: Animesh Sinha
*/


#ifndef __ACCELEROMETER_H__
#define __ACCELEROMETER_H__

#include "AnalogInput.h"
#include "../data/QueueArray.h"

namespace atmicro
{
	class Accelerometer
	{
	public:
		short x=0, y=0, z=0;
	private:
		AnalogInput lineX = AnalogInput(ADC0);
		AnalogInput lineY = AnalogInput(ADC0);
		AnalogInput lineZ = AnalogInput(ADC0);

	//functions
	public:
		Accelerometer(ADCchannel x, ADCchannel y, ADCchannel z);
		~Accelerometer();
		void process();
		void start();
		void stop();
	}; //Accelerometer
}

#endif //__ACCELEROMETER_H__
