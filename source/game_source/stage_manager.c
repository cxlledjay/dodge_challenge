#include "game_include/stage_manager.h"
#include "game_include/object_manager.h"


/// the instance that manages speed changes
stage_manager_t the_stage_manager;


void stage_manager_init(void)
{
	stage_manager_t new_clock = {.frames = 49, .next_stage_timer = 0};
	the_stage_manager = new_clock;

	/// init first stage timer based on menu selection
	switch (the_game.options.game_mode) {
		case GAME_MODE_EASY:
		case GAME_MODE_MID:
		case GAME_MODE_HARD:
		case GAME_MODE_HIDDEN:
		/// dont have any values for now...
		default:
			the_stage_manager.next_stage_timer = 30;
	}

	return;
}


void stage_manager_tick(void)
{
	if(the_stage_manager.frames == 0)
	{
		the_stage_manager.frames = 49;
		if(--(the_stage_manager.next_stage_timer) == 0) {
			the_manager.next_stage = 1;
		}
	}
	else
	{
		the_stage_manager.frames--;
	}
}