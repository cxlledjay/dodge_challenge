#include "game_include/sounds/s_animation.h"
#include <vectrex.h>

#define MUSIC_END           (128u)
#define NXT_CH              (0b10000000)

#define FULL_NOTE           (31)
#define HALF_NOTE           (16)
#define QUARTER_NOTE        (8)

const struct sound_music_t countdown_number = 
{
	.adsr_table = (struct sound_adsr_table_t*) &Vec_ADSR_FADE4,
	.twang_table = (struct sound_twang_table_t*) &Vec_TWANG_VIBEHL,
	{
		__N_G3 | NXT_CH, __N_D4 | NXT_CH, __N_G4, QUARTER_NOTE,
		0, MUSIC_END
	}
};


const struct sound_music_t countdown_go = 
{
	.adsr_table = (struct sound_adsr_table_t*) &Vec_ADSR_FADE4,
	.twang_table = (struct sound_twang_table_t*) &Vec_TWANG_VIBEHL,
	{
		__N_G4 | NXT_CH, __N_D5 | NXT_CH, __N_G5, HALF_NOTE,
		0, MUSIC_END
	}
};


const struct sound_explosion_t player_death =
{
	0b00101010, SOUND_EXPL_RISE, SOUND_VOL_RISE, 1U
};