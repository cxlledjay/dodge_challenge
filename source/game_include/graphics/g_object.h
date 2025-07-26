// ***************************************************************************
// graphics/g_object.h
//
// all vector lists to draw moving objects, those include:
//
// 1) "enemy" car 1
// 2) "enemy" car 2
// 3) "enemy" truck
// 4) "enemy" motorcycle
// 5) fuel can
// 6) ability
// ***************************************************************************
#pragma once
#include "utils/vector.h"

// ***************************************************************************
// enemy models
// ***************************************************************************


/// @brief dummy enemy to test stuff
extern const struct packet_t vl_enemy_dummy[];


extern const struct packet_t vl_enemy_car1[];



// ***************************************************************************
// collectables
// ***************************************************************************


/// @brief spawning fuel can
extern const struct packet_t vl_object_fuelcan[];


/// @brief spawning ability (4 step animation)
extern const void* const vl_ability[4];
