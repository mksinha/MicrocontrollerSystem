/* 
* PushButtonSwitch.h
*
* Created: 4/15/2016 8:29:33 PM
* Author: Manish Sinha
*/

#include "Input.h"

#ifndef __PUSHBUTTONSWITCH_H__
#define __PUSHBUTTONSWITCH_H__


class PushButtonSwitch : public Input
{
//variables
public:
protected:
private:

//functions
public:
	PushButtonSwitch();
	~PushButtonSwitch();
protected:
private:
	PushButtonSwitch( const PushButtonSwitch &c );
	PushButtonSwitch& operator=( const PushButtonSwitch &c );

}; //PushButtonSwitch

#endif //__PUSHBUTTONSWITCH_H__
