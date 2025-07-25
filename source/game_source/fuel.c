#include "game_include/fuel.h"
#include "game_include/player.h"
#include "game_include/game.h"
#include <vectrex.h>

void fuel_bar_draw (void)
{
    Reset0Ref();

    /// TODO: add fuel icon

    /// draw actual fuel bar
	dp_VIA_t1_cnt_lo = 0x7f;
	Moveto_d(116, -100);
	dp_VIA_t1_cnt_lo = the_player.fuel;
	Draw_Line_d(0,127);
	dp_VIA_t1_cnt_lo = 0x1;
	Moveto_d(-128, 0);
	dp_VIA_t1_cnt_lo = the_player.fuel;
	Draw_Line_d(0,-127);

    /// done
    return;
}


void fuel_bar_dec (void)
{
    if( --(the_player.fuel) == 0)
    {
        the_game.execute_state = game_over;
    }

    /// done
    return;
}