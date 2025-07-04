#pragma once

/************************************************************
 * datastructure
 ************************************************************/

#include "game_include/object.h"
typedef struct _spawn_entry_t
{
    unsigned int is_last : 1;       //< flat to indicate last entry
    moving_object_type_t left : 5;  //< object spawning on left lane
    moving_object_type_t mid : 5;   //< object spawning on mid lane
    moving_object_type_t right : 5; //< object spawning on right lane
}spawn_entry_t; //< 2byte datastructure for managing spawning patterns



/************************************************************
 * precompiled spawn patterns
 ************************************************************/

#define SPAWN_PATTERNS_CNT          (4u)    //< has to be 2^n
#define SPAWN_PATTERN_IDX_BITMASK   (SPAWN_PATTERNS_CNT-1)

/// @brief all spawn patterns accessible by bitmasked rng index (check size of array for bitmask size)
extern const spawn_entry_t * const SPAWN_PATTERN_PTR_COLLECTION[SPAWN_PATTERNS_CNT];
