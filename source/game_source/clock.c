#include "game_include/clock.h"


// tick tack
clock_t the_clock;


void clock_init(void)
{
	clock_t new_clock = {.frames = 49, .seconds = 0};
	the_clock = new_clock;
	return;
}


void clock_tick(void)
{
	if(the_clock.frames == 0)
	{
		the_clock.frames = 49;
		the_clock.seconds++;
	}
	else
	{
		the_clock.frames--;
	}
}