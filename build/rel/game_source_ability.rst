                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	ability.c
                              6 	.area	.bss
                              7 	.globl	_the_ability
   C881                       8 _the_ability:	.blkb	4
                              9 	.area	.text
                             10 	.globl	_dummy_tick
   0060                      11 _dummy_tick:
   0060 39            [ 5]   12 	rts
                             13 	.globl	_ability_init
   0061                      14 _ability_init:
   0061 8E 00 60      [ 3]   15 	ldx	#_dummy_tick
   0064 BF C8 83      [ 6]   16 	stx	_the_ability+2
   0067 7F C8 82      [ 7]   17 	clr	_the_ability+1
   006A 7F C8 81      [ 7]   18 	clr	_the_ability
   006D 39            [ 5]   19 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Thu Jun 12 22:57:39 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 _ability_init      0001 GR  |   3 _dummy_tick        0000 GR
  2 _the_ability       0000 GR

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Thu Jun 12 22:57:39 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    4   flags    0
   3 .text            size    E   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

