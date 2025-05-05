#include "game_include/score.h"
#include <vectrex.h>
#include "game_include/graphics/g_misc.h"

long int score;

void score_init(void)
{
    score = 0;
}

void score_update(void)
{
    score = score + 1;
}


void score_draw(void)
{
		Intensity_5F();					// set brightness of the electron beam
		Reset0Ref();					// reset beam to center
		dp_VIA_t1_cnt_lo = 0x7f;			// set scaling factor for drawing
		Moveto_d(110, -100);				// move beam to object coordinates
		dp_VIA_t1_cnt_lo = 9;			// set scaling factor for drawing
		Draw_VLp((void*)vl_digits[0]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[0]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[0]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[0]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[0]);


		dp_VIA_t1_cnt_lo = 0x42;			// set scaling factor for drawing
		Moveto_d(-44, -127);				// move beam to object coordinates
		dp_VIA_t1_cnt_lo = 6;			// set scaling factor for drawing
		Draw_VLp(&vl_speed_display);
		dp_VIA_t1_cnt_lo = 6;			// set scaling factor for drawing
		Draw_VLp((void*)vl_digits[2]);
		Moveto_d(-118, 24);				// move beam to object coordinates
		Dot_here();
		Moveto_d(118, 103);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[5]);

}