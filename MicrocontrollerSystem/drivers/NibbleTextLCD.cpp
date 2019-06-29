/*
* NibbleTextLCD.cpp
*
* Created: 4/12/2016 1:05:26 AM
* Author: Animesh Sinha
*/


#include "NibbleTextLCD.h"
#include <stdlib.h>
#include <util/delay.h>

namespace atmicro
{
	// default constructor
	NibbleTextLCD::NibbleTextLCD(PORT port)
	{
		this->port = port;
		initialize();
	}

	// default destructor
	NibbleTextLCD::~NibbleTextLCD()
	{
	}

	void NibbleTextLCD::initialize()
	{
		setDirection(this->port, 0xFF);			/* Make LCD port direction as o/p */
		_delay_ms(20);			/* LCD Power ON delay always >15ms */
	
		command(0x02);		/* send for 4 bit initialization of LCD  */
		command(0x28);      /* 2 line, 5*7 matrix in 4-bit mode */
		command(0x0c);      /* Display on cursor off*/
		command(0x06);      /* Increment cursor (shift cursor to right)*/
		clear();
	}

	void NibbleTextLCD::print(int x, int y, int num)
	{
		char str[16];
		itoa(num, str, 10);
		print(x, y, str);
	}

	void NibbleTextLCD::print(int num)
	{
		char str[16];
		itoa(num, str, 10);
		print(str);
	}

	void NibbleTextLCD::print(int x, int y, double num, short precision)
	{
		print(x, y, (int)num);
		print(".");
		num = (int)((num - ((int)num))*pow(10, precision));
		print((int) num);
	}

	void NibbleTextLCD::print(double num, short precision)
	{
		print((int)num);
		print(".");
		print((int) pow(10, precision)*(num-(int)num));
	}

	void NibbleTextLCD::print(int x, int y, const char* str)
	{
		cursor(x, y);
		print(str);
	}

	void NibbleTextLCD::print(const char* str)
	{
		while(*str > 0)
			character(*str++);
	}

	void NibbleTextLCD::print(unsigned char chr)
	{
		character(chr);
	}
	
	void NibbleTextLCD::print(int x, int y, unsigned char chr)
	{
		cursor(x, y);
		character(chr);
	}

	void NibbleTextLCD::clear()
	{
		command(0x01);
		_delay_ms(2);
	}

	void NibbleTextLCD::cursor(int x, int y)
	{
		if (y == 0) command((x & 0x0F)|0x80);
		else if (y == 1) command((x & 0x0F)|0xC0);
	}

	void NibbleTextLCD::command(unsigned char cmd)
	{
		setStatus(port, (getStatus(port) & 0x0F) | (cmd & 0xF0));
		setStatus(port, pinRS, false);
		action_enable();
		_delay_us(200);
		setStatus(port, (getStatus(port) & 0x0F) | (cmd << 4));
		action_enable();
		_delay_ms(2);
	}

	void NibbleTextLCD::character(unsigned char chr)
	{
		setStatus(port, (getStatus(port) & 0x0F) | (chr & 0xF0));
		setStatus(port, pinRS, true);
		action_enable();
		_delay_us(200);
		setStatus(port, (getStatus(port) & 0x0F) | (chr << 4));
		action_enable();
		_delay_ms(2);
	}

	void NibbleTextLCD::action_enable(void)
	{
		setStatus(this->port, pinEN, true);
		asm volatile ("nop");
		asm volatile ("nop");
		setStatus(this->port, pinEN, false);
	}
}