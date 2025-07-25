#include "game_include/stage_manager.h"
#include "game_include/object_manager.h"


/// the instance that manages speed changes
stage_manager_t the_stage_manager;


/************************************************************
 * LUT for stage transition times (in seconds)
 ************************************************************/
/* this for the actual game:
const unsigned int _STAGE_TRANSITION_INTERVAL[STAGE_T_SIZE-2] = {
	20, 30, 30, 25, 25, 20, 20, 30, 40
}; */

/// for debugging... is faster :D
const unsigned int _STAGE_TRANSITION_INTERVAL[STAGE_T_SIZE-2] = {
	5, 5, 5, 5, 5, 5, 5, 5, 5
};


/************************************************************
 * init function
 ************************************************************/

//fw decl:
void stage_manager_tick(void);
void no_tick(void) {return;}

void stage_manager_init(void)
{
	stage_manager_t new_clock = {.frames = 49, .next_stage_timer = 0, .tick = stage_manager_tick};
	the_stage_manager = new_clock;

	/// init first stage timer based on menu selection
	switch (the_game.options.game_mode) {
		case GAME_MODE_EASY:
		case GAME_MODE_MID:
		case GAME_MODE_HARD:
		case GAME_MODE_HIDDEN:
		/// dont have any values for now...
		default:
			the_stage_manager.next_stage_timer = _STAGE_TRANSITION_INTERVAL[0];
	}

	return;
}



 
/************************************************************
 * tick function (executed each frame)
 ************************************************************/

/* #define DEBUG */
#ifdef DEBUG
#include "lib/print/print.h"
#endif

void stage_manager_tick(void)
{
	#ifdef DEBUG
		print_unsigned_int(100,-64,the_stage_manager.next_stage_timer);
		print_unsigned_int(100,0,the_object_manager.next_stage);
		print_unsigned_int(80,0,the_game.stage);
	#endif
	if(the_stage_manager.frames == 0)
	{
		the_stage_manager.frames = 49;
		if(--(the_stage_manager.next_stage_timer) == 0) {
			/// indicate stage transition to object manager
			the_object_manager.next_stage = 1;
			if(the_game.stage + 1 > game_max_stage[the_game.options.game_mode])
			{
				/// max stage reached -> stop ramping
				the_stage_manager.tick = no_tick;
				return;
			}
			else
			{
				/// restart timer
				the_stage_manager.next_stage_timer = _STAGE_TRANSITION_INTERVAL[the_game.stage];
			}
		}
	}
	else
	{
		the_stage_manager.frames--;
	}
}