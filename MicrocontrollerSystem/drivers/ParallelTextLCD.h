/* 
* ParallelTextLCD.h
*
* Created: 4/12/2016 1:05:34 AM
* Author: Animesh Sinha
*/

#include "Outputs.h"

#ifndef __TEXTLCD_H__
#define __TEXTLCD_H__


class ParallelTextLCD : public Outputs
{
//variables
public:
protected:
	int dataPort, controlPort;
	int pinEN, pinRW, pinRS;
	int rowPositions[4] = {0, 64, 20, 84};
private:

//functions
public:
	ParallelTextLCD(int portData, int portControl, int pinRS, int pinRW, int pinEN);
	~ParallelTextLCD();
	void initialize();
	void integer(int x, int y, int num, int digits);
	void string(int x, int y, char* str);
	void string(char* str);
	void position(int x, int y);
protected:
	void command(unsigned char cmd);
	void character(unsigned char chr);
	void wait_busy(void);
	void action_enable(void);
private:
	ParallelTextLCD( const ParallelTextLCD &c );
	ParallelTextLCD& operator=( const ParallelTextLCD &c );

}; //TextLCD

#endif //__TEXTLCD_H__
