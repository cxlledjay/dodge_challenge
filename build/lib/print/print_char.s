;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	print_char.c
	.area	.text
	.globl	_print_char
_print_char:
	leas	-5,s
	stb	,s
	ldb	8,s
	stb	1,s
	ldb	#32
	stb	2,s
	stb	3,s
	ldb	#-128
	stb	4,s
	jsr	___Reset0Ref
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	,s
	pshs	b
	ldb	8,s
	jsr	__Moveto_d
	leax	2,s
	jsr	__Print_Str
	leas	6,s
	rts
