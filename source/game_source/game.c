#include "game_include/game.h"

/*****************************************************************************
 * the game is on...
 ****************************************************************************/
game_t the_game;


#include "game_include/ability.h"
#include "game_include/clock.h"
#include "game_include/enemy.h"
#include "game_include/map.h"
#include "game_include/player.h"

//fw declarations:
void start_menu(void);
void play_start_animation(void);
void pause_menu(void);
void game_run(void);

/*****************************************************************************
 * init part
 ****************************************************************************/

void game_init(void)
{
    /// set game starting values
    the_game.score = 0;
    the_game.speed = 0; ///< ??

    /// trigger all other init routines
    clk_init();
    map_init();
    player_init();
    ability_init();
    enemy_init();

    /// go to select screen
    the_game.execute_state = start_menu;

    /// done
    return;
}



/*****************************************************************************
 * init subroutines
 ****************************************************************************/

void start_menu(void)
{
    //sync to 50 fps
    //get input
    //if settings confirmed -> start animation
    the_game.execute_state = play_start_animation;
    //draw selection screen

    /// done
    return;
}

void play_start_animation(void)
{
    //sync to 50 fps
    //draw screen (based on counter)
    //keep track of animation counter
    //if counter is done -> start game
    the_game.execute_state = game_run;

    /// done
    return;
}




/*****************************************************************************
 * game loop
 ****************************************************************************/

#include "utils/controller.h"


void game_run(void)
{

    /// sync to 50 fps
    Wait_Recal();
    
    /// ----------------------------------< calculations >----------------------------------

    /// get input
    check_buttons();
    unsigned int input = buttons_pressed();

    /// process input
    /** pause */
    if(input & 0b00000001)
    {
        the_game.execute_state = pause_menu;
        return;
    }

    /** ability */
    if(input & 0b00001000)
    {
        /// TODO: trigger ability code
    }

    /** movment input */
    if(input & 0b00000110) //< go left + go right
    {
        ; //< stay in current lane
    }
    else if(input & 0b00000010) //< go left
    {
        the_player.tick = player_change_left;
    }
    else if(input & 0b00000100) //< go right
    {
        the_player.tick = player_change_left;
    }
    
    /// call clock update handler
    clk_update(); //< TODO: handle all things depending on certain clock events (e.g. enemy span?)
    
    /// ----------------------------------< draw screen >----------------------------------
    
    /// draw the road
    the_map.tick();

    /// TODO: draw enemies

    /// TODO: draw powerups

    /// draw the player
    the_player.tick();

    /// done
    return;
}





/*****************************************************************************
 * game loop subroutines
 ****************************************************************************/



void pause_menu(void)
{
    /// TODO: implement!
    return;
}

void game_over(void)
{
    /// TODO: implement!
    return;
}