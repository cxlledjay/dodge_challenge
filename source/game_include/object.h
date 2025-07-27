#pragma once


//fw decl
struct _moving_object_t;
typedef void (* object_tick_func) (struct _moving_object_t * me);

/******************************************************************************************************
 * moving object parent class (all moving objects must derive from this object)
 ******************************************************************************************************/
typedef enum _moving_object_type_t
{
    MOT_ENEMY_CAR1 = 0,
    MOT_ENEMY_CAR2 = 1,
    MOT_ENEMY_TRUCK = 2,
    MOT_ENEMY_BIKE = 3,
    MOT_FUELCAN = 4,
    MOT_ABILITY = 5,
    MOT_EXPLODED = 6,
    MOT_NULL = 7,
}moving_object_type_t;

#define MOT_COUNT           (7u) //< MOT_NULL not counted



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

    unsigned int cnt; //< generic counter usable for animation (of exploded object / animation of ability)

    object_tick_func tick; //< executed each "tick" --> animation handling (collision detection in player) | set to idle() when unused!
    /// 3 different tick categories: tick_left, tick_mid and tick_right (state about lane in function hardcoded -> and thus LUTs as well)
    /// each category has own tick functions for different speeds
} moving_object_t;




/******************************************************************************************************
 * [precompiled] moving object tick functions (based on current speed)
 ******************************************************************************************************/
#include "game.h"

/**
 * @brief not yet spawned / despawned object is in idle
 */
void idle(__attribute__((unused)) moving_object_t* me);

extern void (* const MOVING_OBJECT_ABILITY_TICK_FNC_LUT[3]) (moving_object_t * me);
extern void (* const MOVING_OBJECT_EXPLODED_TICK_FNC_LUT[3]) (moving_object_t * me);
extern void (* const MOVING_OBJECT_TICK_FNC_LUT[STAGE_T_SIZE][3]) (moving_object_t * me);