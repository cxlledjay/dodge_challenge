;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	map.c
	.globl	_vl_misc_roadline_left
	.area	.text
_vl_misc_roadline_left:
	.byte	-1
	.byte	-32
	.byte	-8
	.byte	0
	.byte	-32
	.byte	-8
	.byte	-1
	.byte	-32
	.byte	-8
	.byte	0
	.byte	-32
	.byte	-8
	.byte	-1
	.byte	-64
	.byte	-16
	.byte	0
	.byte	-64
	.byte	-16
	.byte	-1
	.byte	-64
	.byte	-16
	.byte	0
	.byte	-64
	.byte	-16
	.byte	-1
	.byte	-96
	.byte	-24
	.byte	0
	.byte	-96
	.byte	-24
	.byte	-1
	.byte	-96
	.byte	-24
	.byte	0
	.byte	-96
	.byte	-24
	.byte	-1
	.byte	-128
	.byte	-32
	.byte	0
	.byte	-128
	.byte	-32
	.byte	-1
	.byte	-128
	.byte	-32
	.byte	0
	.byte	-128
	.byte	-32
	.byte	-1
	.byte	-128
	.byte	-32
	.byte	-1
	.byte	-32
	.byte	-8
_vl_term_0_35:
	.byte	1
	.globl	_vl_misc_roadline_right
_vl_misc_roadline_right:
	.byte	-1
	.byte	-32
	.byte	8
	.byte	0
	.byte	-32
	.byte	8
	.byte	-1
	.byte	-32
	.byte	8
	.byte	0
	.byte	-32
	.byte	8
	.byte	-1
	.byte	-64
	.byte	16
	.byte	0
	.byte	-64
	.byte	16
	.byte	-1
	.byte	-64
	.byte	16
	.byte	0
	.byte	-64
	.byte	16
	.byte	-1
	.byte	-96
	.byte	24
	.byte	0
	.byte	-96
	.byte	24
	.byte	-1
	.byte	-96
	.byte	24
	.byte	0
	.byte	-96
	.byte	24
	.byte	-1
	.byte	-128
	.byte	32
	.byte	0
	.byte	-128
	.byte	32
	.byte	-1
	.byte	-128
	.byte	32
	.byte	0
	.byte	-128
	.byte	32
	.byte	-1
	.byte	-128
	.byte	32
	.byte	-1
	.byte	-32
	.byte	8
_vl_term_1_60:
	.byte	1
	.globl	_local_lu_animation_interval
_local_lu_animation_interval:
	.byte	93
	.byte	81
	.byte	69
	.byte	58
	.byte	49
	.byte	42
	.byte	34
	.area	.bss
	.globl	_animation_step
_animation_step:	.blkb	1
	.area	.text
	.globl	_map_init
_map_init:
	clr	_animation_step
	rts
	.globl	_map_calculate_animation
_map_calculate_animation:
	pshs	y
	leas	-4,s
	ldb	_lvl_speed
	clra		;zero_extendqihi: R:b -> R:d
	tfr	d,x
	ldb	_local_lu_animation_interval,x
	clra		;zero_extendqihi: R:b -> R:d
	std	,s
	ldy	#3
	pshs	y
	ldx	2,s
	jsr	_udivhi3
	leas	2,s
	stx	,s
	ldb	_clk_frames
	clra		;zero_extendqihi: R:b -> R:d
	std	2,s
	tfr	x,d	;movlsbqihi: R:x -> R:b
	clra		;zero_extendqihi: R:b -> R:d
	pshs	d
	ldx	4,s
	jsr	_udivhi3
	tfr	x,d
	clra		;zero_extendqihi: R:b -> R:d
	sty	,s
	tfr	d,x
	jsr	_umodhi3
	tfr	x,d
	stb	_animation_step	;movlsbqihi: R:d -> _animation_step
	leas	6,s
	puls	y,pc
	.globl	_map_draw_road
_map_draw_road:
	leas	-3,s
	jsr	___Intensity_5F
	jsr	___Reset0Ref
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	#36
	stb	,-s
	ldb	#-15
	jsr	__Moveto_d
	ldb	#-88
	stb	*_dp_VIA_t1_cnt_lo
	ldb	#-128
	stb	,-s
	addb	#46
	jsr	__Draw_Line_d
	jsr	___Reset0Ref
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	_animation_step
	stb	3,s
	leas	2,s
	cmpb	#2	;cmpqi:
	lbeq	L12
	ldb	#-5
	subb	1,s
	stb	,s
	ldb	#9
	subb	1,s
	aslb
	aslb
	pshs	b
	ldb	1,s
	jsr	__Moveto_d
	leas	1,s
L7:
	ldb	#16
	stb	*_dp_VIA_t1_cnt_lo
	ldx	#_vl_misc_roadline_left
	jsr	___Draw_VLp
	jsr	___Reset0Ref
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	_animation_step
	stb	2,s
	cmpb	#2	;cmpqi:
	lbeq	L13
	ldb	#9
	subb	2,s
	aslb
	aslb
	pshs	b
	ldb	3,s
	addb	#5
	stb	3,s
	jsr	__Moveto_d
	leas	1,s
L9:
	ldb	#16
	stb	*_dp_VIA_t1_cnt_lo
	ldx	#_vl_misc_roadline_right
	jsr	___Draw_VLp
	jsr	___Reset0Ref
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	#36
	stb	,-s
	ldb	#15
	jsr	__Moveto_d
	ldb	#-1
	stb	*_dp_VIA_t1_cnt_lo
	ldb	#-80
	stb	,-s
	ldb	#52
	jsr	__Draw_Line_d
	leas	5,s
	rts
L12:
	ldb	#36
	stb	,-s
	ldb	#-5
	jsr	__Moveto_d
	ldb	#-4
	stb	,-s
	addb	#3
	jsr	__Draw_Line_d
	ldb	#-4
	stb	,-s
	addb	#3
	jsr	__Moveto_d
	leas	3,s
	lbra	L7
L13:
	ldb	#36
	stb	,-s
	ldb	#5
	jsr	__Moveto_d
	ldb	#-4
	stb	,-s
	ldb	#1
	jsr	__Draw_Line_d
	ldb	#-4
	stb	,-s
	ldb	#1
	jsr	__Moveto_d
	leas	3,s
	lbra	L9
