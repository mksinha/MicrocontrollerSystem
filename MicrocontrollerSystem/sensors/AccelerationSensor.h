/* 
* AccelerationSensor.h
*
* Created: 3/9/2017 12:07:46 PM
* Author: Anime
*/


#ifndef __ACCELERATIONSENSOR_H__
#define __ACCELERATIONSENSOR_H__

#include "../controller/registry.h"
#include "../drivers/AnalogInput.h"
#include "../data/QueueArray.h"

using namespace atmicro;


class AccelerationSensor
{
//variables
public:
	static double x, y, z;
protected:
	QueueArray<int> arrx;
	QueueArray<int> arry;
	QueueArray<int> arrz;
	AnalogInput* adcx;
	AnalogInput* adcy;
	AnalogInput* adcz;

//functions
public:
	AccelerationSensor();
	~AccelerationSensor();
	static void setx(AnalogInput e);
	static void sety(AnalogInput e);
	static void setz(AnalogInput e);
}; //AccelerationSensor

#endif //__ACCELERATIONSENSOR_H__
