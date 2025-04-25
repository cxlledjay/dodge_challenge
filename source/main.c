// ***************************************************************************
// main
// ***************************************************************************

#include <vectrex.h>
#include "print/print.h"
#include "temp_draw.h"

#include "utils/controller.h"

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

const int lookup_player_lane_x_pos[3] =
{
	-48,
	0,
	48
};


int main(void)
{	
	
	do
	{
		Wait_Recal();					// synchronize frame rate to 50 Hz
		
		
		check_buttons();
		
		if(button_1_1_pressed())
		{
			change_lane(-1);
		}
		else if(button_1_2_pressed())
		{
			change_lane(1);
		}
		
		print_unsigned_int(120,-80,player_lane);
		
		

		//draw player
		
		
		Intensity_5F();					// set brightness of the electron beam
		Reset0Ref();					// reset beam to center
		dp_VIA_t1_cnt_lo = 0x7f;		// set scaling factor for positioning
		Moveto_d(-64, lookup_player_lane_x_pos[player_lane]);				// move beam to object coordinates
		dp_VIA_t1_cnt_lo = 64;			// set scaling factor for drawing
		Draw_VLp(&vectors_player);			// draw vector list
	}
	while(1);
	
	/*
	do
	{
		Wait_Recal();
		Intensity_5F();
		Print_Str_d(0, -64, "HELLO ROBIN\x80");
	}
	while(1);
	*/
}

// ***************************************************************************
// end of file
// ***************************************************************************
