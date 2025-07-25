#include "game_include/map.h"


// one road is enough...
map_t the_map;

// fw declarations:
void draw_step1(void);
void draw_step2(void);
void draw_step3(void);
void draw_step4(void);
const unsigned int CNT_DRAW1_LUT[];
const unsigned int CNT_DRAW2_LUT[];
const unsigned int CNT_DRAW3_LUT[];
const unsigned int CNT_DRAW4_LUT[];



#include "game_include/game.h"

// init func
void map_init(void)
{
	map_t new_map = {.cnt = CNT_DRAW1_LUT[the_game.stage], .tick = draw_step1};
	the_map = new_map;
	return;
}



/****************************************************
 * macro utils 
 ***************************************************/

#define DRAW_LEFT() 				\
	Reset0Ref(); 					\
	dp_VIA_t1_cnt_lo = 0x7f;		\
	Moveto_d(36, -15);				\
	dp_VIA_t1_cnt_lo = 187;			\
	Draw_Line_d(-128,-82);	
	
#define DRAW_RIGHT() 				\
	Reset0Ref(); 					\
	dp_VIA_t1_cnt_lo = 0x7f;		\
	Moveto_d(36, 15);				\
	dp_VIA_t1_cnt_lo = 187;			\
	Draw_Line_d(-128,82);

#define ANIMATE_LEFT(VECLIST_PTR) 	\
	Reset0Ref();					\
	dp_VIA_t1_cnt_lo = 0x7f;		\
	Moveto_d(36, -5);				\
	dp_VIA_t1_cnt_lo = 16;			\
	Draw_VLp(VECLIST_PTR);	
	
#define ANIMATE_RIGHT(VECLIST_PTR) 	\
	Reset0Ref();					\
	dp_VIA_t1_cnt_lo = 0x7f;		\
	Moveto_d(36, 5);				\
	dp_VIA_t1_cnt_lo = 16;			\
	Draw_VLp(VECLIST_PTR);	



/****************************************************
 * tick functions 
 ***************************************************/

#include <vectrex.h>
#include "game_include/graphics/g_map.h"
#include "game_include/game.h"

void draw_step1(void)
{	
	/// left roadlines
	DRAW_LEFT();
	ANIMATE_LEFT(&vl_map_roadline_left_1);

	/// right roadlines
	ANIMATE_RIGHT(&vl_map_roadline_right_1);
	DRAW_RIGHT();

	/// check for state transition
	if(the_map.cnt == 0)
	{
		/// go to next animation
		the_map.tick = draw_step2;

		/// set animation time according to current stage
		the_map.cnt = CNT_DRAW2_LUT[the_game.stage];
	}
	else
	{
		the_map.cnt--;
	}
}

void draw_step2(void)
{
	
	/// left roadlines
	DRAW_LEFT();
	ANIMATE_LEFT(&vl_map_roadline_left_2);

	/// right roadlines
	ANIMATE_RIGHT(&vl_map_roadline_right_2);
	DRAW_RIGHT();

	/// check for state transition
	if(the_map.cnt == 0)
	{
		/// go to next animation
		the_map.tick = draw_step3;

		/// set animation time according to current stage
		the_map.cnt = CNT_DRAW3_LUT[the_game.stage];
	}
	else
	{
		the_map.cnt--;
	}
}

void draw_step3(void)
{
	
	/// left roadlines
	DRAW_LEFT();
	ANIMATE_LEFT(&vl_map_roadline_left_3);

	/// right roadlines
	ANIMATE_RIGHT(&vl_map_roadline_right_3);
	DRAW_RIGHT();

	/// check for state transition
	if(the_map.cnt == 0)
	{
		/// go to next animation
		the_map.tick = draw_step4;

		/// set animation time according to current stage
		the_map.cnt = CNT_DRAW4_LUT[the_game.stage];
	}
	else
	{
		the_map.cnt--;
	}
}

void draw_step4(void)
{	
	/// left roadlines
	DRAW_LEFT();
	ANIMATE_LEFT(&vl_map_roadline_left_4);

	/// right roadlines
	ANIMATE_RIGHT(&vl_map_roadline_right_4);
	DRAW_RIGHT();

	/// check for state transition
	if(the_map.cnt == 0)
	{
		/// go to next animation
		the_map.tick = draw_step1;

		/// set animation time according to current stage
		the_map.cnt = CNT_DRAW1_LUT[the_game.stage];
	}
	else
	{
		the_map.cnt--;
	}
}




/****************************************************
 * LUTs 
 ***************************************************/

 const unsigned int CNT_DRAW1_LUT[STAGE_T_SIZE] =
 {
	6,
	5,
	4,
	4,
	3,
	2,
	2,
	2,
	1,
	1,
	0
 };
 
 const unsigned int CNT_DRAW2_LUT[STAGE_T_SIZE] =
 {
	6,
	5,
	4,
	3,
	2,
	2,
	2,
	1,
	1,
	0,
	0
 };
 
 const unsigned int CNT_DRAW3_LUT[STAGE_T_SIZE] =
 {
	6,
	5,
	4,
	3,
	3,
	2,
	1,
	2,
	1,
	1,
	0
 };
 
 const unsigned int CNT_DRAW4_LUT[STAGE_T_SIZE] =
 {
	6,
	5,
	4,
	3,
	2,
	2,
	2,
	1,
	1,
	0,
	0
 };
 

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