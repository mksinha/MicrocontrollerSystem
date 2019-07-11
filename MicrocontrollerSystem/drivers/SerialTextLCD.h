/* 
* SerialTextLCD.h
*
* Created: 6/23/2019 8:51:07 AM
* Author: user
*/


#ifndef __SERIALTEXTLCD_H__
#define __SERIALTEXTLCD_H__

#include "USART.h"
#include "Output.h"

namespace atmicro
{
	class SerialTextLCD : public Output
	{
	//variables
	public:
		enum cursor_move { LEFT, RIGHT, DOWN, ENTER };
	protected:
		USART com = USART(12);
	public:
		SerialTextLCD();
		~SerialTextLCD();
		void initialize();
		void cursor(int x, int y);
		void cursor(bool visible, bool blink);
		void cursor(cursor_move move);
		void print(int x, int y, int num);
		void print(int num);
		void print(int x, int y, double num, short precision=2);
		void print(double num, short precision=2);
		void print(int x, int y, const char* str);
		void print(const char* str);
		void print(int x, int y, unsigned char chr);
		void print(unsigned char chr);
		void clear();
		void backlight(bool on);
		void character(unsigned char chr);
	private:
		SerialTextLCD( const SerialTextLCD &c );
		SerialTextLCD& operator=( const SerialTextLCD &c );

	}; //SerialTextLCD
}
	
#endif //__SERIALTEXTLCD_H__
