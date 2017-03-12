/* 
* ArrayList.cpp
*
* Created: 3/9/2017 10:02:16 AM
* Author: Animesh Sinha
*/


#include "ArrayList.h"
#include "../drivers/Device.h"
#include <stdlib.h>

template <typename Type>
ArrayList<Type>::ArrayList(short size)
{
	this->mList = (Type*)calloc(size, sizeof(Type));
	this->size = size;
}

template <typename Type>
ArrayList<Type>::~ArrayList()
{
	free(this);
}

template <typename Type>
Type ArrayList<Type>::get(short index)
{
	return *(this->mList + index);
}

template <typename Type>
void ArrayList<Type>::set(Type value, short index)
{
	*(this->mList + index) = value;
}

template <typename Type>
short ArrayList<Type>::navIndex(short curIndex, short change)
{
	curIndex += change;
	if (curIndex < 0)
		curIndex = size - curIndex;
	curIndex %= size;
	return curIndex;
}

template class ArrayList<int>;
template class ArrayList<char*>;
template class ArrayList<double>;