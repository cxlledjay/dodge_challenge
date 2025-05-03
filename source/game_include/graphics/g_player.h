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
	{MOVE, {2,-20}},

	//left wheel
	{DRAW, {-20,0}},
	{DRAW, {-6,-4}},
	{DRAW, {0,-20}},
	{DRAW, {6,-4}},
	{DRAW, {20,0}},
	{DRAW, {6,4}},
	{DRAW, {0,20}},
	{DRAW, {-6,4}},

	//backview
	{MOVE, {-2,0}},
	{DRAW, {4,15}},
	{DRAW, {0,10}},
	{DRAW, {-4,15}},

	//right wheel
	{MOVE, {2,0}},
	{DRAW, {-20,0}},
	{DRAW, {-6,-4}},
	{DRAW, {6,-4}},
	{DRAW, {2,0}},

	//back bottom
	{MOVE, {-4,6}},
	{DRAW, {4,-13}},
	{MOVE, {0,15}},
	{DRAW, {0,-40}},
	{MOVE, {0,15}},
	{DRAW, {-4,-16}},

	//left wheel finish
	{MOVE, {-4,-23}},
	{DRAW, {6,4}},
	{DRAW, {20,0}},
	{DRAW, {6,-4}},

	//left front wheel
	{MOVE, {-8,-4}},
	{DRAW, {0,-5}},
	{DRAW, {4,-2}},
	{DRAW, {14,0}},
	{DRAW, {4,2}},
	{DRAW, {-4,2}},
	{DRAW, {-14,0}},
	{DRAW, {-4,-2}},
	{MOVE, {22,0}},
	{DRAW, {0,18}},
	{DRAW, {-4,2}},
	{DRAW, {-10,0}},
	
	//chassis
	{MOVE, {0,5}},
	{DRAW, {7,-5}}, //EDIT 7 is in real 7.5
	{MOVE, {7,-4}},//CARE FOR 7.5 movement (this 7 must be 6.5)
	{DRAW, {10,-7}},

	{MOVE, {-2,2}}, //x only 1.5
	{DRAW, {0,-8}}, //x is 8.5 rather
	{DRAW, {-4,2}},
	{DRAW, {0,8}},
	{MOVE, {6,-4}},
	{DRAW, {0,10}},

	{MOVE, {-2,3}},
	{DRAW, {0,8}},
	{DRAW, {-4,6}},
	{DRAW, {0,-7}},
	{MOVE, {6,-10}},
	{DRAW, {-32,54}},

	//right wheel finish
	{MOVE, {2,0}},
	{DRAW, {6,-4}},
	{DRAW, {-4,-3}},
	{MOVE, {-28,3}},
	{DRAW, {0,20}},
	{DRAW, {6,4}},
	{DRAW, {20,0}},
	{DRAW, {6,-4}},
	{DRAW, {0,-20}},

	//right front wheel
	{MOVE, {-1,-7}},
	{DRAW, {12,0}},
	{DRAW, {4,-2}},
	{DRAW, {0,-18}},
	{DRAW, {-4,2}},
	{DRAW, {-2,0}},
	{MOVE, {6,-2}},
	{DRAW, {-3,-2}},

	//driver
	{MOVE, {-9,5}},
	{DRAW, {6,-11}},
	{DRAW, {0,-7}},
	{DRAW, {-6,4}},

	VL_END
};
