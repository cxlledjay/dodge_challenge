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


const unsigned int _ST00_Y_DEC[10] = { 1,1,1,1,1,1,1,1,1,1 };
const unsigned int _ST01_Y_DEC[10] = { 1,1,2,1,2,1,1,2,1,2 };
const unsigned int _ST02_Y_DEC[10] = { 1,2,2,1,2,2,1,2,1,2 };
const unsigned int _ST03_Y_DEC[10] = { 2,2,2,2,2,2,2,2,2,2 };
const unsigned int _ST04_Y_DEC[10] = { 2,2,3,2,3,2,2,3,2,3 };
const unsigned int _ST05_Y_DEC[10] = { 3,3,3,2,3,3,2,3,3,2 };
const unsigned int _ST06_Y_DEC[10] = { 3,4,3,3,3,3,4,3,3,3 };
const unsigned int _ST07_Y_DEC[10] = { 3,4,3,4,3,3,4,3,4,3 };
const unsigned int _ST08_Y_DEC[10] = { 4,4,5,4,4,4,5,4,4,5 };
const unsigned int _ST09_Y_DEC[10] = { 5,6,5,6,5,6,5,6,5,6 };
const unsigned int _ST10_Y_DEC[10] = { 8,9,8,8,9,8,9,8,9,8 };

#include "game_include/game.h"
const unsigned int * _ANIMATION_Y_DEC_LUT[STAGE_T_SIZE] =
{
    _ST00_Y_DEC,
    _ST01_Y_DEC,
    _ST02_Y_DEC,
    _ST03_Y_DEC,
    _ST04_Y_DEC,
    _ST05_Y_DEC,
    _ST06_Y_DEC,
    _ST07_Y_DEC,
    _ST08_Y_DEC,
    _ST09_Y_DEC,
    _ST10_Y_DEC
};


/// encoded Y starts at 0 (real y = 32) and goes to 232 (real y = -195)

/// encoded Y to real X pos LUTs

#define SPAWN_Y                 (32)
#define DESPAWN_Y               (-200)
#define CONVERSION_LUT_SIZE     (232u)

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
     6, 6, 6, 6, 6,
     7, 7, 7, 7, 7, //10
     8, 8, 8, 8, 8,
     9, 9, 9, 9, 9, //20
    10,10,10,10,10,
    11,11,11,11,11, //30
    12,12,12,12,12,
    13,13,13,13,13, //40
    14,14,14,14,14,
    15,15,15,15,15, //50
    16,16,16,16,16,
    17,17,17,17,17, //60
    18,18,18,18,18,
    19,19,19,19,19, //70
    20,20,20,20,20,
    21,21,21,21,21, //80
    22,22,22,22,22,
    23,23,23,23,23, //90
    24,24,24,24,24,
    25,25,25,25,25, //100
    26,26,26,26,26,
    27,27,27,27,27, //110
    28,28,28,28,28,
    29,29,29,29,29, //120
    30,30,30,30,30,
    31,31,31,31,31, //130
    32,32,32,32,32,
    33,33,33,33,33, //140
    34,34,34,34,34,
    35,35,35,35,35, //150
    36,36,36,36,36,
    37,37,37,37,37, //160
    38,38,38,38,38,
    39,39,39,39,39, //170
    40,40,40,40,40,
    41,41,41,41,41, //180
    42,42,42,42,42,
    43,43,43,43,43, //190
    44,44,44,44,44,
    45,45,45,45,45, //200
    46,46,46,46,46,
    47,47,47,47,47, //210
    48,48,48,48,48,
    49,49,49,49,49, //220
    50,50,50,50,50,
    51,51,51,51,51, //230
    52,52           //232
};
