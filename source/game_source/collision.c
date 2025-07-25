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
    aabb_t car;
    aabb_t wing;
    aabb_t optional; //< only needed for sideview model
}aabb_player_t;

aabb_player_t player_aabbs;


/**************************************************
 * constants
 *************************************************/

#include "game_include/player.h"
#define THRESHOLD_Y_PLAYER_TOP          (PLAYER_Y + 16) //< dont check collision if object y is above this y value
#define THRESHOLD_Y_OBJECT_TOP          (PLAYER_Y - 6) //< dont check collision if object y_bb_top is below this value

#define AABB_CALC_Y_OFFSET          (64) //< shift 8-bit int value AABB_CALC_Y_OFFSET "pixels" down





/**************************************************
 * functions
 *************************************************/

/// @brief init function
void collision_init(void)
{
    /// init collision interface
    collision_check_t new_collision = {.recalculate_player_aabb = aabb_calculate_mid, .check = aabb_check_mid};
    collision = new_collision;

    /// init local data structures
    aabb_player_t new_aabb_player = {.car = {0,0,0,0}, .wing = {0,0,0,0}, .optional = {0,0,0,0}};
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
    Intensity_5F();
    Reset0Ref();					/* reset beam to center	*/
	dp_VIA_t1_cnt_lo = 0x7f;		/* set scaling factor for positioning */
    
    /// car bb
    Moveto_d(player_aabbs.car.y_bot - AABB_CALC_Y_OFFSET, player_aabbs.car.x_left);
    Draw_Line_d(0,(player_aabbs.car.x_right)-(player_aabbs.car.x_left));
    Draw_Line_d((player_aabbs.car.y_top + AABB_CALC_Y_OFFSET)-(player_aabbs.car.y_bot + AABB_CALC_Y_OFFSET),0);
    Draw_Line_d(0,(player_aabbs.car.x_left)-(player_aabbs.car.x_right));
    Draw_Line_d((player_aabbs.car.y_bot + AABB_CALC_Y_OFFSET)-(player_aabbs.car.y_top + AABB_CALC_Y_OFFSET),0);

    /// wing bb
    Reset0Ref();					/* reset beam to center	*/
	dp_VIA_t1_cnt_lo = 0x7f;		/* set scaling factor for positioning */
    Moveto_d(player_aabbs.wing.y_bot - AABB_CALC_Y_OFFSET, player_aabbs.wing.x_left);
    Draw_Line_d(0,(player_aabbs.wing.x_right)-(player_aabbs.wing.x_left));
    Draw_Line_d((player_aabbs.wing.y_top + AABB_CALC_Y_OFFSET)-(player_aabbs.wing.y_bot + AABB_CALC_Y_OFFSET),0);
    Draw_Line_d(0,(player_aabbs.wing.x_left)-(player_aabbs.wing.x_right));
    Draw_Line_d((player_aabbs.wing.y_bot + AABB_CALC_Y_OFFSET)-(player_aabbs.wing.y_top + AABB_CALC_Y_OFFSET),0);

    /// optional part
    if(collision.check != aabb_check_mid)
    {
        /// optional bb
        Reset0Ref();					/* reset beam to center	*/
        dp_VIA_t1_cnt_lo = 0x7f;		/* set scaling factor for positioning */
        Moveto_d(player_aabbs.optional.y_bot - AABB_CALC_Y_OFFSET, player_aabbs.optional.x_left);
        Draw_Line_d(0,(player_aabbs.optional.x_right)-(player_aabbs.optional.x_left));
        Draw_Line_d((player_aabbs.optional.y_top + AABB_CALC_Y_OFFSET)-(player_aabbs.optional.y_bot + AABB_CALC_Y_OFFSET),0);
        Draw_Line_d(0,(player_aabbs.optional.x_left)-(player_aabbs.optional.x_right));
        Draw_Line_d((player_aabbs.optional.y_bot + AABB_CALC_Y_OFFSET)-(player_aabbs.optional.y_top + AABB_CALC_Y_OFFSET),0);
    }

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

void aabb_draw_object(moving_object_t * obj)
{
    if(obj->tick != idle)
    {
        /// get x
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

        int y1 = MOVING_OBJECT_Y1_LUT[the_game.stage][obj->ttl];
        int y2 = MOVING_OBJECT_Y2_LUT[the_game.stage][obj->ttl];
        unsigned int sc = MOVING_OBJECT_SC_LUT[the_game.stage][obj->ttl];

        /// get bb values
        int bb_xh = MO_ENEMY_DUMMY_SC_TO_BB_X_HALFED[sc];
        int bb_y  = MO_ENEMY_DUMMY_SC_TO_BB_Y[sc];

        /// draw
        Reset0Ref();					/* reset beam to center	*/
        dp_VIA_t1_cnt_lo = 0x7f;		/* set scaling factor for positioning */
        Moveto_d(y1, x);
        Moveto_d(y2+bb_y, 0);
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
    /// main car
    player_aabbs.car.y_top = (AABB_CALC_Y_OFFSET + PLAYER_Y + 9);
    player_aabbs.car.y_bot = (AABB_CALC_Y_OFFSET + PLAYER_Y - 12);
    player_aabbs.car.x_left = the_player.x - 20;
    player_aabbs.car.x_right = the_player.x + 20;

    /// front wing
    player_aabbs.wing.y_top = (AABB_CALC_Y_OFFSET + PLAYER_Y + 15);
    player_aabbs.wing.y_bot = (AABB_CALC_Y_OFFSET + PLAYER_Y + 9);
    player_aabbs.wing.x_left = the_player.x - 10;
    player_aabbs.wing.x_right = the_player.x + 10;
}


void aabb_calculate_left(void)
{
    /// main car
    player_aabbs.car.y_top = (AABB_CALC_Y_OFFSET + PLAYER_Y + 11);
    player_aabbs.car.y_bot = (AABB_CALC_Y_OFFSET + PLAYER_Y - 12);
    player_aabbs.car.x_left = the_player.x + 27;
    player_aabbs.car.x_right = the_player.x - 5;

    /// front wing
    player_aabbs.wing.y_top = (AABB_CALC_Y_OFFSET + PLAYER_Y + 16);
    player_aabbs.wing.y_bot = (AABB_CALC_Y_OFFSET + PLAYER_Y + 11);
    player_aabbs.wing.x_left = the_player.x + 25;
    player_aabbs.wing.x_right = the_player.x + 9;

    /// optional
    player_aabbs.optional.y_top = (AABB_CALC_Y_OFFSET + PLAYER_Y + 4);
    player_aabbs.optional.y_bot = (AABB_CALC_Y_OFFSET + PLAYER_Y - 12);
    player_aabbs.optional.x_left = the_player.x - 5;
    player_aabbs.optional.x_right = the_player.x - 20;
}


void aabb_calculate_right(void)
{
    /// main car
    player_aabbs.car.y_top = (AABB_CALC_Y_OFFSET + PLAYER_Y + 11);
    player_aabbs.car.y_bot = (AABB_CALC_Y_OFFSET + PLAYER_Y - 12);
    player_aabbs.car.x_left = the_player.x - 27;
    player_aabbs.car.x_right = the_player.x + 5;

    /// front wing
    player_aabbs.wing.y_top = (AABB_CALC_Y_OFFSET + PLAYER_Y + 16);
    player_aabbs.wing.y_bot = (AABB_CALC_Y_OFFSET + PLAYER_Y + 11);
    player_aabbs.wing.x_left = the_player.x - 25;
    player_aabbs.wing.x_right = the_player.x - 9;

    /// optional
    player_aabbs.optional.y_top = (AABB_CALC_Y_OFFSET + PLAYER_Y + 4);
    player_aabbs.optional.y_bot = (AABB_CALC_Y_OFFSET + PLAYER_Y - 12);
    player_aabbs.optional.x_left = the_player.x + 5;
    player_aabbs.optional.x_right = the_player.x + 20;
}



/**********************************************************************
 * actual collision check function (axis aligned bounding box check)
 *********************************************************************/


#define CHECK_COLLISION(AXIS, COUNTER, PYTOP, PYBOT, OYTOP, OYBOT, PXLEFT, PXRIGHT, OXLEFT, OXRIGHT)        \
    AXIS = 2; /*if one axis doesnt touch -> no hit (its 2d -> so 2 axis = hit)*/               \
    /* check if they touch on y axis */                                                                     \
    if(PYBOT < OYBOT){ /* player y lower than object */                                                     \
        if(PYTOP >= OYBOT) {--axis;}                                                                        \
    }else{                                                                                                  \
        if(OYTOP >= PYBOT) {--axis;}                                                                        \
    }                                                                                                       \
    /* check if they touch on x axis */                                                                     \
    if(PXLEFT < OXLEFT){ /* player x lower than object */                                                   \
        if(PXRIGHT >= OXLEFT) {--axis;}                                                                     \
    }else{                                                                                                  \
        if(OXRIGHT >= PXLEFT) {--axis;}                                                                     \
    }                                                                                                       \
    if(AXIS == 0) {++COUNTER;}


/* #define DEBUG */
#include "lib/print/print.h"
#include "game_include/sounds/s_animation.h"


void aabb_check_mid(void)
{
    #ifdef DEBUG
    aabb_draw();
    print_string(110,-40, "CD:MID\x80");
    #endif

    moving_object_t* obj;
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
            int bb_y        = MO_ENEMY_DUMMY_SC_TO_BB_Y[sc];
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
            int bb_xh = MO_ENEMY_DUMMY_SC_TO_BB_X_HALFED[sc];

            /// build aabb
            //int bb_ybot     = y; //< bb_ybot is just y
            int bb_xleft    = x-bb_xh;
            int bb_xright   = x+bb_xh;
            
            /// debug section
            #ifdef DEBUG
            print_signed_int((int)i*12 +10, -110, y);
            aabb_draw_object(obj);
            #endif

            /// check collision
            unsigned int axis = 0;
            unsigned int collsions = 0;

            /// check with bb of car
            CHECK_COLLISION(
                axis, collsions,
                player_aabbs.car.y_top, player_aabbs.car.y_bot, bb_ytop, y,
                player_aabbs.car.x_left, player_aabbs.car.x_right, bb_xleft, bb_xright
            );
            
            /// check with bb of wing
            CHECK_COLLISION(
                axis, collsions,
                player_aabbs.wing.y_top, player_aabbs.wing.y_bot, bb_ytop, y,
                player_aabbs.wing.x_left, player_aabbs.wing.x_right, bb_xleft, bb_xright
            );

            if(collsions != 0)
            {
                /// we hit something

                /// check the type of object we hit -> ability / enemy / fuel tank / ... ? (TODO: implement)

                /// if it was an enemy -> game over
                the_game.execute_state = game_over;
                #ifdef DEBUG
                print_string(42,-20,"HIT\x80");
                #endif
            }
        }
    }
}


void aabb_check_side(void)
{
    #ifdef DEBUG
    aabb_draw();
    print_string(110,-40, "CD:SIDE\x80");
    #endif

    moving_object_t* obj;
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
            int bb_y        = MO_ENEMY_DUMMY_SC_TO_BB_Y[sc];
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
            int bb_xh = MO_ENEMY_DUMMY_SC_TO_BB_X_HALFED[sc];

            /// build aabb
            //int bb_ybot     = y; //< bb_ybot is just y
            int bb_xleft    = x-bb_xh;
            int bb_xright   = x+bb_xh;
            
            /// debug section
            #ifdef DEBUG
            print_signed_int((int)i*12 +10, -110, y);
            aabb_draw_object(obj);
            #endif

            /// check collision
            unsigned int axis = 0;
            unsigned int collsions = 0;

            /// check with bb of car
            CHECK_COLLISION(
                axis, collsions,
                player_aabbs.car.y_top, player_aabbs.car.y_bot, bb_ytop, y,
                player_aabbs.car.x_left, player_aabbs.car.x_right, bb_xleft, bb_xright
            );
            
            /// check with bb of wing
            CHECK_COLLISION(
                axis, collsions,
                player_aabbs.wing.y_top, player_aabbs.wing.y_bot, bb_ytop, y,
                player_aabbs.wing.x_left, player_aabbs.wing.x_right, bb_xleft, bb_xright
            );
            
            /// check with bb of side
            CHECK_COLLISION(
                axis, collsions,
                player_aabbs.optional.y_top, player_aabbs.optional.y_bot, bb_ytop, y,
                player_aabbs.optional.x_left, player_aabbs.optional.x_right, bb_xleft, bb_xright
            );

            if(collsions != 0)
            {
                /// we hit something

                /// check the type of object we hit -> ability / enemy / fuel tank / ... ? (TODO: implement)

                /// if it was an enemy -> game over
                the_game.execute_state = game_over;
                /// debug section
                #ifdef DEBUG
                print_string(42,-20,"HIT\x80");
                #endif
            }
        }
    }
}
