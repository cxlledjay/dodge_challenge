#pragma once

typedef enum _ability_class_t
{
    AB_NONE = 0,
    AB_EXTRA_LIVE,
    AB_ROCKETS
    //...
}ability_class_t;


/* typedef struct _ability_t
{
    unsigned int cnt; //< private counter to keep track about ability animation etc
    ability_class_t type; //< type of ability -> used to draw in HUD
    void (* tick) (void); //< trigger when using abiltiy
}ability_t; */


void ability_init(void);