;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
	.module	music_off.c
	.globl	_music_off
	.area	.text
_music_off:
	.word	_Vec_ADSR_FADE4
	.word	_Vec_TWANG_VIBEHL
	.byte	-128
	.byte	-128
	.byte	0
	.byte	-128
