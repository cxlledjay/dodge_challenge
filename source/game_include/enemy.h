#pragma once
#include "misc.h"
#include "game.h"

struct _enemy_t;
typedef void (* enemy_tick_func) (struct _enemy_t * me);

typedef struct _enemy_t
{
    void * model; //< only set by spawning

    unsigned int ttl; //<y pos, x pos & scale is derived from LUT in tick()

    //unsigned int cnt; //< used to count ticks for animation handling

    enemy_tick_func tick; //< executed each "tick" --> animation handling (collision detection in player) | set to idle() when unused!
    /// 3 different tick categories: tick_left, tick_mid and tick_right (state about lane in function hardcoded -> and thus LUTs as well)
    /// each category has own tick functions for different speeds
} enemy_t;


/**
 * @brief init or reset enemies for a fresh game
 */
void enemy_init(void);


/**
 * @brief tries to spawn an enemy
 * @param lane the lane in which the enemy should spawn
 * @return 0 on success, -1 on error (maybe 1 on lane used in last spawn?, ...)
 */
int enemy_try_spawn(lane_t lane);


/***************************************************
 * interface for spawner
 **************************************************/

extern void (* const ENEMY_TICK_FNC_LUT[STAGE_T_SIZE][3]) (enemy_t * me);

void enemy_debug(void);