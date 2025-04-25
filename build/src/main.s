;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
	.module	main.c
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
	.globl	_lookup_player_lane_x_pos
_lookup_player_lane_x_pos:
	.byte	-48
	.byte	0
	.byte	48
	.globl	_main
_main:
	leas	-1,s
L8:
	jsr	___Wait_Recal
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
	ldb	_player_lane
	pshs	b
	ldb	#-80
	stb	,-s
	ldb	#120
	jsr	_print_unsigned_int
	leas	2,s
	jsr	___Intensity_5F
	jsr	___Reset0Ref
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	_player_lane
	clra		;zero_extendqihi: R:b -> R:d
	tfr	d,x
	ldb	_lookup_player_lane_x_pos,x
	stb	,s
	ldb	#-100
	stb	,-s
	ldb	1,s
	jsr	__Moveto_d
	leas	1,s
	ldb	#64
	stb	*_dp_VIA_t1_cnt_lo
	ldx	#_vectors_player
	jsr	___Draw_VLp
	lbra	L8
