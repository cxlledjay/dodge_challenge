                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
                              5 	.module	temp_draw.c
                              6 	.globl	_vectors_man
                              7 	.area	.text
   00F6                       8 _vectors_man:
   00F6 00                    9 	.byte	0
   00F7 30                   10 	.byte	48
   00F8 F0                   11 	.byte	-16
   00F9 FF                   12 	.byte	-1
   00FA 00                   13 	.byte	0
   00FB 20                   14 	.byte	32
   00FC FF                   15 	.byte	-1
   00FD E0                   16 	.byte	-32
   00FE 00                   17 	.byte	0
   00FF FF                   18 	.byte	-1
   0100 00                   19 	.byte	0
   0101 E0                   20 	.byte	-32
   0102 FF                   21 	.byte	-1
   0103 20                   22 	.byte	32
   0104 00                   23 	.byte	0
   0105 00                   24 	.byte	0
   0106 E0                   25 	.byte	-32
   0107 10                   26 	.byte	16
   0108 FF                   27 	.byte	-1
   0109 E0                   28 	.byte	-32
   010A 00                   29 	.byte	0
   010B 00                   30 	.byte	0
   010C 10                   31 	.byte	16
   010D E0                   32 	.byte	-32
   010E FF                   33 	.byte	-1
   010F 00                   34 	.byte	0
   0110 40                   35 	.byte	64
   0111 00                   36 	.byte	0
   0112 D0                   37 	.byte	-48
   0113 F0                   38 	.byte	-16
   0114 FF                   39 	.byte	-1
   0115 20                   40 	.byte	32
   0116 F0                   41 	.byte	-16
   0117 FF                   42 	.byte	-1
   0118 E0                   43 	.byte	-32
   0119 F0                   44 	.byte	-16
   011A 01                   45 	.byte	1
   011B 00                   46 	.byte	0
   011C 00                   47 	.byte	0
                             48 	.globl	_vectors_balloon
   011D                      49 _vectors_balloon:
   011D 00                   50 	.byte	0
   011E 19                   51 	.byte	25
   011F 00                   52 	.byte	0
   0120 FF                   53 	.byte	-1
   0121 32                   54 	.byte	50
   0122 00                   55 	.byte	0
   0123 FF                   56 	.byte	-1
   0124 00                   57 	.byte	0
   0125 F6                   58 	.byte	-10
   0126 FF                   59 	.byte	-1
   0127 0A                   60 	.byte	10
   0128 0A                   61 	.byte	10
   0129 FF                   62 	.byte	-1
   012A 0A                   63 	.byte	10
   012B EC                   64 	.byte	-20
   012C FF                   65 	.byte	-1
   012D 1E                   66 	.byte	30
   012E 00                   67 	.byte	0
   012F FF                   68 	.byte	-1
   0130 0A                   69 	.byte	10
   0131 0A                   70 	.byte	10
   0132 FF                   71 	.byte	-1
   0133 00                   72 	.byte	0
   0134 14                   73 	.byte	20
   0135 FF                   74 	.byte	-1
   0136 F6                   75 	.byte	-10
   0137 0A                   76 	.byte	10
   0138 FF                   77 	.byte	-1
   0139 E2                   78 	.byte	-30
   013A 00                   79 	.byte	0
   013B FF                   80 	.byte	-1
   013C F6                   81 	.byte	-10
   013D EC                   82 	.byte	-20
   013E FF                   83 	.byte	-1
   013F F6                   84 	.byte	-10
   0140 0A                   85 	.byte	10
   0141 FF                   86 	.byte	-1
   0142 00                   87 	.byte	0
   0143 F6                   88 	.byte	-10
   0144                      89 _vl_term_0_46:
   0144 01                   90 	.byte	1
                             91 	.globl	_vectors_player
   0145                      92 _vectors_player:
   0145 00                   93 	.byte	0
   0146 E8                   94 	.byte	-24
   0147 EC                   95 	.byte	-20
   0148 FF                   96 	.byte	-1
   0149 00                   97 	.byte	0
   014A EC                   98 	.byte	-20
   014B FF                   99 	.byte	-1
   014C 20                  100 	.byte	32
   014D 00                  101 	.byte	0
   014E FF                  102 	.byte	-1
   014F 00                  103 	.byte	0
   0150 14                  104 	.byte	20
   0151 FF                  105 	.byte	-1
   0152 E0                  106 	.byte	-32
   0153 00                  107 	.byte	0
   0154 00                  108 	.byte	0
   0155 04                  109 	.byte	4
   0156 00                  110 	.byte	0
   0157 FF                  111 	.byte	-1
   0158 04                  112 	.byte	4
   0159 0F                  113 	.byte	15
   015A 00                  114 	.byte	0
   015B 00                  115 	.byte	0
   015C 0A                  116 	.byte	10
   015D FF                  117 	.byte	-1
   015E FC                  118 	.byte	-4
   015F 0F                  119 	.byte	15
   0160 00                  120 	.byte	0
   0161 FC                  121 	.byte	-4
   0162 00                  122 	.byte	0
   0163 FF                  123 	.byte	-1
   0164 00                  124 	.byte	0
   0165 14                  125 	.byte	20
   0166 FF                  126 	.byte	-1
   0167 20                  127 	.byte	32
   0168 00                  128 	.byte	0
   0169 FF                  129 	.byte	-1
   016A 00                  130 	.byte	0
   016B EC                  131 	.byte	-20
   016C FF                  132 	.byte	-1
   016D E0                  133 	.byte	-32
   016E 00                  134 	.byte	0
   016F 00                  135 	.byte	0
   0170 08                  136 	.byte	8
   0171 00                  137 	.byte	0
   0172 FF                  138 	.byte	-1
   0173 00                  139 	.byte	0
   0174 D8                  140 	.byte	-40
   0175 00                  141 	.byte	0
   0176 10                  142 	.byte	16
   0177 00                  143 	.byte	0
   0178 FF                  144 	.byte	-1
   0179 04                  145 	.byte	4
   017A 0F                  146 	.byte	15
   017B FF                  147 	.byte	-1
   017C 00                  148 	.byte	0
   017D 0A                  149 	.byte	10
   017E FF                  150 	.byte	-1
   017F FC                  151 	.byte	-4
   0180 0F                  152 	.byte	15
   0181 FF                  153 	.byte	-1
   0182 1C                  154 	.byte	28
   0183 F0                  155 	.byte	-16
   0184 FF                  156 	.byte	-1
   0185 00                  157 	.byte	0
   0186 F8                  158 	.byte	-8
   0187 00                  159 	.byte	0
   0188 F9                  160 	.byte	-7
   0189 0C                  161 	.byte	12
   018A FF                  162 	.byte	-1
   018B 00                  163 	.byte	0
   018C 0C                  164 	.byte	12
   018D FF                  165 	.byte	-1
   018E 04                  166 	.byte	4
   018F FE                  167 	.byte	-2
   0190 FF                  168 	.byte	-1
   0191 00                  169 	.byte	0
   0192 F4                  170 	.byte	-12
   0193 00                  171 	.byte	0
   0194 00                  172 	.byte	0
   0195 F4                  173 	.byte	-12
   0196 FF                  174 	.byte	-1
   0197 00                  175 	.byte	0
   0198 F4                  176 	.byte	-12
   0199 FF                  177 	.byte	-1
   019A FC                  178 	.byte	-4
   019B FE                  179 	.byte	-2
   019C FF                  180 	.byte	-1
   019D 00                  181 	.byte	0
   019E 0C                  182 	.byte	12
   019F 00                  183 	.byte	0
   01A0 07                  184 	.byte	7
   01A1 04                  185 	.byte	4
   01A2 FF                  186 	.byte	-1
   01A3 E4                  187 	.byte	-28
   01A4 F0                  188 	.byte	-16
   01A5 00                  189 	.byte	0
   01A6 08                  190 	.byte	8
   01A7 F6                  191 	.byte	-10
   01A8 FF                  192 	.byte	-1
   01A9 0A                  193 	.byte	10
   01AA 00                  194 	.byte	0
   01AB FF                  195 	.byte	-1
   01AC 00                  196 	.byte	0
   01AD 0F                  197 	.byte	15
   01AE FF                  198 	.byte	-1
   01AF F7                  199 	.byte	-9
   01B0 00                  200 	.byte	0
   01B1 00                  201 	.byte	0
   01B2 00                  202 	.byte	0
   01B3 1E                  203 	.byte	30
   01B4 FF                  204 	.byte	-1
   01B5 09                  205 	.byte	9
   01B6 00                  206 	.byte	0
   01B7 FF                  207 	.byte	-1
   01B8 00                  208 	.byte	0
   01B9 0F                  209 	.byte	15
   01BA FF                  210 	.byte	-1
   01BB F6                  211 	.byte	-10
   01BC 00                  212 	.byte	0
   01BD 00                  213 	.byte	0
   01BE 05                  214 	.byte	5
   01BF E7                  215 	.byte	-25
   01C0 FF                  216 	.byte	-1
   01C1 04                  217 	.byte	4
   01C2 FE                  218 	.byte	-2
   01C3 FF                  219 	.byte	-1
   01C4 00                  220 	.byte	0
   01C5 FA                  221 	.byte	-6
   01C6 FF                  222 	.byte	-1
   01C7 FC                  223 	.byte	-4
   01C8 FE                  224 	.byte	-2
   01C9                     225 _vl_term_1_109:
   01C9 01                  226 	.byte	1
                            227 	.globl	_vectors_obstacle_truck_s
   01CA                     228 _vectors_obstacle_truck_s:
                            229 	.globl	_temp_draw
   01CA                     230 _temp_draw:
   01CA BD F1 92      [ 8]  231 	jsr	___Wait_Recal
   01CD BD F2 A5      [ 8]  232 	jsr	___Intensity_5F
   01D0 BD F3 54      [ 8]  233 	jsr	___Reset0Ref
   01D3 C6 7F         [ 2]  234 	ldb	#127
   01D5 D7 04         [ 4]  235 	stb	*_dp_VIA_t1_cnt_lo
   01D7 6F E2         [ 8]  236 	clr	,-s
   01D9 5F            [ 2]  237 	clrb
   01DA BD 02 46      [ 8]  238 	jsr	__Moveto_d
   01DD 32 61         [ 5]  239 	leas	1,s
   01DF C6 FF         [ 2]  240 	ldb	#-1
   01E1 D7 04         [ 4]  241 	stb	*_dp_VIA_t1_cnt_lo
   01E3 8E 01 45      [ 3]  242 	ldx	#_vectors_player
   01E6 BD F4 10      [ 8]  243 	jsr	___Draw_VLp
   01E9 39            [ 5]  244 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri Apr 25 17:08:29 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
    __Moveto_d         **** GX  |     ___Draw_VLp        **** GX
    ___Intensity_5     **** GX  |     ___Reset0Ref       **** GX
    ___Wait_Recal      **** GX  |     _dp_VIA_t1_cnt     **** GX
  2 _temp_draw         00D4 GR  |   2 _vectors_ballo     0027 GR
  2 _vectors_man       0000 GR  |   2 _vectors_obsta     00D4 GR
  2 _vectors_playe     004F GR  |   2 _vl_term_0_46      004E R
  2 _vl_term_1_109     00D3 R

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Fri Apr 25 17:08:29 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .text            size   F4   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

