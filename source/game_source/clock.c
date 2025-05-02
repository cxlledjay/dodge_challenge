#include "game_include/clock.h"


unsigned int clk_frames; // increments in frequency of 50Hz, scaled up by 5
//unsigned long int clk_seconds; // increments in frequency of 1Hz

void clk_init(void)
{
	clk_frames = 0;
	//clk_seconds = 0;
}

void clk_update(void)
{
	if(clk_frames > 240)
	{
		//executed each second
		clk_frames = 0;
		//clk_seconds = clk_seconds + 1;
		//call to "each second events" -> e.g. update score
	}
	else
	{
		clk_frames = clk_frames + 5;
	}
}
