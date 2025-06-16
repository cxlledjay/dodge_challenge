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

typedef enum _stage_t
{
   VERY_SLOW      = 0,  //< easy start
   QUITE_SLOW     = 1,
   SLOWISH        = 2,  //< normal start
   SLOW           = 3,
   QUITE_NORMAL   = 4,  //< hard start
   NORMAL         = 5,  //< easy stop
   QUITE_FAST     = 6,
   FAST           = 7,  //< normal stop
   VERY_FAST      = 8,
   SPEEDY         = 9,  //< hard stop
   EXPERT_ONLY    = 10  //< secret speed
}stage_t;



#define STAGE_T_SIZE (11u)        //< how many different speed levels

typedef struct _game_t 
{
   unsigned long score;            //< silent tracking
   unsigned int stage;             //< different stages of speed, advancing through the game. 
                                   //  selectable in start menu (thus progression is dependant on selection)

   void (* execute_state) (void);  //< state machine
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

void game_over(void);
