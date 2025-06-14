#include <vectrex.h>
#include "game_include/player.h"

typedef struct _aabb_t
{
    int y_top;
    int y_bot;
    int x_left;
    int x_right;
} aabb_t;

void debug_draw_aabb_player(void)
{
    /// calculation part
    aabb_t* bb_main = {0};
    //aabb_t* bb_front;
    //aabb_t* bb_extra_sideview; //< only needed for sideview model

    if(the_player.lane == MID_LANE)
    {
        bb_main->y_top = PLAYER_Y + 10;
        bb_main->y_bot = PLAYER_Y - 6;
        bb_main->x_left = the_player.x - 10;
        bb_main->x_right = the_player.x + 10;
    }
    else //< side lanes
    {
        bb_main->y_top = PLAYER_Y + 10;
        bb_main->y_bot = PLAYER_Y - 6;
        bb_main->x_left = the_player.x - 10;
        bb_main->x_right = the_player.x + 10;
    }

    /// move to player
    Intensity_5F();
    Reset0Ref();					/* reset beam to center	*/
	dp_VIA_t1_cnt_lo = 0x7f;		/* set scaling factor for positioning */
	Moveto_d(PLAYER_Y, the_player.x);					/* move to player pos */
	dp_VIA_t1_cnt_lo = 16;			/* set scaling factor for drawing */

    /// drawing aabb
    Moveto_d(bb_main->y_top, bb_main->x_left);
    Draw_Line_d(0,(bb_main->x_right)-(bb_main->x_left));
    Draw_Line_d((bb_main->y_top)-(bb_main->y_bot),0);
    Draw_Line_d(0,(bb_main->x_left)-(bb_main->x_right));
    Draw_Line_d((bb_main->y_bot)-(bb_main->y_top),0);
}













void collision_check(void)
{
    /// TODO: implement! (ayy)
}