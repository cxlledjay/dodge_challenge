// ***************************************************************************
// graphics/g_player.h
//
// all vector lists to draw the player
// ***************************************************************************
#pragma once

#include "utils/vector.h"

// ***************************************************************************
// vector list pointer to different perspectives of player model
// ***************************************************************************


const struct packet_t vl_player_mid[] = 
{
	{MOVE, {-96,-80}}, //move to left back wheel
	
	//wheel1
	{DRAW, {0,-80}},
	{DRAW, {127,0}},
	{DRAW, {0,80}},
	{DRAW, {-128,0}},
	//axles
	{MOVE, {16,0}},
	{DRAW, {16,60}},
	{MOVE, {0,40}},
	{DRAW, {-16,60}},
	{MOVE, {-16,0}},
	//wheel2
	{DRAW, {0,80}},
	{DRAW, {127,0}},
	{DRAW, {0,-80}},
	{DRAW, {-128,0}},
	//back
	{MOVE, {32,0}},
	{DRAW, {0,-80}},
	{DRAW, {0,-80}},
	{MOVE, {64,0}},
	//back top (angles like axle)
	{DRAW, {16,60}},
	{DRAW, {0,40}},
	{DRAW, {-16,60}},
	//chassis
	{DRAW, {112,-64}},
	{DRAW, {0,-32}},
	//front wing right
	{MOVE, {-28,48}},
	{DRAW, {0,48}},
	{DRAW, {16,-8}},
	{DRAW, {0,-48}},
	//front wing left
	{MOVE, {0,-48}},
	{DRAW, {0,-48}},
	{DRAW, {-16,-8}},
	{DRAW, {0,48}},
	//continue chassis
	{MOVE, {28,16}},
	{DRAW, {-112,-64}},
	//front wheel left
	{MOVE, {32,-40}},
	{DRAW, {40,0}},
	{DRAW, {0,60}},
	{DRAW, {-36,0}},
	//front wheel right side
	{MOVE, {0,120}},
	{DRAW, {36,0}},
	{DRAW, {0,60}},
	{DRAW, {-40,0}},
	//driver
	{MOVE, {20,-100}},
	{DRAW, {16,-8}},
	{DRAW, {0,-24}},
	{DRAW, {-16,-8}},
	//done
	VL_END
};



const struct packet_t vl_player_left[] = 
{
	
};



const struct packet_t vl_player_right[] = 
{
	
};
