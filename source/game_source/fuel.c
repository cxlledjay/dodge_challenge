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

const unsigned int _FUEL_BAR_INTERVAL_LUT[STAGE_T_SIZE] = {
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

#include "game_include/graphics/g_gui.h"
#include "game_include/sounds/s_animation.h"
#include "game_include/graphics/g_object.h"

void fuel_bar_tick (void)
{
    FUELBAR_DRAW(the_player.fuel);

    /// tick
    if(--(the_fuel_bar.cnt) == 0)
    {
        /// decrease fuel
        if( --(the_player.fuel) == 0)
        {
            /// no fuel -> game over

            /// state reason for game over
            the_game.reason = 0x01; //< no fuel
            
            /// play sad sound
            Clear_Sound();
            play_music(&game_over_sad);
            
            /// play sad sound
            play_music(&game_over_sad);

            /// highscore handler
            New_High_Score(the_game.score, (void*) &Vec_High_Score);

            /// game over
            the_game.execute_state = game_over;

            /// init game over screen
            the_game.cnt = 20;
            the_game.play_animation = (void *) &vl_exploded[0];
        }

        /// reset timer accordingly
        the_fuel_bar.cnt = _FUEL_BAR_INTERVAL_LUT[the_game.stage];
    }

    /// done
    return;
}
