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

#define IOPIN0 0
#define IOPIN1 1
#define IOPIN2 2
#define IOPIN3 3
#define IOPIN4 4
#define IOPIN5 5
#define IOPIN6 6
#define IOPIN7 7

class Outputs
{
//functions
public:
	virtual void initialize()=0;//make Outputs not instantiable
protected:
	static void pinStatus(int port, int pin, bool state);
	static void pinDirection(int port, int pin, bool state);
	static void portStatus(int port, int state);
	static void portDirection(int port, int state);
	static bool pinStatus(int port, int pin);
	static bool pinDirection(int port, int pin);
}; //Outputs

#endif //__OUTPUTS_H__
