;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	clock.c
	.area	.bss
	.globl	_clk_frames
_clk_frames:	.blkb	1
	.area	.text
	.globl	_clk_init
_clk_init:
	clr	_clk_frames
	rts
	.globl	_clk_update
_clk_update:
	ldb	_clk_frames
	cmpb	#-16	;cmpqi:
	bhi	L8
	addb	#5
	stb	_clk_frames
	rts
L8:
	clr	_clk_frames
	rts
