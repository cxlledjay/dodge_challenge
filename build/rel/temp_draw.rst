                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
                              5 	.module	temp_draw.c
                              6 	.globl	_vectors_man
                              7 	.area	.text
   0066                       8 _vectors_man:
   0066 00                    9 	.byte	0
   0067 30                   10 	.byte	48
   0068 F0                   11 	.byte	-16
   0069 FF                   12 	.byte	-1
   006A 00                   13 	.byte	0
   006B 20                   14 	.byte	32
   006C FF                   15 	.byte	-1
   006D E0                   16 	.byte	-32
   006E 00                   17 	.byte	0
   006F FF                   18 	.byte	-1
   0070 00                   19 	.byte	0
   0071 E0                   20 	.byte	-32
   0072 FF                   21 	.byte	-1
   0073 20                   22 	.byte	32
   0074 00                   23 	.byte	0
   0075 00                   24 	.byte	0
   0076 E0                   25 	.byte	-32
   0077 10                   26 	.byte	16
   0078 FF                   27 	.byte	-1
   0079 E0                   28 	.byte	-32
   007A 00                   29 	.byte	0
   007B 00                   30 	.byte	0
   007C 10                   31 	.byte	16
   007D E0                   32 	.byte	-32
   007E FF                   33 	.byte	-1
   007F 00                   34 	.byte	0
   0080 40                   35 	.byte	64
   0081 00                   36 	.byte	0
   0082 D0                   37 	.byte	-48
   0083 F0                   38 	.byte	-16
   0084 FF                   39 	.byte	-1
   0085 20                   40 	.byte	32
   0086 F0                   41 	.byte	-16
   0087 FF                   42 	.byte	-1
   0088 E0                   43 	.byte	-32
   0089 F0                   44 	.byte	-16
   008A 01                   45 	.byte	1
   008B 00                   46 	.byte	0
   008C 00                   47 	.byte	0
                             48 	.globl	_vectors_balloon
   008D                      49 _vectors_balloon:
   008D 00                   50 	.byte	0
   008E 19                   51 	.byte	25
   008F 00                   52 	.byte	0
   0090 FF                   53 	.byte	-1
   0091 32                   54 	.byte	50
   0092 00                   55 	.byte	0
   0093 FF                   56 	.byte	-1
   0094 00                   57 	.byte	0
   0095 F6                   58 	.byte	-10
   0096 FF                   59 	.byte	-1
   0097 0A                   60 	.byte	10
   0098 0A                   61 	.byte	10
   0099 FF                   62 	.byte	-1
   009A 0A                   63 	.byte	10
   009B EC                   64 	.byte	-20
   009C FF                   65 	.byte	-1
   009D 1E                   66 	.byte	30
   009E 00                   67 	.byte	0
   009F FF                   68 	.byte	-1
   00A0 0A                   69 	.byte	10
   00A1 0A                   70 	.byte	10
   00A2 FF                   71 	.byte	-1
   00A3 00                   72 	.byte	0
   00A4 14                   73 	.byte	20
   00A5 FF                   74 	.byte	-1
   00A6 F6                   75 	.byte	-10
   00A7 0A                   76 	.byte	10
   00A8 FF                   77 	.byte	-1
   00A9 E2                   78 	.byte	-30
   00AA 00                   79 	.byte	0
   00AB FF                   80 	.byte	-1
   00AC F6                   81 	.byte	-10
   00AD EC                   82 	.byte	-20
   00AE FF                   83 	.byte	-1
   00AF F6                   84 	.byte	-10
   00B0 0A                   85 	.byte	10
   00B1 FF                   86 	.byte	-1
   00B2 00                   87 	.byte	0
   00B3 F6                   88 	.byte	-10
   00B4                      89 _vl_term_0_46:
   00B4 01                   90 	.byte	1
                             91 	.globl	_vectors_player_b
   00B5                      92 _vectors_player_b:
   00B5 00                   93 	.byte	0
   00B6 E8                   94 	.byte	-24
   00B7 EC                   95 	.byte	-20
   00B8 FF                   96 	.byte	-1
   00B9 00                   97 	.byte	0
   00BA EC                   98 	.byte	-20
   00BB FF                   99 	.byte	-1
   00BC 20                  100 	.byte	32
   00BD 00                  101 	.byte	0
   00BE FF                  102 	.byte	-1
   00BF 00                  103 	.byte	0
   00C0 14                  104 	.byte	20
   00C1 FF                  105 	.byte	-1
   00C2 E0                  106 	.byte	-32
   00C3 00                  107 	.byte	0
   00C4 00                  108 	.byte	0
   00C5 04                  109 	.byte	4
   00C6 00                  110 	.byte	0
   00C7 FF                  111 	.byte	-1
   00C8 04                  112 	.byte	4
   00C9 0F                  113 	.byte	15
   00CA 00                  114 	.byte	0
   00CB 00                  115 	.byte	0
   00CC 0A                  116 	.byte	10
   00CD FF                  117 	.byte	-1
   00CE FC                  118 	.byte	-4
   00CF 0F                  119 	.byte	15
   00D0 00                  120 	.byte	0
   00D1 FC                  121 	.byte	-4
   00D2 00                  122 	.byte	0
   00D3 FF                  123 	.byte	-1
   00D4 00                  124 	.byte	0
   00D5 14                  125 	.byte	20
   00D6 FF                  126 	.byte	-1
   00D7 20                  127 	.byte	32
   00D8 00                  128 	.byte	0
   00D9 FF                  129 	.byte	-1
   00DA 00                  130 	.byte	0
   00DB EC                  131 	.byte	-20
   00DC FF                  132 	.byte	-1
   00DD E0                  133 	.byte	-32
   00DE 00                  134 	.byte	0
   00DF 00                  135 	.byte	0
   00E0 08                  136 	.byte	8
   00E1 00                  137 	.byte	0
   00E2 FF                  138 	.byte	-1
   00E3 00                  139 	.byte	0
   00E4 D8                  140 	.byte	-40
   00E5 00                  141 	.byte	0
   00E6 10                  142 	.byte	16
   00E7 00                  143 	.byte	0
   00E8 FF                  144 	.byte	-1
   00E9 04                  145 	.byte	4
   00EA 0F                  146 	.byte	15
   00EB FF                  147 	.byte	-1
   00EC 00                  148 	.byte	0
   00ED 0A                  149 	.byte	10
   00EE FF                  150 	.byte	-1
   00EF FC                  151 	.byte	-4
   00F0 0F                  152 	.byte	15
   00F1 FF                  153 	.byte	-1
   00F2 1C                  154 	.byte	28
   00F3 F0                  155 	.byte	-16
   00F4 FF                  156 	.byte	-1
   00F5 00                  157 	.byte	0
   00F6 F8                  158 	.byte	-8
   00F7 00                  159 	.byte	0
   00F8 F9                  160 	.byte	-7
   00F9 0C                  161 	.byte	12
   00FA FF                  162 	.byte	-1
   00FB 00                  163 	.byte	0
   00FC 0C                  164 	.byte	12
   00FD FF                  165 	.byte	-1
   00FE 04                  166 	.byte	4
   00FF FE                  167 	.byte	-2
   0100 FF                  168 	.byte	-1
   0101 00                  169 	.byte	0
   0102 F4                  170 	.byte	-12
   0103 00                  171 	.byte	0
   0104 00                  172 	.byte	0
   0105 F4                  173 	.byte	-12
   0106 FF                  174 	.byte	-1
   0107 00                  175 	.byte	0
   0108 F4                  176 	.byte	-12
   0109 FF                  177 	.byte	-1
   010A FC                  178 	.byte	-4
   010B FE                  179 	.byte	-2
   010C FF                  180 	.byte	-1
   010D 00                  181 	.byte	0
   010E 0C                  182 	.byte	12
   010F 00                  183 	.byte	0
   0110 07                  184 	.byte	7
   0111 04                  185 	.byte	4
   0112 FF                  186 	.byte	-1
   0113 E4                  187 	.byte	-28
   0114 F0                  188 	.byte	-16
   0115 00                  189 	.byte	0
   0116 08                  190 	.byte	8
   0117 F6                  191 	.byte	-10
   0118 FF                  192 	.byte	-1
   0119 0A                  193 	.byte	10
   011A 00                  194 	.byte	0
   011B FF                  195 	.byte	-1
   011C 00                  196 	.byte	0
   011D 0F                  197 	.byte	15
   011E FF                  198 	.byte	-1
   011F F7                  199 	.byte	-9
   0120 00                  200 	.byte	0
   0121 00                  201 	.byte	0
   0122 00                  202 	.byte	0
   0123 1E                  203 	.byte	30
   0124 FF                  204 	.byte	-1
   0125 09                  205 	.byte	9
   0126 00                  206 	.byte	0
   0127 FF                  207 	.byte	-1
   0128 00                  208 	.byte	0
   0129 0F                  209 	.byte	15
   012A FF                  210 	.byte	-1
   012B F6                  211 	.byte	-10
   012C 00                  212 	.byte	0
   012D 00                  213 	.byte	0
   012E 05                  214 	.byte	5
   012F E7                  215 	.byte	-25
   0130 FF                  216 	.byte	-1
   0131 04                  217 	.byte	4
   0132 FE                  218 	.byte	-2
   0133 FF                  219 	.byte	-1
   0134 00                  220 	.byte	0
   0135 FA                  221 	.byte	-6
   0136 FF                  222 	.byte	-1
   0137 FC                  223 	.byte	-4
   0138 FE                  224 	.byte	-2
   0139                     225 _vl_term_1_109:
   0139 01                  226 	.byte	1
                            227 	.globl	_vectors_obstacle_truck_s
   013A                     228 _vectors_obstacle_truck_s:
                            229 	.globl	_temp_draw
   013A                     230 _temp_draw:
   013A BD F1 92      [ 8]  231 	jsr	___Wait_Recal
   013D BD F2 A5      [ 8]  232 	jsr	___Intensity_5F
   0140 BD F3 54      [ 8]  233 	jsr	___Reset0Ref
   0143 C6 7F         [ 2]  234 	ldb	#127
   0145 D7 04         [ 4]  235 	stb	*_dp_VIA_t1_cnt_lo
   0147 6F E2         [ 8]  236 	clr	,-s
   0149 5F            [ 2]  237 	clrb
   014A BD 01 5A      [ 8]  238 	jsr	__Moveto_d
   014D 32 61         [ 5]  239 	leas	1,s
   014F C6 FF         [ 2]  240 	ldb	#-1
   0151 D7 04         [ 4]  241 	stb	*_dp_VIA_t1_cnt_lo
   0153 8E 00 B5      [ 3]  242 	ldx	#_vectors_player_b
   0156 BD F4 10      [ 8]  243 	jsr	___Draw_VLp
   0159 39            [ 5]  244 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Mon Apr 14 13:54:35 2025

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
Hexadecimal [16-Bits]                                 Mon Apr 14 13:54:35 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .text            size   F4   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

