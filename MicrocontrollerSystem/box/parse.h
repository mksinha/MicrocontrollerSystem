/*
 * parse.h
 *
 * Created: 11/24/2016 10:15:52 PM
 *  Author: Animesh Sinha
 */ 


#ifndef PARSE_H_
#define PARSE_H_

#include "../atmicro.h"
#include "actions.h"

void parse(Istream& input, ParallelTextLCD& lcd, State& state)
{
	if (input.length == 0)
	{
		if(state.armstate == true)
		{
			lcd.string(0, 0, "Safe :)         ");
			lcd.string(0, 1, "                ");
		}
		else
		{
			lcd.string(0, 0, "Disarmed!       ");
			lcd.string(0, 1, "                ");
		}
	}
	// Action A - Arm Device
	else if (input.stream[0] == 'A')
	{
		lcd.clear();
		if (arm(state))
			lcd.string(0, 0, "Armed Device    ");
		else
			lcd.string(0, 0, "Error in Arming!");
		input.clear();
		_delay_ms(2000);
		lcd.clear();
	}
	// Action B - Disarm Device
	else if (input.stream[0] == 'B')
	{
		lcd.string(0, 0, "Pass code: ");
		for (int i = 1; i < input.length; i++)
			lcd.string(i + 10, 0, "*");
		if (input.length >= 5)
		{
			if(disarm(input, state))
				lcd.string(0, 1, "Disarmed device ");
			else
				lcd.string(0, 1, "Failed to disarm");
			input.clear();
			_delay_ms(2000);
			lcd.clear();
		}
	}
	// Action C - Password Change
	else if (input.stream[0] == 'C')
	{
		if (input.length < 5)
		{
			lcd.string(0, 0, "Old code: ");
			for (int i = 1; i < input.length; i++)
				lcd.string(i + 9, 0, "*");
		}
		else if (input.length < 9)
		{
			lcd.string(0, 0, "Old code: ****");
			lcd.string(0, 1, "New code: ");
			for (int i = 5; i < input.length; i++)
				lcd.string(i + 5, 1, "*");
		}
		else
		{
			lcd.clear();
			if(changecode(input, state))
				lcd.string(0, 0, "Changed PassCode");
			else
				lcd.string(0, 0, "Failed to Change");
			input.clear();
			_delay_ms(2000);
			lcd.clear();
		}
	}
	// Action D - Menu Settings
	else if (input.stream[0] == 'D')
	{
		lcd.string(0, 0, "Menu Choice: ");
		if (input.length >= 2)
		{
			menuop(input, state);
			lcd.string(14, 0, &input.stream[1]);
			lcd.string(0, 1, "Unavailable Now!");
			input.clear();
			_delay_ms(2000);
		}
	}
	// All Numeric/Symbol/Invalid Inputs
	else
	{
		lcd.clear();
		lcd.string(0, 0, "Invalid Input");
		_delay_ms(2000);
		input.clear();
		lcd.clear();
	}
}


#endif /* PARSE_H_ */