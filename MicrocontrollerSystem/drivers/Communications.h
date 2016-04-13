/* 
* Communications.h
*
* Created: 4/13/2016 1:06:45 AM
* Author: Animesh Sinha
*/


#ifndef __COMMUNICATIONS_H__
#define __COMMUNICATIONS_H__

#include "Devices.h"

class Communications : public Devices
{
//functions
public:
	virtual ~Communications();
	virtual void Method1()=0;//make Communications not instantiable
	virtual void Method2();
	void Method3();

}; //Communications

#endif //__COMMUNICATIONS_H__
