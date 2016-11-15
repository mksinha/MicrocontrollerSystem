/* 
* Keypad.h
*
* Created: 11/15/2016 4:16:48 PM
* Author: Manish Sinha
*/


#ifndef __KEYPAD_H__
#define __KEYPAD_H__

#include "Input.h"

namespace Integral
{
	class KeypadMatrix
	{
	public:
		bool data[4][4];
		bool get(int x, int y)
		{
			return data[x][y];
		}
		void set(int x, int y, bool val)
		{
			data[x][y] = val;
		}
	}; //KeypadMatrix

	class Keypad : public Input
	{
	//variables
	public:
		PORT port;
		KeypadMatrix status;
	protected:
	private:

	//functions
	public:
		Keypad(PORT port);
		~Keypad();
		void initialize();
		KeypadMatrix isPressed(); //debounced status
		KeypadMatrix undebouncedStatus(); //state without debouncing
	protected:
	private:
		bool switchPressed(PIN pin);
	}; //Keypad
}

#endif //__KEYPAD_H__
