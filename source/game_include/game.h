#pragma once

/**
 * @brief this module keeps track of most things and keeps everything together
 * 
 * game.h/c handles the
 *  a) current game state (starting, running, stopped, game over)
 *  b) reached score(s)
 *  c) current speed (aka. level/stage/...)
 *  d) game loop
 */



 #include "misc.h"


 typedef struct _game_t 
 {
    unsigned long score;            //< silent tracking
    unsigned int speed;             //< idk how wich way i will implement :)

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
  * TODO: implement start screen select (speed + difficulty??)
  * TODO: implement some fancy starting animation
  */
 void game_init(void);
