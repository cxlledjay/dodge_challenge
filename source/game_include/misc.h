#pragma once

typedef enum
{
    LEFT_LANE = 0,
    MID_LANE = 1,
    RIGHT_LANE = 2
} lane_t;


void convert_bin_to_bcd (unsigned int bin, int * bcd, unsigned int bcd_len);