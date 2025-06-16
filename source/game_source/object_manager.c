#include "game_include/object_manager.h"


/// @brief nice posh guy
object_manager_t the_manager;

/// ------------- temp

#define TEMP_SIZE       (10u)
const spawn_entry_t temp_pattern[TEMP_SIZE] =
{
    0b00000001,
    0b00000010,
    0b00000000,
    0b00000001,
    0b00000000,
    0b00000001,
    0b00000010,
    0b00000000,
    0b00000010,
    0b00000010
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
    the_manager.remaining_spawns = TEMP_SIZE;
    the_manager.cnt = 50;
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
#include "game_include/gen_data/gen_object_path.h"

void spawn_objects(void)
{
    /// get current entity to spawn
    if(--(the_manager.remaining_spawns) == 0)
    {
        /// TODO: select different pattern
        //the_manager.pattern = temp_pattern;
        the_manager.remaining_spawns = TEMP_SIZE;
    }

    /// retrieve data
    spawn_entry_t entity = the_manager.pattern[the_manager.remaining_spawns];

    /// get lane from data
    lane_t lane = entity & 0b00000011;

    /// get model from data
    moving_object_type_t type = ENEMY_DUMMY; //< temp

    /// spawn
    if(the_manager.queue_ptr->tick == idle)
    {
        /// can spawn
        the_manager.queue_ptr->model = &vl_enemy_dummy;
        the_manager.queue_ptr->lane = lane;
        the_manager.queue_ptr->type = type;
        the_manager.queue_ptr->tick = MOVING_OBJECT_TICK_FNC_LUT[the_game.stage][lane];
        the_manager.queue_ptr->ttl = MOVING_OBJECT_TTL_LUT[the_game.stage];

        /// set queue ptr for next spawn
        if(the_manager.queue_ptr == &the_manager.objects[9])
        {
            the_manager.queue_ptr = the_manager.objects;
        }
        else
        {
            the_manager.queue_ptr++;
        }
    }
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
