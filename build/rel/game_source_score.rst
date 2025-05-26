                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	score.c
                              6 	.area	.bss
                              7 	.globl	_score
   C886                       8 _score:	.blkb	5
                              9 	.area	.text
                             10 	.globl	_score_init
   070D                      11 _score_init:
   070D 7F C8 86      [ 7]   12 	clr	_score
   0710 7F C8 87      [ 7]   13 	clr	_score+1
   0713 7F C8 88      [ 7]   14 	clr	_score+2
   0716 7F C8 89      [ 7]   15 	clr	_score+3
   0719 7F C8 8A      [ 7]   16 	clr	_score+4
   071C 39            [ 5]   17 	rts
                             18 	.globl	_local_lu_score_addition
   071D                      19 _local_lu_score_addition:
   071D 01                   20 	.byte	1
   071E 02                   21 	.byte	2
   071F 03                   22 	.byte	3
   0720 04                   23 	.byte	4
   0721 05                   24 	.byte	5
   0722 06                   25 	.byte	6
   0723 07                   26 	.byte	7
                             27 	.globl	_score_update
   0724                      28 _score_update:
   0724 32 76         [ 5]   29 	leas	-10,s
   0726 F6 C8 83      [ 5]   30 	ldb	_lvl_speed
   0729 4F            [ 2]   31 	clra		;zero_extendqihi: R:b -> R:d
   072A 1F 01         [ 6]   32 	tfr	d,x
   072C E6 89 07 1D   [ 8]   33 	ldb	_local_lu_score_addition,x
   0730 FB C8 86      [ 5]   34 	addb	_score
   0733 E7 66         [ 5]   35 	stb	6,s
   0735 C1 09         [ 2]   36 	cmpb	#9	;cmpqi:
   0737 10 2F 00 C0   [ 6]   37 	lble	L10
   073B E6 66         [ 5]   38 	ldb	6,s
   073D 86 67         [ 2]   39 	lda	#103	;mulqihi3
   073F 3D            [11]   40 	mul
   0740 ED E4         [ 5]   41 	std	,s
   0742 1F 89         [ 6]   42 	tfr	a,b
   0744 4F            [ 2]   43 	clra		;zero_extendqihi: R:b -> R:d
   0745 57            [ 2]   44 	asrb
   0746 57            [ 2]   45 	asrb
   0747 E7 65         [ 5]   46 	stb	5,s
   0749 E6 66         [ 5]   47 	ldb	6,s
   074B 59            [ 2]   48 	rolb
   074C 59            [ 2]   49 	rolb
   074D C4 01         [ 2]   50 	andb	#1
   074F 50            [ 2]   51 	negb
   0750 E7 62         [ 5]   52 	stb	2,s
   0752 E6 65         [ 5]   53 	ldb	5,s
   0754 E0 62         [ 5]   54 	subb	2,s
   0756 E7 62         [ 5]   55 	stb	2,s
   0758 FB C8 87      [ 5]   56 	addb	_score+1
   075B E7 67         [ 5]   57 	stb	7,s
   075D E6 62         [ 5]   58 	ldb	2,s
   075F 86 0A         [ 2]   59 	lda	#10	;mulqihi3
   0761 3D            [11]   60 	mul
   0762 1F 01         [ 6]   61 	tfr	d,x
   0764 1F 10         [ 6]   62 	tfr	x,d	;movlsbqihi: R:x -> R:b
   0766 E0 66         [ 5]   63 	subb	6,s
   0768 50            [ 2]   64 	negb
   0769 F7 C8 86      [ 5]   65 	stb	_score
   076C E6 67         [ 5]   66 	ldb	7,s
   076E C1 09         [ 2]   67 	cmpb	#9	;cmpqi:
   0770 10 2F 00 81   [ 6]   68 	lble	L11
   0774 E6 67         [ 5]   69 	ldb	7,s
   0776 86 67         [ 2]   70 	lda	#103	;mulqihi3
   0778 3D            [11]   71 	mul
   0779 ED E4         [ 5]   72 	std	,s
   077B 1F 89         [ 6]   73 	tfr	a,b
   077D 4F            [ 2]   74 	clra		;zero_extendqihi: R:b -> R:d
   077E 57            [ 2]   75 	asrb
   077F 57            [ 2]   76 	asrb
   0780 E7 64         [ 5]   77 	stb	4,s
   0782 E6 67         [ 5]   78 	ldb	7,s
   0784 59            [ 2]   79 	rolb
   0785 59            [ 2]   80 	rolb
   0786 C4 01         [ 2]   81 	andb	#1
   0788 50            [ 2]   82 	negb
   0789 E7 E4         [ 4]   83 	stb	,s
   078B E6 64         [ 5]   84 	ldb	4,s
   078D E0 E4         [ 4]   85 	subb	,s
   078F E7 E4         [ 4]   86 	stb	,s
   0791 FB C8 88      [ 5]   87 	addb	_score+2
   0794 E7 68         [ 5]   88 	stb	8,s
   0796 E6 E4         [ 4]   89 	ldb	,s
   0798 86 0A         [ 2]   90 	lda	#10	;mulqihi3
   079A 3D            [11]   91 	mul
   079B 1F 01         [ 6]   92 	tfr	d,x
   079D 1F 10         [ 6]   93 	tfr	x,d	;movlsbqihi: R:x -> R:b
   079F E0 67         [ 5]   94 	subb	7,s
   07A1 50            [ 2]   95 	negb
   07A2 F7 C8 87      [ 5]   96 	stb	_score+1
   07A5 E6 68         [ 5]   97 	ldb	8,s
   07A7 C1 09         [ 2]   98 	cmpb	#9	;cmpqi:
   07A9 2F 56         [ 3]   99 	ble	L12
   07AB E6 68         [ 5]  100 	ldb	8,s
   07AD 86 67         [ 2]  101 	lda	#103	;mulqihi3
   07AF 3D            [11]  102 	mul
   07B0 ED E4         [ 5]  103 	std	,s
   07B2 1F 89         [ 6]  104 	tfr	a,b
   07B4 4F            [ 2]  105 	clra		;zero_extendqihi: R:b -> R:d
   07B5 57            [ 2]  106 	asrb
   07B6 57            [ 2]  107 	asrb
   07B7 E7 E4         [ 4]  108 	stb	,s
   07B9 E6 68         [ 5]  109 	ldb	8,s
   07BB 59            [ 2]  110 	rolb
   07BC 59            [ 2]  111 	rolb
   07BD C4 01         [ 2]  112 	andb	#1
   07BF 50            [ 2]  113 	negb
   07C0 E7 69         [ 5]  114 	stb	9,s
   07C2 E6 E4         [ 4]  115 	ldb	,s
   07C4 E0 69         [ 5]  116 	subb	9,s
   07C6 FB C8 89      [ 5]  117 	addb	_score+3
   07C9 E7 69         [ 5]  118 	stb	9,s
   07CB 86 67         [ 2]  119 	lda	#103	;mulqihi3
   07CD 3D            [11]  120 	mul
   07CE ED E4         [ 5]  121 	std	,s
   07D0 1F 89         [ 6]  122 	tfr	a,b
   07D2 4F            [ 2]  123 	clra		;zero_extendqihi: R:b -> R:d
   07D3 57            [ 2]  124 	asrb
   07D4 57            [ 2]  125 	asrb
   07D5 E7 63         [ 5]  126 	stb	3,s
   07D7 E6 69         [ 5]  127 	ldb	9,s
   07D9 59            [ 2]  128 	rolb
   07DA 59            [ 2]  129 	rolb
   07DB C4 01         [ 2]  130 	andb	#1
   07DD 50            [ 2]  131 	negb
   07DE E0 63         [ 5]  132 	subb	3,s
   07E0 50            [ 2]  133 	negb
   07E1 86 0A         [ 2]  134 	lda	#10	;mulqihi3
   07E3 3D            [11]  135 	mul
                            136 		;movlsbqihi: D->B
   07E4 E0 69         [ 5]  137 	subb	9,s
   07E6 50            [ 2]  138 	negb
   07E7 F7 C8 88      [ 5]  139 	stb	_score+2
   07EA E6 69         [ 5]  140 	ldb	9,s
   07EC C1 09         [ 2]  141 	cmpb	#9	;cmpqi:
   07EE 2E 08         [ 3]  142 	bgt	L8
   07F0 F7 C8 89      [ 5]  143 	stb	_score+3
   07F3 20 03         [ 3]  144 	bra	L8
   07F5                     145 L11:
   07F5 F7 C8 87      [ 5]  146 	stb	_score+1
   07F8                     147 L8:
   07F8 32 6A         [ 5]  148 	leas	10,s
   07FA 39            [ 5]  149 	rts
   07FB                     150 L10:
   07FB F7 C8 86      [ 5]  151 	stb	_score
   07FE 32 6A         [ 5]  152 	leas	10,s
   0800 39            [ 5]  153 	rts
   0801                     154 L12:
   0801 F7 C8 88      [ 5]  155 	stb	_score+2
   0804 32 6A         [ 5]  156 	leas	10,s
   0806 39            [ 5]  157 	rts
                            158 	.globl	_local_lu_speed_digit_1
   0807                     159 _local_lu_speed_digit_1:
   0807 01                  160 	.byte	1
   0808 01                  161 	.byte	1
   0809 02                  162 	.byte	2
   080A 02                  163 	.byte	2
   080B 03                  164 	.byte	3
   080C 03                  165 	.byte	3
   080D 04                  166 	.byte	4
                            167 	.globl	_local_lu_speed_digit_2
   080E                     168 _local_lu_speed_digit_2:
   080E 00                  169 	.byte	0
   080F 05                  170 	.byte	5
   0810 00                  171 	.byte	0
   0811 05                  172 	.byte	5
   0812 00                  173 	.byte	0
   0813 05                  174 	.byte	5
   0814 00                  175 	.byte	0
                            176 	.globl	_score_draw
   0815                     177 _score_draw:
   0815 32 7E         [ 5]  178 	leas	-2,s
   0817 BD F2 A5      [ 8]  179 	jsr	___Intensity_5F
   081A BD F3 54      [ 8]  180 	jsr	___Reset0Ref
   081D C6 7F         [ 2]  181 	ldb	#127
   081F D7 04         [ 4]  182 	stb	*_dp_VIA_t1_cnt_lo
   0821 C6 6E         [ 2]  183 	ldb	#110
   0823 E7 E2         [ 6]  184 	stb	,-s
   0825 CB 2E         [ 2]  185 	addb	#46
   0827 BD 09 36      [ 8]  186 	jsr	__Moveto_d
   082A C6 09         [ 2]  187 	ldb	#9
   082C D7 04         [ 4]  188 	stb	*_dp_VIA_t1_cnt_lo
   082E F6 C8 89      [ 5]  189 	ldb	_score+3
   0831 1D            [ 2]  190 	sex		;extendqihi2: R:b -> R:d
   0832 58            [ 2]  191 	aslb
   0833 49            [ 2]  192 	rola
   0834 1F 01         [ 6]  193 	tfr	d,x
   0836 AE 89 01 DE   [ 9]  194 	ldx	_vl_digits,x
   083A BD F4 10      [ 8]  195 	jsr	___Draw_VLp
   083D 6F E2         [ 8]  196 	clr	,-s
   083F C6 7F         [ 2]  197 	ldb	#127
   0841 BD 09 36      [ 8]  198 	jsr	__Moveto_d
   0844 F6 C8 88      [ 5]  199 	ldb	_score+2
   0847 1D            [ 2]  200 	sex		;extendqihi2: R:b -> R:d
   0848 58            [ 2]  201 	aslb
   0849 49            [ 2]  202 	rola
   084A 1F 01         [ 6]  203 	tfr	d,x
   084C AE 89 01 DE   [ 9]  204 	ldx	_vl_digits,x
   0850 BD F4 10      [ 8]  205 	jsr	___Draw_VLp
   0853 6F E2         [ 8]  206 	clr	,-s
   0855 C6 7F         [ 2]  207 	ldb	#127
   0857 BD 09 36      [ 8]  208 	jsr	__Moveto_d
   085A F6 C8 87      [ 5]  209 	ldb	_score+1
   085D 1D            [ 2]  210 	sex		;extendqihi2: R:b -> R:d
   085E 58            [ 2]  211 	aslb
   085F 49            [ 2]  212 	rola
   0860 1F 01         [ 6]  213 	tfr	d,x
   0862 AE 89 01 DE   [ 9]  214 	ldx	_vl_digits,x
   0866 BD F4 10      [ 8]  215 	jsr	___Draw_VLp
   0869 6F E2         [ 8]  216 	clr	,-s
   086B C6 7F         [ 2]  217 	ldb	#127
   086D BD 09 36      [ 8]  218 	jsr	__Moveto_d
   0870 F6 C8 86      [ 5]  219 	ldb	_score
   0873 1D            [ 2]  220 	sex		;extendqihi2: R:b -> R:d
   0874 58            [ 2]  221 	aslb
   0875 49            [ 2]  222 	rola
   0876 1F 01         [ 6]  223 	tfr	d,x
   0878 AE 89 01 DE   [ 9]  224 	ldx	_vl_digits,x
   087C BD F4 10      [ 8]  225 	jsr	___Draw_VLp
   087F 6F E2         [ 8]  226 	clr	,-s
   0881 C6 7F         [ 2]  227 	ldb	#127
   0883 BD 09 36      [ 8]  228 	jsr	__Moveto_d
   0886 BE 01 DE      [ 6]  229 	ldx	_vl_digits
   0889 BD F4 10      [ 8]  230 	jsr	___Draw_VLp
   088C C6 42         [ 2]  231 	ldb	#66
   088E D7 04         [ 4]  232 	stb	*_dp_VIA_t1_cnt_lo
   0890 C6 D4         [ 2]  233 	ldb	#-44
   0892 E7 E2         [ 6]  234 	stb	,-s
   0894 C6 81         [ 2]  235 	ldb	#-127
   0896 BD 09 36      [ 8]  236 	jsr	__Moveto_d
   0899 C6 06         [ 2]  237 	ldb	#6
   089B D7 04         [ 4]  238 	stb	*_dp_VIA_t1_cnt_lo
   089D 8E 01 F2      [ 3]  239 	ldx	#_vl_speed_display
   08A0 BD F4 10      [ 8]  240 	jsr	___Draw_VLp
   08A3 C6 06         [ 2]  241 	ldb	#6
   08A5 D7 04         [ 4]  242 	stb	*_dp_VIA_t1_cnt_lo
   08A7 F6 C8 83      [ 5]  243 	ldb	_lvl_speed
   08AA 4F            [ 2]  244 	clra		;zero_extendqihi: R:b -> R:d
   08AB 1F 01         [ 6]  245 	tfr	d,x
   08AD E6 89 08 07   [ 8]  246 	ldb	_local_lu_speed_digit_1,x
   08B1 1D            [ 2]  247 	sex		;extendqihi2: R:b -> R:d
   08B2 58            [ 2]  248 	aslb
   08B3 49            [ 2]  249 	rola
   08B4 1F 01         [ 6]  250 	tfr	d,x
   08B6 AE 89 01 DE   [ 9]  251 	ldx	_vl_digits,x
   08BA BD F4 10      [ 8]  252 	jsr	___Draw_VLp
   08BD C6 8A         [ 2]  253 	ldb	#-118
   08BF E7 E2         [ 6]  254 	stb	,-s
   08C1 C6 2A         [ 2]  255 	ldb	#42
   08C3 BD 09 36      [ 8]  256 	jsr	__Moveto_d
   08C6 BD F2 C5      [ 8]  257 	jsr	___Dot_here
   08C9 C6 76         [ 2]  258 	ldb	#118
   08CB E7 E2         [ 6]  259 	stb	,-s
   08CD C6 67         [ 2]  260 	ldb	#103
   08CF BD 09 36      [ 8]  261 	jsr	__Moveto_d
   08D2 F6 C8 83      [ 5]  262 	ldb	_lvl_speed
   08D5 4F            [ 2]  263 	clra		;zero_extendqihi: R:b -> R:d
   08D6 1F 01         [ 6]  264 	tfr	d,x
   08D8 E6 89 08 0E   [ 8]  265 	ldb	_local_lu_speed_digit_2,x
   08DC 1D            [ 2]  266 	sex		;extendqihi2: R:b -> R:d
   08DD ED 68         [ 6]  267 	std	8,s
   08DF 58            [ 2]  268 	aslb
   08E0 49            [ 2]  269 	rola
   08E1 1F 01         [ 6]  270 	tfr	d,x
   08E3 AE 89 01 DE   [ 9]  271 	ldx	_vl_digits,x
   08E7 32 6A         [ 5]  272 	leas	10,s
   08E9 7E F4 10      [ 4]  273 	jmp	___Draw_VLp
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Mon May 26 12:40:53 2025

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
Hexadecimal [16-Bits]                                 Mon May 26 12:40:53 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    5   flags    0
   3 .text            size  1DF   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

