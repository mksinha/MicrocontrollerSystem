/* 
* LED.h
*
* Created: 4/10/2016 12:32:17 PM
* Author: Manish Sinha
*/


#ifndef __LED_H__
#define __LED_H__


class LED
{
//variables
public:
protected:
	bool status;
private:

//functions
public:
	LED();
	~LED();
	void on();
	void off();
	bool toggle();
protected:
private:
	LED( const LED &c );
	LED& operator=( const LED &c );

}; //LED

#endif //__LED_H__
