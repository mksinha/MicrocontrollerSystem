/* 
* Device.h
*
* Created: 4/17/2016 10:32:49 AM
* Author: Animesh Sinha
*/


#ifndef __DEVICE_H__
#define __DEVICE_H__

#include <avr/io.h>
#include "../controller/registry.h"

namespace Integral 
{
	class Device
	{
	//functions
	public:
		virtual void initialize()=0;//make Device not instantiable
	protected:
		static void setStatus(PORT port, POSITION pin, bool state);
		static void setDirection(PORT port, POSITION pin, bool state);
		static void setStatus(PORT port, int state);
		static void setDirection(PORT port, int state);
		static bool getStatus(PORT port, POSITION pin);
	}; //Device
}

#endif //__DEVICE_H__