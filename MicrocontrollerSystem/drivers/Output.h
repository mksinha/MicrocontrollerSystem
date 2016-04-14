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
	static void pinStatus(PORT port, PIN pin, bool state);
	static void pinDirection(PORT port, PIN pin, bool state);
	static void portStatus(PORT port, int state);
	static void portDirection(PORT port, int state);
	static bool pinStatus(PORT port, PIN pin);
	static bool pinDirection(PORT port, PIN pin);
}; //Output

#endif //__OUTPUT_H__
