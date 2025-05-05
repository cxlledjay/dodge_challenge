;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	score.c
	.area	.bss
	.globl	_score
_score:	.blkb	2
	.area	.text
	.globl	_score_init
_score_init:
	ldd	#0
	std	_score
	rts
	.globl	_score_update
_score_update:
	inc	_score+1
	bne	__IL15
	inc	_score
	__IL15:
	rts
	.globl	_score_draw
_score_draw:
	pshs	y
	jsr	___Intensity_5F
	jsr	___Reset0Ref
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	#110
	stb	,-s
	addb	#46
	jsr	__Moveto_d
	ldb	#9
	stb	*_dp_VIA_t1_cnt_lo
	ldy	_vl_digits
	leax	,y
	jsr	___Draw_VLp
	clr	,-s
	ldb	#127
	jsr	__Moveto_d
	leax	,y
	jsr	___Draw_VLp
	clr	,-s
	ldb	#127
	jsr	__Moveto_d
	leax	,y
	jsr	___Draw_VLp
	clr	,-s
	ldb	#127
	jsr	__Moveto_d
	leax	,y
	jsr	___Draw_VLp
	clr	,-s
	ldb	#127
	jsr	__Moveto_d
	leax	,y
	jsr	___Draw_VLp
	ldb	#100
	stb	*_dp_VIA_t1_cnt_lo
	ldb	#-42
	stb	,-s
	ldb	#-127
	jsr	__Moveto_d
	ldb	#15
	stb	*_dp_VIA_t1_cnt_lo
	ldx	#_vl_speed_display
	jsr	___Draw_VLp
	ldb	#8
	stb	*_dp_VIA_t1_cnt_lo
	ldx	_vl_digits+4
	jsr	___Draw_VLp
	ldb	#-118
	stb	,-s
	ldb	#24
	jsr	__Moveto_d
	jsr	___Dot_here
	ldb	#118
	stb	,-s
	ldb	#103
	jsr	__Moveto_d
	leas	8,s
	ldx	_vl_digits+10
	puls	y
	jmp	___Draw_VLp
