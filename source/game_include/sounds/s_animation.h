
#pragma once
#include "sound/sound.h"

// **************************************************************
// menu selection
// **************************************************************
extern const struct sound_music_t menu_select_sound;
extern const struct sound_music_t menu_select_sound_hidden;

// **************************************************************
// start animation
// **************************************************************
extern const struct sound_music_t countdown_number;
extern const struct sound_music_t countdown_go;

// **************************************************************
// car spawn sounds
// **************************************************************
extern const void * const object_spawn_sound[2];

// **************************************************************
// pickup stuff
// **************************************************************
extern const struct sound_music_t pickup_fuel;
extern const struct sound_music_t pickup_ability;

// **************************************************************
// game over sounds
// **************************************************************
extern const struct sound_music_t game_over_sad;
extern const struct sound_explosion_t player_death;

// **************************************************************
// player causing explosions
// **************************************************************

extern const struct sound_explosion_t e_extralife_explosion;
extern const struct sound_explosion_t e_missile_explode_enemy;
extern const struct sound_explosion_t e_missile_shoot;
