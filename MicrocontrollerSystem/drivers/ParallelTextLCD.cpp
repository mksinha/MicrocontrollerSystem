/* 
* ParallelTextLCD.cpp
*
* Created: 4/12/2016 1:05:26 AM
* Author: Animesh Sinha
*/


#include "ParallelTextLCD.h"
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>

// default constructor
ParallelTextLCD::ParallelTextLCD(int portData, int portControl, int pinRS, int pinRW, int pinEN)
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
}

void ParallelTextLCD::initialize()
{
	Output::pinDirection(controlPort, pinRS, true);
	Output::pinDirection(controlPort, pinRW, true);
	Output::pinDirection(controlPort, pinEN, true);
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

void ParallelTextLCD::string(int x, int y, char* str)
{
	position(x, y);
	string(str);
}

void ParallelTextLCD::string(char* str)
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
	Output::portStatus(dataPort, cmd);
	Output::pinStatus(controlPort, pinRW, false);
	Output::pinStatus(controlPort, pinRS, false);
	action_enable();
	Output::portStatus(dataPort, 0x00);
}

void ParallelTextLCD::character(unsigned char chr)
{
	wait_busy();
	Output::portStatus(dataPort, chr);
	Output::pinStatus(controlPort, pinRW, false);
	Output::pinStatus(controlPort, pinRS, true);
	action_enable();
	Output::portStatus(dataPort, 0x00);
}

void ParallelTextLCD::wait_busy(void)
{
	Output::portDirection(dataPort, 0x00);
	Output::pinStatus(controlPort, pinRW, true);
	Output::pinStatus(controlPort, pinRS, false);
	while (Output::pinStatus(dataPort, IOPIN7) == true)
		action_enable();
	Output::portDirection(dataPort, 0xFF);
}

void ParallelTextLCD::action_enable(void)
{
	Output::pinStatus(controlPort, pinEN, true);
	asm volatile ("nop");
	asm volatile ("nop");
	Output::pinStatus(controlPort, pinEN, false);
}