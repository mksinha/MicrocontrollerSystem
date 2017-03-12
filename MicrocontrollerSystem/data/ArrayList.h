/* 
* ArrayList.h
*
* Created: 3/9/2017 10:02:16 AM
* Author: Animesh Sinha
*/


#ifndef __ARRAYLIST_H__
#define __ARRAYLIST_H__

#include "List.h"

template <typename Type>
class ArrayList : public List<Type>
{
//variables
public:
	short size;
protected:
	Type* mList;

//functions
public:
	ArrayList(short size=10);
	~ArrayList();
	Type get(short index);
	void set(Type value, short index);
protected:
	short navIndex(short curIndex, short change = 0);
};

#endif