#include "game_include/collision.h"


// interface used for collision detection
collision_check_t collision;

/**************************************************
 * data strucutres for bounding boxes
 *************************************************/
typedef struct _aabb_t
{
    int y_top;
    int y_bot;
    int x_left;
    int x_right;
} aabb_t;

typedef struct _aabb_player_t
{
    /// player bounding box
    /// (only using one, instead of three as before due to performance increase)
    aabb_t car;
}aabb_player_t;

aabb_player_t player_aabbs;


/**************************************************
 * constants
 *************************************************/

#include "game_include/player.h"
#define THRESHOLD_Y_PLAYER_TOP          (PLAYER_Y + 16) //< dont check collision if object y is above this y value
#define THRESHOLD_Y_OBJECT_TOP          (PLAYER_Y - 6) //< dont check collision if object y_bb_top is below this value

#define AABB_CALC_Y_OFFSET              (64) //< shift 8-bit int value AABB_CALC_Y_OFFSET "pixels" down





/**************************************************
 * functions
 *************************************************/

/// @brief init function
void collision_init(void)
{
    /// init collision interface
    collision_check_t new_collision = {.recalculate_player_aabb = aabb_calculate_mid};
    collision = new_collision;

    /// init local data structures
    aabb_player_t new_aabb_player = {.car = {0,0,0,0}};
    player_aabbs = new_aabb_player;

    /// start with values for first frame aabb
    collision.recalculate_player_aabb();

    /// done
    return;
}


#include <vectrex.h>
#include "game_include/player.h"
#include "game_include/gen_data/gen_object_path.h"
#include "game_include/object_manager.h"
#include "game_include/gen_data/gen_object_hitbox.h"

/// @brief drawing function, for debug only
void aabb_draw(void)
{
    /// move to player
    Reset0Ref();					/* reset beam to center	*/
	dp_VIA_t1_cnt_lo = 0x7f;		/* set scaling factor for positioning */
    
    /// car bb
    Moveto_d(player_aabbs.car.y_bot - AABB_CALC_Y_OFFSET, player_aabbs.car.x_left);
    Draw_Line_d(0,(player_aabbs.car.x_right)-(player_aabbs.car.x_left));
    Draw_Line_d((player_aabbs.car.y_top + AABB_CALC_Y_OFFSET)-(player_aabbs.car.y_bot + AABB_CALC_Y_OFFSET),0);
    Draw_Line_d(0,(player_aabbs.car.x_left)-(player_aabbs.car.x_right));
    Draw_Line_d((player_aabbs.car.y_bot + AABB_CALC_Y_OFFSET)-(player_aabbs.car.y_top + AABB_CALC_Y_OFFSET),0);

    /// draw threshold line top
    Reset0Ref();					/* reset beam to center	*/
	dp_VIA_t1_cnt_lo = 0x7f;		/* set scaling factor for positioning */
    Moveto_d(THRESHOLD_Y_PLAYER_TOP, -100);
    Draw_Line_d(0, 100);
    Draw_Line_d(0, 100);

    /// draw threshold line top (this is meant for enemy y_top
    Reset0Ref();					/* reset beam to center	*/
	dp_VIA_t1_cnt_lo = 0x7f;		/* set scaling factor for positioning */
    Moveto_d(THRESHOLD_Y_OBJECT_TOP, -116);
    Draw_Line_d(0, 116);
    Draw_Line_d(0, 116);
}

void aabb_draw_object(moving_object_t * obj, int x, int y, int bb_xh, int bb_y)
{
    if(obj->tick != idle)
    {
        /// draw
        Reset0Ref();					/* reset beam to center	*/
        dp_VIA_t1_cnt_lo = 0x7f;		/* set scaling factor for positioning */
        Moveto_d(-AABB_CALC_Y_OFFSET, x);
        Moveto_d(y+bb_y, 0);
        Draw_Line_d(0,bb_xh);
        Draw_Line_d(-bb_y,0);
        Draw_Line_d(0,-2* bb_xh);
        Draw_Line_d(bb_y,0);
        Draw_Line_d(0,bb_xh);
    }
}



/**************************************************
 * interfaces for different player models
 *************************************************/

void aabb_calculate_mid(void)
{
    player_aabbs.car.y_top = (AABB_CALC_Y_OFFSET + PLAYER_Y + 11);
    player_aabbs.car.y_bot = (AABB_CALC_Y_OFFSET + PLAYER_Y - 12);
    player_aabbs.car.x_left = the_player.x - 18;
    player_aabbs.car.x_right = the_player.x + 18;
}


void aabb_calculate_left(void)
{
    player_aabbs.car.y_top = (AABB_CALC_Y_OFFSET + PLAYER_Y + 11);
    player_aabbs.car.y_bot = (AABB_CALC_Y_OFFSET + PLAYER_Y - 12);
    player_aabbs.car.x_left = the_player.x - 16;
    player_aabbs.car.x_right = the_player.x + 24;
}


void aabb_calculate_right(void)
{
    player_aabbs.car.y_top = (AABB_CALC_Y_OFFSET + PLAYER_Y + 11);
    player_aabbs.car.y_bot = (AABB_CALC_Y_OFFSET + PLAYER_Y - 12);
    player_aabbs.car.x_left = the_player.x - 24;
    player_aabbs.car.x_right = the_player.x + 16;
}



/**********************************************************************
 * actual collision check function (axis aligned bounding box check)
 *********************************************************************/

/* #define DEBUG */
#include "lib/print/print.h"
#include "game_include/sounds/s_animation.h"
#include "game_include/fuel.h"
#include "game_include/random.h"

void aabb_check_collision(void)
{
    #ifdef DEBUG
    aabb_draw();
    #endif

    moving_object_t* obj;
    volatile unsigned int axis; //< axis counter for hit detection (volatile, because the compiler optimization breaks it (idk why))
    /// loop over all objects
    for(unsigned int i = 0; i < MAX_MOVING_OBJECTS; ++i)
    {
        obj = &the_object_manager.objects[i];

        /// only care when object is active
        if(obj->tick != idle)
        {
            int y = MOVING_OBJECT_Y1_LUT[the_game.stage][obj->ttl];

            /// only care when object is below y of player aabb top 
            if(y > THRESHOLD_Y_PLAYER_TOP)
            {
                continue;
            }
            
            /// manipulate y to increase performance and keep extended axis system
            y += AABB_CALC_Y_OFFSET; 
            y += MOVING_OBJECT_Y2_LUT[the_game.stage][obj->ttl]; //< now y is real y shifted up AABB_CALC_Y_OFFSET "pixels"
            
            /// start building aabb of object
            unsigned int sc = MOVING_OBJECT_SC_LUT[the_game.stage][obj->ttl];
            int bb_y        = MO_SC_TO_BB_Y[obj->type][sc];
            int bb_ytop     = y+bb_y; //< adjusted to scaled axis

            /// only care when player is above y of object aabb top (micro optimisation)
            if(bb_ytop < (THRESHOLD_Y_OBJECT_TOP + AABB_CALC_Y_OFFSET))
            {
                continue;
            }

            /// get remaining values for aabb check

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
            //int bb_ybot     = y; //< bb_ybot is just y
            int bb_xleft    = x-bb_xh;
            int bb_xright   = x+bb_xh;
            
            /// debug section
            #ifdef DEBUG
            /* print_signed_int((int)i*12 +10, -120, y); */
            /* print_unsigned_int((int)i*12 +10, -120, sc); */
            aabb_draw_object(obj, x, y, bb_xh, bb_y);
            #endif

            /// check collision
            axis = 2; //< axis count (in 2d: 2 axis) for each axis we hit -> axis gets reduced by one

            /// check collision on y axis
            if(player_aabbs.car.y_bot < y){
                /// player is lower than object
                if(player_aabbs.car.y_top >= y)
                {
                    axis--; //< hit
                }
            }else{
                /// player is lower than object
                if(bb_ytop >= player_aabbs.car.y_bot)
                {
                    axis--; //< hit
                } 
            }                           
            /// check collision on x axis 
            if(player_aabbs.car.x_left < bb_xleft){
                /// player is more to the left than the object
                if(player_aabbs.car.x_right >= bb_xleft)
                {
                    axis--; //< hit
                }
            }else{
                /// player is more to the right than the object
                if(bb_xright >= player_aabbs.car.x_left)
                {
                    axis--; //< hit
                }
            }

            #ifdef DEBUG
            print_signed_int((int)i*12 +10, -120, player_aabbs.car.x_left);
            print_signed_int((int)i*12 +10, -80, bb_xright);
            #endif

            /// if we touch an object on all axis (2 axis - 2 hit per axis = 0) => hit
            if(axis == 0)
            {
                /// check the type of object we hit -> ability / enemy / fuel tank / ... ? (TODO: implement)
                switch(obj->type)
                {
                    case MOT_FUELCAN:

                        /// refill player fuel
                        if( the_player.fuel + FUEL_CAN_REFILL_AMOUNT > 100)
                        {
                            /// protect overflow
                            the_player.fuel = 100;
                        }
                        else
                        {
                            /// refill
                            the_player.fuel = the_player.fuel + FUEL_CAN_REFILL_AMOUNT;
                        }

                        /// TODO: play refuel sound

                        /// and despawn the fuel can
                        obj->tick = idle;

                        /// done
                        break;

                    case MOT_ABILITY_EXTRALIFE:

                        /// only pick up ability if player has none
                        if(the_player.has_extralife == 0)
                        {
                            /// set extralife for player
                            the_player.has_extralife = 1;

                            /// despawn ability object
                            obj->tick = idle;
                        }

                        /// done
                        break;

                    case MOT_ABILITY_MISSILE:

                        /// only pick up ability if player has none
                        if(the_player.ability == AC_NONE)
                        {
                            /// set ability for player
                            the_player.ability = AC_MISSILE;

                            /// despawn ability object
                            obj->tick = idle;
                        }

                        /// done
                        break;

                    case MOT_EXPLODED:

                        /// drive trough explosion
                        break;

                    case MOT_ENEMY_CAR1:
                    case MOT_ENEMY_CAR2:
                    case MOT_ENEMY_TRUCK:
                    case MOT_ENEMY_BIKE:
                    case MOT_NULL:
                    default:

                        /// we hit an enemy

                        if(the_player.has_extralife)
                        {
                            /// second chance for player
                            the_player.has_extralife = 0;

                            /// enable player to drive trough enemy
                            obj->type = MOT_EXPLODED;
                            obj->model = (void *) 2; //< init 3 step explosion
                            obj->tick = MOVING_OBJECT_EXPLODED_TICK_FNC_LUT[obj->lane];

                            /// TODO: play sound
                        }
                        else
                        {
                            /// TODO: tell the game over screen, why it was over (here, reason = hit object)
                            
                            the_game.execute_state = game_over; //< back to game over screen
                        }
                }
            }
        }
    }
}
