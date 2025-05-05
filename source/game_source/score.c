#include "game_include/score.h"
#include <vectrex.h>
#include "game_include/graphics/g_misc.h"
#include "game_include/level.h"

int score[5];

void score_init(void)
{
    score[0] = 0;
    score[1] = 0;
    score[2] = 0;
    score[3] = 0;
    score[4] = 0;
}

const int local_lu_score_addition[] =
{
    1,
    2,
    3,
    4,
    5,
    6,
    7
};

void score_update(void)
{
    int increment = local_lu_score_addition[lvl_speed];
    int h = score[0] + increment;
    if(h < 10)
    {
        score[0] = h;
        return;
    }
    else
    {
        int g = score[1] + h/10; //integer division
        score[0] = h % 10;
        if(g < 10)
        {
            score[1] = g;
            return;
        }
        else
        {
            h = score[2] + g/10;
            score[1] = g % 10;
            if(h < 10)
            {
                score[2] = h;
                return;
            }
            else
            {
                g = score[3] + h/10;
                score[2] = g % 10;
                if(g < 10)
                {
                    score[3] = g;
                    return;
                }
                else
                {
                    //overflow event
                }
            }
        }
    }
}

const int local_lu_speed_digit_1[] =
{
    1,
    1,
    2,
    2,
    3,
    3,
    4
};
const int local_lu_speed_digit_2[] =
{
    0,
    5,
    0,
    5,
    0,
    5,
    0
};


void score_draw(void)
{
		Intensity_5F();					// set brightness of the electron beam
		Reset0Ref();					// reset beam to center
		dp_VIA_t1_cnt_lo = 0x7f;			// set scaling factor for drawing
		Moveto_d(110, -100);				// move beam to object coordinates
		dp_VIA_t1_cnt_lo = 9;			// set scaling factor for drawing
		Draw_VLp((void*)vl_digits[score[3]]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[score[2]]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[score[1]]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[score[0]]);
		Moveto_d(0, 127);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[0]);


		dp_VIA_t1_cnt_lo = 0x42;			// set scaling factor for drawing
		Moveto_d(-44, -127);				// move beam to object coordinates
		dp_VIA_t1_cnt_lo = 6;			// set scaling factor for drawing
		Draw_VLp(&vl_speed_display);
		dp_VIA_t1_cnt_lo = 6;			// set scaling factor for drawing
		Draw_VLp((void*)vl_digits[local_lu_speed_digit_1[lvl_speed]]);
		Moveto_d(-118, 42);				// move beam to object coordinates
		Dot_here();
		Moveto_d(118, 103);				// move beam to object coordinates
		Draw_VLp((void*)vl_digits[local_lu_speed_digit_2[lvl_speed]]);

}