#pragma once


/****************************************************************
 * data structures
 ****************************************************************/
#include "game_include/ability.h"
#include "game_include/fuel.h"
#include "game_include/misc.h"

/// @brief the player object
typedef struct _player_t
{
    /* player position parameters */
    lane_t lane; //< used to get correct model + aabbcd (aligned axis bounding box collision detection)
    int x; //< player x pos for animation & collision check

    /* parameters for button controls */
    const int * x_LUT; //< pointer for correct LUT for animation (set by game loop)
    unsigned int cnt; //< if player is changing lanes, keep track of lane change animation here
    int queued_lane_change; //< if input is given when player is still in animation (-1 = left, 0 = none, 1 = right)

    /* ingame attributes */
    fuel_amount_t fuel; //< amount of fuel, the player is carrying
    ability_class_t ability; //< the ability the player has picked up
    unsigned int has_extralife;

    /* player handling */
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

/// @brief static player position for each lane
#define PLAYER_X_MIN                (-82)
#define PLAYER_X_MAX                (82)
#define PLAYER_X_MID                (0)
#define PLAYER_X_MIN_HALF           (PLAYER_X_MIN/2)
#define PLAYER_X_MAX_HALF           (PLAYER_X_MAX/2)

/// @brief driving straight
void player_draw(void);

/// @brief animation function pointers (=> initiate lane change)
extern const player_lane_change_animation_t _player_lanechange_tick_phase1;

/// @brief animation function pointers (=> complete lane change)
extern const player_lane_change_animation_t _player_lanechange_tick_phase2;



/****************************************************************
 * macros for initiating lane change
 * (the complete lane change is handled automatically afterwards)
 ****************************************************************/

#define PLAYER_INIT_LC_LEFT_MID()                                                       \
    the_player.tick = player_lane_change_phase1.animation_tick->left_to_mid;            \
    the_player.cnt = player_lane_change_phase1.FRAME_CNT[the_game.stage];               \
    the_player.x_LUT = player_lane_change_phase1.x_LUT.left_to_mid[the_game.stage];

#define PLAYER_INIT_LC_MID_RIGHT()                                                      \
    the_player.tick = player_lane_change_phase1.animation_tick->mid_to_right;           \
    the_player.cnt = player_lane_change_phase1.FRAME_CNT[the_game.stage];               \
    the_player.x_LUT = player_lane_change_phase1.x_LUT.mid_to_right[the_game.stage];

#define PLAYER_INIT_LC_RIGHT_MID()                                                      \
    the_player.tick = player_lane_change_phase1.animation_tick->right_to_mid;           \
    the_player.cnt = player_lane_change_phase1.FRAME_CNT[the_game.stage];               \
    the_player.x_LUT = player_lane_change_phase1.x_LUT.right_to_mid[the_game.stage];
    
#define PLAYER_INIT_LC_MID_LEFT()                                                       \
    the_player.tick = player_lane_change_phase1.animation_tick->mid_to_left;            \
    the_player.cnt = player_lane_change_phase1.FRAME_CNT[the_game.stage];               \
    the_player.x_LUT = player_lane_change_phase1.x_LUT.mid_to_left[the_game.stage];
