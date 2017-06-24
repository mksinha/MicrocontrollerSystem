/* 
* ParallelTextLCD.h
*
* Created: 4/12/2016 1:05:34 AM
* Author: Animesh Sinha
*/


#ifndef __TEXTLCD_H__
#define __TEXTLCD_H__

#include "Output.h"


namespace atmicro
{
	struct pos {
		int x, y;
		pos(int x, int y) {this->x = x; this->y = y;}
	};
	struct endl{};
	class ParallelTextLCD : public Output
	{
	protected:
		PORT dataPort;
		PIN pinEN, pinRW, pinRS;
		int rowPositions[4] = {0, 64, 20, 84};

	public:
		ParallelTextLCD(PORT portData, PIN pinRS, PIN pinRW, PIN pinEN);
		~ParallelTextLCD();
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
		void cursor(bool visible, bool blink);
		void clear();
	protected:
		void character(unsigned char chr);
		void command(unsigned char cmd);
		void wait_busy(void);
		void action_enable(void);
	}; //TextLCD
}

#endif //__TEXTLCD_H__