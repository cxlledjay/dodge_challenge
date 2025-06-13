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
    the_game.stage = 0; ///< ??

    /// trigger all other init routines
    clock_init();
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

//debug
#include "lib/print/print.h"

void game_run(void)
{
    /// sync to 50 fps
    Wait_Recal();
    
    /// ----------------------------------< calculations >----------------------------------

    /// get input
    check_buttons();
    unsigned int input = buttons_pressed();

    /// process input

    /**
     *  BUTTON 1 = ability
     *  BUTTON 2 = go left
     *  BUTTON 3 = go right
     *  BUTTON 4 = use ability
     */

    /** pause */
    if(input & 0b00000001)
    {
        // the_game.execute_state = pause_menu; //< TODO: implement later on

        //debug only
        the_game.stage++;
        return;
    }

    /** ability */
    if(input & 0b00001000)
    {
        /// TODO: trigger ability code
        the_game.stage--;
    }

    /** movment input */
    if((input & 0b00000110) == 0b00000110) //< go left + go right
    {
        ; //< stay in current lane
    }
    else if(input & 0b00000010) //< go left
    {
        /// only allow lange change if there is no active lane change
        if(the_player.tick == player_draw)
        {
            /// start correct animation
            switch(the_player.lane)
            {
                case RIGHT_LANE: //< right -> mid
                    the_player.tick = player_change_right_to_mid_step1;
                    the_player.cnt = PLAYER_ANIMATION_FRAME_CNT_STEP1_LUT[the_game.stage];
                    the_player.x_LUT = PLAYER_LUT_RIGHT_MID_STEP1[the_game.stage];
                    the_player.lane = CHANGE;
                    break;
                case MID_LANE: //< mid -> left
                    the_player.tick = player_change_mid_to_left_step1;
                    the_player.cnt = PLAYER_ANIMATION_FRAME_CNT_STEP1_LUT[the_game.stage];
                    the_player.x_LUT = PLAYER_LUT_MID_LEFT_STEP1[the_game.stage];
                    the_player.lane = CHANGE;
                    break;
                case LEFT_LANE: //< in left lane
                    break; //< cant go further left
                case CHANGE:
                case NA:
                default:
                    /// should never happen!
                    break;
            }
        } 
    }
    else if(input & 0b00000100) //< go right
    {
        /// only allow lange change if there is no active lane change
        if(the_player.tick == player_draw)
        {
            /// start correct animation
            switch(the_player.lane)
            {
                case LEFT_LANE: //< left -> mid
                    the_player.tick = player_change_left_to_mid_step1;
                    the_player.cnt = PLAYER_ANIMATION_FRAME_CNT_STEP1_LUT[the_game.stage];
                    the_player.x_LUT = PLAYER_LUT_LEFT_MID_STEP1[the_game.stage];
                    the_player.lane = CHANGE;
                    break;
                case MID_LANE: //< mid -> right
                    the_player.tick = player_change_mid_to_right_step1;
                    the_player.cnt = PLAYER_ANIMATION_FRAME_CNT_STEP1_LUT[the_game.stage];
                    the_player.x_LUT = PLAYER_LUT_MID_RIGHT_STEP1[the_game.stage];
                    the_player.lane = CHANGE;
                    break;
                case RIGHT_LANE: //< in right lane
                    break; //< cant go further right
                case CHANGE:
                case NA:
                default:
                    /// should never happen!
                    break;
            }
        }
    }
    
    /// call clock update handler
    clock_tick(); //< TODO: handle all things depending on certain clock events (e.g. enemy span?)
    
    /// ----------------------------------< draw screen >----------------------------------
    
    /// draw the road
    the_map.tick();

    /// draw the player & check collisions etc.
    the_player.tick(); //< keep sequence so the game seems more fair!
    
    /// TODO: draw new position of enemies

    /// TODO: draw new position of powerups
    

    /* print_signed_int(100,-20,the_player.x);
    print_unsigned_int(80,-20,the_player.cnt); */

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