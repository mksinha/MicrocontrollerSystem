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
	ADCPIN pin;
private:

//functions
public:
	AnalogInput(ADCPIN pin);
	~AnalogInput();
	void initialize();
	ADCPIN getID();
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
