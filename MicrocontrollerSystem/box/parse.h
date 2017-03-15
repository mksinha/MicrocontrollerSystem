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
			lcd.print(0, 0, "Safe :)         ");
			lcd.print(0, 1, "                ");
		}
		else
		{
			lcd.print(0, 0, "Disarmed!       ");
			lcd.print(0, 1, "                ");
		}
	}
	// Action A - Arm Device
	else if (input.stream[0] == 'A')
	{
		lcd.clear();
		if (arm(state))
			lcd.print(0, 0, "Armed Device.   ");
		else if (state.armstate == true)
			lcd.print(0, 0, "Already Armed.  ");
		else
			lcd.print(0, 0, "Error in Arming!");

		if(state.travelMode == State::TRAIN)
			lcd.print(2, 1, "Train Mode.     ");
		else if(state.travelMode == State::BUS)
			lcd.print(2, 1, "Bus Mode.       ");
		else if(state.travelMode == State::AIRPLANE)
			lcd.print(2, 1, "Airplane Mode.  ");
		else if(state.travelMode == State::TAXI)
			lcd.print(2, 1, "Taxi Mode.      ");
		else if(state.travelMode == State::WALK)
			lcd.print(2, 1, "Walk Mode.      ");
		else if(state.travelMode == State::STATION)
			lcd.print(2, 1, "Station mode.   ");
		_delay_ms(500);
		if(state.alarmMode == State::ON)
			lcd.print(2, 1, "Alarm on.       ");
		else if(state.alarmMode == State::LOCAL)
			lcd.print(2, 1, "Local Alarm on. ");
		else if(state.alarmMode == State::OFF)
			lcd.print(2, 1, "Alarm on.       ");

		input.clear();
		_delay_ms(2000);
		lcd.clear();
	}
	// Action B - Disarm Device
	else if (input.stream[0] == 'B')
	{
		lcd.print(0, 0, "Pass code: ");
		for (int i = 1; i < input.length; i++)
			lcd.print(i + 10, 0, "*");
		if (input.length >= 5)
		{
			if (disarm(input, state))
				lcd.print(0, 1, "Disarmed device.");
			else if (state.armstate == false)
				lcd.print(0, 1, "Already Disarmed");
			else
				lcd.print(0, 1, "PassCode Invalid");
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
			lcd.print(0, 0, "Old code: ");
			for (int i = 1; i < input.length; i++)
				lcd.print(i + 9, 0, "*");
		}
		else if (input.length < 9)
		{
			lcd.print(0, 0, "Old code: ****");
			lcd.print(0, 1, "New code: ");
			for (int i = 5; i < input.length; i++)
				lcd.print(i + 5, 1, "*");
		}
		else
		{
			lcd.clear();
			if(changecode(input, state))
				lcd.print(0, 0, "Changed PassCode");
			else
				lcd.print(0, 0, "Invalid OldCode.");
			input.clear();
			_delay_ms(2000);
			lcd.clear();
		}
	}
	// Action D - Menu Settings
	else if (input.stream[0] == 'D')
	{
		lcd.print(0, 0, "Menu Choice: ");
		if (input.length == 2)
		{
			lcd.print(14, 0, input.stream[1]);
			if (input.stream[1] == '1')
				lcd.print(2, 1, "- Alarm Mode");
			else if (input.stream[1] == '2')
				lcd.print(2, 1, "- Travel Mode");
			else
			{
				lcd.clear();
				lcd.print(0, 1, "No Such Option.");
				input.clear();
			}
		}
		if (input.length >= 3)
		{
			lcd.print(15, 0, input.stream[2]);
			if(menuop(input, state))
			{
				if(input.stream[1] == '1')
				{
					if(state.alarmMode == State::ON)
						lcd.print(0, 1, "Alarm On.       ");
					if(state.alarmMode == State::LOCAL)
						lcd.print(0, 1, "Local alarm on. ");
					if(state.alarmMode == State::OFF)
						lcd.print(0, 1, "Alarm Off.      ");
				}
				if(input.stream[1] == '2')
				{
					if(state.travelMode == State::TRAIN)
						lcd.print(0, 1, "Train mode on.  ");
					if(state.travelMode == State::BUS)
						lcd.print(0, 1, "Bus mode on.    ");
					if(state.travelMode == State::AIRPLANE)
						lcd.print(0, 1, "Plane mode on. ");
					if(state.travelMode == State::TAXI)
						lcd.print(0, 1, "Taxi mode on.  ");
					if(state.travelMode == State::WALK)
						lcd.print(0, 1, "Walk mode on.   ");
					if(state.travelMode == State::STATION)
						lcd.print(0, 1, "Station mode on.");
				}
			}
			else
				lcd.print(0, 1, "Invalid Choice. ");
			input.clear();
			_delay_ms(2000);
		}
	}
	// All Numeric/Symbol/Invalid Inputs
	else
	{
		lcd.clear();
		lcd.print(0, 0, "Invalid Input");
		_delay_ms(2000);
		input.clear();
		lcd.clear();
	}
}


#endif /* PARSE_H_ */