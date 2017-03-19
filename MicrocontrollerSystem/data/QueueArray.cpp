/* 
* QueueArray.cpp
*
* Created: 3/9/2017 10:53:02 AM
* Author: Animesh Sinha
*/


#include "QueueArray.h"
#include <stddef.h>

template <typename Type>
Type QueueArray<Type>::dequeue()
{
	if (getSize() == 0) return 0;
	return ArrayList<Type>::get(start++);
}

template <typename Type>
void QueueArray<Type>::enqueue(Type el)
{
	ArrayList<Type>::set(el, end++);
}

template <typename Type>
short QueueArray<Type>::getSize()
{
	if(start <= end)
		return end - start;
	else 
		return this->size - (end - start);
}

template <typename Type>
Type QueueArray<Type>::peek(int depth)
{
	return ArrayList<Type>::get(ArrayList<Type>::navIndex(start, depth));
}

template class QueueArray<int>;
template class QueueArray<char*>;
template class QueueArray<double>;