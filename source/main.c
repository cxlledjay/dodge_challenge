// ***************************************************************************
// entry point after boot => call game loop
// ***************************************************************************



// -----------------------------< d e b u g >------------------------------------


// *************************************
// set DEBUG_MODE  [1 = on, 0 = off]
#define DEBUG_MODE 0
// *************************************


#if DEBUG_MODE

	#include "game_include/graphics/g_gui.h"
	#include "game_include/graphics/g_object.h"
	#include "print/print.h"
	#include "utils/controller.h"
	__attribute__((noreturn)) void debug_run(void)
	{
		unsigned int mode = 0;
		do
		{
			/// sync
			Intensity_7F();
			Wait_Recal();

			/// toggle drawing to compare clocks
			check_buttons();
			mode = (buttons_pressed() != 0) ? buttons_pressed() : mode; //< dirty hack
			
			switch (mode) {
				case 1:
					/// draw nothing (baseline clk)
					Reset0Ref();
					dp_VIA_t1_cnt_lo = 0x7f;
					Moveto_d(0, 0);
					dp_VIA_t1_cnt_lo = 25;
					Draw_VLp(&vl_enemy_car1);
					break;
				case 2:
					/// compare draw 1
					Reset0Ref();
					dp_VIA_t1_cnt_lo = 0x7f;
					Moveto_d(0, 0);
					dp_VIA_t1_cnt_lo = 25;
					Draw_VLp((struct packet_t *) vl_exploded[1]);
					break;
				case 4:
					/// compare draw 2
					Reset0Ref();
					dp_VIA_t1_cnt_lo = 0x7f;
					Moveto_d(0, 0);
					dp_VIA_t1_cnt_lo = 25;
					Draw_VLp((struct packet_t *) vl_exploded[2]);
					break;
				case 8:
					/// compare draw 3
					Reset0Ref();
					dp_VIA_t1_cnt_lo = 0x7f;
					Moveto_d(0, 0);
					dp_VIA_t1_cnt_lo = 25;
					Draw_VLp((struct packet_t *) vl_exploded[3]);
					break;
					break;
				default:
					print_string(0,0,"BAD MODE\x80");
			}
		}
		while(1);
	}
#endif

// -----------------------------< / d e b u g >------------------------------------


#include "game_include/game.h"
int main(void)
{	
	#if DEBUG_MODE
	debug_run();
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
