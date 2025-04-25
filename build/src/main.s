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
	.globl	_draw_road
_draw_road:
	jsr	___Intensity_5F
	jsr	___Reset0Ref
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	#36
	stb	,-s
	ldb	#-128
	jsr	__Moveto_d
	leas	1,s
	ldb	#-1
	stb	*_dp_VIA_t1_cnt_lo
	ldx	#_vectors_horizon
	jsr	___Draw_VLp
	jsr	___Reset0Ref
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	#36
	stb	,-s
	ldb	#-15
	jsr	__Moveto_d
	leas	1,s
	ldb	#-1
	stb	*_dp_VIA_t1_cnt_lo
	ldx	#_vectors_road_outer_line_l
	jsr	___Draw_VLp
	jsr	___Reset0Ref
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	#36
	stb	,-s
	ldb	#-5
	jsr	__Moveto_d
	leas	1,s
	ldb	#-1
	stb	*_dp_VIA_t1_cnt_lo
	ldx	#_vectors_road_inner_line_l
	jsr	___Draw_VLp
	jsr	___Reset0Ref
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	#36
	stb	,-s
	ldb	#5
	jsr	__Moveto_d
	leas	1,s
	ldb	#-1
	stb	*_dp_VIA_t1_cnt_lo
	ldx	#_vectors_road_inner_line_r
	jsr	___Draw_VLp
	jsr	___Reset0Ref
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	#36
	stb	,-s
	ldb	#15
	jsr	__Moveto_d
	leas	1,s
	ldb	#-1
	stb	*_dp_VIA_t1_cnt_lo
	ldx	#_vectors_road_outer_line_r
	jsr	___Draw_VLp
	rts
	.globl	_lookup_player_lane_x_pos
_lookup_player_lane_x_pos:
	.byte	-71
	.byte	0
	.byte	71
	.globl	_main
_main:
	leas	-1,s
L10:
	jsr	___Wait_Recal
	jsr	_draw_road
	jsr	___Read_Btns
	ldb	_Vec_Buttons
	andb	#1
	tstb
	beq	L8
	ldb	#-1
	jsr	_change_lane
	bra	L9
L8:
	ldb	_Vec_Buttons
	andb	#4
	tstb
	beq	L9
	ldb	#1
	jsr	_change_lane
L9:
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
	ldb	#-112
	stb	,-s
	ldb	1,s
	jsr	__Moveto_d
	leas	1,s
	ldb	#64
	stb	*_dp_VIA_t1_cnt_lo
	ldx	#_vectors_player
	jsr	___Draw_VLp
	lbra	L10
