#pragma once


typedef struct _collision_check_t
{
    void (* recalculate_player_aabb) (void);
} collision_check_t;

/**
 * @brief public interface for collisions
 * 
 * trigger recalculate_player_aabb each time the player moves
 * trigger check each tick to calculate if the player touched an object
 * (check uses a tweaked variant of Axis Aligned Bounding Boxes)
 */
extern collision_check_t collision;

/// @brief trigger according to player spawn
void collision_init(void);




/**************************************************
 * interfaces for different player models
 *************************************************/

/// @brief calculate player bounding box for midlane viewmodel 
void aabb_calculate_mid(void);
/// @brief calculate player bounding box for leftlane viewmodel 
void aabb_calculate_left(void);
/// @brief calculate player bounding box for rightlane viewmodel 
void aabb_calculate_right(void);

/// @brief only check player collision with moving object
void aabb_check_collision(void);


/// use macros for ease of use...

/// recalculate collision of player moved (for midlane model)
#define COLLISION_SET_MID()                                     \
    collision.recalculate_player_aabb = aabb_calculate_mid;

/// recalculate collision of player moved (for leftlane model)
#define COLLISION_SET_LEFT()                                    \
    collision.recalculate_player_aabb = aabb_calculate_left;

/// recalculate collision of player moved (for rightlane model)
#define COLLISION_SET_RIGHT()                                   \
    collision.recalculate_player_aabb = aabb_calculate_right;
