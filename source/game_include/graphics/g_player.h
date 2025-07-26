// ***************************************************************************
// graphics/g_player.h
//
// all vector lists to draw the player
// ***************************************************************************
#pragma once
#include "utils/vector.h"

// ***************************************************************************
// vector list pointer to different perspectives of player model
//
// they are split into multiple lists, to reset the electron beam
// inbetween, to reduce analog inaccuracy
// ***************************************************************************

/// mid lane player model

extern const struct packet_t vl_player_mid1[];
extern const struct packet_t vl_player_mid2[];


/// left lane player model

extern const struct packet_t vl_player_left1[];
extern const struct packet_t vl_player_left2[];
extern const struct packet_t vl_player_left3[];


/// left lane player model

extern const struct packet_t vl_player_right1[];
extern const struct packet_t vl_player_right2[];
extern const struct packet_t vl_player_right3[];
