#include "game_include/sounds/s_animation.h"
#include <vectrex.h>

#define MUSIC_END           (128u)
#define NXT_CH              (0b10000000)

#define FULL_NOTE           (31)
#define HALF_NOTE           (16)
#define QUARTER_NOTE        (8)
#define EIGTH_NOTE        	(4)



const struct sound_music_t menu_select_sound =
{
	.adsr_table = (struct sound_adsr_table_t*) &Vec_ADSR_FADE4,
	.twang_table = (struct sound_twang_table_t*) &Vec_TWANG_VIBEHL,
	{
		__N_CS4, QUARTER_NOTE,
		0, MUSIC_END
	}
};

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







const struct sound_music_t _object_spawn_sound1 = 
{
	.adsr_table = (struct sound_adsr_table_t*) &Vec_ADSR_FADE12,
	.twang_table = (struct sound_twang_table_t*) &Vec_TWANG_VIBE0,
	{
		__N_CS4, QUARTER_NOTE,
		0, MUSIC_END
	}
};

const struct sound_music_t _object_spawn_sound2 = 
{
	.adsr_table = (struct sound_adsr_table_t*) &Vec_ADSR_FADE12,
	.twang_table = (struct sound_twang_table_t*) &Vec_TWANG_VIBE0,
	{
		__N_GS2, QUARTER_NOTE,
		0, MUSIC_END
	}
};

const void * const object_spawn_sound[2] =
{
	&_object_spawn_sound1,
	&_object_spawn_sound2
};






const struct sound_music_t pickup_fuel =
{
	.adsr_table = (struct sound_adsr_table_t*) &Vec_ADSR_FADE4,
	.twang_table = (struct sound_twang_table_t*) &Vec_TWANG_VIBEHL,
	{
		__N_C3 | NXT_CH, __N_E3 | NXT_CH, __N_G3, EIGTH_NOTE,
		__N_F3 | NXT_CH, __N_A3 | NXT_CH, __N_C4, EIGTH_NOTE,
		__N_A3 | NXT_CH, __N_C4 | NXT_CH, __N_E4, EIGTH_NOTE,
		__N_B3 | NXT_CH, __N_D4 | NXT_CH, __N_F4, EIGTH_NOTE,
		0, MUSIC_END
	}
};


const struct sound_music_t pickup_ability =
{
	.adsr_table = (struct sound_adsr_table_t*) &Vec_ADSR_FADE4,
	.twang_table = (struct sound_twang_table_t*) &Vec_TWANG_VIBEHL,
	{
		__N_D4 | NXT_CH, __N_F4 | NXT_CH, __N_A4, EIGTH_NOTE,
		__N_E5 | NXT_CH, __N_C6 | NXT_CH, __N_G6, QUARTER_NOTE,
		0, MUSIC_END
	}
};






const struct sound_music_t game_over_sad =
{
	.adsr_table = (struct sound_adsr_table_t*) &Vec_ADSR_FADE0,
	.twang_table = (struct sound_twang_table_t*) &Vec_TWANG_VIBENL,
	{
		__N_C4, QUARTER_NOTE,
		__N_C4, QUARTER_NOTE,
		__N_C4, QUARTER_NOTE,
		__N_G2, FULL_NOTE,
		0, MUSIC_END
	}
};





const struct sound_explosion_t player_death =
{
	0b00101010, SOUND_EXPL_RISE, SOUND_VOL_RISE, 1U
};









const struct sound_explosion_t e_extralife_explosion =
{
	0b00000100, SOUND_EXPL_EVEN, SOUND_VOL_RISE, 2U
};

const struct sound_explosion_t e_missile_explode_enemy =
{
	0b00011100, SOUND_EXPL_RISE, SOUND_VOL_RISE, 3U
};

const struct sound_explosion_t e_missile_shoot =
{
	0b00111100, SOUND_EXPL_RISE, SOUND_VOL_RISE, 8U
};