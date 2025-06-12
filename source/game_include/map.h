#pragma once


typedef struct _map_t
{
    unsigned int cnt; //< used to track roadline animation
    void (*tick) (void); //< used to draw map
} map_t;

/**
 * @brief singleton instance of the map
 *        used to draw and animate the background road
 * 
 * manipulate via different tick() functions (e.g. displaying new speed)
 */
extern map_t the_map;


/**
 * @brief init function
 */
void map_init(void);