/*
* NibbleTextLCD.h
*
* Created: 4/12/2016 1:05:34 AM
* Author: Animesh Sinha
*/


#ifndef __NIBBLETEXTLCD_H__
#define __NIBBLETEXTLCD_H__

#include "Output.h"


namespace atmicro
{
	class NibbleTextLCD : public Output
	{
	private:
		const POSITION pinEN = IOPIN1, pinRS = IOPIN0;
	protected:
		PORT port;

	public:
		NibbleTextLCD(PORT port);
		~NibbleTextLCD();
		void initialize();
		void print(int x, int y, int num);
		void print(int num);
		void print(int x, int y, double num, short precision=2);
		void print(double num, short precision=2);
		void print(int x, int y, const char* str);
		void print(const char* str);
		void print(int x, int y, unsigned char chr);
		void print(unsigned char chr);
		void cursor(int x, int y);
		void clear();
	protected:
		void character(unsigned char chr);
		void command(unsigned char cmd);
		void action_enable(void);
	}; //NibbleTextLCD
}

#endif //__NIBBLETEXTLCD_H__