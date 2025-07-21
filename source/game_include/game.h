#pragma once

/**
 * @brief this module keeps track of most things and keeps everything together
 * 
 * game.h/c handles the
 *  a) current game state (starting, running, stopped, game over)
 *  b) reached score(s) + highscore
 *  c) current speed (aka. level/stage/...)
 *  d) game loop
 */



#include "misc.h"

#define STAGE_T_SIZE (11u)        //< how many different speed levels
typedef enum _stage_t
{
   GS_VERY_SLOW      = 0,  //< easy start
   GS_QUITE_SLOW     = 1,
   GS_SLOWISH        = 2,  //< normal start
   GS_SLOW           = 3,
   GS_QUITE_NORMAL   = 4,  //< hard start
   GS_NORMAL         = 5,  //< easy stop
   GS_QUITE_FAST     = 6,
   GS_FAST           = 7,  //< normal stop
   GS_VERY_FAST      = 8,
   GS_SPEEDY         = 9,  //< hard stop
   GS_HIDDEN    = 10  //< secret speed
}stage_t;


/// @brief persisten storage of start menu selection, gets parsed in init
typedef struct _game_options_t {
   unsigned int input_method : 4;
   unsigned int game_mode : 4;
} game_options_t;

#define GAME_MODE_EASY              (0u)
#define GAME_MODE_MID               (1u)
#define GAME_MODE_HARD              (2u)
#define GAME_MODE_HIDDEN            (3u)

#define INPUT_METHOD_1_4            (0u)
#define INPUT_METHOD_2_3            (1u)
#define INPUT_METHOD_ANALOG         (2u)




typedef struct _game_t 
{
   game_options_t options;          //< storing start menu selection

   unsigned long score;             //< silent tracking
   stage_t stage;                   //< different stages of speed, advancing through the game. 
                                    //  selectable in start menu (thus progression is dependant on selection)

   unsigned int cnt;                //< tracking animations

   void (* process_input) (void);   //< get user input and manipulate game
   void (* execute_state) (void);   //< game state machine
}game_t;


/**
 * @brief singleton game object, used to manage everything about the current run
 * 
 * execute_state() handles everything from init to the game loop based on internal states
 */
extern game_t the_game;


/**
 * @brief handled by execute_state() internally, interface needed for bootstrap in main
 * 
 * (re)sets all variables and starts the game
 * TODO: implement start screen select (stage + difficulty??)
 * TODO: implement some fancy starting animation
 */
void game_init(void);

/// @brief hard reset / for first start
void game_start(void);

/// @brief state when player crashes
void game_over(void);
