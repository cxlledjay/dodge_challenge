                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	main.c
                              6 	.area	.text
                              7 	.globl	_main
   0A55                       8 _main:
   0A55 7F C8 A4      [ 7]    9 	clr	_the_game+2
   0A58 CC 00 00      [ 3]   10 	ldd	#0
   0A5B FD C8 A2      [ 6]   11 	std	_the_game
   0A5E 8E 00 DD      [ 3]   12 	ldx	#_game_init
   0A61 BF C8 A5      [ 6]   13 	stx	_the_game+3
   0A64                      14 L2:
   0A64 AD 9F C8 A5   [12]   15 	jsr	[_the_game+3]
   0A68 20 FA         [ 3]   16 	bra	L2
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri Jun 13 20:36:15 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  2 L2                 000F R   |     _game_init         **** GX
  2 _main              0000 GR  |     _the_game          **** GX

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Fri Jun 13 20:36:15 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .text            size   15   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

