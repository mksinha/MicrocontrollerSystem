/* 
* ATmega32.h
*
* Created: 4/15/2016 1:11:01 AM
* Author: Animesh Sinha
*/

#include "Microcontroller.h"

#ifndef __ATMEGA32_H__
#define __ATMEGA32_H__


class ATmega32 : public Microcontroller
{
//variables
public:
protected:
private:

//functions
public:
	ATmega32();
	~ATmega32();
protected:
private:
	ATmega32( const ATmega32 &c );
	ATmega32& operator=( const ATmega32 &c );

}; //ATmega32

#endif //__ATMEGA32_H__
