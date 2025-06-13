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
   074E                      11 _PLAYER_X_LUT:
   074E AE                   12 	.byte	-82
   074F 00                   13 	.byte	0
   0750 52                   14 	.byte	82
                             15 	.globl	_PLAYER_DRAW_LUT
   0751                      16 _PLAYER_DRAW_LUT:
   0751 0A 14                17 	.word	__player_draw_left
   0753 0A 38                18 	.word	__player_draw_mid
   0755 0A 7E                19 	.word	__player_draw_right
                             20 	.globl	_player_init
   0757                      21 _player_init:
   0757 8E 07 66      [ 3]   22 	ldx	#_player_draw
   075A BF C8 AC      [ 6]   23 	stx	_the_player+2
   075D 7F C8 AB      [ 7]   24 	clr	_the_player+1
   0760 C6 01         [ 2]   25 	ldb	#1
   0762 F7 C8 AA      [ 5]   26 	stb	_the_player
   0765 39            [ 5]   27 	rts
                             28 	.globl	_player_draw
   0766                      29 _player_draw:
   0766 32 7E         [ 5]   30 	leas	-2,s
   0768 BD F2 A5      [ 8]   31 	jsr	___Intensity_5F
   076B F6 C8 AA      [ 5]   32 	ldb	_the_player
   076E 4F            [ 2]   33 	clra		;zero_extendqihi: R:b -> R:d
   076F ED E4         [ 5]   34 	std	,s
   0771 58            [ 2]   35 	aslb
   0772 49            [ 2]   36 	rola
   0773 1F 01         [ 6]   37 	tfr	d,x
   0775 AD 99 07 51   [14]   38 	jsr	[_PLAYER_DRAW_LUT,x]
   0779 32 62         [ 5]   39 	leas	2,s
   077B 39            [ 5]   40 	rts
                             41 	.globl	_player_change_left
   077C                      42 _player_change_left:
   077C F6 C8 AA      [ 5]   43 	ldb	_the_player
   077F 27 04         [ 3]   44 	beq	L6
   0781 5A            [ 2]   45 	decb
   0782 F7 C8 AA      [ 5]   46 	stb	_the_player
   0785                      47 L6:
   0785 8E 07 66      [ 3]   48 	ldx	#_player_draw
   0788 BF C8 AC      [ 6]   49 	stx	_the_player+2
   078B 7E 07 66      [ 4]   50 	jmp	_player_draw
                             51 	.globl	_player_change_right
   078E                      52 _player_change_right:
   078E F6 C8 AA      [ 5]   53 	ldb	_the_player
   0791 C1 02         [ 2]   54 	cmpb	#2	;cmpqi:
   0793 27 04         [ 3]   55 	beq	L10
   0795 5C            [ 2]   56 	incb
   0796 F7 C8 AA      [ 5]   57 	stb	_the_player
   0799                      58 L10:
   0799 8E 07 66      [ 3]   59 	ldx	#_player_draw
   079C BF C8 AC      [ 6]   60 	stx	_the_player+2
   079F 7E 07 66      [ 4]   61 	jmp	_player_draw
                             62 	.globl	_check_collision
   07A2                      63 _check_collision:
   07A2 39            [ 5]   64 	rts
                             65 	.globl	_vl_player_mid1
   07A3                      66 _vl_player_mid1:
   07A3 00                   67 	.byte	0
   07A4 A0                   68 	.byte	-96
   07A5 B0                   69 	.byte	-80
   07A6 FF                   70 	.byte	-1
   07A7 00                   71 	.byte	0
   07A8 B0                   72 	.byte	-80
   07A9 FF                   73 	.byte	-1
   07AA 7F                   74 	.byte	127
   07AB 00                   75 	.byte	0
   07AC FF                   76 	.byte	-1
   07AD 00                   77 	.byte	0
   07AE 50                   78 	.byte	80
   07AF FF                   79 	.byte	-1
   07B0 80                   80 	.byte	-128
   07B1 00                   81 	.byte	0
   07B2 00                   82 	.byte	0
   07B3 10                   83 	.byte	16
   07B4 00                   84 	.byte	0
   07B5 FF                   85 	.byte	-1
   07B6 10                   86 	.byte	16
   07B7 3C                   87 	.byte	60
   07B8 00                   88 	.byte	0
   07B9 00                   89 	.byte	0
   07BA 28                   90 	.byte	40
   07BB FF                   91 	.byte	-1
   07BC F0                   92 	.byte	-16
   07BD 3C                   93 	.byte	60
   07BE 00                   94 	.byte	0
   07BF F0                   95 	.byte	-16
   07C0 00                   96 	.byte	0
   07C1 FF                   97 	.byte	-1
   07C2 00                   98 	.byte	0
   07C3 50                   99 	.byte	80
   07C4 FF                  100 	.byte	-1
   07C5 7F                  101 	.byte	127
   07C6 00                  102 	.byte	0
   07C7 FF                  103 	.byte	-1
   07C8 00                  104 	.byte	0
   07C9 B0                  105 	.byte	-80
   07CA FF                  106 	.byte	-1
   07CB 80                  107 	.byte	-128
   07CC 00                  108 	.byte	0
   07CD 00                  109 	.byte	0
   07CE 20                  110 	.byte	32
   07CF 00                  111 	.byte	0
   07D0 FF                  112 	.byte	-1
   07D1 00                  113 	.byte	0
   07D2 B0                  114 	.byte	-80
   07D3 FF                  115 	.byte	-1
   07D4 00                  116 	.byte	0
   07D5 B0                  117 	.byte	-80
   07D6 00                  118 	.byte	0
   07D7 40                  119 	.byte	64
   07D8 00                  120 	.byte	0
   07D9 FF                  121 	.byte	-1
   07DA 10                  122 	.byte	16
   07DB 3C                  123 	.byte	60
   07DC FF                  124 	.byte	-1
   07DD 00                  125 	.byte	0
   07DE 28                  126 	.byte	40
   07DF FF                  127 	.byte	-1
   07E0 F0                  128 	.byte	-16
   07E1 3C                  129 	.byte	60
   07E2                     130 _vl_term_0_46:
   07E2 01                  131 	.byte	1
                            132 	.globl	_vl_player_mid2_enhanced
   07E3                     133 _vl_player_mid2_enhanced:
   07E3 00                  134 	.byte	0
   07E4 20                  135 	.byte	32
   07E5 88                  136 	.byte	-120
   07E6 FF                  137 	.byte	-1
   07E7 28                  138 	.byte	40
   07E8 00                  139 	.byte	0
   07E9 FF                  140 	.byte	-1
   07EA 00                  141 	.byte	0
   07EB 3C                  142 	.byte	60
   07EC FF                  143 	.byte	-1
   07ED DC                  144 	.byte	-36
   07EE 00                  145 	.byte	0
   07EF 00                  146 	.byte	0
   07F0 E0                  147 	.byte	-32
   07F1 EC                  148 	.byte	-20
   07F2 FF                  149 	.byte	-1
   07F3 70                  150 	.byte	112
   07F4 40                  151 	.byte	64
   07F5 FF                  152 	.byte	-1
   07F6 00                  153 	.byte	0
   07F7 20                  154 	.byte	32
   07F8 FF                  155 	.byte	-1
   07F9 90                  156 	.byte	-112
   07FA 40                  157 	.byte	64
   07FB 00                  158 	.byte	0
   07FC 20                  159 	.byte	32
   07FD 28                  160 	.byte	40
   07FE FF                  161 	.byte	-1
   07FF 28                  162 	.byte	40
   0800 00                  163 	.byte	0
   0801 FF                  164 	.byte	-1
   0802 00                  165 	.byte	0
   0803 C4                  166 	.byte	-60
   0804 FF                  167 	.byte	-1
   0805 DC                  168 	.byte	-36
   0806 00                  169 	.byte	0
   0807 00                  170 	.byte	0
   0808 2D                  171 	.byte	45
   0809 E4                  172 	.byte	-28
   080A FF                  173 	.byte	-1
   080B 00                  174 	.byte	0
   080C 30                  175 	.byte	48
   080D FF                  176 	.byte	-1
   080E 10                  177 	.byte	16
   080F F8                  178 	.byte	-8
   0810 FF                  179 	.byte	-1
   0811 00                  180 	.byte	0
   0812 D0                  181 	.byte	-48
   0813 00                  182 	.byte	0
   0814 00                  183 	.byte	0
   0815 D0                  184 	.byte	-48
   0816 FF                  185 	.byte	-1
   0817 00                  186 	.byte	0
   0818 D0                  187 	.byte	-48
   0819 FF                  188 	.byte	-1
   081A F0                  189 	.byte	-16
   081B F8                  190 	.byte	-8
   081C FF                  191 	.byte	-1
   081D 00                  192 	.byte	0
   081E 30                  193 	.byte	48
   081F 00                  194 	.byte	0
   0820 E4                  195 	.byte	-28
   0821 0C                  196 	.byte	12
   0822 FF                  197 	.byte	-1
   0823 10                  198 	.byte	16
   0824 08                  199 	.byte	8
   0825 FF                  200 	.byte	-1
   0826 00                  201 	.byte	0
   0827 18                  202 	.byte	24
   0828 FF                  203 	.byte	-1
   0829 F0                  204 	.byte	-16
   082A 08                  205 	.byte	8
   082B                     206 _vl_term_1_127:
   082B 01                  207 	.byte	1
                            208 	.globl	_vl_player_left
   082C                     209 _vl_player_left:
   082C 00                  210 	.byte	0
   082D 0C                  211 	.byte	12
   082E 78                  212 	.byte	120
   082F FF                  213 	.byte	-1
   0830 88                  214 	.byte	-120
   0831 00                  215 	.byte	0
   0832 FF                  216 	.byte	-1
   0833 DC                  217 	.byte	-36
   0834 18                  218 	.byte	24
   0835 FF                  219 	.byte	-1
   0836 00                  220 	.byte	0
   0837 78                  221 	.byte	120
   0838 FF                  222 	.byte	-1
   0839 24                  223 	.byte	36
   083A 18                  224 	.byte	24
   083B FF                  225 	.byte	-1
   083C 78                  226 	.byte	120
   083D 00                  227 	.byte	0
   083E FF                  228 	.byte	-1
   083F 24                  229 	.byte	36
   0840 E8                  230 	.byte	-24
   0841 FF                  231 	.byte	-1
   0842 00                  232 	.byte	0
   0843 88                  233 	.byte	-120
   0844 FF                  234 	.byte	-1
   0845 DC                  235 	.byte	-36
   0846 E8                  236 	.byte	-24
   0847 00                  237 	.byte	0
   0848 F4                  238 	.byte	-12
   0849 00                  239 	.byte	0
   084A FF                  240 	.byte	-1
   084B 18                  241 	.byte	24
   084C A6                  242 	.byte	-90
   084D FF                  243 	.byte	-1
   084E 00                  244 	.byte	0
   084F C4                  245 	.byte	-60
   0850 FF                  246 	.byte	-1
   0851 E8                  247 	.byte	-24
   0852 A6                  248 	.byte	-90
   0853 00                  249 	.byte	0
   0854 0C                  250 	.byte	12
   0855 00                  251 	.byte	0
   0856 FF                  252 	.byte	-1
   0857 88                  253 	.byte	-120
   0858 00                  254 	.byte	0
   0859 FF                  255 	.byte	-1
   085A DC                  256 	.byte	-36
   085B 18                  257 	.byte	24
   085C FF                  258 	.byte	-1
   085D 24                  259 	.byte	36
   085E 18                  260 	.byte	24
   085F FF                  261 	.byte	-1
   0860 0C                  262 	.byte	12
   0861 00                  263 	.byte	0
   0862 00                  264 	.byte	0
   0863 E8                  265 	.byte	-24
   0864 DC                  266 	.byte	-36
   0865 FF                  267 	.byte	-1
   0866 18                  268 	.byte	24
   0867 4E                  269 	.byte	78
   0868 00                  270 	.byte	0
   0869 00                  271 	.byte	0
   086A A6                  272 	.byte	-90
   086B FF                  273 	.byte	-1
   086C 00                  274 	.byte	0
   086D 78                  275 	.byte	120
   086E FF                  276 	.byte	-1
   086F 00                  277 	.byte	0
   0870 78                  278 	.byte	120
   0871 00                  279 	.byte	0
   0872 00                  280 	.byte	0
   0873 A6                  281 	.byte	-90
   0874 FF                  282 	.byte	-1
   0875 E8                  283 	.byte	-24
   0876 60                  284 	.byte	96
   0877 00                  285 	.byte	0
   0878 F4                  286 	.byte	-12
   0879 45                  287 	.byte	69
   087A 00                  288 	.byte	0
   087B F4                  289 	.byte	-12
   087C 45                  290 	.byte	69
   087D FF                  291 	.byte	-1
   087E 24                  292 	.byte	36
   087F E8                  293 	.byte	-24
   0880 FF                  294 	.byte	-1
   0881 78                  295 	.byte	120
   0882 00                  296 	.byte	0
   0883 FF                  297 	.byte	-1
   0884 24                  298 	.byte	36
   0885 18                  299 	.byte	24
   0886 00                  300 	.byte	0
   0887 D0                  301 	.byte	-48
   0888 18                  302 	.byte	24
   0889 FF                  303 	.byte	-1
   088A 00                  304 	.byte	0
   088B 1E                  305 	.byte	30
   088C FF                  306 	.byte	-1
   088D 18                  307 	.byte	24
   088E 0C                  308 	.byte	12
   088F FF                  309 	.byte	-1
   0890 54                  310 	.byte	84
   0891 00                  311 	.byte	0
   0892 FF                  312 	.byte	-1
   0893 18                  313 	.byte	24
   0894 F4                  314 	.byte	-12
   0895 FF                  315 	.byte	-1
   0896 E8                  316 	.byte	-24
   0897 F4                  317 	.byte	-12
   0898 FF                  318 	.byte	-1
   0899 AC                  319 	.byte	-84
   089A 00                  320 	.byte	0
   089B FF                  321 	.byte	-1
   089C E8                  322 	.byte	-24
   089D 0C                  323 	.byte	12
   089E 00                  324 	.byte	0
   089F 45                  325 	.byte	69
   08A0 00                  326 	.byte	0
   08A1 00                  327 	.byte	0
   08A2 45                  328 	.byte	69
   08A3 00                  329 	.byte	0
   08A4 FF                  330 	.byte	-1
   08A5 00                  331 	.byte	0
   08A6 94                  332 	.byte	-108
   08A7 FF                  333 	.byte	-1
   08A8 E8                  334 	.byte	-24
   08A9 F4                  335 	.byte	-12
   08AA FF                  336 	.byte	-1
   08AB C4                  337 	.byte	-60
   08AC 00                  338 	.byte	0
   08AD 00                  339 	.byte	0
   08AE 00                  340 	.byte	0
   08AF E2                  341 	.byte	-30
   08B0 FF                  342 	.byte	-1
   08B1 2A                  343 	.byte	42
   08B2 1E                  344 	.byte	30
   08B3 00                  345 	.byte	0
   08B4 2A                  346 	.byte	42
   08B5 18                  347 	.byte	24
   08B6 FF                  348 	.byte	-1
   08B7 3C                  349 	.byte	60
   08B8 2A                  350 	.byte	42
   08B9 00                  351 	.byte	0
   08BA F4                  352 	.byte	-12
   08BB F4                  353 	.byte	-12
   08BC FF                  354 	.byte	-1
   08BD 00                  355 	.byte	0
   08BE 30                  356 	.byte	48
   08BF FF                  357 	.byte	-1
   08C0 E8                  358 	.byte	-24
   08C1 F4                  359 	.byte	-12
   08C2 FF                  360 	.byte	-1
   08C3 00                  361 	.byte	0
   08C4 D0                  362 	.byte	-48
   08C5 00                  363 	.byte	0
   08C6 24                  364 	.byte	36
   08C7 18                  365 	.byte	24
   08C8 FF                  366 	.byte	-1
   08C9 00                  367 	.byte	0
   08CA C4                  368 	.byte	-60
   08CB 00                  369 	.byte	0
   08CC F4                  370 	.byte	-12
   08CD EE                  371 	.byte	-18
   08CE FF                  372 	.byte	-1
   08CF 00                  373 	.byte	0
   08D0 D0                  374 	.byte	-48
   08D1 FF                  375 	.byte	-1
   08D2 E8                  376 	.byte	-24
   08D3 DC                  377 	.byte	-36
   08D4 FF                  378 	.byte	-1
   08D5 00                  379 	.byte	0
   08D6 2A                  380 	.byte	42
   08D7 00                  381 	.byte	0
   08D8 24                  382 	.byte	36
   08D9 3C                  383 	.byte	60
   08DA FF                  384 	.byte	-1
   08DB C0                  385 	.byte	-64
   08DC 94                  386 	.byte	-108
   08DD FF                  387 	.byte	-1
   08DE C0                  388 	.byte	-64
   08DF 94                  389 	.byte	-108
   08E0 FF                  390 	.byte	-1
   08E1 C0                  391 	.byte	-64
   08E2 94                  392 	.byte	-108
   08E3 00                  393 	.byte	0
   08E4 0C                  394 	.byte	12
   08E5 00                  395 	.byte	0
   08E6 FF                  396 	.byte	-1
   08E7 24                  397 	.byte	36
   08E8 18                  398 	.byte	24
   08E9 FF                  399 	.byte	-1
   08EA E8                  400 	.byte	-24
   08EB 12                  401 	.byte	18
   08EC 00                  402 	.byte	0
   08ED AC                  403 	.byte	-84
   08EE F7                  404 	.byte	-9
   08EF 00                  405 	.byte	0
   08F0 AC                  406 	.byte	-84
   08F1 F7                  407 	.byte	-9
   08F2 FF                  408 	.byte	-1
   08F3 00                  409 	.byte	0
   08F4 88                  410 	.byte	-120
   08F5 FF                  411 	.byte	-1
   08F6 24                  412 	.byte	36
   08F7 E8                  413 	.byte	-24
   08F8 FF                  414 	.byte	-1
   08F9 78                  415 	.byte	120
   08FA 00                  416 	.byte	0
   08FB FF                  417 	.byte	-1
   08FC 24                  418 	.byte	36
   08FD 18                  419 	.byte	24
   08FE FF                  420 	.byte	-1
   08FF 00                  421 	.byte	0
   0900 78                  422 	.byte	120
   0901 00                  423 	.byte	0
   0902 FA                  424 	.byte	-6
   0903 2A                  425 	.byte	42
   0904 FF                  426 	.byte	-1
   0905 48                  427 	.byte	72
   0906 00                  428 	.byte	0
   0907 FF                  429 	.byte	-1
   0908 18                  430 	.byte	24
   0909 0C                  431 	.byte	12
   090A FF                  432 	.byte	-1
   090B 00                  433 	.byte	0
   090C 6C                  434 	.byte	108
   090D FF                  435 	.byte	-1
   090E E8                  436 	.byte	-24
   090F F4                  437 	.byte	-12
   0910 FF                  438 	.byte	-1
   0911 F4                  439 	.byte	-12
   0912 00                  440 	.byte	0
   0913 00                  441 	.byte	0
   0914 24                  442 	.byte	36
   0915 0C                  443 	.byte	12
   0916 FF                  444 	.byte	-1
   0917 EE                  445 	.byte	-18
   0918 0C                  446 	.byte	12
   0919 00                  447 	.byte	0
   091A CA                  448 	.byte	-54
   091B E2                  449 	.byte	-30
   091C FF                  450 	.byte	-1
   091D 24                  451 	.byte	36
   091E 42                  452 	.byte	66
   091F FF                  453 	.byte	-1
   0920 00                  454 	.byte	0
   0921 2A                  455 	.byte	42
   0922 FF                  456 	.byte	-1
   0923 DC                  457 	.byte	-36
   0924 E8                  458 	.byte	-24
   0925                     459 _vl_term_2_240:
   0925 01                  460 	.byte	1
                            461 	.globl	_vl_player_right
   0926                     462 _vl_player_right:
   0926 00                  463 	.byte	0
   0927 08                  464 	.byte	8
   0928 B0                  465 	.byte	-80
   0929 FF                  466 	.byte	-1
   092A B0                  467 	.byte	-80
   092B 00                  468 	.byte	0
   092C FF                  469 	.byte	-1
   092D E8                  470 	.byte	-24
   092E F0                  471 	.byte	-16
   092F FF                  472 	.byte	-1
   0930 00                  473 	.byte	0
   0931 B0                  474 	.byte	-80
   0932 FF                  475 	.byte	-1
   0933 18                  476 	.byte	24
   0934 F0                  477 	.byte	-16
   0935 FF                  478 	.byte	-1
   0936 50                  479 	.byte	80
   0937 00                  480 	.byte	0
   0938 FF                  481 	.byte	-1
   0939 18                  482 	.byte	24
   093A 10                  483 	.byte	16
   093B FF                  484 	.byte	-1
   093C 00                  485 	.byte	0
   093D 50                  486 	.byte	80
   093E FF                  487 	.byte	-1
   093F E8                  488 	.byte	-24
   0940 10                  489 	.byte	16
   0941 00                  490 	.byte	0
   0942 F8                  491 	.byte	-8
   0943 00                  492 	.byte	0
   0944 FF                  493 	.byte	-1
   0945 10                  494 	.byte	16
   0946 3C                  495 	.byte	60
   0947 FF                  496 	.byte	-1
   0948 00                  497 	.byte	0
   0949 28                  498 	.byte	40
   094A FF                  499 	.byte	-1
   094B F0                  500 	.byte	-16
   094C 3C                  501 	.byte	60
   094D 00                  502 	.byte	0
   094E 08                  503 	.byte	8
   094F 00                  504 	.byte	0
   0950 FF                  505 	.byte	-1
   0951 B0                  506 	.byte	-80
   0952 00                  507 	.byte	0
   0953 FF                  508 	.byte	-1
   0954 E8                  509 	.byte	-24
   0955 F0                  510 	.byte	-16
   0956 FF                  511 	.byte	-1
   0957 18                  512 	.byte	24
   0958 F0                  513 	.byte	-16
   0959 FF                  514 	.byte	-1
   095A 08                  515 	.byte	8
   095B 00                  516 	.byte	0
   095C 00                  517 	.byte	0
   095D F0                  518 	.byte	-16
   095E 18                  519 	.byte	24
   095F FF                  520 	.byte	-1
   0960 10                  521 	.byte	16
   0961 CC                  522 	.byte	-52
   0962 00                  523 	.byte	0
   0963 00                  524 	.byte	0
   0964 3C                  525 	.byte	60
   0965 FF                  526 	.byte	-1
   0966 00                  527 	.byte	0
   0967 B0                  528 	.byte	-80
   0968 FF                  529 	.byte	-1
   0969 00                  530 	.byte	0
   096A B0                  531 	.byte	-80
   096B 00                  532 	.byte	0
   096C 00                  533 	.byte	0
   096D 3C                  534 	.byte	60
   096E FF                  535 	.byte	-1
   096F F0                  536 	.byte	-16
   0970 C0                  537 	.byte	-64
   0971 00                  538 	.byte	0
   0972 F0                  539 	.byte	-16
   0973 A4                  540 	.byte	-92
   0974 FF                  541 	.byte	-1
   0975 18                  542 	.byte	24
   0976 10                  543 	.byte	16
   0977 FF                  544 	.byte	-1
   0978 50                  545 	.byte	80
   0979 00                  546 	.byte	0
   097A FF                  547 	.byte	-1
   097B 18                  548 	.byte	24
   097C F0                  549 	.byte	-16
   097D 00                  550 	.byte	0
   097E E0                  551 	.byte	-32
   097F F0                  552 	.byte	-16
   0980 FF                  553 	.byte	-1
   0981 00                  554 	.byte	0
   0982 EC                  555 	.byte	-20
   0983 FF                  556 	.byte	-1
   0984 10                  557 	.byte	16
   0985 F8                  558 	.byte	-8
   0986 FF                  559 	.byte	-1
   0987 38                  560 	.byte	56
   0988 00                  561 	.byte	0
   0989 FF                  562 	.byte	-1
   098A 10                  563 	.byte	16
   098B 08                  564 	.byte	8
   098C FF                  565 	.byte	-1
   098D F0                  566 	.byte	-16
   098E 08                  567 	.byte	8
   098F FF                  568 	.byte	-1
   0990 C8                  569 	.byte	-56
   0991 00                  570 	.byte	0
   0992 FF                  571 	.byte	-1
   0993 F0                  572 	.byte	-16
   0994 F8                  573 	.byte	-8
   0995 00                  574 	.byte	0
   0996 58                  575 	.byte	88
   0997 00                  576 	.byte	0
   0998 FF                  577 	.byte	-1
   0999 00                  578 	.byte	0
   099A 48                  579 	.byte	72
   099B FF                  580 	.byte	-1
   099C F0                  581 	.byte	-16
   099D 08                  582 	.byte	8
   099E FF                  583 	.byte	-1
   099F D8                  584 	.byte	-40
   09A0 00                  585 	.byte	0
   09A1 00                  586 	.byte	0
   09A2 00                  587 	.byte	0
   09A3 14                  588 	.byte	20
   09A4 FF                  589 	.byte	-1
   09A5 1C                  590 	.byte	28
   09A6 EC                  591 	.byte	-20
   09A7 00                  592 	.byte	0
   09A8 1C                  593 	.byte	28
   09A9 F0                  594 	.byte	-16
   09AA FF                  595 	.byte	-1
   09AB 28                  596 	.byte	40
   09AC E4                  597 	.byte	-28
   09AD 00                  598 	.byte	0
   09AE F8                  599 	.byte	-8
   09AF 08                  600 	.byte	8
   09B0 FF                  601 	.byte	-1
   09B1 00                  602 	.byte	0
   09B2 E0                  603 	.byte	-32
   09B3 FF                  604 	.byte	-1
   09B4 F0                  605 	.byte	-16
   09B5 08                  606 	.byte	8
   09B6 FF                  607 	.byte	-1
   09B7 00                  608 	.byte	0
   09B8 20                  609 	.byte	32
   09B9 00                  610 	.byte	0
   09BA 18                  611 	.byte	24
   09BB F0                  612 	.byte	-16
   09BC FF                  613 	.byte	-1
   09BD 00                  614 	.byte	0
   09BE 28                  615 	.byte	40
   09BF 00                  616 	.byte	0
   09C0 F8                  617 	.byte	-8
   09C1 0C                  618 	.byte	12
   09C2 FF                  619 	.byte	-1
   09C3 00                  620 	.byte	0
   09C4 20                  621 	.byte	32
   09C5 FF                  622 	.byte	-1
   09C6 F0                  623 	.byte	-16
   09C7 18                  624 	.byte	24
   09C8 FF                  625 	.byte	-1
   09C9 00                  626 	.byte	0
   09CA E4                  627 	.byte	-28
   09CB 00                  628 	.byte	0
   09CC 18                  629 	.byte	24
   09CD D8                  630 	.byte	-40
   09CE FF                  631 	.byte	-1
   09CF C0                  632 	.byte	-64
   09D0 6C                  633 	.byte	108
   09D1 FF                  634 	.byte	-1
   09D2 C0                  635 	.byte	-64
   09D3 6C                  636 	.byte	108
   09D4 00                  637 	.byte	0
   09D5 08                  638 	.byte	8
   09D6 00                  639 	.byte	0
   09D7 FF                  640 	.byte	-1
   09D8 18                  641 	.byte	24
   09D9 F0                  642 	.byte	-16
   09DA FF                  643 	.byte	-1
   09DB F0                  644 	.byte	-16
   09DC F4                  645 	.byte	-12
   09DD 00                  646 	.byte	0
   09DE 90                  647 	.byte	-112
   09DF 0C                  648 	.byte	12
   09E0 FF                  649 	.byte	-1
   09E1 00                  650 	.byte	0
   09E2 50                  651 	.byte	80
   09E3 FF                  652 	.byte	-1
   09E4 18                  653 	.byte	24
   09E5 10                  654 	.byte	16
   09E6 FF                  655 	.byte	-1
   09E7 50                  656 	.byte	80
   09E8 00                  657 	.byte	0
   09E9 FF                  658 	.byte	-1
   09EA 18                  659 	.byte	24
   09EB F0                  660 	.byte	-16
   09EC FF                  661 	.byte	-1
   09ED 00                  662 	.byte	0
   09EE B0                  663 	.byte	-80
   09EF 00                  664 	.byte	0
   09F0 FC                  665 	.byte	-4
   09F1 E4                  666 	.byte	-28
   09F2 FF                  667 	.byte	-1
   09F3 30                  668 	.byte	48
   09F4 00                  669 	.byte	0
   09F5 FF                  670 	.byte	-1
   09F6 10                  671 	.byte	16
   09F7 F8                  672 	.byte	-8
   09F8 FF                  673 	.byte	-1
   09F9 00                  674 	.byte	0
   09FA B8                  675 	.byte	-72
   09FB FF                  676 	.byte	-1
   09FC F0                  677 	.byte	-16
   09FD 08                  678 	.byte	8
   09FE FF                  679 	.byte	-1
   09FF F8                  680 	.byte	-8
   0A00 00                  681 	.byte	0
   0A01 00                  682 	.byte	0
   0A02 18                  683 	.byte	24
   0A03 F8                  684 	.byte	-8
   0A04 FF                  685 	.byte	-1
   0A05 F4                  686 	.byte	-12
   0A06 F8                  687 	.byte	-8
   0A07 00                  688 	.byte	0
   0A08 DC                  689 	.byte	-36
   0A09 14                  690 	.byte	20
   0A0A FF                  691 	.byte	-1
   0A0B 18                  692 	.byte	24
   0A0C D4                  693 	.byte	-44
   0A0D FF                  694 	.byte	-1
   0A0E 00                  695 	.byte	0
   0A0F E4                  696 	.byte	-28
   0A10 FF                  697 	.byte	-1
   0A11 E8                  698 	.byte	-24
   0A12 10                  699 	.byte	16
   0A13                     700 _vl_term_3_349:
   0A13 01                  701 	.byte	1
                            702 	.globl	__player_draw_left
   0A14                     703 __player_draw_left:
   0A14 BD F3 54      [ 8]  704 	jsr	___Reset0Ref
   0A17 C6 7F         [ 2]  705 	ldb	#127
   0A19 D7 04         [ 4]  706 	stb	*_dp_VIA_t1_cnt_lo
   0A1B F6 C8 AA      [ 5]  707 	ldb	_the_player
   0A1E 4F            [ 2]  708 	clra		;zero_extendqihi: R:b -> R:d
   0A1F 1F 01         [ 6]  709 	tfr	d,x
   0A21 C6 90         [ 2]  710 	ldb	#-112
   0A23 E7 E2         [ 6]  711 	stb	,-s
   0A25 E6 89 07 4E   [ 8]  712 	ldb	_PLAYER_X_LUT,x
   0A29 BD 0B 0E      [ 8]  713 	jsr	__Moveto_d
   0A2C C6 0A         [ 2]  714 	ldb	#10
   0A2E D7 04         [ 4]  715 	stb	*_dp_VIA_t1_cnt_lo
   0A30 32 61         [ 5]  716 	leas	1,s
   0A32 8E 08 2C      [ 3]  717 	ldx	#_vl_player_left
   0A35 7E F4 10      [ 4]  718 	jmp	___Draw_VLp
                            719 	.globl	__player_draw_mid
   0A38                     720 __player_draw_mid:
   0A38 BD F3 54      [ 8]  721 	jsr	___Reset0Ref
   0A3B C6 7F         [ 2]  722 	ldb	#127
   0A3D D7 04         [ 4]  723 	stb	*_dp_VIA_t1_cnt_lo
   0A3F F6 C8 AA      [ 5]  724 	ldb	_the_player
   0A42 4F            [ 2]  725 	clra		;zero_extendqihi: R:b -> R:d
   0A43 1F 01         [ 6]  726 	tfr	d,x
   0A45 C6 90         [ 2]  727 	ldb	#-112
   0A47 E7 E2         [ 6]  728 	stb	,-s
   0A49 E6 89 07 4E   [ 8]  729 	ldb	_PLAYER_X_LUT,x
   0A4D BD 0B 0E      [ 8]  730 	jsr	__Moveto_d
   0A50 C6 10         [ 2]  731 	ldb	#16
   0A52 D7 04         [ 4]  732 	stb	*_dp_VIA_t1_cnt_lo
   0A54 8E 07 A3      [ 3]  733 	ldx	#_vl_player_mid1
   0A57 BD F4 10      [ 8]  734 	jsr	___Draw_VLp
   0A5A BD F3 54      [ 8]  735 	jsr	___Reset0Ref
   0A5D C6 7F         [ 2]  736 	ldb	#127
   0A5F D7 04         [ 4]  737 	stb	*_dp_VIA_t1_cnt_lo
   0A61 F6 C8 AA      [ 5]  738 	ldb	_the_player
   0A64 4F            [ 2]  739 	clra		;zero_extendqihi: R:b -> R:d
   0A65 1F 01         [ 6]  740 	tfr	d,x
   0A67 C6 90         [ 2]  741 	ldb	#-112
   0A69 E7 E2         [ 6]  742 	stb	,-s
   0A6B E6 89 07 4E   [ 8]  743 	ldb	_PLAYER_X_LUT,x
   0A6F BD 0B 0E      [ 8]  744 	jsr	__Moveto_d
   0A72 C6 10         [ 2]  745 	ldb	#16
   0A74 D7 04         [ 4]  746 	stb	*_dp_VIA_t1_cnt_lo
   0A76 32 62         [ 5]  747 	leas	2,s
   0A78 8E 07 E3      [ 3]  748 	ldx	#_vl_player_mid2_enhanced
   0A7B 7E F4 10      [ 4]  749 	jmp	___Draw_VLp
                            750 	.globl	__player_draw_right
   0A7E                     751 __player_draw_right:
   0A7E BD F3 54      [ 8]  752 	jsr	___Reset0Ref
   0A81 C6 7F         [ 2]  753 	ldb	#127
   0A83 D7 04         [ 4]  754 	stb	*_dp_VIA_t1_cnt_lo
   0A85 F6 C8 AA      [ 5]  755 	ldb	_the_player
   0A88 4F            [ 2]  756 	clra		;zero_extendqihi: R:b -> R:d
   0A89 1F 01         [ 6]  757 	tfr	d,x
   0A8B C6 90         [ 2]  758 	ldb	#-112
   0A8D E7 E2         [ 6]  759 	stb	,-s
   0A8F E6 89 07 4E   [ 8]  760 	ldb	_PLAYER_X_LUT,x
   0A93 BD 0B 0E      [ 8]  761 	jsr	__Moveto_d
   0A96 C6 10         [ 2]  762 	ldb	#16
   0A98 D7 04         [ 4]  763 	stb	*_dp_VIA_t1_cnt_lo
   0A9A 32 61         [ 5]  764 	leas	1,s
   0A9C 8E 09 26      [ 3]  765 	ldx	#_vl_player_right
   0A9F 7E F4 10      [ 4]  766 	jmp	___Draw_VLp
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri Jun 13 21:28:25 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L10                004B R   |   3 L6                 0037 R
  3 _PLAYER_DRAW_L     0003 GR  |   3 _PLAYER_X_LUT      0000 GR
    __Moveto_d         **** GX  |     ___Draw_VLp        **** GX
    ___Intensity_5     **** GX  |     ___Reset0Ref       **** GX
  3 __player_draw_     02C6 GR  |   3 __player_draw_     02EA GR
  3 __player_draw_     0330 GR  |   3 _check_collisi     0054 GR
    _dp_VIA_t1_cnt     **** GX  |   3 _player_change     002E GR
  3 _player_change     0040 GR  |   3 _player_draw       0018 GR
  3 _player_init       0009 GR  |   2 _the_player        0000 GR
  3 _vl_player_lef     00DE GR  |   3 _vl_player_mid     0055 GR
  3 _vl_player_mid     0095 GR  |   3 _vl_player_rig     01D8 GR
  3 _vl_term_0_46      0094 R   |   3 _vl_term_1_127     00DD R
  3 _vl_term_2_240     01D7 R   |   3 _vl_term_3_349     02C5 R

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Fri Jun 13 21:28:25 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    4   flags    0
   3 .text            size  354   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

