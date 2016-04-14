/* 
* Output.h
*
* Created: 4/11/2016 9:06:43 PM
* Author: Animesh Sinha
*/


#ifndef __OUTPUT_H__
#define __OUTPUT_H__

#include "Device.h"

class Output : public Device
{
//functions
public:
	virtual void initialize()=0;//make Output not instantiable
protected:
	static void pinStatus(int port, int pin, bool state);
	static void pinDirection(int port, int pin, bool state);
	static void portStatus(int port, int state);
	static void portDirection(int port, int state);
	static bool pinStatus(int port, int pin);
	static bool pinDirection(int port, int pin);
}; //Output

#endif //__OUTPUT_H__
