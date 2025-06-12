;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	clock.c
	.area	.bss
	.globl	_the_clock
_the_clock:	.blkb	3
	.area	.text
	.globl	_clock_init
_clock_init:
	ldd	#0
	std	_the_clock+1
	ldb	#49
	stb	_the_clock
	rts
	.globl	_clock_tick
_clock_tick:
	ldb	_the_clock
	beq	L8
	decb
	stb	_the_clock
	rts
L8:
	ldb	#49
	stb	_the_clock
	ldd	_the_clock+1
	addd	#1; addhi3,3
	std	_the_clock+1
	rts
