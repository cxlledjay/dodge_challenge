                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	clock.c
                              6 	.area	.bss
                              7 	.globl	_clk_frames
   C880                       8 _clk_frames:	.blkb	1
                              9 	.globl	_clk_seconds
   C881                      10 _clk_seconds:	.blkb	2
                             11 	.area	.text
                             12 	.globl	_clk_init
   0060                      13 _clk_init:
   0060 7F C8 80      [ 7]   14 	clr	_clk_frames
   0063 CC 00 00      [ 3]   15 	ldd	#0
   0066 FD C8 81      [ 6]   16 	std	_clk_seconds
   0069 39            [ 5]   17 	rts
                             18 	.globl	_clk_update
   006A                      19 _clk_update:
   006A F6 C8 80      [ 5]   20 	ldb	_clk_frames
   006D C1 F0         [ 2]   21 	cmpb	#-16	;cmpqi:
   006F 22 11         [ 3]   22 	bhi	L10
   0071 C1 50         [ 2]   23 	cmpb	#80	;cmpqi:
   0073 27 1B         [ 3]   24 	beq	L8
   0075 C1 A5         [ 2]   25 	cmpb	#-91	;cmpqi:
   0077 27 17         [ 3]   26 	beq	L8
   0079 F6 C8 80      [ 5]   27 	ldb	_clk_frames
   007C CB 05         [ 2]   28 	addb	#5
   007E F7 C8 80      [ 5]   29 	stb	_clk_frames
   0081 39            [ 5]   30 	rts
   0082                      31 L10:
   0082 7F C8 80      [ 7]   32 	clr	_clk_frames
   0085 7C C8 82      [ 7]   33 	inc	_clk_seconds+1
   0088 26 03         [ 3]   34 	bne	__IL35
   008A 7C C8 81      [ 7]   35 	inc	_clk_seconds
   008D                      36 	__IL35:
   008D 7E 07 24      [ 4]   37 	jmp	_score_update
   0090                      38 L8:
   0090 BD 07 24      [ 8]   39 	jsr	_score_update
   0093 F6 C8 80      [ 5]   40 	ldb	_clk_frames
   0096 CB 05         [ 2]   41 	addb	#5
   0098 F7 C8 80      [ 5]   42 	stb	_clk_frames
   009B 39            [ 5]   43 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Mon May  5 19:48:08 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L10                0022 R   |   3 L8                 0030 R
  3 __IL35             002D R   |   2 _clk_frames        0000 GR
  3 _clk_init          0000 GR  |   2 _clk_seconds       0001 GR
  3 _clk_update        000A GR  |     _score_update      **** GX

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Mon May  5 19:48:08 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    3   flags    0
   3 .text            size   3C   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

