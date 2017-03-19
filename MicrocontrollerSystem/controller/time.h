/*
 * time.h
 *
 * Created: 3/9/2017 5:42:32 PM
 *  Author: Animesh Sinha
 */ 


#ifndef TIME_H_
#define TIME_H_

#include <util/delay.h>

#define delay(time) { _delay_ms((int)time); _delay_us((int)((time-(int)time)*1000)); }

#endif /* TIME_H_ */