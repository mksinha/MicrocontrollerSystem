/* 
* ParallelTextLCD.cpp
*
* Created: 4/12/2016 1:05:26 AM
* Author: Animesh Sinha
*/


#include "ParallelTextLCD.h"
#include <stdlib.h>
#include <util/delay.h>


namespace atmicro
{
	// default constructor
	ParallelTextLCD::ParallelTextLCD(PORT portData, PIN pinRS, PIN pinRW, PIN pinEN)
	{
		this->dataPort = portData;
		this->pinRS = pinRS;
		this->pinRW = pinRW;
		this->pinEN = pinEN;
		initialize();
	}

	// default destructor
	ParallelTextLCD::~ParallelTextLCD()
	{
		setDirection(dataPort, DDR_INPUT);
		setDirection(pinRS, DDR_INPUT);
		setDirection(pinRW, DDR_INPUT);
		setDirection(pinEN, DDR_INPUT);
		setStatus(dataPort, LOW);
		setStatus(pinRS, LOW);
		setStatus(pinRW, LOW);
		setStatus(pinEN, LOW);
	}

	void ParallelTextLCD::initialize()
	{
		setDirection(pinRS, DDR_OUTPUT);
		setDirection(pinRW, DDR_OUTPUT);
		setDirection(pinEN, DDR_OUTPUT);
		_delay_ms(15);
		command(0x01); // Clear Screen
		_delay_ms(2);
		command(0x38); // Set up LCD 8-bit mode
		_delay_us(50);
		command(0b00001100); // Bit 3: Use function |2: Show Display |1: Show Cursor |0: Blinking Cursor
		_delay_us(50);
	}

	void ParallelTextLCD::print(int x, int y, int num)
	{
		char str[16];
		itoa(num, str, 10);
		print(x, y, str);
	}

	void ParallelTextLCD::print(int num)
	{
		char str[16];
		itoa(num, str, 10);
		print(str);
	}

	void ParallelTextLCD::print(int x, int y, double num, short precision)
	{
		print(x, y, (int)num);
		print(".");
		num = (int)((num - ((int)num))*pow(10, precision));
		print((int) num);
	}

	void ParallelTextLCD::print(double num, short precision)
	{
		print((int)num);
		print(".");
		print((int) pow(10, precision)*(num-(int)num));
	}

	void ParallelTextLCD::print(int x, int y, const char* str)
	{
		cursor(x, y);
		print(str);
	}

	void ParallelTextLCD::print(const char* str)
	{
		while(*str > 0)
			character(*str++);
	}

	void ParallelTextLCD::print(int x, int y, unsigned char chr)
	{
		cursor(x, y);
		character(chr);
	}

	void ParallelTextLCD::print(unsigned char chr)
	{
		character(chr);
	}

	void ParallelTextLCD::clear()
	{
		command(0x01);
		_delay_ms(2);
	}

	void ParallelTextLCD::cursor(int x, int y)
	{
		command(0x80 + this->rowPositions[y] + x);
	}

	void ParallelTextLCD::cursor(bool visible, bool blink)
	{
		if (!visible)
		command(0b00001100);
		else if (visible && !blink)
		command(0b00001110);
		else if (visible && blink)
		command(0b00001111);
		_delay_us(50);
	}

	void ParallelTextLCD::command(unsigned char cmd)
	{
		wait_busy();
		setStatus(dataPort, cmd);
		setStatus(pinRW, LOW);
		setStatus(pinRS, LOW);
		action_enable();
		setStatus(dataPort, 0x00);
	}

	void ParallelTextLCD::character(unsigned char chr)
	{
		wait_busy();
		setStatus(dataPort, chr);
		setStatus(pinRW, LOW);
		setStatus(pinRS, HIGH);
		action_enable();
		setStatus(dataPort, 0x00);
	}

	void ParallelTextLCD::wait_busy(void)
	{
		setDirection(dataPort, 0x00);
		setStatus(pinRW, HIGH);
		setStatus(pinRS, LOW);
		while (getStatus(dataPort, IOPIN7) != HIGH)
			action_enable();
		setDirection(dataPort, 0xFF);
	}

	void ParallelTextLCD::action_enable(void)
	{
		setStatus(pinEN, HIGH);
		asm volatile ("nop");
		asm volatile ("nop");
		setStatus(pinEN, LOW);
	}
}