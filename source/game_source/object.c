#include "game_include/object.h"



/**************************************************************************
 * utils
 **************************************************************************/
#include <vectrex.h>

#include "game_include/game.h"
#define DESPAWN_CHECK(OBJECT_PTR)                                                                                            \
    if(--(OBJECT_PTR->ttl) == 0) {OBJECT_PTR->tick = idle;  /* check if enemy should still be rendered */                    \
    ++(the_game.score);  return;} /* and also increase score */ /** TODO: implement score getting even more with higher stage */

#define DECODE_VAR(STAGE, VAR_TYPE) _ST##STAGE##_##VAR_TYPE##_LUT

#define DRAW_OBJECT_MID(OBJECT_PTR, STAGE)                                                                                  \
    Reset0Ref(); dp_VIA_t1_cnt_lo = 0x7f; /* prepare */                                                                     \
    Moveto_d(DECODE_VAR(STAGE, Y1)[OBJECT_PTR->ttl],0);                                                                     \
    Moveto_d(DECODE_VAR(STAGE, Y2)[OBJECT_PTR->ttl],0); /* two moves because of big range of motion*/                       \
    dp_VIA_t1_cnt_lo = DECODE_VAR(STAGE, SC)[OBJECT_PTR->ttl]; /* set scaling */                                            \
    Draw_VLp((struct packet_t *) OBJECT_PTR->model); /* draw */

    
#define DRAW_OBJECT_LEFT(OBJECT_PTR, STAGE)                                                                                 \
    Reset0Ref(); dp_VIA_t1_cnt_lo = 0x7f; /* prepare */                                                                     \
    Moveto_d(DECODE_VAR(STAGE, Y1)[OBJECT_PTR->ttl],DECODE_VAR(STAGE, XL)[OBJECT_PTR->ttl]);                                \
    Moveto_d(DECODE_VAR(STAGE, Y2)[OBJECT_PTR->ttl],0); /* two moves because of big range of motion*/                       \
    dp_VIA_t1_cnt_lo = DECODE_VAR(STAGE, SC)[OBJECT_PTR->ttl]; /* set scaling */                                            \
    Draw_VLp((struct packet_t *) OBJECT_PTR->model); /* draw */

    
#define DRAW_OBJECT_RIGHT(OBJECT_PTR, STAGE)                                                                                \
    Reset0Ref(); dp_VIA_t1_cnt_lo = 0x7f; /* prepare */                                                                     \
    Moveto_d(DECODE_VAR(STAGE, Y1)[OBJECT_PTR->ttl],DECODE_VAR(STAGE, XR)[OBJECT_PTR->ttl]);                                \
    Moveto_d(DECODE_VAR(STAGE, Y2)[OBJECT_PTR->ttl],0); /* two moves because of big range of motion*/                       \
    dp_VIA_t1_cnt_lo = DECODE_VAR(STAGE, SC)[OBJECT_PTR->ttl]; /* set scaling */                                            \
    Draw_VLp((struct packet_t *) OBJECT_PTR->model); /* draw */






/**************************************************************************
 * concrete tick functions
 **************************************************************************/

/**
 * @brief not yet spawned / despawned object is in idle
 */
void idle(__attribute__((unused)) moving_object_t* me)
{
    return;
}




/// generated object paths
#include "game_include/gen_data/gen_object_path.h"

 
void _tick_st0_mid(moving_object_t * me)
{
    DRAW_OBJECT_MID(me, 0);
    DESPAWN_CHECK(me);
    return;
}
void _tick_st0_left(moving_object_t * me)
{
    DRAW_OBJECT_LEFT(me, 0);
    DESPAWN_CHECK(me);
    return;
}
void _tick_st0_right(moving_object_t * me)
{
    DRAW_OBJECT_RIGHT(me, 0);
    DESPAWN_CHECK(me);
    return;
}

void _tick_st1_mid(moving_object_t * me)
{
    DRAW_OBJECT_MID(me, 1);
    DESPAWN_CHECK(me);
    return;
}
void _tick_st1_left(moving_object_t * me)
{
    DRAW_OBJECT_LEFT(me, 1);
    DESPAWN_CHECK(me);
    return;
}
void _tick_st1_right(moving_object_t * me)
{
    DRAW_OBJECT_RIGHT(me, 1);
    DESPAWN_CHECK(me);
    return;
}

void _tick_st2_mid(moving_object_t * me)
{
    DRAW_OBJECT_MID(me, 2);
    DESPAWN_CHECK(me);
    return;
}
void _tick_st2_left(moving_object_t * me)
{
    DRAW_OBJECT_LEFT(me, 2);
    DESPAWN_CHECK(me);
    return;
}
void _tick_st2_right(moving_object_t * me)
{
    DRAW_OBJECT_RIGHT(me, 2);
    DESPAWN_CHECK(me);
    return;
}

void _tick_st3_mid(moving_object_t * me)
{
    DRAW_OBJECT_MID(me, 3);
    DESPAWN_CHECK(me);
    return;
}
void _tick_st3_left(moving_object_t * me)
{
    DRAW_OBJECT_LEFT(me, 3);
    DESPAWN_CHECK(me);
    return;
}
void _tick_st3_right(moving_object_t * me)
{
    DRAW_OBJECT_RIGHT(me, 3);
    DESPAWN_CHECK(me);
    return;
}

void _tick_st4_mid(moving_object_t * me)
{
    DRAW_OBJECT_MID(me, 4);
    DESPAWN_CHECK(me);
    return;
}
void _tick_st4_left(moving_object_t * me)
{
    DRAW_OBJECT_LEFT(me, 4);
    DESPAWN_CHECK(me);
    return;
}
void _tick_st4_right(moving_object_t * me)
{
    DRAW_OBJECT_RIGHT(me, 4);
    DESPAWN_CHECK(me);
    return;
}

void _tick_st5_mid(moving_object_t * me)
{
    DRAW_OBJECT_MID(me, 5);
    DESPAWN_CHECK(me);
    return;
}
void _tick_st5_left(moving_object_t * me)
{
    DRAW_OBJECT_LEFT(me, 5);
    DESPAWN_CHECK(me);
    return;
}
void _tick_st5_right(moving_object_t * me)
{
    DRAW_OBJECT_RIGHT(me, 5);
    DESPAWN_CHECK(me);
    return;
}

void _tick_st6_mid(moving_object_t * me)
{
    DRAW_OBJECT_MID(me, 6);
    DESPAWN_CHECK(me);
    return;
}
void _tick_st6_left(moving_object_t * me)
{
    DRAW_OBJECT_LEFT(me, 6);
    DESPAWN_CHECK(me);
    return;
}
void _tick_st6_right(moving_object_t * me)
{
    DRAW_OBJECT_RIGHT(me, 6);
    DESPAWN_CHECK(me);
    return;
}

void _tick_st7_mid(moving_object_t * me)
{
    DRAW_OBJECT_MID(me, 7);
    DESPAWN_CHECK(me);
    return;
}
void _tick_st7_left(moving_object_t * me)
{
    DRAW_OBJECT_LEFT(me, 7);
    DESPAWN_CHECK(me);
    return;
}
void _tick_st7_right(moving_object_t * me)
{
    DRAW_OBJECT_RIGHT(me, 7);
    DESPAWN_CHECK(me);
    return;
}

void _tick_st8_mid(moving_object_t * me)
{
    DRAW_OBJECT_MID(me, 8);
    DESPAWN_CHECK(me);
    return;
}
void _tick_st8_left(moving_object_t * me)
{
    DRAW_OBJECT_LEFT(me, 8);
    DESPAWN_CHECK(me);
    return;
}
void _tick_st8_right(moving_object_t * me)
{
    DRAW_OBJECT_RIGHT(me, 8);
    DESPAWN_CHECK(me);
    return;
}

void _tick_st9_mid(moving_object_t * me)
{
    DRAW_OBJECT_MID(me, 9);
    DESPAWN_CHECK(me);
    return;
}
void _tick_st9_left(moving_object_t * me)
{
    DRAW_OBJECT_LEFT(me, 9);
    DESPAWN_CHECK(me);
    return;
}
void _tick_st9_right(moving_object_t * me)
{
    DRAW_OBJECT_RIGHT(me, 9);
    DESPAWN_CHECK(me);
    return;
}

void _tick_st10_mid(moving_object_t * me)
{
    DRAW_OBJECT_MID(me, 10);
    DESPAWN_CHECK(me);
    return;
}
void _tick_st10_left(moving_object_t * me)
{
    DRAW_OBJECT_LEFT(me, 10);
    DESPAWN_CHECK(me);
    return;
}
void _tick_st10_right(moving_object_t * me)
{
    DRAW_OBJECT_RIGHT(me, 10);
    DESPAWN_CHECK(me);
    return;
}





/**********************************************
 * LUTs
 *********************************************/

void (* const MOVING_OBJECT_TICK_FNC_LUT[STAGE_T_SIZE][3]) (moving_object_t * me) =
{
    { //< stage 0
        _tick_st0_left,
        _tick_st0_mid,
        _tick_st0_right
    },
    { //< stage 1
        _tick_st1_left,
        _tick_st1_mid,
        _tick_st1_right
    },
    { //< stage 2
        _tick_st2_left,
        _tick_st2_mid,
        _tick_st2_right
    },
    { //< stage 3
        _tick_st3_left,
        _tick_st3_mid,
        _tick_st3_right
    },
    { //< stage 4
        _tick_st4_left,
        _tick_st4_mid,
        _tick_st4_right
    },
    { //< stage 5
        _tick_st5_left,
        _tick_st5_mid,
        _tick_st5_right
    },
    { //< stage 6
        _tick_st6_left,
        _tick_st6_mid,
        _tick_st6_right
    },
    { //< stage 7
        _tick_st7_left,
        _tick_st7_mid,
        _tick_st7_right
    },
    { //< stage 8
        _tick_st8_left,
        _tick_st8_mid,
        _tick_st8_right
    },
    { //< stage 9
        _tick_st9_left,
        _tick_st9_mid,
        _tick_st9_right
    },
    { //< stage 10
        _tick_st10_left,
        _tick_st10_mid,
        _tick_st10_right
    }
};
