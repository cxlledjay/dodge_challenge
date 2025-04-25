// ***************************************************************************
// main
// ***************************************************************************

#include <vectrex.h>
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



const struct packet_t vectors_road_outer_line_l[] =
{
	{DRAW, {-80,-53}},
	VL_END
};

const struct packet_t vectors_road_inner_line_l[] =
{
	{DRAW, {-90,-20}}
	VL_END
};

const struct packet_t vectors_road_inner_line_r[] =
{
	{DRAW, {-90,20}}
	VL_END
};

const struct packet_t vectors_road_outer_line_r[] =
{
	{DRAW, {-80,53}}
	VL_END
};


const struct packet_t vectors_obstacle_truck_s[] =
{
	
};
// ---------------------------------------------------------------------------
// draw objects on screen

void temp_draw(void)
{
	Wait_Recal();					// synchronize frame rate to 50 Hz

	//draw player
	
	
	Intensity_5F();					// set brightness of the electron beam
	Reset0Ref();					// reset beam to center
	dp_VIA_t1_cnt_lo = 0x7f;		// set scaling factor for positioning
	Moveto_d(0, 0);				// move beam to object coordinates
	dp_VIA_t1_cnt_lo = 255;			// set scaling factor for drawing
	Draw_VLp(&vectors_player);			// draw vector list

















	/*
	// draw man
	
	Intensity_5F();					// set brightness of the electron beam
	Reset0Ref();					// reset beam to center
	dp_VIA_t1_cnt_lo = 0x7f;		// set scaling factor for positioning
	Moveto_d(64, -64);				// move beam to object coordinates
	dp_VIA_t1_cnt_lo = 32;			// set scaling factor for drawing
	Draw_VLp(&vectors_man);			// draw vector list

	// draw same man with smaller scale

	Intensity_5F();					// set brightness of the electron beam
	Reset0Ref();					// reset beam to center
	dp_VIA_t1_cnt_lo = 0x7f;		// set scaling factor for positioning
	Moveto_d(64, 0);				// move beam to object coordinates
	dp_VIA_t1_cnt_lo = 16;			// set scaling factor for drawing
	Draw_VLp(&vectors_man);			// draw vector list

	// draw same man with larger scale

	Intensity_5F();					// set brightness of the electron beam
	Reset0Ref();					// reset beam to center
	dp_VIA_t1_cnt_lo = 0x7f;		// set scaling factor for positioning
	Moveto_d(64, 64);				// move beam to object coordinates
	dp_VIA_t1_cnt_lo = 48;			// set scaling factor for drawing
	Draw_VLp(&vectors_man);			// draw vector list

	// draw balloon

	Intensity_5F();					// set brightness of the electron beam
	Reset0Ref();					// reset beam to center
	dp_VIA_t1_cnt_lo = 0x7f;		// set scaling factor for positioning
	Moveto_d(-64, 0);				// move beam to object coordinates
	dp_VIA_t1_cnt_lo = 64;			// set scaling factor for drawing
	Draw_VLp(&vectors_balloon);		// draw vector list
	*/
}

// ***************************************************************************
// end of file
// ***************************************************************************
