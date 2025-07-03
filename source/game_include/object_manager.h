#pragma once



/**********************************************************************************************************
 * spawning datastructure
 **********************************************************************************************************/

#include "game_include/object.h"
typedef struct _spawn_entry_t
{
    unsigned int is_last : 1;       //< flat to indicate last entry
    moving_object_type_t left : 5;  //< object spawning on left lane
    moving_object_type_t mid : 5;   //< object spawning on mid lane
    moving_object_type_t right : 5; //< object spawning on right lane
}spawn_entry_t; //< 2byte datastructure for managing spawning patterns



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
    const spawn_entry_t * pattern;                            //< pointer to precompiled spawning pattern
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