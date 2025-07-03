#pragma once

#include "game_include/game.h"
#include "game_include/player.h"


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
    const player_lane_change_x_lut_t x_LUT;
}player_lane_change_t;




/// ----------------------------------------------< interfaces >----------------------------------------------

/// @brief constant structure holding everything needed to initiate a lane change
/// everything else regarding the lane change is processed and calculated locally (in player.c)
extern const player_lane_change_t player_lane_change_phase1;

/// @brief constant structure holding everything needed to complete a lane change
extern const player_lane_change_t player_lane_change_phase2;