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
	.globl	_temp
	.area	.data
_temp:
	.byte	0
	.area	.text
	.globl	_game_run
_game_run:
	leas	-1,s
	jsr	___Wait_Recal
	ldb	_temp
	beq	L22
	decb
	stb	_temp
	leas	1,s
	rts
L22:
	ldb	#10
	stb	_temp
	ldb	_the_player+1
	stb	,-s
	ldb	#-20
	stb	,-s
	ldb	#100
	jsr	_print_signed_int
	jsr	___Read_Btns
	ldb	_Vec_Buttons
	stb	2,s
	leas	2,s
	bitb	#1
	bne	L23
	ldb	#8
	andb	,s
	beq	L12
	dec	_the_game+2
L12:
	ldb	#6
	andb	,s
	cmpb	#6	;cmpqi:
	beq	L13
	ldb	#2
	andb	,s
	beq	L14
	ldx	_the_player+5
	cmpx	#_player_draw	;cmphi:
	beq	L24
L13:
	jsr	_clock_tick
	jsr	[_the_map+1]
	jsr	[_the_player+5]
	leas	1,s
	rts
L23:
	inc	_the_game+2
	leas	1,s
	rts
L14:
	ldb	#4
	andb	,s
	beq	L13
	ldx	_the_player+5
	cmpx	#_player_draw	;cmphi:
	bne	L13
	ldb	_the_player
	lbne	L25
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
	bra	L13
L24:
	ldb	_the_player
	cmpb	#1	;cmpqi:
	beq	L15
	cmpb	#2	;cmpqi:
	bne	L13
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
	lbra	L13
L15:
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
	lbra	L13
L25:
	cmpb	#1	;cmpqi:
	lbne	L13
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
	lbra	L13
	.globl	_pause_menu
_pause_menu:
	rts
	.globl	_game_over
_game_over:
	rts
