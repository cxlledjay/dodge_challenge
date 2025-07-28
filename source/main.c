// ***************************************************************************
// entry point after boot => call game loop
// ***************************************************************************



// -----------------------------< d e b u g >------------------------------------


// *************************************
// set DEBUG_MODE  [1 = on, 0 = off]
#define DEBUG_MODE 1
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
				default:
					print_string(0,0,"BAD MODE\x80");
			}
		}
		while(1);
	}

	#include "game_include/sounds/s_animation.h"
	__attribute__((noreturn)) void debug_music(void)
	{
		unsigned int mode = 0;
		do
		{
			/// game header (professionally stolen :D)
			DP_to_C8();
			Explosion_Snd(current_explosion);
			Init_Music_chk(current_music);
			Wait_Recal();
			Do_Sound();
			Intensity_5F();

			/// toggle drawing to compare clocks
			check_buttons();
			mode = buttons_pressed();
			
			switch (mode) {
				case 1:
					/// clear sound
					Clear_Sound();
					break;
				case 2:
					/// sound 1
					play_music((struct sound_music_t *) object_spawn_sound[0]);
					break;
				case 4:
					/// sound 2
					play_music((struct sound_music_t *) object_spawn_sound[1]);
					break;
				case 8:
					/// sound 3
					play_music(&game_over_sad);
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
	//debug_run();
	debug_music();
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
