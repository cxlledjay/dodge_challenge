#include "game_include/enemy.h"


/**
 * @brief hidden datastructure to save and manage all enemies
 * 
 * basically a queue with less steps.
 */
#define MAX_ENEMIES (5u)
enemy_t enemy_list[MAX_ENEMIES]; //< allocate ram for each enemy (if enemy is not active -> set tick() to idle())
enemy_t * queue_ptr; //< always points to a location where an enemy can be added (queue tail)











//forward declare idle func (well, the implementation does not look more exciting...)
void idle(enemy_t* me);

void enemy_init(void)
{
    enemy_t empty_enemy = {.tick = idle};
    for(unsigned int i = 0; i < MAX_ENEMIES; ++i)
    {
        enemy_list[i] = empty_enemy;
    }
    queue_ptr = &enemy_list[0];
}

//forward declare tick_dummy func (well, the implementation does not look more exciting...)
void tick_dummy(enemy_t* me);

int enemy_try_spawn(__attribute__((unused)) lane_t lane)
{
    int ret = -1;
    //check if queue has space
    if(queue_ptr->tick == idle) 
    {
        #define spawn_y (30) //< TODO: adjust!
        // TODO: add rng to set different tick functions (one func for car model, one func for truck model, ...)
        //enemy_t new_enemy = {.my_lane = lane, .y = spawn_y, .cnt = 0, .tick = tick_dummy};

        //check if spawn would make sense
        //e.g. already two enemies in same lane
        //e.g. enemy would collide with recently spawned enemy
        //...

        //*queue_ptr = new_enemy;
        ret = 0;
    }
    //queue has no space
    else
    {
        ret = -1;
    }
    return ret;
}




/**************************************************************************
 * concrete enemy functions
 **************************************************************************/


#include "game_include/gen_data/gen_object_path.h"

 
/**
 * @brief do nothing (not yet used / despawned)
 */
void idle(__attribute__((unused)) enemy_t* me)
{
    return;
}



void tick_dummy(__attribute__((unused)) enemy_t* me)
{
    return;
}


#include <vectrex.h>
#include "game_include/graphics/g_enemy.h"

#define DESPAWN_CHECK(ENEMY_PTR)                                                                                            \
    if(--(ENEMY_PTR->ttl) == 0) {ENEMY_PTR->tick = idle; return;} /* check if enemy should still be rendered */

#define DECODE_VAR(STAGE, VAR_TYPE) _ST##STAGE##_##VAR_TYPE##_LUT

#define DRAW_ENEMY_MID(ENEMY_PTR, STAGE)                                                                                    \
    Intensity_5F(); Reset0Ref(); dp_VIA_t1_cnt_lo = 0x7f; /* prepare */                                                     \
    Moveto_d(DECODE_VAR(STAGE, Y1)[ENEMY_PTR->ttl],0);                                                                      \
    Moveto_d(DECODE_VAR(STAGE, Y2)[ENEMY_PTR->ttl],0); /* two moves because of big range of motion*/                        \
    dp_VIA_t1_cnt_lo = DECODE_VAR(STAGE, SC)[ENEMY_PTR->ttl]; /* set scaling */                                             \
    Draw_VLp((struct packet_t *) ENEMY_PTR->model); /* draw */

    
#define DRAW_ENEMY_LEFT(ENEMY_PTR, STAGE)                                                                                   \
    Intensity_5F(); Reset0Ref(); dp_VIA_t1_cnt_lo = 0x7f; /* prepare */                                                     \
    Moveto_d(DECODE_VAR(STAGE, Y1)[ENEMY_PTR->ttl],DECODE_VAR(STAGE, XL)[ENEMY_PTR->ttl]);                                  \
    Moveto_d(DECODE_VAR(STAGE, Y2)[ENEMY_PTR->ttl],0); /* two moves because of big range of motion*/                        \
    dp_VIA_t1_cnt_lo = DECODE_VAR(STAGE, SC)[ENEMY_PTR->ttl]; /* set scaling */                                             \
    Draw_VLp((struct packet_t *) ENEMY_PTR->model); /* draw */

    
#define DRAW_ENEMY_RIGHT(ENEMY_PTR, STAGE)                                                                                  \
    Intensity_5F(); Reset0Ref(); dp_VIA_t1_cnt_lo = 0x7f; /* prepare */                                                     \
    Moveto_d(DECODE_VAR(STAGE, Y1)[ENEMY_PTR->ttl],DECODE_VAR(STAGE, XR)[ENEMY_PTR->ttl]);                                  \
    Moveto_d(DECODE_VAR(STAGE, Y2)[ENEMY_PTR->ttl],0); /* two moves because of big range of motion*/                        \
    dp_VIA_t1_cnt_lo = DECODE_VAR(STAGE, SC)[ENEMY_PTR->ttl]; /* set scaling */                                             \
    Draw_VLp((struct packet_t *) ENEMY_PTR->model); /* draw */




void _tick_st0_mid(enemy_t * me)
{
    DRAW_ENEMY_MID(me, 0);
    DESPAWN_CHECK(me);
    return;
}
void _tick_st0_left(enemy_t * me)
{
    DRAW_ENEMY_LEFT(me, 0);
    DESPAWN_CHECK(me);
    return;
}
void _tick_st0_right(enemy_t * me)
{
    DRAW_ENEMY_RIGHT(me, 0);
    DESPAWN_CHECK(me);
    return;
}





/**********************************************
 * LUTs
 *********************************************/

void (* const ENEMY_TICK_FNC_LUT[STAGE_T_SIZE][3]) (enemy_t * me) =
{
    { //< stage 0
        _tick_st0_left,
        _tick_st0_mid,
        _tick_st0_right
    }
};


/// debug

enemy_t temp = {.ttl = 0, .tick = idle, .model = &vl_enemy_dummy};

void enemy_debug(void)
{
    if(temp.tick == idle)
    {
        temp.tick = ENEMY_TICK_FNC_LUT[the_game.stage][LEFT_LANE];
        temp.ttl = ENEMY_TTL_LUT[the_game.stage];
        return;
    }

    temp.tick(&temp);
}
