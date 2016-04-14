/* 
* Microcontroller.h
*
* Created: 4/15/2016 1:10:43 AM
* Author: Animesh Sinha
*/


#ifndef __MICROCONTROLLER_H__
#define __MICROCONTROLLER_H__


class Microcontroller
{
//functions
public:
	virtual ~Microcontroller();
	virtual void Method1()=0;//make Microcontroller not instantiable
	virtual void Method2();
	void Method3();

}; //Microcontroller

#endif //__MICROCONTROLLER_H__
