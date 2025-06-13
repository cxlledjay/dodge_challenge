#include "game_include/player.h"


// singleplayer
player_t the_player;


#include "game_include/game.h"

//fist animation step
const unsigned int PLAYER_ANIMATION_FRAME_CNT_STEP1_LUT[STAGE_T_SIZE] =
{
	7,
	7,
	7,
	7,
	7,
	7,
	7,
	7,
	7,
	7,
	7
};

//second animation step
const unsigned int PLAYER_ANIMATION_FRAME_CNT_STEP2_LUT[STAGE_T_SIZE] =
{
	6,
	6,
	6,
	6,
	6,
	6,
	6,
	6,
	6,
	6,
	6
};


// fw declarations:
void check_collision(void);
const int PLAYER_STATIC_X_LUT[];
typedef void (*_player_draw_func)(void);
const _player_draw_func PLAYER_DRAW_LUT[];

void player_change_left_to_mid_step2(void);
void player_change_mid_to_right_step2(void);
void player_change_right_to_mid_step2(void);
void player_change_mid_to_left_step2(void);

const int* const PLAYER_LUT_LEFT_MID_STEP2[];
const int* const PLAYER_LUT_MID_RIGHT_STEP2[];
const int* const PLAYER_LUT_RIGHT_MID_STEP2[];
const int* const PLAYER_LUT_MID_LEFT_STEP2[];


/****************************************************
 * define utils ...
 ***************************************************/
#define PLAYER_Y		(-112)

/**
 * @brief draw one part of the playermodel at the_player.x
 * 
 * @param VECLIST_PTR pointer to list of packet_t (graphic)
 */
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

/** the above has to be done in order to accomodate analog errors when drawing big vector lists */







/****************************************************
 * functions 
 ***************************************************/

/// @brief init function
void player_init(void)
{
	player_t fresh_player = {.lane = MID_LANE, .x = PLAYER_STATIC_X_LUT[MID_LANE], .x_LUT = 0,  .cnt = 0, .tick = player_draw};
	the_player = fresh_player;
}


 
/****************************************************
 * tick functions 
 ***************************************************/


#include <vectrex.h>

/// @brief default drawing function in case of no active lane change
void player_draw(void)
{
	/// check for collision
	check_collision(); //< if collision occurs -> wont reach rest of function

	/// drawing settings
	Intensity_5F();					//< set brightness of the electron beam

	/// draw player vector list (based on lane)
	(* PLAYER_DRAW_LUT[(unsigned int) the_player.lane])();

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
	check_collision(); /* check for collisions */																		\
	Intensity_5F();




/// actual lane change functions: .......................................................


/// left -> mid .................................../

void player_change_left_to_mid_step1(void)
{
	LANE_CHANGE_UPDATE_VARS();
	PLAYER_DRAW_LEFT();

	/// check if first half of animation is done
	if(the_player.cnt == 0)
	{
		/// transition to second half
		the_player.tick = player_change_left_to_mid_step2;
		the_player.cnt = PLAYER_ANIMATION_FRAME_CNT_STEP2_LUT[the_game.stage];
		the_player.x_LUT = PLAYER_LUT_LEFT_MID_STEP2[the_game.stage];
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
		the_player.lane = MID_LANE;
		the_player.x = PLAYER_STATIC_X_LUT[MID_LANE];
		the_player.tick = player_draw;
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
		the_player.tick = player_change_mid_to_right_step2;
		the_player.cnt = PLAYER_ANIMATION_FRAME_CNT_STEP2_LUT[the_game.stage];
		the_player.x_LUT = PLAYER_LUT_MID_RIGHT_STEP2[the_game.stage];
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
		the_player.lane = RIGHT_LANE;
		the_player.x = PLAYER_STATIC_X_LUT[RIGHT_LANE];
		the_player.tick = player_draw;
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
		the_player.tick = player_change_right_to_mid_step2;
		the_player.cnt = PLAYER_ANIMATION_FRAME_CNT_STEP2_LUT[the_game.stage];
		the_player.x_LUT = PLAYER_LUT_RIGHT_MID_STEP2[the_game.stage];
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
		the_player.lane = MID_LANE;
		the_player.x = PLAYER_STATIC_X_LUT[MID_LANE];
		the_player.tick = player_draw;
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
		the_player.tick = player_change_mid_to_left_step2;
		the_player.cnt = PLAYER_ANIMATION_FRAME_CNT_STEP2_LUT[the_game.stage];
		the_player.x_LUT = PLAYER_LUT_MID_LEFT_STEP2[the_game.stage];
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
		the_player.lane = LEFT_LANE;
		the_player.x = PLAYER_STATIC_X_LUT[LEFT_LANE];
		the_player.tick = player_draw;
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

const _player_draw_func PLAYER_DRAW_LUT[3] = 
{
	_player_draw_left,
	_player_draw_mid,
	_player_draw_right
};


 

/****************************************************
 * collision detection
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

const int _SP1_LEFT_MID_X_LUT_2[6] = //< [speed1] left -> mid (2)
{
	-6,
	-12,
	-18,
	-23,
	-29,
	-35
};
const int _SP1_LEFT_MID_X_LUT_1[7] = //< [speed1] left -> mid (1)
{
	-41,
	-47,
	-53,
	-59,
	-64,
	-70,
	-76
};


const int _SP1_MID_RIGHT_X_LUT_2[6] = //< [speed1] mid -> right (2)
{
	76,
	70,
	64,
	59,
	53,
	47
};
const int _SP1_MID_RIGHT_X_LUT_1[7] = //< [speed1] mid -> right (1)
{
	41,
	35,
	29,
	23,
	18,
	12,
	6
};


const int _SP1_RIGHT_MID_X_LUT_2[6] = //< [speed1] right -> mid (2)
{
	6,
	12,
	18,
	23,
	29,
	35
};
const int _SP1_RIGHT_MID_X_LUT_1[7] = //< [speed1] right -> mid (1)
{
	41,
	47,
	53,
	59,
	64,
	70,
	76
};


const int _SP1_MID_LEFT_X_LUT_2[6] = //< [speed1] mid -> left (2)
{
	-76,
	-70,
	-64,
	-59,
	-53,
	-47
};
const int _SP1_MID_LEFT_X_LUT_1[7] = //< [speed1] mid -> left (1)
{
	-41,
	-35,
	-29,
	-23,
	-18,
	-12,
	-6
};



/****************************************************
 * LUT interface (indexed)
 ***************************************************/

/// .....public:

const int* const PLAYER_LUT_LEFT_MID_STEP1[STAGE_T_SIZE] =
{
	_SP1_LEFT_MID_X_LUT_1,
	_SP1_LEFT_MID_X_LUT_1,
	_SP1_LEFT_MID_X_LUT_1,
	_SP1_LEFT_MID_X_LUT_1,
	_SP1_LEFT_MID_X_LUT_1,
	_SP1_LEFT_MID_X_LUT_1,
	_SP1_LEFT_MID_X_LUT_1,
	_SP1_LEFT_MID_X_LUT_1,
	_SP1_LEFT_MID_X_LUT_1,
	_SP1_LEFT_MID_X_LUT_1,
	_SP1_LEFT_MID_X_LUT_1
};

const int* const PLAYER_LUT_MID_RIGHT_STEP1[STAGE_T_SIZE] =
{
	_SP1_MID_RIGHT_X_LUT_1,
	_SP1_MID_RIGHT_X_LUT_1,
	_SP1_MID_RIGHT_X_LUT_1,
	_SP1_MID_RIGHT_X_LUT_1,
	_SP1_MID_RIGHT_X_LUT_1,
	_SP1_MID_RIGHT_X_LUT_1,
	_SP1_MID_RIGHT_X_LUT_1,
	_SP1_MID_RIGHT_X_LUT_1,
	_SP1_MID_RIGHT_X_LUT_1,
	_SP1_MID_RIGHT_X_LUT_1,
	_SP1_MID_RIGHT_X_LUT_1
};

const int* const PLAYER_LUT_RIGHT_MID_STEP1[STAGE_T_SIZE] =
{
	_SP1_RIGHT_MID_X_LUT_1,
	_SP1_RIGHT_MID_X_LUT_1,
	_SP1_RIGHT_MID_X_LUT_1,
	_SP1_RIGHT_MID_X_LUT_1,
	_SP1_RIGHT_MID_X_LUT_1,
	_SP1_RIGHT_MID_X_LUT_1,
	_SP1_RIGHT_MID_X_LUT_1,
	_SP1_RIGHT_MID_X_LUT_1,
	_SP1_RIGHT_MID_X_LUT_1,
	_SP1_RIGHT_MID_X_LUT_1,
	_SP1_RIGHT_MID_X_LUT_1
};

const int* const PLAYER_LUT_MID_LEFT_STEP1[STAGE_T_SIZE] =
{
	_SP1_MID_LEFT_X_LUT_1,
	_SP1_MID_LEFT_X_LUT_1,
	_SP1_MID_LEFT_X_LUT_1,
	_SP1_MID_LEFT_X_LUT_1,
	_SP1_MID_LEFT_X_LUT_1,
	_SP1_MID_LEFT_X_LUT_1,
	_SP1_MID_LEFT_X_LUT_1,
	_SP1_MID_LEFT_X_LUT_1,
	_SP1_MID_LEFT_X_LUT_1,
	_SP1_MID_LEFT_X_LUT_1,
	_SP1_MID_LEFT_X_LUT_1
};


/// .....private:

const int* const PLAYER_LUT_LEFT_MID_STEP2[STAGE_T_SIZE] =
{
	_SP1_LEFT_MID_X_LUT_2,
	_SP1_LEFT_MID_X_LUT_2,
	_SP1_LEFT_MID_X_LUT_2,
	_SP1_LEFT_MID_X_LUT_2,
	_SP1_LEFT_MID_X_LUT_2,
	_SP1_LEFT_MID_X_LUT_2,
	_SP1_LEFT_MID_X_LUT_2,
	_SP1_LEFT_MID_X_LUT_2,
	_SP1_LEFT_MID_X_LUT_2,
	_SP1_LEFT_MID_X_LUT_2,
	_SP1_LEFT_MID_X_LUT_2
};

const int* const PLAYER_LUT_MID_RIGHT_STEP2[STAGE_T_SIZE] =
{
	_SP1_MID_RIGHT_X_LUT_2,
	_SP1_MID_RIGHT_X_LUT_2,
	_SP1_MID_RIGHT_X_LUT_2,
	_SP1_MID_RIGHT_X_LUT_2,
	_SP1_MID_RIGHT_X_LUT_2,
	_SP1_MID_RIGHT_X_LUT_2,
	_SP1_MID_RIGHT_X_LUT_2,
	_SP1_MID_RIGHT_X_LUT_2,
	_SP1_MID_RIGHT_X_LUT_2,
	_SP1_MID_RIGHT_X_LUT_2,
	_SP1_MID_RIGHT_X_LUT_2
};

const int* const PLAYER_LUT_RIGHT_MID_STEP2[STAGE_T_SIZE] =
{
	_SP1_RIGHT_MID_X_LUT_2,
	_SP1_RIGHT_MID_X_LUT_2,
	_SP1_RIGHT_MID_X_LUT_2,
	_SP1_RIGHT_MID_X_LUT_2,
	_SP1_RIGHT_MID_X_LUT_2,
	_SP1_RIGHT_MID_X_LUT_2,
	_SP1_RIGHT_MID_X_LUT_2,
	_SP1_RIGHT_MID_X_LUT_2,
	_SP1_RIGHT_MID_X_LUT_2,
	_SP1_RIGHT_MID_X_LUT_2,
	_SP1_RIGHT_MID_X_LUT_2
};

const int* const PLAYER_LUT_MID_LEFT_STEP2[STAGE_T_SIZE] =
{
	_SP1_MID_LEFT_X_LUT_2,
	_SP1_MID_LEFT_X_LUT_2,
	_SP1_MID_LEFT_X_LUT_2,
	_SP1_MID_LEFT_X_LUT_2,
	_SP1_MID_LEFT_X_LUT_2,
	_SP1_MID_LEFT_X_LUT_2,
	_SP1_MID_LEFT_X_LUT_2,
	_SP1_MID_LEFT_X_LUT_2,
	_SP1_MID_LEFT_X_LUT_2,
	_SP1_MID_LEFT_X_LUT_2,
	_SP1_MID_LEFT_X_LUT_2
};