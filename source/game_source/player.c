#include "map.h"

unsigned int player_lane = MID_LANE;

const int lookup_player_lane_x_pos[3] =
{
	-71,
	0,
	71
};

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