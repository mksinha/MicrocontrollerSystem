#include "atmicro.h"
Accelerometer acc = Accelerometer(ADC2, ADC1, ADC0);
USART com = USART(12);

int main(void)
{
	DigitalOutput led(IOPINB0);
	acc.start();
	delay(1000);
	for (long long i = 0; i < 100; i++)
	{
		com.transmit(0b00001111);
		int aX = acc.x, aY = acc.y, aZ = acc.z;
		com.transmit(0b01000000 | (aX & 0b00011111));
		com.transmit(0b01100000 | (aX >> 5));		 
		com.transmit(0b10000000 | (aY & 0b00011111));
		com.transmit(0b10100000 | (aY >> 5));		 
		com.transmit(0b11000000 | (aZ & 0b00011111));
		com.transmit(0b11100000 | (aZ >> 5));		 
	}
	for (int i = 0; i < 10; i++) com.transmit(0b00111111); delay(5);
	acc.stop(); led.on();
	while(1);
}

ISR(ADCvector) { acc.process(); }
