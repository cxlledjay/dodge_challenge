;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	game.c
	.area	.bss
	.globl	_the_game
_the_game:	.blkb	5
	.area	.text
	.globl	_game_init
_game_init:
	ldd	#0
	std	_the_game
	clr	_the_game+2
	jsr	_clk_init
	jsr	_map_init
	jsr	_player_init
	jsr	_ability_init
	jsr	_enemy_init
	ldx	#_start_menu
	stx	_the_game+3
	rts
	.globl	_start_menu
_start_menu:
	ldx	#_play_start_animation
	stx	_the_game+3
	rts
	.globl	_play_start_animation
_play_start_animation:
	ldx	#_game_run
	stx	_the_game+3
	rts
	.globl	_game_run
_game_run:
	leas	-2,s
	jsr	___Wait_Recal
	jsr	___Read_Btns
	ldb	_Vec_Buttons
	stb	,s
	bitb	#1
	bne	L15
	ldb	,s
	bitb	#6
	beq	L16
L10:
	jsr	_clk_update
	jsr	[_the_map+1]
	jsr	[_the_player+2]
	leas	2,s
	rts
L16:
	ldb	#2
	andb	,s
	beq	L11
L13:
	ldx	#_player_change_left
	stx	_the_player+2
	bra	L10
L15:
	ldx	#_pause_menu
	stx	_the_game+3
	leas	2,s
	rts
L11:
	ldb	#4
	andb	,s
	beq	L10
	bra	L13
	.globl	_pause_menu
_pause_menu:
	rts
	.globl	_game_over
_game_over:
	rts
