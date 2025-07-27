#include "game_include/ability.h"
#include "game_include/player.h"
#include "game_include/object.h"


//fw decl
void ability_idle(void){return;}
void _ability_gui_show_extralife (void);
void _ability_gui_show_missile (void);


/****************************************************************
 * interfaces
 ****************************************************************/


ability_manager_t the_ability_manager;

void (* const ABILITY_TICK_FNC[ABILITY_COUNT][3]) (void) =
{
    {
        ability_idle,
        ability_idle,
        ability_idle
    }
};


void ability_init(void)
{
    ability_manager_t new_ability_manager =
    {
        .cnt1 = 0,
        .cnt2 = 0,
        .tick1 = ability_idle,
        .tick2 = ability_idle
    };
    the_ability_manager = new_ability_manager;
}



/****************************************************************
 * gui function
 ****************************************************************/
#include <vectrex.h>
#include "game_include/graphics/g_gui.h"

void ability_draw_gui (void)
{
    /// draw extralife if available
    if(the_player.has_extralife)
    {
        /// draw extralife icon
        Reset0Ref();
        dp_VIA_t1_cnt_lo = 100;
        Moveto_d(127, 106);
        dp_VIA_t1_cnt_lo = 6;
        Draw_VLp(&vl_gui_extralife);
    }
    
    /// then draw ability, relative to extralife (css flexbox principle
    switch (the_player.ability)
    {
        case AC_MISSILE:
        // case AC_...:

            /// draw ability
            if(the_player.has_extralife)
            {
                dp_VIA_t1_cnt_lo = 20;
                Moveto_d(-15, -128);
            }
            else
            {
                Reset0Ref();
                dp_VIA_t1_cnt_lo = 100;
                Moveto_d(127, 106);
            }
            dp_VIA_t1_cnt_lo = 6;
            Draw_VLp((struct packet_t *) vl_gui_ac[the_player.ability]);
            break;

        case AC_NONE:
            /// well just do nothing
        default:
            /// should not happen
            ;
    }

    /// done
    return;
}



 
/****************************************************************
 * ability tick functions
 ****************************************************************/

