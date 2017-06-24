#include "atmicro.h"
#include "config.h"
#include "box/interface.h"

ParallelTextLCD lcd = ParallelTextLCD(IOPORTB, IOPIND4, IOPIND3, IOPIND2);
DigitalOutput backlight = DigitalOutput(IOPIND5);
DigitalOutput buzzer = DigitalOutput(IOPIND6);
DigitalOutput led = DigitalOutput(IOPIND7);
Accelerometer acclm = Accelerometer(ADC0, ADC1, ADC2);
Keypad pad = Keypad(IOPORTC);
State state;
Istream istream;

int main(void)
{
	acclm.start();
	delay(1000);
	backlight.on();
	lcd.clear();
	state.setLockAccelerations(acclm);
	delay(1000);
 	while(1)
 	{
		istream.update(pad);
		interface(istream, lcd, state, acclm);
		#if DEBUG_MODE == true
			lcd.print(0, 1, acclm.x - state.lockAccX);
			lcd.print(4, 1, acclm.y - state.lockAccY);
			lcd.print(8, 1, acclm.z - state.lockAccZ);
			lcd.print(13, 1, state.safe);
		#endif
		if(	   (acclm.x-state.lockAccX>10 || acclm.x-state.lockAccX<-10 ||  
				acclm.y-state.lockAccY>10 || acclm.y-state.lockAccY<-10 ||
				acclm.z-state.lockAccZ>10 || acclm.z-state.lockAccZ<-10)
				&& state.armstate==true && state.armstate > 0) 
		{
			state.safe--;
		}
		if (state.safe < SAFETY_LIMIT && state.armstate == true)
		{
			led.on();
			buzzer.on();
		}
		else
		{
			led.off();
			buzzer.off();
		}
 	}
}

ISR(ADCvector)
{
	acclm.process();
}