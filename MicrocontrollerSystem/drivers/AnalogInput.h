/* 
* AnalogInput.h
*
* Created: 4/28/2016 10:58:39 PM
* Author: Manish Sinha
*/


#ifndef __ANALOGINPUT_H__
#define __ANALOGINPUT_H__

#include "Input.h"


class AnalogInput : public Input
{
//variables
public:
	uint16_t value;
	void (*callback)(void);
protected:
	ADCchannel pin;
private:

//functions
public:
	AnalogInput(ADCchannel pin);
	~AnalogInput();
	static void globablInit();
	void initialize();
	ADCchannel getID();
	void setCallback(void (*func)(void));
	void readValue();
	void startConversion();
	void stopConversion();
protected:
private:
	AnalogInput( const AnalogInput &c );
	AnalogInput& operator=( const AnalogInput &c );

}; //AnalogInput

#endif //__ANALOGINPUT_H__
