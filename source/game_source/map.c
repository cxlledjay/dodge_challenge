#include "game_include/map.h"

#include <vectrex.h>

#include "game_include/graphics/g_misc.h"
#include "game_include/level.h"
#include "game_include/clock.h"

const unsigned int local_lu_animation_interval[] =
{
	93,
	81,
	69,
	58,
	49,
	42,
	34
};

int animation_step;

void map_init(void)
{
	animation_step = 0;
}

void map_calculate_animation(void)
{
	unsigned int animation_step_ui = (clk_frames / (local_lu_animation_interval[lvl_speed]/3)) % 3;
	animation_step = (int) animation_step_ui;
}


void map_draw_road(void){

	Intensity_5F();


	//left border
	Reset0Ref();
	dp_VIA_t1_cnt_lo = 0x7f;
	Moveto_d(36, -15);
	dp_VIA_t1_cnt_lo = 255;
	Draw_Line_d(-80,-52);
	

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
