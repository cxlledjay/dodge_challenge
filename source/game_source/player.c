#include "game_include/player.h"

#include <vectrex.h>
#include "utils/controller.h"
#include "utils/vector.h"

#include "game_include/map.h"
#include "game_include/level.h"
#include "game_include/graphics/g_player.h"

//**************************************************
// tracking
//**************************************************
unsigned int player_lane;


void player_init(void)
{
	player_lane = MID_LANE;
}

//**************************************************
// handle input
//**************************************************


// input direction := -1 or 1
// -1 : to the left
// 1 to the right
void change_lane(int direction)
{
	if(direction == 1) //to the right
	{
		if(player_lane == RIGHT_LANE)
		{
			return; //can't go further
		}
		player_lane = player_lane + 1;
	}
	else if(direction == -1)
	{
		if(player_lane == LEFT_LANE)
		{
			return; //can't go further
		}
		player_lane = player_lane - 1;
	}
}


void player_handle_input(void)
{
	check_buttons();
	if(button_1_1_pressed())
	{
		change_lane(-1);
	}
	else if(button_1_3_pressed())
	{
		change_lane(1);
	}

	
	//debug
	if(button_1_2_pressed())
	{
		if(lvl_speed != 0) lvl_speed = lvl_speed - 1;
	}
	else if (button_1_4_pressed())
	{
		if(lvl_speed != LVL_MAX_SPEED) lvl_speed = lvl_speed + 1;
	}
}


//**************************************************
// draw player
//**************************************************

const int local_lu_player_x_pos[3] =
{
	-71,
	0,
	71
};


void local_player_draw_left(void)
{
	Draw_VLp(&vl_player_left);
}

void local_player_draw_mid(void)
{
	Draw_VLp(&vl_player_mid);
}

void local_player_draw_right(void)
{
	Draw_VLp(&vl_player_right);
}


typedef void (*local_player_draw_func)(void);
const local_player_draw_func local_lu_player_draw_func_ptr[3] = 
{
	local_player_draw_left,
	local_player_draw_mid,
	local_player_draw_right
};



void player_draw(void)
{
	//draw player		
	Intensity_5F();					// set brightness of the electron beam
	Reset0Ref();					// reset beam to center
	dp_VIA_t1_cnt_lo = 0x7f;		// set scaling factor for positioning
	Moveto_d(-112, local_lu_player_x_pos[player_lane]);				// move beam to object coordinates
	dp_VIA_t1_cnt_lo = 16;
	(* local_lu_player_draw_func_ptr[player_lane])();		// draw vector list
}
