                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
                              5 	.module	clock.c
                              6 	.area	.bss
                              7 	.globl	_clk_frames
   C881                       8 _clk_frames:	.blkb	1
                              9 	.area	.text
                             10 	.globl	_clk_init
   0061                      11 _clk_init:
   0061 7F C8 81      [ 7]   12 	clr	_clk_frames
   0064 39            [ 5]   13 	rts
                             14 	.globl	_clk_update
   0065                      15 _clk_update:
   0065 F6 C8 81      [ 5]   16 	ldb	_clk_frames
   0068 C1 F0         [ 2]   17 	cmpb	#-16	;cmpqi:
   006A 23 05         [ 3]   18 	bls	L4
   006C 7F C8 81      [ 7]   19 	clr	_clk_frames
   006F 20 08         [ 3]   20 	bra	L6
   0071                      21 L4:
   0071 F6 C8 81      [ 5]   22 	ldb	_clk_frames
   0074 CB 05         [ 2]   23 	addb	#5
   0076 F7 C8 81      [ 5]   24 	stb	_clk_frames
   0079                      25 L6:
   0079 39            [ 5]   26 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri May  2 21:41:29 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L4                 0010 R   |   3 L6                 0018 R
  2 _clk_frames        0000 GR  |   3 _clk_init          0000 GR
  3 _clk_update        0004 GR

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Fri May  2 21:41:29 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    1   flags    0
   3 .text            size   19   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

