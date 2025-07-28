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


const struct packet_t vl_enemy_car2[] =
{
    /// move to starting point
    {MOVE, {0, -53}},

    /// left wheel
    {DRAW, {0, -50}},
    {DRAW, {80, 0}},
    {DRAW, {0, 50}},
    {DRAW, {-80, 0}},

    /// floor
    {MOVE, {40, 0}},
    {DRAW, {0, 106}},

    /// right wheel
    {MOVE, {40, 0}},
    {DRAW, {-80, 0}},
    {DRAW, {0, 50}},
    {DRAW, {80, 0}},
    {DRAW, {0, -50}},

    /// cabin
    {MOVE, {0, 35}},
    {DRAW, {55, -25}},
    {DRAW, {0, -126}},
    {DRAW, {-55, -25}},

    /// done
    VL_END
};





/// @brief truck model
const struct packet_t vl_enemy_truck[] =
{
    /// move to starting point
    {MOVE, {15,-53}},
    
    /// bottom 1/2
    {DRAW, {-25,0}},
    {DRAW, {0,-35}},
    {DRAW, {25,0}},
    {DRAW, {0,-15}},

    /// main truck
    {DRAW, {30,0}},
    {DRAW, {0,25}},
    {DRAW, {40,-25}},
    {DRAW, {70,0}},
    {DRAW, {0,103}},
    {DRAW, {0,103}},
    {DRAW, {-70,0}},
    {DRAW, {-40,-25}},
    {DRAW, {0,25}},
    {DRAW, {-30,0}},

    /// bottom 2/2
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

    VL_END
};





/// @brief bike model
const struct packet_t vl_enemy_bike[] =
{
    /// move to starting point
    {MOVE, {0,-18}},
    
    /// back wheel
    {DRAW, {60,0}},
    {DRAW, {0,36}},
    {DRAW, {-60,0}},
    {DRAW, {0,-36}},

    /// bike body
    {MOVE, {30,0}},
    {DRAW, {80,-22}},
    {DRAW, {25,15}},
    {DRAW, {0,50}},
    {DRAW, {-25,15}},
    {DRAW, {-80,-22}},

    /// handle bars
    {MOVE, {118,-68}},
    {DRAW, {-3,35}},
    {DRAW, {-10,15}},
    {DRAW, {10,15}},
    {DRAW, {3,35}},

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
// extralife + abilities (6)
// ***************************************************************************


    
const struct packet_t vl_extralife[] =
{ 
    /// heart
    {DRAW, {93,93}},
    {DRAW, {46,-46}},
    {DRAW, {-46,-46}},
    {DRAW, {46,-46}},
    {DRAW, {-46,-46}},
    {DRAW, {-93,93}},

    /// plus
    {MOVE, {75,-96}},
    {DRAW, {0,-45}},
    {MOVE, {22,22}},
    {DRAW, {-45,0}},

    /// done
	VL_END
};

const struct packet_t vl_ac_missile[] =
{
    /// align center
    {MOVE, {41, -12}},

    /// rocket body
    {DRAW, {30,-30}},
    {DRAW, {93,93}},
    {DRAW, {0,30}},
    {DRAW, {-30,0}},
    {DRAW, {-93,-93}},

    /// right wing
    {DRAW, {-41,0}},
    {DRAW, {41,41}},
    {DRAW, {41,0}},

    /// left wing
    {MOVE, {30,-30}},
    {DRAW, {0,-41}},
    {DRAW, {-41,-41}},
    {DRAW, {0,41}},

    /// done
    VL_END
};



// ***************************************************************************
// animations (7)
// ***************************************************************************

/// ------------------ explosion animation -------------------------------------

/// temp
#define _VL_ABILITY_BASE    \
    {MOVE, {0,-15}},        \
    {DRAW, {69,49}},        \
    {DRAW, {0,-32}},        \
    {DRAW, {51,15}},        \
    {DRAW, {-69,-49}},      \
    {DRAW, {0,32}},         \
    {DRAW, {-51,-15}},
const struct packet_t _temp[] =
{
    _VL_ABILITY_BASE
    VL_END
};

const struct packet_t _vl_exploded1[] =
{
    {MOVE ,{40,-20}},

    {DRAW ,{-20,10}},
    {DRAW ,{30,30}},

    {DRAW ,{25,-10}},
    {DRAW ,{-15,-10}},

    {DRAW ,{10,-60}},
    {DRAW ,{-30,40}},

    VL_END
};

const struct packet_t _vl_exploded2[] =
{
    {MOVE, {40,-20}},

    {DRAW, {-25,-70}},
    {DRAW, {35,60}},

    {DRAW, {30,-25}},
    {DRAW, {-10,35}},

    {DRAW, {20,20}},
    {DRAW, {-35,20}},

    {DRAW, {15,45}},
    {DRAW, {-35,-35}},

    {DRAW, {-25,20}},
    {DRAW, {30,-70}},

    VL_END
};

const struct packet_t _vl_exploded3[] =
{
    {MOVE, {40,-30}},

    {DRAW, {-35,-60}},
    {DRAW, {65,40}},

    {DRAW, {50,-15}},
    {DRAW, {-35,40}},

    {DRAW, {40,65}},
    {DRAW, {-35,-15}},

    {DRAW, {-50,40}},
    {DRAW, {-10,-35}},

    {DRAW, {-35,-25}},
    {DRAW, {45,-35,}},

    VL_END
};

const struct packet_t _vl_exploded4[] =
{
    {DRAW, {30,-60}},

    {DRAW, {-20,-60}},
    {DRAW, {40,20}},

    {DRAW, {10,-20}},
    {DRAW, {20,30}},

    {DRAW, {60,25}},
    {DRAW, {-25,45}},

    {DRAW, {40,50}},
    {DRAW, {-35,20}},

    {DRAW, {30,60}},
    {DRAW, {-70,-25}},

    {DRAW, {-45,30}},
    {DRAW, {10,-45}},
    

    {DRAW, {-45,-70}},

    VL_END
};

const void* const vl_exploded[4] =
{
    _vl_exploded4,
    _vl_exploded3,
    _vl_exploded2,
    _vl_exploded1
};



// ***************************************************************************
// fired missiles (8)
// ***************************************************************************

/// @brief fired missiles
const struct packet_t vl_fired_missile_mid[] =
{
    /// left missile
    {MOVE, {0,-63}},
    {DRAW, {126,21}},

    /// right missile
    {MOVE, {0,84}},
    {DRAW, {-126,21}},

    /// done
    VL_END
};


/// @brief fired missiles left
const struct packet_t vl_fired_missile_left[] =
{
    /// left missile
    {MOVE, {0,-68}},
    {DRAW, {126,53}},

    /// right missile
    {MOVE, {0,84}},
    {DRAW, {-126,-39}},

    /// done
    VL_END
};

/// @brief fired missiles right
const struct packet_t vl_fired_missile_right[] =
{
    /// left missile
    {MOVE, {0,68}},
    {DRAW, {126,-53}},

    /// right missile
    {MOVE, {0,-84}},
    {DRAW, {-126,39}},

    /// done
    VL_END
};