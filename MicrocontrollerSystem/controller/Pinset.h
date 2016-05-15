/* 
* Pinset.h
*
* Created: 5/15/2016 12:12:49 PM
* Author: Animesh Sinha
*/


#ifndef __PINSET_H__
#define __PINSET_H__

#include "registry.h"

namespace Integral
{
	class Pinset
	{
	//variables
	public:
	protected:
		PIN list[];
		int size;
	private:

	//functions
	public:
		Pinset();
		~Pinset();
		unsigned int getData();
		void putData(unsigned int data);
	protected:
	private:
		Pinset( const Pinset &c );
		Pinset& operator=( const Pinset &c );

	}; //Pinset
}

#endif //__PINSET_H__
