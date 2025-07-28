#pragma once

/**********************************************************************************************************
 * datastructure to save and manage all objects (... a queue with extra steps)
 **********************************************************************************************************/

#include "game_include/object.h"
#include "game_include/data/spawn_pattern.h"
#define MAX_MOVING_OBJECTS (10u)


typedef struct _object_manager_t
{
    /// object management
    moving_object_t objects[MAX_MOVING_OBJECTS];        //< allocate ram for each object (if object is not active -> set tick() to idle())
    moving_object_t * queue_ptr;                        //< always pointing after last added element

    /// spawning management
    unsigned int next_stage;                            //< bit set by stage management, to indicate speed ramp up
    const spawn_entry_t * pattern;                      //< pointer to precompiled spawning pattern
    unsigned int cnt;                                   //< counter to regulate spawning intervals
    unsigned int cnt_next_fuelcan;                      //< counter to track next fuelcan spawning
    unsigned int cnt_next_ability;                      //< counter to track next ability spawning

    /// sound management
    unsigned int next_sound;
}object_manager_t;

/// @brief singleton interface for object management
extern object_manager_t the_object_manager; 

// you may not speak to the manager right now...



/**********************************************************************************************************
 * functions
 **********************************************************************************************************/

/// @brief init function
void object_manager_init(void);


/// @brief tick all objects
void object_manager_tick_all(void);


/// @brief tick spawning function
void object_manager_tick_spawn(void);