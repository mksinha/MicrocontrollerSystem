/* 
* ParallelGraphicLCD.cpp
*
* Created: 7/6/2018 4:11:06 PM
* Author: Animesh Sinha
*/


#include "ParallelGraphicLCD.h"
#include <util/delay.h>


namespace atmicro {
	ParallelGraphicLCD::ParallelGraphicLCD(PORT portData, PIN pinRS, PIN pinRW, PIN pinEN) {
		this->dataPort = portData;
		this->pinRS = pinRS;
		this->pinRW = pinRW;
		this->pinEN = pinEN;
		initialize();
	}

	ParallelGraphicLCD::~ParallelGraphicLCD() {
		setDirection(dataPort, DDR_INPUT);
		setDirection(pinRS, DDR_INPUT);
		setDirection(pinRW, DDR_INPUT);
		setDirection(pinEN, DDR_INPUT);
		setStatus(dataPort, LOW);
		setStatus(pinRS, LOW);
		setStatus(pinRW, LOW);
		setStatus(pinEN, LOW);
	}
	
	void ParallelGraphicLCD::action_enable(void) {
		setStatus(pinEN, HIGH);
		asm volatile ("nop");
		asm volatile ("nop");
		setStatus(pinEN, LOW);
	}
	
	void ParallelGraphicLCD::initialize() {
		setDirection(dataPort, DDR_OUTPUT);
		setDirection(pinRS, DDR_OUTPUT);
		setDirection(pinRW, DDR_OUTPUT);
		setDirection(pinEN, DDR_OUTPUT);
		command(0b00110110); // Bit 5,4: 8 Bit Mode | 2: Extended Instruction Set | 1: Graphics
		_delay_ms(100);
		command(0b00001111); // Bit 3: Use function | 2: Show Display | 1: Show Cursor | 0: Blinking Cursor
		_delay_ms(100);
		clear();
	}
	
	void ParallelGraphicLCD::clear() {
		command(0x01);
		_delay_ms(2);
	}

	void ParallelGraphicLCD::data(unsigned char chr) {
		setStatus(pinRS, HIGH);
		setStatus(dataPort, chr);
		action_enable();
	}
	
	void ParallelGraphicLCD::command(unsigned char cmd) {
		setStatus(pinRS, LOW);
		setStatus(dataPort, cmd);
		action_enable();
	}
}