#pragma once



/************************************************************
 * all possible stages (stage range depends on mode)
 ************************************************************/

#define STAGE_T_SIZE (11u)        //< how many different speed levels aka stages
typedef enum _stage_t
{
   GS_VERY_SLOW      = 0,  //< easy start
   GS_QUITE_SLOW     = 1,
   GS_SLOWISH        = 2,  //< normal start
   GS_SLOW           = 3,
   GS_QUITE_NORMAL   = 4,  //< hard start
   GS_NORMAL         = 5,  //< easy stop
   GS_QUITE_FAST     = 6,
   GS_FAST           = 7,  //< normal stop
   GS_VERY_FAST      = 8,
   GS_SPEEDY         = 9,  //< hard stop
   GS_HIDDEN         = 10  //< secret speed
}stage_t;

/// @brief max stage for stage ramping
extern const stage_t game_max_stage[4];

/************************************************************
 * management object (only public because of rand() function)
 ************************************************************/

/// @brief management object for stage ramping
typedef struct _stage_manager_t {
	unsigned long int cnt;
} stage_manager_t;

/// @brief instance of management object
extern stage_manager_t the_stage_manager;


/************************************************************
 * interface
 ************************************************************/

/// @brief init managemet with start menu selection input
void stages_init(void);


/// @brief tick the counter for the next stage increase 
void stages_tick (void);
