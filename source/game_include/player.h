#pragma once
#include "misc.h"

struct _player_t; //forward declaration so player_tick_func knows about the object its stored in
typedef void (* player_tick_func) (struct _player_t * me);

typedef struct _player_t
{
    lane_t lane; //< current lane the player is in
    unsigned int cnt; //< if player is changeing lanes, keep track of lane change animation here

    player_tick_func tick; //< executed every tick -> i/o handle, moving, collision detection, ...
} player_t;

/**
 * @brief singleton instance of the player
 *        used to draw and animate the player, check for collisions etc.
 * 
 * execute the_player.tick() each game tick.
 */
extern player_t the_player;


void player_init(void);