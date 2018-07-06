/* 
* ParallelGraphicLCD.h
*
* Created: 7/6/2018 4:11:06 PM
* Author: Animesh Sinha
*/


#ifndef __PARALLELGRAPHICLCD_H__
#define __PARALLELGRAPHICLCD_H__

#include "Output.h"

namespace atmicro {
	class ParallelGraphicLCD : public Output
	{
	//variables
	public:
	protected:
		PORT dataPort;
		PIN pinEN, pinRW, pinRS;
	private:

	//functions
	public:
		ParallelGraphicLCD(PORT portData, PIN pinRS, PIN pinRW, PIN pinEN);
		~ParallelGraphicLCD();
		void initialize();
		void clear();
		void data(unsigned char chr);
		void command(unsigned char cmd);
		void action_enable(void);
	}; //ParallelGraphicLCD
}

#endif //__PARALLELGRAPHICLCD_H__
