#pragma once

/************************************************************
 * datastructure
 ************************************************************/

#include "game_include/object.h"
typedef struct _spawn_entry_t
{
    unsigned int is_last : 1;       //< flag to indicate last entry
    moving_object_type_t left : 5;  //< object spawning on left lane
    moving_object_type_t mid : 5;   //< object spawning on mid lane
    moving_object_type_t right : 5; //< object spawning on right lane
}spawn_entry_t; //< 2 byte datastructure for managing spawning patterns



/************************************************************
 * precompiled spawn patterns
 ************************************************************/

/// @brief empty spawnpattern for stage transitions
extern const spawn_entry_t SP_empty[1];

#define SPAWN_PATTERNS_CNT          (16u)    //< has to be 2^n
#define SPAWN_PATTERN_IDX_BITMASK   (SPAWN_PATTERNS_CNT-1)

/// @brief all spawn patterns accessible by bitmasked rng index (check size of array for bitmask size)
extern const spawn_entry_t * const SPAWN_PATTERN_PTR_COLLECTION[SPAWN_PATTERNS_CNT];
