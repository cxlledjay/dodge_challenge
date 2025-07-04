#include "game_include/data/spawn_pattern.h"


const spawn_entry_t temp_pattern[] =
{
    {.is_last = 0, .left = MOT_ENEMY_1, .mid = MOT_NULL, .right = MOT_NULL},
    {.is_last = 0, .left = MOT_ENEMY_1, .mid = MOT_NULL, .right = MOT_ENEMY_1},
    {.is_last = 0, .left = MOT_NULL, .mid = MOT_ENEMY_1, .right = MOT_NULL},
    {.is_last = 0, .left = MOT_ENEMY_1, .mid = MOT_NULL, .right = MOT_NULL},
    {.is_last = 0, .left = MOT_ENEMY_1, .mid = MOT_NULL, .right = MOT_ENEMY_1},
    {.is_last = 0, .left = MOT_NULL, .mid = MOT_NULL, .right = MOT_ENEMY_1},
    {.is_last = 0, .left = MOT_NULL, .mid = MOT_NULL, .right = MOT_ENEMY_1},
    {.is_last = 1, .left = MOT_NULL, .mid = MOT_ENEMY_1, .right = MOT_NULL}
};


const spawn_entry_t temp_pattern1[] =
{
    {.is_last = 0, .left = MOT_ENEMY_1, .mid = MOT_NULL, .right = MOT_NULL},
    {.is_last = 0, .left = MOT_ENEMY_1, .mid = MOT_NULL, .right = MOT_NULL},
    {.is_last = 1, .left = MOT_ENEMY_1, .mid = MOT_NULL, .right = MOT_NULL},
};

const spawn_entry_t temp_pattern2[] =
{
    {.is_last = 0, .left = MOT_NULL, .mid = MOT_NULL, .right = MOT_ENEMY_1},
    {.is_last = 0, .left = MOT_NULL, .mid = MOT_NULL, .right = MOT_ENEMY_1},
    {.is_last = 1, .left = MOT_NULL, .mid = MOT_NULL, .right = MOT_ENEMY_1},
};















/************************************************************
 * connecting all spawn patterns to indexed interface for rng
 ************************************************************/

const spawn_entry_t * const SPAWN_PATTERN_PTR_COLLECTION[SPAWN_PATTERNS_CNT] =
{
    temp_pattern1,
    temp_pattern2
};