/* 
* SerialTextLCD.cpp
*
* Created: 6/23/2019 8:51:06 AM
* Author: Animesh Sinha
*/


#include "SerialTextLCD.h"
#include <util/delay.h>
#include <stdlib.h>
#include <math.h>

namespace atmicro 
{
	SerialTextLCD::SerialTextLCD()
	{
		com.transmit(0x0C);
		_delay_ms(10);
		com.transmit(0x80);
		_delay_ms(10);
	}

	SerialTextLCD::~SerialTextLCD()
	{
	}

	void SerialTextLCD::cursor(int x, int y)
	{
		if (y == 0) 
			com.transmit(0x80 + x);
		if (y == 1) 
			com.transmit(0x94 + x);
	}

	void SerialTextLCD::character(unsigned char chr)
	{
		if (chr >= 32 && chr <= 127 && chr != 92 && chr != 126) // If Supported 
		{
			com.transmit(chr); // Print character as ASCII value
			_delay_ms(10);
		}
		else // If we need to define a custom character
		{
			com.transmit(0xFA); // Define custom character 3
			_delay_ms(10);
			com.transmit(chr); // as chr in ASCII
			_delay_ms(10);
			com.transmit(0x02); // Print custom character 3
			_delay_ms(10);
		}
	}

	void SerialTextLCD::cursor(bool visible, bool blink)
	{
		if (!visible && !blink)
			com.transmit(0x16);
		else if (!visible && blink)
			com.transmit(0x17);
		else if (visible && !blink)
			com.transmit(0x18);
		else if (visible && blink)
			com.transmit(0x19);
	}
	
	void SerialTextLCD::cursor(cursor_move move)
	{
		if (move == LEFT)
			com.transmit(0x08);
		else if (move == RIGHT)
			com.transmit(0x09);
		else if (move == DOWN)
			com.transmit(0x0A);
		else if (move == ENTER)
			com.transmit(0x0D);
	}

	void SerialTextLCD::print(int x, int y, int num)
	{
		char str[16];
		itoa(num, str, 10);
		print(x, y, str);
	}

	void SerialTextLCD::print(int num)
	{
		char str[16];
		itoa(num, str, 10);
		print(str);
	}

	void SerialTextLCD::print(int x, int y, double num, short precision)
	{
		print(x, y, (int)num);
		print(".");
		num = (int)((num - ((int)num))*pow(10, precision));
		print((int) num);
	}

	void SerialTextLCD::print(double num, short precision)
	{
		print((int)num);
		print(".");
		print((int) pow(10, precision)*(num-(int)num));
	}

	void SerialTextLCD::print(int x, int y, const char* str)
	{
		cursor(x, y);
		print(str);
	}

	void SerialTextLCD::print(const char* str)
	{
		while(*str > 0)
			character(*str++);
	}

	void SerialTextLCD::print(int x, int y, unsigned char chr)
	{
		cursor(x, y);
		character(chr);
	}

	void SerialTextLCD::print(unsigned char chr)
	{
		character(chr);
	}
	
	void SerialTextLCD::backlight(bool on = true)
	{
		if (on)
			com.transmit(0x11);
		else
			com.transmit(0x12);
		_delay_ms(10);
	}
	
	void SerialTextLCD::clear()
	{
		com.transmit(0x0C);
		_delay_ms(10);
	}
}