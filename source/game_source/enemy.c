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

int enemy_try_spawn(lane_t lane)
{
    int ret = -1;
    //check if queue has space
    if(queue_ptr->tick == idle) 
    {
        #define spawn_y (30) //< TODO: adjust!
        // TODO: add rng to set different tick functions (one func for car model, one func for truck model, ...)
        enemy_t new_enemy = {.my_lane = lane, .y = spawn_y, .cnt = 0, .tick = tick_dummy};

        //check if spawn would make sense
        //e.g. already two enemies in same lane
        //e.g. enemy would collide with recently spawned enemy
        //...

        *queue_ptr = new_enemy;
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
