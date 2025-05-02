;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	print_long_unsigned_int.c
	.area	.text
	.globl	_print_long_unsigned_int
_print_long_unsigned_int:
	leas	-7,s
	stb	,s
	ldb	#-128
	stb	6,s
	ldb	#48
	stb	4,s
	stb	3,s
	stb	2,s
	stb	1,s
	cmpx	#9999	;cmphi:
	bls	L19
L14:
	inc	1,s
	ldb	1,s
	leax	-10000,x
	cmpx	#9999	;cmphi:
	bhi	L14
	cmpx	#999	;cmphi:
	bls	L20
L13:
	inc	2,s
	ldb	2,s
	leax	-1000,x
L19:
	cmpx	#999	;cmphi:
	bhi	L13
	cmpx	#99	;cmphi:
	bls	L21
L12:
	inc	3,s
	ldb	3,s
	leax	-100,x
L20:
	cmpx	#99	;cmphi:
	bhi	L12
	cmpx	#9	;cmphi:
	bls	L23
L11:
	inc	4,s
	ldb	4,s
	leax	-10,x
L21:
	cmpx	#9	;cmphi:
	bhi	L11
L23:
	tfr	x,d	;movlsbqihi: R:x -> R:b
	addb	#48
	stb	5,s
	ldb	#-52
	stb	*_dp_VIA_cntl
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	,s
	pshs	b
	leax	2,s
	ldb	10,s
	jsr	__Print_Str_d
	leas	8,s
	rts
