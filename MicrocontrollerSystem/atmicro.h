/*
 * atmicro.h
 *
 * Created: 11/23/2016 6:40:21 PM
 *  Author: Animesh Sinha
 */ 


#ifndef ATMICRO_H_
#define ATMICRO_H_

#define F_CPU 1000000L

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <math.h>
#include "data/ArrayList.h"
#include "data/QueueArray.h"
#include "controller/registry.h"
#include "controller/time.h"
#include "controller/Pinset.h"
#include "controller/Istream.h"
#include "controller/ADCcontroller.h"
#include "drivers/AnalogInput.h"
#include "drivers/Accelerometer.h"
#include "drivers/DigitalOutput.h"
#include "drivers/PushButtonSwitch.h"
#include "drivers/Keypad.h"
#include "drivers/ParallelTextLCD.h"
#include "drivers/USART.h"
#include "drivers/EEPROM.h"
#include "drivers/NibbleTextLCD.h"

using namespace atmicro;

#define ADCvector _VECTOR(16)

#endif /* ATMICRO_H_ */
