;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	memory_map.c
;----- asm -----
	.bank rom(BASE=0x0000,SIZE=0x8000,FSFX=_rom)
	.area .cartridge		(BANK=rom)
	.area .boot			(BANK=rom)
	.area .text  			(BANK=rom)
	.area .text.hot		(BANK=rom)
	.area .text.unlikely	(BANK=rom)
	.area .text.last		(BANK=rom)
	
	.bank ram(BASE=0xc880,SIZE=0x036b,FSFX=_ram)
	.area .data            (BANK=ram)
	.area .bss             (BANK=ram)
	
