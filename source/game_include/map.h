#pragma once


struct _map_t; //forward declaration so player_tick_func knows about the object its stored in
typedef void (* map_tick_func) (struct _map_t * me);

typedef struct _map_t
{
    unsigned int cnt; //< used to track roadline animation
    map_tick_func tick; //< used to draw map
} map_t;

/**
 * @brief singleton instance of the map
 *        used to draw and animate the background road
 * 
 * manipulate via different tick() functions (e.g. displaying new speed)
 */
extern map_t the_map;


void map_init(void);