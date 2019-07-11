/* 
* SPI.cpp
*
* Created: 7/2/2019 4:58:26 PM
* Author: user
*/


#include "SPI.h"

namespace atmicro
{
	// default constructor
	SPI::SPI(bool master)
	{
		this->master = master;
		initialize();
	} //SPI

	// default destructor
	SPI::~SPI()
	{
	} //~SPI

	void SPI::initialize()
	{
		if (this->master) 
		{
			setDirection(MOSI, DDR_OUTPUT);	
			setDirection(MISO, DDR_INPUT);
			setDirection(SCK, DDR_OUTPUT);
			setDirection(SS, DDR_OUTPUT);
			setStatus(SS, HIGH);
			SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);	/* Enable SPI in master mode with F_osc/16 */
			SPSR &= ~(1<<SPI2X);			/* Disable speed doubler */
		}
		else
		{	
			setDirection(MOSI, DDR_INPUT);
			setDirection(MISO, DDR_OUTPUT);
			setDirection(SCK, DDR_INPUT);
			setDirection(SS, DDR_INPUT);
			SPCR = (1<<SPE);			/* Enable SPI in slave mode */
		}
	}

	void SPI::transmit(char data)
	{
		SPDR = data;				/* Write data to SPI data register */
		while(!(SPSR & (1<<SPIF)));	/* Wait till transmission complete */
		char flush_buffer = SPDR;		/* Flush received data */
		/* Note: SPIF flag is cleared by first reading SPSR (with SPIF set) and 
		then accessing SPDR hence flush buffer used here to access SPDR after SPSR read */
	}

	char SPI::recieve()
	{
		if (master) SPDR = 0xFF;
		while(!(SPSR & (1<<SPIF)));	/* Wait till reception complete */
		return(SPDR);			/* Return received data */
	}

	void SPI::slave_select(bool enable)
	{
		if (enable) setStatus(SS, LOW);
		else setStatus(SS, HIGH);
	}
}