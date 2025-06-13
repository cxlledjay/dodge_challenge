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
	jsr	___Read_Btns
	ldb	_Vec_Buttons
	stb	,s
	bitb	#1
	bne	L19
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
	bne	L20
	ldb	#4
	andb	,s
	beq	L11
	ldx	_the_player+5
	cmpx	#_player_draw	;cmphi:
	beq	L21
L11:
	jsr	_clock_tick
	jsr	[_the_map+1]
	jsr	[_the_player+5]
	leas	1,s
	rts
L19:
	inc	_the_game+2
	leas	1,s
	rts
L20:
	ldx	_the_player+5
	cmpx	#_player_draw	;cmphi:
	bne	L11
	ldb	_the_player
	cmpb	#1	;cmpqi:
	beq	L13
	cmpb	#2	;cmpqi:
	bne	L11
	ldx	#_player_change_right_to_mid_step1
	stx	_the_player+5
	ldb	_the_game+2
	clra		;zero_extendqihi: R:b -> R:d
	tfr	d,x
	ldb	_PLAYER_ANIMATION_FRAME_CNT_STAGE1_LUT,x
	stb	_the_player+4
	ldx	#__SP1_RIGHT_MID_X_LUT_1
	stx	_the_player+2
	ldb	#3
	stb	_the_player
	bra	L11
L21:
	ldb	_the_player
	bne	L22
	ldx	#_player_change_left_to_mid_step1
	stx	_the_player+5
	ldb	_the_game+2
	clra		;zero_extendqihi: R:b -> R:d
	tfr	d,x
	ldb	_PLAYER_ANIMATION_FRAME_CNT_STAGE1_LUT,x
	stb	_the_player+4
	ldx	#__SP1_LEFT_MID_X_LUT_1
	stx	_the_player+2
	ldb	#3
	stb	_the_player
	lbra	L11
L13:
	ldx	#_player_change_mid_to_left_step1
	stx	_the_player+5
	ldb	_the_game+2
	clra		;zero_extendqihi: R:b -> R:d
	tfr	d,x
	ldb	_PLAYER_ANIMATION_FRAME_CNT_STAGE1_LUT,x
	stb	_the_player+4
	ldx	#__SP1_MID_LEFT_X_LUT_1
	stx	_the_player+2
	ldb	#3
	stb	_the_player
	lbra	L11
L22:
	cmpb	#1	;cmpqi:
	lbne	L11
	ldx	#_player_change_mid_to_right_step1
	stx	_the_player+5
	ldb	_the_game+2
	clra		;zero_extendqihi: R:b -> R:d
	tfr	d,x
	ldb	_PLAYER_ANIMATION_FRAME_CNT_STAGE1_LUT,x
	stb	_the_player+4
	ldx	#__SP1_MID_RIGHT_X_LUT_1
	stx	_the_player+2
	ldb	#3
	stb	_the_player
	lbra	L11
	.globl	_pause_menu
_pause_menu:
	rts
	.globl	_game_over
_game_over:
	rts
