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






/**********************************************
 * LUTs
 *********************************************/


const unsigned int _ST00_EY_INC[10] = { 1,1,1,1,1,1,1,1,1,1 };
const unsigned int _ST01_EY_INC[10] = { 1,1,2,1,2,1,1,2,1,2 };
const unsigned int _ST02_EY_INC[10] = { 1,2,2,1,2,2,1,2,1,2 };
const unsigned int _ST03_EY_INC[10] = { 2,2,2,2,2,2,2,2,2,2 };
const unsigned int _ST04_EY_INC[10] = { 2,2,3,2,3,2,2,3,2,3 };
const unsigned int _ST05_EY_INC[10] = { 3,3,3,2,3,3,2,3,3,2 };
const unsigned int _ST06_EY_INC[10] = { 3,4,3,3,3,3,4,3,3,3 };
const unsigned int _ST07_EY_INC[10] = { 3,4,3,4,3,3,4,3,4,3 };
const unsigned int _ST08_EY_INC[10] = { 4,4,5,4,4,4,5,4,4,5 };
const unsigned int _ST09_EY_INC[10] = { 5,6,5,6,5,6,5,6,5,6 };
const unsigned int _ST10_EY_INC[10] = { 8,9,8,8,9,8,9,8,9,8 };

#include "game_include/game.h"
const unsigned int * _ANIMATION_EY_INC_LUT[STAGE_T_SIZE] =
{
    _ST00_EY_INC,
    _ST01_EY_INC,
    _ST02_EY_INC,
    _ST03_EY_INC,
    _ST04_EY_INC,
    _ST05_EY_INC,
    _ST06_EY_INC,
    _ST07_EY_INC,
    _ST08_EY_INC,
    _ST09_EY_INC,
    _ST10_EY_INC
};


/// encoded Y starts at 0 (real y = 32) and goes to 232 (real y = -195)


#define SPAWN_Y                 (32)
#define DESPAWN_Y               (-178)

#define CONVERSION_LUT_SIZE     (80u)


/// encoded Y to real Y pos LUTs

const int _CONVERT_EY_TO_RY1_LUT[CONVERSION_LUT_SIZE] =
{
    32, 31, 31, 31, 31, 31, 30, 30, 29, 29, 28, 28, 27, 26, 25, 24, 23, 22, 21, 20, 18, 17, 16, 14, 13, 11, 9, 8, 6, 4, 2, 0, -1, -3, -5, -8, -10, -12, -15, -17, -20, -23, -25, -28, -31, -34, -37, -40, -43, -46, -50, -53, -56, -60, -63, -67, -70, -74, -78, -82, -86, -90, -94, -98, -102, -106, -110, -115, -119, -124, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128
};

const int _CONVERT_EY_TO_RY2_LUT[CONVERSION_LUT_SIZE] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -5, -10, -14, -19, -24, -29, -34, -39, -44
};




/// encoded Y to real X pos LUTs

#define _CONVERT_Y_TO_X_MID_LUT(index)  (0u) //< in case i think i need to calculate something for midlane

const int _CONVERT_EY_TO_RX_LEFT_LUT[CONVERSION_LUT_SIZE] =
{

};

const int _CONVERT_EY_TO_RX_RIGHT_LUT[CONVERSION_LUT_SIZE] =
{

};


/// encoded Y to scale factor LUT

const unsigned int _CONVERT_EY_TO_SCALE[CONVERSION_LUT_SIZE] =
{
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 14, 15, 16, 16, 17, 17, 18, 19, 19, 20, 21, 21, 22, 23, 24, 24, 25, 26, 27, 28, 29, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 45, 46, 47, 48, 49, 50, 52, 53, 54, 55, 57
};
