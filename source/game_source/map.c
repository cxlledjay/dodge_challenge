#include <vectrex.h>
#include "graphics/misc.h"

void draw_road(){		
	Intensity_5F();
	
	//animation recalculation
	calculate_animation();
	
	//left border
	Reset0Ref();
	dp_VIA_t1_cnt_lo = 0x7f;
	Moveto_d(36, -15);
	dp_VIA_t1_cnt_lo = 255;
	Draw_Line_d(-80,-52);
	
	//animate left inner line
	Reset0Ref();
	dp_VIA_t1_cnt_lo = 0x7f;
	if(temp_steps == 2)
	{
		Moveto_d(36, -5);
		Draw_Line_d(-4,-1);
		Moveto_d(-4,-1);
	}
	else
	{
		Moveto_d(36 - ( 4 * temp_steps ), -5 - temp_steps);
	}
	Draw_VLp(&vl_misc_roadline_left);
	
	//animate right inner line
	Reset0Ref();
	dp_VIA_t1_cnt_lo = 0x7f;
	if(temp_steps == 2)
	{
		Moveto_d(36, 5);
		Draw_Line_d(-4,1);
		Moveto_d(-4,1);
	}
	else
	{
		Moveto_d(36 - ( 4 * temp_steps ), 5 + temp_steps);
	}
	Draw_VLp(&vl_misc_roadline_right);
	
	//right border
	Reset0Ref();
	dp_VIA_t1_cnt_lo = 0x7f;
	Moveto_d(36, 15);
	dp_VIA_t1_cnt_lo = 255;
	Draw_Line_d(-80,52);
}
