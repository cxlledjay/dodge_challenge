// ***************************************************************************
// main
// ***************************************************************************

//std
#include <vectrex.h>
#include "print/print.h"		// printf() equivalent
#include "utils/controller.h" 	// buttons input

//dodge_challenge
#include "graphics/player.h"  	// player sprites
#include "map.h"  				// map (road etc.) logic
#include "player.h"  			// player logic

// *************************************
// set DEBUG_MODE  [1 = on, 0 = off]
#define DEBUG_MODE 0





// ---------------------------------------------------------------------------

#if DEBUG_MODE
// *************************************
// debug loop, used to test stuff, without altering the game loop
// (e.g. drawing new sprites)
// *************************************
__attribute__((noreturn)) void debug_loop(void)
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
__attribute__((noreturn)) void game_loop(void)
{
	do
	{
		Wait_Recal();					// synchronize frame rate to 50 Hz
		
		//build road
		draw_road();
		
		//io management
		check_buttons();
		if(button_1_1_pressed())
		{
			change_lane(-1);
		}
		else if(button_1_3_pressed())
		{
			change_lane(1);
		}
		
		//debug
		if(button_1_2_pressed())
		{
			if(temp_speed == 1) temp_speed = 50;
			else temp_speed = temp_speed - 1;
		}
		else if (button_1_4_pressed())
		{
			if(temp_speed == 50) temp_speed = 1;
			else temp_speed = temp_speed + 1;
		}
		
		print_unsigned_int(120,-80,player_lane);
		print_unsigned_int(120,60,temp_speed);

		//draw player		
		Intensity_5F();					// set brightness of the electron beam
		Reset0Ref();					// reset beam to center
		dp_VIA_t1_cnt_lo = 0x7f;		// set scaling factor for positioning
		Moveto_d(-112, lookup_player_lane_x_pos[player_lane]);				// move beam to object coordinates
		dp_VIA_t1_cnt_lo = 64;			// set scaling factor for drawing
		Draw_VLp(&vectors_player);			// draw vector list
	}
	while(1);
}
#endif


int main(void)
{	
	#if DEBUG_MODE
	debug_loop();
	#else
	game_loop();
	#endif
}

// ***************************************************************************
// end of file
// ***************************************************************************
