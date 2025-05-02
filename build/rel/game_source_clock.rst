                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
                              5 	.module	clock.c
                              6 	.area	.bss
                              7 	.globl	_clk_frames
   C883                       8 _clk_frames:	.blkb	1
                              9 	.globl	_clk_seconds
   C884                      10 _clk_seconds:	.blkb	2
                             11 	.area	.text
                             12 	.globl	_clk_init
   0061                      13 _clk_init:
   0061 7F C8 83      [ 7]   14 	clr	_clk_frames
   0064 8E 00 00      [ 3]   15 	ldx	#0
   0067 BF C8 84      [ 6]   16 	stx	_clk_seconds
   006A 39            [ 5]   17 	rts
                             18 	.globl	_clk_update
   006B                      19 _clk_update:
   006B F6 C8 83      [ 5]   20 	ldb	_clk_frames
   006E C1 31         [ 2]   21 	cmpb	#49	;cmpqi:
   0070 26 0D         [ 3]   22 	bne	L4
   0072 7F C8 83      [ 7]   23 	clr	_clk_frames
   0075 BE C8 84      [ 6]   24 	ldx	_clk_seconds
   0078 30 01         [ 5]   25 	leax	1,x
   007A BF C8 84      [ 6]   26 	stx	_clk_seconds
   007D 20 07         [ 3]   27 	bra	L6
   007F                      28 L4:
   007F F6 C8 83      [ 5]   29 	ldb	_clk_frames
   0082 5C            [ 2]   30 	incb
   0083 F7 C8 83      [ 5]   31 	stb	_clk_frames
   0086                      32 L6:
   0086 39            [ 5]   33 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri May  2 18:56:42 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L4                 001E R   |   3 L6                 0025 R
  2 _clk_frames        0000 GR  |   3 _clk_init          0000 GR
  2 _clk_seconds       0001 GR  |   3 _clk_update        000A GR

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Fri May  2 18:56:42 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    3   flags    0
   3 .text            size   26   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

