#include "game_include/player.h"


// singleplayer
player_t the_player;


// fw declarations:
void check_collision(void);
const int PLAYER_X_LUT[];
typedef void (*_player_draw_func)(void);
const _player_draw_func PLAYER_DRAW_LUT[];


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
	DRAW_PLAYER_VL(PLAYER_Y, PLAYER_X_LUT[(unsigned int) the_player.lane], VECLIST_PTR)





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

 void player_change_left(void)
 {
	if(the_player.lane == LEFT_LANE)
	{
		; //< cannot change lane...
	}
	else
	{
		/// TODO: implement animation
		the_player.lane--;
	}
	
	/// done changing
	the_player.tick = player_draw;
	the_player.tick(); //< temp!
	
	/// dont forget to check for collisions
	check_collision();
	
	/// done
	return;
 }

 void player_change_right(void)
 {
	if(the_player.lane == RIGHT_LANE)
	{
		; //< cannot change lane...
	}
	else
	{
		/// TODO: implement animation
		the_player.lane++;
	}
	
	/// done changing
	the_player.tick = player_draw;
	the_player.tick(); //< temp!
	
	/// dont forget to check for collisions
	check_collision();

	/// done
	return;
 }



 

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
void check_collision(void)
{
	/// TODO: check if bounding box is colliding with objects (enemy / powerup)
}



 
/****************************************************
 * drawing utils 
 ***************************************************/

const int PLAYER_X_LUT[3] =
{
	-82,
	0,
	82
};

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
