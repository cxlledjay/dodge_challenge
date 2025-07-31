#include "game_include/game.h"

/*****************************************************************************
 * the game is on...
 ****************************************************************************/
game_t the_game;


#include "game_include/stage.h"
#include "game_include/map.h"
#include "game_include/player.h"
#include "game_include/object_manager.h"
#include "game_include/collision.h"
#include "game_include/ability.h"
#include "game_include/fuel.h"
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

/* animation */
void game_no_animation(void) { return; }

/*****************************************************************************
 * init part
 ****************************************************************************/


void game_start(void)
{
    /// init the game (main handler)
    game_options_t start_selection = {.game_mode = GAME_MODE_EASY, .input_method = INPUT_METHOD_ANALOG};
    game_t new_game = {
        .options = start_selection,
        .score = {0,0,0,0,0,0,0},
        .stage = 0,
        .cnt = 0,
        .process_input = input_analog,
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

const stage_t game_max_stage[4] = {
    GS_NORMAL,
    GS_FAST,
    GS_SPEEDY,
    GS_HIDDEN
};

#include "lib/sound/sound.h"
void game_init(void)
{
    /// trigger all init routines
    object_manager_init(); //< init first for random seed to use past values in ram
    
    stages_init();
    map_init();
    player_init();
    fuel_bar_init();
    ability_init();
    collision_init();

    /// score reset
	Clear_Score(the_game.score);
    the_game.reason = 0;

    /// init stage according to game mode
    switch (the_game.options.game_mode) {
		case GAME_MODE_EASY:
            the_game.stage = GS_VERY_SLOW;
            break;
		case GAME_MODE_MID:
            the_game.stage = GS_SLOWISH;
            break;
		case GAME_MODE_HARD:
            the_game.stage = GS_QUITE_NORMAL;
            break;
		case GAME_MODE_HIDDEN:
            the_game.stage = GS_QUITE_FAST;
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
    the_game.play_animation = game_no_animation;

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
#include "game_include/sounds/s_animation.h"

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
    
    /// game header (professionally stolen :D)
    DP_to_C8();
    Explosion_Snd(current_explosion);
    Init_Music_chk(current_music);
    Wait_Recal();
    Do_Sound();
    Intensity_5F();

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

        /// play sound
        play_music(&menu_select_sound);
    }

    if(input & 0b00000010) //< BUTTON 2
    {
        /// cycle mode
        if(the_game.options.game_mode == GAME_MODE_HARD) {
            the_game.options.game_mode = GAME_MODE_EASY;
        } else {
            the_game.options.game_mode++;
        }

        /// play sound
        play_music(&menu_select_sound);
    }

    if(input & 0b00000001) //< BUTTON 1
    {
        /// cycle input method
        if(the_game.options.input_method == INPUT_METHOD_ANALOG) {
            the_game.options.input_method = INPUT_METHOD_1_4;
        } else {
            the_game.options.input_method++;
        }

        /// play sound
        play_music(&menu_select_sound);
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




/****************************************************************
 * trigger ability use from player input
 ****************************************************************/
#include "game_include/gen_data/gen_object_path.h"
#include "game_include/sounds/s_animation.h"

/// @brief start ability usage
static inline __attribute__((always_inline)) void ability_use (void)
{
    /// usage code depends on ability type
    switch (the_player.ability)
    {
        case AC_MISSILE:

            /// TODO: shoot missle (from player x coords, w/ lane model)
            if(the_ability_manager.used[0].tick == ability_idle)
            {
                /// first ability "thread" is free
                the_ability_manager.used[0].cnt = ABILITY_MISSILE_MAX_CNT;
                calc_path_factor(&the_ability_manager.used[0], the_player.x);
                the_ability_manager.used[0].tick = ABILITY_TICK_FNC[AC_MISSILE][the_player.lane];
            }
            else
            {
                /// use second "thread"
                the_ability_manager.used[1].cnt = ABILITY_MISSILE_MAX_CNT;
                calc_path_factor(&the_ability_manager.used[1], the_player.x);
                the_ability_manager.used[1].tick = ABILITY_TICK_FNC[AC_MISSILE][the_player.lane];
            }

            /// play shooting sound
            play_explosion(&e_missile_shoot);

            /// remove ability
            the_player.ability = AC_NONE;

            /// done
            break;

        case AC_NONE:
        default:
            ;
    }

    /// done
    return;
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
        /// trigger ability code
        ability_use();
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
                    PLAYER_INIT_LC_RIGHT_MID()
                    break;
                case MID_LANE: //< mid -> left
                    PLAYER_INIT_LC_MID_LEFT()
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
                    PLAYER_INIT_LC_LEFT_MID()
                    break;
                case MID_LANE: //< mid -> right
                    PLAYER_INIT_LC_MID_RIGHT()
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
        /// trigger ability code
        ability_use();
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
                    PLAYER_INIT_LC_RIGHT_MID()
                    break;
                case MID_LANE: //< mid -> left
                    PLAYER_INIT_LC_MID_LEFT()
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
                    PLAYER_INIT_LC_LEFT_MID()
                    break;
                case MID_LANE: //< mid -> right
                    PLAYER_INIT_LC_MID_RIGHT()
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

void input_analog (void)
{
    /// get input
    check_buttons();
	Joy_Analog();

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
        /// trigger ability code
        ability_use();
    }

    /** movement */
    
    int x_offset = joystick_1_x() >> 4;

    if(x_offset < -1) //< deadzone of 1/8
    {
        /// analog left
        the_player.x += x_offset - (int) the_game.stage;

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
        } else if(the_player.x < PLAYER_X_MAX_HALF) {
            /// flag player as in mid lane, is important for drawing correct model and keep consistent colision check
            the_player.lane = MID_LANE;
            collision.recalculate_player_aabb = aabb_calculate_mid;
        }
        collision.recalculate_player_aabb();
    }
    else if(x_offset > 1) //< deadzone of 1/8
    {
        /// analog right
        the_player.x += x_offset + (int) the_game.stage;

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
        } else if(the_player.x > PLAYER_X_MIN_HALF) {
            /// flag player as in mid lane, is important for drawing correct model and keep consistent colision check
            the_player.lane = MID_LANE;
            collision.recalculate_player_aabb = aabb_calculate_mid;
        }
        collision.recalculate_player_aabb();
    }
}


/*****************************************************************************
 * execute start animation and start game
 ****************************************************************************/

#include "game_include/sounds/s_animation.h"
#include "game_include/graphics/g_gui.h"
#include "game_include/graphics/g_player.h"
#include "game_include/gen_data/gen_object_path.h"

void play_start_animation(void)
{
    /// game header
    DP_to_C8();
    Explosion_Snd(current_explosion);
    Init_Music_chk(current_music);
    Wait_Recal();
    Do_Sound();
    Intensity_5F();

    /// draw map
    the_map.tick();

    if(the_game.cnt < 130)
    {
        /// display player as usual
        the_game.process_input();
        the_player.tick();
    }
    else
    {
        /// animate player driving in

        /// steal y and sc table from objects @attention may break if object paths are changed
        unsigned int cnt_to_ttl = the_game.cnt - 117; //< start at 83 (goes to 13)
        int y = _ST5_Y1_LUT[cnt_to_ttl]; //< copy y 1:1
        unsigned int sc = (_ST5_SC_LUT[cnt_to_ttl] * 3)/5; //< copy and scale to 3/5

        /// custom draw player
        Reset0Ref();
        dp_VIA_t1_cnt_lo = 0x7f;
        Moveto_d(y, 0);
        dp_VIA_t1_cnt_lo = sc;
        Draw_VLp(&vl_player_mid1);
        Reset0Ref();
        dp_VIA_t1_cnt_lo = 0x7f;
        Moveto_d(y, 0);
        dp_VIA_t1_cnt_lo = sc;
        Draw_VLp(&vl_player_mid2);
    }

    /// draw full fuelbar
    FUELBAR_DRAW(100);

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


/// @brief helper function to draw the score
static inline __attribute__((always_inline)) void  _draw_score(void)
{
    /// FIXME: should be drawn with vector lists
    print_string(116,-60,(char*) &the_game.score);
}



/*****************************************************************************
 * game loop
 ****************************************************************************/
#include "game_include/fuel.h"

void game_run(void)
{
    /// game header
    DP_to_C8();
    Explosion_Snd(current_explosion);
    Init_Music_chk(current_music);
    Wait_Recal();
    Do_Sound();
    Intensity_5F();
    
    /// get input and move player
    the_game.process_input();
    
    /// tick stage object for speed ramping effect over time
    stages_tick();

    /// draw the map (the road)
    the_map.tick();

    /// draw gui
    fuel_bar_tick();
    ability_draw_gui();

    /// draw the player & check collisions etc.
    the_player.tick();

    /// draw new position of objects
    object_manager_tick_all();

    /// tick currently active abilities
    the_ability_manager.used[0].tick(&the_ability_manager.used[0]);
    the_ability_manager.used[1].tick(&the_ability_manager.used[1]);

    /// spawn new enemies
    object_manager_tick_spawn();

    /// display score
    _draw_score();

    /// display animation
    the_game.play_animation();

    /// done
    return;
}




/*****************************************************************************
 * player hit enemy animation
 ****************************************************************************/
#include "game_include/graphics/g_map.h"
#include "game_include/graphics/g_object.h"

// MOVING_OBJECT_Y1_LUT

/// @brief helper function to draw objects
/// @param lane the lane of the object
static inline __attribute__((always_inline)) void  _draw_object (moving_object_t * obj)
{
    int y1, y2, x;
    unsigned int sc;

    /// fetch current position (not depending on lane)
    y1 = MOVING_OBJECT_Y1_LUT[the_game.stage][obj->ttl];
    y2 = MOVING_OBJECT_Y2_LUT[the_game.stage][obj->ttl];
    sc = MOVING_OBJECT_SC_LUT[the_game.stage][obj->ttl];

    /// fetch current position (depending on lane)
    switch (obj->lane)
    {
        case LEFT_LANE:
            x = MOVING_OBJECT_XL_LUT[the_game.stage][obj->ttl];
            break;
        case MID_LANE:
            x = 0;
            break;
        case RIGHT_LANE:
            x = MOVING_OBJECT_XR_LUT[the_game.stage][obj->ttl];
            break;
        default:
            ; //< should never happen
    }

    /// draw at position
    Reset0Ref();
    dp_VIA_t1_cnt_lo = 0x7f;
    Moveto_d(y1,x);
    Moveto_d(y2,0);
    dp_VIA_t1_cnt_lo = sc;
    if(obj->type != MOT_EXPLODED)
    {
        /// draw as usual
        Draw_VLp(obj->model);
    }
    else
    {
        /// draw exploded model
        Draw_VLp((struct packet_t *) vl_exploded[(unsigned long) obj->model]);

        /// still animate it...
        if(--(obj->cnt) == 0)
        {
            /// reset counter
            obj->cnt = 10;

            /// chose next vl
            unsigned long next = (unsigned long) obj->model;
            if(--next == 0)
            {
                /// animation is over
                obj->tick = idle;
            }
            else
            {
                /// next animation model
                obj->model = (void *) next;
            }
        }
    }
}

void game_player_hit_animation(void)
{
    /// game header
    DP_to_C8();
    Explosion_Snd(current_explosion);
    Init_Music_chk(current_music);
    Wait_Recal();
    Do_Sound();
    Intensity_5F();
    
    /// keep track of time
    if(--(the_game.cnt) == 0)
    {
        /// animation is over -> show end screen
        the_game.execute_state = game_over;

        /// init game over screen
        the_game.cnt = 20;
        the_game.play_animation = (void *) &vl_exploded[0];

        /// play sad sound
        Clear_Sound();
        play_music(&game_over_sad);
    }

    /// draw everything as "freeze frame"

    /// 1) map (may skip one or two animation steps, but it doesn't matter)
	DRAW_LEFT();
	ANIMATE_LEFT(&vl_map_roadline_left_1);
	ANIMATE_RIGHT(&vl_map_roadline_right_1);
	DRAW_RIGHT();

    /// 2) fuel bar (copy paste from fuel.c)
    FUELBAR_DRAW(the_player.fuel);

    /// 3) abilities
    ability_draw_gui();

    /// 4) objects
    for (unsigned int i = 0; i < MAX_MOVING_OBJECTS; ++i)
    {
        moving_object_t * current = &the_object_manager.objects[i];
        if(current->tick == idle)
        {
            continue;
        }

        /// draw object
        _draw_object(current);
    }

    /// 5) score
    _draw_score();

    /// animate player explosion
    if(--(the_player.cnt) == 0)
    {
        /// next explosion model
        --(the_player.queued_lane_change);

        /// reset counter
        the_player.cnt = 15;
    }

    /// draw player explosion
    Reset0Ref();
    dp_VIA_t1_cnt_lo = 0x7f;
    Moveto_d(PLAYER_Y,the_player.x);
    dp_VIA_t1_cnt_lo = 27;
    Draw_VLp((struct packet_t *) vl_exploded[(unsigned int) the_player.queued_lane_change]);
}



/*****************************************************************************
 * game over screen
 ****************************************************************************/
#include "game_include/graphics/g_misc.h"

void game_over(void)
{
    /// game header (professionally stolen :D)
    DP_to_C8();
    Explosion_Snd(current_explosion);
    Init_Music_chk(current_music);
    Wait_Recal();
    Do_Sound();
    Intensity_5F();

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

    score_display[11] = the_game.score[0];
    score_display[12] = the_game.score[1];
    score_display[13] = the_game.score[2];
    score_display[14] = the_game.score[3];
    score_display[15] = the_game.score[4];
    score_display[16] = the_game.score[5];

    highscore_display[11] = Vec_High_score[0];
    highscore_display[12] = Vec_High_score[1];
    highscore_display[13] = Vec_High_score[2];
    highscore_display[14] = Vec_High_score[3];
    highscore_display[15] = Vec_High_score[4];
    highscore_display[16] = Vec_High_score[5];


    /// start drawing

    /// 1) game over
    print_string(110,-85,"-=GAME OVER=-\x80");

    /// 2) show the reason
    unsigned int reason = the_game.reason & 0b00000011;

    /// 2.1) generic "+"
    Reset0Ref();
    dp_VIA_t1_cnt_lo = 57;
    Moveto_d(119,-113);
    dp_VIA_t1_cnt_lo = 13;
    Draw_VLp(&vl_game_over_plus);

    /// 2.2) generic "="
    Reset0Ref();
    dp_VIA_t1_cnt_lo = 57;
    Moveto_d(127,112);
    dp_VIA_t1_cnt_lo = 13;
    Draw_VLp(&vl_game_over_equals);

    /// 2.3) generic car
    #define _GENERIC_CAR_SC     (96u)
    #define _GENERIC_CAR_Y      (75)
    Reset0Ref();
    dp_VIA_t1_cnt_lo = _GENERIC_CAR_SC;
    Moveto_d(_GENERIC_CAR_Y,-127);
    dp_VIA_t1_cnt_lo = 16;

    switch(the_player.lane)
    {
        case LEFT_LANE:
            Draw_VLp(&vl_player_left1);
            Reset0Ref();
            dp_VIA_t1_cnt_lo = _GENERIC_CAR_SC;
            Moveto_d(_GENERIC_CAR_Y,-127);
            dp_VIA_t1_cnt_lo = 16;
            Draw_VLp(&vl_player_left2);
            Reset0Ref();
            dp_VIA_t1_cnt_lo = _GENERIC_CAR_SC;
            Moveto_d(_GENERIC_CAR_Y,-127);
            dp_VIA_t1_cnt_lo = 16;
            Draw_VLp(&vl_player_left3);
            break;

        case MID_LANE:
            Draw_VLp(&vl_player_mid1);
            Reset0Ref();
            dp_VIA_t1_cnt_lo = _GENERIC_CAR_SC;
            Moveto_d(_GENERIC_CAR_Y,-127);
            dp_VIA_t1_cnt_lo = 16;
            Draw_VLp(&vl_player_mid2);
            break;

        case RIGHT_LANE:
            Draw_VLp(&vl_player_right1);
            Reset0Ref();
            dp_VIA_t1_cnt_lo = _GENERIC_CAR_SC;
            Moveto_d(_GENERIC_CAR_Y,-127);
            dp_VIA_t1_cnt_lo = 16;
            Draw_VLp(&vl_player_right2);
            Reset0Ref();
            dp_VIA_t1_cnt_lo = _GENERIC_CAR_SC;
            Moveto_d(_GENERIC_CAR_Y,-127);
            dp_VIA_t1_cnt_lo = 16;
            Draw_VLp(&vl_player_right3);
            break;

        default:
            ; //< should never happen
    }

    /// 2.4) generic explosion
    Reset0Ref();
    dp_VIA_t1_cnt_lo = 96;
    Moveto_d(75,127);
    dp_VIA_t1_cnt_lo = 20;

    if(--(the_game.cnt) == 0)
    {
        /// next animation

    }
    Draw_VLp(&vl_game_over_equals);


    /// 2.5) reason specific stuff
    switch (reason)
    {
        case 0x01:
            /// no fuel left

            /// "0x"
            Reset0Ref();
            dp_VIA_t1_cnt_lo = 60;
            Moveto_d(127,-42);
            dp_VIA_t1_cnt_lo = 13;
            Draw_VLp(&vl_game_over_zero_times);

            /// fuelcan
            Reset0Ref();
            dp_VIA_t1_cnt_lo = 47;
            Moveto_d(126,59);
            dp_VIA_t1_cnt_lo = 27;
            Draw_VLp(&vl_object_fuelcan);

            break;
        case 0x02:
            /// hit an enemy

            break;
        default:
            ; //< should not happen
    }

    /// draw the rest
    print_string(10,-110, score_display);
    print_string(-10,-110, highscore_display);

    print_string(-86,-104,   "[1] BACK TO START\x80");
    print_string(-110,-82,     "[4] TRY AGAIN\x80");

    return;
}