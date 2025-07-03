#pragma once
#include "misc.h"


/****************************************************************
 * data structures
 ****************************************************************/

/// @brief the player object
typedef struct _player_t
{
    lane_t lane; //< used to get correct model + aabbcd (aligned axis bounding box collision detection)

    int x; //< player x pos for animation & collision check
    const int * x_LUT; //< pointer for correct LUT for animation (set by game loop)

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

/// @brief the player y pos (wont ever change)
#define PLAYER_Y		(-112)

/// ---------------------------------------------------------------


/// @brief collection of all tick functions for lane change animation (step1 - public)
typedef struct _player_lane_change_animation_t
{
    void (*left_to_mid) (void);
    void (*mid_to_right) (void);
    void (*right_to_mid) (void);
    void (*mid_to_left) (void);
}player_lane_change_animation_t;




/****************************************************************
 * functions
 ****************************************************************/


/// @brief init function
void player_init(void);


/****************************************************************
 * player tick options interface
 ****************************************************************/

/// @brief driving straight
void player_draw(void);

/// @brief animation function pointers (=> initiate lane change)
extern const player_lane_change_animation_t _player_lanechange_tick_phase1;

/// @brief animation function pointers (=> complete lane change)
extern const player_lane_change_animation_t _player_lanechange_tick_phase2;
