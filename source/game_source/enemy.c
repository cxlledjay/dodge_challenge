#include "game_include/enemy.h"


/**********************************************************************************************************
 * datastructure to save and manage all enemies... basically a queue with less steps.
 **********************************************************************************************************/
#include "game_include/object.h"

#define MAX_ENEMIES (1u)
moving_object_t enemy_list[MAX_ENEMIES]; //< allocate ram for each enemy (if enemy is not active -> set tick() to idle())
moving_object_t * queue_ptr; //< always points to a location where an enemy can be added (queue tail)






/**********************************************************************************************************
 * functions
 **********************************************************************************************************/
#include "game_include/object.h"

/// @brief init all enemies as idle
void enemy_init(void)
{
    moving_object_t empty_enemy = {.tick = idle};
    for(unsigned int i = 0; i < MAX_ENEMIES; ++i)
    {
        enemy_list[i] = empty_enemy;
    }
    queue_ptr = &enemy_list[0];
}

#if 0
int moving_object_try_spawn(__attribute__((unused)) lane_t lane)

{
    int ret = -1;
    //check if queue has space
    if(queue_ptr->tick == idle) 
    {
        #define spawn_y (30) //< TODO: adjust!
        // TODO: add rng to set different tick functions (one func for car model, one func for truck model, ...)
        //moving_object_t new_enemy = {.my_lane = lane, .y = spawn_y, .cnt = 0, .tick = tick_dummy};

        //check if spawn would make sense
        //e.g. already two enemies in same lane
        //e.g. enemy would collide with recently spawned enemy
        //...

        //*queue_ptr = new_enemy;
        ret = 0;
    }
    //queue has no space
    else
    {
        ret = -1;
    }
    return ret;
}
#endif 


/// debug
#include "game_include/graphics/g_enemy.h"
#include "game_include/object.h"
#include "game_include/gen_data/gen_object_path.h"

moving_object_t temp = {.type = ENEMY_DUMMY, .ttl = 0, .tick = idle, .model = &vl_enemy_dummy};

void enemy_debug(void)
{
    if(temp.tick == idle)
    {
        temp.tick = MOVING_OBJECT_TICK_FNC_LUT[6][MID_LANE];
        temp.ttl = MOVING_OBJECT_TTL_LUT[6];
        return;
    }

    temp.tick(&temp);
}
