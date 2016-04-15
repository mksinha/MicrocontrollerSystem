/* 
* Microcontroller.cpp
*
* Created: 4/16/2016 12:29:58 AM
* Author: Animesh Sinha
*/


#include "Microcontroller.h"

// default constructor
Microcontroller::Microcontroller()
{
} //Microcontroller

// default destructor
Microcontroller::~Microcontroller()
{
} //~Microcontroller

void Microcontroller::createTask(void (*func)(void))
{
	this->threadInit = func;
}

void Microcontroller::execute()
{
	this->threadInit();
}