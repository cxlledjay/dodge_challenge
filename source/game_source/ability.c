#include "game_include/ability.h"
#include "game_include/player.h"
#include "game_include/object.h"


//fw decl
void ability_idle(void){return;}


/****************************************************************
 * interfaces
 ****************************************************************/


ability_manager_t the_ability_manager;

void (*ABILITY_TICK_FNC[ABILITY_COUNT][3]) (void) =
{
    {
        ability_idle,
        ability_idle,
        ability_idle
    },
    {
        ability_idle,
        ability_idle,
        ability_idle
    }
};


void (* ABILITY_DRAW_GUI_FNC[ABILITY_COUNT+1]) (void) =
{
    ability_idle,
    ability_idle,
    ability_idle
};


void ability_init(void)
{
    ability_manager_t new_ability_manager = {.cnt1 = 0, .cnt2 = 0, .tick1 = ability_idle, .tick2 = ability_idle, .draw_gui = ability_idle};
    the_ability_manager = new_ability_manager;
}



/****************************************************************
 * gui functions
 ****************************************************************/

 
/****************************************************************
 * ability tick functions
 ****************************************************************/

