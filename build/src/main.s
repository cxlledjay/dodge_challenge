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
	.globl	_temp_steps
	.area	.data
_temp_steps:
	.byte	0
	.globl	_temp_speed
_temp_speed:
	.byte	10
	.globl	_temp_time
_temp_time:
	.byte	10
	.area	.text
	.globl	_calculate_animation
_calculate_animation:
	ldb	_temp_time
	tstb
	bne	L6
	ldb	_temp_steps
	incb
	stb	_temp_steps
	ldb	_temp_steps
	cmpb	#3	;cmpqi:
	bne	L7
	clr	_temp_steps
L7:
	ldb	_temp_speed
	stb	_temp_time
	bra	L9
L6:
	ldb	_temp_time
	decb
	stb	_temp_time
L9:
	rts
	.globl	_draw_road
_draw_road:
	leas	-10,s
	jsr	___Intensity_5F
	jsr	_calculate_animation
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
	ldb	#-80
	stb	,-s
	ldb	#-52
	jsr	__Draw_Line_d
	leas	1,s
	jsr	___Reset0Ref
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	_temp_steps
	cmpb	#2	;cmpqi:
	bne	L11
	ldb	#36
	stb	,-s
	ldb	#-5
	jsr	__Moveto_d
	leas	1,s
	ldb	#-4
	stb	,-s
	ldb	#-1
	jsr	__Draw_Line_d
	leas	1,s
	ldb	#-4
	stb	,-s
	ldb	#-1
	jsr	__Moveto_d
	leas	1,s
	bra	L12
L11:
	ldb	_temp_steps
	stb	1,s
	ldb	#-5
	stb	,s
	ldb	,s
	subb	1,s
	stb	2,s
	ldb	_temp_steps
	stb	3,s
	ldb	#9
	subb	3,s
	aslb
	aslb
	stb	7,s
	ldb	2,s
	stb	6,s
	ldb	7,s
	stb	,-s
	ldb	7,s
	jsr	__Moveto_d
	leas	1,s
L12:
	ldx	#_vectors_road_inner_line_l
	jsr	___Draw_VLp
	jsr	___Reset0Ref
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	_temp_steps
	cmpb	#2	;cmpqi:
	bne	L13
	ldb	#36
	stb	,-s
	ldb	#5
	jsr	__Moveto_d
	leas	1,s
	ldb	#-4
	stb	,-s
	ldb	#1
	jsr	__Draw_Line_d
	leas	1,s
	ldb	#-4
	stb	,-s
	ldb	#1
	jsr	__Moveto_d
	leas	1,s
	bra	L14
L13:
	ldb	_temp_steps
	stb	,s
	ldb	,s
	addb	#5
	stb	4,s
	ldb	_temp_steps
	stb	5,s
	ldb	#9
	subb	5,s
	aslb
	aslb
	stb	9,s
	ldb	4,s
	stb	8,s
	ldb	9,s
	stb	,-s
	ldb	9,s
	jsr	__Moveto_d
	leas	1,s
L14:
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
	ldb	#-80
	stb	,-s
	ldb	#52
	jsr	__Draw_Line_d
	leas	1,s
	leas	10,s
	rts
	.globl	_draw_debug_car
_draw_debug_car:
	jsr	___Reset0Ref
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	clr	,-s
	clrb
	jsr	__Moveto_d
	leas	1,s
	ldb	_temp_speed
	lda	#10	;umulqihi3
	mul
		;movlsbqihi: D->B
	addb	#50
	stb	*_dp_VIA_t1_cnt_lo
	ldx	#_vectors_debug_car
	jsr	___Draw_VLp
	rts
	.globl	_lookup_player_lane_x_pos
_lookup_player_lane_x_pos:
	.byte	-71
	.byte	0
	.byte	71
	.globl	_game_loop
_game_loop:
	leas	-1,s
L26:
	jsr	___Wait_Recal
	jsr	_draw_road
	jsr	___Read_Btns
	ldb	_Vec_Buttons
	andb	#1
	tstb
	beq	L19
	ldb	#-1
	jsr	_change_lane
	bra	L20
L19:
	ldb	_Vec_Buttons
	andb	#4
	tstb
	beq	L20
	ldb	#1
	jsr	_change_lane
L20:
	ldb	_Vec_Buttons
	andb	#2
	tstb
	beq	L21
	ldb	_temp_speed
	cmpb	#1	;cmpqi:
	bne	L22
	ldb	#50
	stb	_temp_speed
	bra	L24
L22:
	ldb	_temp_speed
	decb
	stb	_temp_speed
	bra	L24
L21:
	ldb	_Vec_Buttons
	andb	#8
	tstb
	beq	L24
	ldb	_temp_speed
	cmpb	#50	;cmpqi:
	bne	L25
	ldb	#1
	stb	_temp_speed
	bra	L24
L25:
	ldb	_temp_speed
	incb
	stb	_temp_speed
L24:
	ldb	_player_lane
	pshs	b
	ldb	#-80
	stb	,-s
	ldb	#120
	jsr	_print_unsigned_int
	leas	2,s
	ldb	_temp_speed
	pshs	b
	ldb	#60
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
	lbra	L26
	.globl	_main
_main:
	jsr	_game_loop
