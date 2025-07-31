#pragma once

typedef enum
{
    LEFT_LANE = 0,
    MID_LANE = 1,
    RIGHT_LANE = 2
} lane_t;

/// @brief (fake bios routine) substraction method for acsii encoded bcd arrays
/// @param a number to subtract from x
/// @param x pointer to ascii encoded bcd array
void Sub_Score_a(unsigned int a, void* x);
