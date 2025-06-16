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
#define THRESHOLD_OBJECT_Y     (PLAYER_Y + 16) //< start checking for collision if object y is below this threshold





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
    Moveto_d(player_aabbs.car.y_bot, player_aabbs.car.x_left);
    Draw_Line_d(0,(player_aabbs.car.x_right)-(player_aabbs.car.x_left));
    Draw_Line_d((player_aabbs.car.y_top)-(player_aabbs.car.y_bot),0);
    Draw_Line_d(0,(player_aabbs.car.x_left)-(player_aabbs.car.x_right));
    Draw_Line_d((player_aabbs.car.y_bot)-(player_aabbs.car.y_top),0);

    /// wing bb
    Reset0Ref();					/* reset beam to center	*/
	dp_VIA_t1_cnt_lo = 0x7f;		/* set scaling factor for positioning */
    Moveto_d(player_aabbs.wing.y_bot, player_aabbs.wing.x_left);
    Draw_Line_d(0,(player_aabbs.wing.x_right)-(player_aabbs.wing.x_left));
    Draw_Line_d((player_aabbs.wing.y_top)-(player_aabbs.wing.y_bot),0);
    Draw_Line_d(0,(player_aabbs.wing.x_left)-(player_aabbs.wing.x_right));
    Draw_Line_d((player_aabbs.wing.y_bot)-(player_aabbs.wing.y_top),0);

    /// optional part
    if(collision.check != aabb_check_mid)
    {
        /// optional bb
        Reset0Ref();					/* reset beam to center	*/
        dp_VIA_t1_cnt_lo = 0x7f;		/* set scaling factor for positioning */
        Moveto_d(player_aabbs.optional.y_bot, player_aabbs.optional.x_left);
        Draw_Line_d(0,(player_aabbs.optional.x_right)-(player_aabbs.optional.x_left));
        Draw_Line_d((player_aabbs.optional.y_top)-(player_aabbs.optional.y_bot),0);
        Draw_Line_d(0,(player_aabbs.optional.x_left)-(player_aabbs.optional.x_right));
        Draw_Line_d((player_aabbs.optional.y_bot)-(player_aabbs.optional.y_top),0);
    }

    /// draw threshold line top
    Reset0Ref();					/* reset beam to center	*/
	dp_VIA_t1_cnt_lo = 0x7f;		/* set scaling factor for positioning */
    Moveto_d(THRESHOLD_OBJECT_Y, -100);
    Draw_Line_d(0, 100);
    Draw_Line_d(0, 100);

    /// draw threshold line bot (this is meant for enemy y_bot (!! not enemy y_top))
    Reset0Ref();					/* reset beam to center	*/
	dp_VIA_t1_cnt_lo = 0x7f;		/* set scaling factor for positioning */
    Moveto_d(-128, -100);
    Moveto_d(-16, 0);
    Draw_Line_d(0, 100);
    Draw_Line_d(0, 100);

    /// draw for objects
    for(unsigned int i = 0; i < MAX_MOVING_OBJECTS; ++i)
    {
        moving_object_t* obj = &the_manager.objects[i];
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

            if(y2 == 0)
            {
                /// draw
                Reset0Ref();					/* reset beam to center	*/
                dp_VIA_t1_cnt_lo = 0x7f;		/* set scaling factor for positioning */
                Moveto_d(y1, x);
                Draw_Line_d(0,bb_xh);
                Draw_Line_d(bb_y,0);
                Draw_Line_d(0,-2* bb_xh);
                Draw_Line_d(-bb_y,0);
                Draw_Line_d(0,bb_xh);
            }
        }
    }
}




/**************************************************
 * interfaces for different player models
 *************************************************/

void aabb_calculate_mid(void)
{
    /// main car
    player_aabbs.car.y_top = PLAYER_Y + 9;
    player_aabbs.car.y_bot = PLAYER_Y - 12;
    player_aabbs.car.x_left = the_player.x - 20;
    player_aabbs.car.x_right = the_player.x + 20;

    /// front wing
    player_aabbs.wing.y_top = PLAYER_Y + 15;
    player_aabbs.wing.y_bot = PLAYER_Y + 9;
    player_aabbs.wing.x_left = the_player.x - 10;
    player_aabbs.wing.x_right = the_player.x + 10;
}


void aabb_calculate_left(void)
{
    /// main car
    player_aabbs.car.y_top = PLAYER_Y + 11;
    player_aabbs.car.y_bot = PLAYER_Y - 12;
    player_aabbs.car.x_left = the_player.x + 27;
    player_aabbs.car.x_right = the_player.x - 5;

    /// front wing
    player_aabbs.wing.y_top = PLAYER_Y + 16;
    player_aabbs.wing.y_bot = PLAYER_Y + 11;
    player_aabbs.wing.x_left = the_player.x + 25;
    player_aabbs.wing.x_right = the_player.x + 9;

    /// optional
    player_aabbs.optional.y_top = PLAYER_Y + 4;
    player_aabbs.optional.y_bot = PLAYER_Y - 12;
    player_aabbs.optional.x_left = the_player.x - 5;
    player_aabbs.optional.x_right = the_player.x - 20;
}


void aabb_calculate_right(void)
{
    /// main car
    player_aabbs.car.y_top = PLAYER_Y + 11;
    player_aabbs.car.y_bot = PLAYER_Y - 12;
    player_aabbs.car.x_left = the_player.x - 27;
    player_aabbs.car.x_right = the_player.x + 5;

    /// front wing
    player_aabbs.wing.y_top = PLAYER_Y + 16;
    player_aabbs.wing.y_bot = PLAYER_Y + 11;
    player_aabbs.wing.x_left = the_player.x - 25;
    player_aabbs.wing.x_right = the_player.x - 9;

    /// optional
    player_aabbs.optional.y_top = PLAYER_Y + 4;
    player_aabbs.optional.y_bot = PLAYER_Y - 12;
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




#include "lib/print/print.h"


//#define DEBUG
void aabb_check_mid(void)
{
    /// TODO: implement! (ayy)

    #ifdef DEBUG
    aabb_draw();
    print_string(100,-40, "CD:MID\x80");
    #endif

    moving_object_t* obj;
    /// loop over all objects
    for(unsigned int i = 0; i < MAX_MOVING_OBJECTS; ++i)
    {
        obj = &the_manager.objects[i];

        /// only care when object is active
        if(obj->tick != idle)
        {
            /// only care when object is in threshold
            int y1 = MOVING_OBJECT_Y1_LUT[the_game.stage][obj->ttl];
            if(y1 > THRESHOLD_OBJECT_Y)
            {
                break;
            }
            int y2 = MOVING_OBJECT_Y2_LUT[the_game.stage][obj->ttl];
            if (y2 != 0)
            {
                break;
            }

            /// get values
            
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
            
            /// get scaling
            unsigned int sc = MOVING_OBJECT_SC_LUT[the_game.stage][obj->ttl];

            /// get bb values
            int bb_xh = MO_ENEMY_DUMMY_SC_TO_BB_X_HALFED[sc];
            int bb_y  = MO_ENEMY_DUMMY_SC_TO_BB_Y[sc];

            /// build bb
            int bb_ybot     = y1;
            int bb_ytop     = y1+bb_y;
            int bb_xleft    = x-bb_xh;
            int bb_xright   = x+bb_xh;
            


            /// check collision
            unsigned int axis = 0;
            unsigned int collsions = 0;

            /// check with bb of car
            CHECK_COLLISION(
                axis, collsions,
                player_aabbs.car.y_top, player_aabbs.car.y_bot, bb_ytop, bb_ybot,
                player_aabbs.car.x_left, player_aabbs.car.x_right, bb_xleft, bb_xright
            );
            
            /// check with bb of wing
            CHECK_COLLISION(
                axis, collsions,
                player_aabbs.wing.y_top, player_aabbs.wing.y_bot, bb_ytop, bb_ybot,
                player_aabbs.wing.x_left, player_aabbs.wing.x_right, bb_xleft, bb_xright
            );

            if(collsions != 0)
            {
                /// we hit something

                /// switch the type of object we hit (TODO: implement)

                /// if it was an enemy -> game over
                the_game.execute_state = game_over;
            }
        }
    }
}

void aabb_check_side(void)
{
    /// TODO: implement! (ayy)

    #ifdef DEBUG
    aabb_draw();
    print_string(100,-40, "CD:SIDE\x80");
    #endif

    
    moving_object_t* obj;
    /// loop over all objects
    for(unsigned int i = 0; i < MAX_MOVING_OBJECTS; ++i)
    {
        obj = &the_manager.objects[i];

        /// only care when object is active
        if(obj->tick != idle)
        {
            /// only care when object is in threshold
            int y1 = MOVING_OBJECT_Y1_LUT[the_game.stage][obj->ttl];
            if(y1 > THRESHOLD_OBJECT_Y)
            {
                break;
            }
            int y2 = MOVING_OBJECT_Y2_LUT[the_game.stage][obj->ttl];
            if (y2 != 0)
            {
                break;
            }

            /// get values
            
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
            
            /// get scaling
            unsigned int sc = MOVING_OBJECT_SC_LUT[the_game.stage][obj->ttl];

            /// get bb values
            int bb_xh = MO_ENEMY_DUMMY_SC_TO_BB_X_HALFED[sc];
            int bb_y  = MO_ENEMY_DUMMY_SC_TO_BB_Y[sc];

            /// build bb
            int bb_ybot     = y1;
            int bb_ytop     = y1+bb_y;
            int bb_xleft    = x-bb_xh;
            int bb_xright   = x+bb_xh;
            


            /// check collision
            unsigned int axis = 0;
            unsigned int collsions = 0;

            /// check with bb of car
            CHECK_COLLISION(
                axis, collsions,
                player_aabbs.car.y_top, player_aabbs.car.y_bot, bb_ytop, bb_ybot,
                player_aabbs.car.x_left, player_aabbs.car.x_right, bb_xleft, bb_xright
            );
            
            /// check with bb of wing
            CHECK_COLLISION(
                axis, collsions,
                player_aabbs.wing.y_top, player_aabbs.wing.y_bot, bb_ytop, bb_ybot,
                player_aabbs.wing.x_left, player_aabbs.wing.x_right, bb_xleft, bb_xright
            );
            
            /// check with bb of side
            CHECK_COLLISION(
                axis, collsions,
                player_aabbs.optional.y_top, player_aabbs.optional.y_bot, bb_ytop, bb_ybot,
                player_aabbs.optional.x_left, player_aabbs.optional.x_right, bb_xleft, bb_xright
            );

            if(collsions != 0)
            {
                /// we hit something

                /// switch the type of object we hit (TODO: implement)

                /// if it was an enemy -> game over
                the_game.execute_state = game_over;
            }
        }
    }
}
