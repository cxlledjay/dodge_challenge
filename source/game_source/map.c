#include "game_include/map.h"


// one road is enough...
map_t the_map;



void map_init(void)
{
	map_t new_map = {.cnt = 0, .tick = 0};
	the_map = new_map;
}


#if 0
#include <vectrex.h>

#include "game_include/graphics/g_map.h"
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
	dp_VIA_t1_cnt_lo = 168;
	Draw_Line_d(-128,-82);
	

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
	dp_VIA_t1_cnt_lo = 16;
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
	dp_VIA_t1_cnt_lo = 16;
	Draw_VLp(&vl_misc_roadline_right);
	
	//right border
	Reset0Ref();
	dp_VIA_t1_cnt_lo = 0x7f;
	Moveto_d(36, 15);
	dp_VIA_t1_cnt_lo = 168;
	Draw_Line_d(-128,82);
}

#endif