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
protected:
	PIN pin;
	void (*callback)(void);
private:

//functions
public:
	AnalogInput(PIN pin);
	~AnalogInput();
	void initialize();
	void setCallback(void (*func)(void));
protected:
private:
	AnalogInput( const AnalogInput &c );
	AnalogInput& operator=( const AnalogInput &c );

}; //AnalogInput

#endif //__ANALOGINPUT_H__
