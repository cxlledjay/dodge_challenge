;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
	.module	print_char.c
	.area	.text
	.globl	_print_char
_print_char:
	leas	-9,s
	stb	,s
	ldb	12,s
	stb	1,s
	ldb	#32
	stb	2,s
	ldb	#32
	stb	3,s
	ldb	#-128
	stb	4,s
	ldb	,s
	stb	6,s
	ldb	11,s
	stb	5,s
	jsr	___Reset0Ref
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	6,s
	stb	8,s
	ldb	5,s
	stb	7,s
	ldb	8,s
	stb	,-s
	ldb	8,s
	jsr	__Moveto_d
	leas	1,s
	leax	1,s
	jsr	__Print_Str
	leas	9,s
	rts
