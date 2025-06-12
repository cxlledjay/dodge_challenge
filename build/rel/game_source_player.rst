                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	player.c
                              6 	.area	.bss
                              7 	.globl	_the_player
   C8AB                       8 _the_player:	.blkb	4
                              9 	.globl	_PLAYER_X_LUT
                             10 	.area	.text
   05BC                      11 _PLAYER_X_LUT:
   05BC AE                   12 	.byte	-82
   05BD 00                   13 	.byte	0
   05BE 52                   14 	.byte	82
                             15 	.globl	_PLAYER_DRAW_LUT
   05BF                      16 _PLAYER_DRAW_LUT:
   05BF 08 A5                17 	.word	__player_draw_left
   05C1 08 AF                18 	.word	__player_draw_mid
   05C3 08 B9                19 	.word	__player_draw_right
                             20 	.globl	_player_init
   05C5                      21 _player_init:
   05C5 8E 05 D4      [ 3]   22 	ldx	#_player_draw
   05C8 BF C8 AD      [ 6]   23 	stx	_the_player+2
   05CB 7F C8 AC      [ 7]   24 	clr	_the_player+1
   05CE C6 01         [ 2]   25 	ldb	#1
   05D0 F7 C8 AB      [ 5]   26 	stb	_the_player
   05D3 39            [ 5]   27 	rts
                             28 	.globl	_player_draw
   05D4                      29 _player_draw:
   05D4 32 7E         [ 5]   30 	leas	-2,s
   05D6 BD F2 A5      [ 8]   31 	jsr	___Intensity_5F
   05D9 BD F3 54      [ 8]   32 	jsr	___Reset0Ref
   05DC C6 7F         [ 2]   33 	ldb	#127
   05DE D7 04         [ 4]   34 	stb	*_dp_VIA_t1_cnt_lo
   05E0 F6 C8 AB      [ 5]   35 	ldb	_the_player
   05E3 4F            [ 2]   36 	clra		;zero_extendqihi: R:b -> R:d
   05E4 1F 01         [ 6]   37 	tfr	d,x
   05E6 C6 90         [ 2]   38 	ldb	#-112
   05E8 E7 E2         [ 6]   39 	stb	,-s
   05EA E6 89 05 BC   [ 8]   40 	ldb	_PLAYER_X_LUT,x
   05EE BD 08 DD      [ 8]   41 	jsr	__Moveto_d
   05F1 F6 C8 AB      [ 5]   42 	ldb	_the_player
   05F4 4F            [ 2]   43 	clra		;zero_extendqihi: R:b -> R:d
   05F5 ED 61         [ 6]   44 	std	1,s
   05F7 58            [ 2]   45 	aslb
   05F8 49            [ 2]   46 	rola
   05F9 1F 01         [ 6]   47 	tfr	d,x
   05FB AD 99 05 BF   [14]   48 	jsr	[_PLAYER_DRAW_LUT,x]
   05FF 32 63         [ 5]   49 	leas	3,s
   0601 39            [ 5]   50 	rts
                             51 	.globl	_player_change_left
   0602                      52 _player_change_left:
   0602 F6 C8 AB      [ 5]   53 	ldb	_the_player
   0605 27 04         [ 3]   54 	beq	L6
   0607 5A            [ 2]   55 	decb
   0608 F7 C8 AB      [ 5]   56 	stb	_the_player
   060B                      57 L6:
   060B 8E 05 D4      [ 3]   58 	ldx	#_player_draw
   060E BF C8 AD      [ 6]   59 	stx	_the_player+2
   0611 7E 05 D4      [ 4]   60 	jmp	_player_draw
                             61 	.globl	_player_change_right
   0614                      62 _player_change_right:
   0614 F6 C8 AB      [ 5]   63 	ldb	_the_player
   0617 C1 02         [ 2]   64 	cmpb	#2	;cmpqi:
   0619 27 04         [ 3]   65 	beq	L10
   061B 5C            [ 2]   66 	incb
   061C F7 C8 AB      [ 5]   67 	stb	_the_player
   061F                      68 L10:
   061F 8E 05 D4      [ 3]   69 	ldx	#_player_draw
   0622 BF C8 AD      [ 6]   70 	stx	_the_player+2
   0625 7E 05 D4      [ 4]   71 	jmp	_player_draw
                             72 	.globl	_check_collision
   0628                      73 _check_collision:
   0628 39            [ 5]   74 	rts
                             75 	.globl	_vl_player_mid
   0629                      76 _vl_player_mid:
   0629 00                   77 	.byte	0
   062A A0                   78 	.byte	-96
   062B B0                   79 	.byte	-80
   062C FF                   80 	.byte	-1
   062D 00                   81 	.byte	0
   062E B0                   82 	.byte	-80
   062F FF                   83 	.byte	-1
   0630 7F                   84 	.byte	127
   0631 00                   85 	.byte	0
   0632 FF                   86 	.byte	-1
   0633 00                   87 	.byte	0
   0634 50                   88 	.byte	80
   0635 FF                   89 	.byte	-1
   0636 80                   90 	.byte	-128
   0637 00                   91 	.byte	0
   0638 00                   92 	.byte	0
   0639 10                   93 	.byte	16
   063A 00                   94 	.byte	0
   063B FF                   95 	.byte	-1
   063C 10                   96 	.byte	16
   063D 3C                   97 	.byte	60
   063E 00                   98 	.byte	0
   063F 00                   99 	.byte	0
   0640 28                  100 	.byte	40
   0641 FF                  101 	.byte	-1
   0642 F0                  102 	.byte	-16
   0643 3C                  103 	.byte	60
   0644 00                  104 	.byte	0
   0645 F0                  105 	.byte	-16
   0646 00                  106 	.byte	0
   0647 FF                  107 	.byte	-1
   0648 00                  108 	.byte	0
   0649 50                  109 	.byte	80
   064A FF                  110 	.byte	-1
   064B 7F                  111 	.byte	127
   064C 00                  112 	.byte	0
   064D FF                  113 	.byte	-1
   064E 00                  114 	.byte	0
   064F B0                  115 	.byte	-80
   0650 FF                  116 	.byte	-1
   0651 80                  117 	.byte	-128
   0652 00                  118 	.byte	0
   0653 00                  119 	.byte	0
   0654 20                  120 	.byte	32
   0655 00                  121 	.byte	0
   0656 FF                  122 	.byte	-1
   0657 00                  123 	.byte	0
   0658 B0                  124 	.byte	-80
   0659 FF                  125 	.byte	-1
   065A 00                  126 	.byte	0
   065B B0                  127 	.byte	-80
   065C 00                  128 	.byte	0
   065D 40                  129 	.byte	64
   065E 00                  130 	.byte	0
   065F FF                  131 	.byte	-1
   0660 10                  132 	.byte	16
   0661 3C                  133 	.byte	60
   0662 FF                  134 	.byte	-1
   0663 00                  135 	.byte	0
   0664 28                  136 	.byte	40
   0665 FF                  137 	.byte	-1
   0666 F0                  138 	.byte	-16
   0667 3C                  139 	.byte	60
   0668 FF                  140 	.byte	-1
   0669 70                  141 	.byte	112
   066A C0                  142 	.byte	-64
   066B FF                  143 	.byte	-1
   066C 00                  144 	.byte	0
   066D E0                  145 	.byte	-32
   066E 00                  146 	.byte	0
   066F E4                  147 	.byte	-28
   0670 30                  148 	.byte	48
   0671 FF                  149 	.byte	-1
   0672 00                  150 	.byte	0
   0673 30                  151 	.byte	48
   0674 FF                  152 	.byte	-1
   0675 10                  153 	.byte	16
   0676 F8                  154 	.byte	-8
   0677 FF                  155 	.byte	-1
   0678 00                  156 	.byte	0
   0679 D0                  157 	.byte	-48
   067A 00                  158 	.byte	0
   067B 00                  159 	.byte	0
   067C D0                  160 	.byte	-48
   067D FF                  161 	.byte	-1
   067E 00                  162 	.byte	0
   067F D0                  163 	.byte	-48
   0680 FF                  164 	.byte	-1
   0681 F0                  165 	.byte	-16
   0682 F8                  166 	.byte	-8
   0683 FF                  167 	.byte	-1
   0684 00                  168 	.byte	0
   0685 30                  169 	.byte	48
   0686 00                  170 	.byte	0
   0687 1C                  171 	.byte	28
   0688 10                  172 	.byte	16
   0689 FF                  173 	.byte	-1
   068A 90                  174 	.byte	-112
   068B C0                  175 	.byte	-64
   068C 00                  176 	.byte	0
   068D 20                  177 	.byte	32
   068E D8                  178 	.byte	-40
   068F FF                  179 	.byte	-1
   0690 28                  180 	.byte	40
   0691 00                  181 	.byte	0
   0692 FF                  182 	.byte	-1
   0693 00                  183 	.byte	0
   0694 3C                  184 	.byte	60
   0695 FF                  185 	.byte	-1
   0696 DC                  186 	.byte	-36
   0697 00                  187 	.byte	0
   0698 00                  188 	.byte	0
   0699 00                  189 	.byte	0
   069A 78                  190 	.byte	120
   069B FF                  191 	.byte	-1
   069C 24                  192 	.byte	36
   069D 00                  193 	.byte	0
   069E FF                  194 	.byte	-1
   069F 00                  195 	.byte	0
   06A0 3C                  196 	.byte	60
   06A1 FF                  197 	.byte	-1
   06A2 D8                  198 	.byte	-40
   06A3 00                  199 	.byte	0
   06A4 00                  200 	.byte	0
   06A5 14                  201 	.byte	20
   06A6 9C                  202 	.byte	-100
   06A7 FF                  203 	.byte	-1
   06A8 10                  204 	.byte	16
   06A9 F8                  205 	.byte	-8
   06AA FF                  206 	.byte	-1
   06AB 00                  207 	.byte	0
   06AC E8                  208 	.byte	-24
   06AD FF                  209 	.byte	-1
   06AE F0                  210 	.byte	-16
   06AF F8                  211 	.byte	-8
   06B0                     212 _vl_term_0_76:
   06B0 01                  213 	.byte	1
                            214 	.globl	_vl_player_left
   06B1                     215 _vl_player_left:
   06B1 00                  216 	.byte	0
   06B2 0C                  217 	.byte	12
   06B3 78                  218 	.byte	120
   06B4 FF                  219 	.byte	-1
   06B5 88                  220 	.byte	-120
   06B6 00                  221 	.byte	0
   06B7 FF                  222 	.byte	-1
   06B8 DC                  223 	.byte	-36
   06B9 18                  224 	.byte	24
   06BA FF                  225 	.byte	-1
   06BB 00                  226 	.byte	0
   06BC 78                  227 	.byte	120
   06BD FF                  228 	.byte	-1
   06BE 24                  229 	.byte	36
   06BF 18                  230 	.byte	24
   06C0 FF                  231 	.byte	-1
   06C1 78                  232 	.byte	120
   06C2 00                  233 	.byte	0
   06C3 FF                  234 	.byte	-1
   06C4 24                  235 	.byte	36
   06C5 E8                  236 	.byte	-24
   06C6 FF                  237 	.byte	-1
   06C7 00                  238 	.byte	0
   06C8 88                  239 	.byte	-120
   06C9 FF                  240 	.byte	-1
   06CA DC                  241 	.byte	-36
   06CB E8                  242 	.byte	-24
   06CC 00                  243 	.byte	0
   06CD F4                  244 	.byte	-12
   06CE 00                  245 	.byte	0
   06CF FF                  246 	.byte	-1
   06D0 18                  247 	.byte	24
   06D1 A6                  248 	.byte	-90
   06D2 FF                  249 	.byte	-1
   06D3 00                  250 	.byte	0
   06D4 C4                  251 	.byte	-60
   06D5 FF                  252 	.byte	-1
   06D6 E8                  253 	.byte	-24
   06D7 A6                  254 	.byte	-90
   06D8 00                  255 	.byte	0
   06D9 0C                  256 	.byte	12
   06DA 00                  257 	.byte	0
   06DB FF                  258 	.byte	-1
   06DC 88                  259 	.byte	-120
   06DD 00                  260 	.byte	0
   06DE FF                  261 	.byte	-1
   06DF DC                  262 	.byte	-36
   06E0 18                  263 	.byte	24
   06E1 FF                  264 	.byte	-1
   06E2 24                  265 	.byte	36
   06E3 18                  266 	.byte	24
   06E4 FF                  267 	.byte	-1
   06E5 0C                  268 	.byte	12
   06E6 00                  269 	.byte	0
   06E7 00                  270 	.byte	0
   06E8 E8                  271 	.byte	-24
   06E9 DC                  272 	.byte	-36
   06EA FF                  273 	.byte	-1
   06EB 18                  274 	.byte	24
   06EC 4E                  275 	.byte	78
   06ED 00                  276 	.byte	0
   06EE 00                  277 	.byte	0
   06EF A6                  278 	.byte	-90
   06F0 FF                  279 	.byte	-1
   06F1 00                  280 	.byte	0
   06F2 78                  281 	.byte	120
   06F3 FF                  282 	.byte	-1
   06F4 00                  283 	.byte	0
   06F5 78                  284 	.byte	120
   06F6 00                  285 	.byte	0
   06F7 00                  286 	.byte	0
   06F8 A6                  287 	.byte	-90
   06F9 FF                  288 	.byte	-1
   06FA E8                  289 	.byte	-24
   06FB 60                  290 	.byte	96
   06FC 00                  291 	.byte	0
   06FD F4                  292 	.byte	-12
   06FE 45                  293 	.byte	69
   06FF 00                  294 	.byte	0
   0700 F4                  295 	.byte	-12
   0701 45                  296 	.byte	69
   0702 FF                  297 	.byte	-1
   0703 24                  298 	.byte	36
   0704 E8                  299 	.byte	-24
   0705 FF                  300 	.byte	-1
   0706 78                  301 	.byte	120
   0707 00                  302 	.byte	0
   0708 FF                  303 	.byte	-1
   0709 24                  304 	.byte	36
   070A 18                  305 	.byte	24
   070B 00                  306 	.byte	0
   070C D0                  307 	.byte	-48
   070D 18                  308 	.byte	24
   070E FF                  309 	.byte	-1
   070F 00                  310 	.byte	0
   0710 1E                  311 	.byte	30
   0711 FF                  312 	.byte	-1
   0712 18                  313 	.byte	24
   0713 0C                  314 	.byte	12
   0714 FF                  315 	.byte	-1
   0715 54                  316 	.byte	84
   0716 00                  317 	.byte	0
   0717 FF                  318 	.byte	-1
   0718 18                  319 	.byte	24
   0719 F4                  320 	.byte	-12
   071A FF                  321 	.byte	-1
   071B E8                  322 	.byte	-24
   071C F4                  323 	.byte	-12
   071D FF                  324 	.byte	-1
   071E AC                  325 	.byte	-84
   071F 00                  326 	.byte	0
   0720 FF                  327 	.byte	-1
   0721 E8                  328 	.byte	-24
   0722 0C                  329 	.byte	12
   0723 00                  330 	.byte	0
   0724 45                  331 	.byte	69
   0725 00                  332 	.byte	0
   0726 00                  333 	.byte	0
   0727 45                  334 	.byte	69
   0728 00                  335 	.byte	0
   0729 FF                  336 	.byte	-1
   072A 00                  337 	.byte	0
   072B 94                  338 	.byte	-108
   072C FF                  339 	.byte	-1
   072D E8                  340 	.byte	-24
   072E F4                  341 	.byte	-12
   072F FF                  342 	.byte	-1
   0730 C4                  343 	.byte	-60
   0731 00                  344 	.byte	0
   0732 00                  345 	.byte	0
   0733 00                  346 	.byte	0
   0734 E2                  347 	.byte	-30
   0735 FF                  348 	.byte	-1
   0736 2A                  349 	.byte	42
   0737 1E                  350 	.byte	30
   0738 00                  351 	.byte	0
   0739 2A                  352 	.byte	42
   073A 18                  353 	.byte	24
   073B FF                  354 	.byte	-1
   073C 3C                  355 	.byte	60
   073D 2A                  356 	.byte	42
   073E 00                  357 	.byte	0
   073F F4                  358 	.byte	-12
   0740 F4                  359 	.byte	-12
   0741 FF                  360 	.byte	-1
   0742 00                  361 	.byte	0
   0743 30                  362 	.byte	48
   0744 FF                  363 	.byte	-1
   0745 E8                  364 	.byte	-24
   0746 F4                  365 	.byte	-12
   0747 FF                  366 	.byte	-1
   0748 00                  367 	.byte	0
   0749 D0                  368 	.byte	-48
   074A 00                  369 	.byte	0
   074B 24                  370 	.byte	36
   074C 18                  371 	.byte	24
   074D FF                  372 	.byte	-1
   074E 00                  373 	.byte	0
   074F C4                  374 	.byte	-60
   0750 00                  375 	.byte	0
   0751 F4                  376 	.byte	-12
   0752 EE                  377 	.byte	-18
   0753 FF                  378 	.byte	-1
   0754 00                  379 	.byte	0
   0755 D0                  380 	.byte	-48
   0756 FF                  381 	.byte	-1
   0757 E8                  382 	.byte	-24
   0758 DC                  383 	.byte	-36
   0759 FF                  384 	.byte	-1
   075A 00                  385 	.byte	0
   075B 2A                  386 	.byte	42
   075C 00                  387 	.byte	0
   075D 24                  388 	.byte	36
   075E 3C                  389 	.byte	60
   075F FF                  390 	.byte	-1
   0760 C0                  391 	.byte	-64
   0761 94                  392 	.byte	-108
   0762 FF                  393 	.byte	-1
   0763 C0                  394 	.byte	-64
   0764 94                  395 	.byte	-108
   0765 FF                  396 	.byte	-1
   0766 C0                  397 	.byte	-64
   0767 94                  398 	.byte	-108
   0768 00                  399 	.byte	0
   0769 0C                  400 	.byte	12
   076A 00                  401 	.byte	0
   076B FF                  402 	.byte	-1
   076C 24                  403 	.byte	36
   076D 18                  404 	.byte	24
   076E FF                  405 	.byte	-1
   076F E8                  406 	.byte	-24
   0770 12                  407 	.byte	18
   0771 00                  408 	.byte	0
   0772 AC                  409 	.byte	-84
   0773 F7                  410 	.byte	-9
   0774 00                  411 	.byte	0
   0775 AC                  412 	.byte	-84
   0776 F7                  413 	.byte	-9
   0777 FF                  414 	.byte	-1
   0778 00                  415 	.byte	0
   0779 88                  416 	.byte	-120
   077A FF                  417 	.byte	-1
   077B 24                  418 	.byte	36
   077C E8                  419 	.byte	-24
   077D FF                  420 	.byte	-1
   077E 78                  421 	.byte	120
   077F 00                  422 	.byte	0
   0780 FF                  423 	.byte	-1
   0781 24                  424 	.byte	36
   0782 18                  425 	.byte	24
   0783 FF                  426 	.byte	-1
   0784 00                  427 	.byte	0
   0785 78                  428 	.byte	120
   0786 00                  429 	.byte	0
   0787 FA                  430 	.byte	-6
   0788 2A                  431 	.byte	42
   0789 FF                  432 	.byte	-1
   078A 48                  433 	.byte	72
   078B 00                  434 	.byte	0
   078C FF                  435 	.byte	-1
   078D 18                  436 	.byte	24
   078E 0C                  437 	.byte	12
   078F FF                  438 	.byte	-1
   0790 00                  439 	.byte	0
   0791 6C                  440 	.byte	108
   0792 FF                  441 	.byte	-1
   0793 E8                  442 	.byte	-24
   0794 F4                  443 	.byte	-12
   0795 FF                  444 	.byte	-1
   0796 F4                  445 	.byte	-12
   0797 00                  446 	.byte	0
   0798 00                  447 	.byte	0
   0799 24                  448 	.byte	36
   079A 0C                  449 	.byte	12
   079B FF                  450 	.byte	-1
   079C EE                  451 	.byte	-18
   079D 0C                  452 	.byte	12
   079E 00                  453 	.byte	0
   079F CA                  454 	.byte	-54
   07A0 E2                  455 	.byte	-30
   07A1 FF                  456 	.byte	-1
   07A2 24                  457 	.byte	36
   07A3 42                  458 	.byte	66
   07A4 FF                  459 	.byte	-1
   07A5 00                  460 	.byte	0
   07A6 2A                  461 	.byte	42
   07A7 FF                  462 	.byte	-1
   07A8 DC                  463 	.byte	-36
   07A9 E8                  464 	.byte	-24
   07AA                     465 _vl_term_1_189:
   07AA 01                  466 	.byte	1
                            467 	.globl	_vl_player_right
   07AB                     468 _vl_player_right:
   07AB 00                  469 	.byte	0
   07AC 0C                  470 	.byte	12
   07AD 88                  471 	.byte	-120
   07AE FF                  472 	.byte	-1
   07AF 88                  473 	.byte	-120
   07B0 00                  474 	.byte	0
   07B1 FF                  475 	.byte	-1
   07B2 DC                  476 	.byte	-36
   07B3 E8                  477 	.byte	-24
   07B4 FF                  478 	.byte	-1
   07B5 00                  479 	.byte	0
   07B6 88                  480 	.byte	-120
   07B7 FF                  481 	.byte	-1
   07B8 24                  482 	.byte	36
   07B9 E8                  483 	.byte	-24
   07BA FF                  484 	.byte	-1
   07BB 78                  485 	.byte	120
   07BC 00                  486 	.byte	0
   07BD FF                  487 	.byte	-1
   07BE 24                  488 	.byte	36
   07BF 18                  489 	.byte	24
   07C0 FF                  490 	.byte	-1
   07C1 00                  491 	.byte	0
   07C2 78                  492 	.byte	120
   07C3 FF                  493 	.byte	-1
   07C4 DC                  494 	.byte	-36
   07C5 18                  495 	.byte	24
   07C6 00                  496 	.byte	0
   07C7 F4                  497 	.byte	-12
   07C8 00                  498 	.byte	0
   07C9 FF                  499 	.byte	-1
   07CA 18                  500 	.byte	24
   07CB 5A                  501 	.byte	90
   07CC FF                  502 	.byte	-1
   07CD 00                  503 	.byte	0
   07CE 3C                  504 	.byte	60
   07CF FF                  505 	.byte	-1
   07D0 E8                  506 	.byte	-24
   07D1 5A                  507 	.byte	90
   07D2 00                  508 	.byte	0
   07D3 0C                  509 	.byte	12
   07D4 00                  510 	.byte	0
   07D5 FF                  511 	.byte	-1
   07D6 88                  512 	.byte	-120
   07D7 00                  513 	.byte	0
   07D8 FF                  514 	.byte	-1
   07D9 DC                  515 	.byte	-36
   07DA E8                  516 	.byte	-24
   07DB FF                  517 	.byte	-1
   07DC 24                  518 	.byte	36
   07DD E8                  519 	.byte	-24
   07DE FF                  520 	.byte	-1
   07DF 0C                  521 	.byte	12
   07E0 00                  522 	.byte	0
   07E1 00                  523 	.byte	0
   07E2 E8                  524 	.byte	-24
   07E3 24                  525 	.byte	36
   07E4 FF                  526 	.byte	-1
   07E5 18                  527 	.byte	24
   07E6 B2                  528 	.byte	-78
   07E7 00                  529 	.byte	0
   07E8 00                  530 	.byte	0
   07E9 5A                  531 	.byte	90
   07EA FF                  532 	.byte	-1
   07EB 00                  533 	.byte	0
   07EC 88                  534 	.byte	-120
   07ED FF                  535 	.byte	-1
   07EE 00                  536 	.byte	0
   07EF 88                  537 	.byte	-120
   07F0 00                  538 	.byte	0
   07F1 00                  539 	.byte	0
   07F2 5A                  540 	.byte	90
   07F3 FF                  541 	.byte	-1
   07F4 E8                  542 	.byte	-24
   07F5 A0                  543 	.byte	-96
   07F6 00                  544 	.byte	0
   07F7 F4                  545 	.byte	-12
   07F8 BB                  546 	.byte	-69
   07F9 00                  547 	.byte	0
   07FA F4                  548 	.byte	-12
   07FB BB                  549 	.byte	-69
   07FC FF                  550 	.byte	-1
   07FD 24                  551 	.byte	36
   07FE 18                  552 	.byte	24
   07FF FF                  553 	.byte	-1
   0800 78                  554 	.byte	120
   0801 00                  555 	.byte	0
   0802 FF                  556 	.byte	-1
   0803 24                  557 	.byte	36
   0804 E8                  558 	.byte	-24
   0805 00                  559 	.byte	0
   0806 D0                  560 	.byte	-48
   0807 E8                  561 	.byte	-24
   0808 FF                  562 	.byte	-1
   0809 00                  563 	.byte	0
   080A E2                  564 	.byte	-30
   080B FF                  565 	.byte	-1
   080C 18                  566 	.byte	24
   080D F4                  567 	.byte	-12
   080E FF                  568 	.byte	-1
   080F 54                  569 	.byte	84
   0810 00                  570 	.byte	0
   0811 FF                  571 	.byte	-1
   0812 18                  572 	.byte	24
   0813 0C                  573 	.byte	12
   0814 FF                  574 	.byte	-1
   0815 E8                  575 	.byte	-24
   0816 0C                  576 	.byte	12
   0817 FF                  577 	.byte	-1
   0818 AC                  578 	.byte	-84
   0819 00                  579 	.byte	0
   081A FF                  580 	.byte	-1
   081B E8                  581 	.byte	-24
   081C F4                  582 	.byte	-12
   081D 00                  583 	.byte	0
   081E 45                  584 	.byte	69
   081F 00                  585 	.byte	0
   0820 00                  586 	.byte	0
   0821 45                  587 	.byte	69
   0822 00                  588 	.byte	0
   0823 FF                  589 	.byte	-1
   0824 00                  590 	.byte	0
   0825 6C                  591 	.byte	108
   0826 FF                  592 	.byte	-1
   0827 E8                  593 	.byte	-24
   0828 0C                  594 	.byte	12
   0829 FF                  595 	.byte	-1
   082A C4                  596 	.byte	-60
   082B 00                  597 	.byte	0
   082C 00                  598 	.byte	0
   082D 00                  599 	.byte	0
   082E 1E                  600 	.byte	30
   082F FF                  601 	.byte	-1
   0830 2A                  602 	.byte	42
   0831 E2                  603 	.byte	-30
   0832 00                  604 	.byte	0
   0833 2A                  605 	.byte	42
   0834 E8                  606 	.byte	-24
   0835 FF                  607 	.byte	-1
   0836 3C                  608 	.byte	60
   0837 D6                  609 	.byte	-42
   0838 00                  610 	.byte	0
   0839 F4                  611 	.byte	-12
   083A 0C                  612 	.byte	12
   083B FF                  613 	.byte	-1
   083C 00                  614 	.byte	0
   083D D0                  615 	.byte	-48
   083E FF                  616 	.byte	-1
   083F E8                  617 	.byte	-24
   0840 0C                  618 	.byte	12
   0841 FF                  619 	.byte	-1
   0842 00                  620 	.byte	0
   0843 30                  621 	.byte	48
   0844 00                  622 	.byte	0
   0845 24                  623 	.byte	36
   0846 E8                  624 	.byte	-24
   0847 FF                  625 	.byte	-1
   0848 00                  626 	.byte	0
   0849 3C                  627 	.byte	60
   084A 00                  628 	.byte	0
   084B F4                  629 	.byte	-12
   084C 12                  630 	.byte	18
   084D FF                  631 	.byte	-1
   084E 00                  632 	.byte	0
   084F 30                  633 	.byte	48
   0850 FF                  634 	.byte	-1
   0851 E8                  635 	.byte	-24
   0852 24                  636 	.byte	36
   0853 FF                  637 	.byte	-1
   0854 00                  638 	.byte	0
   0855 D6                  639 	.byte	-42
   0856 00                  640 	.byte	0
   0857 24                  641 	.byte	36
   0858 C4                  642 	.byte	-60
   0859 FF                  643 	.byte	-1
   085A C0                  644 	.byte	-64
   085B 6C                  645 	.byte	108
   085C FF                  646 	.byte	-1
   085D C0                  647 	.byte	-64
   085E 6C                  648 	.byte	108
   085F FF                  649 	.byte	-1
   0860 C0                  650 	.byte	-64
   0861 6C                  651 	.byte	108
   0862 00                  652 	.byte	0
   0863 0C                  653 	.byte	12
   0864 00                  654 	.byte	0
   0865 FF                  655 	.byte	-1
   0866 24                  656 	.byte	36
   0867 E8                  657 	.byte	-24
   0868 FF                  658 	.byte	-1
   0869 E8                  659 	.byte	-24
   086A EE                  660 	.byte	-18
   086B 00                  661 	.byte	0
   086C AC                  662 	.byte	-84
   086D 09                  663 	.byte	9
   086E 00                  664 	.byte	0
   086F AC                  665 	.byte	-84
   0870 09                  666 	.byte	9
   0871 FF                  667 	.byte	-1
   0872 00                  668 	.byte	0
   0873 78                  669 	.byte	120
   0874 FF                  670 	.byte	-1
   0875 24                  671 	.byte	36
   0876 18                  672 	.byte	24
   0877 FF                  673 	.byte	-1
   0878 78                  674 	.byte	120
   0879 00                  675 	.byte	0
   087A FF                  676 	.byte	-1
   087B 24                  677 	.byte	36
   087C E8                  678 	.byte	-24
   087D FF                  679 	.byte	-1
   087E 00                  680 	.byte	0
   087F 88                  681 	.byte	-120
   0880 00                  682 	.byte	0
   0881 FA                  683 	.byte	-6
   0882 D6                  684 	.byte	-42
   0883 FF                  685 	.byte	-1
   0884 48                  686 	.byte	72
   0885 00                  687 	.byte	0
   0886 FF                  688 	.byte	-1
   0887 18                  689 	.byte	24
   0888 F4                  690 	.byte	-12
   0889 FF                  691 	.byte	-1
   088A 00                  692 	.byte	0
   088B 94                  693 	.byte	-108
   088C FF                  694 	.byte	-1
   088D E8                  695 	.byte	-24
   088E 0C                  696 	.byte	12
   088F FF                  697 	.byte	-1
   0890 F4                  698 	.byte	-12
   0891 00                  699 	.byte	0
   0892 00                  700 	.byte	0
   0893 24                  701 	.byte	36
   0894 F4                  702 	.byte	-12
   0895 FF                  703 	.byte	-1
   0896 EE                  704 	.byte	-18
   0897 F4                  705 	.byte	-12
   0898 00                  706 	.byte	0
   0899 CA                  707 	.byte	-54
   089A 1E                  708 	.byte	30
   089B FF                  709 	.byte	-1
   089C 24                  710 	.byte	36
   089D BE                  711 	.byte	-66
   089E FF                  712 	.byte	-1
   089F 00                  713 	.byte	0
   08A0 D6                  714 	.byte	-42
   08A1 FF                  715 	.byte	-1
   08A2 DC                  716 	.byte	-36
   08A3 18                  717 	.byte	24
   08A4                     718 _vl_term_2_302:
   08A4 01                  719 	.byte	1
                            720 	.globl	__player_draw_left
   08A5                     721 __player_draw_left:
   08A5 C6 0A         [ 2]  722 	ldb	#10
   08A7 D7 04         [ 4]  723 	stb	*_dp_VIA_t1_cnt_lo
   08A9 8E 06 B1      [ 3]  724 	ldx	#_vl_player_left
   08AC 7E F4 10      [ 4]  725 	jmp	___Draw_VLp
                            726 	.globl	__player_draw_mid
   08AF                     727 __player_draw_mid:
   08AF C6 10         [ 2]  728 	ldb	#16
   08B1 D7 04         [ 4]  729 	stb	*_dp_VIA_t1_cnt_lo
   08B3 8E 06 29      [ 3]  730 	ldx	#_vl_player_mid
   08B6 7E F4 10      [ 4]  731 	jmp	___Draw_VLp
                            732 	.globl	__player_draw_right
   08B9                     733 __player_draw_right:
   08B9 C6 0A         [ 2]  734 	ldb	#10
   08BB D7 04         [ 4]  735 	stb	*_dp_VIA_t1_cnt_lo
   08BD 8E 07 AB      [ 3]  736 	ldx	#_vl_player_right
   08C0 7E F4 10      [ 4]  737 	jmp	___Draw_VLp
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Thu Jun 12 23:11:43 2025

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
Hexadecimal [16-Bits]                                 Thu Jun 12 23:11:43 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    4   flags    0
   3 .text            size  307   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

