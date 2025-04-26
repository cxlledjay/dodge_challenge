                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
                              5 	.module	temp_draw.c
                              6 	.globl	_vectors_man
                              7 	.area	.text
   0299                       8 _vectors_man:
   0299 00                    9 	.byte	0
   029A 30                   10 	.byte	48
   029B F0                   11 	.byte	-16
   029C FF                   12 	.byte	-1
   029D 00                   13 	.byte	0
   029E 20                   14 	.byte	32
   029F FF                   15 	.byte	-1
   02A0 E0                   16 	.byte	-32
   02A1 00                   17 	.byte	0
   02A2 FF                   18 	.byte	-1
   02A3 00                   19 	.byte	0
   02A4 E0                   20 	.byte	-32
   02A5 FF                   21 	.byte	-1
   02A6 20                   22 	.byte	32
   02A7 00                   23 	.byte	0
   02A8 00                   24 	.byte	0
   02A9 E0                   25 	.byte	-32
   02AA 10                   26 	.byte	16
   02AB FF                   27 	.byte	-1
   02AC E0                   28 	.byte	-32
   02AD 00                   29 	.byte	0
   02AE 00                   30 	.byte	0
   02AF 10                   31 	.byte	16
   02B0 E0                   32 	.byte	-32
   02B1 FF                   33 	.byte	-1
   02B2 00                   34 	.byte	0
   02B3 40                   35 	.byte	64
   02B4 00                   36 	.byte	0
   02B5 D0                   37 	.byte	-48
   02B6 F0                   38 	.byte	-16
   02B7 FF                   39 	.byte	-1
   02B8 20                   40 	.byte	32
   02B9 F0                   41 	.byte	-16
   02BA FF                   42 	.byte	-1
   02BB E0                   43 	.byte	-32
   02BC F0                   44 	.byte	-16
   02BD 01                   45 	.byte	1
   02BE 00                   46 	.byte	0
   02BF 00                   47 	.byte	0
                             48 	.globl	_vectors_balloon
   02C0                      49 _vectors_balloon:
   02C0 00                   50 	.byte	0
   02C1 19                   51 	.byte	25
   02C2 00                   52 	.byte	0
   02C3 FF                   53 	.byte	-1
   02C4 32                   54 	.byte	50
   02C5 00                   55 	.byte	0
   02C6 FF                   56 	.byte	-1
   02C7 00                   57 	.byte	0
   02C8 F6                   58 	.byte	-10
   02C9 FF                   59 	.byte	-1
   02CA 0A                   60 	.byte	10
   02CB 0A                   61 	.byte	10
   02CC FF                   62 	.byte	-1
   02CD 0A                   63 	.byte	10
   02CE EC                   64 	.byte	-20
   02CF FF                   65 	.byte	-1
   02D0 1E                   66 	.byte	30
   02D1 00                   67 	.byte	0
   02D2 FF                   68 	.byte	-1
   02D3 0A                   69 	.byte	10
   02D4 0A                   70 	.byte	10
   02D5 FF                   71 	.byte	-1
   02D6 00                   72 	.byte	0
   02D7 14                   73 	.byte	20
   02D8 FF                   74 	.byte	-1
   02D9 F6                   75 	.byte	-10
   02DA 0A                   76 	.byte	10
   02DB FF                   77 	.byte	-1
   02DC E2                   78 	.byte	-30
   02DD 00                   79 	.byte	0
   02DE FF                   80 	.byte	-1
   02DF F6                   81 	.byte	-10
   02E0 EC                   82 	.byte	-20
   02E1 FF                   83 	.byte	-1
   02E2 F6                   84 	.byte	-10
   02E3 0A                   85 	.byte	10
   02E4 FF                   86 	.byte	-1
   02E5 00                   87 	.byte	0
   02E6 F6                   88 	.byte	-10
   02E7                      89 _vl_term_0_46:
   02E7 01                   90 	.byte	1
                             91 	.globl	_vectors_player
   02E8                      92 _vectors_player:
   02E8 00                   93 	.byte	0
   02E9 E8                   94 	.byte	-24
   02EA EC                   95 	.byte	-20
   02EB FF                   96 	.byte	-1
   02EC 00                   97 	.byte	0
   02ED EC                   98 	.byte	-20
   02EE FF                   99 	.byte	-1
   02EF 20                  100 	.byte	32
   02F0 00                  101 	.byte	0
   02F1 FF                  102 	.byte	-1
   02F2 00                  103 	.byte	0
   02F3 14                  104 	.byte	20
   02F4 FF                  105 	.byte	-1
   02F5 E0                  106 	.byte	-32
   02F6 00                  107 	.byte	0
   02F7 00                  108 	.byte	0
   02F8 04                  109 	.byte	4
   02F9 00                  110 	.byte	0
   02FA FF                  111 	.byte	-1
   02FB 04                  112 	.byte	4
   02FC 0F                  113 	.byte	15
   02FD 00                  114 	.byte	0
   02FE 00                  115 	.byte	0
   02FF 0A                  116 	.byte	10
   0300 FF                  117 	.byte	-1
   0301 FC                  118 	.byte	-4
   0302 0F                  119 	.byte	15
   0303 00                  120 	.byte	0
   0304 FC                  121 	.byte	-4
   0305 00                  122 	.byte	0
   0306 FF                  123 	.byte	-1
   0307 00                  124 	.byte	0
   0308 14                  125 	.byte	20
   0309 FF                  126 	.byte	-1
   030A 20                  127 	.byte	32
   030B 00                  128 	.byte	0
   030C FF                  129 	.byte	-1
   030D 00                  130 	.byte	0
   030E EC                  131 	.byte	-20
   030F FF                  132 	.byte	-1
   0310 E0                  133 	.byte	-32
   0311 00                  134 	.byte	0
   0312 00                  135 	.byte	0
   0313 08                  136 	.byte	8
   0314 00                  137 	.byte	0
   0315 FF                  138 	.byte	-1
   0316 00                  139 	.byte	0
   0317 D8                  140 	.byte	-40
   0318 00                  141 	.byte	0
   0319 10                  142 	.byte	16
   031A 00                  143 	.byte	0
   031B FF                  144 	.byte	-1
   031C 04                  145 	.byte	4
   031D 0F                  146 	.byte	15
   031E FF                  147 	.byte	-1
   031F 00                  148 	.byte	0
   0320 0A                  149 	.byte	10
   0321 FF                  150 	.byte	-1
   0322 FC                  151 	.byte	-4
   0323 0F                  152 	.byte	15
   0324 FF                  153 	.byte	-1
   0325 1C                  154 	.byte	28
   0326 F0                  155 	.byte	-16
   0327 FF                  156 	.byte	-1
   0328 00                  157 	.byte	0
   0329 F8                  158 	.byte	-8
   032A 00                  159 	.byte	0
   032B F9                  160 	.byte	-7
   032C 0C                  161 	.byte	12
   032D FF                  162 	.byte	-1
   032E 00                  163 	.byte	0
   032F 0C                  164 	.byte	12
   0330 FF                  165 	.byte	-1
   0331 04                  166 	.byte	4
   0332 FE                  167 	.byte	-2
   0333 FF                  168 	.byte	-1
   0334 00                  169 	.byte	0
   0335 F4                  170 	.byte	-12
   0336 00                  171 	.byte	0
   0337 00                  172 	.byte	0
   0338 F4                  173 	.byte	-12
   0339 FF                  174 	.byte	-1
   033A 00                  175 	.byte	0
   033B F4                  176 	.byte	-12
   033C FF                  177 	.byte	-1
   033D FC                  178 	.byte	-4
   033E FE                  179 	.byte	-2
   033F FF                  180 	.byte	-1
   0340 00                  181 	.byte	0
   0341 0C                  182 	.byte	12
   0342 00                  183 	.byte	0
   0343 07                  184 	.byte	7
   0344 04                  185 	.byte	4
   0345 FF                  186 	.byte	-1
   0346 E4                  187 	.byte	-28
   0347 F0                  188 	.byte	-16
   0348 00                  189 	.byte	0
   0349 08                  190 	.byte	8
   034A F6                  191 	.byte	-10
   034B FF                  192 	.byte	-1
   034C 0A                  193 	.byte	10
   034D 00                  194 	.byte	0
   034E FF                  195 	.byte	-1
   034F 00                  196 	.byte	0
   0350 0F                  197 	.byte	15
   0351 FF                  198 	.byte	-1
   0352 F7                  199 	.byte	-9
   0353 00                  200 	.byte	0
   0354 00                  201 	.byte	0
   0355 00                  202 	.byte	0
   0356 1E                  203 	.byte	30
   0357 FF                  204 	.byte	-1
   0358 09                  205 	.byte	9
   0359 00                  206 	.byte	0
   035A FF                  207 	.byte	-1
   035B 00                  208 	.byte	0
   035C 0F                  209 	.byte	15
   035D FF                  210 	.byte	-1
   035E F6                  211 	.byte	-10
   035F 00                  212 	.byte	0
   0360 00                  213 	.byte	0
   0361 05                  214 	.byte	5
   0362 E7                  215 	.byte	-25
   0363 FF                  216 	.byte	-1
   0364 04                  217 	.byte	4
   0365 FE                  218 	.byte	-2
   0366 FF                  219 	.byte	-1
   0367 00                  220 	.byte	0
   0368 FA                  221 	.byte	-6
   0369 FF                  222 	.byte	-1
   036A FC                  223 	.byte	-4
   036B FE                  224 	.byte	-2
   036C                     225 _vl_term_1_109:
   036C 01                  226 	.byte	1
                            227 	.globl	_vectors_horizon
   036D                     228 _vectors_horizon:
   036D FF                  229 	.byte	-1
   036E 00                  230 	.byte	0
   036F 7F                  231 	.byte	127
   0370                     232 _vl_term_2_117:
   0370 01                  233 	.byte	1
                            234 	.globl	_vectors_road_inner_line_l
   0371                     235 _vectors_road_inner_line_l:
   0371 FF                  236 	.byte	-1
   0372 FC                  237 	.byte	-4
   0373 FF                  238 	.byte	-1
   0374 00                  239 	.byte	0
   0375 FC                  240 	.byte	-4
   0376 FF                  241 	.byte	-1
   0377 FF                  242 	.byte	-1
   0378 FC                  243 	.byte	-4
   0379 FF                  244 	.byte	-1
   037A 00                  245 	.byte	0
   037B FC                  246 	.byte	-4
   037C FF                  247 	.byte	-1
   037D FF                  248 	.byte	-1
   037E F8                  249 	.byte	-8
   037F FE                  250 	.byte	-2
   0380 00                  251 	.byte	0
   0381 F8                  252 	.byte	-8
   0382 FE                  253 	.byte	-2
   0383 FF                  254 	.byte	-1
   0384 F8                  255 	.byte	-8
   0385 FE                  256 	.byte	-2
   0386 00                  257 	.byte	0
   0387 F8                  258 	.byte	-8
   0388 FE                  259 	.byte	-2
   0389 FF                  260 	.byte	-1
   038A F4                  261 	.byte	-12
   038B FD                  262 	.byte	-3
   038C 00                  263 	.byte	0
   038D F4                  264 	.byte	-12
   038E FD                  265 	.byte	-3
   038F FF                  266 	.byte	-1
   0390 F4                  267 	.byte	-12
   0391 FD                  268 	.byte	-3
   0392 00                  269 	.byte	0
   0393 F4                  270 	.byte	-12
   0394 FD                  271 	.byte	-3
   0395 FF                  272 	.byte	-1
   0396 F0                  273 	.byte	-16
   0397 FC                  274 	.byte	-4
   0398 00                  275 	.byte	0
   0399 F0                  276 	.byte	-16
   039A FC                  277 	.byte	-4
   039B FF                  278 	.byte	-1
   039C F0                  279 	.byte	-16
   039D FC                  280 	.byte	-4
   039E 00                  281 	.byte	0
   039F F0                  282 	.byte	-16
   03A0 FC                  283 	.byte	-4
   03A1 FF                  284 	.byte	-1
   03A2 EC                  285 	.byte	-20
   03A3 FB                  286 	.byte	-5
   03A4                     287 _vl_term_3_141:
   03A4 01                  288 	.byte	1
                            289 	.globl	_vectors_road_inner_line_r
   03A5                     290 _vectors_road_inner_line_r:
   03A5 FF                  291 	.byte	-1
   03A6 FC                  292 	.byte	-4
   03A7 01                  293 	.byte	1
   03A8 00                  294 	.byte	0
   03A9 FC                  295 	.byte	-4
   03AA 01                  296 	.byte	1
   03AB FF                  297 	.byte	-1
   03AC FC                  298 	.byte	-4
   03AD 01                  299 	.byte	1
   03AE 00                  300 	.byte	0
   03AF FC                  301 	.byte	-4
   03B0 01                  302 	.byte	1
   03B1 FF                  303 	.byte	-1
   03B2 F8                  304 	.byte	-8
   03B3 02                  305 	.byte	2
   03B4 00                  306 	.byte	0
   03B5 F8                  307 	.byte	-8
   03B6 02                  308 	.byte	2
   03B7 FF                  309 	.byte	-1
   03B8 F8                  310 	.byte	-8
   03B9 02                  311 	.byte	2
   03BA 00                  312 	.byte	0
   03BB F8                  313 	.byte	-8
   03BC 02                  314 	.byte	2
   03BD FF                  315 	.byte	-1
   03BE F4                  316 	.byte	-12
   03BF 03                  317 	.byte	3
   03C0 00                  318 	.byte	0
   03C1 F4                  319 	.byte	-12
   03C2 03                  320 	.byte	3
   03C3 FF                  321 	.byte	-1
   03C4 F4                  322 	.byte	-12
   03C5 03                  323 	.byte	3
   03C6 00                  324 	.byte	0
   03C7 F4                  325 	.byte	-12
   03C8 03                  326 	.byte	3
   03C9 FF                  327 	.byte	-1
   03CA F0                  328 	.byte	-16
   03CB 04                  329 	.byte	4
   03CC 00                  330 	.byte	0
   03CD F0                  331 	.byte	-16
   03CE 04                  332 	.byte	4
   03CF FF                  333 	.byte	-1
   03D0 F0                  334 	.byte	-16
   03D1 04                  335 	.byte	4
   03D2 00                  336 	.byte	0
   03D3 F0                  337 	.byte	-16
   03D4 04                  338 	.byte	4
   03D5 FF                  339 	.byte	-1
   03D6 EC                  340 	.byte	-20
   03D7 05                  341 	.byte	5
   03D8                     342 _vl_term_4_163:
   03D8 01                  343 	.byte	1
                            344 	.globl	_vectors_debug_car
   03D9                     345 _vectors_debug_car:
   03D9 00                  346 	.byte	0
   03DA 08                  347 	.byte	8
   03DB FA                  348 	.byte	-6
   03DC FF                  349 	.byte	-1
   03DD F4                  350 	.byte	-12
   03DE 00                  351 	.byte	0
   03DF FF                  352 	.byte	-1
   03E0 00                  353 	.byte	0
   03E1 0C                  354 	.byte	12
   03E2 FF                  355 	.byte	-1
   03E3 0C                  356 	.byte	12
   03E4 00                  357 	.byte	0
   03E5 FF                  358 	.byte	-1
   03E6 00                  359 	.byte	0
   03E7 F4                  360 	.byte	-12
   03E8                     361 _vl_term_5_174:
   03E8 01                  362 	.byte	1
                            363 	.globl	_vectors_obstacle_truck_s
   03E9                     364 _vectors_obstacle_truck_s:
                            365 	.globl	_temp_draw
   03E9                     366 _temp_draw:
   03E9 BD F1 92      [ 8]  367 	jsr	___Wait_Recal
   03EC BD F2 A5      [ 8]  368 	jsr	___Intensity_5F
   03EF BD F3 54      [ 8]  369 	jsr	___Reset0Ref
   03F2 C6 7F         [ 2]  370 	ldb	#127
   03F4 D7 04         [ 4]  371 	stb	*_dp_VIA_t1_cnt_lo
   03F6 6F E2         [ 8]  372 	clr	,-s
   03F8 5F            [ 2]  373 	clrb
   03F9 BD 04 6A      [ 8]  374 	jsr	__Moveto_d
   03FC 32 61         [ 5]  375 	leas	1,s
   03FE C6 FF         [ 2]  376 	ldb	#-1
   0400 D7 04         [ 4]  377 	stb	*_dp_VIA_t1_cnt_lo
   0402 8E 02 E8      [ 3]  378 	ldx	#_vectors_player
   0405 BD F4 10      [ 8]  379 	jsr	___Draw_VLp
   0408 39            [ 5]  380 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Sat Apr 26 23:41:18 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
    __Moveto_d         **** GX  |     ___Draw_VLp        **** GX
    ___Intensity_5     **** GX  |     ___Reset0Ref       **** GX
    ___Wait_Recal      **** GX  |     _dp_VIA_t1_cnt     **** GX
  2 _temp_draw         0150 GR  |   2 _vectors_ballo     0027 GR
  2 _vectors_debug     0140 GR  |   2 _vectors_horiz     00D4 GR
  2 _vectors_man       0000 GR  |   2 _vectors_obsta     0150 GR
  2 _vectors_playe     004F GR  |   2 _vectors_road_     00D8 GR
  2 _vectors_road_     010C GR  |   2 _vl_term_0_46      004E R
  2 _vl_term_1_109     00D3 R   |   2 _vl_term_2_117     00D7 R
  2 _vl_term_3_141     010B R   |   2 _vl_term_4_163     013F R
  2 _vl_term_5_174     014F R

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Sat Apr 26 23:41:18 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .text            size  170   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

