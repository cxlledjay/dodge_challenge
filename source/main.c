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
#define DEBUG_MODE 1





// ---------------------------------------------------------------------------

#if DEBUG_MODE
// *************************************
// debug loop, used to test stuff, without altering the game loop
// (e.g. drawing new sprites)
// *************************************
#include "game_include/graphics/g_player.h"
__attribute__((noreturn)) void run_debug(void)
{
	clk_init();
	player_init();
	do
	{
		// synchronize frame rate to 50 Hz
		Wait_Recal();
		clk_update();

		Intensity_5F();					// set brightness of the electron beam
		dp_VIA_t1_cnt_lo = 0x7f;			// set scaling factor for drawing
		Moveto_d(64, 0);				// move beam to object coordinates
		dp_VIA_t1_cnt_lo = 16;			// set scaling factor for drawing
		Draw_VLp(&vl_player_mid);
		//Draw_VLp((void*)vl_digits[clk_seconds % 10]);			// draw vector list
		//print_long_unsigned_int(110,-60,clk_seconds);
		Reset0Ref();					// reset beam to center
		dp_VIA_t1_cnt_lo = 0x7f;		// set scaling factor for positioning
		Moveto_d(-64, 32);				// move beam to object coordinates
		dp_VIA_t1_cnt_lo = 255;			// set scaling factor for drawing
		Draw_VLp(&vl_player_right);
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
	map_init();
	player_init();

	//game loop section
	do
	{
		// synchronize frame rate to 50 Hz
		Wait_Recal();
		clk_update();
		map_calculate_animation();
		
		//build road
		map_draw_road();
		
		//io management
		player_handle_input();

		//debug
		//print_unsigned_int(120,60,lvl_speed);

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
