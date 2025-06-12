                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	map.c
                              6 	.area	.bss
                              7 	.globl	_the_map
   C8A7                       8 _the_map:	.blkb	3
                              9 	.area	.text
                             10 	.globl	_dummy_tick
   02D1                      11 _dummy_tick:
   02D1 39            [ 5]   12 	rts
                             13 	.globl	_map_init
   02D2                      14 _map_init:
   02D2 8E 02 D1      [ 3]   15 	ldx	#_dummy_tick
   02D5 BF C8 A8      [ 6]   16 	stx	_the_map+1
   02D8 7F C8 A7      [ 7]   17 	clr	_the_map
   02DB 39            [ 5]   18 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Thu Jun 12 20:59:45 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 _dummy_tick        0000 GR  |   3 _map_init          0001 GR
  2 _the_map           0000 GR

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Thu Jun 12 20:59:45 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    3   flags    0
   3 .text            size    B   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

