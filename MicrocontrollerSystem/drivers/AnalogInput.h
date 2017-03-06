/* 
* AnalogInput.h
*
* Created: 4/28/2016 10:58:39 PM
* Author: Manish Sinha
*/


#ifndef __ANALOGINPUT_H__
#define __ANALOGINPUT_H__

#include "Input.h"
#include <stddef.h>

namespace atmicro
{
	namespace ADCconf {
		enum ADPS {
			PS2 = 1, PS4 = 2, PS8 = 3, PS16 = 4,
			PS32 = 5, PS64 = 6, PS128 = 7
		};
		enum VREF {
			AREF = 0, AVCC = 1, IREF = 3
		};
	}

	class AnalogInput : public Input
	{
	//variables
	public:
		uint16_t value;
		ADCchannel pin;
	protected:
		void (*callback)(AnalogInput e) = NULL;

	//functions
	public:
		AnalogInput(ADCchannel pin);
		AnalogInput(ADCchannel pin, void (*func)(AnalogInput));
		~AnalogInput();
		void initialize();
		bool isLive();
		void startConversion();
		void stopConversion();
		void setEventListener(void (*func)(AnalogInput));
		void process();
		static void gInit(ADCconf::VREF vref = ADCconf::IREF, ADCconf::ADPS adps = ADCconf::PS16);
	}; //AnalogInput
}

#endif //__ANALOGINPUT_H__