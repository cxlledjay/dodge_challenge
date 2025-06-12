                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	clock.c
                              6 	.area	.bss
                              7 	.globl	_the_clock
   C885                       8 _the_clock:	.blkb	3
                              9 	.area	.text
                             10 	.globl	_clock_init
   006E                      11 _clock_init:
   006E CC 00 00      [ 3]   12 	ldd	#0
   0071 FD C8 86      [ 6]   13 	std	_the_clock+1
   0074 C6 31         [ 2]   14 	ldb	#49
   0076 F7 C8 85      [ 5]   15 	stb	_the_clock
   0079 39            [ 5]   16 	rts
                             17 	.globl	_clock_tick
   007A                      18 _clock_tick:
   007A F6 C8 85      [ 5]   19 	ldb	_the_clock
   007D 27 05         [ 3]   20 	beq	L8
   007F 5A            [ 2]   21 	decb
   0080 F7 C8 85      [ 5]   22 	stb	_the_clock
   0083 39            [ 5]   23 	rts
   0084                      24 L8:
   0084 C6 31         [ 2]   25 	ldb	#49
   0086 F7 C8 85      [ 5]   26 	stb	_the_clock
   0089 FC C8 86      [ 6]   27 	ldd	_the_clock+1
   008C C3 00 01      [ 4]   28 	addd	#1; addhi3,3
   008F FD C8 86      [ 6]   29 	std	_the_clock+1
   0092 39            [ 5]   30 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Thu Jun 12 23:11:43 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L8                 0016 R   |   3 _clock_init        0000 GR
  3 _clock_tick        000C GR  |   2 _the_clock         0000 GR

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Thu Jun 12 23:11:43 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    3   flags    0
   3 .text            size   25   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

