/* 
* LED.h
*
* Created: 4/10/2016 12:32:17 PM
* Author: Manish Sinha
*/

#include "Outputs.h"

#ifndef __LED_H__
#define __LED_H__

class LED : public Outputs
{
//variables
public:
protected:
	bool status; 
	int port, pin;
private:

//functions
public:
	LED(int port, int pin);
	~LED();
	void on();
	void off();
	bool toggle();
	void initialize();
protected:
private:
	LED( const LED &c );
	LED& operator=( const LED &c );

}; //LED

#endif //__LED_H__
