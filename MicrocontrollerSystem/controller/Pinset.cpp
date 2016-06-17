/* 
* Pinset.cpp
*
* Created: 5/15/2016 12:12:48 PM
* Author: Animesh Sinha
*/


#include "Pinset.h"
#include "../drivers/Device.h"

namespace Integral
{
	// default constructor
	Pinset::Pinset(int size, PIN set[])
	{
		this->size = size;
		for(int i = 0; i < size; i++)
			this->pins[i] = set[(size-1)-i];
	}

	// default destructor
	Pinset::~Pinset()
	{
	}

	unsigned int Pinset::getData()
	{
		uint32_t data = 0;
		for (int i = 0; i < size; i++)
		{
			Device::setDirection(pins[i], LOW);
			data = data * 2 + Device::getStatus(pins[i]);
		}
		return data;
	}

	void Pinset::putData(unsigned int data)
	{
		for (int i = 0; i < 4; i++, data /= 2)
		{
			Device::setDirection(pins[i], HIGH);
			if (data % 2 == HIGH)
				Device::setStatus(pins[i], HIGH);
			else
				Device::setStatus(pins[i], LOW);
		}
	}
}