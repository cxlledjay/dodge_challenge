#pragma once

/// @brief amount of fuel in percent (valid range: 0-100, 0 -> game over)
typedef unsigned int fuel_amount_t;

#define FUEL_CAN_REFILL_AMOUNT      (42) //< refills max 42% each time a fuel can is collected


/// @brief init function 
void fuel_bar_init (void);

/// @brief tick fuel bar
void fuel_bar_tick (void);


/****************************************************************
 * macros for drawing the fuelbar (needed in game.c as well)
 ****************************************************************/

#define FUELBAR_DRAW(FUEL_PERCENTAGE)           \
    Reset0Ref(); dp_VIA_t1_cnt_lo = 100;        \
    Moveto_d(127, -127);                        \
	dp_VIA_t1_cnt_lo = FUEL_PERCENTAGE;         \
	Draw_Line_d(0,127);                         \
	dp_VIA_t1_cnt_lo = 0x6;                     \
	Draw_Line_d(-20, 0);                        \
	dp_VIA_t1_cnt_lo = FUEL_PERCENTAGE;         \
	Draw_Line_d(0,-127);                        \
	dp_VIA_t1_cnt_lo = 0x6;                     \
	Draw_Line_d(20, 0);                         \
    /* fuel bar icon: */                        \
    Moveto_d(41,-125);                          \
    Draw_VLp(&vl_gui_fuelcan);
