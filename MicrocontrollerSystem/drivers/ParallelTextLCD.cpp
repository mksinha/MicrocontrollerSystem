/* 
* ParallelTextLCD.cpp
*
* Created: 4/12/2016 1:05:26 AM
* Author: Animesh Sinha
*/


#include "ParallelTextLCD.h"
#include <stdlib.h>
#include <util/delay.h>


namespace Integral
{
	// default constructor
	ParallelTextLCD::ParallelTextLCD(PORT portData, PORT portControl, POSITION pinRS, POSITION pinRW, POSITION pinEN)
	{
		this->dataPort = portData;
		this->controlPort = portControl;
		this->pinRS = pinRS;
		this->pinRW = pinRW;
		this->pinEN = pinEN;
		initialize();
	}

	// default destructor
	ParallelTextLCD::~ParallelTextLCD()
	{
		setDirection(dataPort, LOW);
		setDirection(controlPort, pinRS, LOW);
		setDirection(controlPort, pinRW, LOW);
		setDirection(controlPort, pinEN, LOW);
		setStatus(dataPort, LOW);
		setStatus(controlPort, pinRS, LOW);
		setStatus(controlPort, pinRW, LOW);
		setStatus(controlPort, pinEN, LOW);
	}

	void ParallelTextLCD::initialize()
	{
		setDirection(controlPort, pinRS, HIGH);
		setDirection(controlPort, pinRW, HIGH);
		setDirection(controlPort, pinEN, HIGH);
		_delay_ms(15);
		command(0x01); // Clear Screen
		_delay_ms(2);
		command(0x38); // Set up LCD 8-bit mode
		_delay_us(50);
		command(0b00001100); // Bit 3: Use function |2: Show Display |1: Show Cursor |0: Blinking Cursor
		_delay_us(50);
	}

	void ParallelTextLCD::integer(int x, int y, int num, int digits)
	{
		char str[digits];
		itoa(num, str, 10);
		for (int i = 0; i < digits; i++) string(" ");
		string(x, y, str);
	}

	void ParallelTextLCD::integer(int num, int digits)
	{
		char str[digits];
		itoa(num, str, 10);
		for (int i = 0; i < digits; i++) string(" ");
		string(str);
	}

	void ParallelTextLCD::string(int x, int y, const char* str)
	{
		position(x, y);
		string(str);
	}

	void ParallelTextLCD::string(const char* str)
	{
		while(*str > 0)
		character(*str++);
	}

	void ParallelTextLCD::position(int x, int y)
	{
		command(0x80 + this->rowPositions[y] + x);
	}

	void ParallelTextLCD::clear()
	{
		command(0x01);
		_delay_ms(2);
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
		setStatus(controlPort, pinRW, LOW);
		setStatus(controlPort, pinRS, LOW);
		action_enable();
		setStatus(dataPort, 0x00);
	}

	void ParallelTextLCD::character(unsigned char chr)
	{
		wait_busy();
		setStatus(dataPort, chr);
		setStatus(controlPort, pinRW, LOW);
		setStatus(controlPort, pinRS, HIGH);
		action_enable();
		setStatus(dataPort, 0x00);
	}

	void ParallelTextLCD::wait_busy(void)
	{
		setDirection(dataPort, 0x00);
		setStatus(controlPort, pinRW, HIGH);
		setStatus(controlPort, pinRS, LOW);
		while (getStatus(dataPort, IOPIN7) != HIGH)
		action_enable();
		setDirection(dataPort, 0xFF);
	}

	void ParallelTextLCD::action_enable(void)
	{
		setStatus(controlPort, pinEN, HIGH);
		asm volatile ("nop");
		asm volatile ("nop");
		setStatus(controlPort, pinEN, LOW);
	}
}