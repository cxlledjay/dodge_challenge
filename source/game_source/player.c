#include "game_include/player.h"


// singleplayer
player_t the_player;



//different lane swap animation times (in frames) for different speed stages
const unsigned int PLAYER_ANIMATION_FRAME_CNT_LUT[11] =
{
	14,
	14,
	14,
	11,
	11,
	11,
	8,
	8,
	5,
	5,
	2
};

//half the values for smooth transition keeping
const unsigned int PLAYER_ANIMATION_FRAME_CNT_HALFED_LUT[11] =
{
	7,
	7,
	7,
	6,
	6,
	6,
	4,
	4,
	3,
	3,
	1
};


// fw declarations:
void check_collision(void);
const int PLAYER_STATIC_X_LUT[];
typedef void (*_player_draw_func)(void);
const _player_draw_func PLAYER_DRAW_LUT[];
const int SP1_MID_LEFT_X_LUT[];
const int SP1_RIGHT_MID_X_LUT[];
const int SP1_MID_RIGHT_X_LUT[];
const int SP1_LEFT_MID_X_LUT[];


/****************************************************
 * define utils ... TODO: add draw functions as define?? 
 ***************************************************/
#define PLAYER_Y		(-112)

/**
 * @brief draw one part of the playermodel at (y,x)
 * 
 * used for lane change animation
 */
#define DRAW_PLAYER_VL(Y, X, VECLIST_PTR) 													\
	Reset0Ref();					/* reset beam to center	*/								\
	dp_VIA_t1_cnt_lo = 0x7f;		/* set scaling factor for positioning */				\
	Moveto_d(Y, X);					/* move to player pos */								\
	dp_VIA_t1_cnt_lo = 16;			/* set scaling factor for drawing */					\
	Draw_VLp(VECLIST_PTR);

/**
 * @brief draw one part of the playermodel in his current lane
 * 
 * used for non lane change (default)
 */
#define DRAW_PLAYER_STATIC_VL(VECLIST_PTR)													\
	DRAW_PLAYER_VL(PLAYER_Y, PLAYER_STATIC_X_LUT[(unsigned int) the_player.lane], VECLIST_PTR)





// init func
void player_init(void)
{
	player_t fresh_player = {.lane = MID_LANE, .cnt = 0, .tick = player_draw};
	the_player = fresh_player;
}


 
/****************************************************
 * tick functions 
 ***************************************************/


#include <vectrex.h>

void player_draw(void)
{
	/// drawing settings
	Intensity_5F();					//< set brightness of the electron beam

	/// draw player vector list (based on lane)
	(* PLAYER_DRAW_LUT[(unsigned int) the_player.lane])();

	/// dont forget to check for collisions
	check_collision();

	/// done
	return;
}

#include "game_include/graphics/g_player.h"
#include "game_include/game.h"
void player_change_left(void)
{
	if(the_player.lane == LEFT_LANE)
	{
		/// cannot change lane -> behave as usual
		the_player.tick = player_draw;
		the_player.tick(); //< we still need to draw the player in this frame
	}
	else
	{
		/// animation part
		if(the_player.lane == MID_LANE)
		{
			/// mid -> left

			if(the_player.cnt > PLAYER_ANIMATION_FRAME_CNT_HALFED_LUT[the_game.stage])
			{
				/// first part of animation
				DRAW_PLAYER_VL(PLAYER_Y, SP1_MID_LEFT_X_LUT[the_player.cnt], &vl_player_mid1);
				DRAW_PLAYER_VL(PLAYER_Y, SP1_MID_LEFT_X_LUT[the_player.cnt], &vl_player_mid2);
			}
			else
			{
				/// second part
				DRAW_PLAYER_VL(PLAYER_Y, SP1_MID_LEFT_X_LUT[the_player.cnt], &vl_player_left1);
				DRAW_PLAYER_VL(PLAYER_Y, SP1_MID_LEFT_X_LUT[the_player.cnt], &vl_player_left2);
				DRAW_PLAYER_VL(PLAYER_Y, SP1_MID_LEFT_X_LUT[the_player.cnt], &vl_player_left3);
			}
		}
		else
		{
			/// right -> mid

			if(the_player.cnt > PLAYER_ANIMATION_FRAME_CNT_HALFED_LUT[the_game.stage])
			{
				/// first part of animation
				DRAW_PLAYER_VL(PLAYER_Y, SP1_RIGHT_MID_X_LUT[the_player.cnt], &vl_player_right1);
				DRAW_PLAYER_VL(PLAYER_Y, SP1_RIGHT_MID_X_LUT[the_player.cnt], &vl_player_right2);
				DRAW_PLAYER_VL(PLAYER_Y, SP1_RIGHT_MID_X_LUT[the_player.cnt], &vl_player_right3);
			}
			else
			{
				/// second part
				DRAW_PLAYER_VL(PLAYER_Y, SP1_RIGHT_MID_X_LUT[the_player.cnt], &vl_player_mid1);
				DRAW_PLAYER_VL(PLAYER_Y, SP1_RIGHT_MID_X_LUT[the_player.cnt], &vl_player_mid2);
			}
		}


		the_player.cnt--; //< one frame of animation is completed
		if(the_player.cnt == 0)
		{
			the_player.lane--; //< keep track of new lane the player is now on
			the_player.tick = player_draw; //< done with animation, next frame is normal again
		}
	
		/// dont forget to check for collisions
		check_collision();
	}

	/// done
	return;
}

void player_change_right(void)
{
	if(the_player.lane == RIGHT_LANE)
	{
		/// cannot change lane -> behave as usual
		the_player.tick = player_draw;
		the_player.tick(); //< we still need to draw the player in this frame
	}
	else
	{
		/// animation part
		if(the_player.lane == MID_LANE)
		{
			///        mid -> right

			if(the_player.cnt > PLAYER_ANIMATION_FRAME_CNT_HALFED_LUT[the_game.stage])
			{
				/// first part of animation
				DRAW_PLAYER_VL(PLAYER_Y, SP1_MID_RIGHT_X_LUT[the_player.cnt], &vl_player_mid1);
				DRAW_PLAYER_VL(PLAYER_Y, SP1_MID_RIGHT_X_LUT[the_player.cnt], &vl_player_mid2);
			}
			else
			{
				/// second part
				DRAW_PLAYER_VL(PLAYER_Y, SP1_MID_RIGHT_X_LUT[the_player.cnt], &vl_player_right1);
				DRAW_PLAYER_VL(PLAYER_Y, SP1_MID_RIGHT_X_LUT[the_player.cnt], &vl_player_right2);
				DRAW_PLAYER_VL(PLAYER_Y, SP1_MID_RIGHT_X_LUT[the_player.cnt], &vl_player_right3);
			}
		}
		else
		{
			/// left -> mid

			if(the_player.cnt > PLAYER_ANIMATION_FRAME_CNT_HALFED_LUT[the_game.stage])
			{
				/// first part of animation
				DRAW_PLAYER_VL(PLAYER_Y, SP1_LEFT_MID_X_LUT[the_player.cnt], &vl_player_left1);
				DRAW_PLAYER_VL(PLAYER_Y, SP1_LEFT_MID_X_LUT[the_player.cnt], &vl_player_left2);
				DRAW_PLAYER_VL(PLAYER_Y, SP1_LEFT_MID_X_LUT[the_player.cnt], &vl_player_left3);
			}
			else
			{
				/// second part
				DRAW_PLAYER_VL(PLAYER_Y, SP1_LEFT_MID_X_LUT[the_player.cnt], &vl_player_mid1);
				DRAW_PLAYER_VL(PLAYER_Y, SP1_LEFT_MID_X_LUT[the_player.cnt], &vl_player_mid2);
			}
		}


		the_player.cnt--; //< one frame of animation is completed
		if(the_player.cnt == 0)
		{
			the_player.lane++; //< keep track of new lane the player is now on
			the_player.tick = player_draw; //< done with animation, next frame is normal again
		}
	
		/// dont forget to check for collisions
		check_collision();
	}

	/// done
	return;
}







/****************************************************
 * drawing utils 
 ***************************************************/


#include <vectrex.h>
#include "game_include/graphics/g_player.h"


void _player_draw_mid(void)
{
	DRAW_PLAYER_STATIC_VL(&vl_player_mid1);
	DRAW_PLAYER_STATIC_VL(&vl_player_mid2); //< need to execute drawing function multiple times because of increasing analog offset
}

void _player_draw_left(void)
{
	DRAW_PLAYER_STATIC_VL(&vl_player_left1);
	DRAW_PLAYER_STATIC_VL(&vl_player_left2);
	DRAW_PLAYER_STATIC_VL(&vl_player_left3);
}

void _player_draw_right(void)
{
	DRAW_PLAYER_STATIC_VL(&vl_player_right1);
	DRAW_PLAYER_STATIC_VL(&vl_player_right2);
	DRAW_PLAYER_STATIC_VL(&vl_player_right3);
}

const _player_draw_func PLAYER_DRAW_LUT[3] = 
{
	_player_draw_left,
	_player_draw_mid,
	_player_draw_right
};


 

/****************************************************
 * subroutines
 ***************************************************/

 /**
  * @brief checking if player collides with an object
  * 
  * possible collisions:
  *  1) ability -> pick it up (call dedicated handler...)
  *  2) enemy   -> game over! (just change game state...)
  */
void check_collision(void) //< TODO: might need to add parameter to determine where player is (x pos)
{
	/// TODO: check if bounding box is colliding with objects (enemy / powerup)
}



 
/****************************************************
 * LUTs
 ***************************************************/


const int PLAYER_STATIC_X_LUT[3] =
{
	-82,
	0,
	82
};


/**
 * !!! the LUTs are read beackwards !!!
 */

const int SP1_LEFT_MID_X_LUT[13] = //< [speed1] left -> mid
{
	-6,
	-12,
	-18,
	-23,
	-29,
	-35,
	-41,
	-47,
	-53,
	-59,
	-64,
	-70,
	-76
};
const int SP1_MID_RIGHT_X_LUT[13] = //< [speed1] mid -> right
{
	76,
	70,
	64,
	59,
	53,
	47,
	41,
	35,
	29,
	23,
	18,
	12,
	6
};


const int SP1_RIGHT_MID_X_LUT[13] = //< [speed1] right -> mid
{
	6,
	12,
	18,
	23,
	29,
	35,
	41,
	47,
	53,
	59,
	64,
	70,
	76
};
const int SP1_MID_LEFT_X_LUT[13] = //< [speed1] mid -> left
{
	-76,
	-70,
	-64,
	-59,
	-53,
	-47,
	-41,
	-35,
	-29,
	-23,
	-18,
	-12,
	-6
};
