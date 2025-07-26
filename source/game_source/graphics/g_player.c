#include "game_include/graphics/g_player.h"

// ***************************************************************************
// mid lane
// ***************************************************************************

/// @brief player mid 1/2
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

/// @brief  player mid 2/2
const struct packet_t vl_player_mid2[] = 
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



// ***************************************************************************
// left lane
// ***************************************************************************

/// @brief player left 1/3
const struct packet_t vl_player_left1[] = 
{
	{MOVE, {8,80}},

	/// left wheel
	{DRAW, {-80,0}},
	{DRAW, {-24,16}},
	{DRAW, {0,80}},
	{DRAW, {24,16}},
	{DRAW, {80,0}},
	{DRAW, {24,-16}},
	{DRAW, {0,-80}},
	{DRAW, {-24,-16}},

	/// backview
	{MOVE, {-8,0}},
	{DRAW, {16,-60}},
	{DRAW, {0,-40}},
	{DRAW, {-16,-60}},

	/// right wheel
	{MOVE, {8,0}},
	{DRAW, {-80,0}},
	{DRAW, {-24,16}},
	{DRAW, {24,16}},
	{DRAW, {8,0}},

	/// back bottom
	{MOVE, {-16,-24}},
	{DRAW, {16,52}},
	{MOVE, {0,-60}},
	{DRAW, {0,80}},
	{DRAW, {0,80}},
	{MOVE, {0,-60}},
	{DRAW, {-16,64}},
	VL_END
};

/// @brief player left 2/3
const struct packet_t vl_player_left2[] = 
{
	/// starting from mid again
	{MOVE, {-48,88}},
	{MOVE, {-48,88}},

	/// left wheel finish
	{DRAW, {24,-16}},
	{DRAW, {80,0}},
	{DRAW, {24,16}},

	/// left front wheel
	{MOVE, {-32,16}},
	{DRAW, {0,20}},
	{DRAW, {16,8}},
	{DRAW, {56,0}},
	{DRAW, {16,-8}},
	{DRAW, {-16,-8}},
	{DRAW, {-56,0}},
	{DRAW, {-16,8}},
	{MOVE, {88,0}},
	{DRAW, {0,-72}},
	{DRAW, {-16,-8}},
	{DRAW, {-40,0}},

	/// chassis
	{MOVE, {0,-20}},
	{DRAW, {28,20}},
	{MOVE, {28,16}},
	{DRAW, {40,28}},
	{DRAW, {0,-40}},
	{DRAW, {-64,-108}},
	{DRAW, {-64,-108}},

	/// front wing
	{MOVE, {52,88}},
	{MOVE, {52,88}},
	{DRAW, {0,-28}},
	{DRAW, {16,24}},
	{DRAW, {0,32}},
	{MOVE, {0,46}},
	{DRAW, {0,32}},
	{DRAW, {-16,-8}},
	{DRAW, {0,-32}},
	VL_END
};

/// @brief player left 3/3
const struct packet_t vl_player_left3[] = 
{
	/// start from mid again
	    {MOVE, {8,-80}},

    /// right wheel finish
    {DRAW, {24,16}},
    {DRAW, {-16,12}},
    {MOVE, {-112,-12}},
    {DRAW, {0,-80}},
    {DRAW, {24,-16}},
    {DRAW, {80,0}},
    {DRAW, {24,16}},
    {DRAW, {0,80}},

    /// right front wheel
    {MOVE, {-4,28}},
    {DRAW, {48,0}},
    {DRAW, {16,8}},
    {DRAW, {0,72}},
    {DRAW, {-16,-8}},
    {DRAW, {-8,0}},
    {MOVE, {24,8}},
    {DRAW, {-12,8}},

    /// driver
    {MOVE, {-36,-20}},
    {DRAW, {24,44}},
    {DRAW, {0,28}},
    {DRAW, {-24,-16}},
    VL_END
};


// ***************************************************************************
// right lane
// ***************************************************************************

/// @brief player right 1/3
const struct packet_t vl_player_right1[] = 
{
	{MOVE, {8,-80}},

	/// left wheel
	{DRAW, {-80,0}},
	{DRAW, {-24,-16}},
	{DRAW, {0,-80}},
	{DRAW, {24,-16}},
	{DRAW, {80,0}},
	{DRAW, {24,16}},
	{DRAW, {0,80}},
	{DRAW, {-24,16}},

	/// backview
	{MOVE, {-8,0}},
	{DRAW, {16,60}},
	{DRAW, {0,40}},
	{DRAW, {-16,60}},

	/// right wheel
	{MOVE, {8,0}},
	{DRAW, {-80,0}},
	{DRAW, {-24,-16}},
	{DRAW, {24,-16}},
	{DRAW, {8,0}},

	/// back bottom
	{MOVE, {-16,24}},
	{DRAW, {16,-52}},
	{MOVE, {0,60}},
	{DRAW, {0,-80}},
	{DRAW, {0,-80}},
	{MOVE, {0,60}},
	{DRAW, {-16,-64}},
	VL_END
};

/// @brief player right 2/3
const struct packet_t vl_player_right2[] = 
{
	/// starting from mid again
	{MOVE, {-48,-88}},
	{MOVE, {-48,-88}},	

	/// left wheel finish
	{DRAW, {24,16}},
	{DRAW, {80,0}},
	{DRAW, {24,-16}},

	/// left front wheel
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

	/// chassis
	{MOVE, {0,20}},
	{DRAW, {28,-20}},
	{MOVE, {28,-16}},
	{DRAW, {40,-28}},
	{DRAW, {0,40}},
	{DRAW, {-64,108}},
	{DRAW, {-64,108}},

	/// front wing
	{MOVE, {52,-88}},
	{MOVE, {52,-88}},
	{DRAW, {0,28}},
	{DRAW, {16,-24}},
	{DRAW, {0,-32}},
	{MOVE, {0,-46}}, //< this one might be off
	{DRAW, {0,-32}},
	{DRAW, {-16,8}},
	{DRAW, {0,32}},
	VL_END
};

/// @brief player right 3/3
const struct packet_t vl_player_right3[] = 
{
	/// start from mid again
	{MOVE, {8,80}},

	/// right wheel finish
	{DRAW, {24,-16}},
	{DRAW, {-16,-12}},
	{MOVE, {-112,12}},
	{DRAW, {0,80}},
	{DRAW, {24,16}},
	{DRAW, {80,0}},
	{DRAW, {24,-16}},
	{DRAW, {0,-80}},

	/// right front wheel
	{MOVE, {-4,-28}},
	{DRAW, {48,0}},
	{DRAW, {16,-8}},
	{DRAW, {0,-72}},
	{DRAW, {-16,8}},
	{DRAW, {-8,0}},
	{MOVE, {24,-8}},
	{DRAW, {-12,-8}},

	/// driver
	{MOVE, {-36,20}},
	{DRAW, {24,-44}},
	{DRAW, {0,-28}},
	{DRAW, {-24,16}},
	VL_END
};
