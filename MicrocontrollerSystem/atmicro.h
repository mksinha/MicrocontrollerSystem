/*
 * atmicro.h
 *
 * Created: 11/23/2016 6:40:21 PM
 *  Author: Animesh Sinha
 */ 


#ifndef ATMICRO_H_
#define ATMICRO_H_

#define F_CPU 1000000L

#define __OPTION_ADMUX true

#include "controller/registry.h"
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include "data/ArrayList.h"
#include "data/QueueArray.h"
#include "controller/Pinset.h"
#include "controller/Istream.h"
// #include "controller/adc.h"
#include "drivers/AnalogInput.h"
#include "drivers/DigitalOutput.h"
#include "drivers/PushButtonSwitch.h"
#include "drivers/Keypad.h"
#include "drivers/ParallelTextLCD.h"
#include "drivers/USART.h"
#include "drivers/EEPROM.h"
#include <util/delay.h>
#include <math.h>

using namespace atmicro;

#endif /* ATMICRO_H_ */
