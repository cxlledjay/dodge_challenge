;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
	.module	main.c
	.area	.text
	.globl	_main
_main:
L2:
	jsr	_temp_draw
	bra	L2
