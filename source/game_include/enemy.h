#pragma once


/**
 * @brief init or reset enemies for a fresh game
 */
void enemy_init(void);


/**
 * @brief tries to spawn an enemy
 * @param lane the lane in which the enemy should spawn
 * @return 0 on success, -1 on error (maybe 1 on lane used in last spawn?, ...)
 */
#include "misc.h"
int enemy_try_spawn(lane_t lane);


/***************************************************
 * interface for spawner
 **************************************************/
void enemy_debug(void);