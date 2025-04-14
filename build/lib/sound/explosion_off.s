;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
	.module	explosion_off.c
	.globl	_explosion_off
	.area	.text
_explosion_off:
	.byte	63
	.byte	0
	.byte	1
	.byte	-128
