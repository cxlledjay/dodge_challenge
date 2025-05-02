                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	cartridge.c
                              6 	.globl	_game_header
                              7 	.area	.cartridge
   0000                       8 _game_header:
   0000 67 20 47 43 45 20     9 	.byte	103,32,71,67,69,32,50,48
        32 30
   0008 32 35 80             10 	.byte	50,53,-128
   000B FD 0D                11 	.word	_Vec_Music_1
   000D F8                   12 	.byte	-8
   000E 50                   13 	.byte	80
   000F 28                   14 	.byte	40
   0010 A6                   15 	.byte	-90
   0011 44 4F 44 47 45 20    16 	.byte	68,79,68,71,69,32,67,72
        43 48
   0019 41 4C 4C 45 4E 47    17 	.byte	65,76,76,69,78,71,69,-128
        45 80
   0021 00                   18 	.byte	0
                             19 ;----- asm -----
                     0021    20 	. = . - 1
                             21 	
                             22 ;--- end asm ---
                             23 	.globl	_end_of_cartridge_header
   0021                      24 _end_of_cartridge_header:
   0021 00                   25 	.byte	0
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri May  2 23:22:15 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
    _Vec_Music_1       **** GX  |   2 _end_of_cartri     0021 GR
  2 _game_header       0000 GR

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Fri May  2 23:22:15 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .cartridge       size   22   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

