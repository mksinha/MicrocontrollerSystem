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
	virtual ~Input();
	virtual void Method1()=0;//make Input not instantiable
	virtual void Method2();
	void Method3();

}; //Input

#endif //__INPUT_H__
