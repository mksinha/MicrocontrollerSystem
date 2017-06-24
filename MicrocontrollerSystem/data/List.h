/* 
* List.h
*
* Created: 3/9/2017 5:45:23 PM
* Author: Animesh Sinha
*/


#ifndef __LIST_H__
#define __LIST_H__


template <typename Type>
class List
{
//functions
public:
	virtual Type get(short index) = 0;
	virtual void set(Type el, short index) = 0;

}; //List

#endif //__LIST_H__
