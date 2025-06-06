// ***************************************************************************
// print
// ***************************************************************************

#include <vectrex.h>
#include "utils/utils.h"
#include "print.h"

// ---------------------------------------------------------------------------
// print a c string (with \0 at the end) at absolute coordinates (y, x)

void print_char(int y, int x, char c)
{
	char s[4];
	s[0] = c;
	s[1] = ' ';
	s[2] = ' ';
	s[3] = '\x80';
	
	position_beam_s(y, x, 0x7F);
	Print_Str((void*) s);
}

// ***************************************************************************
// end of file
// ***************************************************************************
