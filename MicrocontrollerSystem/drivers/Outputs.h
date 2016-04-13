/* 
* Outputs.h
*
* Created: 4/11/2016 9:06:43 PM
* Author: Animesh Sinha
*/


#ifndef __OUTPUTS_H__
#define __OUTPUTS_H__

#include "Devices.h"

class Outputs : public Devices
{
//functions
public:
	virtual void initialize()=0;//make Outputs not instantiable
protected:
	static void pinStatus(int port, int pin, bool state);
	static void pinDirection(int port, int pin, bool state);
	static void portStatus(int port, int state);
	static void portDirection(int port, int state);
	static bool pinStatus(int port, int pin);
	static bool pinDirection(int port, int pin);
}; //Outputs

#endif //__OUTPUTS_H__
