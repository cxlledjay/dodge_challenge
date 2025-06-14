#pragma once


/// @brief for debug purpose only
/// draws the bounding box of the player model
void debug_draw_aabb_player(void);


/**
 * @brief collision detection for player
 * 
 * utilizing tweaked aabb (axis aligned bounding boxes) to check against enemies and spawned abilities
 */
void collision_check(void);