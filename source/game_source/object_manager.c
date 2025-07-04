#include "game_include/object_manager.h"



/**********************************************************************************************************
 * global objects
 **********************************************************************************************************/

/// @brief nice posh guy
object_manager_t the_manager;

#include "game_include/random.h"
/// @brief rng object for choosing next spawn pattern (and abilities??)
rng_t om_rng_obj;



/**********************************************************************************************************
 * functions
 **********************************************************************************************************/

/// fw decl:
const spawn_entry_t * get_next_pattern();

/// includes for rng init
#include "game_include/clock.h"
#include "game_include/map.h"
#include "game_include/player.h"

/// debug
#include "vectrex.h"
#include "lib/print/print.h"

/// @brief init function
void object_manager_init(void)
{
    /// build hard to replicate seed
    unsigned int seed0 = 42 + the_clock.frames;                                                     //< hard to time
    unsigned int seed1 = (unsigned int) (the_game.score);                                           //< should always differ
    unsigned int seed2 = (the_manager.queue_ptr - 1)->ttl * ((unsigned int)the_player.lane + 10);   //< might access out of bounds
    unsigned int seed3 = (the_manager.queue_ptr - 3)->ttl * the_map.cnt;                            //< propably out of bounds but idc

    /// init random number gen
    rng_init(&om_rng_obj, seed0, seed1, seed2, seed3);


    /// init ram segement for moving object
    moving_object_t new_obj = {.type = 0, .ttl = 0, .model = 0, .tick = idle};
    for(unsigned int i = 0; i < MAX_MOVING_OBJECTS; ++i)
    {
        the_manager.objects[i] = new_obj;
    }
    the_manager.queue_ptr = the_manager.objects;


    /// init spawner
    the_manager.pattern = get_next_pattern(); //< random start pattern
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
 * spawn functions
 **********************************************************************************************************/

#include "game_include/data/spawn_pattern.h"
const spawn_entry_t * get_next_pattern()
{
    unsigned int idx_bitmasked = rand(&om_rng_obj) &0b00000001;
    return SPAWN_PATTERN_PTR_COLLECTION[idx_bitmasked];
}



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
    if(the_manager.pattern->is_last == 1)
    {
        /// select random next pattern
        the_manager.pattern = get_next_pattern();
    }
    else
    {
        the_manager.pattern++;
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
