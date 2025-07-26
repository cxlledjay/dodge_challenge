#pragma once

/// @brief amount of fuel in percent (valid range: 0-100, 0 -> game over)
typedef unsigned int fuel_amount_t;

#define FUEL_CAN_REFILL_AMOUNT      (42) //< refills max 42% each time a fuel can is collected


/// @brief init function 
void fuel_bar_init (void);

/// @brief tick fuel bar
void fuel_bar_tick (void);
