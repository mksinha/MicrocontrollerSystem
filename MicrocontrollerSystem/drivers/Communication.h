/* 
* Communication.h
*
* Created: 4/13/2016 1:06:45 AM
* Author: Animesh Sinha
*/


#ifndef __COMMUNICATION_H__
#define __COMMUNICATION_H__

#include "Device.h"

class Communication : public Device
{
//functions
public:
	virtual ~Communication();
	virtual void Method1()=0;//make Communication not instantiable
	virtual void Method2();
	void Method3();

}; //Communication

#endif //__COMMUNICATION_H__
