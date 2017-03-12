/* 
* AccelerationSensor.cpp
*
* Created: 3/9/2017 12:07:46 PM
* Author: Animesh Sinha
*/


#include "AccelerationSensor.h"
#include <stdlib.h>

AccelerationSensor::AccelerationSensor()
{
	AnalogInput tempx(ADC0, setx);
	AnalogInput tempy(ADC1, sety);
	AnalogInput tempz(ADC2, setz);
	adcx = &tempx;
	adcy = &tempy;
	adcz = &tempz;
}

AccelerationSensor::~AccelerationSensor()
{
}

void AccelerationSensor::setx(AnalogInput e)
{
	x = e.value;
}

void AccelerationSensor::sety(AnalogInput e)
{
	y = e.value;
}

void AccelerationSensor::setz(AnalogInput e)
{
	z = e.value;
}