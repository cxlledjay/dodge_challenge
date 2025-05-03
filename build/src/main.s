;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	main.c
	.area	.text
	.globl	_run_game
_run_game:
	jsr	_clk_init
	jsr	_lvl_init
	jsr	_map_init
	jsr	_player_init
L2:
	jsr	___Wait_Recal
	jsr	_clk_update
	jsr	_map_calculate_animation
	jsr	_map_draw_road
	jsr	_player_handle_input
	jsr	_player_draw
	bra	L2
	.globl	_main
_main:
	jsr	_run_game
