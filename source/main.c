// ***************************************************************************
// main
// ***************************************************************************

#include <vectrex.h>
#include "print/print.h"
#include "temp_draw.h"

#include "utils/controller.h" // buttons input
#include "graphics/player.h"  // player sprites

// ---------------------------------------------------------------------------

#define LEFT_LANE		(0u)
#define MID_LANE		(1u)
#define RIGHT_LANE		(2u)



unsigned int player_lane = MID_LANE;

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

int temp_steps = 0;
unsigned int temp_speed = 10;
unsigned int temp_time = 10;

void calculate_animation()
{
	
	if(temp_time == 0)
	{
		//tracking		
		temp_steps = temp_steps + 1;
		if(temp_steps == 3) temp_steps = 0;
		//and reset
		temp_time = temp_speed;
	}
	else
	{
		temp_time = temp_time - 1;
	}
}



void draw_road(){		
	Intensity_5F();
	
	//animation recalculation
	calculate_animation();
	
	//left border
	Reset0Ref();
	dp_VIA_t1_cnt_lo = 0x7f;
	Moveto_d(36, -15);
	dp_VIA_t1_cnt_lo = 255;
	Draw_Line_d(-80,-52);
	
	//animate left inner line
	Reset0Ref();
	dp_VIA_t1_cnt_lo = 0x7f;
	if(temp_steps == 2)
	{
		Moveto_d(36, -5);
		Draw_Line_d(-4,-1);
		Moveto_d(-4,-1);
	}
	else
	{
		Moveto_d(36 - ( 4 * temp_steps ), -5 - temp_steps);
	}
	Draw_VLp(&vectors_road_inner_line_l);
	
	//animate right inner line
	Reset0Ref();
	dp_VIA_t1_cnt_lo = 0x7f;
	if(temp_steps == 2)
	{
		Moveto_d(36, 5);
		Draw_Line_d(-4,1);
		Moveto_d(-4,1);
	}
	else
	{
		Moveto_d(36 - ( 4 * temp_steps ), 5 + temp_steps);
	}
	Draw_VLp(&vectors_road_inner_line_r);
	
	//right border
	Reset0Ref();
	dp_VIA_t1_cnt_lo = 0x7f;
	Moveto_d(36, 15);
	dp_VIA_t1_cnt_lo = 255;
	Draw_Line_d(-80,52);
}


void draw_debug_car(void)
{
	Reset0Ref();
	dp_VIA_t1_cnt_lo = 0x7f;
	Moveto_d(0, 0);
	
	//scaling
	dp_VIA_t1_cnt_lo = 50 + temp_speed * 10;
	
	Draw_VLp(&vectors_debug_car);
}




const int lookup_player_lane_x_pos[3] =
{
	-71,
	0,
	71
};

__attribute__((noreturn)) void debug_sprites(void)
{
	do
	{
		//draw player		
		Intensity_5F();					// set brightness of the electron beam
		Reset0Ref();					// reset beam to center
		dp_VIA_t1_cnt_lo = 0x7f;		// set scaling factor for positioning
		Moveto_d(0, 0);				// move beam to object coordinates
		dp_VIA_t1_cnt_lo = 255;			// set scaling factor for drawing
		Draw_VLp(&vl_player_mid);			// draw vector list
	}
	while(1);
}

#define DEBUG_SPRITES (1u)

int main(void)
{	
	#if DEBUG_SPRITES
	debug_sprites();
	#else
	do
	{
		Wait_Recal();					// synchronize frame rate to 50 Hz
		
		//build road
		draw_road();
		
		
		//io management
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
			if(temp_speed == 1) temp_speed = 50;
			else temp_speed = temp_speed - 1;
		}
		else if (button_1_4_pressed())
		{
			if(temp_speed == 50) temp_speed = 1;
			else temp_speed = temp_speed + 1;
		}
		
		print_unsigned_int(120,-80,player_lane);
		print_unsigned_int(120,60,temp_speed);
		
		//draw_debug_car();

		//draw player		
		Intensity_5F();					// set brightness of the electron beam
		Reset0Ref();					// reset beam to center
		dp_VIA_t1_cnt_lo = 0x7f;		// set scaling factor for positioning
		Moveto_d(-112, lookup_player_lane_x_pos[player_lane]);				// move beam to object coordinates
		dp_VIA_t1_cnt_lo = 64;			// set scaling factor for drawing
		Draw_VLp(&vectors_player);			// draw vector list
	}
	while(1);
	#endif
}

// ***************************************************************************
// end of file
// ***************************************************************************
