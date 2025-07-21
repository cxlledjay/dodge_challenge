#pragma once


typedef struct _stage_manager_t
{
    unsigned int frames;                    //< keeping track of frames
    unsigned long next_stage_timer;         //< countdown in seconds until next speed stage
}stage_manager_t;

/**
 * @brief singleton clock instance
 */
extern stage_manager_t the_stage_manager;

/**
 * @brief init function, needs information from start menu
 */
void stage_manager_init(void);

/**
 * ticks the stage_manager (executed in every frame)
 */
void stage_manager_tick(void);