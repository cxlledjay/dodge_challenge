// ***************************************************************************
// vectrex cartridge init block - edit to set game title
// ***************************************************************************

#include <vectrex.h>

#include "utils/utils.h"
#include "cartridge.h"

// ---------------------------------------------------------------------------
// game title

const struct cartridge_t game_header __attribute__((section(".cartridge"), used)) = 
{
	.copyright 		= "g GCE 2025\x80",
	.music 			= &Vec_Music_1,
	.title_height	= TEXT_HEIGHT_L,
	.title_width	= TEXT_WIDTH_L,
	.title_y 		= 40,
	.title_x 		= CENTER_TEXT(TEXT_WIDTH_L, 15),
	.title			= "DODGE CHALLENGE\x80",
};

// ---------------------------------------------------------------------------

__asm(". = . - 1\n\t"); // this is soooo dirty...
const int end_of_cartridge_header __attribute__((section(".cartridge"), used)) = 0;

// ***************************************************************************
// end of file
// ***************************************************************************
