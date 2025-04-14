;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
	.module	cartridge.c
	.globl	_game_header
	.area	.cartridge
_game_header:
	.byte	103,32,71,67,69,32,50,48
	.byte	50,53,-128
	.word	_Vec_Music_1
	.byte	-8
	.byte	80
	.byte	40
	.byte	-90
	.byte	68,79,68,71,69,32,67,72
	.byte	65,76,76,69,78,71,69,-128
	.byte	0
;----- asm -----
	. = . - 1
	
;--- end asm ---
	.globl	_end_of_cartridge_header
_end_of_cartridge_header:
	.byte	0
