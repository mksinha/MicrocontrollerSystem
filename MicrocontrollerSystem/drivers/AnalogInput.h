/* 
* AnalogInput.h
*
* Created: 4/28/2016 10:58:39 PM
* Author: Manish Sinha
*/


#ifndef __ANALOGINPUT_H__
#define __ANALOGINPUT_H__

#include "Input.h"

namespace Integral
{
	namespace ADCconfig {
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
	protected:
		ADCchannel pin;
		void (*callback)(int value, ADCchannel channel);

	//functions
	public:
		AnalogInput(ADCchannel pin);
		~AnalogInput();
		static void globablInit(ADCconfig::VREF vref = ADCconfig::IREF, ADCconfig::ADPS adps = ADCconfig::PS16);
		void initialize();
		ADCchannel getChannel();
		bool isLive();
		void readValue();
		void startConversion();
		void stopConversion();
		void setCallback(void (*func)(int, ADCchannel));
		void process();
	private:
		AnalogInput( const AnalogInput &c );
		AnalogInput& operator=( const AnalogInput &c );
	}; //AnalogInput
}

#endif //__ANALOGINPUT_H__