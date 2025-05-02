// ***************************************************************************
// graphics/player.c
//
// all vector lists to draw the player
// ***************************************************************************

#include "utils/vector.h"


const struct packet_t vl_player_mid[] = 
{
	{MOVE, {-24,-20}}, //move to left back wheel
	
	//wheel1
	{DRAW, {0,-20}},
	{DRAW, {32,0}},
	{DRAW, {0,20}},
	{DRAW, {-32,0}},
	//axles
	{MOVE, {4,0}},
	{DRAW, {4,15}},
	{MOVE, {0,10}},
	{DRAW, {-4,15}},
	{MOVE, {-4,0}},
	//wheel2
	{DRAW, {0,20}},
	{DRAW, {32,0}},
	{DRAW, {0,-20}},
	{DRAW, {-32,0}},
	//back
	{MOVE, {8,0}},
	{DRAW, {0,-40}},
	{MOVE, {16,0}},
	//back top (angles like axle)
	{DRAW, {4,15}},
	{DRAW, {0,10}},
	{DRAW, {-4,15}},
	//chassis
	{DRAW, {28,-16}},
	{DRAW, {0,-8}},
	//front wing right
	{MOVE, {-7,12}},
	{DRAW, {0,12}},
	{DRAW, {4,-2}},
	{DRAW, {0,-12}},
	//front wing left
	{MOVE, {0,-12}},
	{DRAW, {0,-12}},
	{DRAW, {-4,-2}},
	{DRAW, {0,12}},
	//continue chassis
	{MOVE, {7,4}},
	{DRAW, {-28,-16}},
	//front wheel left
	{MOVE, {8,-10}},
	{DRAW, {10,0}},
	{DRAW, {0,15}},
	{DRAW, {-9,0}},
	//front wheel right side
	{MOVE, {0,30}},
	{DRAW, {9,0}},
	{DRAW, {0,15}},
	{DRAW, {-10,0}},
	//driver
	{MOVE, {5,-25}},
	{DRAW, {4,-2}},
	{DRAW, {0,-6}},
	{DRAW, {-4,-2}},
	//done
	VL_END
};




const struct packet_t vl_player_right[] = 
{
	{MOVE, {-24,-20}}, //move to left back wheel
	
	VL_END
};
