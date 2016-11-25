/* 
* State.h
*
* Created: 11/25/2016 9:09:06 AM
* Author: mksin
*/


#ifndef __STATE_H__
#define __STATE_H__


class State
{
//variables
public:
protected:
private:
	char* passcode;
	

//functions
public:
	State();
	~State();
protected:
private:
	State( const State &c );
	State& operator=( const State &c );

}; //State

#endif //__STATE_H__
