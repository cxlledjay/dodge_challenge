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


	unsigned int score[7];

	#include "game_include/misc.h"
	__attribute__((noreturn)) void debug_math(void)
	{
		Clear_Score((void*) score);
		//for(unsigned int i = 0; i < 100; ++i) Add_Score_a(100, (void*)score);
		Add_Score_a(41,(void*)score);
		Sub_Score_a(40, (void*) score);
		Sub_Score_a(1, (void*) score);
		Sub_Score_a(1, (void*) score);
		
		unsigned int input = 0;
		do
		{
			char score_display[19] =     "SCORE:     XXXXXX\x80";

			score_display[11] = score[0];
			score_display[12] = score[1];
			score_display[13] = score[2];
			score_display[14] = score[3];
			score_display[15] = score[4];
			score_display[16] = score[5];
			print_string(10,-110, score_display);

    		check_buttons();
			input = buttons_held();

			print_unsigned_int(-30,0,input);
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
	//debug_music();
	debug_math();
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
