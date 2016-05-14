/*
 * registry.h
 *
 * Created: 4/15/2016 12:57:09 AM
 *  Author: Animesh Sinha
 */ 


#ifndef REGISTRY_H_
#define REGISTRY_H_

// Pin Configuration setup

namespace Integral
{
	#define HIGH true
	#define LOW false

	enum PORT {
		IOPORTA, IOPORTB, IOPORTC, IOPORTD
	};
	enum POSITION {
		IOPIN0 = 0, IOPIN1 = 1, IOPIN2 = 2, IOPIN3 = 3,
		IOPIN4 = 4, IOPIN5 = 5, IOPIN6 = 6, IOPIN7 = 7
	};

	enum ADCchannel {
		ADC0 = 0, ADC1 = 1, ADC2 = 2, ADC3 = 3,
		ADC4 = 4, ADC5 = 5, ADC6 = 6, ADC7 = 7
	};
}

#endif /* REGISTRY_H_ */