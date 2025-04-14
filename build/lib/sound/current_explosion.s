;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
	.module	current_explosion.c
	.globl	_current_explosion
	.area	.data
_current_explosion:
	.word	_explosion_off
