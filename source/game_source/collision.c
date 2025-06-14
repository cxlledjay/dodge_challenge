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

    /// optional part
    if(collision.check != aabb_check_mid)
    {
        /// optional bb
    }
}


/**************************************************
 * interfaces for different player models
 *************************************************/

void aabb_calculate_mid(void)
{
    player_aabbs.car.y_top = PLAYER_Y + 9;
    player_aabbs.car.y_bot = PLAYER_Y - 12;
    player_aabbs.car.x_left = the_player.x - 20;
    player_aabbs.car.x_right = the_player.x + 20;
}


void aabb_calculate_left(void)
{
    player_aabbs.car.y_top = PLAYER_Y + 11;
    player_aabbs.car.y_bot = PLAYER_Y - 12;
    player_aabbs.car.x_left = the_player.x - 20;
    player_aabbs.car.x_right = the_player.x + 27;
}


void aabb_calculate_right(void)
{
    player_aabbs.car.y_top = PLAYER_Y + 11;
    player_aabbs.car.y_bot = PLAYER_Y - 12;
    player_aabbs.car.x_left = the_player.x - 27;
    player_aabbs.car.x_right = the_player.x + 20;
}





#include "lib/print/print.h"


#define DEBUG
void aabb_check_mid(void)
{
    /// TODO: implement! (ayy)

    #ifdef DEBUG
    aabb_draw();
    print_string(100,-40, "CD:MID");
    #endif
}

void aabb_check_left(void)
{
    /// TODO: implement! (ayy)

    #ifdef DEBUG
    aabb_draw();
    print_string(100,-40, "CD:LEFT");
    #endif
}

void aabb_check_right(void)
{
    /// TODO: implement! (ayy)

    #ifdef DEBUG
    aabb_draw();
    print_string(100,-40, "CD:RIGHT");
    #endif
}