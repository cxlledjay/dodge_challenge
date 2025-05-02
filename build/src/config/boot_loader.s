;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	boot_loader.c
	.area	.boot
	.globl	_boot
_boot:
;----- asm -----
; 21 "source\config\boot_loader.c" 1
	_crt0:							
	_crt0_data:					
		ldx		#l_.data			
		beq		_crt0_data_done		
		ldu		#a_.text			
		leau	l_.text,u			
		leau	l_.text.hot,u		
		leau	l_.text.unlikely,u	
		ldy		#a_.data			
	_crt0_data_copy:				
		lda		,u+					
		sta		,y+					
		leax	-1,x				
		bne		_crt0_data_copy		
	_crt0_data_done:				
	_crt0_bss:						
		ldx		#l_.bss				
		beq		_crt0_bss_done		
		ldy		#a_.bss				
	_crt0_bss_zero:				
		clr		,y+					
		leax	-1,x				
		bne		_crt0_bss_zero		
	_crt0_bss_done:				
	
;--- end asm ---
	jsr	_main
	tstb
	beq	L2
	ldd	#0
	std	_Vec_Cold_Flag
L2:
	jmp	___Reset
