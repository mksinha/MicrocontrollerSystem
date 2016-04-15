/* 
* Microcontroller.h
*
* Created: 4/16/2016 12:30:01 AM
* Author: Animesh Sinha
*
*	NOTE: Use tasks only for functions with no parameters
*	or returns, for parameterized functions, use data-bind,
*	callback or other mechanisms.
*/


#ifndef __MICROCONTROLLER_H__
#define __MICROCONTROLLER_H__


class Microcontroller
{
//variables
public:
	void (*threadInit)(void);
protected:
private:

//functions
public:
	Microcontroller();
	~Microcontroller();
	void createTask(void (*func)(void));
	void execute();
protected:
private:
	Microcontroller( const Microcontroller &c );
	Microcontroller& operator=( const Microcontroller &c );

}; //Microcontroller

#endif //__MICROCONTROLLER_H__
