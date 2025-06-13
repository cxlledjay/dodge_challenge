#pragma once
#include "misc.h"


typedef struct _player_t
{
    lane_t lane; //< current lane the player is in

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

/**
 * @brief different lane swap animation times (in frames) for different speed stages
 * 
 * @param IN the_game.stage
 * @returns  the frame count of how long the lane swap animation will last
 */
extern const unsigned int PLAYER_ANIMATION_FRAME_CNT_STEP1_LUT[11];






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


 /// -------------< l a n e   c h a n g e >-------------

 /// @brief left -> mid
 void player_change_left_to_mid_step1(void);

 /// @brief mid -> right
 void player_change_mid_to_right_step1(void);


 /// @brief right -> mid
 void player_change_right_to_mid_step1(void);

 /// @brief mid -> left
 void player_change_mid_to_left_step1(void);



 
/****************************************************************
 * animation LUTs
 ****************************************************************/

/// @brief x pos LUT for left -> mid step 1 animation
/// @param index the_game.stage
/// @return pointer to LUT
extern const int* const PLAYER_LUT_LEFT_MID_STEP1[];

/// @brief x pos LUT for mid -> right step 1 animation
/// @param index the_game.stage
/// @return pointer to LUT
extern const int* const PLAYER_LUT_MID_RIGHT_STEP1[];

/// @brief x pos LUT for right -> mid step 1 animation
/// @param index the_game.stage
/// @return pointer to LUT
extern const int* const PLAYER_LUT_RIGHT_MID_STEP1[];

/// @brief x pos LUT for mid -> left step 1 animation
/// @param index the_game.stage
/// @return pointer to LUT
extern const int* const PLAYER_LUT_MID_LEFT_STEP1[];