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
   02F0                      11 _CNT_DRAW1_LUT:
   02F0 06                   12 	.byte	6
   02F1 05                   13 	.byte	5
   02F2 04                   14 	.byte	4
   02F3 04                   15 	.byte	4
   02F4 03                   16 	.byte	3
   02F5 02                   17 	.byte	2
   02F6 02                   18 	.byte	2
   02F7 02                   19 	.byte	2
   02F8 01                   20 	.byte	1
   02F9 01                   21 	.byte	1
   02FA 00                   22 	.byte	0
                             23 	.globl	_CNT_DRAW2_LUT
   02FB                      24 _CNT_DRAW2_LUT:
   02FB 06                   25 	.byte	6
   02FC 05                   26 	.byte	5
   02FD 04                   27 	.byte	4
   02FE 03                   28 	.byte	3
   02FF 02                   29 	.byte	2
   0300 02                   30 	.byte	2
   0301 02                   31 	.byte	2
   0302 01                   32 	.byte	1
   0303 01                   33 	.byte	1
   0304 00                   34 	.byte	0
   0305 00                   35 	.byte	0
                             36 	.globl	_CNT_DRAW3_LUT
   0306                      37 _CNT_DRAW3_LUT:
   0306 06                   38 	.byte	6
   0307 05                   39 	.byte	5
   0308 04                   40 	.byte	4
   0309 03                   41 	.byte	3
   030A 03                   42 	.byte	3
   030B 02                   43 	.byte	2
   030C 01                   44 	.byte	1
   030D 02                   45 	.byte	2
   030E 01                   46 	.byte	1
   030F 01                   47 	.byte	1
   0310 00                   48 	.byte	0
                             49 	.globl	_CNT_DRAW4_LUT
   0311                      50 _CNT_DRAW4_LUT:
   0311 06                   51 	.byte	6
   0312 05                   52 	.byte	5
   0313 04                   53 	.byte	4
   0314 03                   54 	.byte	3
   0315 02                   55 	.byte	2
   0316 02                   56 	.byte	2
   0317 02                   57 	.byte	2
   0318 01                   58 	.byte	1
   0319 01                   59 	.byte	1
   031A 00                   60 	.byte	0
   031B 00                   61 	.byte	0
                             62 	.globl	_map_init
   031C                      63 _map_init:
   031C F6 C8 A4      [ 5]   64 	ldb	_the_game+2
   031F 4F            [ 2]   65 	clra		;zero_extendqihi: R:b -> R:d
   0320 1F 01         [ 6]   66 	tfr	d,x
   0322 E6 89 02 F0   [ 8]   67 	ldb	_CNT_DRAW1_LUT,x
   0326 8E 05 06      [ 3]   68 	ldx	#_draw_step1
   0329 BF C8 A8      [ 6]   69 	stx	_the_map+1
   032C F7 C8 A7      [ 5]   70 	stb	_the_map
   032F 39            [ 5]   71 	rts
                             72 	.globl	_vl_map_roadline_left_1
   0330                      73 _vl_map_roadline_left_1:
   0330 FF                   74 	.byte	-1
   0331 F0                   75 	.byte	-16
   0332 FC                   76 	.byte	-4
   0333 00                   77 	.byte	0
   0334 E4                   78 	.byte	-28
   0335 F9                   79 	.byte	-7
   0336 FF                   80 	.byte	-1
   0337 D8                   81 	.byte	-40
   0338 F6                   82 	.byte	-10
   0339 00                   83 	.byte	0
   033A CC                   84 	.byte	-52
   033B F3                   85 	.byte	-13
   033C FF                   86 	.byte	-1
   033D C0                   87 	.byte	-64
   033E F0                   88 	.byte	-16
   033F 00                   89 	.byte	0
   0340 B4                   90 	.byte	-76
   0341 ED                   91 	.byte	-19
   0342 FF                   92 	.byte	-1
   0343 A8                   93 	.byte	-88
   0344 EA                   94 	.byte	-22
   0345 00                   95 	.byte	0
   0346 9C                   96 	.byte	-100
   0347 E7                   97 	.byte	-25
   0348 FF                   98 	.byte	-1
   0349 90                   99 	.byte	-112
   034A E4                  100 	.byte	-28
   034B 00                  101 	.byte	0
   034C 84                  102 	.byte	-124
   034D E1                  103 	.byte	-31
   034E FF                  104 	.byte	-1
   034F BC                  105 	.byte	-68
   0350 EF                  106 	.byte	-17
   0351 FF                  107 	.byte	-1
   0352 BC                  108 	.byte	-68
   0353 EF                  109 	.byte	-17
   0354 00                  110 	.byte	0
   0355 B6                  111 	.byte	-74
   0356 ED                  112 	.byte	-19
   0357 00                  113 	.byte	0
   0358 B6                  114 	.byte	-74
   0359 EE                  115 	.byte	-18
   035A FF                  116 	.byte	-1
   035B B0                  117 	.byte	-80
   035C EC                  118 	.byte	-20
   035D FF                  119 	.byte	-1
   035E B0                  120 	.byte	-80
   035F EC                  121 	.byte	-20
   0360 00                  122 	.byte	0
   0361 AA                  123 	.byte	-86
   0362 EA                  124 	.byte	-22
   0363 00                  125 	.byte	0
   0364 AA                  126 	.byte	-86
   0365 EB                  127 	.byte	-21
   0366 FF                  128 	.byte	-1
   0367 84                  129 	.byte	-124
   0368 E1                  130 	.byte	-31
   0369                     131 _vl_term_0_37:
   0369 01                  132 	.byte	1
                            133 	.globl	_vl_map_roadline_left_2
   036A                     134 _vl_map_roadline_left_2:
   036A 00                  135 	.byte	0
   036B F8                  136 	.byte	-8
   036C FE                  137 	.byte	-2
   036D FF                  138 	.byte	-1
   036E EC                  139 	.byte	-20
   036F FB                  140 	.byte	-5
   0370 00                  141 	.byte	0
   0371 DC                  142 	.byte	-36
   0372 F7                  143 	.byte	-9
   0373 FF                  144 	.byte	-1
   0374 D4                  145 	.byte	-44
   0375 F5                  146 	.byte	-11
   0376 00                  147 	.byte	0
   0377 C4                  148 	.byte	-60
   0378 F1                  149 	.byte	-15
   0379 FF                  150 	.byte	-1
   037A BC                  151 	.byte	-68
   037B EF                  152 	.byte	-17
   037C 00                  153 	.byte	0
   037D AC                  154 	.byte	-84
   037E EB                  155 	.byte	-21
   037F FF                  156 	.byte	-1
   0380 A4                  157 	.byte	-92
   0381 E9                  158 	.byte	-23
   0382 00                  159 	.byte	0
   0383 94                  160 	.byte	-108
   0384 E5                  161 	.byte	-27
   0385 FF                  162 	.byte	-1
   0386 8C                  163 	.byte	-116
   0387 E3                  164 	.byte	-29
   0388 00                  165 	.byte	0
   0389 84                  166 	.byte	-124
   038A E1                  167 	.byte	-31
   038B 00                  168 	.byte	0
   038C F8                  169 	.byte	-8
   038D FE                  170 	.byte	-2
   038E FF                  171 	.byte	-1
   038F B8                  172 	.byte	-72
   0390 EE                  173 	.byte	-18
   0391 FF                  174 	.byte	-1
   0392 BC                  175 	.byte	-68
   0393 EF                  176 	.byte	-17
   0394 00                  177 	.byte	0
   0395 AE                  178 	.byte	-82
   0396 EB                  179 	.byte	-21
   0397 00                  180 	.byte	0
   0398 B6                  181 	.byte	-74
   0399 EE                  182 	.byte	-18
   039A FF                  183 	.byte	-1
   039B AC                  184 	.byte	-84
   039C EB                  185 	.byte	-21
   039D FF                  186 	.byte	-1
   039E B0                  187 	.byte	-80
   039F EC                  188 	.byte	-20
   03A0 00                  189 	.byte	0
   03A1 A2                  190 	.byte	-94
   03A2 E8                  191 	.byte	-24
   03A3 00                  192 	.byte	0
   03A4 AA                  193 	.byte	-86
   03A5 EB                  194 	.byte	-21
   03A6 FF                  195 	.byte	-1
   03A7 84                  196 	.byte	-124
   03A8 E1                  197 	.byte	-31
   03A9                     198 _vl_term_1_64:
   03A9 01                  199 	.byte	1
                            200 	.globl	_vl_map_roadline_left_3
   03AA                     201 _vl_map_roadline_left_3:
   03AA 00                  202 	.byte	0
   03AB F0                  203 	.byte	-16
   03AC FC                  204 	.byte	-4
   03AD FF                  205 	.byte	-1
   03AE E4                  206 	.byte	-28
   03AF F9                  207 	.byte	-7
   03B0 00                  208 	.byte	0
   03B1 D8                  209 	.byte	-40
   03B2 F6                  210 	.byte	-10
   03B3 FF                  211 	.byte	-1
   03B4 CC                  212 	.byte	-52
   03B5 F3                  213 	.byte	-13
   03B6 00                  214 	.byte	0
   03B7 C0                  215 	.byte	-64
   03B8 F0                  216 	.byte	-16
   03B9 FF                  217 	.byte	-1
   03BA B4                  218 	.byte	-76
   03BB ED                  219 	.byte	-19
   03BC 00                  220 	.byte	0
   03BD A8                  221 	.byte	-88
   03BE EA                  222 	.byte	-22
   03BF FF                  223 	.byte	-1
   03C0 9C                  224 	.byte	-100
   03C1 E7                  225 	.byte	-25
   03C2 00                  226 	.byte	0
   03C3 90                  227 	.byte	-112
   03C4 E4                  228 	.byte	-28
   03C5 FF                  229 	.byte	-1
   03C6 84                  230 	.byte	-124
   03C7 E1                  231 	.byte	-31
   03C8 00                  232 	.byte	0
   03C9 84                  233 	.byte	-124
   03CA E1                  234 	.byte	-31
   03CB 00                  235 	.byte	0
   03CC F4                  236 	.byte	-12
   03CD FD                  237 	.byte	-3
   03CE FF                  238 	.byte	-1
   03CF B0                  239 	.byte	-80
   03D0 EC                  240 	.byte	-20
   03D1 FF                  241 	.byte	-1
   03D2 BC                  242 	.byte	-68
   03D3 EF                  243 	.byte	-17
   03D4 00                  244 	.byte	0
   03D5 AA                  245 	.byte	-86
   03D6 EA                  246 	.byte	-22
   03D7 00                  247 	.byte	0
   03D8 B6                  248 	.byte	-74
   03D9 EE                  249 	.byte	-18
   03DA FF                  250 	.byte	-1
   03DB A4                  251 	.byte	-92
   03DC E9                  252 	.byte	-23
   03DD FF                  253 	.byte	-1
   03DE B0                  254 	.byte	-80
   03DF EC                  255 	.byte	-20
   03E0                     256 _vl_term_2_88:
   03E0 01                  257 	.byte	1
                            258 	.globl	_vl_map_roadline_left_4
   03E1                     259 _vl_map_roadline_left_4:
   03E1 FF                  260 	.byte	-1
   03E2 F8                  261 	.byte	-8
   03E3 FE                  262 	.byte	-2
   03E4 00                  263 	.byte	0
   03E5 F0                  264 	.byte	-16
   03E6 FC                  265 	.byte	-4
   03E7 FF                  266 	.byte	-1
   03E8 E0                  267 	.byte	-32
   03E9 F8                  268 	.byte	-8
   03EA 00                  269 	.byte	0
   03EB D0                  270 	.byte	-48
   03EC F4                  271 	.byte	-12
   03ED FF                  272 	.byte	-1
   03EE C8                  273 	.byte	-56
   03EF F2                  274 	.byte	-14
   03F0 00                  275 	.byte	0
   03F1 B8                  276 	.byte	-72
   03F2 EE                  277 	.byte	-18
   03F3 FF                  278 	.byte	-1
   03F4 B0                  279 	.byte	-80
   03F5 EC                  280 	.byte	-20
   03F6 00                  281 	.byte	0
   03F7 A0                  282 	.byte	-96
   03F8 E8                  283 	.byte	-24
   03F9 FF                  284 	.byte	-1
   03FA 98                  285 	.byte	-104
   03FB E6                  286 	.byte	-26
   03FC 00                  287 	.byte	0
   03FD 88                  288 	.byte	-120
   03FE E2                  289 	.byte	-30
   03FF FF                  290 	.byte	-1
   0400 81                  291 	.byte	-127
   0401 E0                  292 	.byte	-32
   0402 00                  293 	.byte	0
   0403 84                  294 	.byte	-124
   0404 E1                  295 	.byte	-31
   0405 00                  296 	.byte	0
   0406 EC                  297 	.byte	-20
   0407 FB                  298 	.byte	-5
   0408 FF                  299 	.byte	-1
   0409 AC                  300 	.byte	-84
   040A EB                  301 	.byte	-21
   040B FF                  302 	.byte	-1
   040C BC                  303 	.byte	-68
   040D EF                  304 	.byte	-17
   040E 00                  305 	.byte	0
   040F A2                  306 	.byte	-94
   0410 E8                  307 	.byte	-24
   0411 00                  308 	.byte	0
   0412 B6                  309 	.byte	-74
   0413 EE                  310 	.byte	-18
   0414 FF                  311 	.byte	-1
   0415 A0                  312 	.byte	-96
   0416 E8                  313 	.byte	-24
   0417 FF                  314 	.byte	-1
   0418 B0                  315 	.byte	-80
   0419 EC                  316 	.byte	-20
   041A                     317 _vl_term_3_113:
   041A 01                  318 	.byte	1
                            319 	.globl	_vl_map_roadline_right_1
   041B                     320 _vl_map_roadline_right_1:
   041B FF                  321 	.byte	-1
   041C F0                  322 	.byte	-16
   041D 04                  323 	.byte	4
   041E 00                  324 	.byte	0
   041F E4                  325 	.byte	-28
   0420 07                  326 	.byte	7
   0421 FF                  327 	.byte	-1
   0422 D8                  328 	.byte	-40
   0423 0A                  329 	.byte	10
   0424 00                  330 	.byte	0
   0425 CC                  331 	.byte	-52
   0426 0D                  332 	.byte	13
   0427 FF                  333 	.byte	-1
   0428 C0                  334 	.byte	-64
   0429 10                  335 	.byte	16
   042A 00                  336 	.byte	0
   042B B4                  337 	.byte	-76
   042C 13                  338 	.byte	19
   042D FF                  339 	.byte	-1
   042E A8                  340 	.byte	-88
   042F 16                  341 	.byte	22
   0430 00                  342 	.byte	0
   0431 9C                  343 	.byte	-100
   0432 19                  344 	.byte	25
   0433 FF                  345 	.byte	-1
   0434 90                  346 	.byte	-112
   0435 1C                  347 	.byte	28
   0436 00                  348 	.byte	0
   0437 84                  349 	.byte	-124
   0438 1F                  350 	.byte	31
   0439 FF                  351 	.byte	-1
   043A BC                  352 	.byte	-68
   043B 11                  353 	.byte	17
   043C FF                  354 	.byte	-1
   043D BC                  355 	.byte	-68
   043E 11                  356 	.byte	17
   043F 00                  357 	.byte	0
   0440 B6                  358 	.byte	-74
   0441 13                  359 	.byte	19
   0442 00                  360 	.byte	0
   0443 B6                  361 	.byte	-74
   0444 12                  362 	.byte	18
   0445 FF                  363 	.byte	-1
   0446 B0                  364 	.byte	-80
   0447 14                  365 	.byte	20
   0448 FF                  366 	.byte	-1
   0449 B0                  367 	.byte	-80
   044A 14                  368 	.byte	20
   044B 00                  369 	.byte	0
   044C AA                  370 	.byte	-86
   044D 16                  371 	.byte	22
   044E 00                  372 	.byte	0
   044F AA                  373 	.byte	-86
   0450 15                  374 	.byte	21
   0451 FF                  375 	.byte	-1
   0452 84                  376 	.byte	-124
   0453 1F                  377 	.byte	31
   0454                     378 _vl_term_4_145:
   0454 01                  379 	.byte	1
                            380 	.globl	_vl_map_roadline_right_2
   0455                     381 _vl_map_roadline_right_2:
   0455 00                  382 	.byte	0
   0456 F8                  383 	.byte	-8
   0457 02                  384 	.byte	2
   0458 FF                  385 	.byte	-1
   0459 EC                  386 	.byte	-20
   045A 05                  387 	.byte	5
   045B 00                  388 	.byte	0
   045C DC                  389 	.byte	-36
   045D 09                  390 	.byte	9
   045E FF                  391 	.byte	-1
   045F D4                  392 	.byte	-44
   0460 0B                  393 	.byte	11
   0461 00                  394 	.byte	0
   0462 C4                  395 	.byte	-60
   0463 0F                  396 	.byte	15
   0464 FF                  397 	.byte	-1
   0465 BC                  398 	.byte	-68
   0466 11                  399 	.byte	17
   0467 00                  400 	.byte	0
   0468 AC                  401 	.byte	-84
   0469 15                  402 	.byte	21
   046A FF                  403 	.byte	-1
   046B A4                  404 	.byte	-92
   046C 17                  405 	.byte	23
   046D 00                  406 	.byte	0
   046E 94                  407 	.byte	-108
   046F 1B                  408 	.byte	27
   0470 FF                  409 	.byte	-1
   0471 8C                  410 	.byte	-116
   0472 1D                  411 	.byte	29
   0473 00                  412 	.byte	0
   0474 84                  413 	.byte	-124
   0475 1F                  414 	.byte	31
   0476 00                  415 	.byte	0
   0477 F8                  416 	.byte	-8
   0478 02                  417 	.byte	2
   0479 FF                  418 	.byte	-1
   047A B8                  419 	.byte	-72
   047B 12                  420 	.byte	18
   047C FF                  421 	.byte	-1
   047D BC                  422 	.byte	-68
   047E 11                  423 	.byte	17
   047F 00                  424 	.byte	0
   0480 AE                  425 	.byte	-82
   0481 15                  426 	.byte	21
   0482 00                  427 	.byte	0
   0483 B6                  428 	.byte	-74
   0484 12                  429 	.byte	18
   0485 FF                  430 	.byte	-1
   0486 AC                  431 	.byte	-84
   0487 15                  432 	.byte	21
   0488 FF                  433 	.byte	-1
   0489 B0                  434 	.byte	-80
   048A 14                  435 	.byte	20
   048B 00                  436 	.byte	0
   048C A2                  437 	.byte	-94
   048D 18                  438 	.byte	24
   048E 00                  439 	.byte	0
   048F AA                  440 	.byte	-86
   0490 15                  441 	.byte	21
   0491 FF                  442 	.byte	-1
   0492 84                  443 	.byte	-124
   0493 1F                  444 	.byte	31
   0494                     445 _vl_term_5_172:
   0494 01                  446 	.byte	1
                            447 	.globl	_vl_map_roadline_right_3
   0495                     448 _vl_map_roadline_right_3:
   0495 00                  449 	.byte	0
   0496 F0                  450 	.byte	-16
   0497 04                  451 	.byte	4
   0498 FF                  452 	.byte	-1
   0499 E4                  453 	.byte	-28
   049A 07                  454 	.byte	7
   049B 00                  455 	.byte	0
   049C D8                  456 	.byte	-40
   049D 0A                  457 	.byte	10
   049E FF                  458 	.byte	-1
   049F CC                  459 	.byte	-52
   04A0 0D                  460 	.byte	13
   04A1 00                  461 	.byte	0
   04A2 C0                  462 	.byte	-64
   04A3 10                  463 	.byte	16
   04A4 FF                  464 	.byte	-1
   04A5 B4                  465 	.byte	-76
   04A6 13                  466 	.byte	19
   04A7 00                  467 	.byte	0
   04A8 A8                  468 	.byte	-88
   04A9 16                  469 	.byte	22
   04AA FF                  470 	.byte	-1
   04AB 9C                  471 	.byte	-100
   04AC 19                  472 	.byte	25
   04AD 00                  473 	.byte	0
   04AE 90                  474 	.byte	-112
   04AF 1C                  475 	.byte	28
   04B0 FF                  476 	.byte	-1
   04B1 84                  477 	.byte	-124
   04B2 1F                  478 	.byte	31
   04B3 00                  479 	.byte	0
   04B4 84                  480 	.byte	-124
   04B5 1F                  481 	.byte	31
   04B6 00                  482 	.byte	0
   04B7 F4                  483 	.byte	-12
   04B8 03                  484 	.byte	3
   04B9 FF                  485 	.byte	-1
   04BA B0                  486 	.byte	-80
   04BB 14                  487 	.byte	20
   04BC FF                  488 	.byte	-1
   04BD BC                  489 	.byte	-68
   04BE 11                  490 	.byte	17
   04BF 00                  491 	.byte	0
   04C0 AA                  492 	.byte	-86
   04C1 16                  493 	.byte	22
   04C2 00                  494 	.byte	0
   04C3 B6                  495 	.byte	-74
   04C4 12                  496 	.byte	18
   04C5 FF                  497 	.byte	-1
   04C6 A4                  498 	.byte	-92
   04C7 17                  499 	.byte	23
   04C8 FF                  500 	.byte	-1
   04C9 B0                  501 	.byte	-80
   04CA 14                  502 	.byte	20
   04CB                     503 _vl_term_6_196:
   04CB 01                  504 	.byte	1
                            505 	.globl	_vl_map_roadline_right_4
   04CC                     506 _vl_map_roadline_right_4:
   04CC FF                  507 	.byte	-1
   04CD F8                  508 	.byte	-8
   04CE 02                  509 	.byte	2
   04CF 00                  510 	.byte	0
   04D0 F0                  511 	.byte	-16
   04D1 04                  512 	.byte	4
   04D2 FF                  513 	.byte	-1
   04D3 E0                  514 	.byte	-32
   04D4 08                  515 	.byte	8
   04D5 00                  516 	.byte	0
   04D6 D0                  517 	.byte	-48
   04D7 0C                  518 	.byte	12
   04D8 FF                  519 	.byte	-1
   04D9 C8                  520 	.byte	-56
   04DA 0E                  521 	.byte	14
   04DB 00                  522 	.byte	0
   04DC B8                  523 	.byte	-72
   04DD 12                  524 	.byte	18
   04DE FF                  525 	.byte	-1
   04DF B0                  526 	.byte	-80
   04E0 14                  527 	.byte	20
   04E1 00                  528 	.byte	0
   04E2 A0                  529 	.byte	-96
   04E3 18                  530 	.byte	24
   04E4 FF                  531 	.byte	-1
   04E5 98                  532 	.byte	-104
   04E6 1A                  533 	.byte	26
   04E7 00                  534 	.byte	0
   04E8 88                  535 	.byte	-120
   04E9 1E                  536 	.byte	30
   04EA FF                  537 	.byte	-1
   04EB 81                  538 	.byte	-127
   04EC 20                  539 	.byte	32
   04ED 00                  540 	.byte	0
   04EE 84                  541 	.byte	-124
   04EF 1F                  542 	.byte	31
   04F0 00                  543 	.byte	0
   04F1 EC                  544 	.byte	-20
   04F2 05                  545 	.byte	5
   04F3 FF                  546 	.byte	-1
   04F4 AC                  547 	.byte	-84
   04F5 15                  548 	.byte	21
   04F6 FF                  549 	.byte	-1
   04F7 BC                  550 	.byte	-68
   04F8 11                  551 	.byte	17
   04F9 00                  552 	.byte	0
   04FA A2                  553 	.byte	-94
   04FB 18                  554 	.byte	24
   04FC 00                  555 	.byte	0
   04FD B6                  556 	.byte	-74
   04FE 12                  557 	.byte	18
   04FF FF                  558 	.byte	-1
   0500 A0                  559 	.byte	-96
   0501 18                  560 	.byte	24
   0502 FF                  561 	.byte	-1
   0503 B0                  562 	.byte	-80
   0504 14                  563 	.byte	20
   0505                     564 _vl_term_7_221:
   0505 01                  565 	.byte	1
                            566 	.globl	_draw_step1
   0506                     567 _draw_step1:
   0506 BD F2 A5      [ 8]  568 	jsr	___Intensity_5F
   0509 BD F3 54      [ 8]  569 	jsr	___Reset0Ref
   050C C6 7F         [ 2]  570 	ldb	#127
   050E D7 04         [ 4]  571 	stb	*_dp_VIA_t1_cnt_lo
   0510 C6 24         [ 2]  572 	ldb	#36
   0512 E7 E2         [ 6]  573 	stb	,-s
   0514 C6 F1         [ 2]  574 	ldb	#-15
   0516 BD 0A C1      [ 8]  575 	jsr	__Moveto_d
   0519 C6 A8         [ 2]  576 	ldb	#-88
   051B D7 04         [ 4]  577 	stb	*_dp_VIA_t1_cnt_lo
   051D C6 80         [ 2]  578 	ldb	#-128
   051F E7 E2         [ 6]  579 	stb	,-s
   0521 CB 2E         [ 2]  580 	addb	#46
   0523 BD 0A BC      [ 8]  581 	jsr	__Draw_Line_d
   0526 BD F3 54      [ 8]  582 	jsr	___Reset0Ref
   0529 C6 7F         [ 2]  583 	ldb	#127
   052B D7 04         [ 4]  584 	stb	*_dp_VIA_t1_cnt_lo
   052D C6 24         [ 2]  585 	ldb	#36
   052F E7 E2         [ 6]  586 	stb	,-s
   0531 C6 FB         [ 2]  587 	ldb	#-5
   0533 BD 0A C1      [ 8]  588 	jsr	__Moveto_d
   0536 C6 10         [ 2]  589 	ldb	#16
   0538 D7 04         [ 4]  590 	stb	*_dp_VIA_t1_cnt_lo
   053A 8E 03 30      [ 3]  591 	ldx	#_vl_map_roadline_left_1
   053D BD F4 10      [ 8]  592 	jsr	___Draw_VLp
   0540 BD F3 54      [ 8]  593 	jsr	___Reset0Ref
   0543 C6 7F         [ 2]  594 	ldb	#127
   0545 D7 04         [ 4]  595 	stb	*_dp_VIA_t1_cnt_lo
   0547 C6 24         [ 2]  596 	ldb	#36
   0549 E7 E2         [ 6]  597 	stb	,-s
   054B C6 05         [ 2]  598 	ldb	#5
   054D BD 0A C1      [ 8]  599 	jsr	__Moveto_d
   0550 C6 10         [ 2]  600 	ldb	#16
   0552 D7 04         [ 4]  601 	stb	*_dp_VIA_t1_cnt_lo
   0554 8E 04 1B      [ 3]  602 	ldx	#_vl_map_roadline_right_1
   0557 BD F4 10      [ 8]  603 	jsr	___Draw_VLp
   055A BD F3 54      [ 8]  604 	jsr	___Reset0Ref
   055D C6 7F         [ 2]  605 	ldb	#127
   055F D7 04         [ 4]  606 	stb	*_dp_VIA_t1_cnt_lo
   0561 C6 24         [ 2]  607 	ldb	#36
   0563 E7 E2         [ 6]  608 	stb	,-s
   0565 C6 0F         [ 2]  609 	ldb	#15
   0567 BD 0A C1      [ 8]  610 	jsr	__Moveto_d
   056A C6 A8         [ 2]  611 	ldb	#-88
   056C D7 04         [ 4]  612 	stb	*_dp_VIA_t1_cnt_lo
   056E C6 80         [ 2]  613 	ldb	#-128
   0570 E7 E2         [ 6]  614 	stb	,-s
   0572 C6 52         [ 2]  615 	ldb	#82
   0574 BD 0A BC      [ 8]  616 	jsr	__Draw_Line_d
   0577 F6 C8 A7      [ 5]  617 	ldb	_the_map
   057A 32 66         [ 5]  618 	leas	6,s
   057C 5D            [ 2]  619 	tstb
   057D 27 05         [ 3]  620 	beq	L8
   057F 5A            [ 2]  621 	decb
   0580 F7 C8 A7      [ 5]  622 	stb	_the_map
   0583 39            [ 5]  623 	rts
   0584                     624 L8:
   0584 8E 05 98      [ 3]  625 	ldx	#_draw_step2
   0587 BF C8 A8      [ 6]  626 	stx	_the_map+1
   058A F6 C8 A4      [ 5]  627 	ldb	_the_game+2
   058D 4F            [ 2]  628 	clra		;zero_extendqihi: R:b -> R:d
   058E 1F 01         [ 6]  629 	tfr	d,x
   0590 E6 89 02 FB   [ 8]  630 	ldb	_CNT_DRAW2_LUT,x
   0594 F7 C8 A7      [ 5]  631 	stb	_the_map
   0597 39            [ 5]  632 	rts
                            633 	.globl	_draw_step2
   0598                     634 _draw_step2:
   0598 BD F2 A5      [ 8]  635 	jsr	___Intensity_5F
   059B BD F3 54      [ 8]  636 	jsr	___Reset0Ref
   059E C6 7F         [ 2]  637 	ldb	#127
   05A0 D7 04         [ 4]  638 	stb	*_dp_VIA_t1_cnt_lo
   05A2 C6 24         [ 2]  639 	ldb	#36
   05A4 E7 E2         [ 6]  640 	stb	,-s
   05A6 C6 F1         [ 2]  641 	ldb	#-15
   05A8 BD 0A C1      [ 8]  642 	jsr	__Moveto_d
   05AB C6 A8         [ 2]  643 	ldb	#-88
   05AD D7 04         [ 4]  644 	stb	*_dp_VIA_t1_cnt_lo
   05AF C6 80         [ 2]  645 	ldb	#-128
   05B1 E7 E2         [ 6]  646 	stb	,-s
   05B3 CB 2E         [ 2]  647 	addb	#46
   05B5 BD 0A BC      [ 8]  648 	jsr	__Draw_Line_d
   05B8 BD F3 54      [ 8]  649 	jsr	___Reset0Ref
   05BB C6 7F         [ 2]  650 	ldb	#127
   05BD D7 04         [ 4]  651 	stb	*_dp_VIA_t1_cnt_lo
   05BF C6 24         [ 2]  652 	ldb	#36
   05C1 E7 E2         [ 6]  653 	stb	,-s
   05C3 C6 FB         [ 2]  654 	ldb	#-5
   05C5 BD 0A C1      [ 8]  655 	jsr	__Moveto_d
   05C8 C6 10         [ 2]  656 	ldb	#16
   05CA D7 04         [ 4]  657 	stb	*_dp_VIA_t1_cnt_lo
   05CC 8E 03 6A      [ 3]  658 	ldx	#_vl_map_roadline_left_2
   05CF BD F4 10      [ 8]  659 	jsr	___Draw_VLp
   05D2 BD F3 54      [ 8]  660 	jsr	___Reset0Ref
   05D5 C6 7F         [ 2]  661 	ldb	#127
   05D7 D7 04         [ 4]  662 	stb	*_dp_VIA_t1_cnt_lo
   05D9 C6 24         [ 2]  663 	ldb	#36
   05DB E7 E2         [ 6]  664 	stb	,-s
   05DD C6 05         [ 2]  665 	ldb	#5
   05DF BD 0A C1      [ 8]  666 	jsr	__Moveto_d
   05E2 C6 10         [ 2]  667 	ldb	#16
   05E4 D7 04         [ 4]  668 	stb	*_dp_VIA_t1_cnt_lo
   05E6 8E 04 55      [ 3]  669 	ldx	#_vl_map_roadline_right_2
   05E9 BD F4 10      [ 8]  670 	jsr	___Draw_VLp
   05EC BD F3 54      [ 8]  671 	jsr	___Reset0Ref
   05EF C6 7F         [ 2]  672 	ldb	#127
   05F1 D7 04         [ 4]  673 	stb	*_dp_VIA_t1_cnt_lo
   05F3 C6 24         [ 2]  674 	ldb	#36
   05F5 E7 E2         [ 6]  675 	stb	,-s
   05F7 C6 0F         [ 2]  676 	ldb	#15
   05F9 BD 0A C1      [ 8]  677 	jsr	__Moveto_d
   05FC C6 A8         [ 2]  678 	ldb	#-88
   05FE D7 04         [ 4]  679 	stb	*_dp_VIA_t1_cnt_lo
   0600 C6 80         [ 2]  680 	ldb	#-128
   0602 E7 E2         [ 6]  681 	stb	,-s
   0604 C6 52         [ 2]  682 	ldb	#82
   0606 BD 0A BC      [ 8]  683 	jsr	__Draw_Line_d
   0609 F6 C8 A7      [ 5]  684 	ldb	_the_map
   060C 32 66         [ 5]  685 	leas	6,s
   060E 5D            [ 2]  686 	tstb
   060F 27 05         [ 3]  687 	beq	L13
   0611 5A            [ 2]  688 	decb
   0612 F7 C8 A7      [ 5]  689 	stb	_the_map
   0615 39            [ 5]  690 	rts
   0616                     691 L13:
   0616 8E 06 2A      [ 3]  692 	ldx	#_draw_step3
   0619 BF C8 A8      [ 6]  693 	stx	_the_map+1
   061C F6 C8 A4      [ 5]  694 	ldb	_the_game+2
   061F 4F            [ 2]  695 	clra		;zero_extendqihi: R:b -> R:d
   0620 1F 01         [ 6]  696 	tfr	d,x
   0622 E6 89 03 06   [ 8]  697 	ldb	_CNT_DRAW3_LUT,x
   0626 F7 C8 A7      [ 5]  698 	stb	_the_map
   0629 39            [ 5]  699 	rts
                            700 	.globl	_draw_step3
   062A                     701 _draw_step3:
   062A BD F2 A5      [ 8]  702 	jsr	___Intensity_5F
   062D BD F3 54      [ 8]  703 	jsr	___Reset0Ref
   0630 C6 7F         [ 2]  704 	ldb	#127
   0632 D7 04         [ 4]  705 	stb	*_dp_VIA_t1_cnt_lo
   0634 C6 24         [ 2]  706 	ldb	#36
   0636 E7 E2         [ 6]  707 	stb	,-s
   0638 C6 F1         [ 2]  708 	ldb	#-15
   063A BD 0A C1      [ 8]  709 	jsr	__Moveto_d
   063D C6 A8         [ 2]  710 	ldb	#-88
   063F D7 04         [ 4]  711 	stb	*_dp_VIA_t1_cnt_lo
   0641 C6 80         [ 2]  712 	ldb	#-128
   0643 E7 E2         [ 6]  713 	stb	,-s
   0645 CB 2E         [ 2]  714 	addb	#46
   0647 BD 0A BC      [ 8]  715 	jsr	__Draw_Line_d
   064A BD F3 54      [ 8]  716 	jsr	___Reset0Ref
   064D C6 7F         [ 2]  717 	ldb	#127
   064F D7 04         [ 4]  718 	stb	*_dp_VIA_t1_cnt_lo
   0651 C6 24         [ 2]  719 	ldb	#36
   0653 E7 E2         [ 6]  720 	stb	,-s
   0655 C6 FB         [ 2]  721 	ldb	#-5
   0657 BD 0A C1      [ 8]  722 	jsr	__Moveto_d
   065A C6 10         [ 2]  723 	ldb	#16
   065C D7 04         [ 4]  724 	stb	*_dp_VIA_t1_cnt_lo
   065E 8E 03 AA      [ 3]  725 	ldx	#_vl_map_roadline_left_3
   0661 BD F4 10      [ 8]  726 	jsr	___Draw_VLp
   0664 BD F3 54      [ 8]  727 	jsr	___Reset0Ref
   0667 C6 7F         [ 2]  728 	ldb	#127
   0669 D7 04         [ 4]  729 	stb	*_dp_VIA_t1_cnt_lo
   066B C6 24         [ 2]  730 	ldb	#36
   066D E7 E2         [ 6]  731 	stb	,-s
   066F C6 05         [ 2]  732 	ldb	#5
   0671 BD 0A C1      [ 8]  733 	jsr	__Moveto_d
   0674 C6 10         [ 2]  734 	ldb	#16
   0676 D7 04         [ 4]  735 	stb	*_dp_VIA_t1_cnt_lo
   0678 8E 04 95      [ 3]  736 	ldx	#_vl_map_roadline_right_3
   067B BD F4 10      [ 8]  737 	jsr	___Draw_VLp
   067E BD F3 54      [ 8]  738 	jsr	___Reset0Ref
   0681 C6 7F         [ 2]  739 	ldb	#127
   0683 D7 04         [ 4]  740 	stb	*_dp_VIA_t1_cnt_lo
   0685 C6 24         [ 2]  741 	ldb	#36
   0687 E7 E2         [ 6]  742 	stb	,-s
   0689 C6 0F         [ 2]  743 	ldb	#15
   068B BD 0A C1      [ 8]  744 	jsr	__Moveto_d
   068E C6 A8         [ 2]  745 	ldb	#-88
   0690 D7 04         [ 4]  746 	stb	*_dp_VIA_t1_cnt_lo
   0692 C6 80         [ 2]  747 	ldb	#-128
   0694 E7 E2         [ 6]  748 	stb	,-s
   0696 C6 52         [ 2]  749 	ldb	#82
   0698 BD 0A BC      [ 8]  750 	jsr	__Draw_Line_d
   069B F6 C8 A7      [ 5]  751 	ldb	_the_map
   069E 32 66         [ 5]  752 	leas	6,s
   06A0 5D            [ 2]  753 	tstb
   06A1 27 05         [ 3]  754 	beq	L18
   06A3 5A            [ 2]  755 	decb
   06A4 F7 C8 A7      [ 5]  756 	stb	_the_map
   06A7 39            [ 5]  757 	rts
   06A8                     758 L18:
   06A8 8E 06 BC      [ 3]  759 	ldx	#_draw_step4
   06AB BF C8 A8      [ 6]  760 	stx	_the_map+1
   06AE F6 C8 A4      [ 5]  761 	ldb	_the_game+2
   06B1 4F            [ 2]  762 	clra		;zero_extendqihi: R:b -> R:d
   06B2 1F 01         [ 6]  763 	tfr	d,x
   06B4 E6 89 03 11   [ 8]  764 	ldb	_CNT_DRAW4_LUT,x
   06B8 F7 C8 A7      [ 5]  765 	stb	_the_map
   06BB 39            [ 5]  766 	rts
                            767 	.globl	_draw_step4
   06BC                     768 _draw_step4:
   06BC BD F2 A5      [ 8]  769 	jsr	___Intensity_5F
   06BF BD F3 54      [ 8]  770 	jsr	___Reset0Ref
   06C2 C6 7F         [ 2]  771 	ldb	#127
   06C4 D7 04         [ 4]  772 	stb	*_dp_VIA_t1_cnt_lo
   06C6 C6 24         [ 2]  773 	ldb	#36
   06C8 E7 E2         [ 6]  774 	stb	,-s
   06CA C6 F1         [ 2]  775 	ldb	#-15
   06CC BD 0A C1      [ 8]  776 	jsr	__Moveto_d
   06CF C6 A8         [ 2]  777 	ldb	#-88
   06D1 D7 04         [ 4]  778 	stb	*_dp_VIA_t1_cnt_lo
   06D3 C6 80         [ 2]  779 	ldb	#-128
   06D5 E7 E2         [ 6]  780 	stb	,-s
   06D7 CB 2E         [ 2]  781 	addb	#46
   06D9 BD 0A BC      [ 8]  782 	jsr	__Draw_Line_d
   06DC BD F3 54      [ 8]  783 	jsr	___Reset0Ref
   06DF C6 7F         [ 2]  784 	ldb	#127
   06E1 D7 04         [ 4]  785 	stb	*_dp_VIA_t1_cnt_lo
   06E3 C6 24         [ 2]  786 	ldb	#36
   06E5 E7 E2         [ 6]  787 	stb	,-s
   06E7 C6 FB         [ 2]  788 	ldb	#-5
   06E9 BD 0A C1      [ 8]  789 	jsr	__Moveto_d
   06EC C6 10         [ 2]  790 	ldb	#16
   06EE D7 04         [ 4]  791 	stb	*_dp_VIA_t1_cnt_lo
   06F0 8E 03 E1      [ 3]  792 	ldx	#_vl_map_roadline_left_4
   06F3 BD F4 10      [ 8]  793 	jsr	___Draw_VLp
   06F6 BD F3 54      [ 8]  794 	jsr	___Reset0Ref
   06F9 C6 7F         [ 2]  795 	ldb	#127
   06FB D7 04         [ 4]  796 	stb	*_dp_VIA_t1_cnt_lo
   06FD C6 24         [ 2]  797 	ldb	#36
   06FF E7 E2         [ 6]  798 	stb	,-s
   0701 C6 05         [ 2]  799 	ldb	#5
   0703 BD 0A C1      [ 8]  800 	jsr	__Moveto_d
   0706 C6 10         [ 2]  801 	ldb	#16
   0708 D7 04         [ 4]  802 	stb	*_dp_VIA_t1_cnt_lo
   070A 8E 04 CC      [ 3]  803 	ldx	#_vl_map_roadline_right_4
   070D BD F4 10      [ 8]  804 	jsr	___Draw_VLp
   0710 BD F3 54      [ 8]  805 	jsr	___Reset0Ref
   0713 C6 7F         [ 2]  806 	ldb	#127
   0715 D7 04         [ 4]  807 	stb	*_dp_VIA_t1_cnt_lo
   0717 C6 24         [ 2]  808 	ldb	#36
   0719 E7 E2         [ 6]  809 	stb	,-s
   071B C6 0F         [ 2]  810 	ldb	#15
   071D BD 0A C1      [ 8]  811 	jsr	__Moveto_d
   0720 C6 A8         [ 2]  812 	ldb	#-88
   0722 D7 04         [ 4]  813 	stb	*_dp_VIA_t1_cnt_lo
   0724 C6 80         [ 2]  814 	ldb	#-128
   0726 E7 E2         [ 6]  815 	stb	,-s
   0728 C6 52         [ 2]  816 	ldb	#82
   072A BD 0A BC      [ 8]  817 	jsr	__Draw_Line_d
   072D F6 C8 A7      [ 5]  818 	ldb	_the_map
   0730 32 66         [ 5]  819 	leas	6,s
   0732 5D            [ 2]  820 	tstb
   0733 27 05         [ 3]  821 	beq	L23
   0735 5A            [ 2]  822 	decb
   0736 F7 C8 A7      [ 5]  823 	stb	_the_map
   0739 39            [ 5]  824 	rts
   073A                     825 L23:
   073A 8E 05 06      [ 3]  826 	ldx	#_draw_step1
   073D BF C8 A8      [ 6]  827 	stx	_the_map+1
   0740 F6 C8 A4      [ 5]  828 	ldb	_the_game+2
   0743 4F            [ 2]  829 	clra		;zero_extendqihi: R:b -> R:d
   0744 1F 01         [ 6]  830 	tfr	d,x
   0746 E6 89 02 F0   [ 8]  831 	ldb	_CNT_DRAW1_LUT,x
   074A F7 C8 A7      [ 5]  832 	stb	_the_map
   074D 39            [ 5]  833 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri Jun 13 20:36:16 2025

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
Hexadecimal [16-Bits]                                 Fri Jun 13 20:36:16 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    3   flags    0
   3 .text            size  45E   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

