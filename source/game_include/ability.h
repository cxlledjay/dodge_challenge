#pragma once
#include "utils/vector.h"



/****************************************************************
 * data structures
 ****************************************************************/

typedef enum _ability_class_t
{
    AC_EXTRALIFE = 0,
    AC_MISSILE = 1,
    AC_NONE = 2
}ability_class_t;

#define ABILITY_COUNT           (2u) //< AC_NONE not counted


typedef struct _ability_manager_t {
    /** management of first ability */
    unsigned int cnt1;              //< counter for animation managing
    void (* tick1) (void);          //< tick function

    /** backup management of possible second ability (e.g. player shoots missile, picks up missile, shoots again) */
    unsigned int cnt2;              //< backup counter
    void (* tick2) (void);          //< backup tick function

    /** gui */
    void (* draw_gui) (void);       //< show player which ability he currently has (if he has one)
} ability_manager_t;



/****************************************************************
 * interfaces
 ****************************************************************/

/// @brief init function
void ability_init(void);

/// @brief idle function
void ability_idle(void);



/// @brief instance to tick all used abilities
extern ability_manager_t the_ability_manager;

/// @brief interface to start ticking an ability
/// @param first the ability type
/// @param second the lane
extern void (* ABILITY_TICK_FNC[ABILITY_COUNT][3]) (void);

/// @brief interface for drawing gui
/// @param first the ability type (AC_NONE is included)
extern void (* ABILITY_DRAW_GUI_FNC[ABILITY_COUNT+1]) (void);
