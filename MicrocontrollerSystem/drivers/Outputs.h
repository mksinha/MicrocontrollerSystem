/* 
* Outputs.h
*
* Created: 4/11/2016 9:06:43 PM
* Author: Animesh Sinha
*/


#ifndef __OUTPUTS_H__
#define __OUTPUTS_H__

#define IOPORTA 0
#define IOPORTB 1
#define IOPORTC 2
#define IOPORTD 3

class Outputs
{
//functions
public:
	virtual bool test()=0;//make Outputs not instantiable
protected:
	static void pinStatus(int port, int pin, bool state);
	static void pinDirection(int port, int pin, bool state);
}; //Outputs

#endif //__OUTPUTS_H__
