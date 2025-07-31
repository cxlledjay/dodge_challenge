#include "game_include/player.h"


// singleplayer
player_t the_player;


// fw declarations:
typedef void (*_player_draw_func)(void);
const _player_draw_func _PLAYER_DRAW_LUT[];

    

/****************************************************************
 * macros for drawing the player
 ****************************************************************/


/// @brief draw one part of the playermodel at the_player.x
/// @param VECLIST_PTR pointer to list of packet_t (graphic)
#define _DRAW_PLAYER_VL(VECLIST_PTR) 													\
	Reset0Ref();					/* reset beam to center	*/								\
	dp_VIA_t1_cnt_lo = 0x7f;		/* set scaling factor for positioning */				\
	Moveto_d(PLAYER_Y, the_player.x);					/* move to player pos */								\
	dp_VIA_t1_cnt_lo = 16;			/* set scaling factor for drawing */					\
	Draw_VLp(VECLIST_PTR);


/// @brief draw leftlane model of player at (PLAYER_Y,the_player.x)
#define PLAYER_DRAW_LEFT()				\
	_DRAW_PLAYER_VL(&vl_player_left1);	\
	_DRAW_PLAYER_VL(&vl_player_left2);	\
	_DRAW_PLAYER_VL(&vl_player_left3);
	
/// @brief draw leftlane model of player at (PLAYER_Y,the_player.x)
#define PLAYER_DRAW_MID()				\
	_DRAW_PLAYER_VL(&vl_player_mid1);	\
	_DRAW_PLAYER_VL(&vl_player_mid2);
	
/// @brief draw leftlane model of player at (PLAYER_Y,the_player.x)
#define PLAYER_DRAW_RIGHT()				\
	_DRAW_PLAYER_VL(&vl_player_right1);	\
	_DRAW_PLAYER_VL(&vl_player_right2);	\
	_DRAW_PLAYER_VL(&vl_player_right3);

/** the above has to be done, in order to accomodate analog errors when drawing big vector lists */


/****************************************************
 * functions 
 ***************************************************/

/// @brief init function
void player_init(void)
{
	player_t fresh_player = {
		.lane = MID_LANE,
		.x = PLAYER_X_MID,
		.x_LUT = 0,
		.queued_lane_change = 0,
		.cnt = 0,
		.fuel = 100,
		.ability = AC_NONE,
		.has_extralife = 0,
		.tick = player_draw};
	the_player = fresh_player;
}


 
/****************************************************
 * tick functions 
 ***************************************************/


#include <vectrex.h>
#include "game_include/collision.h"

/// @brief default drawing function in case of no active lane change
void player_draw(void)
{
	/// check for collision
	aabb_check_collision(); //< if collision occurs -> wont reach rest of function

	/// draw player vector list (based on lane)
	(* _PLAYER_DRAW_LUT[(unsigned int) the_player.lane])();

	/// done
	return;
}



/// ---------------------------------< lane changes >---------------------------------


#include "game_include/graphics/g_player.h"
#include "game_include/game.h"

/**
 * @brief generic part for all lane change functions
 */
#define LANE_CHANGE_UPDATE_VARS()																						\
	the_player.cnt--; /* sequence is important... first decrement to match index starting from 0 */						\
	the_player.x = the_player.x_LUT[the_player.cnt]; /* move to next x coord */											\
	collision.recalculate_player_aabb(); /* recalculated player bounding box */													\
	aabb_check_collision(); /* now check for collisions */




/// actual lane change functions: .......................................................
#include "game_include/gen_data/gen_player_lanechange.h"

/// left -> mid .................................../

void player_change_left_to_mid_step1(void)
{
	LANE_CHANGE_UPDATE_VARS();
	PLAYER_DRAW_LEFT();

	/// check if first half of animation is done
	if(the_player.cnt == 0)
	{
		/// transition to second half
		the_player.tick = player_lane_change_phase2.animation_tick->left_to_mid;
		the_player.cnt = player_lane_change_phase2.FRAME_CNT[the_game.stage];
		the_player.x_LUT = player_lane_change_phase2.x_LUT.left_to_mid[the_game.stage];
		the_player.lane = MID_LANE; //< now use midlane model + aabbcd
		COLLISION_SET_MID();
	}
}

void player_change_left_to_mid_step2(void)
{
	LANE_CHANGE_UPDATE_VARS();
	PLAYER_DRAW_MID();

	/// check if second half of animation is done
	if(the_player.cnt == 0)
	{
		/// transition to normal again
		the_player.x = PLAYER_X_MID;
		collision.recalculate_player_aabb();

		/// check if lane change is queued
		switch(the_player.queued_lane_change) {
			default:
			case 0:
				/// nothing queued
				the_player.tick = player_draw;
				break;
			case -1:
				/// left change queued
				PLAYER_INIT_LC_MID_LEFT()
				break;
			case 1:
				/// right change queued
				PLAYER_INIT_LC_MID_RIGHT()
				break;
		}
		the_player.queued_lane_change = 0; //< clear queued
	}
}



/// mid -> right .................................../

void player_change_mid_to_right_step1(void)
{
	LANE_CHANGE_UPDATE_VARS();
	PLAYER_DRAW_MID();

	/// check if first half of animation is done
	if(the_player.cnt == 0)
	{
		/// transition to second half
		the_player.tick = player_lane_change_phase2.animation_tick->mid_to_right;
		the_player.cnt = player_lane_change_phase2.FRAME_CNT[the_game.stage];
		the_player.x_LUT = player_lane_change_phase2.x_LUT.mid_to_right[the_game.stage];
		the_player.lane = RIGHT_LANE;
		COLLISION_SET_RIGHT();
	}
}

void player_change_mid_to_right_step2(void)
{
	LANE_CHANGE_UPDATE_VARS();
	PLAYER_DRAW_RIGHT();

	/// check if second half of animation is done
	if(the_player.cnt == 0)
	{
		/// transition to normal again
		the_player.x = PLAYER_X_MAX;
		collision.recalculate_player_aabb();
		
		/// check if lane change is queued
		switch(the_player.queued_lane_change) {
			default:
			case 1:
				/// not executable
			case 0:
				/// nothing queued
				the_player.tick = player_draw;
				break;
			case -1:
				/// left change queued
				PLAYER_INIT_LC_RIGHT_MID()
				break;
		}
		the_player.queued_lane_change = 0; //< clear queued
	}
}



/// right -> mid .................................../

void player_change_right_to_mid_step1(void)
{
	LANE_CHANGE_UPDATE_VARS();
	PLAYER_DRAW_RIGHT();

	/// check if first half of animation is done
	if(the_player.cnt == 0)
	{
		/// transition to second half
		the_player.tick = player_lane_change_phase2.animation_tick->right_to_mid;
		the_player.cnt = player_lane_change_phase2.FRAME_CNT[the_game.stage];
		the_player.x_LUT = player_lane_change_phase2.x_LUT.right_to_mid[the_game.stage];
		the_player.lane = MID_LANE;
		COLLISION_SET_MID();
	}
}

void player_change_right_to_mid_step2(void)
{
	LANE_CHANGE_UPDATE_VARS();
	PLAYER_DRAW_MID();

	/// check if second half of animation is done
	if(the_player.cnt == 0)
	{
		/// transition to normal again
		the_player.x = PLAYER_X_MID;
		collision.recalculate_player_aabb();
		
		/// check if lane change is queued
		switch(the_player.queued_lane_change) {
			default:
			case 0:
				/// nothing queued
				the_player.tick = player_draw;
				break;
			case -1:
				/// left change queued
				PLAYER_INIT_LC_MID_LEFT()
				break;
			case 1:
				/// right change queued
				PLAYER_INIT_LC_MID_RIGHT()
				break;
		}
		the_player.queued_lane_change = 0; //< clear queued
	}
}



/// mid -> left .................................../

void player_change_mid_to_left_step1(void)
{
	LANE_CHANGE_UPDATE_VARS();
	PLAYER_DRAW_MID();

	/// check if first half of animation is done
	if(the_player.cnt == 0)
	{
		/// transition to second half
		the_player.tick = player_lane_change_phase2.animation_tick->mid_to_left;
		the_player.cnt = player_lane_change_phase2.FRAME_CNT[the_game.stage];
		the_player.x_LUT = player_lane_change_phase2.x_LUT.mid_to_left[the_game.stage];
		the_player.lane = LEFT_LANE;
		COLLISION_SET_LEFT();
	}
}

void player_change_mid_to_left_step2(void)
{
	LANE_CHANGE_UPDATE_VARS();
	PLAYER_DRAW_LEFT();

	/// check if second half of animation is done
	if(the_player.cnt == 0)
	{
		/// transition to normal again
		the_player.x = PLAYER_X_MIN;
		collision.recalculate_player_aabb();
		
		/// check if lane change is queued
		switch(the_player.queued_lane_change) {
			default:
			case -1:
				/// not possible
			case 0:
				/// nothing queued
				the_player.tick = player_draw;
				break;
			case 1:
				/// right change queued
				PLAYER_INIT_LC_LEFT_MID()
				break;
		}
		the_player.queued_lane_change = 0; //< clear queued
	}
}

















/****************************************************
 * drawing utils 
 ***************************************************/


#include <vectrex.h>
#include "game_include/graphics/g_player.h"


void _player_draw_mid(void)
{
	PLAYER_DRAW_MID();
}

void _player_draw_left(void)
{
	PLAYER_DRAW_LEFT();
}

void _player_draw_right(void)
{
	PLAYER_DRAW_RIGHT();
}

const _player_draw_func _PLAYER_DRAW_LUT[3] = 
{
	_player_draw_left,
	_player_draw_mid,
	_player_draw_right
};




/****************************************************
 * animation tick functions interfaces
 ***************************************************/

/// @brief animation pointers (public interface)
const player_lane_change_animation_t _player_lanechange_tick_phase1 =
{
	.left_to_mid = player_change_left_to_mid_step1,
	.mid_to_right = player_change_mid_to_right_step1,
	.right_to_mid = player_change_right_to_mid_step1,
	.mid_to_left = player_change_mid_to_left_step1
};

/// @brief animation pointers (must only be used here!)
const player_lane_change_animation_t _player_lanechange_tick_phase2 =
{
	.left_to_mid = player_change_left_to_mid_step2,
	.mid_to_right = player_change_mid_to_right_step2,
	.right_to_mid = player_change_right_to_mid_step2,
	.mid_to_left = player_change_mid_to_left_step2
};
