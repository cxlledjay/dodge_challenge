#pragma once



/**********************************************************************************************************
 * spawning datastructure
 **********************************************************************************************************/

typedef struct _spawn_entry_t
{
    unsigned int model_id : 3;
    unsigned int opt_model_id : 2;
    unsigned int left_lane : 1;
    unsigned int mid_lane : 1;
    unsigned int right_lane : 1;
}spawn_entry_t;





/**********************************************************************************************************
 * datastructure to save and manage all objects (... a queue with extra steps)
 **********************************************************************************************************/

#include "game_include/object.h"
#define MAX_MOVING_OBJECTS (10u)


typedef struct _object_manager_t
{
    /// object management
    moving_object_t objects[MAX_MOVING_OBJECTS];        //< allocate ram for each object (if object is not active -> set tick() to idle())
    moving_object_t * queue_ptr;                        //< always pointing after last added element

    /// spawning management
    const spawn_entry_t * template;                     //< pointer to precompiled spawning template 
    unsigned int remaining_spawns;                      //< counter to keep track of spawner template progress
    unsigned int cnt;                                   //< counter to regulate spawning intervals 
}object_manager_t;

/// @brief singleton interface for object management
extern object_manager_t the_manager; 

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