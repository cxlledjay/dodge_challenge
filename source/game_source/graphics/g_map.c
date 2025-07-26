#include "game_include/graphics/g_map.h"

// ***************************************************************************
// roadline animation (left)
// ***************************************************************************


/// @brief left roadline animation 1/4
const struct packet_t vl_map_roadline_left_1[] =
{
	{DRAW, {-16,-4}},
	{MOVE, {-28,-7}},
	{DRAW, {-40,-10}},
	{MOVE, {-52,-13}},
	{DRAW, {-64,-16}},
	{MOVE, {-76,-19}},
	{DRAW, {-88,-22}},
	{MOVE, {-100,-25}},
	{DRAW, {-112,-28}},
	{MOVE, {-124,-31}},
	{DRAW, {-68,-17}},
	{DRAW, {-68,-17}},
	{MOVE, {-74,-19}},
	{MOVE, {-74,-18}},
	{DRAW, {-80,-20}},
	{DRAW, {-80,-20}},
	{MOVE, {-86,-22}},
	{MOVE, {-86,-21}},
	{DRAW, {-124,-31}},
	VL_END
};


/// @brief left roadline animation 2/4
const struct packet_t vl_map_roadline_left_2[] =
{
	{MOVE, {-8,-2}},
	{DRAW, {-20,-5}},
	{MOVE, {-36,-9}},
	{DRAW, {-44,-11}},
	{MOVE, {-60,-15}},
	{DRAW, {-68,-17}},
	{MOVE, {-84,-21}},
	{DRAW, {-92,-23}},
	{MOVE, {-108,-27}},
	{DRAW, {-116,-29}},
	{MOVE, {-124,-31}},
	{MOVE, {-8,-2}},
	{DRAW, {-72,-18}},
	{DRAW, {-68,-17}},
	{MOVE, {-82,-21}},
	{MOVE, {-74,-18}},
	{DRAW, {-84,-21}},
	{DRAW, {-80,-20}},
	{MOVE, {-94,-24}},
	{MOVE, {-86,-21}},
	{DRAW, {-124,-31}},
	VL_END
};


/// @brief left roadline animation 3/4
const struct packet_t vl_map_roadline_left_3[] =
{
	{MOVE, {-16,-4}},
	{DRAW, {-28,-7}},
	{MOVE, {-40,-10}},
	{DRAW, {-52,-13}},
	{MOVE, {-64,-16}},
	{DRAW, {-76,-19}},
	{MOVE, {-88,-22}},
	{DRAW, {-100,-25}},
	{MOVE, {-112,-28}},
	{DRAW, {-124,-31}},
	{MOVE, {-124,-31}},
	{MOVE, {-12,-3}},
	{DRAW, {-80,-20}},
	{DRAW, {-68,-17}},
	{MOVE, {-86,-22}},
	{MOVE, {-74,-18}},
	{DRAW, {-92,-23}},
	{DRAW, {-80,-20}},
	VL_END
};


/// @brief left roadline animation 4/4
const struct packet_t vl_map_roadline_left_4[] =
{
	{DRAW, {-8,-2}},
	{MOVE, {-16,-4}},
	{DRAW, {-32,-8}},
	{MOVE, {-48,-12}},
	{DRAW, {-56,-14}},
	{MOVE, {-72,-18}},
	{DRAW, {-80,-20}},
	{MOVE, {-96,-24}},
	{DRAW, {-104,-26}},
	{MOVE, {-120,-30}},
	{DRAW, {-127,-32}},
	{MOVE, {-124,-31}},
	{MOVE, {-20,-5}},
	{DRAW, {-84,-21}},
	{DRAW, {-68,-17}},
	{MOVE, {-94,-24}},
	{MOVE, {-74,-18}},
	{DRAW, {-96,-24}},
	{DRAW, {-80,-20}},
	VL_END
};




// ***************************************************************************
// roadline animation (right)
// ***************************************************************************

/// @brief right roadline animation 1/4
const struct packet_t vl_map_roadline_right_1[] =
{
	{DRAW, {-16,4}},
	{MOVE, {-28,7}},
	{DRAW, {-40,10}},
	{MOVE, {-52,13}},
	{DRAW, {-64,16}},
	{MOVE, {-76,19}},
	{DRAW, {-88,22}},
	{MOVE, {-100,25}},
	{DRAW, {-112,28}},
	{MOVE, {-124,31}},
	{DRAW, {-68,17}},
	{DRAW, {-68,17}},
	{MOVE, {-74,19}},
	{MOVE, {-74,18}},
	{DRAW, {-80,20}},
	{DRAW, {-80,20}},
	{MOVE, {-86,22}},
	{MOVE, {-86,21}},
	{DRAW, {-124,31}},
	VL_END
};


/// @brief right roadline animation 2/4
const struct packet_t vl_map_roadline_right_2[] =
{
	{MOVE, {-8,2}},
	{DRAW, {-20,5}},
	{MOVE, {-36,9}},
	{DRAW, {-44,11}},
	{MOVE, {-60,15}},
	{DRAW, {-68,17}},
	{MOVE, {-84,21}},
	{DRAW, {-92,23}},
	{MOVE, {-108,27}},
	{DRAW, {-116,29}},
	{MOVE, {-124,31}},
	{MOVE, {-8,2}},
	{DRAW, {-72,18}},
	{DRAW, {-68,17}},
	{MOVE, {-82,21}},
	{MOVE, {-74,18}},
	{DRAW, {-84,21}},
	{DRAW, {-80,20}},
	{MOVE, {-94,24}},
	{MOVE, {-86,21}},
	{DRAW, {-124,31}},
	VL_END
};


/// @brief right roadline animation 3/4
const struct packet_t vl_map_roadline_right_3[] =
{
	{MOVE, {-16,4}},
	{DRAW, {-28,7}},
	{MOVE, {-40,10}},
	{DRAW, {-52,13}},
	{MOVE, {-64,16}},
	{DRAW, {-76,19}},
	{MOVE, {-88,22}},
	{DRAW, {-100,25}},
	{MOVE, {-112,28}},
	{DRAW, {-124,31}},
	{MOVE, {-124,31}},
	{MOVE, {-12,3}},
	{DRAW, {-80,20}},
	{DRAW, {-68,17}},
	{MOVE, {-86,22}},
	{MOVE, {-74,18}},
	{DRAW, {-92,23}},
	{DRAW, {-80,20}},
	VL_END
};


/// @brief right roadline animation 4/4
const struct packet_t vl_map_roadline_right_4[] =
{
	{DRAW, {-8,2}},
	{MOVE, {-16,4}},
	{DRAW, {-32,8}},
	{MOVE, {-48,12}},
	{DRAW, {-56,14}},
	{MOVE, {-72,18}},
	{DRAW, {-80,20}},
	{MOVE, {-96,24}},
	{DRAW, {-104,26}},
	{MOVE, {-120,30}},
	{DRAW, {-127,32}},
	{MOVE, {-124,31}},
	{MOVE, {-20,5}},
	{DRAW, {-84,21}},
	{DRAW, {-68,17}},
	{MOVE, {-94,24}},
	{MOVE, {-74,18}},
	{DRAW, {-96,24}},
	{DRAW, {-80,20}},
	VL_END
};
