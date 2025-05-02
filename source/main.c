// ***************************************************************************
// main
// ***************************************************************************

//std
#include <vectrex.h>
#include "print/print.h"		// printf() equivalent
#include "utils/controller.h" 	// buttons input

//dodge_challenge
#include "game_include/clock.h"
#include "game_include/level.h"
#include "game_include/player.h"
#include "game_include/map.h"

// *************************************
// set DEBUG_MODE  [1 = on, 0 = off]
#define DEBUG_MODE 0





// ---------------------------------------------------------------------------

#if DEBUG_MODE
// *************************************
// debug loop, used to test stuff, without altering the game loop
// (e.g. drawing new sprites)
// *************************************
#include "game_include/graphics/g_player.h"
__attribute__((noreturn)) void run_debug(void)
{
	do
	{
		//draw player		
		Intensity_5F();					// set brightness of the electron beam
		Reset0Ref();					// reset beam to center
		dp_VIA_t1_cnt_lo = 0x7f;		// set scaling factor for positioning
		Moveto_d(0, 0);				// move beam to object coordinates
		dp_VIA_t1_cnt_lo = 255;			// set scaling factor for drawing
		Draw_VLp(&vl_player_mid);			// draw vector list
	}
	while(1);
}
#else
// *************************************
// game loop, called by main
// *************************************
__attribute__((noreturn)) void run_game(void)
{
	//init section
	clk_init();
	lvl_init();

	//game loop section
	do
	{
		// synchronize frame rate to 50 Hz
		Wait_Recal();
		
		// update game clock
		clk_update();
		
		//build road
		map_draw_road();
		
		//io management
		player_handle_input();

		//debug
		print_signed_int(120,60,lvl_speed);

		//draw player
		player_draw();

	}
	while(1);
}
#endif


int main(void)
{	
	#if DEBUG_MODE
	run_debug();
	#else
	run_game();
	#endif
}

// ***************************************************************************
// end of file
// ***************************************************************************
