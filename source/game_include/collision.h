#pragma once


typedef struct _collision_check_t
{
    void (* recalculate_player_aabb) (void);
    void (* check) (void);
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

void aabb_calculate_mid(void);
void aabb_calculate_left(void);
void aabb_calculate_right(void);

void aabb_check_mid(void);
void aabb_check_side(void);


/// use macros for ease of use...
#define COLLISION_SET_MID()                                 \
    collision.recalculate_player_aabb = aabb_calculate_mid; \
    collision.check = aabb_check_mid;

#define COLLISION_SET_LEFT()                                 \
    collision.recalculate_player_aabb = aabb_calculate_left; \
    collision.check = aabb_check_side;

#define COLLISION_SET_RIGHT()                                 \
    collision.recalculate_player_aabb = aabb_calculate_right; \
    collision.check = aabb_check_side;
