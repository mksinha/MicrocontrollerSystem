/*
 * parse.h
 *
 * Created: 11/24/2016 10:15:52 PM
 *  Author: mksin
 */ 


#ifndef PARSE_H_
#define PARSE_H_

#include "../atmicro.h"
ParallelTextLCD lcd(IOPORTB, IOPIND2, IOPIND7, IOPIND5);

void parse(Istream& input)
{
	if (input.length == 0)
	{
		lcd.string(0, 0, "Awaiting        ");
		lcd.string(0, 1, "   Instructions!");
	}
	else if (input.stream[0] == 'A')
	{
		lcd.clear();
		input.clear();
		lcd.string(0, 0, "Armed Device");
		_delay_ms(2000);
	}
	else if (input.stream[0] == 'B')
	{
		lcd.clear();
		input.clear();
		lcd.string(0, 0, "Code to Disarm: ");
		_delay_ms(2000);
	}
	else if (input.stream[0] == 'C')
	{
		lcd.clear();
		input.clear();
		lcd.string(0, 0, "Old Password: ");
		_delay_ms(2000);
	}
	else if (input.stream[0] == 'D')
	{
		lcd.clear();
		input.clear();
		lcd.string(0, 0, "Menu Choice: ");
		_delay_ms(2000);
	}
	else
	{
		lcd.clear();
		input.clear();
	}
}


#endif /* PARSE_H_ */