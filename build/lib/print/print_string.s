;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	print_string.c
	.area	.text
	.globl	_print_string
_print_string:
	leas	-2,s
	stb	,s
	ldb	4,s
	stb	1,s
	ldb	#-52
	stb	*_dp_VIA_cntl
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	,s
	stb	4,s
	ldb	1,s
	leas	2,s
	jmp	__Print_Str_d
