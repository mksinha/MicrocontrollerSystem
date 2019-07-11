/* 
* SPI.h
*
* Created: 7/2/2019 4:58:26 PM
* Author: user
*/


#ifndef __SPI_H__
#define __SPI_H__

#include "Communication.h"

namespace atmicro
{
	class SPI : public Communication
	{
	//variables
	public:
	protected:
	private:
		const PIN MOSI = IOPINB5, MISO = IOPINB6, SCK = IOPINB7, SS = IOPINB4;
		bool master;
	//functions
	public:
		SPI(bool master);
		~SPI();
		void initialize();
		void transmit(char data);
		char recieve();
		void slave_select(bool enable = true);
	protected:
	private:
		SPI( const SPI &c );
		SPI& operator=( const SPI &c );
	};
}

#endif //__SPI_H__
