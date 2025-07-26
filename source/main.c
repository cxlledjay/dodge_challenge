// ***************************************************************************
// main -> entry point & endless loop
// ***************************************************************************

#include "game_include/game.h"

// *************************************
// set DEBUG_MODE  [1 = on, 0 = off]
#define DEBUG_MODE 0

//debug
#include <vectrex.h>
#include "print/print.h"		// printf() equivalent
#include "utils/controller.h" 	// buttons input





// -----------------------------< d e b u g >------------------------------------

#if DEBUG_MODE
// *************************************
// debug loop, used to test stuff, without altering the game loop
// (e.g. drawing new sprites)
// *************************************
#include "game_include/graphics/g_player.h"
	#if 0
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

#include "game_include/graphics/g_misc.h"
__attribute__((noreturn)) void draw_font(void)
{
	clk_init();
	do
	{
		// synchronize frame rate to 50 Hz
		Wait_Recal();
		clk_update();

		Intensity_5F();					// set brightness of the electron beam
		Reset0Ref();					// reset beam to center
		dp_VIA_t1_cnt_lo = 0x7f;			// set scaling factor for drawing
		Moveto_d(0, -111);				// move beam to object coordinates
		dp_VIA_t1_cnt_lo = 16;			// set scaling factor for drawing
		Draw_VLp((void*)vl_digits[0]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[1]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[2]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[3]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[4]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[5]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[6]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[7]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[8]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[9]);


		//reference
		Intensity_5F();					// set brightness of the electron beam
		Reset0Ref();					// reset beam to center
		dp_VIA_t1_cnt_lo = 0x7f;			// set scaling factor for drawing
		Moveto_d(-42, -111);				// move beam to object coordinates
		dp_VIA_t1_cnt_lo = 16;			// set scaling factor for drawing
		Draw_VLp((void*)vl_digits[0]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[0]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[0]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[0]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[0]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[0]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[0]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[0]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[0]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[0]);
	}
	while(1);
}


__attribute__((noreturn)) void draw_speed(void)
{
	do
	{
		// synchronize frame rate to 50 Hz
		Wait_Recal();
		clk_update();

		Intensity_5F();					// set brightness of the electron beam
		Reset0Ref();					// reset beam to center
		dp_VIA_t1_cnt_lo = 0x7f;			// set scaling factor for drawing
		Moveto_d(0, -64);				// move beam to object coordinates
		dp_VIA_t1_cnt_lo = 15;			// set scaling factor for drawing
		Draw_VLp(&vl_speed_display);
		dp_VIA_t1_cnt_lo = 8;			// set scaling factor for drawing
		Draw_VLp((void*)vl_digits[2]);
		Moveto_d(-118, 24);				// move beam to object coordinates
		Dot_here();
		Moveto_d(118, 103);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[5]);
	}
	while(1);
}
	#endif

__attribute__((noreturn)) void draw_icons(void)
{
	do
	{
		// synchronize frame rate to 50 Hz
		Intensity_5F();					// set brightness of the electron beam
		Wait_Recal();

		Reset0Ref();					// reset beam to center

		dp_VIA_t1_cnt_lo = 0x7f;			// set scaling factor for drawing
		Moveto_d(0, -64);				// move beam to object coordinates
		dp_VIA_t1_cnt_lo = 15;			// set scaling factor for drawing
		Draw_VLp(&vl_speed_display);
		dp_VIA_t1_cnt_lo = 8;			// set scaling factor for drawing
		Draw_VLp((void*)vl_digits[2]);
		Moveto_d(-118, 24);				// move beam to object coordinates
		Dot_here();
		Moveto_d(118, 103);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[5]);
	}
	while(1);
}
#endif

// -----------------------------< / d e b u g >------------------------------------


int main(void)
{	
	#if DEBUG_MODE
	//run_debug();
	//draw_font();
	draw_speed();
	#else
	
	/**
	 * @brief endless game loop
	 * the few only important lines in this file...
	 */

	/// bootstrap init
	game_t new_game = {.execute_state = game_start};
	the_game = new_game;

	/// main loop
	while(1) the_game.execute_state();
	

	#endif
}
