/* 
* Input.h
*
* Created: 4/13/2016 1:07:43 AM
* Author: Animesh Sinha
*/


#ifndef __INPUT_H__
#define __INPUT_H__

#include "Device.h"

class Input : public Device
{
//functions
public:
protected:
	static void pinStatus(PORT port, PIN pin, bool state);
	static void pinDirection(PORT port, PIN pin, bool state);
	static bool pinStatus(PORT port, PIN pin);
}; //Input

#endif //__INPUT_H__
