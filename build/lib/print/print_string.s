;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
	.module	print_string.c
	.area	.text
	.globl	_print_string
_print_string:
	leas	-7,s
	stb	2,s
	stx	,s
	ldb	#-52
	stb	*_dp_VIA_cntl
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	2,s
	stb	6,s
	ldb	9,s
	stb	5,s
	ldx	,s
	stx	3,s
	ldb	6,s
	stb	,-s
	ldx	4,s
	ldb	6,s
	jsr	__Print_Str_d
	leas	1,s
	leas	7,s
	rts
