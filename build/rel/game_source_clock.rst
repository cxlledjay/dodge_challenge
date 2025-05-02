                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	clock.c
                              6 	.area	.bss
                              7 	.globl	_clk_frames
   C886                       8 _clk_frames:	.blkb	1
                              9 	.area	.text
                             10 	.globl	_clk_init
   0060                      11 _clk_init:
   0060 7F C8 86      [ 7]   12 	clr	_clk_frames
   0063 39            [ 5]   13 	rts
                             14 	.globl	_clk_update
   0064                      15 _clk_update:
   0064 F6 C8 86      [ 5]   16 	ldb	_clk_frames
   0067 C1 F0         [ 2]   17 	cmpb	#-16	;cmpqi:
   0069 22 06         [ 3]   18 	bhi	L8
   006B CB 05         [ 2]   19 	addb	#5
   006D F7 C8 86      [ 5]   20 	stb	_clk_frames
   0070 39            [ 5]   21 	rts
   0071                      22 L8:
   0071 7F C8 86      [ 7]   23 	clr	_clk_frames
   0074 39            [ 5]   24 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri May  2 23:22:15 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L8                 0011 R   |   2 _clk_frames        0000 GR
  3 _clk_init          0000 GR  |   3 _clk_update        0004 GR

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Fri May  2 23:22:15 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    1   flags    0
   3 .text            size   15   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

