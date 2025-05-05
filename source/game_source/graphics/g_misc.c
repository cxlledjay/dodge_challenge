// ***************************************************************************
// graphics/g_misc.h
//
// collection of used miscellaneous sprites
// ***************************************************************************

#include "game_include/graphics/g_misc.h"

// ***************************************************************************
// animated middle line (left and right)
// ***************************************************************************

const struct packet_t _vl_digit_zero[] =
{
    {MOVE, {126,-55}}, //move to top left

    {DRAW, {0,110}},
    {MOVE, {-8,8}},
    {DRAW, {-110,0}},
    {MOVE, {-16,0}},
    {DRAW, {-110,0}},
    {MOVE, {-8,-8}},
    {DRAW, {0,-110}},
    {MOVE, {8,-8}},
    {DRAW, {110,0}},
    {MOVE, {16,0}},
    {DRAW, {110,0}},

    {MOVE, {-118,127}}, //MOVE TO MIDDLE
    VL_END
};


const struct packet_t _vl_digit_one[] =
{
    {MOVE, {118,63}}, //move to top left

    {DRAW, {-110,0}},
    {MOVE, {-16,0}},
    {DRAW, {-110,0}},

    {MOVE, {118,-1}}, //MOVE TO MIDDLE
    VL_END
};


const struct packet_t _vl_digit_two[] =
{
    {MOVE, {126,-55}}, //move to top left

    {DRAW, {0,110}},
    {MOVE, {-8,8}},
    {DRAW, {-110,0}},
    {MOVE, {-8,-8}},
    {DRAW, {0,-110}},
    {MOVE, {-8,-8}},
    {DRAW, {-110,0}},
    {MOVE, {-8,8}},
    {DRAW, {0,110}},

    {MOVE, {126,9}}, //MOVE TO MIDDLE
    VL_END
};


const struct packet_t _vl_digit_three[] =
{
    {MOVE, {126,-55}}, //move to top left

    {DRAW, {0,110}},
    {MOVE, {-8,8}},
    {DRAW, {-110,0}},
    {MOVE, {-16,0}},
    {DRAW, {-110,0}},
    {MOVE, {-8,-8}},
    {DRAW, {0,-110}},
    {MOVE, {126,0}},
    {DRAW, {0,110}},

    {MOVE, {0,9}}, //MOVE TO MIDDLE
    VL_END
};


const struct packet_t _vl_digit_four[] =
{
    {MOVE, {118,-63}}, //move to top left

    {DRAW, {-110,0}},
    {MOVE, {-8,8}},
    {DRAW, {0,110}},
    {MOVE, {118,8}},
    {DRAW, {-110,0}},
    {MOVE, {-16,0}},
    {DRAW, {-110,0}},

    {MOVE, {118,1}}, //MOVE TO MIDDLE
    VL_END
};


const struct packet_t _vl_digit_five[] =
{
    {MOVE, {126,55}}, //move to top right

    {DRAW, {0,-110}},
    {MOVE, {-8,-8}},
    {DRAW, {-110,0}},
    {MOVE, {-8,8}},
    {DRAW, {0,110}},
    {MOVE, {-8,8}},
    {DRAW, {-110,0}},
    {MOVE, {-8,-8}},
    {DRAW, {0,-110}},

    {MOVE, {126,119}}, //MOVE TO MIDDLE
    VL_END
};


const struct packet_t _vl_digit_six[] =
{
    {MOVE, {118,-63}}, //move to top left

    {DRAW, {-110,0}},
    {MOVE, {-16,0}},
    {DRAW, {-110,0}},
    {MOVE, {-8,8}},
    {DRAW, {0,110}},
    {MOVE, {8,8}},
    {DRAW, {110,0}},
    {MOVE, {8,-8}},
    {DRAW, {0,-110}},

    {MOVE, {0,119}}, //MOVE TO MIDDLE
    VL_END
};


const struct packet_t _vl_digit_seven[] =
{
    {MOVE, {126,-55}}, //move to top left

    {DRAW, {0,110}},
    {MOVE, {-8,8}},
    {DRAW, {-110,0}},
    {MOVE, {-16,0}},
    {DRAW, {-110,0}},

    {MOVE, {118,1}}, //MOVE TO MIDDLE
    VL_END
};


const struct packet_t _vl_digit_eight[] =
{
    {MOVE, {126,-55}}, //move to top left

    {DRAW, {0,110}},
    {MOVE, {-8,8}},
    {DRAW, {-110,0}},
    {MOVE, {-16,0}},
    {DRAW, {-110,0}},
    {MOVE, {-8,-8}},
    {DRAW, {0,-110}},
    {MOVE, {8,-8}},
    {DRAW, {110,0}},
    {MOVE, {16,0}},
    {DRAW, {110,0}},
    {MOVE, {-118,8}},
    {DRAW, {0,110}},

    {MOVE, {0,9}}, //MOVE TO MIDDLE
    VL_END
};


const struct packet_t _vl_digit_nine[] =
{
    {MOVE, {-118,63}},

    {DRAW, {110,0}},
    {MOVE, {16,0}},
    {DRAW, {110,0}},
    {MOVE, {8,-8}},
    {DRAW, {0,-110}},
    {MOVE, {-8,-8}},
    {DRAW, {-110,0}},
    {MOVE, {-8,8}},
    {DRAW, {0,110}},

    {MOVE, {0,9}}, //MOVE TO MIDDLE
    VL_END
};




const void* const vl_digits[10] =
{
    _vl_digit_zero,
    _vl_digit_one,
    _vl_digit_two,
    _vl_digit_three,
    _vl_digit_four,
    _vl_digit_five,
    _vl_digit_six,
    _vl_digit_seven,
    _vl_digit_eight,
    _vl_digit_nine
};



const struct packet_t vl_speed_display[] =
{
    //speed sign
    {DRAW, {-64,112}},
    {DRAW, {-64,-112}},
    {MOVE, {0,127}},
    {DRAW, {64,112}},
    {DRAW, {64,-112}},
    {MOVE, {0,127}},
    {DRAW, {-64,112}},
    {DRAW, {-64,-112}},

    //multi symbol
    {MOVE, {0,127}},
    {MOVE, {0,127}},
    {DRAW, {127,127}},
    {MOVE, {0,-127}},
    {DRAW, {-127,127}},

    {MOVE, {96,127}},
    {MOVE, {0,57}},
    VL_END
};
