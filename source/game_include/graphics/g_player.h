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


const struct packet_t vl_player_mid1[] = 
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

	/// split
	VL_END
};

#if 0

const struct packet_t vl_player_mid2[] = 
{
	/// starting from mid again
	{MOVE, {0,80}},
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

#endif


const struct packet_t vl_player_mid2_enhanced[] = 
{
	/// starting from mid again
	{MOVE, {32,-120}},
	//front wheel left
	{DRAW, {40,0}},
	{DRAW, {0,60}},
	{DRAW, {-36,0}},
	//chassis
	{MOVE, {-32,-20}},
	{DRAW, {112,64}},
	{DRAW, {0,32}},
	{DRAW, {-112,64}},
	//front wheel right side
	{MOVE, {32,40}},
	{DRAW, {40,0}},
	{DRAW, {0,-60}},
	{DRAW, {-36,0}},
	//front wing right
	{MOVE, {45,-28}}, //< this measurement was taken with one eye closed and pi*thumb
	{DRAW, {0,48}},
	{DRAW, {16,-8}},
	{DRAW, {0,-48}},
	//front wing left
	{MOVE, {0,-48}},
	{DRAW, {0,-48}},
	{DRAW, {-16,-8}},
	{DRAW, {0,48}},
	//driver
	{MOVE, {-28,12}},
	{DRAW, {16,8}},
	{DRAW, {0,24}},
	{DRAW, {-16,8}},
	//done
	VL_END
};



const struct packet_t vl_player_left[] = 
{
	{MOVE, {12,120}},

	//left wheel
	{DRAW, {-120,0}},
	{DRAW, {-36,24}},
	{DRAW, {0,120}},
	{DRAW, {36,24}},
	{DRAW, {120,0}},
	{DRAW, {36,-24}},
	{DRAW, {0,-120}},
	{DRAW, {-36,-24}},

	//backview
	{MOVE, {-12,0}}, //10
	{DRAW, {24,-90}},
	{DRAW, {0,-60}},
	{DRAW, {-24,-90}},

	//right wheel
	{MOVE, {12,0}},
	{DRAW, {-120,0}},
	{DRAW, {-36,24}},
	{DRAW, {36,24}},
	{DRAW, {12,0}},

	//back bottom
	{MOVE, {-24,-36}},
	{DRAW, {24,78}}, //20
	{MOVE, {0,-90}},
	{DRAW, {0,120}},
	{DRAW, {0,120}},
	{MOVE, {0,-90}},
	{DRAW, {-24,96}},

	//left wheel finish
	{MOVE, {-12,69}},
	{MOVE, {-12,69}},
	{DRAW, {36,-24}},
	{DRAW, {120,0}},
	{DRAW, {36,24}}, //30

	//left front wheel
	{MOVE, {-48,24}},
	{DRAW, {0,30}},
	{DRAW, {24,12}},
	{DRAW, {84,0}},
	{DRAW, {24,-12}},
	{DRAW, {-24,-12}},
	{DRAW, {-84,0}},
	{DRAW, {-24,12}},
	{MOVE, {69,0}},
	{MOVE, {69,0}}, //40
	{DRAW, {0,-108}},
	{DRAW, {-24,-12}},
	{DRAW, {-60,0}},

	//chassis
	{MOVE, {0,-30}},
	{DRAW, {42,30}},
	{MOVE, {42,24}},
	{DRAW, {60,42}},

	{MOVE, {-12,-12}},
	{DRAW, {0,48}},
	{DRAW, {-24,-12}}, //50
	{DRAW, {0,-48}},
	{MOVE, {36,24}},
	{DRAW, {0,-60}},

	{MOVE, {-12,-18}},
	{DRAW, {0,-48}},
	{DRAW, {-24,-36}},
	{DRAW, {0,42}},
	{MOVE, {36,60}},
	{DRAW, {-64,-108}},
	{DRAW, {-64,-108}}, //60
	{DRAW, {-64,-108}},

	//right wheel finish
	{MOVE, {12,0}},
	{DRAW, {36,24}},
	{DRAW, {-24,18}},
	{MOVE, {-84,-9}},
	{MOVE, {-84,-9}},
	{DRAW, {0,-120}},
	{DRAW, {36,-24}},
	{DRAW, {120,0}},
	{DRAW, {36,24}}, //70
	{DRAW, {0,120}},

	//right front wheel
	{MOVE, {-6,42}},
	{DRAW, {72,0}},
	{DRAW, {24,12}},
	{DRAW, {0,108}},
	{DRAW, {-24,-12}},
	{DRAW, {-12,0}},
	{MOVE, {36,12}},
	{DRAW, {-18,12}},

	//driver
	{MOVE, {-54,-30}}, //80
	{DRAW, {36,66}},
	{DRAW, {0,42}},
	{DRAW, {-36,-24}},

	VL_END
};



const struct packet_t vl_player_right[] = 
{
	{MOVE, {8,-80}},

	//left wheel
	{DRAW, {-80,0}},
	{DRAW, {-24,-16}},
	{DRAW, {0,-80}},
	{DRAW, {24,-16}},
	{DRAW, {80,0}},
	{DRAW, {24,16}},
	{DRAW, {0,80}},
	{DRAW, {-24,16}},

	//backview
	{MOVE, {-8,0}},
	{DRAW, {16,60}},
	{DRAW, {0,40}},
	{DRAW, {-16,60}},

	//right wheel
	{MOVE, {8,0}},
	{DRAW, {-80,0}},
	{DRAW, {-24,-16}},
	{DRAW, {24,-16}},
	{DRAW, {8,0}},

	//back bottom
	{MOVE, {-16,24}},
	{DRAW, {16,-52}},
	{MOVE, {0,60}},
	{DRAW, {0,-80}},
	{DRAW, {0,-80}},
	{MOVE, {0,60}},
	{DRAW, {-16,-64}},

	//left wheel finish
	{MOVE, {-16,-92}},
	{DRAW, {24,16}},
	{DRAW, {80,0}},
	{DRAW, {24,-16}},

	//left front wheel
	{MOVE, {-32,-16}},
	{DRAW, {0,-20}},
	{DRAW, {16,-8}},
	{DRAW, {56,0}},
	{DRAW, {16,8}},
	{DRAW, {-16,8}},
	{DRAW, {-56,0}},
	{DRAW, {-16,-8}},
	{MOVE, {88,0}},
	{DRAW, {0,72}},
	{DRAW, {-16,8}},
	{DRAW, {-40,0}},

	//chassis
	{MOVE, {0,20}},
	{DRAW, {28,-20}},
	{MOVE, {28,-16}},
	{DRAW, {40,-28}},

	{MOVE, {-8,8}},
	{DRAW, {0,-32}},
	{DRAW, {-16,8}},
	{DRAW, {0,32}},
	{MOVE, {24,-16}},
	{DRAW, {0,40}},

	{MOVE, {-8,12}},
	{DRAW, {0,32}},
	{DRAW, {-16,24}},
	{DRAW, {0,-28}},
	{MOVE, {24,-40}},
	{DRAW, {-64,108}},
	{DRAW, {-64,108}},

	//right wheel finish
	{MOVE, {8,0}},
	{DRAW, {24,-16}},
	{DRAW, {-16,-12}},
	{MOVE, {-112,12}},
	{DRAW, {0,80}},
	{DRAW, {24,16}},
	{DRAW, {80,0}},
	{DRAW, {24,-16}},
	{DRAW, {0,-80}},

	//right front wheel
	{MOVE, {-4,-28}},
	{DRAW, {48,0}},
	{DRAW, {16,-8}},
	{DRAW, {0,-72}},
	{DRAW, {-16,8}},
	{DRAW, {-8,0}},
	{MOVE, {24,-8}},
	{DRAW, {-12,-8}},

	//driver
	{MOVE, {-36,20}},
	{DRAW, {24,-44}},
	{DRAW, {0,-28}},
	{DRAW, {-24,16}},

	VL_END
};
