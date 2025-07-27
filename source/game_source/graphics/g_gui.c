#include "game_include/graphics/g_gui.h"

// ***************************************************************************
// fuel bar
// ***************************************************************************

/// @brief fuel can icon for fuel bar
const struct packet_t vl_gui_fuelcan[] = 
{
    /// fuel can
    {DRAW, {-80,0}},
    {DRAW, {0,64}},
    {DRAW, {127,0}},
    {DRAW, {0,-48}},
    {DRAW, {-47,-16}},
    /// spigot
    {DRAW, {32,-32}},

    /// done
	VL_END
};


// ***************************************************************************
// abilities
// ***************************************************************************


const struct packet_t vl_gui_ac_extralife[] =
{
    /// plus
    {DRAW, {0,41}},
    {MOVE, {-20,-20}},
    {DRAW, {41,0}},
    
    /// heart
    {MOVE, {20,41}},
    {DRAW, {-125,125}},
    {DRAW, {125,125}},
    {DRAW, {62,-62}},
    {DRAW, {-62,-62}},
    {DRAW, {62,-62}},
    {DRAW, {-62,-62}},

    /// done
	VL_END
};


const struct packet_t vl_gui_ac_missile[] =
{
    /// rocket body
    {DRAW, {125,125}},
    {DRAW, {0,41}},
    {DRAW, {-41,0}},
    {DRAW, {-125,-125}},
    {DRAW, {41,-41}},

    /// left wing
    {DRAW, {0,-55}},
    {DRAW, {55,55}},
    {DRAW, {0,55}},

    /// left wing
    {MOVE, {-41,41}},
    {DRAW, {-55,0}},
    {DRAW, {-55,-55}},
    {DRAW, {55,0}},

    /// done
    VL_END
};


/// interface


const void* const vl_gui_ac[2] =
{
    vl_gui_ac_extralife,
    vl_gui_ac_missile
};
