#pragma once
#include "utils/vector.h"



/****************************************************************
 * data structures
 ****************************************************************/

typedef enum _ability_class_t
{
    AC_MISSILE = 0,
    // could add more here...
    AC_NONE
}ability_class_t;

#define ABILITY_COUNT           (1u) //< AC_NONE not counted


//fw decl
struct _active_ability_t;
typedef void (* active_ability_tick_func_t) (struct _active_ability_t * me);

typedef struct _active_ability_t
{
    long path_factor;                   //< factor for dynamic path calculation
    unsigned int cnt;                   //< position, scaling factor and hitbox are derived from cnt
    active_ability_tick_func_t tick;    //< tick function (ability_idle if idling)
} active_ability_t;



typedef struct _ability_manager_t
{
    /// @brief keeping track of active abilities
    active_ability_t used[2];
    int points; //< tracker for animating gotten points
} ability_manager_t;



/****************************************************************
 * interfaces
 ****************************************************************/

/// @brief init function
void ability_init(void);

/// @brief idle function
void ability_idle(active_ability_t * me);

/// @brief show the current abilities the player has
void ability_draw_gui(void);

/// @brief animation of scored points
void ability_play_animation_points(void);



/// @brief calculate dynamic moving path constant "path_factor" and save it to ram
/// @param aa the ability object
/// @param initial_x the x value where the player triggered the ability
void calc_path_factor(active_ability_t * aa, int initial_x);


/// @brief instance to tick all used abilities
extern ability_manager_t the_ability_manager;

/// @brief interface to start ticking an ability
/// @param first the ability type
/// @param second the lane (for viewmodel)
extern void (* const ABILITY_TICK_FNC[ABILITY_COUNT][3]) (active_ability_t* me);
