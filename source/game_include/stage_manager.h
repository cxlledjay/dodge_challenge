#pragma once


typedef struct _stage_manager_t
{
    unsigned int frames;                    //< keeping track of frames
    unsigned int next_stage_timer;         //< countdown in seconds until next speed stage
    void (* tick) (void);                   //< tick function as function pointer -> able to disable stage increase
}stage_manager_t;

/**
 * @brief singleton clock instance
 */
extern stage_manager_t the_stage_manager;

/**
 * @brief init function, needs information from start menu
 */
void stage_manager_init(void);