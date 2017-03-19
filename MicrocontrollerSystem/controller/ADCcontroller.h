/* 
* ADCcontroller.h
*
* Created: 3/15/2017 4:28:12 PM
* Author: mksin
*/


#ifndef __ADCCONTROLLER_H__
#define __ADCCONTROLLER_H__

#include <stddef.h>

namespace atmicro
{
	class AnalogInput;

	class ADCcontroller
	{
	//variables
	private:
		AnalogInput* listADC[8];
		bool adcProcessRunning = false;
		void (*cycleListener)() = NULL;

	//functions
	public:
		ADCcontroller();
		~ADCcontroller();
		void registerADC(AnalogInput& adc);
		void clearADC();
		void processADC();
		void startADC();
		void stopADC();
		void setCycleListener(void (*cycleEndListener)());
	}; //ADCcontroller
}

#endif //__ADCCONTROLLER_H__
