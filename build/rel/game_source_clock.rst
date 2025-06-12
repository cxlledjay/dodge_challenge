                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	clock.c
                              6 	.area	.bss
                              7 	.globl	_clk_frames
   C884                       8 _clk_frames:	.blkb	1
                              9 	.globl	_clk_seconds
   C885                      10 _clk_seconds:	.blkb	2
                             11 	.area	.text
                             12 	.globl	_clk_init
   006E                      13 _clk_init:
   006E 7F C8 84      [ 7]   14 	clr	_clk_frames
   0071 CC 00 00      [ 3]   15 	ldd	#0
   0074 FD C8 85      [ 6]   16 	std	_clk_seconds
   0077 39            [ 5]   17 	rts
                             18 	.globl	_clk_update
   0078                      19 _clk_update:
   0078 F6 C8 84      [ 5]   20 	ldb	_clk_frames
   007B C1 F0         [ 2]   21 	cmpb	#-16	;cmpqi:
   007D 22 06         [ 3]   22 	bhi	L8
   007F CB 05         [ 2]   23 	addb	#5
   0081 F7 C8 84      [ 5]   24 	stb	_clk_frames
   0084 39            [ 5]   25 	rts
   0085                      26 L8:
   0085 7F C8 84      [ 7]   27 	clr	_clk_frames
   0088 7C C8 86      [ 7]   28 	inc	_clk_seconds+1
   008B 26 03         [ 3]   29 	bne	__IL28
   008D 7C C8 85      [ 7]   30 	inc	_clk_seconds
   0090                      31 	__IL28:
   0090 39            [ 5]   32 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Thu Jun 12 18:40:10 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L8                 0017 R   |   3 __IL28             0022 R
  2 _clk_frames        0000 GR  |   3 _clk_init          0000 GR
  2 _clk_seconds       0001 GR  |   3 _clk_update        000A GR

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Thu Jun 12 18:40:10 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    3   flags    0
   3 .text            size   23   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

