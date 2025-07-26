// ***************************************************************************
// graphics/g_map.h
//
// all vector lists used for drawing the road
//
// the middle roadline animation is split in 4 steps and played like a gif
// ***************************************************************************
#pragma once
#include "utils/vector.h"

// ***************************************************************************
// roadline animation (left)
// ***************************************************************************

extern const struct packet_t vl_map_roadline_left_1[];
extern const struct packet_t vl_map_roadline_left_2[];
extern const struct packet_t vl_map_roadline_left_3[];
extern const struct packet_t vl_map_roadline_left_4[];



// ***************************************************************************
// roadline animation (right)
// ***************************************************************************

extern const struct packet_t vl_map_roadline_right_1[];
extern const struct packet_t vl_map_roadline_right_2[];
extern const struct packet_t vl_map_roadline_right_3[];
extern const struct packet_t vl_map_roadline_right_4[];
