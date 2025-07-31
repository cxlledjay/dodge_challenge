// ***************************************************************************
// graphics/g_misc.h
//
// collection of used miscellaneous sprites
// ***************************************************************************

#include "game_include/graphics/g_misc.h"

// ***************************************************************************
// animated middle line (left and right)
// ***************************************************************************

const struct packet_t vl_game_over_plus[] =
{
    {DRAW, {126, 0}},
    {MOVE, {-63, 0-63}},
    {DRAW, {0, 126}},

    VL_END
};



const struct packet_t vl_game_over_zero_times[] =
{
    ///move to top right
    {MOVE, {126,55}}, 

    /// zero
    {DRAW, {0,-110}},
    {MOVE, {-8,-8}},
    {DRAW, {-110,0}},
    {MOVE, {-16,0}},
    {DRAW, {-110,0}},
    {MOVE, {-8,8}},
    {DRAW, {0,110}},
    {MOVE, {8,8}},
    {DRAW, {110,0}},
    {MOVE, {16,0}},
    {DRAW, {110,0}},

    /// move to "x"
    {MOVE, {-63,72}},

    /// times
    {DRAW, {-110, 110}},
    {MOVE, {110, 0}},
    {DRAW, {-110, -110}},

    VL_END
};



const struct packet_t vl_game_over_equals[] =
{
    {DRAW, {0, 127}},
    {MOVE, {52, 0}},
    {DRAW, {0, -127}},

    VL_END
};


