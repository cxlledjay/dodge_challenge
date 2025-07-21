#include "game_include/game.h"

/*****************************************************************************
 * the game is on...
 ****************************************************************************/
game_t the_game;


#include "game_include/stage_manager.h"
#include "game_include/map.h"
#include "game_include/player.h"
#include "game_include/object_manager.h"
#include "game_include/collision.h"
#include "utils/controller.h"

//fw declarations:

/* execute functions */
void start_menu(void);
void play_start_animation(void);
void game_run(void);

/* process input function */
void input_1_4(void);
void input_2_3(void);
void input_analog(void);

/*****************************************************************************
 * init part
 ****************************************************************************/


void game_start(void)
{
    /// init the game (main handler)
    game_options_t start_selection = {.game_mode = GAME_MODE_EASY, .input_method = INPUT_METHOD_ANALOG};
    game_t new_game = {
        .options = start_selection,
        .score = 0,
        .stage = 0,
        .cnt = 0,
        .process_input = input_1_4,
        .execute_state = start_menu
    };

    the_game = new_game;

    /// init controller
    disable_controller_1_x();
    disable_controller_1_y();
    disable_controller_2_x();
    disable_controller_2_y();

    /// done
    return;
}

#include "lib/sound/sound.h"
void game_init(void)
{
    /// trigger all init routines
    object_manager_init(); //< init first for random seed to use past values in ram
    
    stage_manager_init();
    map_init();
    player_init();
    collision_init();

    /// score reset
    the_game.score = 0;

    /// init stage according to game mode
    switch (the_game.options.game_mode) {
		case GAME_MODE_EASY:
            the_game.stage = GS_VERY_SLOW;
            break;
		case GAME_MODE_MID:
            the_game.stage = GS_SLOW;
            break;
		case GAME_MODE_HARD:
            the_game.stage = GS_NORMAL;
            break;
		case GAME_MODE_HIDDEN:
            the_game.stage = GS_HIDDEN;
            break;
		default:
            // should never happen
            the_game.execute_state = game_start; //< reset
	}

    /// go directly to run depending on input method
    switch (the_game.options.input_method) {
        case INPUT_METHOD_1_4:
            disable_controller_1_x();
            the_game.process_input = input_1_4;
            break;
        case INPUT_METHOD_2_3:
            disable_controller_1_x();
            the_game.process_input = input_2_3;
            break;
        case INPUT_METHOD_ANALOG:
            enable_controller_1_x();
            the_game.process_input = input_analog;
            break;
        default:
            // should never happen
            the_game.execute_state = game_start; //< reset
    }

    /// start game w/animation
    the_game.cnt = 200; //< 3 seconds countdown + 1 second "GO"
    the_game.execute_state = play_start_animation;

    /// init sound module
    sound_init();

    /// done
    return;
}



/*****************************************************************************
 * start menu
 ****************************************************************************/


#include "utils/controller.h"
#include "lib/print/print.h"

/// menu display LUTs
const char * const _GAME_INPUT_DISPLAY_LUT[3] = {
    "[1] INPUT BUTTON 1/4\x80",
    "[1] INPUT BUTTON 2/3\x80",
    "[1] INPUT ANALOG    \x80"
};
const char * const _GAME_MODE_DISPLAY_LUT[4] = {
    "[2] MODE  EASY\x80",
    "[2] MODE  MID \x80",
    "[2] MODE  HARD\x80",
    "[2] MODE  #!?-\x80"
};

void start_menu(void) {
    
    /// sync to 50 fps
    Wait_Recal();

    /// get input
    check_buttons();
    unsigned int input = buttons_pressed();

    /// process input
    /**
     *  BUTTON 1 = input: 1/4, 2/3, joy
     *  BUTTON 2 = mode: easy, mid, hard
     *  BUTTON 3 = reset highscore
     *  BUTTON 4 = play
     */

    if(input & 0b00001000) //< BUTTON 4
    {
        /// directly start the game with current settings
        the_game.execute_state = game_init;
        return;
    }

    if(input & 0b00000100) //< BUTTON 3
    {
        /// reset highscore
        Clear_Score(&Vec_High_Score);
    }

    if(input & 0b00000010) //< BUTTON 2
    {
        if(the_game.options.game_mode == GAME_MODE_HARD) {
            the_game.options.game_mode = GAME_MODE_EASY;
        } else {
            the_game.options.game_mode++;
        }
    }

    if(input & 0b00000001) //< BUTTON 1
    {
        if(the_game.options.input_method == INPUT_METHOD_ANALOG) {
            the_game.options.input_method = INPUT_METHOD_1_4;
        } else {
            the_game.options.input_method++;
        }        
    }



    /// assemble strings for menu
    char highscore_display[14] = "BEST: XXXXXX\x80";
    highscore_display[6] = Vec_High_score[0];
    highscore_display[7] = Vec_High_score[1];
    highscore_display[8] = Vec_High_score[2];
    highscore_display[9] = Vec_High_score[3];
    highscore_display[10] = Vec_High_score[4];
    highscore_display[11] = Vec_High_score[5];

    /// print the menu
    print_string(110,-90,highscore_display); //< maybe add some graphic to start menu as well?
    print_string(50,-91, "SELECT OPTIONS\x80");
    print_string(20,-120, (char *) _GAME_INPUT_DISPLAY_LUT[the_game.options.input_method]);
    print_string(-10,-120, (char *) _GAME_MODE_DISPLAY_LUT[the_game.options.game_mode]);
    print_string(-40,-120, "[3] RESET HIGHSCORE\x80");
    print_string(-100,-58, "[4] START\x80");
}


/*****************************************************************************
 * input methods (chosen by start menu)
 ****************************************************************************/

#include "utils/controller.h"
#include "game_include/gen_data/gen_player_lanechange.h"
void input_1_4 (void)
{
    /// get input
    check_buttons();
    unsigned int input = buttons_pressed();

    /// process input
    /**
     *  BUTTON 1 = go left
     *  BUTTON 2 = use ability
     *  BUTTON 3 = use ability
     *  BUTTON 4 = go right
     */

    /** ability */
    if(input & 0b00000110)
    {
        /// TODO: trigger ability code
        ;
    }

    /** movment input */
    if(input & 0b00000001) //< go left
    {
        /// only initiate lange change if there is no active lane change
        if(the_player.tick == player_draw)
        {
            /// start correct animation
            switch(the_player.lane)
            {
                case RIGHT_LANE: //< right -> mid
                    the_player.tick = player_lane_change_phase1.animation_tick->right_to_mid;
                    the_player.cnt = player_lane_change_phase1.FRAME_CNT[the_game.stage];
                    the_player.x_LUT = player_lane_change_phase1.x_LUT.right_to_mid[the_game.stage];
                    break;
                case MID_LANE: //< mid -> left
                    the_player.tick = player_lane_change_phase1.animation_tick->mid_to_left;
                    the_player.cnt = player_lane_change_phase1.FRAME_CNT[the_game.stage];
                    the_player.x_LUT = player_lane_change_phase1.x_LUT.mid_to_left[the_game.stage];
                    break;
                case LEFT_LANE: //< in left lane
                    break; //< cant go further left
                default:
                    /// should never happen!
                    break;
            }
        }
        else
        {
            /// there is a lane change ongoing, so we are queuing the input
            the_player.queued_lane_change = -1;
        }
    }
    else if(input & 0b00001000) //< go right
    {
        /// only initiate lange change if there is no active lane change
        if(the_player.tick == player_draw)
        {
            /// start correct animation
            switch(the_player.lane)
            {
                case LEFT_LANE: //< left -> mid
                    the_player.tick = player_lane_change_phase1.animation_tick->left_to_mid;
                    the_player.cnt = player_lane_change_phase1.FRAME_CNT[the_game.stage];
                    the_player.x_LUT = player_lane_change_phase1.x_LUT.left_to_mid[the_game.stage];
                    break;
                case MID_LANE: //< mid -> right
                    the_player.tick = player_lane_change_phase1.animation_tick->mid_to_right;
                    the_player.cnt = player_lane_change_phase1.FRAME_CNT[the_game.stage];
                    the_player.x_LUT = player_lane_change_phase1.x_LUT.mid_to_right[the_game.stage];
                    break;
                case RIGHT_LANE: //< in right lane
                    break; //< cant go further right
                default:
                    /// should never happen!
                    break;
            }
        }
        else
        {
            /// there is a lane change ongoing, so we are queuing the input
            the_player.queued_lane_change = 1;
        }
    }
}

void input_2_3 (void)
{
    /// get input
    check_buttons();
    unsigned int input = buttons_pressed();

    /// process input
    /**
     *  BUTTON 1 = use ability
     *  BUTTON 2 = go left
     *  BUTTON 3 = go right
     *  BUTTON 4 = use ability
     */

    /** ability */
    if(input & 0b00001001)
    {
        /// TODO: trigger ability code
        ;
    }

    /** movment input */
    if(input & 0b00000010) //< go left
    {
        /// only initiate lange change if there is no active lane change
        if(the_player.tick == player_draw)
        {
            /// start correct animation
            switch(the_player.lane)
            {
                case RIGHT_LANE: //< right -> mid
                    the_player.tick = player_lane_change_phase1.animation_tick->right_to_mid;
                    the_player.cnt = player_lane_change_phase1.FRAME_CNT[the_game.stage];
                    the_player.x_LUT = player_lane_change_phase1.x_LUT.right_to_mid[the_game.stage];
                    break;
                case MID_LANE: //< mid -> left
                    the_player.tick = player_lane_change_phase1.animation_tick->mid_to_left;
                    the_player.cnt = player_lane_change_phase1.FRAME_CNT[the_game.stage];
                    the_player.x_LUT = player_lane_change_phase1.x_LUT.mid_to_left[the_game.stage];
                    break;
                case LEFT_LANE: //< in left lane
                    break; //< cant go further left
                default:
                    /// should never happen!
                    break;
            }
        }
        else
        {
            /// there is a lane change ongoing, so we are queuing the input
            the_player.queued_lane_change = -1;
        }
    }
    else if(input & 0b00000100) //< go right
    {
        /// only initiate lange change if there is no active lane change
        if(the_player.tick == player_draw)
        {
            /// start correct animation
            switch(the_player.lane)
            {
                case LEFT_LANE: //< left -> mid
                    the_player.tick = player_lane_change_phase1.animation_tick->left_to_mid;
                    the_player.cnt = player_lane_change_phase1.FRAME_CNT[the_game.stage];
                    the_player.x_LUT = player_lane_change_phase1.x_LUT.left_to_mid[the_game.stage];
                    break;
                case MID_LANE: //< mid -> right
                    the_player.tick = player_lane_change_phase1.animation_tick->mid_to_right;
                    the_player.cnt = player_lane_change_phase1.FRAME_CNT[the_game.stage];
                    the_player.x_LUT = player_lane_change_phase1.x_LUT.mid_to_right[the_game.stage];
                    break;
                case RIGHT_LANE: //< in right lane
                    break; //< cant go further right
                default:
                    /// should never happen!
                    break;
            }
        }
        else
        {
            /// there is a lane change ongoing, so we are queuing the input
            the_player.queued_lane_change = 1;
        }
    }
}

const int _ANALOG_PLAYER_X_GAIN[STAGE_T_SIZE] = {
    1, 2, 4, 6, 9, 11, 14, 16, 18, 20, 24
};
void input_analog (void)
{
    /// get input
    check_buttons();
	check_joysticks();

    unsigned int input = buttons_pressed();

    /// process input
    /**
     *  BUTTON 1 = use ability
     *  BUTTON 2 = use ability
     *  BUTTON 3 = use ability
     *  BUTTON 4 = use ability
     */

    /** ability */
    if(input & 0b00001111)
    {
        /// TODO: trigger ability code
        the_game.stage++;
    }

    /** movement */
    
    int x_offset = joystick_1_x() >> 3;

    if(x_offset < -1) //< deadzone of 1/8
    {
        /// analog left
        the_player.x += x_offset - _ANALOG_PLAYER_X_GAIN[the_game.stage];

        if(the_player.x < PLAYER_X_MIN) //< too low
        {
            /// set to lowest
            the_player.x = PLAYER_X_MIN;
        }
        else if(the_player.x < PLAYER_X_MIN_HALF)
        {
            /// flag player as in left lane, is important for drawing correct model and keep consistent colision check
            the_player.lane = LEFT_LANE;
            collision.recalculate_player_aabb = aabb_calculate_left;
            collision.check = aabb_check_side;
        } else if(the_player.x < PLAYER_X_MAX_HALF) {
            /// flag player as in mid lane, is important for drawing correct model and keep consistent colision check
            the_player.lane = MID_LANE;
            collision.recalculate_player_aabb = aabb_calculate_mid;
            collision.check = aabb_check_mid;
        }
        collision.recalculate_player_aabb();
    }
    else if(x_offset > 1) //< deadzone of 1/8
    {
        /// analog right
        the_player.x += x_offset + _ANALOG_PLAYER_X_GAIN[the_game.stage];

        if(the_player.x > PLAYER_X_MAX) //< too high
        {
            /// set to highest
            the_player.x = PLAYER_X_MAX;
        }
        else if(the_player.x > PLAYER_X_MAX_HALF)
        {
            /// flag player as in right lane, is important for drawing correct model and keep consistent colision check
            the_player.lane = RIGHT_LANE;
            collision.recalculate_player_aabb = aabb_calculate_right;
            collision.check = aabb_check_side;
        } else if(the_player.x > PLAYER_X_MIN_HALF) {
            /// flag player as in mid lane, is important for drawing correct model and keep consistent colision check
            the_player.lane = MID_LANE;
            collision.recalculate_player_aabb = aabb_calculate_mid;
            collision.check = aabb_check_mid;
        }
        collision.recalculate_player_aabb();
    }

    print_signed_int(100,0,x_offset);
}


/*****************************************************************************
 * execute start animation and start game
 ****************************************************************************/

#include "game_include/sounds/s_animation.h"

void play_start_animation(void)
{
    /// play sound
    DP_to_C8();
    Init_Music_chk(current_music);

    /// sync to 50 fps
    Wait_Recal();
    Do_Sound();

    /// display map and player
    the_game.process_input();
    the_map.tick();
    the_player.tick();

    if(--(the_game.cnt) == 0)
    {
        /// animation over -> start game
        the_game.execute_state = game_run;
    }
    else
    {

        /// display countdown
        if(the_game.cnt < 50)
        {
            if (the_game.cnt == 49) play_music(&countdown_go);
            print_string(0,-16,"GO\x80");
            object_manager_tick_all();
            object_manager_tick_spawn();
        }
        else if(the_game.cnt < 100)
        {
            if (the_game.cnt == 99) play_music(&countdown_number);
            print_char(0,-9,'1');
        }
        else if(the_game.cnt < 150)
        {
            if (the_game.cnt == 149) play_music(&countdown_number);
            print_char(0,-9,'2');
        }
        else
        {
            if (the_game.cnt == 199) play_music(&countdown_number);
            print_char(0,-9,'3');
        }
    }

    ///next frame
    return;
}




/*****************************************************************************
 * game loop
 ****************************************************************************/


void game_run(void)
{
    /// sync to 50 fps
    Wait_Recal();
    
    /// get input and move player
    the_game.process_input();
    
    /// tick stage manager to determine next speed ramp up
    stage_manager_tick();

    /// draw the map (the road)
    the_map.tick();

    /// draw the player & check collisions etc.
    the_player.tick();

    /// draw new position of enemies (TODO: and fuel and powerups)
    object_manager_tick_all(); //< tick enemies after player for collision-model sync!!!!

    /// spawn new enemies
    object_manager_tick_spawn();

    /// done
    return;
}



/*****************************************************************************
 * game over screen
 ****************************************************************************/

void game_over(void)
{
    /// sync to 50 fps
    Wait_Recal();

    /// highscore handler
	unsigned int score[7];
	Clear_Score(&score);
	Add_Score_d(the_game.score, &score);
	New_High_Score(&score, (void*) &Vec_High_Score);

    /// get input
    check_buttons();
    unsigned int input = buttons_pressed();

    /// process input

    /**
     *  BUTTON 1 = menu
     *  BUTTON 2 = /
     *  BUTTON 3 = /
     *  BUTTON 4 = retry
     */

    if(input & 0b00001000) //< BUTTON 4
    {
        /// retry
        the_game.execute_state = game_init;
    }

    if(input & 0b00000001) //< BUTTON 1
    {
        /// back to start
        the_game.execute_state = start_menu;
    }

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


    /// draw game over screen
    print_string(100,-85,"-=GAME OVER=-\x80");

    print_string(10,-110, score_display);
    print_string(-10,-110, highscore_display);

    print_string(-86,-94,   "[1] BACK TO START\x80");
    print_string(-110,-72,    "[4] TRY AGAIN\x80");

    return;
}