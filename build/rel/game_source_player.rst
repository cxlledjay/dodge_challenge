                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	player.c
                              6 	.area	.bss
                              7 	.globl	_the_player
   C8AA                       8 _the_player:	.blkb	4
                              9 	.globl	_PLAYER_X_LUT
                             10 	.area	.text
   02DC                      11 _PLAYER_X_LUT:
   02DC AE                   12 	.byte	-82
   02DD 00                   13 	.byte	0
   02DE 52                   14 	.byte	82
                             15 	.globl	_PLAYER_DRAW_LUT
   02DF                      16 _PLAYER_DRAW_LUT:
   02DF 05 C5                17 	.word	__player_draw_left
   02E1 05 CF                18 	.word	__player_draw_mid
   02E3 05 D9                19 	.word	__player_draw_right
                             20 	.globl	_player_init
   02E5                      21 _player_init:
   02E5 8E 02 F4      [ 3]   22 	ldx	#_player_draw
   02E8 BF C8 AC      [ 6]   23 	stx	_the_player+2
   02EB 7F C8 AB      [ 7]   24 	clr	_the_player+1
   02EE C6 01         [ 2]   25 	ldb	#1
   02F0 F7 C8 AA      [ 5]   26 	stb	_the_player
   02F3 39            [ 5]   27 	rts
                             28 	.globl	_player_draw
   02F4                      29 _player_draw:
   02F4 32 7E         [ 5]   30 	leas	-2,s
   02F6 BD F2 A5      [ 8]   31 	jsr	___Intensity_5F
   02F9 BD F3 54      [ 8]   32 	jsr	___Reset0Ref
   02FC C6 7F         [ 2]   33 	ldb	#127
   02FE D7 04         [ 4]   34 	stb	*_dp_VIA_t1_cnt_lo
   0300 F6 C8 AA      [ 5]   35 	ldb	_the_player
   0303 4F            [ 2]   36 	clra		;zero_extendqihi: R:b -> R:d
   0304 1F 01         [ 6]   37 	tfr	d,x
   0306 C6 90         [ 2]   38 	ldb	#-112
   0308 E7 E2         [ 6]   39 	stb	,-s
   030A E6 89 02 DC   [ 8]   40 	ldb	_PLAYER_X_LUT,x
   030E BD 05 F8      [ 8]   41 	jsr	__Moveto_d
   0311 F6 C8 AA      [ 5]   42 	ldb	_the_player
   0314 4F            [ 2]   43 	clra		;zero_extendqihi: R:b -> R:d
   0315 ED 61         [ 6]   44 	std	1,s
   0317 58            [ 2]   45 	aslb
   0318 49            [ 2]   46 	rola
   0319 1F 01         [ 6]   47 	tfr	d,x
   031B AD 99 02 DF   [14]   48 	jsr	[_PLAYER_DRAW_LUT,x]
   031F 32 63         [ 5]   49 	leas	3,s
   0321 39            [ 5]   50 	rts
                             51 	.globl	_player_change_left
   0322                      52 _player_change_left:
   0322 F6 C8 AA      [ 5]   53 	ldb	_the_player
   0325 27 04         [ 3]   54 	beq	L6
   0327 5A            [ 2]   55 	decb
   0328 F7 C8 AA      [ 5]   56 	stb	_the_player
   032B                      57 L6:
   032B 8E 02 F4      [ 3]   58 	ldx	#_player_draw
   032E BF C8 AC      [ 6]   59 	stx	_the_player+2
   0331 7E 02 F4      [ 4]   60 	jmp	_player_draw
                             61 	.globl	_player_change_right
   0334                      62 _player_change_right:
   0334 F6 C8 AA      [ 5]   63 	ldb	_the_player
   0337 C1 02         [ 2]   64 	cmpb	#2	;cmpqi:
   0339 27 04         [ 3]   65 	beq	L10
   033B 5C            [ 2]   66 	incb
   033C F7 C8 AA      [ 5]   67 	stb	_the_player
   033F                      68 L10:
   033F 8E 02 F4      [ 3]   69 	ldx	#_player_draw
   0342 BF C8 AC      [ 6]   70 	stx	_the_player+2
   0345 7E 02 F4      [ 4]   71 	jmp	_player_draw
                             72 	.globl	_check_collision
   0348                      73 _check_collision:
   0348 39            [ 5]   74 	rts
                             75 	.globl	_vl_player_mid
   0349                      76 _vl_player_mid:
   0349 00                   77 	.byte	0
   034A A0                   78 	.byte	-96
   034B B0                   79 	.byte	-80
   034C FF                   80 	.byte	-1
   034D 00                   81 	.byte	0
   034E B0                   82 	.byte	-80
   034F FF                   83 	.byte	-1
   0350 7F                   84 	.byte	127
   0351 00                   85 	.byte	0
   0352 FF                   86 	.byte	-1
   0353 00                   87 	.byte	0
   0354 50                   88 	.byte	80
   0355 FF                   89 	.byte	-1
   0356 80                   90 	.byte	-128
   0357 00                   91 	.byte	0
   0358 00                   92 	.byte	0
   0359 10                   93 	.byte	16
   035A 00                   94 	.byte	0
   035B FF                   95 	.byte	-1
   035C 10                   96 	.byte	16
   035D 3C                   97 	.byte	60
   035E 00                   98 	.byte	0
   035F 00                   99 	.byte	0
   0360 28                  100 	.byte	40
   0361 FF                  101 	.byte	-1
   0362 F0                  102 	.byte	-16
   0363 3C                  103 	.byte	60
   0364 00                  104 	.byte	0
   0365 F0                  105 	.byte	-16
   0366 00                  106 	.byte	0
   0367 FF                  107 	.byte	-1
   0368 00                  108 	.byte	0
   0369 50                  109 	.byte	80
   036A FF                  110 	.byte	-1
   036B 7F                  111 	.byte	127
   036C 00                  112 	.byte	0
   036D FF                  113 	.byte	-1
   036E 00                  114 	.byte	0
   036F B0                  115 	.byte	-80
   0370 FF                  116 	.byte	-1
   0371 80                  117 	.byte	-128
   0372 00                  118 	.byte	0
   0373 00                  119 	.byte	0
   0374 20                  120 	.byte	32
   0375 00                  121 	.byte	0
   0376 FF                  122 	.byte	-1
   0377 00                  123 	.byte	0
   0378 B0                  124 	.byte	-80
   0379 FF                  125 	.byte	-1
   037A 00                  126 	.byte	0
   037B B0                  127 	.byte	-80
   037C 00                  128 	.byte	0
   037D 40                  129 	.byte	64
   037E 00                  130 	.byte	0
   037F FF                  131 	.byte	-1
   0380 10                  132 	.byte	16
   0381 3C                  133 	.byte	60
   0382 FF                  134 	.byte	-1
   0383 00                  135 	.byte	0
   0384 28                  136 	.byte	40
   0385 FF                  137 	.byte	-1
   0386 F0                  138 	.byte	-16
   0387 3C                  139 	.byte	60
   0388 FF                  140 	.byte	-1
   0389 70                  141 	.byte	112
   038A C0                  142 	.byte	-64
   038B FF                  143 	.byte	-1
   038C 00                  144 	.byte	0
   038D E0                  145 	.byte	-32
   038E 00                  146 	.byte	0
   038F E4                  147 	.byte	-28
   0390 30                  148 	.byte	48
   0391 FF                  149 	.byte	-1
   0392 00                  150 	.byte	0
   0393 30                  151 	.byte	48
   0394 FF                  152 	.byte	-1
   0395 10                  153 	.byte	16
   0396 F8                  154 	.byte	-8
   0397 FF                  155 	.byte	-1
   0398 00                  156 	.byte	0
   0399 D0                  157 	.byte	-48
   039A 00                  158 	.byte	0
   039B 00                  159 	.byte	0
   039C D0                  160 	.byte	-48
   039D FF                  161 	.byte	-1
   039E 00                  162 	.byte	0
   039F D0                  163 	.byte	-48
   03A0 FF                  164 	.byte	-1
   03A1 F0                  165 	.byte	-16
   03A2 F8                  166 	.byte	-8
   03A3 FF                  167 	.byte	-1
   03A4 00                  168 	.byte	0
   03A5 30                  169 	.byte	48
   03A6 00                  170 	.byte	0
   03A7 1C                  171 	.byte	28
   03A8 10                  172 	.byte	16
   03A9 FF                  173 	.byte	-1
   03AA 90                  174 	.byte	-112
   03AB C0                  175 	.byte	-64
   03AC 00                  176 	.byte	0
   03AD 20                  177 	.byte	32
   03AE D8                  178 	.byte	-40
   03AF FF                  179 	.byte	-1
   03B0 28                  180 	.byte	40
   03B1 00                  181 	.byte	0
   03B2 FF                  182 	.byte	-1
   03B3 00                  183 	.byte	0
   03B4 3C                  184 	.byte	60
   03B5 FF                  185 	.byte	-1
   03B6 DC                  186 	.byte	-36
   03B7 00                  187 	.byte	0
   03B8 00                  188 	.byte	0
   03B9 00                  189 	.byte	0
   03BA 78                  190 	.byte	120
   03BB FF                  191 	.byte	-1
   03BC 24                  192 	.byte	36
   03BD 00                  193 	.byte	0
   03BE FF                  194 	.byte	-1
   03BF 00                  195 	.byte	0
   03C0 3C                  196 	.byte	60
   03C1 FF                  197 	.byte	-1
   03C2 D8                  198 	.byte	-40
   03C3 00                  199 	.byte	0
   03C4 00                  200 	.byte	0
   03C5 14                  201 	.byte	20
   03C6 9C                  202 	.byte	-100
   03C7 FF                  203 	.byte	-1
   03C8 10                  204 	.byte	16
   03C9 F8                  205 	.byte	-8
   03CA FF                  206 	.byte	-1
   03CB 00                  207 	.byte	0
   03CC E8                  208 	.byte	-24
   03CD FF                  209 	.byte	-1
   03CE F0                  210 	.byte	-16
   03CF F8                  211 	.byte	-8
   03D0                     212 _vl_term_0_76:
   03D0 01                  213 	.byte	1
                            214 	.globl	_vl_player_left
   03D1                     215 _vl_player_left:
   03D1 00                  216 	.byte	0
   03D2 0C                  217 	.byte	12
   03D3 78                  218 	.byte	120
   03D4 FF                  219 	.byte	-1
   03D5 88                  220 	.byte	-120
   03D6 00                  221 	.byte	0
   03D7 FF                  222 	.byte	-1
   03D8 DC                  223 	.byte	-36
   03D9 18                  224 	.byte	24
   03DA FF                  225 	.byte	-1
   03DB 00                  226 	.byte	0
   03DC 78                  227 	.byte	120
   03DD FF                  228 	.byte	-1
   03DE 24                  229 	.byte	36
   03DF 18                  230 	.byte	24
   03E0 FF                  231 	.byte	-1
   03E1 78                  232 	.byte	120
   03E2 00                  233 	.byte	0
   03E3 FF                  234 	.byte	-1
   03E4 24                  235 	.byte	36
   03E5 E8                  236 	.byte	-24
   03E6 FF                  237 	.byte	-1
   03E7 00                  238 	.byte	0
   03E8 88                  239 	.byte	-120
   03E9 FF                  240 	.byte	-1
   03EA DC                  241 	.byte	-36
   03EB E8                  242 	.byte	-24
   03EC 00                  243 	.byte	0
   03ED F4                  244 	.byte	-12
   03EE 00                  245 	.byte	0
   03EF FF                  246 	.byte	-1
   03F0 18                  247 	.byte	24
   03F1 A6                  248 	.byte	-90
   03F2 FF                  249 	.byte	-1
   03F3 00                  250 	.byte	0
   03F4 C4                  251 	.byte	-60
   03F5 FF                  252 	.byte	-1
   03F6 E8                  253 	.byte	-24
   03F7 A6                  254 	.byte	-90
   03F8 00                  255 	.byte	0
   03F9 0C                  256 	.byte	12
   03FA 00                  257 	.byte	0
   03FB FF                  258 	.byte	-1
   03FC 88                  259 	.byte	-120
   03FD 00                  260 	.byte	0
   03FE FF                  261 	.byte	-1
   03FF DC                  262 	.byte	-36
   0400 18                  263 	.byte	24
   0401 FF                  264 	.byte	-1
   0402 24                  265 	.byte	36
   0403 18                  266 	.byte	24
   0404 FF                  267 	.byte	-1
   0405 0C                  268 	.byte	12
   0406 00                  269 	.byte	0
   0407 00                  270 	.byte	0
   0408 E8                  271 	.byte	-24
   0409 DC                  272 	.byte	-36
   040A FF                  273 	.byte	-1
   040B 18                  274 	.byte	24
   040C 4E                  275 	.byte	78
   040D 00                  276 	.byte	0
   040E 00                  277 	.byte	0
   040F A6                  278 	.byte	-90
   0410 FF                  279 	.byte	-1
   0411 00                  280 	.byte	0
   0412 78                  281 	.byte	120
   0413 FF                  282 	.byte	-1
   0414 00                  283 	.byte	0
   0415 78                  284 	.byte	120
   0416 00                  285 	.byte	0
   0417 00                  286 	.byte	0
   0418 A6                  287 	.byte	-90
   0419 FF                  288 	.byte	-1
   041A E8                  289 	.byte	-24
   041B 60                  290 	.byte	96
   041C 00                  291 	.byte	0
   041D F4                  292 	.byte	-12
   041E 45                  293 	.byte	69
   041F 00                  294 	.byte	0
   0420 F4                  295 	.byte	-12
   0421 45                  296 	.byte	69
   0422 FF                  297 	.byte	-1
   0423 24                  298 	.byte	36
   0424 E8                  299 	.byte	-24
   0425 FF                  300 	.byte	-1
   0426 78                  301 	.byte	120
   0427 00                  302 	.byte	0
   0428 FF                  303 	.byte	-1
   0429 24                  304 	.byte	36
   042A 18                  305 	.byte	24
   042B 00                  306 	.byte	0
   042C D0                  307 	.byte	-48
   042D 18                  308 	.byte	24
   042E FF                  309 	.byte	-1
   042F 00                  310 	.byte	0
   0430 1E                  311 	.byte	30
   0431 FF                  312 	.byte	-1
   0432 18                  313 	.byte	24
   0433 0C                  314 	.byte	12
   0434 FF                  315 	.byte	-1
   0435 54                  316 	.byte	84
   0436 00                  317 	.byte	0
   0437 FF                  318 	.byte	-1
   0438 18                  319 	.byte	24
   0439 F4                  320 	.byte	-12
   043A FF                  321 	.byte	-1
   043B E8                  322 	.byte	-24
   043C F4                  323 	.byte	-12
   043D FF                  324 	.byte	-1
   043E AC                  325 	.byte	-84
   043F 00                  326 	.byte	0
   0440 FF                  327 	.byte	-1
   0441 E8                  328 	.byte	-24
   0442 0C                  329 	.byte	12
   0443 00                  330 	.byte	0
   0444 45                  331 	.byte	69
   0445 00                  332 	.byte	0
   0446 00                  333 	.byte	0
   0447 45                  334 	.byte	69
   0448 00                  335 	.byte	0
   0449 FF                  336 	.byte	-1
   044A 00                  337 	.byte	0
   044B 94                  338 	.byte	-108
   044C FF                  339 	.byte	-1
   044D E8                  340 	.byte	-24
   044E F4                  341 	.byte	-12
   044F FF                  342 	.byte	-1
   0450 C4                  343 	.byte	-60
   0451 00                  344 	.byte	0
   0452 00                  345 	.byte	0
   0453 00                  346 	.byte	0
   0454 E2                  347 	.byte	-30
   0455 FF                  348 	.byte	-1
   0456 2A                  349 	.byte	42
   0457 1E                  350 	.byte	30
   0458 00                  351 	.byte	0
   0459 2A                  352 	.byte	42
   045A 18                  353 	.byte	24
   045B FF                  354 	.byte	-1
   045C 3C                  355 	.byte	60
   045D 2A                  356 	.byte	42
   045E 00                  357 	.byte	0
   045F F4                  358 	.byte	-12
   0460 F4                  359 	.byte	-12
   0461 FF                  360 	.byte	-1
   0462 00                  361 	.byte	0
   0463 30                  362 	.byte	48
   0464 FF                  363 	.byte	-1
   0465 E8                  364 	.byte	-24
   0466 F4                  365 	.byte	-12
   0467 FF                  366 	.byte	-1
   0468 00                  367 	.byte	0
   0469 D0                  368 	.byte	-48
   046A 00                  369 	.byte	0
   046B 24                  370 	.byte	36
   046C 18                  371 	.byte	24
   046D FF                  372 	.byte	-1
   046E 00                  373 	.byte	0
   046F C4                  374 	.byte	-60
   0470 00                  375 	.byte	0
   0471 F4                  376 	.byte	-12
   0472 EE                  377 	.byte	-18
   0473 FF                  378 	.byte	-1
   0474 00                  379 	.byte	0
   0475 D0                  380 	.byte	-48
   0476 FF                  381 	.byte	-1
   0477 E8                  382 	.byte	-24
   0478 DC                  383 	.byte	-36
   0479 FF                  384 	.byte	-1
   047A 00                  385 	.byte	0
   047B 2A                  386 	.byte	42
   047C 00                  387 	.byte	0
   047D 24                  388 	.byte	36
   047E 3C                  389 	.byte	60
   047F FF                  390 	.byte	-1
   0480 C0                  391 	.byte	-64
   0481 94                  392 	.byte	-108
   0482 FF                  393 	.byte	-1
   0483 C0                  394 	.byte	-64
   0484 94                  395 	.byte	-108
   0485 FF                  396 	.byte	-1
   0486 C0                  397 	.byte	-64
   0487 94                  398 	.byte	-108
   0488 00                  399 	.byte	0
   0489 0C                  400 	.byte	12
   048A 00                  401 	.byte	0
   048B FF                  402 	.byte	-1
   048C 24                  403 	.byte	36
   048D 18                  404 	.byte	24
   048E FF                  405 	.byte	-1
   048F E8                  406 	.byte	-24
   0490 12                  407 	.byte	18
   0491 00                  408 	.byte	0
   0492 AC                  409 	.byte	-84
   0493 F7                  410 	.byte	-9
   0494 00                  411 	.byte	0
   0495 AC                  412 	.byte	-84
   0496 F7                  413 	.byte	-9
   0497 FF                  414 	.byte	-1
   0498 00                  415 	.byte	0
   0499 88                  416 	.byte	-120
   049A FF                  417 	.byte	-1
   049B 24                  418 	.byte	36
   049C E8                  419 	.byte	-24
   049D FF                  420 	.byte	-1
   049E 78                  421 	.byte	120
   049F 00                  422 	.byte	0
   04A0 FF                  423 	.byte	-1
   04A1 24                  424 	.byte	36
   04A2 18                  425 	.byte	24
   04A3 FF                  426 	.byte	-1
   04A4 00                  427 	.byte	0
   04A5 78                  428 	.byte	120
   04A6 00                  429 	.byte	0
   04A7 FA                  430 	.byte	-6
   04A8 2A                  431 	.byte	42
   04A9 FF                  432 	.byte	-1
   04AA 48                  433 	.byte	72
   04AB 00                  434 	.byte	0
   04AC FF                  435 	.byte	-1
   04AD 18                  436 	.byte	24
   04AE 0C                  437 	.byte	12
   04AF FF                  438 	.byte	-1
   04B0 00                  439 	.byte	0
   04B1 6C                  440 	.byte	108
   04B2 FF                  441 	.byte	-1
   04B3 E8                  442 	.byte	-24
   04B4 F4                  443 	.byte	-12
   04B5 FF                  444 	.byte	-1
   04B6 F4                  445 	.byte	-12
   04B7 00                  446 	.byte	0
   04B8 00                  447 	.byte	0
   04B9 24                  448 	.byte	36
   04BA 0C                  449 	.byte	12
   04BB FF                  450 	.byte	-1
   04BC EE                  451 	.byte	-18
   04BD 0C                  452 	.byte	12
   04BE 00                  453 	.byte	0
   04BF CA                  454 	.byte	-54
   04C0 E2                  455 	.byte	-30
   04C1 FF                  456 	.byte	-1
   04C2 24                  457 	.byte	36
   04C3 42                  458 	.byte	66
   04C4 FF                  459 	.byte	-1
   04C5 00                  460 	.byte	0
   04C6 2A                  461 	.byte	42
   04C7 FF                  462 	.byte	-1
   04C8 DC                  463 	.byte	-36
   04C9 E8                  464 	.byte	-24
   04CA                     465 _vl_term_1_189:
   04CA 01                  466 	.byte	1
                            467 	.globl	_vl_player_right
   04CB                     468 _vl_player_right:
   04CB 00                  469 	.byte	0
   04CC 0C                  470 	.byte	12
   04CD 88                  471 	.byte	-120
   04CE FF                  472 	.byte	-1
   04CF 88                  473 	.byte	-120
   04D0 00                  474 	.byte	0
   04D1 FF                  475 	.byte	-1
   04D2 DC                  476 	.byte	-36
   04D3 E8                  477 	.byte	-24
   04D4 FF                  478 	.byte	-1
   04D5 00                  479 	.byte	0
   04D6 88                  480 	.byte	-120
   04D7 FF                  481 	.byte	-1
   04D8 24                  482 	.byte	36
   04D9 E8                  483 	.byte	-24
   04DA FF                  484 	.byte	-1
   04DB 78                  485 	.byte	120
   04DC 00                  486 	.byte	0
   04DD FF                  487 	.byte	-1
   04DE 24                  488 	.byte	36
   04DF 18                  489 	.byte	24
   04E0 FF                  490 	.byte	-1
   04E1 00                  491 	.byte	0
   04E2 78                  492 	.byte	120
   04E3 FF                  493 	.byte	-1
   04E4 DC                  494 	.byte	-36
   04E5 18                  495 	.byte	24
   04E6 00                  496 	.byte	0
   04E7 F4                  497 	.byte	-12
   04E8 00                  498 	.byte	0
   04E9 FF                  499 	.byte	-1
   04EA 18                  500 	.byte	24
   04EB 5A                  501 	.byte	90
   04EC FF                  502 	.byte	-1
   04ED 00                  503 	.byte	0
   04EE 3C                  504 	.byte	60
   04EF FF                  505 	.byte	-1
   04F0 E8                  506 	.byte	-24
   04F1 5A                  507 	.byte	90
   04F2 00                  508 	.byte	0
   04F3 0C                  509 	.byte	12
   04F4 00                  510 	.byte	0
   04F5 FF                  511 	.byte	-1
   04F6 88                  512 	.byte	-120
   04F7 00                  513 	.byte	0
   04F8 FF                  514 	.byte	-1
   04F9 DC                  515 	.byte	-36
   04FA E8                  516 	.byte	-24
   04FB FF                  517 	.byte	-1
   04FC 24                  518 	.byte	36
   04FD E8                  519 	.byte	-24
   04FE FF                  520 	.byte	-1
   04FF 0C                  521 	.byte	12
   0500 00                  522 	.byte	0
   0501 00                  523 	.byte	0
   0502 E8                  524 	.byte	-24
   0503 24                  525 	.byte	36
   0504 FF                  526 	.byte	-1
   0505 18                  527 	.byte	24
   0506 B2                  528 	.byte	-78
   0507 00                  529 	.byte	0
   0508 00                  530 	.byte	0
   0509 5A                  531 	.byte	90
   050A FF                  532 	.byte	-1
   050B 00                  533 	.byte	0
   050C 88                  534 	.byte	-120
   050D FF                  535 	.byte	-1
   050E 00                  536 	.byte	0
   050F 88                  537 	.byte	-120
   0510 00                  538 	.byte	0
   0511 00                  539 	.byte	0
   0512 5A                  540 	.byte	90
   0513 FF                  541 	.byte	-1
   0514 E8                  542 	.byte	-24
   0515 A0                  543 	.byte	-96
   0516 00                  544 	.byte	0
   0517 F4                  545 	.byte	-12
   0518 BB                  546 	.byte	-69
   0519 00                  547 	.byte	0
   051A F4                  548 	.byte	-12
   051B BB                  549 	.byte	-69
   051C FF                  550 	.byte	-1
   051D 24                  551 	.byte	36
   051E 18                  552 	.byte	24
   051F FF                  553 	.byte	-1
   0520 78                  554 	.byte	120
   0521 00                  555 	.byte	0
   0522 FF                  556 	.byte	-1
   0523 24                  557 	.byte	36
   0524 E8                  558 	.byte	-24
   0525 00                  559 	.byte	0
   0526 D0                  560 	.byte	-48
   0527 E8                  561 	.byte	-24
   0528 FF                  562 	.byte	-1
   0529 00                  563 	.byte	0
   052A E2                  564 	.byte	-30
   052B FF                  565 	.byte	-1
   052C 18                  566 	.byte	24
   052D F4                  567 	.byte	-12
   052E FF                  568 	.byte	-1
   052F 54                  569 	.byte	84
   0530 00                  570 	.byte	0
   0531 FF                  571 	.byte	-1
   0532 18                  572 	.byte	24
   0533 0C                  573 	.byte	12
   0534 FF                  574 	.byte	-1
   0535 E8                  575 	.byte	-24
   0536 0C                  576 	.byte	12
   0537 FF                  577 	.byte	-1
   0538 AC                  578 	.byte	-84
   0539 00                  579 	.byte	0
   053A FF                  580 	.byte	-1
   053B E8                  581 	.byte	-24
   053C F4                  582 	.byte	-12
   053D 00                  583 	.byte	0
   053E 45                  584 	.byte	69
   053F 00                  585 	.byte	0
   0540 00                  586 	.byte	0
   0541 45                  587 	.byte	69
   0542 00                  588 	.byte	0
   0543 FF                  589 	.byte	-1
   0544 00                  590 	.byte	0
   0545 6C                  591 	.byte	108
   0546 FF                  592 	.byte	-1
   0547 E8                  593 	.byte	-24
   0548 0C                  594 	.byte	12
   0549 FF                  595 	.byte	-1
   054A C4                  596 	.byte	-60
   054B 00                  597 	.byte	0
   054C 00                  598 	.byte	0
   054D 00                  599 	.byte	0
   054E 1E                  600 	.byte	30
   054F FF                  601 	.byte	-1
   0550 2A                  602 	.byte	42
   0551 E2                  603 	.byte	-30
   0552 00                  604 	.byte	0
   0553 2A                  605 	.byte	42
   0554 E8                  606 	.byte	-24
   0555 FF                  607 	.byte	-1
   0556 3C                  608 	.byte	60
   0557 D6                  609 	.byte	-42
   0558 00                  610 	.byte	0
   0559 F4                  611 	.byte	-12
   055A 0C                  612 	.byte	12
   055B FF                  613 	.byte	-1
   055C 00                  614 	.byte	0
   055D D0                  615 	.byte	-48
   055E FF                  616 	.byte	-1
   055F E8                  617 	.byte	-24
   0560 0C                  618 	.byte	12
   0561 FF                  619 	.byte	-1
   0562 00                  620 	.byte	0
   0563 30                  621 	.byte	48
   0564 00                  622 	.byte	0
   0565 24                  623 	.byte	36
   0566 E8                  624 	.byte	-24
   0567 FF                  625 	.byte	-1
   0568 00                  626 	.byte	0
   0569 3C                  627 	.byte	60
   056A 00                  628 	.byte	0
   056B F4                  629 	.byte	-12
   056C 12                  630 	.byte	18
   056D FF                  631 	.byte	-1
   056E 00                  632 	.byte	0
   056F 30                  633 	.byte	48
   0570 FF                  634 	.byte	-1
   0571 E8                  635 	.byte	-24
   0572 24                  636 	.byte	36
   0573 FF                  637 	.byte	-1
   0574 00                  638 	.byte	0
   0575 D6                  639 	.byte	-42
   0576 00                  640 	.byte	0
   0577 24                  641 	.byte	36
   0578 C4                  642 	.byte	-60
   0579 FF                  643 	.byte	-1
   057A C0                  644 	.byte	-64
   057B 6C                  645 	.byte	108
   057C FF                  646 	.byte	-1
   057D C0                  647 	.byte	-64
   057E 6C                  648 	.byte	108
   057F FF                  649 	.byte	-1
   0580 C0                  650 	.byte	-64
   0581 6C                  651 	.byte	108
   0582 00                  652 	.byte	0
   0583 0C                  653 	.byte	12
   0584 00                  654 	.byte	0
   0585 FF                  655 	.byte	-1
   0586 24                  656 	.byte	36
   0587 E8                  657 	.byte	-24
   0588 FF                  658 	.byte	-1
   0589 E8                  659 	.byte	-24
   058A EE                  660 	.byte	-18
   058B 00                  661 	.byte	0
   058C AC                  662 	.byte	-84
   058D 09                  663 	.byte	9
   058E 00                  664 	.byte	0
   058F AC                  665 	.byte	-84
   0590 09                  666 	.byte	9
   0591 FF                  667 	.byte	-1
   0592 00                  668 	.byte	0
   0593 78                  669 	.byte	120
   0594 FF                  670 	.byte	-1
   0595 24                  671 	.byte	36
   0596 18                  672 	.byte	24
   0597 FF                  673 	.byte	-1
   0598 78                  674 	.byte	120
   0599 00                  675 	.byte	0
   059A FF                  676 	.byte	-1
   059B 24                  677 	.byte	36
   059C E8                  678 	.byte	-24
   059D FF                  679 	.byte	-1
   059E 00                  680 	.byte	0
   059F 88                  681 	.byte	-120
   05A0 00                  682 	.byte	0
   05A1 FA                  683 	.byte	-6
   05A2 D6                  684 	.byte	-42
   05A3 FF                  685 	.byte	-1
   05A4 48                  686 	.byte	72
   05A5 00                  687 	.byte	0
   05A6 FF                  688 	.byte	-1
   05A7 18                  689 	.byte	24
   05A8 F4                  690 	.byte	-12
   05A9 FF                  691 	.byte	-1
   05AA 00                  692 	.byte	0
   05AB 94                  693 	.byte	-108
   05AC FF                  694 	.byte	-1
   05AD E8                  695 	.byte	-24
   05AE 0C                  696 	.byte	12
   05AF FF                  697 	.byte	-1
   05B0 F4                  698 	.byte	-12
   05B1 00                  699 	.byte	0
   05B2 00                  700 	.byte	0
   05B3 24                  701 	.byte	36
   05B4 F4                  702 	.byte	-12
   05B5 FF                  703 	.byte	-1
   05B6 EE                  704 	.byte	-18
   05B7 F4                  705 	.byte	-12
   05B8 00                  706 	.byte	0
   05B9 CA                  707 	.byte	-54
   05BA 1E                  708 	.byte	30
   05BB FF                  709 	.byte	-1
   05BC 24                  710 	.byte	36
   05BD BE                  711 	.byte	-66
   05BE FF                  712 	.byte	-1
   05BF 00                  713 	.byte	0
   05C0 D6                  714 	.byte	-42
   05C1 FF                  715 	.byte	-1
   05C2 DC                  716 	.byte	-36
   05C3 18                  717 	.byte	24
   05C4                     718 _vl_term_2_302:
   05C4 01                  719 	.byte	1
                            720 	.globl	__player_draw_left
   05C5                     721 __player_draw_left:
   05C5 C6 0A         [ 2]  722 	ldb	#10
   05C7 D7 04         [ 4]  723 	stb	*_dp_VIA_t1_cnt_lo
   05C9 8E 03 D1      [ 3]  724 	ldx	#_vl_player_left
   05CC 7E F4 10      [ 4]  725 	jmp	___Draw_VLp
                            726 	.globl	__player_draw_mid
   05CF                     727 __player_draw_mid:
   05CF C6 10         [ 2]  728 	ldb	#16
   05D1 D7 04         [ 4]  729 	stb	*_dp_VIA_t1_cnt_lo
   05D3 8E 03 49      [ 3]  730 	ldx	#_vl_player_mid
   05D6 7E F4 10      [ 4]  731 	jmp	___Draw_VLp
                            732 	.globl	__player_draw_right
   05D9                     733 __player_draw_right:
   05D9 C6 0A         [ 2]  734 	ldb	#10
   05DB D7 04         [ 4]  735 	stb	*_dp_VIA_t1_cnt_lo
   05DD 8E 04 CB      [ 3]  736 	ldx	#_vl_player_right
   05E0 7E F4 10      [ 4]  737 	jmp	___Draw_VLp
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Thu Jun 12 20:59:45 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L10                0063 R   |   3 L6                 004F R
  3 _PLAYER_DRAW_L     0003 GR  |   3 _PLAYER_X_LUT      0000 GR
    __Moveto_d         **** GX  |     ___Draw_VLp        **** GX
    ___Intensity_5     **** GX  |     ___Reset0Ref       **** GX
  3 __player_draw_     02E9 GR  |   3 __player_draw_     02F3 GR
  3 __player_draw_     02FD GR  |   3 _check_collisi     006C GR
    _dp_VIA_t1_cnt     **** GX  |   3 _player_change     0046 GR
  3 _player_change     0058 GR  |   3 _player_draw       0018 GR
  3 _player_init       0009 GR  |   2 _the_player        0000 GR
  3 _vl_player_lef     00F5 GR  |   3 _vl_player_mid     006D GR
  3 _vl_player_rig     01EF GR  |   3 _vl_term_0_76      00F4 R
  3 _vl_term_1_189     01EE R   |   3 _vl_term_2_302     02E8 R

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Thu Jun 12 20:59:45 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    4   flags    0
   3 .text            size  307   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

