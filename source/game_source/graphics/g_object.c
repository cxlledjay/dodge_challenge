#include "game_include/graphics/g_object.h"


// ***************************************************************************
// enemy models
// ***************************************************************************

/// @brief dummy enemy to test stuff
const struct packet_t vl_enemy_dummy[] = 
{
    /// move to middle point touching ground
    {MOVE, {0,-42}},

    /// dummy car
    {DRAW, {0,-30}},
    {DRAW, {70,0}},
    {DRAW, {30,42}},
    {DRAW, {0,60}},
    {DRAW, {-30,42}},
    {DRAW, {-70,0}},
    {DRAW, {0,-30}},
    {DRAW, {20,0}},
    {DRAW, {0,-84}},
    {DRAW, {-20,0}},

    /// done
	VL_END
};



const struct packet_t vl_enemy_car1[] =
{
    /// move to starting point
    {MOVE, {15,-53}},
    
    /// chassis
    {DRAW, {-25,0}},
    {DRAW, {0,-35}},
    {DRAW, {25,0}},
    {DRAW, {0,-15}},
    {DRAW, {65,0}},
    {DRAW, {0,15}},
    {DRAW, {55,25}},
    {DRAW, {0,126}},
    {DRAW, {-55,25}},
    {DRAW, {0,15}},
    {DRAW, {-65,0}},
    {DRAW, {0,-15}},
    {DRAW, {-25,0}},
    {DRAW, {0,-35}},
    {DRAW, {25,0}},
    {DRAW, {0,-106}},

    /// lights
    {MOVE, {40,-35}},
    {DRAW, {0,30}},
    {MOVE, {0,116}},
    {DRAW, {0,30}},

    /// done
    VL_END
};




// ***************************************************************************
// fuel can (5)
// ***************************************************************************


/// @brief spawning fuel can
const struct packet_t vl_object_fuelcan[] =
{
    /// fuel can 1/2
    {MOVE, {0,45}},
    {DRAW, {0,-90}},
    {DRAW, {90,0}},
    
    /// cap
    {DRAW, {7,7}},
    {DRAW, {10,-10}},
    {DRAW, {21,21}},
    {DRAW, {-10,10}},
    {MOVE, {-21,-21}},
    {DRAW, {28,28}},
    
    /// fuel can 2/2
    {DRAW, {0,55}},
    {DRAW, {-125,0}},

    /// done
	VL_END
};





// ***************************************************************************
// animations (6-7)
// ***************************************************************************

/// ------------------ ability animation -------------------------------------

#define _VL_ABILITY_BASE    \
    {MOVE, {0,-15}},        \
    {DRAW, {69,49}},        \
    {DRAW, {0,-32}},        \
    {DRAW, {51,15}},        \
    {DRAW, {-69,-49}},      \
    {DRAW, {0,32}},         \
    {DRAW, {-51,-15}},

const struct packet_t _vl_ability_step1[] =
{
    /// ability icon
    _VL_ABILITY_BASE

    /// done
	VL_END
};

const struct packet_t _vl_ability_step2[] =
{
    /// ability icon
    _VL_ABILITY_BASE

    /// done
	VL_END
};

const struct packet_t _vl_ability_step3[] =
{
    /// ability icon
    _VL_ABILITY_BASE

    /// done
	VL_END
};

const struct packet_t _vl_ability_step4[] =
{
    /// ability icon
    _VL_ABILITY_BASE

    /// done
	VL_END
};



const void* const vl_ability[4] =
{
    _vl_ability_step1,
    _vl_ability_step2,
    _vl_ability_step3,
    _vl_ability_step4
};

/// ------------------ explosion animation -------------------------------------


const void* const vl_exploded[3] =
{
    _vl_ability_step1,
    _vl_ability_step2,
    _vl_ability_step3
};