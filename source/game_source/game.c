#include "game_include/game.h"

/*****************************************************************************
 * the game is on...
 ****************************************************************************/
game_t the_game;


#include "game_include/clock.h"
#include "game_include/map.h"
#include "game_include/player.h"
#include "game_include/object_manager.h"
#include "game_include/collision.h"

//fw declarations:
void start_menu(void);
void play_start_animation(void);
void pause_menu(void);
void game_run(void);

//private types
typedef enum _sm_selection_type_t
{
    SM_LEVEL = 0, //< first option
    SM_START = 1  //< last option
}sm_selection_type_t;

typedef struct _sm_selection_t
{
    sm_selection_type_t type : 7;
    unsigned int is_selected : 1;
}sm_selection_t;

/// datatype for keeping track of start menu selection
sm_selection_t start_menu_selection;


typedef union _menu_selection_t
{
    unsigned int selection;
} menu_selection_t;

/// track other menu selections
menu_selection_t gp_menu;

//macros
#define GAME_PRINT_VERSION()                \
    print_string(-120,-19,"V0.1 - ALPHA\x80");

/*****************************************************************************
 * init part
 ****************************************************************************/


void game_start(void)
{
    /// init menu
    sm_selection_t selection = {.type = SM_LEVEL, .is_selected = 0};
    start_menu_selection = selection;
    the_game.stage = 0;

    /// go to menu
    the_game.execute_state = start_menu;

    /// done
    return;
}


void game_init(void)
{
    /// set game starting values
    the_game.score = 0;
    //the_game.stage = 0; ///< keep the stage (for alpha release) <- later keep the difficulty here
    gp_menu.selection = 0;

    /// trigger all other init routines
    clock_init();
    map_init();
    player_init();
    object_manager_init();
    collision_init();

    /// go directly to run
    the_game.execute_state = play_start_animation;

    /// done
    return;
}



/*****************************************************************************
 * start menu
 ****************************************************************************/


#include "utils/controller.h"
#include "lib/print/print.h"

void start_menu(void)
{
    /// sync to 50 fps
    Wait_Recal();

    /// get input
    check_buttons();
    unsigned int input = buttons_pressed();

    /// process input

    /**
     *  BUTTON 1 = /
     *  BUTTON 2 = prev
     *  BUTTON 3 = next
     *  BUTTON 4 = select
     */

    /* select button */
    if(input & 0b00001000)
    {
        if(start_menu_selection.type == SM_START)
        {
            /// start the game
            the_game.execute_state = game_init;
            return;
        }
        else
        {
            start_menu_selection.is_selected = ++start_menu_selection.is_selected; //< T-FLIPFLOP because of 1 bit long field
        }
    }

    /* next / prev input */
    int delta = 0;
    delta += (int) (input & 0b00000100) >> 2; //< next
    delta -= (int) (input & 0b00000010) >> 1; //< prev

    /* next / prev handler */
    if(start_menu_selection.is_selected)
    {
        /// individual handling for selected type
        int new_stage = (int) the_game.stage;
        switch(start_menu_selection.type)
        {
            case SM_LEVEL:
                /// cycle game stages
                new_stage += delta;

                //check for overflow
                if(new_stage > EXPERT_ONLY)
                {
                    the_game.stage = VERY_SLOW;
                }
                else if(new_stage < VERY_SLOW)
                {
                    the_game.stage = EXPERT_ONLY;
                }
                else
                {
                    the_game.stage = (unsigned int) new_stage;
                }
            break;

            case SM_START:
            default:
                ;
            break;
        }
    }
    else
    {
        /// generic cycling throug menu
        if (delta == 0)
        {
            ; //< no change
        }
        else
        {
            int new_state = (int) start_menu_selection.type;
            new_state += delta;

            //check for overflow
            if(new_state > SM_START)
            {
                start_menu_selection.type = SM_LEVEL;
            }
            else if(new_state < SM_LEVEL)
            {
                start_menu_selection.type = SM_START;
            }
            else
            {
                start_menu_selection.type = (sm_selection_type_t) new_state;
            }
        }
    }

    /// assemble option strings

    /// speed
    char speed_display[16] = " SPEED      XX \x80";

    /// uint to char array
    speed_display[12] = the_game.stage / 10 + '0';
    speed_display[13] = the_game.stage % 10 + '0';

    /// selection
    if(start_menu_selection.type == SM_LEVEL)
    {
        if(start_menu_selection.is_selected)
        {
            speed_display[11] = '<';
            speed_display[14] = '>';
        }
        else
        {
            speed_display[0] = '[';
            speed_display[6] = ']';
        }
    }

    /// start game
    char start_display[9]  = " START \x80";

    /// selection
    if(start_menu_selection.type == SM_START)
    {
        start_display[0] = '[';
        start_display[6] = ']';
    }

    /// highscore
    char highscore_display[19] = "HIGHSCORE: XXXXXX\x80";
    highscore_display[11] = Vec_High_score[0];
    highscore_display[12] = Vec_High_score[1];
    highscore_display[13] = Vec_High_score[2];
    highscore_display[14] = Vec_High_score[3];
    highscore_display[15] = Vec_High_score[4];
    highscore_display[16] = Vec_High_score[5];


    /// print screen
    //GAME_PRINT_VERSION();
    print_string(111,-120,"-------------------\x80");
    print_string(100,-110,highscore_display);
    print_string(89,-120,"-------------------\x80");
    print_string(24,-72,"SELECT MODE\x80");
    print_string(-96,-46,start_display);
    print_string(-10,-91,speed_display);

    /// done
    return;
}



/*****************************************************************************
 * start animation (future feature)
 ****************************************************************************/

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
        /// the_game.execute_state = pause_menu; //< TODO: implement later on
        // return;
        ;
    }

    /** ability */
    if(input & 0b00001000)
    {
        /// TODO: trigger ability code
        ;
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
                    the_player.tick = player_lane_change.animation_tick->right_to_mid;
                    the_player.cnt = player_lane_change.FRAME_CNT[the_game.stage];
                    the_player.x_LUT = player_lane_change.x_LUT->right_to_mid[the_game.stage];
                    break;
                case MID_LANE: //< mid -> left
                    the_player.tick = player_lane_change.animation_tick->mid_to_left;
                    the_player.cnt = player_lane_change.FRAME_CNT[the_game.stage];
                    the_player.x_LUT = player_lane_change.x_LUT->mid_to_left[the_game.stage];
                    break;
                case LEFT_LANE: //< in left lane
                    break; //< cant go further left
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
                    the_player.tick = player_lane_change.animation_tick->left_to_mid;
                    the_player.cnt = player_lane_change.FRAME_CNT[the_game.stage];
                    the_player.x_LUT = player_lane_change.x_LUT->left_to_mid[the_game.stage];
                    break;
                case MID_LANE: //< mid -> right
                    the_player.tick = player_lane_change.animation_tick->mid_to_right;
                    the_player.cnt = player_lane_change.FRAME_CNT[the_game.stage];
                    the_player.x_LUT = player_lane_change.x_LUT->mid_to_right[the_game.stage];
                    break;
                case RIGHT_LANE: //< in right lane
                    break; //< cant go further right
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
    the_player.tick();

    /// draw new position of enemies
    /// draw new position of powerups
    object_manager_tick_all(); //< tick enemies after player for collision-model sync!!!!

    /// spawn new enemies
    object_manager_tick_spawn();


    
    

    /// DEBUG SECTION
    /* print_signed_int(100,-20,the_player.x);
    print_unsigned_int(80,-20,the_player.cnt); */
    //enemy_debug();
    //print_unsigned_int(80,-20,the_manager.remaining_spawns);

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
    /// sync to 50 fps
    Wait_Recal();

    /// TODO: check highscore stuff

    /// get input
    check_buttons();
    unsigned int input = buttons_pressed();

    /// process input

    /**
     *  BUTTON 1 = /
     *  BUTTON 2 = prev
     *  BUTTON 3 = next
     *  BUTTON 4 = select
     * 
     *  selection 0 -> try again
     *  selection 1 -> menu
     */

    /* select */
    if(input & 0b00001000)
    {
        if(gp_menu.selection == 0)
        {
            /// try again
            the_game.execute_state = game_init;
        }
        if(gp_menu.selection == 1)
        {
            /// back to start
            the_game.execute_state = start_menu;
        }
    }

    /* prev / next (hack) */
    if(input & 0b00000110)
    {
        gp_menu.selection = (unsigned int) !gp_menu.selection;
    }

    /// highscore handler
	unsigned int score[7];
	Clear_Score(&score);
	Add_Score_d(the_game.score, &score);
	New_High_Score(&score, (void*) &Vec_High_Score);

    /// assemble strings
    char score_display[19] =     "SCORE:     XXXXXX\x80";
    char highscore_display[19] = "HIGHSCORE: XXXXXX\x80";

    score_display[11] = score[0];
    score_display[12] = score[1];
    score_display[13] = score[2];
    score_display[14] = score[3];
    score_display[15] = score[4];
    score_display[16] = score[5];

    highscore_display[11] = Vec_High_score[0];
    highscore_display[12] = Vec_High_score[1];
    highscore_display[13] = Vec_High_score[2];
    highscore_display[14] = Vec_High_score[3];
    highscore_display[15] = Vec_High_score[4];
    highscore_display[16] = Vec_High_score[5];


    char retry_display[13] =   " TRY AGAIN \x80";
    char start_display[17] = " BACK TO START \x80";

    switch(gp_menu.selection)
    {
        case 0:
            retry_display[0] = '[';
            retry_display[10] = ']';
            break;
        case 1:
            start_display[0] = '[';
            start_display[14] = ']';
            break;
        default:
            break;
    }


    /// draw game over screen
    print_string(100,-85,"-=GAME OVER=-\x80");

    print_string(10,-110, score_display);
    print_string(-10,-110, highscore_display);

    print_string(-90,-72, retry_display);
    print_string(-110,-94,start_display);

    return;
}