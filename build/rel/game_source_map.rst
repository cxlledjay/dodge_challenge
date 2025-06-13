                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	map.c
                              6 	.area	.bss
                              7 	.globl	_the_map
   C8A7                       8 _the_map:	.blkb	3
                              9 	.globl	_CNT_DRAW1_LUT
                             10 	.area	.text
   0314                      11 _CNT_DRAW1_LUT:
   0314 06                   12 	.byte	6
   0315 05                   13 	.byte	5
   0316 04                   14 	.byte	4
   0317 04                   15 	.byte	4
   0318 03                   16 	.byte	3
   0319 02                   17 	.byte	2
   031A 02                   18 	.byte	2
   031B 02                   19 	.byte	2
   031C 01                   20 	.byte	1
   031D 01                   21 	.byte	1
   031E 00                   22 	.byte	0
                             23 	.globl	_CNT_DRAW2_LUT
   031F                      24 _CNT_DRAW2_LUT:
   031F 06                   25 	.byte	6
   0320 05                   26 	.byte	5
   0321 04                   27 	.byte	4
   0322 03                   28 	.byte	3
   0323 02                   29 	.byte	2
   0324 02                   30 	.byte	2
   0325 02                   31 	.byte	2
   0326 01                   32 	.byte	1
   0327 01                   33 	.byte	1
   0328 00                   34 	.byte	0
   0329 00                   35 	.byte	0
                             36 	.globl	_CNT_DRAW3_LUT
   032A                      37 _CNT_DRAW3_LUT:
   032A 06                   38 	.byte	6
   032B 05                   39 	.byte	5
   032C 04                   40 	.byte	4
   032D 03                   41 	.byte	3
   032E 03                   42 	.byte	3
   032F 02                   43 	.byte	2
   0330 01                   44 	.byte	1
   0331 02                   45 	.byte	2
   0332 01                   46 	.byte	1
   0333 01                   47 	.byte	1
   0334 00                   48 	.byte	0
                             49 	.globl	_CNT_DRAW4_LUT
   0335                      50 _CNT_DRAW4_LUT:
   0335 06                   51 	.byte	6
   0336 05                   52 	.byte	5
   0337 04                   53 	.byte	4
   0338 03                   54 	.byte	3
   0339 02                   55 	.byte	2
   033A 02                   56 	.byte	2
   033B 02                   57 	.byte	2
   033C 01                   58 	.byte	1
   033D 01                   59 	.byte	1
   033E 00                   60 	.byte	0
   033F 00                   61 	.byte	0
                             62 	.globl	_map_init
   0340                      63 _map_init:
   0340 F6 C8 A4      [ 5]   64 	ldb	_the_game+2
   0343 4F            [ 2]   65 	clra		;zero_extendqihi: R:b -> R:d
   0344 1F 01         [ 6]   66 	tfr	d,x
   0346 E6 89 03 14   [ 8]   67 	ldb	_CNT_DRAW1_LUT,x
   034A 8E 05 2A      [ 3]   68 	ldx	#_draw_step1
   034D BF C8 A8      [ 6]   69 	stx	_the_map+1
   0350 F7 C8 A7      [ 5]   70 	stb	_the_map
   0353 39            [ 5]   71 	rts
                             72 	.globl	_vl_map_roadline_left_1
   0354                      73 _vl_map_roadline_left_1:
   0354 FF                   74 	.byte	-1
   0355 F0                   75 	.byte	-16
   0356 FC                   76 	.byte	-4
   0357 00                   77 	.byte	0
   0358 E4                   78 	.byte	-28
   0359 F9                   79 	.byte	-7
   035A FF                   80 	.byte	-1
   035B D8                   81 	.byte	-40
   035C F6                   82 	.byte	-10
   035D 00                   83 	.byte	0
   035E CC                   84 	.byte	-52
   035F F3                   85 	.byte	-13
   0360 FF                   86 	.byte	-1
   0361 C0                   87 	.byte	-64
   0362 F0                   88 	.byte	-16
   0363 00                   89 	.byte	0
   0364 B4                   90 	.byte	-76
   0365 ED                   91 	.byte	-19
   0366 FF                   92 	.byte	-1
   0367 A8                   93 	.byte	-88
   0368 EA                   94 	.byte	-22
   0369 00                   95 	.byte	0
   036A 9C                   96 	.byte	-100
   036B E7                   97 	.byte	-25
   036C FF                   98 	.byte	-1
   036D 90                   99 	.byte	-112
   036E E4                  100 	.byte	-28
   036F 00                  101 	.byte	0
   0370 84                  102 	.byte	-124
   0371 E1                  103 	.byte	-31
   0372 FF                  104 	.byte	-1
   0373 BC                  105 	.byte	-68
   0374 EF                  106 	.byte	-17
   0375 FF                  107 	.byte	-1
   0376 BC                  108 	.byte	-68
   0377 EF                  109 	.byte	-17
   0378 00                  110 	.byte	0
   0379 B6                  111 	.byte	-74
   037A ED                  112 	.byte	-19
   037B 00                  113 	.byte	0
   037C B6                  114 	.byte	-74
   037D EE                  115 	.byte	-18
   037E FF                  116 	.byte	-1
   037F B0                  117 	.byte	-80
   0380 EC                  118 	.byte	-20
   0381 FF                  119 	.byte	-1
   0382 B0                  120 	.byte	-80
   0383 EC                  121 	.byte	-20
   0384 00                  122 	.byte	0
   0385 AA                  123 	.byte	-86
   0386 EA                  124 	.byte	-22
   0387 00                  125 	.byte	0
   0388 AA                  126 	.byte	-86
   0389 EB                  127 	.byte	-21
   038A FF                  128 	.byte	-1
   038B 84                  129 	.byte	-124
   038C E1                  130 	.byte	-31
   038D                     131 _vl_term_0_37:
   038D 01                  132 	.byte	1
                            133 	.globl	_vl_map_roadline_left_2
   038E                     134 _vl_map_roadline_left_2:
   038E 00                  135 	.byte	0
   038F F8                  136 	.byte	-8
   0390 FE                  137 	.byte	-2
   0391 FF                  138 	.byte	-1
   0392 EC                  139 	.byte	-20
   0393 FB                  140 	.byte	-5
   0394 00                  141 	.byte	0
   0395 DC                  142 	.byte	-36
   0396 F7                  143 	.byte	-9
   0397 FF                  144 	.byte	-1
   0398 D4                  145 	.byte	-44
   0399 F5                  146 	.byte	-11
   039A 00                  147 	.byte	0
   039B C4                  148 	.byte	-60
   039C F1                  149 	.byte	-15
   039D FF                  150 	.byte	-1
   039E BC                  151 	.byte	-68
   039F EF                  152 	.byte	-17
   03A0 00                  153 	.byte	0
   03A1 AC                  154 	.byte	-84
   03A2 EB                  155 	.byte	-21
   03A3 FF                  156 	.byte	-1
   03A4 A4                  157 	.byte	-92
   03A5 E9                  158 	.byte	-23
   03A6 00                  159 	.byte	0
   03A7 94                  160 	.byte	-108
   03A8 E5                  161 	.byte	-27
   03A9 FF                  162 	.byte	-1
   03AA 8C                  163 	.byte	-116
   03AB E3                  164 	.byte	-29
   03AC 00                  165 	.byte	0
   03AD 84                  166 	.byte	-124
   03AE E1                  167 	.byte	-31
   03AF 00                  168 	.byte	0
   03B0 F8                  169 	.byte	-8
   03B1 FE                  170 	.byte	-2
   03B2 FF                  171 	.byte	-1
   03B3 B8                  172 	.byte	-72
   03B4 EE                  173 	.byte	-18
   03B5 FF                  174 	.byte	-1
   03B6 BC                  175 	.byte	-68
   03B7 EF                  176 	.byte	-17
   03B8 00                  177 	.byte	0
   03B9 AE                  178 	.byte	-82
   03BA EB                  179 	.byte	-21
   03BB 00                  180 	.byte	0
   03BC B6                  181 	.byte	-74
   03BD EE                  182 	.byte	-18
   03BE FF                  183 	.byte	-1
   03BF AC                  184 	.byte	-84
   03C0 EB                  185 	.byte	-21
   03C1 FF                  186 	.byte	-1
   03C2 B0                  187 	.byte	-80
   03C3 EC                  188 	.byte	-20
   03C4 00                  189 	.byte	0
   03C5 A2                  190 	.byte	-94
   03C6 E8                  191 	.byte	-24
   03C7 00                  192 	.byte	0
   03C8 AA                  193 	.byte	-86
   03C9 EB                  194 	.byte	-21
   03CA FF                  195 	.byte	-1
   03CB 84                  196 	.byte	-124
   03CC E1                  197 	.byte	-31
   03CD                     198 _vl_term_1_64:
   03CD 01                  199 	.byte	1
                            200 	.globl	_vl_map_roadline_left_3
   03CE                     201 _vl_map_roadline_left_3:
   03CE 00                  202 	.byte	0
   03CF F0                  203 	.byte	-16
   03D0 FC                  204 	.byte	-4
   03D1 FF                  205 	.byte	-1
   03D2 E4                  206 	.byte	-28
   03D3 F9                  207 	.byte	-7
   03D4 00                  208 	.byte	0
   03D5 D8                  209 	.byte	-40
   03D6 F6                  210 	.byte	-10
   03D7 FF                  211 	.byte	-1
   03D8 CC                  212 	.byte	-52
   03D9 F3                  213 	.byte	-13
   03DA 00                  214 	.byte	0
   03DB C0                  215 	.byte	-64
   03DC F0                  216 	.byte	-16
   03DD FF                  217 	.byte	-1
   03DE B4                  218 	.byte	-76
   03DF ED                  219 	.byte	-19
   03E0 00                  220 	.byte	0
   03E1 A8                  221 	.byte	-88
   03E2 EA                  222 	.byte	-22
   03E3 FF                  223 	.byte	-1
   03E4 9C                  224 	.byte	-100
   03E5 E7                  225 	.byte	-25
   03E6 00                  226 	.byte	0
   03E7 90                  227 	.byte	-112
   03E8 E4                  228 	.byte	-28
   03E9 FF                  229 	.byte	-1
   03EA 84                  230 	.byte	-124
   03EB E1                  231 	.byte	-31
   03EC 00                  232 	.byte	0
   03ED 84                  233 	.byte	-124
   03EE E1                  234 	.byte	-31
   03EF 00                  235 	.byte	0
   03F0 F4                  236 	.byte	-12
   03F1 FD                  237 	.byte	-3
   03F2 FF                  238 	.byte	-1
   03F3 B0                  239 	.byte	-80
   03F4 EC                  240 	.byte	-20
   03F5 FF                  241 	.byte	-1
   03F6 BC                  242 	.byte	-68
   03F7 EF                  243 	.byte	-17
   03F8 00                  244 	.byte	0
   03F9 AA                  245 	.byte	-86
   03FA EA                  246 	.byte	-22
   03FB 00                  247 	.byte	0
   03FC B6                  248 	.byte	-74
   03FD EE                  249 	.byte	-18
   03FE FF                  250 	.byte	-1
   03FF A4                  251 	.byte	-92
   0400 E9                  252 	.byte	-23
   0401 FF                  253 	.byte	-1
   0402 B0                  254 	.byte	-80
   0403 EC                  255 	.byte	-20
   0404                     256 _vl_term_2_88:
   0404 01                  257 	.byte	1
                            258 	.globl	_vl_map_roadline_left_4
   0405                     259 _vl_map_roadline_left_4:
   0405 FF                  260 	.byte	-1
   0406 F8                  261 	.byte	-8
   0407 FE                  262 	.byte	-2
   0408 00                  263 	.byte	0
   0409 F0                  264 	.byte	-16
   040A FC                  265 	.byte	-4
   040B FF                  266 	.byte	-1
   040C E0                  267 	.byte	-32
   040D F8                  268 	.byte	-8
   040E 00                  269 	.byte	0
   040F D0                  270 	.byte	-48
   0410 F4                  271 	.byte	-12
   0411 FF                  272 	.byte	-1
   0412 C8                  273 	.byte	-56
   0413 F2                  274 	.byte	-14
   0414 00                  275 	.byte	0
   0415 B8                  276 	.byte	-72
   0416 EE                  277 	.byte	-18
   0417 FF                  278 	.byte	-1
   0418 B0                  279 	.byte	-80
   0419 EC                  280 	.byte	-20
   041A 00                  281 	.byte	0
   041B A0                  282 	.byte	-96
   041C E8                  283 	.byte	-24
   041D FF                  284 	.byte	-1
   041E 98                  285 	.byte	-104
   041F E6                  286 	.byte	-26
   0420 00                  287 	.byte	0
   0421 88                  288 	.byte	-120
   0422 E2                  289 	.byte	-30
   0423 FF                  290 	.byte	-1
   0424 81                  291 	.byte	-127
   0425 E0                  292 	.byte	-32
   0426 00                  293 	.byte	0
   0427 84                  294 	.byte	-124
   0428 E1                  295 	.byte	-31
   0429 00                  296 	.byte	0
   042A EC                  297 	.byte	-20
   042B FB                  298 	.byte	-5
   042C FF                  299 	.byte	-1
   042D AC                  300 	.byte	-84
   042E EB                  301 	.byte	-21
   042F FF                  302 	.byte	-1
   0430 BC                  303 	.byte	-68
   0431 EF                  304 	.byte	-17
   0432 00                  305 	.byte	0
   0433 A2                  306 	.byte	-94
   0434 E8                  307 	.byte	-24
   0435 00                  308 	.byte	0
   0436 B6                  309 	.byte	-74
   0437 EE                  310 	.byte	-18
   0438 FF                  311 	.byte	-1
   0439 A0                  312 	.byte	-96
   043A E8                  313 	.byte	-24
   043B FF                  314 	.byte	-1
   043C B0                  315 	.byte	-80
   043D EC                  316 	.byte	-20
   043E                     317 _vl_term_3_113:
   043E 01                  318 	.byte	1
                            319 	.globl	_vl_map_roadline_right_1
   043F                     320 _vl_map_roadline_right_1:
   043F FF                  321 	.byte	-1
   0440 F0                  322 	.byte	-16
   0441 04                  323 	.byte	4
   0442 00                  324 	.byte	0
   0443 E4                  325 	.byte	-28
   0444 07                  326 	.byte	7
   0445 FF                  327 	.byte	-1
   0446 D8                  328 	.byte	-40
   0447 0A                  329 	.byte	10
   0448 00                  330 	.byte	0
   0449 CC                  331 	.byte	-52
   044A 0D                  332 	.byte	13
   044B FF                  333 	.byte	-1
   044C C0                  334 	.byte	-64
   044D 10                  335 	.byte	16
   044E 00                  336 	.byte	0
   044F B4                  337 	.byte	-76
   0450 13                  338 	.byte	19
   0451 FF                  339 	.byte	-1
   0452 A8                  340 	.byte	-88
   0453 16                  341 	.byte	22
   0454 00                  342 	.byte	0
   0455 9C                  343 	.byte	-100
   0456 19                  344 	.byte	25
   0457 FF                  345 	.byte	-1
   0458 90                  346 	.byte	-112
   0459 1C                  347 	.byte	28
   045A 00                  348 	.byte	0
   045B 84                  349 	.byte	-124
   045C 1F                  350 	.byte	31
   045D FF                  351 	.byte	-1
   045E BC                  352 	.byte	-68
   045F 11                  353 	.byte	17
   0460 FF                  354 	.byte	-1
   0461 BC                  355 	.byte	-68
   0462 11                  356 	.byte	17
   0463 00                  357 	.byte	0
   0464 B6                  358 	.byte	-74
   0465 13                  359 	.byte	19
   0466 00                  360 	.byte	0
   0467 B6                  361 	.byte	-74
   0468 12                  362 	.byte	18
   0469 FF                  363 	.byte	-1
   046A B0                  364 	.byte	-80
   046B 14                  365 	.byte	20
   046C FF                  366 	.byte	-1
   046D B0                  367 	.byte	-80
   046E 14                  368 	.byte	20
   046F 00                  369 	.byte	0
   0470 AA                  370 	.byte	-86
   0471 16                  371 	.byte	22
   0472 00                  372 	.byte	0
   0473 AA                  373 	.byte	-86
   0474 15                  374 	.byte	21
   0475 FF                  375 	.byte	-1
   0476 84                  376 	.byte	-124
   0477 1F                  377 	.byte	31
   0478                     378 _vl_term_4_145:
   0478 01                  379 	.byte	1
                            380 	.globl	_vl_map_roadline_right_2
   0479                     381 _vl_map_roadline_right_2:
   0479 00                  382 	.byte	0
   047A F8                  383 	.byte	-8
   047B 02                  384 	.byte	2
   047C FF                  385 	.byte	-1
   047D EC                  386 	.byte	-20
   047E 05                  387 	.byte	5
   047F 00                  388 	.byte	0
   0480 DC                  389 	.byte	-36
   0481 09                  390 	.byte	9
   0482 FF                  391 	.byte	-1
   0483 D4                  392 	.byte	-44
   0484 0B                  393 	.byte	11
   0485 00                  394 	.byte	0
   0486 C4                  395 	.byte	-60
   0487 0F                  396 	.byte	15
   0488 FF                  397 	.byte	-1
   0489 BC                  398 	.byte	-68
   048A 11                  399 	.byte	17
   048B 00                  400 	.byte	0
   048C AC                  401 	.byte	-84
   048D 15                  402 	.byte	21
   048E FF                  403 	.byte	-1
   048F A4                  404 	.byte	-92
   0490 17                  405 	.byte	23
   0491 00                  406 	.byte	0
   0492 94                  407 	.byte	-108
   0493 1B                  408 	.byte	27
   0494 FF                  409 	.byte	-1
   0495 8C                  410 	.byte	-116
   0496 1D                  411 	.byte	29
   0497 00                  412 	.byte	0
   0498 84                  413 	.byte	-124
   0499 1F                  414 	.byte	31
   049A 00                  415 	.byte	0
   049B F8                  416 	.byte	-8
   049C 02                  417 	.byte	2
   049D FF                  418 	.byte	-1
   049E B8                  419 	.byte	-72
   049F 12                  420 	.byte	18
   04A0 FF                  421 	.byte	-1
   04A1 BC                  422 	.byte	-68
   04A2 11                  423 	.byte	17
   04A3 00                  424 	.byte	0
   04A4 AE                  425 	.byte	-82
   04A5 15                  426 	.byte	21
   04A6 00                  427 	.byte	0
   04A7 B6                  428 	.byte	-74
   04A8 12                  429 	.byte	18
   04A9 FF                  430 	.byte	-1
   04AA AC                  431 	.byte	-84
   04AB 15                  432 	.byte	21
   04AC FF                  433 	.byte	-1
   04AD B0                  434 	.byte	-80
   04AE 14                  435 	.byte	20
   04AF 00                  436 	.byte	0
   04B0 A2                  437 	.byte	-94
   04B1 18                  438 	.byte	24
   04B2 00                  439 	.byte	0
   04B3 AA                  440 	.byte	-86
   04B4 15                  441 	.byte	21
   04B5 FF                  442 	.byte	-1
   04B6 84                  443 	.byte	-124
   04B7 1F                  444 	.byte	31
   04B8                     445 _vl_term_5_172:
   04B8 01                  446 	.byte	1
                            447 	.globl	_vl_map_roadline_right_3
   04B9                     448 _vl_map_roadline_right_3:
   04B9 00                  449 	.byte	0
   04BA F0                  450 	.byte	-16
   04BB 04                  451 	.byte	4
   04BC FF                  452 	.byte	-1
   04BD E4                  453 	.byte	-28
   04BE 07                  454 	.byte	7
   04BF 00                  455 	.byte	0
   04C0 D8                  456 	.byte	-40
   04C1 0A                  457 	.byte	10
   04C2 FF                  458 	.byte	-1
   04C3 CC                  459 	.byte	-52
   04C4 0D                  460 	.byte	13
   04C5 00                  461 	.byte	0
   04C6 C0                  462 	.byte	-64
   04C7 10                  463 	.byte	16
   04C8 FF                  464 	.byte	-1
   04C9 B4                  465 	.byte	-76
   04CA 13                  466 	.byte	19
   04CB 00                  467 	.byte	0
   04CC A8                  468 	.byte	-88
   04CD 16                  469 	.byte	22
   04CE FF                  470 	.byte	-1
   04CF 9C                  471 	.byte	-100
   04D0 19                  472 	.byte	25
   04D1 00                  473 	.byte	0
   04D2 90                  474 	.byte	-112
   04D3 1C                  475 	.byte	28
   04D4 FF                  476 	.byte	-1
   04D5 84                  477 	.byte	-124
   04D6 1F                  478 	.byte	31
   04D7 00                  479 	.byte	0
   04D8 84                  480 	.byte	-124
   04D9 1F                  481 	.byte	31
   04DA 00                  482 	.byte	0
   04DB F4                  483 	.byte	-12
   04DC 03                  484 	.byte	3
   04DD FF                  485 	.byte	-1
   04DE B0                  486 	.byte	-80
   04DF 14                  487 	.byte	20
   04E0 FF                  488 	.byte	-1
   04E1 BC                  489 	.byte	-68
   04E2 11                  490 	.byte	17
   04E3 00                  491 	.byte	0
   04E4 AA                  492 	.byte	-86
   04E5 16                  493 	.byte	22
   04E6 00                  494 	.byte	0
   04E7 B6                  495 	.byte	-74
   04E8 12                  496 	.byte	18
   04E9 FF                  497 	.byte	-1
   04EA A4                  498 	.byte	-92
   04EB 17                  499 	.byte	23
   04EC FF                  500 	.byte	-1
   04ED B0                  501 	.byte	-80
   04EE 14                  502 	.byte	20
   04EF                     503 _vl_term_6_196:
   04EF 01                  504 	.byte	1
                            505 	.globl	_vl_map_roadline_right_4
   04F0                     506 _vl_map_roadline_right_4:
   04F0 FF                  507 	.byte	-1
   04F1 F8                  508 	.byte	-8
   04F2 02                  509 	.byte	2
   04F3 00                  510 	.byte	0
   04F4 F0                  511 	.byte	-16
   04F5 04                  512 	.byte	4
   04F6 FF                  513 	.byte	-1
   04F7 E0                  514 	.byte	-32
   04F8 08                  515 	.byte	8
   04F9 00                  516 	.byte	0
   04FA D0                  517 	.byte	-48
   04FB 0C                  518 	.byte	12
   04FC FF                  519 	.byte	-1
   04FD C8                  520 	.byte	-56
   04FE 0E                  521 	.byte	14
   04FF 00                  522 	.byte	0
   0500 B8                  523 	.byte	-72
   0501 12                  524 	.byte	18
   0502 FF                  525 	.byte	-1
   0503 B0                  526 	.byte	-80
   0504 14                  527 	.byte	20
   0505 00                  528 	.byte	0
   0506 A0                  529 	.byte	-96
   0507 18                  530 	.byte	24
   0508 FF                  531 	.byte	-1
   0509 98                  532 	.byte	-104
   050A 1A                  533 	.byte	26
   050B 00                  534 	.byte	0
   050C 88                  535 	.byte	-120
   050D 1E                  536 	.byte	30
   050E FF                  537 	.byte	-1
   050F 81                  538 	.byte	-127
   0510 20                  539 	.byte	32
   0511 00                  540 	.byte	0
   0512 84                  541 	.byte	-124
   0513 1F                  542 	.byte	31
   0514 00                  543 	.byte	0
   0515 EC                  544 	.byte	-20
   0516 05                  545 	.byte	5
   0517 FF                  546 	.byte	-1
   0518 AC                  547 	.byte	-84
   0519 15                  548 	.byte	21
   051A FF                  549 	.byte	-1
   051B BC                  550 	.byte	-68
   051C 11                  551 	.byte	17
   051D 00                  552 	.byte	0
   051E A2                  553 	.byte	-94
   051F 18                  554 	.byte	24
   0520 00                  555 	.byte	0
   0521 B6                  556 	.byte	-74
   0522 12                  557 	.byte	18
   0523 FF                  558 	.byte	-1
   0524 A0                  559 	.byte	-96
   0525 18                  560 	.byte	24
   0526 FF                  561 	.byte	-1
   0527 B0                  562 	.byte	-80
   0528 14                  563 	.byte	20
   0529                     564 _vl_term_7_221:
   0529 01                  565 	.byte	1
                            566 	.globl	_draw_step1
   052A                     567 _draw_step1:
   052A BD F2 A5      [ 8]  568 	jsr	___Intensity_5F
   052D BD F3 54      [ 8]  569 	jsr	___Reset0Ref
   0530 C6 7F         [ 2]  570 	ldb	#127
   0532 D7 04         [ 4]  571 	stb	*_dp_VIA_t1_cnt_lo
   0534 C6 24         [ 2]  572 	ldb	#36
   0536 E7 E2         [ 6]  573 	stb	,-s
   0538 C6 F1         [ 2]  574 	ldb	#-15
   053A BD 0F 13      [ 8]  575 	jsr	__Moveto_d
   053D C6 A8         [ 2]  576 	ldb	#-88
   053F D7 04         [ 4]  577 	stb	*_dp_VIA_t1_cnt_lo
   0541 C6 80         [ 2]  578 	ldb	#-128
   0543 E7 E2         [ 6]  579 	stb	,-s
   0545 CB 2E         [ 2]  580 	addb	#46
   0547 BD 0F 0E      [ 8]  581 	jsr	__Draw_Line_d
   054A BD F3 54      [ 8]  582 	jsr	___Reset0Ref
   054D C6 7F         [ 2]  583 	ldb	#127
   054F D7 04         [ 4]  584 	stb	*_dp_VIA_t1_cnt_lo
   0551 C6 24         [ 2]  585 	ldb	#36
   0553 E7 E2         [ 6]  586 	stb	,-s
   0555 C6 FB         [ 2]  587 	ldb	#-5
   0557 BD 0F 13      [ 8]  588 	jsr	__Moveto_d
   055A C6 10         [ 2]  589 	ldb	#16
   055C D7 04         [ 4]  590 	stb	*_dp_VIA_t1_cnt_lo
   055E 8E 03 54      [ 3]  591 	ldx	#_vl_map_roadline_left_1
   0561 BD F4 10      [ 8]  592 	jsr	___Draw_VLp
   0564 BD F3 54      [ 8]  593 	jsr	___Reset0Ref
   0567 C6 7F         [ 2]  594 	ldb	#127
   0569 D7 04         [ 4]  595 	stb	*_dp_VIA_t1_cnt_lo
   056B C6 24         [ 2]  596 	ldb	#36
   056D E7 E2         [ 6]  597 	stb	,-s
   056F C6 05         [ 2]  598 	ldb	#5
   0571 BD 0F 13      [ 8]  599 	jsr	__Moveto_d
   0574 C6 10         [ 2]  600 	ldb	#16
   0576 D7 04         [ 4]  601 	stb	*_dp_VIA_t1_cnt_lo
   0578 8E 04 3F      [ 3]  602 	ldx	#_vl_map_roadline_right_1
   057B BD F4 10      [ 8]  603 	jsr	___Draw_VLp
   057E BD F3 54      [ 8]  604 	jsr	___Reset0Ref
   0581 C6 7F         [ 2]  605 	ldb	#127
   0583 D7 04         [ 4]  606 	stb	*_dp_VIA_t1_cnt_lo
   0585 C6 24         [ 2]  607 	ldb	#36
   0587 E7 E2         [ 6]  608 	stb	,-s
   0589 C6 0F         [ 2]  609 	ldb	#15
   058B BD 0F 13      [ 8]  610 	jsr	__Moveto_d
   058E C6 A8         [ 2]  611 	ldb	#-88
   0590 D7 04         [ 4]  612 	stb	*_dp_VIA_t1_cnt_lo
   0592 C6 80         [ 2]  613 	ldb	#-128
   0594 E7 E2         [ 6]  614 	stb	,-s
   0596 C6 52         [ 2]  615 	ldb	#82
   0598 BD 0F 0E      [ 8]  616 	jsr	__Draw_Line_d
   059B F6 C8 A7      [ 5]  617 	ldb	_the_map
   059E 32 66         [ 5]  618 	leas	6,s
   05A0 5D            [ 2]  619 	tstb
   05A1 27 05         [ 3]  620 	beq	L8
   05A3 5A            [ 2]  621 	decb
   05A4 F7 C8 A7      [ 5]  622 	stb	_the_map
   05A7 39            [ 5]  623 	rts
   05A8                     624 L8:
   05A8 8E 05 BC      [ 3]  625 	ldx	#_draw_step2
   05AB BF C8 A8      [ 6]  626 	stx	_the_map+1
   05AE F6 C8 A4      [ 5]  627 	ldb	_the_game+2
   05B1 4F            [ 2]  628 	clra		;zero_extendqihi: R:b -> R:d
   05B2 1F 01         [ 6]  629 	tfr	d,x
   05B4 E6 89 03 1F   [ 8]  630 	ldb	_CNT_DRAW2_LUT,x
   05B8 F7 C8 A7      [ 5]  631 	stb	_the_map
   05BB 39            [ 5]  632 	rts
                            633 	.globl	_draw_step2
   05BC                     634 _draw_step2:
   05BC BD F2 A5      [ 8]  635 	jsr	___Intensity_5F
   05BF BD F3 54      [ 8]  636 	jsr	___Reset0Ref
   05C2 C6 7F         [ 2]  637 	ldb	#127
   05C4 D7 04         [ 4]  638 	stb	*_dp_VIA_t1_cnt_lo
   05C6 C6 24         [ 2]  639 	ldb	#36
   05C8 E7 E2         [ 6]  640 	stb	,-s
   05CA C6 F1         [ 2]  641 	ldb	#-15
   05CC BD 0F 13      [ 8]  642 	jsr	__Moveto_d
   05CF C6 A8         [ 2]  643 	ldb	#-88
   05D1 D7 04         [ 4]  644 	stb	*_dp_VIA_t1_cnt_lo
   05D3 C6 80         [ 2]  645 	ldb	#-128
   05D5 E7 E2         [ 6]  646 	stb	,-s
   05D7 CB 2E         [ 2]  647 	addb	#46
   05D9 BD 0F 0E      [ 8]  648 	jsr	__Draw_Line_d
   05DC BD F3 54      [ 8]  649 	jsr	___Reset0Ref
   05DF C6 7F         [ 2]  650 	ldb	#127
   05E1 D7 04         [ 4]  651 	stb	*_dp_VIA_t1_cnt_lo
   05E3 C6 24         [ 2]  652 	ldb	#36
   05E5 E7 E2         [ 6]  653 	stb	,-s
   05E7 C6 FB         [ 2]  654 	ldb	#-5
   05E9 BD 0F 13      [ 8]  655 	jsr	__Moveto_d
   05EC C6 10         [ 2]  656 	ldb	#16
   05EE D7 04         [ 4]  657 	stb	*_dp_VIA_t1_cnt_lo
   05F0 8E 03 8E      [ 3]  658 	ldx	#_vl_map_roadline_left_2
   05F3 BD F4 10      [ 8]  659 	jsr	___Draw_VLp
   05F6 BD F3 54      [ 8]  660 	jsr	___Reset0Ref
   05F9 C6 7F         [ 2]  661 	ldb	#127
   05FB D7 04         [ 4]  662 	stb	*_dp_VIA_t1_cnt_lo
   05FD C6 24         [ 2]  663 	ldb	#36
   05FF E7 E2         [ 6]  664 	stb	,-s
   0601 C6 05         [ 2]  665 	ldb	#5
   0603 BD 0F 13      [ 8]  666 	jsr	__Moveto_d
   0606 C6 10         [ 2]  667 	ldb	#16
   0608 D7 04         [ 4]  668 	stb	*_dp_VIA_t1_cnt_lo
   060A 8E 04 79      [ 3]  669 	ldx	#_vl_map_roadline_right_2
   060D BD F4 10      [ 8]  670 	jsr	___Draw_VLp
   0610 BD F3 54      [ 8]  671 	jsr	___Reset0Ref
   0613 C6 7F         [ 2]  672 	ldb	#127
   0615 D7 04         [ 4]  673 	stb	*_dp_VIA_t1_cnt_lo
   0617 C6 24         [ 2]  674 	ldb	#36
   0619 E7 E2         [ 6]  675 	stb	,-s
   061B C6 0F         [ 2]  676 	ldb	#15
   061D BD 0F 13      [ 8]  677 	jsr	__Moveto_d
   0620 C6 A8         [ 2]  678 	ldb	#-88
   0622 D7 04         [ 4]  679 	stb	*_dp_VIA_t1_cnt_lo
   0624 C6 80         [ 2]  680 	ldb	#-128
   0626 E7 E2         [ 6]  681 	stb	,-s
   0628 C6 52         [ 2]  682 	ldb	#82
   062A BD 0F 0E      [ 8]  683 	jsr	__Draw_Line_d
   062D F6 C8 A7      [ 5]  684 	ldb	_the_map
   0630 32 66         [ 5]  685 	leas	6,s
   0632 5D            [ 2]  686 	tstb
   0633 27 05         [ 3]  687 	beq	L13
   0635 5A            [ 2]  688 	decb
   0636 F7 C8 A7      [ 5]  689 	stb	_the_map
   0639 39            [ 5]  690 	rts
   063A                     691 L13:
   063A 8E 06 4E      [ 3]  692 	ldx	#_draw_step3
   063D BF C8 A8      [ 6]  693 	stx	_the_map+1
   0640 F6 C8 A4      [ 5]  694 	ldb	_the_game+2
   0643 4F            [ 2]  695 	clra		;zero_extendqihi: R:b -> R:d
   0644 1F 01         [ 6]  696 	tfr	d,x
   0646 E6 89 03 2A   [ 8]  697 	ldb	_CNT_DRAW3_LUT,x
   064A F7 C8 A7      [ 5]  698 	stb	_the_map
   064D 39            [ 5]  699 	rts
                            700 	.globl	_draw_step3
   064E                     701 _draw_step3:
   064E BD F2 A5      [ 8]  702 	jsr	___Intensity_5F
   0651 BD F3 54      [ 8]  703 	jsr	___Reset0Ref
   0654 C6 7F         [ 2]  704 	ldb	#127
   0656 D7 04         [ 4]  705 	stb	*_dp_VIA_t1_cnt_lo
   0658 C6 24         [ 2]  706 	ldb	#36
   065A E7 E2         [ 6]  707 	stb	,-s
   065C C6 F1         [ 2]  708 	ldb	#-15
   065E BD 0F 13      [ 8]  709 	jsr	__Moveto_d
   0661 C6 A8         [ 2]  710 	ldb	#-88
   0663 D7 04         [ 4]  711 	stb	*_dp_VIA_t1_cnt_lo
   0665 C6 80         [ 2]  712 	ldb	#-128
   0667 E7 E2         [ 6]  713 	stb	,-s
   0669 CB 2E         [ 2]  714 	addb	#46
   066B BD 0F 0E      [ 8]  715 	jsr	__Draw_Line_d
   066E BD F3 54      [ 8]  716 	jsr	___Reset0Ref
   0671 C6 7F         [ 2]  717 	ldb	#127
   0673 D7 04         [ 4]  718 	stb	*_dp_VIA_t1_cnt_lo
   0675 C6 24         [ 2]  719 	ldb	#36
   0677 E7 E2         [ 6]  720 	stb	,-s
   0679 C6 FB         [ 2]  721 	ldb	#-5
   067B BD 0F 13      [ 8]  722 	jsr	__Moveto_d
   067E C6 10         [ 2]  723 	ldb	#16
   0680 D7 04         [ 4]  724 	stb	*_dp_VIA_t1_cnt_lo
   0682 8E 03 CE      [ 3]  725 	ldx	#_vl_map_roadline_left_3
   0685 BD F4 10      [ 8]  726 	jsr	___Draw_VLp
   0688 BD F3 54      [ 8]  727 	jsr	___Reset0Ref
   068B C6 7F         [ 2]  728 	ldb	#127
   068D D7 04         [ 4]  729 	stb	*_dp_VIA_t1_cnt_lo
   068F C6 24         [ 2]  730 	ldb	#36
   0691 E7 E2         [ 6]  731 	stb	,-s
   0693 C6 05         [ 2]  732 	ldb	#5
   0695 BD 0F 13      [ 8]  733 	jsr	__Moveto_d
   0698 C6 10         [ 2]  734 	ldb	#16
   069A D7 04         [ 4]  735 	stb	*_dp_VIA_t1_cnt_lo
   069C 8E 04 B9      [ 3]  736 	ldx	#_vl_map_roadline_right_3
   069F BD F4 10      [ 8]  737 	jsr	___Draw_VLp
   06A2 BD F3 54      [ 8]  738 	jsr	___Reset0Ref
   06A5 C6 7F         [ 2]  739 	ldb	#127
   06A7 D7 04         [ 4]  740 	stb	*_dp_VIA_t1_cnt_lo
   06A9 C6 24         [ 2]  741 	ldb	#36
   06AB E7 E2         [ 6]  742 	stb	,-s
   06AD C6 0F         [ 2]  743 	ldb	#15
   06AF BD 0F 13      [ 8]  744 	jsr	__Moveto_d
   06B2 C6 A8         [ 2]  745 	ldb	#-88
   06B4 D7 04         [ 4]  746 	stb	*_dp_VIA_t1_cnt_lo
   06B6 C6 80         [ 2]  747 	ldb	#-128
   06B8 E7 E2         [ 6]  748 	stb	,-s
   06BA C6 52         [ 2]  749 	ldb	#82
   06BC BD 0F 0E      [ 8]  750 	jsr	__Draw_Line_d
   06BF F6 C8 A7      [ 5]  751 	ldb	_the_map
   06C2 32 66         [ 5]  752 	leas	6,s
   06C4 5D            [ 2]  753 	tstb
   06C5 27 05         [ 3]  754 	beq	L18
   06C7 5A            [ 2]  755 	decb
   06C8 F7 C8 A7      [ 5]  756 	stb	_the_map
   06CB 39            [ 5]  757 	rts
   06CC                     758 L18:
   06CC 8E 06 E0      [ 3]  759 	ldx	#_draw_step4
   06CF BF C8 A8      [ 6]  760 	stx	_the_map+1
   06D2 F6 C8 A4      [ 5]  761 	ldb	_the_game+2
   06D5 4F            [ 2]  762 	clra		;zero_extendqihi: R:b -> R:d
   06D6 1F 01         [ 6]  763 	tfr	d,x
   06D8 E6 89 03 35   [ 8]  764 	ldb	_CNT_DRAW4_LUT,x
   06DC F7 C8 A7      [ 5]  765 	stb	_the_map
   06DF 39            [ 5]  766 	rts
                            767 	.globl	_draw_step4
   06E0                     768 _draw_step4:
   06E0 BD F2 A5      [ 8]  769 	jsr	___Intensity_5F
   06E3 BD F3 54      [ 8]  770 	jsr	___Reset0Ref
   06E6 C6 7F         [ 2]  771 	ldb	#127
   06E8 D7 04         [ 4]  772 	stb	*_dp_VIA_t1_cnt_lo
   06EA C6 24         [ 2]  773 	ldb	#36
   06EC E7 E2         [ 6]  774 	stb	,-s
   06EE C6 F1         [ 2]  775 	ldb	#-15
   06F0 BD 0F 13      [ 8]  776 	jsr	__Moveto_d
   06F3 C6 A8         [ 2]  777 	ldb	#-88
   06F5 D7 04         [ 4]  778 	stb	*_dp_VIA_t1_cnt_lo
   06F7 C6 80         [ 2]  779 	ldb	#-128
   06F9 E7 E2         [ 6]  780 	stb	,-s
   06FB CB 2E         [ 2]  781 	addb	#46
   06FD BD 0F 0E      [ 8]  782 	jsr	__Draw_Line_d
   0700 BD F3 54      [ 8]  783 	jsr	___Reset0Ref
   0703 C6 7F         [ 2]  784 	ldb	#127
   0705 D7 04         [ 4]  785 	stb	*_dp_VIA_t1_cnt_lo
   0707 C6 24         [ 2]  786 	ldb	#36
   0709 E7 E2         [ 6]  787 	stb	,-s
   070B C6 FB         [ 2]  788 	ldb	#-5
   070D BD 0F 13      [ 8]  789 	jsr	__Moveto_d
   0710 C6 10         [ 2]  790 	ldb	#16
   0712 D7 04         [ 4]  791 	stb	*_dp_VIA_t1_cnt_lo
   0714 8E 04 05      [ 3]  792 	ldx	#_vl_map_roadline_left_4
   0717 BD F4 10      [ 8]  793 	jsr	___Draw_VLp
   071A BD F3 54      [ 8]  794 	jsr	___Reset0Ref
   071D C6 7F         [ 2]  795 	ldb	#127
   071F D7 04         [ 4]  796 	stb	*_dp_VIA_t1_cnt_lo
   0721 C6 24         [ 2]  797 	ldb	#36
   0723 E7 E2         [ 6]  798 	stb	,-s
   0725 C6 05         [ 2]  799 	ldb	#5
   0727 BD 0F 13      [ 8]  800 	jsr	__Moveto_d
   072A C6 10         [ 2]  801 	ldb	#16
   072C D7 04         [ 4]  802 	stb	*_dp_VIA_t1_cnt_lo
   072E 8E 04 F0      [ 3]  803 	ldx	#_vl_map_roadline_right_4
   0731 BD F4 10      [ 8]  804 	jsr	___Draw_VLp
   0734 BD F3 54      [ 8]  805 	jsr	___Reset0Ref
   0737 C6 7F         [ 2]  806 	ldb	#127
   0739 D7 04         [ 4]  807 	stb	*_dp_VIA_t1_cnt_lo
   073B C6 24         [ 2]  808 	ldb	#36
   073D E7 E2         [ 6]  809 	stb	,-s
   073F C6 0F         [ 2]  810 	ldb	#15
   0741 BD 0F 13      [ 8]  811 	jsr	__Moveto_d
   0744 C6 A8         [ 2]  812 	ldb	#-88
   0746 D7 04         [ 4]  813 	stb	*_dp_VIA_t1_cnt_lo
   0748 C6 80         [ 2]  814 	ldb	#-128
   074A E7 E2         [ 6]  815 	stb	,-s
   074C C6 52         [ 2]  816 	ldb	#82
   074E BD 0F 0E      [ 8]  817 	jsr	__Draw_Line_d
   0751 F6 C8 A7      [ 5]  818 	ldb	_the_map
   0754 32 66         [ 5]  819 	leas	6,s
   0756 5D            [ 2]  820 	tstb
   0757 27 05         [ 3]  821 	beq	L23
   0759 5A            [ 2]  822 	decb
   075A F7 C8 A7      [ 5]  823 	stb	_the_map
   075D 39            [ 5]  824 	rts
   075E                     825 L23:
   075E 8E 05 2A      [ 3]  826 	ldx	#_draw_step1
   0761 BF C8 A8      [ 6]  827 	stx	_the_map+1
   0764 F6 C8 A4      [ 5]  828 	ldb	_the_game+2
   0767 4F            [ 2]  829 	clra		;zero_extendqihi: R:b -> R:d
   0768 1F 01         [ 6]  830 	tfr	d,x
   076A E6 89 03 14   [ 8]  831 	ldb	_CNT_DRAW1_LUT,x
   076E F7 C8 A7      [ 5]  832 	stb	_the_map
   0771 39            [ 5]  833 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri Jun 13 23:47:53 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L13                0326 R   |   3 L18                03B8 R
  3 L23                044A R   |   3 L8                 0294 R
  3 _CNT_DRAW1_LUT     0000 GR  |   3 _CNT_DRAW2_LUT     000B GR
  3 _CNT_DRAW3_LUT     0016 GR  |   3 _CNT_DRAW4_LUT     0021 GR
    __Draw_Line_d      **** GX  |     __Moveto_d         **** GX
    ___Draw_VLp        **** GX  |     ___Intensity_5     **** GX
    ___Reset0Ref       **** GX  |     _dp_VIA_t1_cnt     **** GX
  3 _draw_step1        0216 GR  |   3 _draw_step2        02A8 GR
  3 _draw_step3        033A GR  |   3 _draw_step4        03CC GR
  3 _map_init          002C GR  |     _the_game          **** GX
  2 _the_map           0000 GR  |   3 _vl_map_roadli     0040 GR
  3 _vl_map_roadli     007A GR  |   3 _vl_map_roadli     00BA GR
  3 _vl_map_roadli     00F1 GR  |   3 _vl_map_roadli     012B GR
  3 _vl_map_roadli     0165 GR  |   3 _vl_map_roadli     01A5 GR
  3 _vl_map_roadli     01DC GR  |   3 _vl_term_0_37      0079 R
  3 _vl_term_1_64      00B9 R   |   3 _vl_term_2_88      00F0 R
  3 _vl_term_3_113     012A R   |   3 _vl_term_4_145     0164 R
  3 _vl_term_5_172     01A4 R   |   3 _vl_term_6_196     01DB R
  3 _vl_term_7_221     0215 R

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Fri Jun 13 23:47:53 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    3   flags    0
   3 .text            size  45E   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

