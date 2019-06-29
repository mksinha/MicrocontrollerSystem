/* 
* SerialTextLCD.h
*
* Created: 6/23/2019 8:51:07 AM
* Author: user
*/


#ifndef __SERIALTEXTLCD_H__
#define __SERIALTEXTLCD_H__

#include "USART.h"

namespace atmicro
{
	class SerialTextLCD
	{
	//variables
	public:
		enum cursor_move { LEFT, RIGHT, DOWN, ENTER };
	protected:
		USART com = USART(9600);
	public:
		SerialTextLCD();
		~SerialTextLCD();
		void initialize();
		void cursor(int x, int y);
		void cursor(bool visible, bool blink);
		void cursor(cursor_move move);
		void clear();
		void backlight(bool on);
		void character(unsigned char chr);
	private:
		SerialTextLCD( const SerialTextLCD &c );
		SerialTextLCD& operator=( const SerialTextLCD &c );

	}; //SerialTextLCD
}
	
#endif //__SERIALTEXTLCD_H__
