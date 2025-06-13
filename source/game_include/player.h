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

/**
 * @brief different lane swap animation times (in frames) for different speed stages
 * 
 * @param IN the_game.stage
 * @returns  the frame count of how long the lane swap animation will last
 */
extern const unsigned int PLAYER_ANIMATION_FRAME_CNT_LUT[11];


void player_init(void);


/****************************************************************
 * player tick options interface
 ****************************************************************/

 void player_draw(void);
 void player_change_left(void);
 void player_change_right(void);