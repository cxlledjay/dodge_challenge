#include "game_include/map.h"

#include <vectrex.h>

#include "game_include/graphics/misc.h"
#include "game_include/level.h"

int local_cnt = 0;
int animation_step = 0; // can be 0, 1, 2

void map_draw_road(){

	Intensity_5F();


	//left border
	Reset0Ref();
	dp_VIA_t1_cnt_lo = 0x7f;
	Moveto_d(36, -15);
	dp_VIA_t1_cnt_lo = 255;
	Draw_Line_d(-80,-52);
	
	//calculate animation
	int cnt_limiter = LVL_MAX_SPEED - lvl_speed; //cnt_limiter = {0,...,MAX_SPEED-1}

	//clock animation
	if(local_cnt == cnt_limiter)
	{
		if(animation_step == 2)
		{
			animation_step = 0;
		}
		else
		{
			animation_step = animation_step + 1;
		}
		local_cnt = 0;
	}
	else
	{
		local_cnt = local_cnt + 1;
	}

	//animation of inner lines
	Reset0Ref();
	dp_VIA_t1_cnt_lo = 0x7f;
	if(animation_step == 2)
	{
		Moveto_d(36, -5);
		Draw_Line_d(-4,-1);
		Moveto_d(-4,-1);
	}
	else
	{
		Moveto_d(36 - ( 4 * animation_step ), -5 - animation_step);
	}
	Draw_VLp(&vl_misc_roadline_left);
	
	//animate right inner line
	Reset0Ref();
	dp_VIA_t1_cnt_lo = 0x7f;
	if(animation_step == 2)
	{
		Moveto_d(36, 5);
		Draw_Line_d(-4,1);
		Moveto_d(-4,1);
	}
	else
	{
		Moveto_d(36 - ( 4 * animation_step ), 5 + animation_step);
	}
	Draw_VLp(&vl_misc_roadline_right);
	
	//right border
	Reset0Ref();
	dp_VIA_t1_cnt_lo = 0x7f;
	Moveto_d(36, 15);
	dp_VIA_t1_cnt_lo = 255;
	Draw_Line_d(-80,52);
}
