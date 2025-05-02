// ***************************************************************************
// main
// ***************************************************************************
#include "temp_draw.h"

//#include <vectrex.h>
#include "utils/vector.h" // provides a C data type for vector lists

// ---------------------------------------------------------------------------
// define a vector list for a simple stick figure

const struct packet_t vectors_man[] =
{
	{MOVE, {  48, -16}},
	{DRAW, {   0,  32}},
	{DRAW, { -32,   0}},
	{DRAW, {   0, -32}},
	{DRAW, {  32,   0}},
	{MOVE, { -32,  16}},
	{DRAW, { -32,   0}},
	{MOVE, {  16, -32}},
	{DRAW, {   0,  64}},
	{MOVE, { -48, -16}},
	{DRAW, {  32, -16}},
	{DRAW, { -32, -16}},
	{STOP, {   0,   0}},
};

// ---------------------------------------------------------------------------
// define a vector list for a simple balloon

const struct packet_t vectors_balloon[] =
{
	{MOVE, { 25,   0}},
	{DRAW, { 50,   0}},
	{DRAW, {  0, -10}},
	{DRAW, { 10,  10}},
	{DRAW, { 10, -20}},
	{DRAW, { 30,   0}},
	{DRAW, { 10,  10}},
	{DRAW, {  0,  20}},
	{DRAW, {-10,  10}},
	{DRAW, {-30,   0}},
	{DRAW, {-10, -20}},
	{DRAW, {-10,  10}},
	{DRAW, {  0, -10}},
	VL_END
};

const struct packet_t vectors_player[] = 
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



const struct packet_t vectors_horizon[] =
{
	{DRAW, {0,127}}
	VL_END
};


const struct packet_t vectors_road_inner_line_l[] =
{
	//{DRAW, {-92,-23}},
	{DRAW, {-4,-1}},
	{MOVE, {-4,-1}},
	{DRAW, {-4,-1}},
	{MOVE, {-4,-1}},
	{DRAW, {-8,-2}},
	{MOVE, {-8,-2}},
	{DRAW, {-8,-2}},
	{MOVE, {-8,-2}},
	{DRAW, {-12,-3}},
	{MOVE, {-12,-3}},
	{DRAW, {-12,-3}},
	{MOVE, {-12,-3}},
	{DRAW, {-16,-4}},
	{MOVE, {-16,-4}},
	{DRAW, {-16,-4}},
	{MOVE, {-16,-4}},
	{DRAW, {-20,-5}},
	VL_END
};

const struct packet_t vectors_road_inner_line_r[] =
{
	{DRAW, {-4,1}},
	{MOVE, {-4,1}},
	{DRAW, {-4,1}},
	{MOVE, {-4,1}},
	{DRAW, {-8,2}},
	{MOVE, {-8,2}},
	{DRAW, {-8,2}},
	{MOVE, {-8,2}},
	{DRAW, {-12,3}},
	{MOVE, {-12,3}},
	{DRAW, {-12,3}},
	{MOVE, {-12,3}},
	{DRAW, {-16,4}},
	{MOVE, {-16,4}},
	{DRAW, {-16,4}},
	{MOVE, {-16,4}},
	{DRAW, {-20,5}},
	VL_END
};


const struct packet_t vectors_debug_car[] =
{
	{MOVE, {8,-6}},
	{DRAW, {-12,0}},
	{DRAW, {0,12}},
	{DRAW, {12,0}},
	{DRAW, {0,-12}},
	VL_END
};




const struct packet_t vectors_obstacle_truck_s[] =
{
	
};


// ***************************************************************************
// end of file
// ***************************************************************************
