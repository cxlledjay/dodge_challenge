;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
	.module	stop_explosion.c
	.area	.text
	.globl	_stop_explosion
_stop_explosion:
	clr	_Vec_Expl_Timer
	clr	_Vec_Expl_Flag
	jsr	___Clear_Sound
	ldx	#_explosion_off
	stx	_current_explosion
	rts
