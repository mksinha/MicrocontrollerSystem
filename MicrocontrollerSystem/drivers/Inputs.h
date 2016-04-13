/* 
* Inputs.h
*
* Created: 4/13/2016 1:07:43 AM
* Author: Animesh Sinha
*/


#ifndef __INPUTS_H__
#define __INPUTS_H__

#include "Devices.h"

class Inputs : public Devices
{
//functions
public:
	virtual ~Inputs();
	virtual void Method1()=0;//make Inputs not instantiable
	virtual void Method2();
	void Method3();

}; //Inputs

#endif //__INPUTS_H__
