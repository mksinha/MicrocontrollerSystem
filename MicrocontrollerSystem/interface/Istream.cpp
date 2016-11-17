/* 
* Istream.cpp
*
* Created: 11/17/2016 12:35:04 PM
* Author: Animesh Sinha
*/


#include "Istream.h"
#include <util/delay.h>
#include <string.h>

namespace Integral
{
	// default constructor
	Istream::Istream()
	{
		for(int i = 0; i < BUFFER_SIZE; i++)
			stream[i] = ' ';
		disabledKey = 100;
	} //Istream

	// default destructor
	Istream::~Istream()
	{
	} //~Istream
	
	void Istream::update(Keypad& pad)
	{
		KeypadMatrix data = pad.isPressed();
		if (data.get(disabledKey/4, disabledKey%4) == false)
			disabledKey = 100;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (data.get(i, j) && disabledKey != i*4 + j)
				{
					append(keymap[i][j]);
					disabledKey = i*4 + j;
				}
	}
	
	void Istream::append(char chr)
	{
		if(streamPtrE >= BUFFER_SIZE) streamPtrE = 0;
		stream[streamPtrE] = chr;
		streamPtrE++;
	}

	char* Istream::getStream()
	{
		stream[streamPtrE] = '\0';
		return stream;
	}
}