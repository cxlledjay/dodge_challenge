                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	level.c
                              6 	.area	.bss
                              7 	.globl	_lvl_speed
   C883                       8 _lvl_speed:	.blkb	1
                              9 	.area	.text
                             10 	.globl	_lvl_init
   0204                      11 _lvl_init:
   0204 7F C8 83      [ 7]   12 	clr	_lvl_speed
   0207 39            [ 5]   13 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Mon May  5 18:50:34 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 _lvl_init          0000 GR  |   2 _lvl_speed         0000 GR

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Mon May  5 18:50:34 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    1   flags    0
   3 .text            size    4   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

