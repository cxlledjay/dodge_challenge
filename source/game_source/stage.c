#include "game_include/stage.h"
#include "game_include/object_manager.h"

/************************************************************
 * management object
 ************************************************************/

/// @brief instance of management object
stage_manager_t the_stage_manager;



/************************************************************
 * LUT for stage transition times (in cnt_seconds)
 ************************************************************/

const unsigned long int _STAGE_TRANSITION_INTERVAL[STAGE_T_SIZE] = {
	1000, 900, 900, 800, 800, 800, 700, 700, 700, 700, 1000
};


/************************************************************
 * init function
 ************************************************************/


void stages_init(void)
{
	/// set initial timer to correct value (corresponding to stage)
	the_stage_manager.cnt = _STAGE_TRANSITION_INTERVAL[the_game.stage];
	return;
}

 
/************************************************************
 * tick function (executed each frame)
 ************************************************************/

/* #define DEBUG */
#ifdef DEBUG
#include "lib/print/print.h"
#endif

void stages_tick(void)
{
	#ifdef DEBUG
		print_long_unsigned_int(100,-64,the_stage_manager.cnt);
		print_unsigned_int(100,0,the_object_manager.next_stage);
		print_unsigned_int(80,0,the_game.stage);
	#endif

	/// count down until stage change is required
	if(--(the_stage_manager.cnt) == 0)
	{
		if(the_game.stage < game_max_stage[the_game.options.game_mode])
		{
			/// enqueue stage change
			the_object_manager.next_stage = 1;

			/// set next timer
			the_stage_manager.cnt = _STAGE_TRANSITION_INTERVAL[the_game.stage];
		}
		else
		{
			/// max stage reached -> no next stage
			the_stage_manager.cnt = 0xffff; //< count down for a while before triggering this code again
		}
	}

	/// done
	return;
}