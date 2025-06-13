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
	jsr	_clock_init
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
	leas	-1,s
	jsr	___Wait_Recal
	ldb	_the_game+2
	stb	,-s
	ldb	#-20
	stb	,-s
	ldb	#100
	jsr	_print_unsigned_int
	jsr	___Read_Btns
	ldb	_Vec_Buttons
	stb	2,s
	leas	2,s
	bitb	#1
	bne	L15
	ldb	#8
	andb	,s
	beq	L10
	dec	_the_game+2
L10:
	ldb	#6
	andb	,s
	cmpb	#6	;cmpqi:
	beq	L11
	ldb	#2
	andb	,s
	bne	L16
	ldb	#4
	andb	,s
	beq	L11
	ldx	#_player_change_right
	stx	_the_player+2
L11:
	jsr	_clock_tick
	jsr	[_the_map+1]
	jsr	[_the_player+2]
	leas	1,s
	rts
L15:
	inc	_the_game+2
	leas	1,s
	rts
L16:
	ldx	#_player_change_left
	stx	_the_player+2
	bra	L11
	.globl	_pause_menu
_pause_menu:
	rts
	.globl	_game_over
_game_over:
	rts
