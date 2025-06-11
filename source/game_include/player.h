#pragma once
#include "misc.h"

struct _player_t; //forward declaration so player_tick_func knows about the object its stored in
typedef void (* player_tick_func) (struct _player_t * me);

typedef struct _player_t
{
    lane_t lane; //< current lane the player is in
    unsigned int cntr; //< if player is changeing lanes, keep track of lane change here

    player_tick_func tick; //< executed every tick -> i/o handle, moving, collision detection, ...
} player_t;


void player_init(void);

void player_handle_input(void);

void player_draw(void);