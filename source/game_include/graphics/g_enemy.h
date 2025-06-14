// ***************************************************************************
// graphics/g_enemy.h
//
// all vector lists to draw enemies
// ***************************************************************************
#pragma once

#include "utils/vector.h"

// ***************************************************************************
// vector lists
// ***************************************************************************


/// @brief dummy enemy to test stuff
const struct packet_t vl_enemy_dummy[] = 
{
    /// move to middle point touching ground
    {MOVE, {0,-42}},

    /// dummy car
    {DRAW, {0,-30}},
    {DRAW, {100,0}},
    {DRAW, {0,72}},
    {DRAW, {0,72}},
    {DRAW, {-100,0}},
    {DRAW, {0,-30}},
    {DRAW, {20,0}},
    {DRAW, {0,-84}},
    {DRAW, {-20,0}},

    /// done
	VL_END
};
