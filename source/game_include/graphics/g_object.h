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
// 6) extralife + abilities (only missile so far)
// 7) explosion (animated)
// ***************************************************************************
#pragma once
#include "utils/vector.h"

// ***************************************************************************
// enemy models (1-4)
// ***************************************************************************


/// @brief dummy enemy to test stuff
extern const struct packet_t vl_enemy_dummy[];

/// @brief car model nr 1
extern const struct packet_t vl_enemy_car1[];

/// @brief car model nr 2
extern const struct packet_t vl_enemy_car2[];

/// @brief truck model
extern const struct packet_t vl_enemy_truck[];

/// @brief bike model
extern const struct packet_t vl_enemy_bike[];



// ***************************************************************************
// fuel can (5)
// ***************************************************************************


/// @brief spawning fuel can
extern const struct packet_t vl_object_fuelcan[];




// ***************************************************************************
// extralife + abilities (6)
// ***************************************************************************

/// @brief spawning extralife object (MOT_EXTRALIFE)
extern const struct packet_t vl_extralife[];

/// @brief spawning ability object missile (MOT_ABILITY_MISSILE)
extern const struct packet_t vl_ac_missile[];



// ***************************************************************************
// animations (7)
// ***************************************************************************

/// @brief spawning ability (3 step animation)
extern const void* const vl_exploded[3];
