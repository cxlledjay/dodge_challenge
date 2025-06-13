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

void _player_draw_left(void)
{
	Reset0Ref();					//< reset beam to center
	dp_VIA_t1_cnt_lo = 0x7f;		//< set scaling factor for positioning
	/// move to correct lane
	Moveto_d(PLAYER_Y, PLAYER_X_LUT[(unsigned int) the_player.lane]); //< use look up table for performance <insert hacker man meme here>
	dp_VIA_t1_cnt_lo = 10;
	Draw_VLp(&vl_player_left);
}

void _player_draw_mid(void)
{
	/// draw first part
	Reset0Ref();					//< reset beam to center
	dp_VIA_t1_cnt_lo = 0x7f;		//< set scaling factor for positioning
	Moveto_d(PLAYER_Y, PLAYER_X_LUT[(unsigned int) the_player.lane]); //< use look up table for performance <insert hacker man meme here>
	dp_VIA_t1_cnt_lo = 16;			//< set scaling factor for drawing
	Draw_VLp(&vl_player_mid1);

	/// draw second part
	Reset0Ref();
	dp_VIA_t1_cnt_lo = 0x7f;
	Moveto_d(PLAYER_Y, PLAYER_X_LUT[(unsigned int) the_player.lane]);
	dp_VIA_t1_cnt_lo = 16;
	Draw_VLp(&vl_player_mid2_enhanced);
}

void _player_draw_right(void)
{
	Reset0Ref();					//< reset beam to center
	dp_VIA_t1_cnt_lo = 0x7f;		//< set scaling factor for positioning
	/// move to correct lane
	Moveto_d(PLAYER_Y, PLAYER_X_LUT[(unsigned int) the_player.lane]); //< use look up table for performance <insert hacker man meme here>
	dp_VIA_t1_cnt_lo = 10;
	Draw_VLp(&vl_player_right);
}

const _player_draw_func PLAYER_DRAW_LUT[3] = 
{
	_player_draw_left,
	_player_draw_mid,
	_player_draw_right
};
