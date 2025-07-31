#pragma once


typedef struct _map_t
{
    unsigned int cnt; //< used to track roadline animation
    void (*tick) (void); //< used to draw map
} map_t;

/**
 * @brief singleton instance of the map
 *        used to draw and animate the background road
 * 
 * manipulate via different tick() functions (e.g. displaying new speed)
 */
extern map_t the_map;


/**
 * @brief init function
 */
void map_init(void);


/****************************************************
 * macro utils (needed in game.c as well)
 ***************************************************/

#define DRAW_LEFT() 				\
	Reset0Ref(); 					\
	dp_VIA_t1_cnt_lo = 0x7f;		\
	Moveto_d(36, -15);				\
	dp_VIA_t1_cnt_lo = 187;			\
	Draw_Line_d(-128,-82);
	
#define DRAW_RIGHT() 				\
	Reset0Ref(); 					\
	dp_VIA_t1_cnt_lo = 0x7f;		\
	Moveto_d(36, 15);				\
	dp_VIA_t1_cnt_lo = 187;			\
	Draw_Line_d(-128,82);

#define ANIMATE_LEFT(VECLIST_PTR) 	\
	Reset0Ref();					\
	dp_VIA_t1_cnt_lo = 0x7f;		\
	Moveto_d(36, -5);				\
	dp_VIA_t1_cnt_lo = 16;			\
	Draw_VLp(VECLIST_PTR);	
	
#define ANIMATE_RIGHT(VECLIST_PTR) 	\
	Reset0Ref();					\
	dp_VIA_t1_cnt_lo = 0x7f;		\
	Moveto_d(36, 5);				\
	dp_VIA_t1_cnt_lo = 16;			\
	Draw_VLp(VECLIST_PTR);
