#include "game_include/ability.h"
#include "game_include/player.h"
#include "game_include/object.h"


/// @brief idle function (does nothing)
void ability_idle(__attribute__((unused)) active_ability_t* me){return;}

//fw decl
void _tick_ac_missile_left (active_ability_t* me);
void _tick_ac_missile_mid (active_ability_t* me);
void _tick_ac_missile_right (active_ability_t* me);


/****************************************************************
 * interfaces
 ****************************************************************/


ability_manager_t the_ability_manager;

void (* const ABILITY_TICK_FNC[ABILITY_COUNT][3]) (active_ability_t* me) =
{
    {
        _tick_ac_missile_left,
        _tick_ac_missile_mid,
        _tick_ac_missile_right
    }
};


void ability_init(void)
{
    /// init with no active ability
    active_ability_t inactive_ability = {.cnt = 0, .tick = ability_idle};
    the_ability_manager.used[0] = inactive_ability;
    the_ability_manager.used[1] = inactive_ability;

    /// done
    return;
}



/****************************************************************
 * gui function
 ****************************************************************/
#include <vectrex.h>
#include "game_include/graphics/g_gui.h"

void ability_draw_gui (void)
{
    /// draw extralife if available
    if(the_player.has_extralife)
    {
        /// draw extralife icon
        Reset0Ref();
        dp_VIA_t1_cnt_lo = 100;
        Moveto_d(127, 106);
        dp_VIA_t1_cnt_lo = 6;
        Draw_VLp(&vl_gui_extralife);
    }
    
    /// then draw ability, relative to extralife (css flexbox principle
    switch (the_player.ability)
    {
        case AC_MISSILE:
        // case AC_...:

            /// draw ability
            if(the_player.has_extralife)
            {
                dp_VIA_t1_cnt_lo = 20;
                Moveto_d(-15, -128);
            }
            else
            {
                Reset0Ref();
                dp_VIA_t1_cnt_lo = 100;
                Moveto_d(127, 106);
            }
            dp_VIA_t1_cnt_lo = 6;
            Draw_VLp((struct packet_t *) vl_gui_ac[the_player.ability]);
            break;

        case AC_NONE:
            /// well just do nothing
        default:
            /// should not happen
            ;
    }

    /// done
    return;
}



 
/****************************************************************
 * ability tick functions helpers
 ****************************************************************/

void calc_path_factor(active_ability_t * aa, int initial_x)
{
    /// calculate times 100 scaled up factor for deriving x from y values
    long upscaled_initial_x = (long) -initial_x;
    upscaled_initial_x *= 100L;
    aa->path_factor = upscaled_initial_x / 167L;

    ///done
    return;
}

#include "game_include/gen_data/gen_object_path.h"
#include "game_include/gen_data/gen_object_hitbox.h"
#include "game_include/object_manager.h"
#include "game_include/collision.h"
#include "lib/print/print.h"

/// @brief helper function for missile tick
/// @param model missiles model to fire
static inline __attribute__((always_inline)) void  _tick_ac_missile (active_ability_t * me, void * model)
{
    /// iterate to next step and check despawn
    if (--(me->cnt) == 0)
    {
        /// despawn
        me->tick = ability_idle;
    }

    /// calculate position
    int my_y = ABILITY_MISSILE_YY_LUT[me->cnt];
    long helper = me->path_factor * ((long) my_y - 55L);
    long result = helper / 100L; //< downscale again
    int my_x = (int) result;

    unsigned int my_sc = ABILITY_MISSILE_SC_LUT[me->cnt];

    /// draw me
    Reset0Ref();
    dp_VIA_t1_cnt_lo = 0x7f;
    Moveto_d(my_y, my_x);
    dp_VIA_t1_cnt_lo = my_sc;
    Draw_VLp((struct packet_t *) model);

    /// check for collision ----------(copy paste from collision.c)

    
    /// utils
    moving_object_t* obj;
    volatile unsigned int axis; //< axis counter for hit detection (volatile, because the compiler optimization breaks it (idk why))

    /// loop over all objects
    for(unsigned int i = 0; i < MAX_MOVING_OBJECTS; ++i)
    {
        obj = &the_object_manager.objects[i];

        /// only care when object is active
        if(obj->tick != idle)
        {
            int y = MOVING_OBJECT_Y1_LUT[the_game.stage][obj->ttl]; //< no need to use Y2_LUT because we are high enough

            /// only continue with high enough enemies
            if (y < PLAYER_Y)
            {
                continue;
            }

            /// build aabb of missile (approximation)
            int my_bb_y_top = my_y + (int) my_sc;
            int my_bb_xleft = my_x - (int) my_sc/2;
            int my_bb_xright = my_x + (int) my_sc/2;
            
            /// start building aabb of object
            unsigned int sc = MOVING_OBJECT_SC_LUT[the_game.stage][obj->ttl];
            int bb_y        = MO_SC_TO_BB_Y[obj->type][sc];
            int bb_ytop     = y+bb_y;

            int x = 0;
            switch(obj->lane)
            {
                case LEFT_LANE:
                    x = MOVING_OBJECT_XL_LUT[the_game.stage][obj->ttl];
                    break;
                case RIGHT_LANE:
                    x = MOVING_OBJECT_XR_LUT[the_game.stage][obj->ttl];
                    break;
                case MID_LANE:
                    x = 0;
                    break;
                default:
                    break;
            }
            int bb_xh = MO_SC_TO_BB_X_HALFED[obj->type][sc];

            /// build aabb
            int bb_xleft    = x-bb_xh;
            int bb_xright   = x+bb_xh;

            /// check collision
            axis = 2; //< axis count (in 2d: 2 axis) for each axis we hit -> axis gets reduced by one

            /// check collision on y axis
            if(my_y < y){
                /// player is lower than object
                if(my_bb_y_top >= y)
                {
                    axis--; //< hit
                }
            }else{
                /// player is lower than object
                if(bb_ytop >= my_y)
                {
                    axis--; //< hit
                } 
            }                           
            /// check collision on x axis 
            if(my_bb_xleft < bb_xleft){
                /// player is more to the left than the object
                if(my_bb_xright >= bb_xleft)
                {
                    axis--; //< hit
                }
            }else{
                /// player is more to the right than the object
                if(bb_xright >= my_bb_xleft)
                {
                    axis--; //< hit
                }
            }

            /// if we touch an object on all axis (2 axis - 2 hit per axis = 0) => hit
            if(axis == 0)
            {
                /// check the type of object we hit -> ability / enemy / fuel tank / ... ?
                switch(obj->type)
                {
                    case MOT_ENEMY_CAR1:
                    case MOT_ENEMY_CAR2:
                    case MOT_ENEMY_TRUCK:
                    case MOT_ENEMY_BIKE:
                        /// destroy it
                        obj->type = MOT_EXPLODED;
                        obj->model = (void *) 2; //< init 3 step explosion (a bit hacky...)
                        obj->tick = MOVING_OBJECT_EXPLODED_TICK_FNC_LUT[obj->lane];

                        /// and despawn
                        me->tick = ability_idle;
                        break;

                    case MOT_FUELCAN:
                    case MOT_EXTRALIFE:
                    case MOT_ABILITY_MISSILE:
                    case MOT_EXPLODED:
                    case MOT_NULL:
                    default:
                        /// we wont destroy those
                        ;
                }
            }
        }
    }
}



 
/****************************************************************
 * ability tick functions
 ****************************************************************/

#include "game_include/graphics/g_object.h"
void _tick_ac_missile_mid (active_ability_t * me)
{
    /// use helper function
    _tick_ac_missile(me, &vl_fired_missile_mid);

    /// done
    return;
}

void _tick_ac_missile_left(active_ability_t * me)
{
    /// use helper function
    _tick_ac_missile(me, &vl_fired_missile_left);

    /// done
    return;
}

void _tick_ac_missile_right (active_ability_t * me)
{
    /// use helper function
    _tick_ac_missile(me, &vl_fired_missile_right);

    /// done
    return;
}
