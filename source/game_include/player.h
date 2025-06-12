#pragma once
#include "misc.h"


typedef struct _player_t
{
    lane_t lane; //< current lane the player is in
    unsigned int cnt; //< if player is changeing lanes, keep track of lane change animation here

    void (*tick) (void); //< handle drawing (+animation), collision detection (+game state change), ability pickup
} player_t;

/**
 * @brief singleton instance of the player
 *        used to draw and animate the player, check for collisions etc.
 * 
 * execute the_player.tick() each game tick.
 */
extern player_t the_player;


void player_init(void);


/****************************************************************
 * player tick options interface
 ****************************************************************/

 void player_draw(void);
 void player_change_left(void);
 void player_change_right(void);