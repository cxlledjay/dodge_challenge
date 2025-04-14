// ***************************************************************************
// print
// ***************************************************************************

#pragma once
#include <vectrex.h>

// ---------------------------------------------------------------------------
// all functions for debugging purposes only,
// ---------------------------------------------------------------------------

void print_string(int y, int x, char* text);
void print_unsigned_int(int y, int x, unsigned int z);
void print_signed_int(int y, int x, int z);
void print_long_unsigned_int(int y, int x, long unsigned int z);
void print_long_signed_int(int y, int x, long signed int z);
void print_binary(int y, int x, unsigned int z);
void print_long_binary(int y, int x, long unsigned int z);
void print_hex(int y, int x, unsigned int z);
void print_long_hex(int y, int x, long unsigned int z);
void print_char(int y, int x, char c);

// ---------------------------------------------------------------------------

#define PRINT_SCALE 0x7F

// ---------------------------------------------------------------------------
// position vector beam at absolute coordinates

static inline __attribute__((always_inline)) 
void reset_print_position(void)
{
	dp_VIA_cntl = 0xcc;				// zero the integrators, reset beam
	dp_VIA_t1_cnt_lo = PRINT_SCALE;	// set scale
}

// ***************************************************************************
// end of file
// ***************************************************************************
