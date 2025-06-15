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

#include "game_include/game.h"
/// @brief collection of all x position LUTs per animation frame for lane change animation (step1 - public)
typedef struct _player_lane_change_x_lut_t
{
    /// @brief x pos LUT for left -> mid step 1 animation
    /// @param index the_game.stage
    /// @return pointer to LUT
    const int* const left_to_mid[STAGE_T_SIZE];
    const int* const mid_to_right[STAGE_T_SIZE];
    const int* const right_to_mid[STAGE_T_SIZE];
    const int* const mid_to_left[STAGE_T_SIZE];
}player_lane_change_x_lut_t;

/// @brief collection of everything needed to calculate lane change in one structure
typedef struct _player_lane_change_t
{
    const unsigned int FRAME_CNT[STAGE_T_SIZE];
    const player_lane_change_animation_t const * animation_tick;
    const player_lane_change_x_lut_t * x_LUT;
}player_lane_change_t;




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


/// @brief constant structure holding everything needed to initiate a lane change
/// everything else regarding the lane change is processed and calculated locally (in player.c)
extern const player_lane_change_t player_lane_change;
