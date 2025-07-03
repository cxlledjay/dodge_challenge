#include "game_include/object_manager.h"


/// @brief nice posh guy
object_manager_t the_manager;

/// ------------- temp

const spawn_entry_t temp_pattern[] =
{
    {.is_last = 0, .left = MOT_ENEMY_1, .mid = MOT_NULL, .right = MOT_NULL},
    {.is_last = 0, .left = MOT_ENEMY_1, .mid = MOT_NULL, .right = MOT_ENEMY_1},
    {.is_last = 0, .left = MOT_NULL, .mid = MOT_ENEMY_1, .right = MOT_NULL},
    {.is_last = 0, .left = MOT_ENEMY_1, .mid = MOT_NULL, .right = MOT_NULL},
    {.is_last = 0, .left = MOT_ENEMY_1, .mid = MOT_NULL, .right = MOT_ENEMY_1},
    {.is_last = 0, .left = MOT_NULL, .mid = MOT_NULL, .right = MOT_ENEMY_1}, // 16486 byte
    {.is_last = 0, .left = MOT_NULL, .mid = MOT_NULL, .right = MOT_ENEMY_1}, // 16488 byte??
    {.is_last = 1, .left = MOT_NULL, .mid = MOT_ENEMY_1, .right = MOT_NULL}
};


/**********************************************************************************************************
 * functions
 **********************************************************************************************************/

void om_dummy (void) {}


/// @brief init function
void object_manager_init(void)
{
    /// init each pre allocated object
    moving_object_t new_obj = {.type = 0, .ttl = 0, .model = 0, .tick = idle};
    for(unsigned int i = 0; i < MAX_MOVING_OBJECTS; ++i)
    {
        the_manager.objects[i] = new_obj;
    }
    the_manager.queue_ptr = the_manager.objects;

    /// init spawner stuff
    the_manager.pattern = temp_pattern;
    the_manager.cnt = 50; //< one second delay at start
}                          
    



/**********************************************************************************************************
 * tick function
 **********************************************************************************************************/

void object_manager_tick_all(void)
{
    /// tick all objects (if the object is inactive it will call idle() and return instantly)
    the_manager.objects[0].tick(&the_manager.objects[0]);
    the_manager.objects[1].tick(&the_manager.objects[1]);
    the_manager.objects[2].tick(&the_manager.objects[2]);
    the_manager.objects[3].tick(&the_manager.objects[3]);
    the_manager.objects[4].tick(&the_manager.objects[4]);
    the_manager.objects[5].tick(&the_manager.objects[5]);
    the_manager.objects[6].tick(&the_manager.objects[6]);
    the_manager.objects[7].tick(&the_manager.objects[7]);
    the_manager.objects[8].tick(&the_manager.objects[8]);
    the_manager.objects[9].tick(&the_manager.objects[9]);

    /// done
    return;
}



/**********************************************************************************************************
 * spawn function
 **********************************************************************************************************/


#include "game_include/graphics/g_enemy.h"
const void * const MOT_TYPE_TO_MODEL[] =
{
    0, //< MOT_NONE
    &vl_enemy_dummy //< MOT_ENEMY_1
};


#include "game_include/gen_data/gen_object_path.h"

#define SPAWN_OBJECT(TYPE, LANE)                                                                \
    if(the_manager.queue_ptr->tick == idle){ /* ram is unused */                                \
        the_manager.queue_ptr->model = (void *) MOT_TYPE_TO_MODEL[TYPE];                                 \
        the_manager.queue_ptr->lane = LANE;                                                     \
        the_manager.queue_ptr->type = TYPE;                                                     \
        the_manager.queue_ptr->tick = MOVING_OBJECT_TICK_FNC_LUT[the_game.stage][LANE];         \
        the_manager.queue_ptr->ttl = MOVING_OBJECT_TTL_LUT[the_game.stage];                     \
        /* set queue ptr for next spawn */                                                      \
        if(the_manager.queue_ptr == &the_manager.objects[9]){                                   \
            the_manager.queue_ptr = the_manager.objects;                                        \
        }else{                                                                                  \
            the_manager.queue_ptr++;                                                            \
        }                                                                                       \
    }

void spawn_objects(void)
{
    /// check if pattern contains entity for each lane and then try to spawn it

    if(the_manager.pattern->left != MOT_NULL)
    {
        /// try spawning
        SPAWN_OBJECT(the_manager.pattern->left, LEFT_LANE);
    }

    if(the_manager.pattern->mid != MOT_NULL)
    {
        /// try spawning
        SPAWN_OBJECT(the_manager.pattern->mid, MID_LANE);
    }

    if(the_manager.pattern->right != MOT_NULL)
    {
        /// try spawning
        SPAWN_OBJECT(the_manager.pattern->right, RIGHT_LANE);
    }

    
    /// iterate to next pattern entry and check for end of list
    if((++the_manager.pattern)->is_last == 1)
    {
        /// TODO: select different pattern
        the_manager.pattern = temp_pattern;
    }

    /// done
    return;
}



// fw declares
#include "game_include/game.h"
const unsigned int _OM_NEXT_SPAWN_INTERVAL[];


void object_manager_tick_spawn(void)
{
    if(--(the_manager.cnt) == 0) //< decrease and check at same place
    {
        /// reset counter
        the_manager.cnt = _OM_NEXT_SPAWN_INTERVAL[the_game.stage];

        /// execute spawn algorithm and produce new objects
        spawn_objects();
    }
}

 


/**********************************************************************************************************
 * LUTs for spawn interval modulation
 **********************************************************************************************************/

#include "game_include/game.h"
const unsigned int _OM_NEXT_SPAWN_INTERVAL[STAGE_T_SIZE] =
{
	49,42,35,30,25,21,19,18,14,11,7
};
