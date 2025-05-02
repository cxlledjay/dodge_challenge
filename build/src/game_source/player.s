;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
	.module	player.c
	.globl	_vl_player_mid
	.area	.text
_vl_player_mid:
	.byte	0
	.byte	-24
	.byte	-20
	.byte	-1
	.byte	0
	.byte	-20
	.byte	-1
	.byte	32
	.byte	0
	.byte	-1
	.byte	0
	.byte	20
	.byte	-1
	.byte	-32
	.byte	0
	.byte	0
	.byte	4
	.byte	0
	.byte	-1
	.byte	4
	.byte	15
	.byte	0
	.byte	0
	.byte	10
	.byte	-1
	.byte	-4
	.byte	15
	.byte	0
	.byte	-4
	.byte	0
	.byte	-1
	.byte	0
	.byte	20
	.byte	-1
	.byte	32
	.byte	0
	.byte	-1
	.byte	0
	.byte	-20
	.byte	-1
	.byte	-32
	.byte	0
	.byte	0
	.byte	8
	.byte	0
	.byte	-1
	.byte	0
	.byte	-40
	.byte	0
	.byte	16
	.byte	0
	.byte	-1
	.byte	4
	.byte	15
	.byte	-1
	.byte	0
	.byte	10
	.byte	-1
	.byte	-4
	.byte	15
	.byte	-1
	.byte	28
	.byte	-16
	.byte	-1
	.byte	0
	.byte	-8
	.byte	0
	.byte	-7
	.byte	12
	.byte	-1
	.byte	0
	.byte	12
	.byte	-1
	.byte	4
	.byte	-2
	.byte	-1
	.byte	0
	.byte	-12
	.byte	0
	.byte	0
	.byte	-12
	.byte	-1
	.byte	0
	.byte	-12
	.byte	-1
	.byte	-4
	.byte	-2
	.byte	-1
	.byte	0
	.byte	12
	.byte	0
	.byte	7
	.byte	4
	.byte	-1
	.byte	-28
	.byte	-16
	.byte	0
	.byte	8
	.byte	-10
	.byte	-1
	.byte	10
	.byte	0
	.byte	-1
	.byte	0
	.byte	15
	.byte	-1
	.byte	-9
	.byte	0
	.byte	0
	.byte	0
	.byte	30
	.byte	-1
	.byte	9
	.byte	0
	.byte	-1
	.byte	0
	.byte	15
	.byte	-1
	.byte	-10
	.byte	0
	.byte	0
	.byte	5
	.byte	-25
	.byte	-1
	.byte	4
	.byte	-2
	.byte	-1
	.byte	0
	.byte	-6
	.byte	-1
	.byte	-4
	.byte	-2
_vl_term_0_75:
	.byte	1
	.globl	_vl_player_left
_vl_player_left:
	.byte	0
	.byte	-24
	.byte	-20
_vl_term_1_84:
	.byte	1
	.globl	_vl_player_right
_vl_player_right:
	.byte	0
	.byte	-24
	.byte	-20
_vl_term_2_93:
	.byte	1
	.globl	_player_lane
	.area	.data
_player_lane:
	.byte	1
	.area	.text
	.globl	_change_lane
_change_lane:
	leas	-1,s
	stb	,s
	ldb	,s
	cmpb	#1	;cmpqi:
	bne	L2
	ldb	_player_lane
	cmpb	#2	;cmpqi:
	beq	L4
	ldb	_player_lane
	incb
	stb	_player_lane
	bra	L4
L2:
	ldb	,s
	cmpb	#-1	;cmpqi:
	bne	L4
	ldb	_player_lane
	tstb
	beq	L4
	ldb	_player_lane
	decb
	stb	_player_lane
L4:
	leas	1,s
	rts
	.globl	_player_handle_input
_player_handle_input:
	jsr	___Read_Btns
	ldb	_Vec_Buttons
	andb	#1
	tstb
	beq	L6
	ldb	#-1
	jsr	_change_lane
	bra	L7
L6:
	ldb	_Vec_Buttons
	andb	#4
	tstb
	beq	L7
	ldb	#1
	jsr	_change_lane
L7:
	ldb	_Vec_Buttons
	andb	#2
	tstb
	beq	L8
	ldb	_lvl_speed
	cmpb	#1	;cmpqi:
	bne	L9
	ldb	#10
	stb	_lvl_speed
	bra	L13
L9:
	ldb	_lvl_speed
	decb
	stb	_lvl_speed
	bra	L13
L8:
	ldb	_Vec_Buttons
	andb	#8
	tstb
	beq	L13
	ldb	_lvl_speed
	cmpb	#10	;cmpqi:
	bne	L12
	ldb	#1
	stb	_lvl_speed
	bra	L13
L12:
	ldb	_lvl_speed
	incb
	stb	_lvl_speed
L13:
	rts
	.globl	_local_lu_player_x_pos
_local_lu_player_x_pos:
	.byte	-71
	.byte	0
	.byte	71
	.globl	_player_draw
_player_draw:
	leas	-1,s
	jsr	___Intensity_5F
	jsr	___Reset0Ref
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	_player_lane
	clra		;zero_extendqihi: R:b -> R:d
	tfr	d,x
	ldb	_local_lu_player_x_pos,x
	stb	,s
	ldb	#-112
	stb	,-s
	ldb	1,s
	jsr	__Moveto_d
	leas	1,s
	ldb	#64
	stb	*_dp_VIA_t1_cnt_lo
	ldx	#_vl_player_mid
	jsr	___Draw_VLp
	leas	1,s
	rts
