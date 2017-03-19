/* 
* Accelerometer.h
*
* Created: 3/19/2017 1:34:23 PM
* Author: Animesh Sinha
*/


#ifndef __ACCELEROMETER_H__
#define __ACCELEROMETER_H__

#include "../drivers/AnalogInput.h"
#include "../data/QueueArray.h"

namespace atmicro
{
	class Accelerometer
	{
	public:
		int x=0, y=0, z=0;
	private:
		AnalogInput* listADC[3];
		QueueArray<int> listX, listY, listZ;

	//functions
	public:
		Accelerometer();
		~Accelerometer();
		void registerADC(AnalogInput& adc);
		void clearADC();
		void processADC();
		void startADC();
		void stopADC();
	}; //Accelerometer
}

#endif //__ACCELEROMETER_H__
