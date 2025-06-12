#include "game_include/ability.h"

/// TODO: implement! (very far in future...)


ability_t the_ability;






void dummy_tick(void){return;}

/**
 * @brief init function
 */
void ability_init(void)
{
    ability_t new_ability = {.cnt = 0, .type = NONE, .tick = dummy_tick};
    the_ability = new_ability;
}
