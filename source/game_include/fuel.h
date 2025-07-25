#pragma once

/// @brief amount of fuel in percent (valid range: 0-100, 0 -> game over)
typedef unsigned int fuel_amount_t;

/// @brief draw fuel bar
void fuel_bar_draw (void);

/// @brief decrease fuel bar by 1% and check if the game is over now
void fuel_bar_dec (void);
