;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
	.module	level.c
	.area	.bss
	.globl	_lvl_speed
_lvl_speed:	.blkb	1
	.area	.text
	.globl	_lvl_init
_lvl_init:
	clr	_lvl_speed
	rts
