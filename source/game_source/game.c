#include "game_include/game.h"

/*****************************************************************************
 * the game is on...
 ****************************************************************************/
game_t the_game;


#include "game_include/clock.h"
#include "game_include/enemy.h"
#include "game_include/map.h"
#include "game_include/player.h"

//fw declarations:
void start_menu(void);
void play_start_animation(void);
void pause_menu(void);

/*****************************************************************************
 * init part
 ****************************************************************************/

void game_init(void)
{
    /// set game starting values
    the_game.score = 0;
    the_game.speed = 0; ///< ??

    /// trigger all other init routines
    clk_init();
    enemy_init();
    map_init();
    player_init();

    /// go to select screen
    the_game.execute_state = start_menu;

    /// done
    return;
}



/*****************************************************************************
 * init subroutines
 ****************************************************************************/

void start_menu(void)
{
    //sync to 50 fps
    //get input
    //if settings confirmed -> start animation
    the_game.execute_state == play_start_animation;
    //draw selection screen

    /// done
    return;
}

void play_start_animation(void)
{
    //sync to 50 fps
    //draw screen (based on counter)
    //keep track of animation counter
    //if counter is done -> start game
    the_game.execute_state = game_run;

    /// done
    return;
}




/*****************************************************************************
 * game loop
 ****************************************************************************/

void game_run(void)
{
    /// sync to 50 fps
    Wait_Recal();


    /// get input
    check_buttons();
	if(button_1_1_pressed())
	{
		change_lane(-1);
	}
	else if(button_1_3_pressed())
	{
		change_lane(1);
	}

	
	//debug
	if(button_1_2_pressed())
	{
		if(lvl_speed != 0) lvl_speed = lvl_speed - 1;
	}
	else if (button_1_4_pressed())
	{
		if(lvl_speed != LVL_MAX_SPEED) lvl_speed = lvl_speed + 1;
	}

    /// calculations
    clk_update();
    map_calculate_animation();
    
    //build road
    map_draw_road();
    
    //io management
    player_handle_input();

    //debug
    //print_unsigned_int(120,60,lvl_speed);

    //draw player
    player_draw();
}





/*****************************************************************************
 * game loop subroutines
 ****************************************************************************/



void pause_menu(void)
{
    /// TODO: implement!
    return;
}