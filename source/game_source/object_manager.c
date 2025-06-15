#include "game_include/object_manager.h"


/// @brief nice posh guy
object_manager_t the_manager;




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
    the_manager.template = 0;
    the_manager.remaining_spawns = 0;
    the_manager.cnt = 0;
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

void spawn_objects(void)
{
    /// TODO: implement
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
