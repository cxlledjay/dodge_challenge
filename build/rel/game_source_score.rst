                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	score.c
                              6 	.area	.bss
                              7 	.globl	_score
   C8A1                       8 _score:	.blkb	5
                              9 	.area	.text
                             10 	.globl	_score_init
   0757                      11 _score_init:
   0757 7F C8 A1      [ 7]   12 	clr	_score
   075A 7F C8 A2      [ 7]   13 	clr	_score+1
   075D 7F C8 A3      [ 7]   14 	clr	_score+2
   0760 7F C8 A4      [ 7]   15 	clr	_score+3
   0763 7F C8 A5      [ 7]   16 	clr	_score+4
   0766 39            [ 5]   17 	rts
                             18 	.globl	_local_lu_score_addition
   0767                      19 _local_lu_score_addition:
   0767 01                   20 	.byte	1
   0768 02                   21 	.byte	2
   0769 03                   22 	.byte	3
   076A 04                   23 	.byte	4
   076B 05                   24 	.byte	5
   076C 06                   25 	.byte	6
   076D 07                   26 	.byte	7
                             27 	.globl	_score_update
   076E                      28 _score_update:
   076E 32 76         [ 5]   29 	leas	-10,s
   0770 F6 C8 9E      [ 5]   30 	ldb	_lvl_speed
   0773 4F            [ 2]   31 	clra		;zero_extendqihi: R:b -> R:d
   0774 1F 01         [ 6]   32 	tfr	d,x
   0776 E6 89 07 67   [ 8]   33 	ldb	_local_lu_score_addition,x
   077A FB C8 A1      [ 5]   34 	addb	_score
   077D E7 66         [ 5]   35 	stb	6,s
   077F C1 09         [ 2]   36 	cmpb	#9	;cmpqi:
   0781 10 2F 00 C0   [ 6]   37 	lble	L10
   0785 E6 66         [ 5]   38 	ldb	6,s
   0787 86 67         [ 2]   39 	lda	#103	;mulqihi3
   0789 3D            [11]   40 	mul
   078A ED E4         [ 5]   41 	std	,s
   078C 1F 89         [ 6]   42 	tfr	a,b
   078E 4F            [ 2]   43 	clra		;zero_extendqihi: R:b -> R:d
   078F 57            [ 2]   44 	asrb
   0790 57            [ 2]   45 	asrb
   0791 E7 65         [ 5]   46 	stb	5,s
   0793 E6 66         [ 5]   47 	ldb	6,s
   0795 59            [ 2]   48 	rolb
   0796 59            [ 2]   49 	rolb
   0797 C4 01         [ 2]   50 	andb	#1
   0799 50            [ 2]   51 	negb
   079A E7 62         [ 5]   52 	stb	2,s
   079C E6 65         [ 5]   53 	ldb	5,s
   079E E0 62         [ 5]   54 	subb	2,s
   07A0 E7 62         [ 5]   55 	stb	2,s
   07A2 FB C8 A2      [ 5]   56 	addb	_score+1
   07A5 E7 67         [ 5]   57 	stb	7,s
   07A7 E6 62         [ 5]   58 	ldb	2,s
   07A9 86 0A         [ 2]   59 	lda	#10	;mulqihi3
   07AB 3D            [11]   60 	mul
   07AC 1F 01         [ 6]   61 	tfr	d,x
   07AE 1F 10         [ 6]   62 	tfr	x,d	;movlsbqihi: R:x -> R:b
   07B0 E0 66         [ 5]   63 	subb	6,s
   07B2 50            [ 2]   64 	negb
   07B3 F7 C8 A1      [ 5]   65 	stb	_score
   07B6 E6 67         [ 5]   66 	ldb	7,s
   07B8 C1 09         [ 2]   67 	cmpb	#9	;cmpqi:
   07BA 10 2F 00 81   [ 6]   68 	lble	L11
   07BE E6 67         [ 5]   69 	ldb	7,s
   07C0 86 67         [ 2]   70 	lda	#103	;mulqihi3
   07C2 3D            [11]   71 	mul
   07C3 ED E4         [ 5]   72 	std	,s
   07C5 1F 89         [ 6]   73 	tfr	a,b
   07C7 4F            [ 2]   74 	clra		;zero_extendqihi: R:b -> R:d
   07C8 57            [ 2]   75 	asrb
   07C9 57            [ 2]   76 	asrb
   07CA E7 64         [ 5]   77 	stb	4,s
   07CC E6 67         [ 5]   78 	ldb	7,s
   07CE 59            [ 2]   79 	rolb
   07CF 59            [ 2]   80 	rolb
   07D0 C4 01         [ 2]   81 	andb	#1
   07D2 50            [ 2]   82 	negb
   07D3 E7 E4         [ 4]   83 	stb	,s
   07D5 E6 64         [ 5]   84 	ldb	4,s
   07D7 E0 E4         [ 4]   85 	subb	,s
   07D9 E7 E4         [ 4]   86 	stb	,s
   07DB FB C8 A3      [ 5]   87 	addb	_score+2
   07DE E7 68         [ 5]   88 	stb	8,s
   07E0 E6 E4         [ 4]   89 	ldb	,s
   07E2 86 0A         [ 2]   90 	lda	#10	;mulqihi3
   07E4 3D            [11]   91 	mul
   07E5 1F 01         [ 6]   92 	tfr	d,x
   07E7 1F 10         [ 6]   93 	tfr	x,d	;movlsbqihi: R:x -> R:b
   07E9 E0 67         [ 5]   94 	subb	7,s
   07EB 50            [ 2]   95 	negb
   07EC F7 C8 A2      [ 5]   96 	stb	_score+1
   07EF E6 68         [ 5]   97 	ldb	8,s
   07F1 C1 09         [ 2]   98 	cmpb	#9	;cmpqi:
   07F3 2F 56         [ 3]   99 	ble	L12
   07F5 E6 68         [ 5]  100 	ldb	8,s
   07F7 86 67         [ 2]  101 	lda	#103	;mulqihi3
   07F9 3D            [11]  102 	mul
   07FA ED E4         [ 5]  103 	std	,s
   07FC 1F 89         [ 6]  104 	tfr	a,b
   07FE 4F            [ 2]  105 	clra		;zero_extendqihi: R:b -> R:d
   07FF 57            [ 2]  106 	asrb
   0800 57            [ 2]  107 	asrb
   0801 E7 E4         [ 4]  108 	stb	,s
   0803 E6 68         [ 5]  109 	ldb	8,s
   0805 59            [ 2]  110 	rolb
   0806 59            [ 2]  111 	rolb
   0807 C4 01         [ 2]  112 	andb	#1
   0809 50            [ 2]  113 	negb
   080A E7 69         [ 5]  114 	stb	9,s
   080C E6 E4         [ 4]  115 	ldb	,s
   080E E0 69         [ 5]  116 	subb	9,s
   0810 FB C8 A4      [ 5]  117 	addb	_score+3
   0813 E7 69         [ 5]  118 	stb	9,s
   0815 86 67         [ 2]  119 	lda	#103	;mulqihi3
   0817 3D            [11]  120 	mul
   0818 ED E4         [ 5]  121 	std	,s
   081A 1F 89         [ 6]  122 	tfr	a,b
   081C 4F            [ 2]  123 	clra		;zero_extendqihi: R:b -> R:d
   081D 57            [ 2]  124 	asrb
   081E 57            [ 2]  125 	asrb
   081F E7 63         [ 5]  126 	stb	3,s
   0821 E6 69         [ 5]  127 	ldb	9,s
   0823 59            [ 2]  128 	rolb
   0824 59            [ 2]  129 	rolb
   0825 C4 01         [ 2]  130 	andb	#1
   0827 50            [ 2]  131 	negb
   0828 E0 63         [ 5]  132 	subb	3,s
   082A 50            [ 2]  133 	negb
   082B 86 0A         [ 2]  134 	lda	#10	;mulqihi3
   082D 3D            [11]  135 	mul
                            136 		;movlsbqihi: D->B
   082E E0 69         [ 5]  137 	subb	9,s
   0830 50            [ 2]  138 	negb
   0831 F7 C8 A3      [ 5]  139 	stb	_score+2
   0834 E6 69         [ 5]  140 	ldb	9,s
   0836 C1 09         [ 2]  141 	cmpb	#9	;cmpqi:
   0838 2E 08         [ 3]  142 	bgt	L8
   083A F7 C8 A4      [ 5]  143 	stb	_score+3
   083D 20 03         [ 3]  144 	bra	L8
   083F                     145 L11:
   083F F7 C8 A2      [ 5]  146 	stb	_score+1
   0842                     147 L8:
   0842 32 6A         [ 5]  148 	leas	10,s
   0844 39            [ 5]  149 	rts
   0845                     150 L10:
   0845 F7 C8 A1      [ 5]  151 	stb	_score
   0848 32 6A         [ 5]  152 	leas	10,s
   084A 39            [ 5]  153 	rts
   084B                     154 L12:
   084B F7 C8 A3      [ 5]  155 	stb	_score+2
   084E 32 6A         [ 5]  156 	leas	10,s
   0850 39            [ 5]  157 	rts
                            158 	.globl	_local_lu_speed_digit_1
   0851                     159 _local_lu_speed_digit_1:
   0851 01                  160 	.byte	1
   0852 01                  161 	.byte	1
   0853 02                  162 	.byte	2
   0854 02                  163 	.byte	2
   0855 03                  164 	.byte	3
   0856 03                  165 	.byte	3
   0857 04                  166 	.byte	4
                            167 	.globl	_local_lu_speed_digit_2
   0858                     168 _local_lu_speed_digit_2:
   0858 00                  169 	.byte	0
   0859 05                  170 	.byte	5
   085A 00                  171 	.byte	0
   085B 05                  172 	.byte	5
   085C 00                  173 	.byte	0
   085D 05                  174 	.byte	5
   085E 00                  175 	.byte	0
                            176 	.globl	_score_draw
   085F                     177 _score_draw:
   085F 32 7E         [ 5]  178 	leas	-2,s
   0861 BD F2 A5      [ 8]  179 	jsr	___Intensity_5F
   0864 BD F3 54      [ 8]  180 	jsr	___Reset0Ref
   0867 C6 7F         [ 2]  181 	ldb	#127
   0869 D7 04         [ 4]  182 	stb	*_dp_VIA_t1_cnt_lo
   086B C6 6E         [ 2]  183 	ldb	#110
   086D E7 E2         [ 6]  184 	stb	,-s
   086F CB 2E         [ 2]  185 	addb	#46
   0871 BD 09 80      [ 8]  186 	jsr	__Moveto_d
   0874 C6 09         [ 2]  187 	ldb	#9
   0876 D7 04         [ 4]  188 	stb	*_dp_VIA_t1_cnt_lo
   0878 F6 C8 A4      [ 5]  189 	ldb	_score+3
   087B 1D            [ 2]  190 	sex		;extendqihi2: R:b -> R:d
   087C 58            [ 2]  191 	aslb
   087D 49            [ 2]  192 	rola
   087E 1F 01         [ 6]  193 	tfr	d,x
   0880 AE 89 02 28   [ 9]  194 	ldx	_vl_digits,x
   0884 BD F4 10      [ 8]  195 	jsr	___Draw_VLp
   0887 6F E2         [ 8]  196 	clr	,-s
   0889 C6 7F         [ 2]  197 	ldb	#127
   088B BD 09 80      [ 8]  198 	jsr	__Moveto_d
   088E F6 C8 A3      [ 5]  199 	ldb	_score+2
   0891 1D            [ 2]  200 	sex		;extendqihi2: R:b -> R:d
   0892 58            [ 2]  201 	aslb
   0893 49            [ 2]  202 	rola
   0894 1F 01         [ 6]  203 	tfr	d,x
   0896 AE 89 02 28   [ 9]  204 	ldx	_vl_digits,x
   089A BD F4 10      [ 8]  205 	jsr	___Draw_VLp
   089D 6F E2         [ 8]  206 	clr	,-s
   089F C6 7F         [ 2]  207 	ldb	#127
   08A1 BD 09 80      [ 8]  208 	jsr	__Moveto_d
   08A4 F6 C8 A2      [ 5]  209 	ldb	_score+1
   08A7 1D            [ 2]  210 	sex		;extendqihi2: R:b -> R:d
   08A8 58            [ 2]  211 	aslb
   08A9 49            [ 2]  212 	rola
   08AA 1F 01         [ 6]  213 	tfr	d,x
   08AC AE 89 02 28   [ 9]  214 	ldx	_vl_digits,x
   08B0 BD F4 10      [ 8]  215 	jsr	___Draw_VLp
   08B3 6F E2         [ 8]  216 	clr	,-s
   08B5 C6 7F         [ 2]  217 	ldb	#127
   08B7 BD 09 80      [ 8]  218 	jsr	__Moveto_d
   08BA F6 C8 A1      [ 5]  219 	ldb	_score
   08BD 1D            [ 2]  220 	sex		;extendqihi2: R:b -> R:d
   08BE 58            [ 2]  221 	aslb
   08BF 49            [ 2]  222 	rola
   08C0 1F 01         [ 6]  223 	tfr	d,x
   08C2 AE 89 02 28   [ 9]  224 	ldx	_vl_digits,x
   08C6 BD F4 10      [ 8]  225 	jsr	___Draw_VLp
   08C9 6F E2         [ 8]  226 	clr	,-s
   08CB C6 7F         [ 2]  227 	ldb	#127
   08CD BD 09 80      [ 8]  228 	jsr	__Moveto_d
   08D0 BE 02 28      [ 6]  229 	ldx	_vl_digits
   08D3 BD F4 10      [ 8]  230 	jsr	___Draw_VLp
   08D6 C6 42         [ 2]  231 	ldb	#66
   08D8 D7 04         [ 4]  232 	stb	*_dp_VIA_t1_cnt_lo
   08DA C6 D4         [ 2]  233 	ldb	#-44
   08DC E7 E2         [ 6]  234 	stb	,-s
   08DE C6 81         [ 2]  235 	ldb	#-127
   08E0 BD 09 80      [ 8]  236 	jsr	__Moveto_d
   08E3 C6 06         [ 2]  237 	ldb	#6
   08E5 D7 04         [ 4]  238 	stb	*_dp_VIA_t1_cnt_lo
   08E7 8E 02 3C      [ 3]  239 	ldx	#_vl_speed_display
   08EA BD F4 10      [ 8]  240 	jsr	___Draw_VLp
   08ED C6 06         [ 2]  241 	ldb	#6
   08EF D7 04         [ 4]  242 	stb	*_dp_VIA_t1_cnt_lo
   08F1 F6 C8 9E      [ 5]  243 	ldb	_lvl_speed
   08F4 4F            [ 2]  244 	clra		;zero_extendqihi: R:b -> R:d
   08F5 1F 01         [ 6]  245 	tfr	d,x
   08F7 E6 89 08 51   [ 8]  246 	ldb	_local_lu_speed_digit_1,x
   08FB 1D            [ 2]  247 	sex		;extendqihi2: R:b -> R:d
   08FC 58            [ 2]  248 	aslb
   08FD 49            [ 2]  249 	rola
   08FE 1F 01         [ 6]  250 	tfr	d,x
   0900 AE 89 02 28   [ 9]  251 	ldx	_vl_digits,x
   0904 BD F4 10      [ 8]  252 	jsr	___Draw_VLp
   0907 C6 8A         [ 2]  253 	ldb	#-118
   0909 E7 E2         [ 6]  254 	stb	,-s
   090B C6 2A         [ 2]  255 	ldb	#42
   090D BD 09 80      [ 8]  256 	jsr	__Moveto_d
   0910 BD F2 C5      [ 8]  257 	jsr	___Dot_here
   0913 C6 76         [ 2]  258 	ldb	#118
   0915 E7 E2         [ 6]  259 	stb	,-s
   0917 C6 67         [ 2]  260 	ldb	#103
   0919 BD 09 80      [ 8]  261 	jsr	__Moveto_d
   091C F6 C8 9E      [ 5]  262 	ldb	_lvl_speed
   091F 4F            [ 2]  263 	clra		;zero_extendqihi: R:b -> R:d
   0920 1F 01         [ 6]  264 	tfr	d,x
   0922 E6 89 08 58   [ 8]  265 	ldb	_local_lu_speed_digit_2,x
   0926 1D            [ 2]  266 	sex		;extendqihi2: R:b -> R:d
   0927 ED 68         [ 6]  267 	std	8,s
   0929 58            [ 2]  268 	aslb
   092A 49            [ 2]  269 	rola
   092B 1F 01         [ 6]  270 	tfr	d,x
   092D AE 89 02 28   [ 9]  271 	ldx	_vl_digits,x
   0931 32 6A         [ 5]  272 	leas	10,s
   0933 7E F4 10      [ 4]  273 	jmp	___Draw_VLp
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Wed Jun 11 20:47:46 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L10                00EE R   |   3 L11                00E8 R
  3 L12                00F4 R   |   3 L8                 00EB R
    __Moveto_d         **** GX  |     ___Dot_here        **** GX
    ___Draw_VLp        **** GX  |     ___Intensity_5     **** GX
    ___Reset0Ref       **** GX  |     _dp_VIA_t1_cnt     **** GX
  3 _local_lu_scor     0010 GR  |   3 _local_lu_spee     00FA GR
  3 _local_lu_spee     0101 GR  |     _lvl_speed         **** GX
  2 _score             0000 GR  |   3 _score_draw        0108 GR
  3 _score_init        0000 GR  |   3 _score_update      0017 GR
    _vl_digits         **** GX  |     _vl_speed_disp     **** GX

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Wed Jun 11 20:47:46 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    5   flags    0
   3 .text            size  1DF   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

