#pragma once


//fw decl
struct _moving_object_t;
typedef void (* object_tick_func) (struct _moving_object_t * me);

/******************************************************************************************************
 * moving object parent class (all moving objects must derive from this object)
 ******************************************************************************************************/
typedef enum _moving_object_type_t
{
    ENEMY_DUMMY = 0,
    ABILITY_1,
    ABILITY_2,
    ABILITY_3,
    ABILITY_4,
    ENEMY_1,
    ENEMY_2,
    ENEMY_3,
}moving_object_type_t;



/******************************************************************************************************
 * generic moving object parent class (derive classes via type field)
 ******************************************************************************************************/

 #include "misc.h"
typedef struct _moving_object_t
{
    moving_object_type_t type; //< what am i?
    lane_t lane; //< where am i? (<-- for collision check used)

    void * model; //< only set by spawning
    unsigned int ttl; //<y pos, x pos & scale is derived from LUT in tick()

    object_tick_func tick; //< executed each "tick" --> animation handling (collision detection in player) | set to idle() when unused!
    /// 3 different tick categories: tick_left, tick_mid and tick_right (state about lane in function hardcoded -> and thus LUTs as well)
    /// each category has own tick functions for different speeds
} moving_object_t;




/******************************************************************************************************
 * moving object tick functions (based on current speed)
 ******************************************************************************************************/
#include "game.h"

/**
 * @brief not yet spawned / despawned object is in idle
 */
void idle(__attribute__((unused)) moving_object_t* me);

extern void (* const MOVING_OBJECT_TICK_FNC_LUT[STAGE_T_SIZE][3]) (moving_object_t * me);