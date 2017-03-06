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
#define __OPTION_VAULT true

#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include "drivers/AnalogInput.h"
#include "drivers/DigitalOutput.h"
#include "drivers/Keypad.h"
#include "drivers/ParallelTextLCD.h"
#include "drivers/PushButtonSwitch.h"
#include "drivers/USART.h"
#include "controller/Istream.h"
#include "controller/adc.h"
#include "controller/vault.h"

using namespace atmicro;

typedef char* string;

#endif /* ATMICRO_H_ */