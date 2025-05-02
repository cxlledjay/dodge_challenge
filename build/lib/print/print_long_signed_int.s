;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	print_long_signed_int.c
	.area	.text
	.globl	_print_long_signed_int
_print_long_signed_int:
	leas	-8,s
	stb	,s
	ldb	#-128
	stb	7,s
	ldb	#48
	stb	5,s
	stb	4,s
	stb	3,s
	stb	2,s
	cmpx	#0
	lblt	L2
	ldb	#43
	stb	1,s
	bra	L21
L16:
	inc	2,s
	ldb	2,s
	leax	-10000,x
L21:
	cmpx	#9999	;cmphi:
	bhi	L16
	cmpx	#999	;cmphi:
	ble	L23
L15:
	inc	3,s
	ldb	3,s
	leax	-1000,x
	cmpx	#999	;cmphi:
	bgt	L15
	cmpx	#99	;cmphi:
	ble	L24
L14:
	inc	4,s
	ldb	4,s
	leax	-100,x
L23:
	cmpx	#99	;cmphi:
	bgt	L14
	cmpx	#9	;cmphi:
	ble	L26
L13:
	inc	5,s
	ldb	5,s
	leax	-10,x
L24:
	cmpx	#9	;cmphi:
	bgt	L13
L26:
	tfr	x,d	;movlsbqihi: R:x -> R:b
	addb	#48
	stb	6,s
	ldb	#-52
	stb	*_dp_VIA_cntl
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	,s
	pshs	b
	leax	2,s
	ldb	11,s
	jsr	__Print_Str_d
	leas	9,s
	rts
L2:
	ldb	#45
	stb	1,s
	exg	d,x
	nega
	negb
	sbca	#0
	exg	d,x
	lbra	L21
