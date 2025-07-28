#include "game_include/object_manager.h"
#include "game_include/random.h"


/**********************************************************************************************************
 * global objects
 **********************************************************************************************************/

object_manager_t the_object_manager;




/**********************************************************************************************************
 * functions
 **********************************************************************************************************/

/// fw decl:
static inline __attribute__((always_inline)) const spawn_entry_t * get_next_pattern (void);
static inline __attribute__((always_inline)) unsigned int get_next_interval (void);

/// includes for rng init
#include "game_include/stage.h"
#include "game_include/map.h"
#include "game_include/player.h"

/// debug
#include "vectrex.h"
#include "lib/print/print.h"

/// @brief init function
void object_manager_init(void)
{
    /// build hard to replicate seed
    unsigned int seed0 = 42 + (unsigned int) the_stage_manager.cnt;                                         //< hard to time
    unsigned int seed1 = (unsigned int) (the_game.score[6]);                                                //< should always differ
    unsigned int seed2 = (the_object_manager.queue_ptr - 1)->ttl * ((unsigned int)the_player.lane + 10);    //< might access out of bounds
    unsigned int seed3 = (the_object_manager.queue_ptr - 3)->ttl * the_map.cnt;                             //< propably out of bounds but idc

    /// init random number gen
    rng_init(&random_obj, seed0, seed1, seed2, seed3);


    /// init ram segement for moving object
    moving_object_t new_obj = {.type = 0, .ttl = 0, .cnt = 0, .model = 0, .tick = idle};
    for(unsigned int i = 0; i < MAX_MOVING_OBJECTS; ++i)
    {
        the_object_manager.objects[i] = new_obj;
    }
    the_object_manager.queue_ptr = the_object_manager.objects;


    /// init spawner
    the_object_manager.pattern = get_next_pattern(); //< random start pattern
    the_object_manager.cnt = 15; //< small delay at start, to keep the sound from start animation
    the_object_manager.cnt_next_fuelcan = get_next_interval();
    the_object_manager.cnt_next_ability = get_next_interval() >> 1;

    the_object_manager.next_sound = 0;
}




/**********************************************************************************************************
 * tick function
 **********************************************************************************************************/

void object_manager_tick_all(void)
{
    /// tick all objects (if the object is inactive it will call idle() and return instantly)
    the_object_manager.objects[0].tick(&the_object_manager.objects[0]);
    the_object_manager.objects[1].tick(&the_object_manager.objects[1]);
    the_object_manager.objects[2].tick(&the_object_manager.objects[2]);
    the_object_manager.objects[3].tick(&the_object_manager.objects[3]);
    the_object_manager.objects[4].tick(&the_object_manager.objects[4]);
    the_object_manager.objects[5].tick(&the_object_manager.objects[5]);
    the_object_manager.objects[6].tick(&the_object_manager.objects[6]);
    the_object_manager.objects[7].tick(&the_object_manager.objects[7]);
    the_object_manager.objects[8].tick(&the_object_manager.objects[8]);
    the_object_manager.objects[9].tick(&the_object_manager.objects[9]);

    /// done
    return;
}



/**********************************************************************************************************
 * spawn functions
 **********************************************************************************************************/

#include "game_include/data/spawn_pattern.h"
static inline __attribute__((always_inline)) const spawn_entry_t * get_next_pattern (void)
{
    unsigned int idx_bitmasked = rand(&random_obj) & SPAWN_PATTERN_IDX_BITMASK;
    return SPAWN_PATTERN_PTR_COLLECTION[idx_bitmasked];
}

/// @brief calculate next spawn interval for fuel or ability
/// @return random value between 31 and 47
static inline __attribute__((always_inline)) unsigned int get_next_interval (void)
{
    return (rand(&random_obj) >> 4) + 31; //< range: 31-47
}


#include "game_include/graphics/g_object.h"
const void * const MOT_TYPE_TO_MODEL[] =
{
    &vl_enemy_car1, //< MOT_ENEMY_CAR1
    &vl_enemy_car2, //< MOT_ENEMY_CAR2
    &vl_enemy_truck, //< MOT_ENEMY_TRUCK
    &vl_enemy_bike, //< MOT_ENEMY_BIKE
    &vl_object_fuelcan, //< MOT_FUELCAN
    &vl_extralife, //< MOT_EXTRALIFE
    &vl_ac_missile //< MOT_ABILITY_MISSILE
};


#include "game_include/gen_data/gen_object_path.h"

static inline __attribute__((always_inline)) void try_spawn_obj (moving_object_type_t type, lane_t lane)
{
    /// check if datastructure has free slot
    if(the_object_manager.queue_ptr->tick == idle)
    {
        /// attempt to replace enemy in pattern with fuelcan
        if(--(the_object_manager.cnt_next_fuelcan) == 0)
        {
            /// reset counter to random value
            the_object_manager.cnt_next_fuelcan = get_next_interval();

            /// spawn fuelcan
            the_object_manager.queue_ptr->model = (void *) MOT_TYPE_TO_MODEL[MOT_FUELCAN];
            the_object_manager.queue_ptr->lane = lane;
            the_object_manager.queue_ptr->type = MOT_FUELCAN;
            the_object_manager.queue_ptr->tick = MOVING_OBJECT_TICK_FNC_LUT[the_game.stage][lane];
            the_object_manager.queue_ptr->ttl = MOVING_OBJECT_TTL_LUT[the_game.stage];
        }
        /// attempt to replace enemy in pattern with extralife / ability
        else if (--(the_object_manager.cnt_next_ability) == 0)
        {
            /// reset counter to random value
            the_object_manager.cnt_next_ability = get_next_interval() >> 1; //< more abilities than fuel ?

            /// select type
            unsigned int type = 1; //< 75% chance for missiles
            if((rand(&random_obj) >> 6) == 0)
            {
                type = 0; //< 25% chance for extralife
            }

            /// spawn object
            the_object_manager.queue_ptr->type = type + 5; //< generate and translate ability class to moving_object_t
            the_object_manager.queue_ptr->model = (void *) MOT_TYPE_TO_MODEL[the_object_manager.queue_ptr->type];
            the_object_manager.queue_ptr->lane = lane;
            the_object_manager.queue_ptr->tick = MOVING_OBJECT_TICK_FNC_LUT[the_game.stage][lane];
            the_object_manager.queue_ptr->ttl = MOVING_OBJECT_TTL_LUT[the_game.stage];
        }
        /// continue with spawn pattern
        else
        {
            /// spawn object from spawn pattern
            the_object_manager.queue_ptr->model = (void *) MOT_TYPE_TO_MODEL[type];
            the_object_manager.queue_ptr->lane = lane;
            the_object_manager.queue_ptr->type = type;
            the_object_manager.queue_ptr->tick = MOVING_OBJECT_TICK_FNC_LUT[the_game.stage][lane];
            the_object_manager.queue_ptr->ttl = MOVING_OBJECT_TTL_LUT[the_game.stage];
        }

        /* set queue ptr for next spawn */
        if(the_object_manager.queue_ptr == &the_object_manager.objects[9]){
            the_object_manager.queue_ptr = the_object_manager.objects;
        }else{
            the_object_manager.queue_ptr++;
        }
    }
}




void spawn_objects(void)
{
    /// check if pattern contains entity for each lane and then try to spawn it

    if(the_object_manager.pattern->left != MOT_NULL)
    {
        /// try spawning
        try_spawn_obj(the_object_manager.pattern->left, LEFT_LANE);
    }

    if(the_object_manager.pattern->mid != MOT_NULL)
    {
        /// try spawning
        try_spawn_obj(the_object_manager.pattern->mid, MID_LANE);
    }

    if(the_object_manager.pattern->right != MOT_NULL)
    {
        /// try spawning
        try_spawn_obj(the_object_manager.pattern->right, RIGHT_LANE);
    }

    
    /// iterate to next pattern entry and check for end of list
    if(the_object_manager.pattern->is_last == 1)
    {
        if(the_object_manager.next_stage)
        {
            /// stage transition -> don't spawn enemies for a short amout of time
            the_object_manager.pattern = SP_empty;

            the_game.stage++; //< increase stage
            the_object_manager.next_stage = 0; //< reset next stage flag
        }
        else
        {
            /// select random next pattern
            the_object_manager.pattern = get_next_pattern();
        }
    }
    else
    {
        the_object_manager.pattern++;
    }

    /// done
    return;
}



// fw declares
#include "game_include/game.h"
const unsigned int _OM_NEXT_SPAWN_INTERVAL[];

#include "game_include/sounds/s_animation.h"
void object_manager_tick_spawn(void)
{
    if(--(the_object_manager.cnt) == 0) //< spawn object in this frame?
    { //< yes

        /// reset counter
        the_object_manager.cnt = _OM_NEXT_SPAWN_INTERVAL[the_game.stage];

        /// execute spawn algorithm and produce new objects
        spawn_objects();

        /// alternate sound
        unsigned int idx = ++(the_object_manager.next_sound) & 0x01;

        /// play spawning sound
        play_music((struct sound_music_t *) object_spawn_sound[idx]);
        
        /// increase score
        Add_Score_a(the_game.stage + 1 , the_game.score);
    }
}

 


/**********************************************************************************************************
 * LUTs for spawn interval modulation
 **********************************************************************************************************/

#include "game_include/game.h"
const unsigned int _OM_NEXT_SPAWN_INTERVAL[STAGE_T_SIZE] =
{
	49,42,35,30,25,21,19,18,16,14,9
};
