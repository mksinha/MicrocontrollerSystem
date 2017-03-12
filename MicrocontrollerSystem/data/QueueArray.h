/* 
* QueueArray.h
*
* Created: 3/9/2017 10:53:02 AM
* Author: Animesh Sinha
*/


#ifndef __QUEUEARRAY_H__
#define __QUEUEARRAY_H__

#include "ArrayList.h"

template <typename Type>
class QueueArray : public ArrayList<Type>
{
//variables
public:
	int start=0, end=0;
protected:
private:

//functions
public:
	using ArrayList<Type>::ArrayList;
	Type dequeue();
	void enqueue(Type el);
	short getSize();
	Type peek();
}; //QueueArray

#endif //__QUEUEARRAY_H__
