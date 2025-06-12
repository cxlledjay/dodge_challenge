                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	map.c
                              6 	.area	.bss
                              7 	.globl	_the_map
   C8A8                       8 _the_map:	.blkb	3
                              9 	.area	.text
                             10 	.globl	_dummy_tick
   02D1                      11 _dummy_tick:
   02D1 39            [ 5]   12 	rts
                             13 	.globl	_map_init
   02D2                      14 _map_init:
   02D2 8E 04 35      [ 3]   15 	ldx	#_draw_step1
   02D5 BF C8 A9      [ 6]   16 	stx	_the_map+1
   02D8 7F C8 A8      [ 7]   17 	clr	_the_map
   02DB 39            [ 5]   18 	rts
                             19 	.globl	_vl_misc_roadline_left
   02DC                      20 _vl_misc_roadline_left:
   02DC FF                   21 	.byte	-1
   02DD E0                   22 	.byte	-32
   02DE F8                   23 	.byte	-8
   02DF 00                   24 	.byte	0
   02E0 E0                   25 	.byte	-32
   02E1 F8                   26 	.byte	-8
   02E2 FF                   27 	.byte	-1
   02E3 E0                   28 	.byte	-32
   02E4 F8                   29 	.byte	-8
   02E5 00                   30 	.byte	0
   02E6 E0                   31 	.byte	-32
   02E7 F8                   32 	.byte	-8
   02E8 FF                   33 	.byte	-1
   02E9 C0                   34 	.byte	-64
   02EA F0                   35 	.byte	-16
   02EB 00                   36 	.byte	0
   02EC C0                   37 	.byte	-64
   02ED F0                   38 	.byte	-16
   02EE FF                   39 	.byte	-1
   02EF C0                   40 	.byte	-64
   02F0 F0                   41 	.byte	-16
   02F1 00                   42 	.byte	0
   02F2 C0                   43 	.byte	-64
   02F3 F0                   44 	.byte	-16
   02F4 FF                   45 	.byte	-1
   02F5 A0                   46 	.byte	-96
   02F6 E8                   47 	.byte	-24
   02F7 00                   48 	.byte	0
   02F8 A0                   49 	.byte	-96
   02F9 E8                   50 	.byte	-24
   02FA FF                   51 	.byte	-1
   02FB A0                   52 	.byte	-96
   02FC E8                   53 	.byte	-24
   02FD 00                   54 	.byte	0
   02FE A0                   55 	.byte	-96
   02FF E8                   56 	.byte	-24
   0300 FF                   57 	.byte	-1
   0301 80                   58 	.byte	-128
   0302 E0                   59 	.byte	-32
   0303 00                   60 	.byte	0
   0304 80                   61 	.byte	-128
   0305 E0                   62 	.byte	-32
   0306 FF                   63 	.byte	-1
   0307 80                   64 	.byte	-128
   0308 E0                   65 	.byte	-32
   0309 00                   66 	.byte	0
   030A 80                   67 	.byte	-128
   030B E0                   68 	.byte	-32
   030C FF                   69 	.byte	-1
   030D 80                   70 	.byte	-128
   030E E0                   71 	.byte	-32
   030F FF                   72 	.byte	-1
   0310 E0                   73 	.byte	-32
   0311 F8                   74 	.byte	-8
   0312                      75 _vl_term_0_35:
   0312 01                   76 	.byte	1
                             77 	.globl	_vl_misc_roadline_right
   0313                      78 _vl_misc_roadline_right:
   0313 FF                   79 	.byte	-1
   0314 E0                   80 	.byte	-32
   0315 08                   81 	.byte	8
   0316 00                   82 	.byte	0
   0317 E0                   83 	.byte	-32
   0318 08                   84 	.byte	8
   0319 FF                   85 	.byte	-1
   031A E0                   86 	.byte	-32
   031B 08                   87 	.byte	8
   031C 00                   88 	.byte	0
   031D E0                   89 	.byte	-32
   031E 08                   90 	.byte	8
   031F FF                   91 	.byte	-1
   0320 C0                   92 	.byte	-64
   0321 10                   93 	.byte	16
   0322 00                   94 	.byte	0
   0323 C0                   95 	.byte	-64
   0324 10                   96 	.byte	16
   0325 FF                   97 	.byte	-1
   0326 C0                   98 	.byte	-64
   0327 10                   99 	.byte	16
   0328 00                  100 	.byte	0
   0329 C0                  101 	.byte	-64
   032A 10                  102 	.byte	16
   032B FF                  103 	.byte	-1
   032C A0                  104 	.byte	-96
   032D 18                  105 	.byte	24
   032E 00                  106 	.byte	0
   032F A0                  107 	.byte	-96
   0330 18                  108 	.byte	24
   0331 FF                  109 	.byte	-1
   0332 A0                  110 	.byte	-96
   0333 18                  111 	.byte	24
   0334 00                  112 	.byte	0
   0335 A0                  113 	.byte	-96
   0336 18                  114 	.byte	24
   0337 FF                  115 	.byte	-1
   0338 80                  116 	.byte	-128
   0339 20                  117 	.byte	32
   033A 00                  118 	.byte	0
   033B 80                  119 	.byte	-128
   033C 20                  120 	.byte	32
   033D FF                  121 	.byte	-1
   033E 80                  122 	.byte	-128
   033F 20                  123 	.byte	32
   0340 00                  124 	.byte	0
   0341 80                  125 	.byte	-128
   0342 20                  126 	.byte	32
   0343 FF                  127 	.byte	-1
   0344 80                  128 	.byte	-128
   0345 20                  129 	.byte	32
   0346 FF                  130 	.byte	-1
   0347 E0                  131 	.byte	-32
   0348 08                  132 	.byte	8
   0349                     133 _vl_term_1_60:
   0349 01                  134 	.byte	1
                            135 	.globl	_vl_map_roadline_left_1
   034A                     136 _vl_map_roadline_left_1:
   034A FF                  137 	.byte	-1
   034B F0                  138 	.byte	-16
   034C FC                  139 	.byte	-4
   034D 00                  140 	.byte	0
   034E E4                  141 	.byte	-28
   034F F9                  142 	.byte	-7
   0350 FF                  143 	.byte	-1
   0351 D8                  144 	.byte	-40
   0352 F6                  145 	.byte	-10
   0353 00                  146 	.byte	0
   0354 CC                  147 	.byte	-52
   0355 F3                  148 	.byte	-13
   0356 FF                  149 	.byte	-1
   0357 C0                  150 	.byte	-64
   0358 F0                  151 	.byte	-16
   0359 00                  152 	.byte	0
   035A B4                  153 	.byte	-76
   035B ED                  154 	.byte	-19
   035C FF                  155 	.byte	-1
   035D A8                  156 	.byte	-88
   035E EA                  157 	.byte	-22
   035F 00                  158 	.byte	0
   0360 9C                  159 	.byte	-100
   0361 E7                  160 	.byte	-25
   0362 FF                  161 	.byte	-1
   0363 90                  162 	.byte	-112
   0364 E4                  163 	.byte	-28
   0365 00                  164 	.byte	0
   0366 84                  165 	.byte	-124
   0367 E1                  166 	.byte	-31
   0368 FF                  167 	.byte	-1
   0369 BC                  168 	.byte	-68
   036A EF                  169 	.byte	-17
   036B FF                  170 	.byte	-1
   036C BC                  171 	.byte	-68
   036D EF                  172 	.byte	-17
   036E 00                  173 	.byte	0
   036F B6                  174 	.byte	-74
   0370 ED                  175 	.byte	-19
   0371 00                  176 	.byte	0
   0372 B6                  177 	.byte	-74
   0373 EE                  178 	.byte	-18
   0374 FF                  179 	.byte	-1
   0375 B0                  180 	.byte	-80
   0376 EC                  181 	.byte	-20
   0377 FF                  182 	.byte	-1
   0378 B0                  183 	.byte	-80
   0379 EC                  184 	.byte	-20
   037A 00                  185 	.byte	0
   037B AA                  186 	.byte	-86
   037C EA                  187 	.byte	-22
   037D 00                  188 	.byte	0
   037E AA                  189 	.byte	-86
   037F EB                  190 	.byte	-21
   0380 FF                  191 	.byte	-1
   0381 84                  192 	.byte	-124
   0382 E1                  193 	.byte	-31
   0383                     194 _vl_term_2_89:
   0383 01                  195 	.byte	1
                            196 	.globl	_vl_map_roadline_left_2
   0384                     197 _vl_map_roadline_left_2:
   0384 00                  198 	.byte	0
   0385 F8                  199 	.byte	-8
   0386 FE                  200 	.byte	-2
   0387 FF                  201 	.byte	-1
   0388 EC                  202 	.byte	-20
   0389 FB                  203 	.byte	-5
   038A 00                  204 	.byte	0
   038B DC                  205 	.byte	-36
   038C F7                  206 	.byte	-9
   038D FF                  207 	.byte	-1
   038E D4                  208 	.byte	-44
   038F F5                  209 	.byte	-11
   0390 00                  210 	.byte	0
   0391 C4                  211 	.byte	-60
   0392 F1                  212 	.byte	-15
   0393 FF                  213 	.byte	-1
   0394 BC                  214 	.byte	-68
   0395 EF                  215 	.byte	-17
   0396 00                  216 	.byte	0
   0397 AC                  217 	.byte	-84
   0398 EB                  218 	.byte	-21
   0399 FF                  219 	.byte	-1
   039A A4                  220 	.byte	-92
   039B E9                  221 	.byte	-23
   039C 00                  222 	.byte	0
   039D 94                  223 	.byte	-108
   039E E5                  224 	.byte	-27
   039F FF                  225 	.byte	-1
   03A0 8C                  226 	.byte	-116
   03A1 E3                  227 	.byte	-29
   03A2 00                  228 	.byte	0
   03A3 84                  229 	.byte	-124
   03A4 E1                  230 	.byte	-31
   03A5 00                  231 	.byte	0
   03A6 F8                  232 	.byte	-8
   03A7 FE                  233 	.byte	-2
   03A8 FF                  234 	.byte	-1
   03A9 B8                  235 	.byte	-72
   03AA EE                  236 	.byte	-18
   03AB FF                  237 	.byte	-1
   03AC BC                  238 	.byte	-68
   03AD EF                  239 	.byte	-17
   03AE 00                  240 	.byte	0
   03AF AE                  241 	.byte	-82
   03B0 EB                  242 	.byte	-21
   03B1 00                  243 	.byte	0
   03B2 B6                  244 	.byte	-74
   03B3 EE                  245 	.byte	-18
   03B4 FF                  246 	.byte	-1
   03B5 AC                  247 	.byte	-84
   03B6 EB                  248 	.byte	-21
   03B7 FF                  249 	.byte	-1
   03B8 B0                  250 	.byte	-80
   03B9 EC                  251 	.byte	-20
   03BA 00                  252 	.byte	0
   03BB A2                  253 	.byte	-94
   03BC E8                  254 	.byte	-24
   03BD 00                  255 	.byte	0
   03BE AA                  256 	.byte	-86
   03BF EB                  257 	.byte	-21
   03C0 FF                  258 	.byte	-1
   03C1 84                  259 	.byte	-124
   03C2 E1                  260 	.byte	-31
   03C3                     261 _vl_term_3_116:
   03C3 01                  262 	.byte	1
                            263 	.globl	_vl_map_roadline_left_3
   03C4                     264 _vl_map_roadline_left_3:
   03C4 00                  265 	.byte	0
   03C5 F0                  266 	.byte	-16
   03C6 FC                  267 	.byte	-4
   03C7 FF                  268 	.byte	-1
   03C8 E4                  269 	.byte	-28
   03C9 F9                  270 	.byte	-7
   03CA 00                  271 	.byte	0
   03CB D8                  272 	.byte	-40
   03CC F6                  273 	.byte	-10
   03CD FF                  274 	.byte	-1
   03CE CC                  275 	.byte	-52
   03CF F3                  276 	.byte	-13
   03D0 00                  277 	.byte	0
   03D1 C0                  278 	.byte	-64
   03D2 F0                  279 	.byte	-16
   03D3 FF                  280 	.byte	-1
   03D4 B4                  281 	.byte	-76
   03D5 ED                  282 	.byte	-19
   03D6 00                  283 	.byte	0
   03D7 A8                  284 	.byte	-88
   03D8 EA                  285 	.byte	-22
   03D9 FF                  286 	.byte	-1
   03DA 9C                  287 	.byte	-100
   03DB E7                  288 	.byte	-25
   03DC 00                  289 	.byte	0
   03DD 90                  290 	.byte	-112
   03DE E4                  291 	.byte	-28
   03DF FF                  292 	.byte	-1
   03E0 84                  293 	.byte	-124
   03E1 E1                  294 	.byte	-31
   03E2 00                  295 	.byte	0
   03E3 84                  296 	.byte	-124
   03E4 E1                  297 	.byte	-31
   03E5 00                  298 	.byte	0
   03E6 F4                  299 	.byte	-12
   03E7 FD                  300 	.byte	-3
   03E8 FF                  301 	.byte	-1
   03E9 B0                  302 	.byte	-80
   03EA EC                  303 	.byte	-20
   03EB FF                  304 	.byte	-1
   03EC BC                  305 	.byte	-68
   03ED EF                  306 	.byte	-17
   03EE 00                  307 	.byte	0
   03EF AA                  308 	.byte	-86
   03F0 EA                  309 	.byte	-22
   03F1 00                  310 	.byte	0
   03F2 B6                  311 	.byte	-74
   03F3 EE                  312 	.byte	-18
   03F4 FF                  313 	.byte	-1
   03F5 A4                  314 	.byte	-92
   03F6 E9                  315 	.byte	-23
   03F7 FF                  316 	.byte	-1
   03F8 B0                  317 	.byte	-80
   03F9 EC                  318 	.byte	-20
   03FA                     319 _vl_term_4_140:
   03FA 01                  320 	.byte	1
                            321 	.globl	_vl_map_roadline_left_4
   03FB                     322 _vl_map_roadline_left_4:
   03FB FF                  323 	.byte	-1
   03FC F8                  324 	.byte	-8
   03FD FE                  325 	.byte	-2
   03FE 00                  326 	.byte	0
   03FF F0                  327 	.byte	-16
   0400 FC                  328 	.byte	-4
   0401 FF                  329 	.byte	-1
   0402 E0                  330 	.byte	-32
   0403 F8                  331 	.byte	-8
   0404 00                  332 	.byte	0
   0405 D0                  333 	.byte	-48
   0406 F4                  334 	.byte	-12
   0407 FF                  335 	.byte	-1
   0408 C8                  336 	.byte	-56
   0409 F2                  337 	.byte	-14
   040A 00                  338 	.byte	0
   040B B8                  339 	.byte	-72
   040C EE                  340 	.byte	-18
   040D FF                  341 	.byte	-1
   040E B0                  342 	.byte	-80
   040F EC                  343 	.byte	-20
   0410 00                  344 	.byte	0
   0411 A0                  345 	.byte	-96
   0412 E8                  346 	.byte	-24
   0413 FF                  347 	.byte	-1
   0414 98                  348 	.byte	-104
   0415 E6                  349 	.byte	-26
   0416 00                  350 	.byte	0
   0417 88                  351 	.byte	-120
   0418 E2                  352 	.byte	-30
   0419 FF                  353 	.byte	-1
   041A 80                  354 	.byte	-128
   041B E0                  355 	.byte	-32
   041C 00                  356 	.byte	0
   041D 84                  357 	.byte	-124
   041E E1                  358 	.byte	-31
   041F 00                  359 	.byte	0
   0420 EC                  360 	.byte	-20
   0421 FB                  361 	.byte	-5
   0422 FF                  362 	.byte	-1
   0423 AC                  363 	.byte	-84
   0424 EB                  364 	.byte	-21
   0425 FF                  365 	.byte	-1
   0426 BC                  366 	.byte	-68
   0427 EF                  367 	.byte	-17
   0428 00                  368 	.byte	0
   0429 A2                  369 	.byte	-94
   042A E8                  370 	.byte	-24
   042B 00                  371 	.byte	0
   042C B6                  372 	.byte	-74
   042D EE                  373 	.byte	-18
   042E FF                  374 	.byte	-1
   042F A0                  375 	.byte	-96
   0430 E8                  376 	.byte	-24
   0431 FF                  377 	.byte	-1
   0432 B0                  378 	.byte	-80
   0433 EC                  379 	.byte	-20
   0434                     380 _vl_term_5_165:
   0434 01                  381 	.byte	1
                            382 	.globl	_step
                            383 	.area	.data
   C880                     384 _step:
   C880 00                  385 	.byte	0
                            386 	.area	.text
                            387 	.globl	_draw_step1
   0435                     388 _draw_step1:
   0435 BD F2 A5      [ 8]  389 	jsr	___Intensity_5F
   0438 BD 04 AC      [ 8]  390 	jsr	_draw_left
   043B 7D C8 A8      [ 7]  391 	tst	_the_map
   043E 26 10         [ 3]  392 	bne	L6
   0440 F6 C8 80      [ 5]  393 	ldb	_step
   0443 C1 02         [ 2]  394 	cmpb	#2	;cmpqi:
   0445 22 48         [ 3]  395 	bhi	L16
   0447 5C            [ 2]  396 	incb
   0448 F7 C8 80      [ 5]  397 	stb	_step
   044B                     398 L8:
   044B C6 19         [ 2]  399 	ldb	#25
   044D F7 C8 A8      [ 5]  400 	stb	_the_map
   0450                     401 L6:
   0450 BD F3 54      [ 8]  402 	jsr	___Reset0Ref
   0453 C6 7F         [ 2]  403 	ldb	#127
   0455 D7 04         [ 4]  404 	stb	*_dp_VIA_t1_cnt_lo
   0457 C6 24         [ 2]  405 	ldb	#36
   0459 E7 E2         [ 6]  406 	stb	,-s
   045B C6 FB         [ 2]  407 	ldb	#-5
   045D BD 08 14      [ 8]  408 	jsr	__Moveto_d
   0460 C6 10         [ 2]  409 	ldb	#16
   0462 D7 04         [ 4]  410 	stb	*_dp_VIA_t1_cnt_lo
   0464 32 61         [ 5]  411 	leas	1,s
   0466 F6 C8 80      [ 5]  412 	ldb	_step
   0469 C1 01         [ 2]  413 	cmpb	#1	;cmpqi:
   046B 27 27         [ 3]  414 	beq	L11
   046D 24 0C         [ 3]  415 	bhs	L17
   046F 8E 03 4A      [ 3]  416 	ldx	#_vl_map_roadline_left_1
   0472 BD F4 10      [ 8]  417 	jsr	___Draw_VLp
   0475                     418 L9:
   0475 7A C8 A8      [ 7]  419 	dec	_the_map
   0478 7E 04 CC      [ 4]  420 	jmp	_draw_right
   047B                     421 L17:
   047B C1 02         [ 2]  422 	cmpb	#2	;cmpqi:
   047D 27 21         [ 3]  423 	beq	L12
   047F C1 03         [ 2]  424 	cmpb	#3	;cmpqi:
   0481 26 F2         [ 3]  425 	bne	L9
   0483 8E 03 FB      [ 3]  426 	ldx	#_vl_map_roadline_left_4
   0486 BD F4 10      [ 8]  427 	jsr	___Draw_VLp
   0489 7A C8 A8      [ 7]  428 	dec	_the_map
   048C 7E 04 CC      [ 4]  429 	jmp	_draw_right
   048F                     430 L16:
   048F 7F C8 80      [ 7]  431 	clr	_step
   0492 20 B7         [ 3]  432 	bra	L8
   0494                     433 L11:
   0494 8E 03 84      [ 3]  434 	ldx	#_vl_map_roadline_left_2
   0497 BD F4 10      [ 8]  435 	jsr	___Draw_VLp
   049A 7A C8 A8      [ 7]  436 	dec	_the_map
   049D 7E 04 CC      [ 4]  437 	jmp	_draw_right
   04A0                     438 L12:
   04A0 8E 03 C4      [ 3]  439 	ldx	#_vl_map_roadline_left_3
   04A3 BD F4 10      [ 8]  440 	jsr	___Draw_VLp
   04A6 7A C8 A8      [ 7]  441 	dec	_the_map
   04A9 7E 04 CC      [ 4]  442 	jmp	_draw_right
                            443 	.globl	_draw_left
   04AC                     444 _draw_left:
   04AC BD F3 54      [ 8]  445 	jsr	___Reset0Ref
   04AF C6 7F         [ 2]  446 	ldb	#127
   04B1 D7 04         [ 4]  447 	stb	*_dp_VIA_t1_cnt_lo
   04B3 C6 24         [ 2]  448 	ldb	#36
   04B5 E7 E2         [ 6]  449 	stb	,-s
   04B7 C6 F1         [ 2]  450 	ldb	#-15
   04B9 BD 08 14      [ 8]  451 	jsr	__Moveto_d
   04BC C6 A8         [ 2]  452 	ldb	#-88
   04BE D7 04         [ 4]  453 	stb	*_dp_VIA_t1_cnt_lo
   04C0 C6 80         [ 2]  454 	ldb	#-128
   04C2 E7 E2         [ 6]  455 	stb	,-s
   04C4 CB 2E         [ 2]  456 	addb	#46
   04C6 BD 08 0F      [ 8]  457 	jsr	__Draw_Line_d
   04C9 32 62         [ 5]  458 	leas	2,s
   04CB 39            [ 5]  459 	rts
                            460 	.globl	_draw_right
   04CC                     461 _draw_right:
   04CC BD F3 54      [ 8]  462 	jsr	___Reset0Ref
   04CF C6 7F         [ 2]  463 	ldb	#127
   04D1 D7 04         [ 4]  464 	stb	*_dp_VIA_t1_cnt_lo
   04D3 C6 24         [ 2]  465 	ldb	#36
   04D5 E7 E2         [ 6]  466 	stb	,-s
   04D7 C6 0F         [ 2]  467 	ldb	#15
   04D9 BD 08 14      [ 8]  468 	jsr	__Moveto_d
   04DC C6 A8         [ 2]  469 	ldb	#-88
   04DE D7 04         [ 4]  470 	stb	*_dp_VIA_t1_cnt_lo
   04E0 C6 80         [ 2]  471 	ldb	#-128
   04E2 E7 E2         [ 6]  472 	stb	,-s
   04E4 C6 52         [ 2]  473 	ldb	#82
   04E6 BD 08 0F      [ 8]  474 	jsr	__Draw_Line_d
   04E9 32 62         [ 5]  475 	leas	2,s
   04EB 39            [ 5]  476 	rts
                            477 	.globl	_CNT_SPEED_LUT
   04EC                     478 _CNT_SPEED_LUT:
   04EC 00 00 00 00 00 00   479 	.word	0,0,0
   04F2 00                  480 	.byte	0
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Thu Jun 12 22:57:40 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L11                01C3 R   |   3 L12                01CF R
  3 L16                01BE R   |   3 L17                01AA R
  3 L6                 017F R   |   3 L8                 017A R
  3 L9                 01A4 R   |   3 _CNT_SPEED_LUT     021B GR
    __Draw_Line_d      **** GX  |     __Moveto_d         **** GX
    ___Draw_VLp        **** GX  |     ___Intensity_5     **** GX
    ___Reset0Ref       **** GX  |     _dp_VIA_t1_cnt     **** GX
  3 _draw_left         01DB GR  |   3 _draw_right        01FB GR
  3 _draw_step1        0164 GR  |   3 _dummy_tick        0000 GR
  3 _map_init          0001 GR  |   4 _step              0000 GR
  2 _the_map           0000 GR  |   3 _vl_map_roadli     0079 GR
  3 _vl_map_roadli     00B3 GR  |   3 _vl_map_roadli     00F3 GR
  3 _vl_map_roadli     012A GR  |   3 _vl_misc_roadl     000B GR
  3 _vl_misc_roadl     0042 GR  |   3 _vl_term_0_35      0041 R
  3 _vl_term_1_60      0078 R   |   3 _vl_term_2_89      00B2 R
  3 _vl_term_3_116     00F2 R   |   3 _vl_term_4_140     0129 R
  3 _vl_term_5_165     0163 R

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Thu Jun 12 22:57:40 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    3   flags    0
   3 .text            size  222   flags  100
   4 .data            size    1   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

