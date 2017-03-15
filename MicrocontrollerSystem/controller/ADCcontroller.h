/* 
* ADCcontroller.h
*
* Created: 3/15/2017 4:28:12 PM
* Author: mksin
*/


#ifndef __ADCCONTROLLER_H__
#define __ADCCONTROLLER_H__

#include "../drivers/AnalogInput.h"

namespace atmicro
{
	class ADCcontroller
	{
	//variables
	public:
		AnalogInput* listADC[8];
		bool adcProcessRunning = false;

	//functions
	public:
		ADCcontroller();
		~ADCcontroller();
		void registerADC(AnalogInput& adc);
		void clearADC();
		void processADC();
		void startADC();
		void stopADC();
	protected:
	private:
		ADCcontroller( const ADCcontroller &c );
		ADCcontroller& operator=( const ADCcontroller &c );

	}; //ADCcontroller
}

#endif //__ADCCONTROLLER_H__
