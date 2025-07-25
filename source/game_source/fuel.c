#include "game_include/fuel.h"
#include "game_include/player.h"
#include "game_include/game.h"
#include <vectrex.h>


/************************************************************
 * management object
 ************************************************************/

typedef struct _fuel_bar_t {
    unsigned int cnt;
} fuel_bar_t;

fuel_bar_t the_fuel_bar;


/************************************************************
 * LUT for fuel depletion per stage
 ************************************************************/

unsigned int _FUEL_BAR_INTERVAL_LUT[STAGE_T_SIZE] = {
    40,37,34,31,27,24,21,19,17,15,11
};




/************************************************************
 * init function
 ************************************************************/

void fuel_bar_init (void)
{
    the_fuel_bar.cnt = _FUEL_BAR_INTERVAL_LUT[the_game.stage];
}



/************************************************************
 * management object
 ************************************************************/

void fuel_bar_tick (void)
{
    /// draw fuel bar
    Reset0Ref();

    /// TODO: add fuel icon

    /// draw actual fuel bar
	dp_VIA_t1_cnt_lo = 0x7f;
	Moveto_d(116, -100);
	dp_VIA_t1_cnt_lo = the_player.fuel;
	Draw_Line_d(0,127);
	dp_VIA_t1_cnt_lo = 0x1;
	Draw_Line_d(-127, 0);
	dp_VIA_t1_cnt_lo = the_player.fuel;
	Draw_Line_d(0,-127);
	dp_VIA_t1_cnt_lo = 0x1;
	Draw_Line_d(127, 0);

    /// tick
    if(--(the_fuel_bar.cnt) == 0)
    {
        /// decrease fuel
        if( --(the_player.fuel) == 0)
        {
            /// no fuel -> game over
            the_game.execute_state = game_over;
        }

        /// reset timer accordingly
        the_fuel_bar.cnt = _FUEL_BAR_INTERVAL_LUT[the_game.stage];
    }

    /// done
    return;
}
