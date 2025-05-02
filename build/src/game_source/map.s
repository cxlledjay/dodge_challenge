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
	.globl	_local_cnt
	.area	.data
_local_cnt:
	.byte	0
	.globl	_animation_step
_animation_step:
	.byte	0
	.area	.text
	.globl	_map_draw_road
_map_draw_road:
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
	ldb	_lvl_speed
	stb	1,s
	ldb	#10
	subb	1,s
	stb	7,s
	ldb	_local_cnt
	cmpb	7,s	;cmpqi:
	bne	L2
	ldb	_animation_step
	cmpb	#2	;cmpqi:
	bne	L3
	clr	_animation_step
	bra	L4
L3:
	ldb	_animation_step
	incb
	stb	_animation_step
L4:
	clr	_local_cnt
	bra	L5
L2:
	ldb	_local_cnt
	incb
	stb	_local_cnt
L5:
	jsr	___Reset0Ref
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	_animation_step
	cmpb	#2	;cmpqi:
	bne	L6
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
	bra	L7
L6:
	ldb	_animation_step
	stb	2,s
	ldb	#-5
	stb	,s
	ldb	,s
	subb	2,s
	stb	3,s
	ldb	_animation_step
	stb	4,s
	ldb	#9
	subb	4,s
	aslb
	aslb
	stb	9,s
	ldb	3,s
	stb	8,s
	ldb	9,s
	stb	,-s
	ldb	9,s
	jsr	__Moveto_d
	leas	1,s
L7:
	ldx	#_vl_misc_roadline_left
	jsr	___Draw_VLp
	jsr	___Reset0Ref
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	_animation_step
	cmpb	#2	;cmpqi:
	bne	L8
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
	bra	L9
L8:
	ldb	_animation_step
	stb	,s
	ldb	,s
	addb	#5
	stb	5,s
	ldb	_animation_step
	stb	6,s
	ldb	#9
	subb	6,s
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
L9:
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
	rts
