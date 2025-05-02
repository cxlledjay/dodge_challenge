                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
                              5 	.module	memory_map.c
                              6 ;----- asm -----
                              7 	.bank rom(BASE=0x0000,SIZE=0x8000,FSFX=_rom)
                              8 	.area .cartridge		(BANK=rom)
                              9 	.area .boot			(BANK=rom)
                             10 	.area .text  			(BANK=rom)
                             11 	.area .text.hot		(BANK=rom)
                             12 	.area .text.unlikely	(BANK=rom)
                             13 	.area .text.last		(BANK=rom)
                             14 	
                             15 	.bank ram(BASE=0xc880,SIZE=0x036b,FSFX=_ram)
                             16 	.area .data            (BANK=ram)
                             17 	.area .bss             (BANK=ram)
                             18 	
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri May  2 16:45:27 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Fri May  2 16:45:27 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
[_DSEG]
   1 _DATA            size    0   flags C0C0
[rom]
   2 .cartridge       size    0   flags 8080
   3 .boot            size    0   flags 8080
   4 .text            size    0   flags 8080
   5 .text.hot        size    0   flags 8080
   6 .text.unlikely   size    0   flags 8080
   7 .text.last       size    0   flags 8080
[ram]
   8 .data            size    0   flags 8080
   9 .bss             size    0   flags 8080

