#pragma once


typedef struct _clock_t
{
    unsigned int frames;        //< in wich frame in a second am i?
    unsigned long seconds;      //< seconds since game started
}clock_t;

/**
 * @brief singleton clock instance
 */
extern clock_t the_clock;

/**
 * @brief init function
 */
void clock_init(void);

/**
 * ticks the clock (executed in every frame)
 */
void clock_tick(void);