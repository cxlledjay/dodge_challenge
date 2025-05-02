;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
	.module	map.c
	.globl	_vl_misc_roadline_left
	.area	.text
_vl_misc_roadline_left:
	.byte	-1
	.byte	-4
	.byte	-1
	.byte	0
	.byte	-4
	.byte	-1
	.byte	-1
	.byte	-4
	.byte	-1
	.byte	0
	.byte	-4
	.byte	-1
	.byte	-1
	.byte	-8
	.byte	-2
	.byte	0
	.byte	-8
	.byte	-2
	.byte	-1
	.byte	-8
	.byte	-2
	.byte	0
	.byte	-8
	.byte	-2
	.byte	-1
	.byte	-12
	.byte	-3
	.byte	0
	.byte	-12
	.byte	-3
	.byte	-1
	.byte	-12
	.byte	-3
	.byte	0
	.byte	-12
	.byte	-3
	.byte	-1
	.byte	-16
	.byte	-4
	.byte	0
	.byte	-16
	.byte	-4
	.byte	-1
	.byte	-16
	.byte	-4
	.byte	0
	.byte	-16
	.byte	-4
	.byte	-1
	.byte	-20
	.byte	-5
_vl_term_0_35:
	.byte	1
	.globl	_vl_misc_roadline_right
_vl_misc_roadline_right:
	.byte	-1
	.byte	-4
	.byte	1
	.byte	0
	.byte	-4
	.byte	1
	.byte	-1
	.byte	-4
	.byte	1
	.byte	0
	.byte	-4
	.byte	1
	.byte	-1
	.byte	-8
	.byte	2
	.byte	0
	.byte	-8
	.byte	2
	.byte	-1
	.byte	-8
	.byte	2
	.byte	0
	.byte	-8
	.byte	2
	.byte	-1
	.byte	-12
	.byte	3
	.byte	0
	.byte	-12
	.byte	3
	.byte	-1
	.byte	-12
	.byte	3
	.byte	0
	.byte	-12
	.byte	3
	.byte	-1
	.byte	-16
	.byte	4
	.byte	0
	.byte	-16
	.byte	4
	.byte	-1
	.byte	-16
	.byte	4
	.byte	0
	.byte	-16
	.byte	4
	.byte	-1
	.byte	-20
	.byte	5
_vl_term_1_59:
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
	.globl	_map_draw_road
_map_draw_road:
	pshs	u
	leas	-12,s
	jsr	___Intensity_5F
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
	ldb	_clk_frames
	stb	3,s
	ldb	_lvl_speed
	clra		;zero_extendqihi: R:b -> R:d
	tfr	d,x
	ldb	_local_lu_animation_interval,x
	clra		;zero_extendqihi: R:b -> R:d
	ldx	#3
	pshs	x
	tfr	d,x
	jsr	_udivhi3
	leas	2,s
	tfr	x,d	;movlsbqihi: R:x -> R:b
	stb	2,s
	ldb	3,s
	clra		;zero_extendqihi: R:b -> R:d
	tfr	d,x
	ldb	2,s
	clra		;zero_extendqihi: R:b -> R:d
	std	,s
	ldu	,s
	pshs	u
	jsr	_udivhi3
	leas	2,s
	tfr	x,d	;movlsbqihi: R:x -> R:b
	clra		;zero_extendqihi: R:b -> R:d
	ldx	#3
	pshs	x
	tfr	d,x
	jsr	_umodhi3
	leas	2,s
	tfr	x,d
	stb	6,s	;movlsbqihi: R:d -> 6,s
	ldb	6,s
	stb	7,s
	jsr	___Reset0Ref
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	7,s
	cmpb	#2	;cmpqi:
	bne	L2
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
	bra	L3
L2:
	ldb	#-5
	stb	2,s
	ldb	2,s
	subb	7,s
	stb	4,s
	ldb	#9
	subb	7,s
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
L3:
	ldx	#_vl_misc_roadline_left
	jsr	___Draw_VLp
	jsr	___Reset0Ref
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	7,s
	cmpb	#2	;cmpqi:
	bne	L4
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
	bra	L5
L4:
	ldb	7,s
	addb	#5
	stb	5,s
	ldb	#9
	subb	7,s
	aslb
	aslb
	stb	11,s
	ldb	5,s
	stb	10,s
	ldb	11,s
	stb	,-s
	ldb	11,s
	jsr	__Moveto_d
	leas	1,s
L5:
	ldx	#_vl_misc_roadline_right
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
	leas	12,s
	puls	u,pc
