                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	score.c
                              6 	.area	.bss
                              7 	.globl	_score
   C886                       8 _score:	.blkb	2
                              9 	.area	.text
                             10 	.globl	_score_init
   06F1                      11 _score_init:
   06F1 CC 00 00      [ 3]   12 	ldd	#0
   06F4 FD C8 86      [ 6]   13 	std	_score
   06F7 39            [ 5]   14 	rts
                             15 	.globl	_score_update
   06F8                      16 _score_update:
   06F8 7C C8 87      [ 7]   17 	inc	_score+1
   06FB 26 03         [ 3]   18 	bne	__IL15
   06FD 7C C8 86      [ 7]   19 	inc	_score
   0700                      20 	__IL15:
   0700 39            [ 5]   21 	rts
                             22 	.globl	_score_draw
   0701                      23 _score_draw:
   0701 34 20         [ 6]   24 	pshs	y
   0703 BD F2 A5      [ 8]   25 	jsr	___Intensity_5F
   0706 BD F3 54      [ 8]   26 	jsr	___Reset0Ref
   0709 C6 7F         [ 2]   27 	ldb	#127
   070B D7 04         [ 4]   28 	stb	*_dp_VIA_t1_cnt_lo
   070D C6 6E         [ 2]   29 	ldb	#110
   070F E7 E2         [ 6]   30 	stb	,-s
   0711 CB 2E         [ 2]   31 	addb	#46
   0713 BD 07 DD      [ 8]   32 	jsr	__Moveto_d
   0716 C6 09         [ 2]   33 	ldb	#9
   0718 D7 04         [ 4]   34 	stb	*_dp_VIA_t1_cnt_lo
   071A 10 BE 01 C5   [ 7]   35 	ldy	_vl_digits
   071E 30 A4         [ 4]   36 	leax	,y
   0720 BD F4 10      [ 8]   37 	jsr	___Draw_VLp
   0723 6F E2         [ 8]   38 	clr	,-s
   0725 C6 7F         [ 2]   39 	ldb	#127
   0727 BD 07 DD      [ 8]   40 	jsr	__Moveto_d
   072A 30 A4         [ 4]   41 	leax	,y
   072C BD F4 10      [ 8]   42 	jsr	___Draw_VLp
   072F 6F E2         [ 8]   43 	clr	,-s
   0731 C6 7F         [ 2]   44 	ldb	#127
   0733 BD 07 DD      [ 8]   45 	jsr	__Moveto_d
   0736 30 A4         [ 4]   46 	leax	,y
   0738 BD F4 10      [ 8]   47 	jsr	___Draw_VLp
   073B 6F E2         [ 8]   48 	clr	,-s
   073D C6 7F         [ 2]   49 	ldb	#127
   073F BD 07 DD      [ 8]   50 	jsr	__Moveto_d
   0742 30 A4         [ 4]   51 	leax	,y
   0744 BD F4 10      [ 8]   52 	jsr	___Draw_VLp
   0747 6F E2         [ 8]   53 	clr	,-s
   0749 C6 7F         [ 2]   54 	ldb	#127
   074B BD 07 DD      [ 8]   55 	jsr	__Moveto_d
   074E 30 A4         [ 4]   56 	leax	,y
   0750 BD F4 10      [ 8]   57 	jsr	___Draw_VLp
   0753 C6 64         [ 2]   58 	ldb	#100
   0755 D7 04         [ 4]   59 	stb	*_dp_VIA_t1_cnt_lo
   0757 C6 D6         [ 2]   60 	ldb	#-42
   0759 E7 E2         [ 6]   61 	stb	,-s
   075B C6 81         [ 2]   62 	ldb	#-127
   075D BD 07 DD      [ 8]   63 	jsr	__Moveto_d
   0760 C6 0F         [ 2]   64 	ldb	#15
   0762 D7 04         [ 4]   65 	stb	*_dp_VIA_t1_cnt_lo
   0764 8E 01 D9      [ 3]   66 	ldx	#_vl_speed_display
   0767 BD F4 10      [ 8]   67 	jsr	___Draw_VLp
   076A C6 08         [ 2]   68 	ldb	#8
   076C D7 04         [ 4]   69 	stb	*_dp_VIA_t1_cnt_lo
   076E BE 01 C9      [ 6]   70 	ldx	_vl_digits+4
   0771 BD F4 10      [ 8]   71 	jsr	___Draw_VLp
   0774 C6 8A         [ 2]   72 	ldb	#-118
   0776 E7 E2         [ 6]   73 	stb	,-s
   0778 C6 18         [ 2]   74 	ldb	#24
   077A BD 07 DD      [ 8]   75 	jsr	__Moveto_d
   077D BD F2 C5      [ 8]   76 	jsr	___Dot_here
   0780 C6 76         [ 2]   77 	ldb	#118
   0782 E7 E2         [ 6]   78 	stb	,-s
   0784 C6 67         [ 2]   79 	ldb	#103
   0786 BD 07 DD      [ 8]   80 	jsr	__Moveto_d
   0789 32 68         [ 5]   81 	leas	8,s
   078B BE 01 CF      [ 6]   82 	ldx	_vl_digits+10
   078E 35 20         [ 6]   83 	puls	y
   0790 7E F4 10      [ 4]   84 	jmp	___Draw_VLp
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Mon May  5 18:50:34 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 __IL15             000F R   |     __Moveto_d         **** GX
    ___Dot_here        **** GX  |     ___Draw_VLp        **** GX
    ___Intensity_5     **** GX  |     ___Reset0Ref       **** GX
    _dp_VIA_t1_cnt     **** GX  |   2 _score             0000 GR
  3 _score_draw        0010 GR  |   3 _score_init        0000 GR
  3 _score_update      0007 GR  |     _vl_digits         **** GX
    _vl_speed_disp     **** GX

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Mon May  5 18:50:34 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    2   flags    0
   3 .text            size   A2   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

