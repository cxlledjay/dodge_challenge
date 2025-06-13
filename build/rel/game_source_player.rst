                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	player.c
                              6 	.area	.bss
                              7 	.globl	_the_player
   C8AB                       8 _the_player:	.blkb	7
                              9 	.globl	_PLAYER_ANIMATION_FRAME_CNT_STAGE1_LUT
                             10 	.area	.text
   07FC                      11 _PLAYER_ANIMATION_FRAME_CNT_STAGE1_LUT:
   07FC 07                   12 	.byte	7
   07FD 07                   13 	.byte	7
   07FE 07                   14 	.byte	7
   07FF 07                   15 	.byte	7
   0800 07                   16 	.byte	7
   0801 07                   17 	.byte	7
   0802 07                   18 	.byte	7
   0803 07                   19 	.byte	7
   0804 07                   20 	.byte	7
   0805 07                   21 	.byte	7
   0806 07                   22 	.byte	7
                             23 	.globl	_PLAYER_ANIMATION_FRAME_CNT_STAGE2_LUT
   0807                      24 _PLAYER_ANIMATION_FRAME_CNT_STAGE2_LUT:
   0807 06                   25 	.byte	6
   0808 06                   26 	.byte	6
   0809 06                   27 	.byte	6
   080A 06                   28 	.byte	6
   080B 06                   29 	.byte	6
   080C 06                   30 	.byte	6
   080D 06                   31 	.byte	6
   080E 06                   32 	.byte	6
   080F 06                   33 	.byte	6
   0810 06                   34 	.byte	6
   0811 06                   35 	.byte	6
                             36 	.globl	_PLAYER_STATIC_X_LUT
   0812                      37 _PLAYER_STATIC_X_LUT:
   0812 AE                   38 	.byte	-82
   0813 00                   39 	.byte	0
   0814 52                   40 	.byte	82
                             41 	.globl	_PLAYER_DRAW_LUT
   0815                      42 _PLAYER_DRAW_LUT:
   0815 0F 14                43 	.word	__player_draw_left
   0817 0E DC                44 	.word	__player_draw_mid
   0819 0F 67                45 	.word	__player_draw_right
                             46 	.globl	__SP1_LEFT_MID_X_LUT_2
   081B                      47 __SP1_LEFT_MID_X_LUT_2:
   081B FA                   48 	.byte	-6
   081C F4                   49 	.byte	-12
   081D EE                   50 	.byte	-18
   081E E9                   51 	.byte	-23
   081F E3                   52 	.byte	-29
   0820 DD                   53 	.byte	-35
                             54 	.globl	__SP1_MID_RIGHT_X_LUT_2
   0821                      55 __SP1_MID_RIGHT_X_LUT_2:
   0821 4C                   56 	.byte	76
   0822 46                   57 	.byte	70
   0823 40                   58 	.byte	64
   0824 3B                   59 	.byte	59
   0825 35                   60 	.byte	53
   0826 2F                   61 	.byte	47
                             62 	.globl	__SP1_RIGHT_MID_X_LUT_2
   0827                      63 __SP1_RIGHT_MID_X_LUT_2:
   0827 06                   64 	.byte	6
   0828 0C                   65 	.byte	12
   0829 12                   66 	.byte	18
   082A 17                   67 	.byte	23
   082B 1D                   68 	.byte	29
   082C 23                   69 	.byte	35
                             70 	.globl	__SP1_MID_LEFT_X_LUT_2
   082D                      71 __SP1_MID_LEFT_X_LUT_2:
   082D B4                   72 	.byte	-76
   082E BA                   73 	.byte	-70
   082F C0                   74 	.byte	-64
   0830 C5                   75 	.byte	-59
   0831 CB                   76 	.byte	-53
   0832 D1                   77 	.byte	-47
                             78 	.globl	_player_init
   0833                      79 _player_init:
   0833 8E 08 4B      [ 3]   80 	ldx	#_player_draw
   0836 BF C8 B0      [ 6]   81 	stx	_the_player+5
   0839 7F C8 AF      [ 7]   82 	clr	_the_player+4
   083C CC 00 00      [ 3]   83 	ldd	#0
   083F FD C8 AD      [ 6]   84 	std	_the_player+2
   0842 7F C8 AC      [ 7]   85 	clr	_the_player+1
   0845 C6 01         [ 2]   86 	ldb	#1
   0847 F7 C8 AB      [ 5]   87 	stb	_the_player
   084A 39            [ 5]   88 	rts
                             89 	.globl	_player_draw
   084B                      90 _player_draw:
   084B 32 7E         [ 5]   91 	leas	-2,s
   084D BD F2 A5      [ 8]   92 	jsr	___Intensity_5F
   0850 F6 C8 AB      [ 5]   93 	ldb	_the_player
   0853 4F            [ 2]   94 	clra		;zero_extendqihi: R:b -> R:d
   0854 ED E4         [ 5]   95 	std	,s
   0856 58            [ 2]   96 	aslb
   0857 49            [ 2]   97 	rola
   0858 1F 01         [ 6]   98 	tfr	d,x
   085A AD 99 08 15   [14]   99 	jsr	[_PLAYER_DRAW_LUT,x]
   085E 32 62         [ 5]  100 	leas	2,s
   0860 39            [ 5]  101 	rts
                            102 	.globl	_vl_player_mid1
   0861                     103 _vl_player_mid1:
   0861 00                  104 	.byte	0
   0862 A0                  105 	.byte	-96
   0863 B0                  106 	.byte	-80
   0864 FF                  107 	.byte	-1
   0865 00                  108 	.byte	0
   0866 B0                  109 	.byte	-80
   0867 FF                  110 	.byte	-1
   0868 7F                  111 	.byte	127
   0869 00                  112 	.byte	0
   086A FF                  113 	.byte	-1
   086B 00                  114 	.byte	0
   086C 50                  115 	.byte	80
   086D FF                  116 	.byte	-1
   086E 80                  117 	.byte	-128
   086F 00                  118 	.byte	0
   0870 00                  119 	.byte	0
   0871 10                  120 	.byte	16
   0872 00                  121 	.byte	0
   0873 FF                  122 	.byte	-1
   0874 10                  123 	.byte	16
   0875 3C                  124 	.byte	60
   0876 00                  125 	.byte	0
   0877 00                  126 	.byte	0
   0878 28                  127 	.byte	40
   0879 FF                  128 	.byte	-1
   087A F0                  129 	.byte	-16
   087B 3C                  130 	.byte	60
   087C 00                  131 	.byte	0
   087D F0                  132 	.byte	-16
   087E 00                  133 	.byte	0
   087F FF                  134 	.byte	-1
   0880 00                  135 	.byte	0
   0881 50                  136 	.byte	80
   0882 FF                  137 	.byte	-1
   0883 7F                  138 	.byte	127
   0884 00                  139 	.byte	0
   0885 FF                  140 	.byte	-1
   0886 00                  141 	.byte	0
   0887 B0                  142 	.byte	-80
   0888 FF                  143 	.byte	-1
   0889 80                  144 	.byte	-128
   088A 00                  145 	.byte	0
   088B 00                  146 	.byte	0
   088C 20                  147 	.byte	32
   088D 00                  148 	.byte	0
   088E FF                  149 	.byte	-1
   088F 00                  150 	.byte	0
   0890 B0                  151 	.byte	-80
   0891 FF                  152 	.byte	-1
   0892 00                  153 	.byte	0
   0893 B0                  154 	.byte	-80
   0894 00                  155 	.byte	0
   0895 40                  156 	.byte	64
   0896 00                  157 	.byte	0
   0897 FF                  158 	.byte	-1
   0898 10                  159 	.byte	16
   0899 3C                  160 	.byte	60
   089A FF                  161 	.byte	-1
   089B 00                  162 	.byte	0
   089C 28                  163 	.byte	40
   089D FF                  164 	.byte	-1
   089E F0                  165 	.byte	-16
   089F 3C                  166 	.byte	60
   08A0                     167 _vl_term_0_46:
   08A0 01                  168 	.byte	1
                            169 	.globl	_vl_player_mid2
   08A1                     170 _vl_player_mid2:
   08A1 00                  171 	.byte	0
   08A2 20                  172 	.byte	32
   08A3 88                  173 	.byte	-120
   08A4 FF                  174 	.byte	-1
   08A5 28                  175 	.byte	40
   08A6 00                  176 	.byte	0
   08A7 FF                  177 	.byte	-1
   08A8 00                  178 	.byte	0
   08A9 3C                  179 	.byte	60
   08AA FF                  180 	.byte	-1
   08AB DC                  181 	.byte	-36
   08AC 00                  182 	.byte	0
   08AD 00                  183 	.byte	0
   08AE E0                  184 	.byte	-32
   08AF EC                  185 	.byte	-20
   08B0 FF                  186 	.byte	-1
   08B1 70                  187 	.byte	112
   08B2 40                  188 	.byte	64
   08B3 FF                  189 	.byte	-1
   08B4 00                  190 	.byte	0
   08B5 20                  191 	.byte	32
   08B6 FF                  192 	.byte	-1
   08B7 90                  193 	.byte	-112
   08B8 40                  194 	.byte	64
   08B9 00                  195 	.byte	0
   08BA 20                  196 	.byte	32
   08BB 28                  197 	.byte	40
   08BC FF                  198 	.byte	-1
   08BD 28                  199 	.byte	40
   08BE 00                  200 	.byte	0
   08BF FF                  201 	.byte	-1
   08C0 00                  202 	.byte	0
   08C1 C4                  203 	.byte	-60
   08C2 FF                  204 	.byte	-1
   08C3 DC                  205 	.byte	-36
   08C4 00                  206 	.byte	0
   08C5 00                  207 	.byte	0
   08C6 2D                  208 	.byte	45
   08C7 E4                  209 	.byte	-28
   08C8 FF                  210 	.byte	-1
   08C9 00                  211 	.byte	0
   08CA 30                  212 	.byte	48
   08CB FF                  213 	.byte	-1
   08CC 10                  214 	.byte	16
   08CD F8                  215 	.byte	-8
   08CE FF                  216 	.byte	-1
   08CF 00                  217 	.byte	0
   08D0 D0                  218 	.byte	-48
   08D1 00                  219 	.byte	0
   08D2 00                  220 	.byte	0
   08D3 D0                  221 	.byte	-48
   08D4 FF                  222 	.byte	-1
   08D5 00                  223 	.byte	0
   08D6 D0                  224 	.byte	-48
   08D7 FF                  225 	.byte	-1
   08D8 F0                  226 	.byte	-16
   08D9 F8                  227 	.byte	-8
   08DA FF                  228 	.byte	-1
   08DB 00                  229 	.byte	0
   08DC 30                  230 	.byte	48
   08DD 00                  231 	.byte	0
   08DE E4                  232 	.byte	-28
   08DF 0C                  233 	.byte	12
   08E0 FF                  234 	.byte	-1
   08E1 10                  235 	.byte	16
   08E2 08                  236 	.byte	8
   08E3 FF                  237 	.byte	-1
   08E4 00                  238 	.byte	0
   08E5 18                  239 	.byte	24
   08E6 FF                  240 	.byte	-1
   08E7 F0                  241 	.byte	-16
   08E8 08                  242 	.byte	8
   08E9                     243 _vl_term_1_83:
   08E9 01                  244 	.byte	1
                            245 	.globl	_vl_player_left1
   08EA                     246 _vl_player_left1:
   08EA 00                  247 	.byte	0
   08EB 08                  248 	.byte	8
   08EC 50                  249 	.byte	80
   08ED FF                  250 	.byte	-1
   08EE B0                  251 	.byte	-80
   08EF 00                  252 	.byte	0
   08F0 FF                  253 	.byte	-1
   08F1 E8                  254 	.byte	-24
   08F2 10                  255 	.byte	16
   08F3 FF                  256 	.byte	-1
   08F4 00                  257 	.byte	0
   08F5 50                  258 	.byte	80
   08F6 FF                  259 	.byte	-1
   08F7 18                  260 	.byte	24
   08F8 10                  261 	.byte	16
   08F9 FF                  262 	.byte	-1
   08FA 50                  263 	.byte	80
   08FB 00                  264 	.byte	0
   08FC FF                  265 	.byte	-1
   08FD 18                  266 	.byte	24
   08FE F0                  267 	.byte	-16
   08FF FF                  268 	.byte	-1
   0900 00                  269 	.byte	0
   0901 B0                  270 	.byte	-80
   0902 FF                  271 	.byte	-1
   0903 E8                  272 	.byte	-24
   0904 F0                  273 	.byte	-16
   0905 00                  274 	.byte	0
   0906 F8                  275 	.byte	-8
   0907 00                  276 	.byte	0
   0908 FF                  277 	.byte	-1
   0909 10                  278 	.byte	16
   090A C4                  279 	.byte	-60
   090B FF                  280 	.byte	-1
   090C 00                  281 	.byte	0
   090D D8                  282 	.byte	-40
   090E FF                  283 	.byte	-1
   090F F0                  284 	.byte	-16
   0910 C4                  285 	.byte	-60
   0911 00                  286 	.byte	0
   0912 08                  287 	.byte	8
   0913 00                  288 	.byte	0
   0914 FF                  289 	.byte	-1
   0915 B0                  290 	.byte	-80
   0916 00                  291 	.byte	0
   0917 FF                  292 	.byte	-1
   0918 E8                  293 	.byte	-24
   0919 10                  294 	.byte	16
   091A FF                  295 	.byte	-1
   091B 18                  296 	.byte	24
   091C 10                  297 	.byte	16
   091D FF                  298 	.byte	-1
   091E 08                  299 	.byte	8
   091F 00                  300 	.byte	0
   0920 00                  301 	.byte	0
   0921 F0                  302 	.byte	-16
   0922 E8                  303 	.byte	-24
   0923 FF                  304 	.byte	-1
   0924 10                  305 	.byte	16
   0925 34                  306 	.byte	52
   0926 00                  307 	.byte	0
   0927 00                  308 	.byte	0
   0928 C4                  309 	.byte	-60
   0929 FF                  310 	.byte	-1
   092A 00                  311 	.byte	0
   092B 50                  312 	.byte	80
   092C FF                  313 	.byte	-1
   092D 00                  314 	.byte	0
   092E 50                  315 	.byte	80
   092F 00                  316 	.byte	0
   0930 00                  317 	.byte	0
   0931 C4                  318 	.byte	-60
   0932 FF                  319 	.byte	-1
   0933 F0                  320 	.byte	-16
   0934 40                  321 	.byte	64
   0935                     322 _vl_term_2_123:
   0935 01                  323 	.byte	1
                            324 	.globl	_vl_player_left2
   0936                     325 _vl_player_left2:
   0936 00                  326 	.byte	0
   0937 D0                  327 	.byte	-48
   0938 58                  328 	.byte	88
   0939 00                  329 	.byte	0
   093A D0                  330 	.byte	-48
   093B 58                  331 	.byte	88
   093C FF                  332 	.byte	-1
   093D 18                  333 	.byte	24
   093E F0                  334 	.byte	-16
   093F FF                  335 	.byte	-1
   0940 50                  336 	.byte	80
   0941 00                  337 	.byte	0
   0942 FF                  338 	.byte	-1
   0943 18                  339 	.byte	24
   0944 10                  340 	.byte	16
   0945 00                  341 	.byte	0
   0946 E0                  342 	.byte	-32
   0947 10                  343 	.byte	16
   0948 FF                  344 	.byte	-1
   0949 00                  345 	.byte	0
   094A 14                  346 	.byte	20
   094B FF                  347 	.byte	-1
   094C 10                  348 	.byte	16
   094D 08                  349 	.byte	8
   094E FF                  350 	.byte	-1
   094F 38                  351 	.byte	56
   0950 00                  352 	.byte	0
   0951 FF                  353 	.byte	-1
   0952 10                  354 	.byte	16
   0953 F8                  355 	.byte	-8
   0954 FF                  356 	.byte	-1
   0955 F0                  357 	.byte	-16
   0956 F8                  358 	.byte	-8
   0957 FF                  359 	.byte	-1
   0958 C8                  360 	.byte	-56
   0959 00                  361 	.byte	0
   095A FF                  362 	.byte	-1
   095B F0                  363 	.byte	-16
   095C 08                  364 	.byte	8
   095D 00                  365 	.byte	0
   095E 58                  366 	.byte	88
   095F 00                  367 	.byte	0
   0960 FF                  368 	.byte	-1
   0961 00                  369 	.byte	0
   0962 B8                  370 	.byte	-72
   0963 FF                  371 	.byte	-1
   0964 F0                  372 	.byte	-16
   0965 F8                  373 	.byte	-8
   0966 FF                  374 	.byte	-1
   0967 D8                  375 	.byte	-40
   0968 00                  376 	.byte	0
   0969 00                  377 	.byte	0
   096A 00                  378 	.byte	0
   096B EC                  379 	.byte	-20
   096C FF                  380 	.byte	-1
   096D 1C                  381 	.byte	28
   096E 14                  382 	.byte	20
   096F 00                  383 	.byte	0
   0970 1C                  384 	.byte	28
   0971 10                  385 	.byte	16
   0972 FF                  386 	.byte	-1
   0973 28                  387 	.byte	40
   0974 1C                  388 	.byte	28
   0975 FF                  389 	.byte	-1
   0976 00                  390 	.byte	0
   0977 D8                  391 	.byte	-40
   0978 FF                  392 	.byte	-1
   0979 C0                  393 	.byte	-64
   097A 94                  394 	.byte	-108
   097B FF                  395 	.byte	-1
   097C C0                  396 	.byte	-64
   097D 94                  397 	.byte	-108
   097E 00                  398 	.byte	0
   097F 34                  399 	.byte	52
   0980 58                  400 	.byte	88
   0981 00                  401 	.byte	0
   0982 34                  402 	.byte	52
   0983 58                  403 	.byte	88
   0984 FF                  404 	.byte	-1
   0985 00                  405 	.byte	0
   0986 E4                  406 	.byte	-28
   0987 FF                  407 	.byte	-1
   0988 10                  408 	.byte	16
   0989 18                  409 	.byte	24
   098A FF                  410 	.byte	-1
   098B 00                  411 	.byte	0
   098C 20                  412 	.byte	32
   098D 00                  413 	.byte	0
   098E 00                  414 	.byte	0
   098F 2E                  415 	.byte	46
   0990 FF                  416 	.byte	-1
   0991 00                  417 	.byte	0
   0992 20                  418 	.byte	32
   0993 FF                  419 	.byte	-1
   0994 F0                  420 	.byte	-16
   0995 F8                  421 	.byte	-8
   0996 FF                  422 	.byte	-1
   0997 00                  423 	.byte	0
   0998 E0                  424 	.byte	-32
   0999                     425 _vl_term_3_170:
   0999 01                  426 	.byte	1
                            427 	.globl	_vl_player_left3
   099A                     428 _vl_player_left3:
   099A 00                  429 	.byte	0
   099B 08                  430 	.byte	8
   099C B0                  431 	.byte	-80
   099D FF                  432 	.byte	-1
   099E 18                  433 	.byte	24
   099F 10                  434 	.byte	16
   09A0 FF                  435 	.byte	-1
   09A1 F0                  436 	.byte	-16
   09A2 0C                  437 	.byte	12
   09A3 00                  438 	.byte	0
   09A4 90                  439 	.byte	-112
   09A5 F4                  440 	.byte	-12
   09A6 FF                  441 	.byte	-1
   09A7 00                  442 	.byte	0
   09A8 B0                  443 	.byte	-80
   09A9 FF                  444 	.byte	-1
   09AA 18                  445 	.byte	24
   09AB F0                  446 	.byte	-16
   09AC FF                  447 	.byte	-1
   09AD 50                  448 	.byte	80
   09AE 00                  449 	.byte	0
   09AF FF                  450 	.byte	-1
   09B0 18                  451 	.byte	24
   09B1 10                  452 	.byte	16
   09B2 FF                  453 	.byte	-1
   09B3 00                  454 	.byte	0
   09B4 50                  455 	.byte	80
   09B5 00                  456 	.byte	0
   09B6 FC                  457 	.byte	-4
   09B7 1C                  458 	.byte	28
   09B8 FF                  459 	.byte	-1
   09B9 30                  460 	.byte	48
   09BA 00                  461 	.byte	0
   09BB FF                  462 	.byte	-1
   09BC 10                  463 	.byte	16
   09BD 08                  464 	.byte	8
   09BE FF                  465 	.byte	-1
   09BF 00                  466 	.byte	0
   09C0 48                  467 	.byte	72
   09C1 FF                  468 	.byte	-1
   09C2 F0                  469 	.byte	-16
   09C3 F8                  470 	.byte	-8
   09C4 FF                  471 	.byte	-1
   09C5 F8                  472 	.byte	-8
   09C6 00                  473 	.byte	0
   09C7 00                  474 	.byte	0
   09C8 18                  475 	.byte	24
   09C9 08                  476 	.byte	8
   09CA FF                  477 	.byte	-1
   09CB F4                  478 	.byte	-12
   09CC 08                  479 	.byte	8
   09CD 00                  480 	.byte	0
   09CE DC                  481 	.byte	-36
   09CF EC                  482 	.byte	-20
   09D0 FF                  483 	.byte	-1
   09D1 18                  484 	.byte	24
   09D2 2C                  485 	.byte	44
   09D3 FF                  486 	.byte	-1
   09D4 00                  487 	.byte	0
   09D5 1C                  488 	.byte	28
   09D6 FF                  489 	.byte	-1
   09D7 E8                  490 	.byte	-24
   09D8 F0                  491 	.byte	-16
   09D9                     492 _vl_term_4_203:
   09D9 01                  493 	.byte	1
                            494 	.globl	_vl_player_right1
   09DA                     495 _vl_player_right1:
   09DA 00                  496 	.byte	0
   09DB 08                  497 	.byte	8
   09DC B0                  498 	.byte	-80
   09DD FF                  499 	.byte	-1
   09DE B0                  500 	.byte	-80
   09DF 00                  501 	.byte	0
   09E0 FF                  502 	.byte	-1
   09E1 E8                  503 	.byte	-24
   09E2 F0                  504 	.byte	-16
   09E3 FF                  505 	.byte	-1
   09E4 00                  506 	.byte	0
   09E5 B0                  507 	.byte	-80
   09E6 FF                  508 	.byte	-1
   09E7 18                  509 	.byte	24
   09E8 F0                  510 	.byte	-16
   09E9 FF                  511 	.byte	-1
   09EA 50                  512 	.byte	80
   09EB 00                  513 	.byte	0
   09EC FF                  514 	.byte	-1
   09ED 18                  515 	.byte	24
   09EE 10                  516 	.byte	16
   09EF FF                  517 	.byte	-1
   09F0 00                  518 	.byte	0
   09F1 50                  519 	.byte	80
   09F2 FF                  520 	.byte	-1
   09F3 E8                  521 	.byte	-24
   09F4 10                  522 	.byte	16
   09F5 00                  523 	.byte	0
   09F6 F8                  524 	.byte	-8
   09F7 00                  525 	.byte	0
   09F8 FF                  526 	.byte	-1
   09F9 10                  527 	.byte	16
   09FA 3C                  528 	.byte	60
   09FB FF                  529 	.byte	-1
   09FC 00                  530 	.byte	0
   09FD 28                  531 	.byte	40
   09FE FF                  532 	.byte	-1
   09FF F0                  533 	.byte	-16
   0A00 3C                  534 	.byte	60
   0A01 00                  535 	.byte	0
   0A02 08                  536 	.byte	8
   0A03 00                  537 	.byte	0
   0A04 FF                  538 	.byte	-1
   0A05 B0                  539 	.byte	-80
   0A06 00                  540 	.byte	0
   0A07 FF                  541 	.byte	-1
   0A08 E8                  542 	.byte	-24
   0A09 F0                  543 	.byte	-16
   0A0A FF                  544 	.byte	-1
   0A0B 18                  545 	.byte	24
   0A0C F0                  546 	.byte	-16
   0A0D FF                  547 	.byte	-1
   0A0E 08                  548 	.byte	8
   0A0F 00                  549 	.byte	0
   0A10 00                  550 	.byte	0
   0A11 F0                  551 	.byte	-16
   0A12 18                  552 	.byte	24
   0A13 FF                  553 	.byte	-1
   0A14 10                  554 	.byte	16
   0A15 CC                  555 	.byte	-52
   0A16 00                  556 	.byte	0
   0A17 00                  557 	.byte	0
   0A18 3C                  558 	.byte	60
   0A19 FF                  559 	.byte	-1
   0A1A 00                  560 	.byte	0
   0A1B B0                  561 	.byte	-80
   0A1C FF                  562 	.byte	-1
   0A1D 00                  563 	.byte	0
   0A1E B0                  564 	.byte	-80
   0A1F 00                  565 	.byte	0
   0A20 00                  566 	.byte	0
   0A21 3C                  567 	.byte	60
   0A22 FF                  568 	.byte	-1
   0A23 F0                  569 	.byte	-16
   0A24 C0                  570 	.byte	-64
   0A25                     571 _vl_term_5_243:
   0A25 01                  572 	.byte	1
                            573 	.globl	_vl_player_right2
   0A26                     574 _vl_player_right2:
   0A26 00                  575 	.byte	0
   0A27 D0                  576 	.byte	-48
   0A28 A8                  577 	.byte	-88
   0A29 00                  578 	.byte	0
   0A2A D0                  579 	.byte	-48
   0A2B A8                  580 	.byte	-88
   0A2C FF                  581 	.byte	-1
   0A2D 18                  582 	.byte	24
   0A2E 10                  583 	.byte	16
   0A2F FF                  584 	.byte	-1
   0A30 50                  585 	.byte	80
   0A31 00                  586 	.byte	0
   0A32 FF                  587 	.byte	-1
   0A33 18                  588 	.byte	24
   0A34 F0                  589 	.byte	-16
   0A35 00                  590 	.byte	0
   0A36 E0                  591 	.byte	-32
   0A37 F0                  592 	.byte	-16
   0A38 FF                  593 	.byte	-1
   0A39 00                  594 	.byte	0
   0A3A EC                  595 	.byte	-20
   0A3B FF                  596 	.byte	-1
   0A3C 10                  597 	.byte	16
   0A3D F8                  598 	.byte	-8
   0A3E FF                  599 	.byte	-1
   0A3F 38                  600 	.byte	56
   0A40 00                  601 	.byte	0
   0A41 FF                  602 	.byte	-1
   0A42 10                  603 	.byte	16
   0A43 08                  604 	.byte	8
   0A44 FF                  605 	.byte	-1
   0A45 F0                  606 	.byte	-16
   0A46 08                  607 	.byte	8
   0A47 FF                  608 	.byte	-1
   0A48 C8                  609 	.byte	-56
   0A49 00                  610 	.byte	0
   0A4A FF                  611 	.byte	-1
   0A4B F0                  612 	.byte	-16
   0A4C F8                  613 	.byte	-8
   0A4D 00                  614 	.byte	0
   0A4E 58                  615 	.byte	88
   0A4F 00                  616 	.byte	0
   0A50 FF                  617 	.byte	-1
   0A51 00                  618 	.byte	0
   0A52 48                  619 	.byte	72
   0A53 FF                  620 	.byte	-1
   0A54 F0                  621 	.byte	-16
   0A55 08                  622 	.byte	8
   0A56 FF                  623 	.byte	-1
   0A57 D8                  624 	.byte	-40
   0A58 00                  625 	.byte	0
   0A59 00                  626 	.byte	0
   0A5A 00                  627 	.byte	0
   0A5B 14                  628 	.byte	20
   0A5C FF                  629 	.byte	-1
   0A5D 1C                  630 	.byte	28
   0A5E EC                  631 	.byte	-20
   0A5F 00                  632 	.byte	0
   0A60 1C                  633 	.byte	28
   0A61 F0                  634 	.byte	-16
   0A62 FF                  635 	.byte	-1
   0A63 28                  636 	.byte	40
   0A64 E4                  637 	.byte	-28
   0A65 FF                  638 	.byte	-1
   0A66 00                  639 	.byte	0
   0A67 28                  640 	.byte	40
   0A68 FF                  641 	.byte	-1
   0A69 C0                  642 	.byte	-64
   0A6A 6C                  643 	.byte	108
   0A6B FF                  644 	.byte	-1
   0A6C C0                  645 	.byte	-64
   0A6D 6C                  646 	.byte	108
   0A6E 00                  647 	.byte	0
   0A6F 34                  648 	.byte	52
   0A70 A8                  649 	.byte	-88
   0A71 00                  650 	.byte	0
   0A72 34                  651 	.byte	52
   0A73 A8                  652 	.byte	-88
   0A74 FF                  653 	.byte	-1
   0A75 00                  654 	.byte	0
   0A76 1C                  655 	.byte	28
   0A77 FF                  656 	.byte	-1
   0A78 10                  657 	.byte	16
   0A79 E8                  658 	.byte	-24
   0A7A FF                  659 	.byte	-1
   0A7B 00                  660 	.byte	0
   0A7C E0                  661 	.byte	-32
   0A7D 00                  662 	.byte	0
   0A7E 00                  663 	.byte	0
   0A7F D2                  664 	.byte	-46
   0A80 FF                  665 	.byte	-1
   0A81 00                  666 	.byte	0
   0A82 E0                  667 	.byte	-32
   0A83 FF                  668 	.byte	-1
   0A84 F0                  669 	.byte	-16
   0A85 08                  670 	.byte	8
   0A86 FF                  671 	.byte	-1
   0A87 00                  672 	.byte	0
   0A88 20                  673 	.byte	32
   0A89                     674 _vl_term_6_290:
   0A89 01                  675 	.byte	1
                            676 	.globl	_vl_player_right3
   0A8A                     677 _vl_player_right3:
   0A8A 00                  678 	.byte	0
   0A8B 08                  679 	.byte	8
   0A8C 50                  680 	.byte	80
   0A8D FF                  681 	.byte	-1
   0A8E 18                  682 	.byte	24
   0A8F F0                  683 	.byte	-16
   0A90 FF                  684 	.byte	-1
   0A91 F0                  685 	.byte	-16
   0A92 F4                  686 	.byte	-12
   0A93 00                  687 	.byte	0
   0A94 90                  688 	.byte	-112
   0A95 0C                  689 	.byte	12
   0A96 FF                  690 	.byte	-1
   0A97 00                  691 	.byte	0
   0A98 50                  692 	.byte	80
   0A99 FF                  693 	.byte	-1
   0A9A 18                  694 	.byte	24
   0A9B 10                  695 	.byte	16
   0A9C FF                  696 	.byte	-1
   0A9D 50                  697 	.byte	80
   0A9E 00                  698 	.byte	0
   0A9F FF                  699 	.byte	-1
   0AA0 18                  700 	.byte	24
   0AA1 F0                  701 	.byte	-16
   0AA2 FF                  702 	.byte	-1
   0AA3 00                  703 	.byte	0
   0AA4 B0                  704 	.byte	-80
   0AA5 00                  705 	.byte	0
   0AA6 FC                  706 	.byte	-4
   0AA7 E4                  707 	.byte	-28
   0AA8 FF                  708 	.byte	-1
   0AA9 30                  709 	.byte	48
   0AAA 00                  710 	.byte	0
   0AAB FF                  711 	.byte	-1
   0AAC 10                  712 	.byte	16
   0AAD F8                  713 	.byte	-8
   0AAE FF                  714 	.byte	-1
   0AAF 00                  715 	.byte	0
   0AB0 B8                  716 	.byte	-72
   0AB1 FF                  717 	.byte	-1
   0AB2 F0                  718 	.byte	-16
   0AB3 08                  719 	.byte	8
   0AB4 FF                  720 	.byte	-1
   0AB5 F8                  721 	.byte	-8
   0AB6 00                  722 	.byte	0
   0AB7 00                  723 	.byte	0
   0AB8 18                  724 	.byte	24
   0AB9 F8                  725 	.byte	-8
   0ABA FF                  726 	.byte	-1
   0ABB F4                  727 	.byte	-12
   0ABC F8                  728 	.byte	-8
   0ABD 00                  729 	.byte	0
   0ABE DC                  730 	.byte	-36
   0ABF 14                  731 	.byte	20
   0AC0 FF                  732 	.byte	-1
   0AC1 18                  733 	.byte	24
   0AC2 D4                  734 	.byte	-44
   0AC3 FF                  735 	.byte	-1
   0AC4 00                  736 	.byte	0
   0AC5 E4                  737 	.byte	-28
   0AC6 FF                  738 	.byte	-1
   0AC7 E8                  739 	.byte	-24
   0AC8 10                  740 	.byte	16
   0AC9                     741 _vl_term_7_323:
   0AC9 01                  742 	.byte	1
                            743 	.globl	_player_change_left_to_mid_step1
   0ACA                     744 _player_change_left_to_mid_step1:
   0ACA 32 7D         [ 5]  745 	leas	-3,s
   0ACC F6 C8 AF      [ 5]  746 	ldb	_the_player+4
   0ACF E7 E4         [ 4]  747 	stb	,s
   0AD1 4F            [ 2]  748 	clra		;zero_extendqihi: R:b -> R:d
   0AD2 ED 61         [ 6]  749 	std	1,s
   0AD4 1F 01         [ 6]  750 	tfr	d,x
   0AD6 1E 01         [ 8]  751 	exg	d,x
   0AD8 F3 C8 AD      [ 7]  752 	addd	_the_player+2; addhi3,3
   0ADB 1E 01         [ 8]  753 	exg	d,x
   0ADD E6 84         [ 4]  754 	ldb	,x
   0ADF F7 C8 AC      [ 5]  755 	stb	_the_player+1
   0AE2 E6 E4         [ 4]  756 	ldb	,s
   0AE4 5A            [ 2]  757 	decb
   0AE5 F7 C8 AF      [ 5]  758 	stb	_the_player+4
   0AE8 BD F2 A5      [ 8]  759 	jsr	___Intensity_5F
   0AEB BD F3 54      [ 8]  760 	jsr	___Reset0Ref
   0AEE C6 7F         [ 2]  761 	ldb	#127
   0AF0 D7 04         [ 4]  762 	stb	*_dp_VIA_t1_cnt_lo
   0AF2 CB 11         [ 2]  763 	addb	#17
   0AF4 E7 E2         [ 6]  764 	stb	,-s
   0AF6 F6 C8 AC      [ 5]  765 	ldb	_the_player+1
   0AF9 BD 10 5E      [ 8]  766 	jsr	__Moveto_d
   0AFC C6 10         [ 2]  767 	ldb	#16
   0AFE D7 04         [ 4]  768 	stb	*_dp_VIA_t1_cnt_lo
   0B00 8E 08 EA      [ 3]  769 	ldx	#_vl_player_left1
   0B03 BD F4 10      [ 8]  770 	jsr	___Draw_VLp
   0B06 BD F3 54      [ 8]  771 	jsr	___Reset0Ref
   0B09 C6 7F         [ 2]  772 	ldb	#127
   0B0B D7 04         [ 4]  773 	stb	*_dp_VIA_t1_cnt_lo
   0B0D CB 11         [ 2]  774 	addb	#17
   0B0F E7 E2         [ 6]  775 	stb	,-s
   0B11 F6 C8 AC      [ 5]  776 	ldb	_the_player+1
   0B14 BD 10 5E      [ 8]  777 	jsr	__Moveto_d
   0B17 C6 10         [ 2]  778 	ldb	#16
   0B19 D7 04         [ 4]  779 	stb	*_dp_VIA_t1_cnt_lo
   0B1B 8E 09 36      [ 3]  780 	ldx	#_vl_player_left2
   0B1E BD F4 10      [ 8]  781 	jsr	___Draw_VLp
   0B21 BD F3 54      [ 8]  782 	jsr	___Reset0Ref
   0B24 C6 7F         [ 2]  783 	ldb	#127
   0B26 D7 04         [ 4]  784 	stb	*_dp_VIA_t1_cnt_lo
   0B28 CB 11         [ 2]  785 	addb	#17
   0B2A E7 E2         [ 6]  786 	stb	,-s
   0B2C F6 C8 AC      [ 5]  787 	ldb	_the_player+1
   0B2F BD 10 5E      [ 8]  788 	jsr	__Moveto_d
   0B32 C6 10         [ 2]  789 	ldb	#16
   0B34 D7 04         [ 4]  790 	stb	*_dp_VIA_t1_cnt_lo
   0B36 8E 09 9A      [ 3]  791 	ldx	#_vl_player_left3
   0B39 BD F4 10      [ 8]  792 	jsr	___Draw_VLp
   0B3C 32 63         [ 5]  793 	leas	3,s
   0B3E 7D C8 AF      [ 7]  794 	tst	_the_player+4
   0B41 26 19         [ 3]  795 	bne	L7
   0B43 8E 0B 5F      [ 3]  796 	ldx	#_player_change_left_to_mid_step2
   0B46 BF C8 B0      [ 6]  797 	stx	_the_player+5
   0B49 F6 C8 A5      [ 5]  798 	ldb	_the_game+2
   0B4C 4F            [ 2]  799 	clra		;zero_extendqihi: R:b -> R:d
   0B4D 1F 01         [ 6]  800 	tfr	d,x
   0B4F E6 89 08 07   [ 8]  801 	ldb	_PLAYER_ANIMATION_FRAME_CNT_STAGE2_LUT,x
   0B53 F7 C8 AF      [ 5]  802 	stb	_the_player+4
   0B56 8E 08 1B      [ 3]  803 	ldx	#__SP1_LEFT_MID_X_LUT_2
   0B59 BF C8 AD      [ 6]  804 	stx	_the_player+2
   0B5C                     805 L7:
   0B5C 32 63         [ 5]  806 	leas	3,s
   0B5E 39            [ 5]  807 	rts
                            808 	.globl	_player_change_left_to_mid_step2
   0B5F                     809 _player_change_left_to_mid_step2:
   0B5F 32 7D         [ 5]  810 	leas	-3,s
   0B61 F6 C8 AF      [ 5]  811 	ldb	_the_player+4
   0B64 E7 E4         [ 4]  812 	stb	,s
   0B66 4F            [ 2]  813 	clra		;zero_extendqihi: R:b -> R:d
   0B67 ED 61         [ 6]  814 	std	1,s
   0B69 1F 01         [ 6]  815 	tfr	d,x
   0B6B 1E 01         [ 8]  816 	exg	d,x
   0B6D F3 C8 AD      [ 7]  817 	addd	_the_player+2; addhi3,3
   0B70 1E 01         [ 8]  818 	exg	d,x
   0B72 E6 84         [ 4]  819 	ldb	,x
   0B74 F7 C8 AC      [ 5]  820 	stb	_the_player+1
   0B77 E6 E4         [ 4]  821 	ldb	,s
   0B79 5A            [ 2]  822 	decb
   0B7A F7 C8 AF      [ 5]  823 	stb	_the_player+4
   0B7D BD F2 A5      [ 8]  824 	jsr	___Intensity_5F
   0B80 BD F3 54      [ 8]  825 	jsr	___Reset0Ref
   0B83 C6 7F         [ 2]  826 	ldb	#127
   0B85 D7 04         [ 4]  827 	stb	*_dp_VIA_t1_cnt_lo
   0B87 CB 11         [ 2]  828 	addb	#17
   0B89 E7 E2         [ 6]  829 	stb	,-s
   0B8B F6 C8 AC      [ 5]  830 	ldb	_the_player+1
   0B8E BD 10 5E      [ 8]  831 	jsr	__Moveto_d
   0B91 C6 10         [ 2]  832 	ldb	#16
   0B93 D7 04         [ 4]  833 	stb	*_dp_VIA_t1_cnt_lo
   0B95 8E 08 61      [ 3]  834 	ldx	#_vl_player_mid1
   0B98 BD F4 10      [ 8]  835 	jsr	___Draw_VLp
   0B9B BD F3 54      [ 8]  836 	jsr	___Reset0Ref
   0B9E C6 7F         [ 2]  837 	ldb	#127
   0BA0 D7 04         [ 4]  838 	stb	*_dp_VIA_t1_cnt_lo
   0BA2 CB 11         [ 2]  839 	addb	#17
   0BA4 E7 E2         [ 6]  840 	stb	,-s
   0BA6 F6 C8 AC      [ 5]  841 	ldb	_the_player+1
   0BA9 BD 10 5E      [ 8]  842 	jsr	__Moveto_d
   0BAC C6 10         [ 2]  843 	ldb	#16
   0BAE D7 04         [ 4]  844 	stb	*_dp_VIA_t1_cnt_lo
   0BB0 8E 08 A1      [ 3]  845 	ldx	#_vl_player_mid2
   0BB3 BD F4 10      [ 8]  846 	jsr	___Draw_VLp
   0BB6 32 62         [ 5]  847 	leas	2,s
   0BB8 7D C8 AF      [ 7]  848 	tst	_the_player+4
   0BBB 26 0E         [ 3]  849 	bne	L11
   0BBD C6 01         [ 2]  850 	ldb	#1
   0BBF F7 C8 AB      [ 5]  851 	stb	_the_player
   0BC2 7F C8 AC      [ 7]  852 	clr	_the_player+1
   0BC5 8E 08 4B      [ 3]  853 	ldx	#_player_draw
   0BC8 BF C8 B0      [ 6]  854 	stx	_the_player+5
   0BCB                     855 L11:
   0BCB 32 63         [ 5]  856 	leas	3,s
   0BCD 39            [ 5]  857 	rts
                            858 	.globl	_player_change_mid_to_right_step1
   0BCE                     859 _player_change_mid_to_right_step1:
   0BCE 32 7D         [ 5]  860 	leas	-3,s
   0BD0 F6 C8 AF      [ 5]  861 	ldb	_the_player+4
   0BD3 E7 E4         [ 4]  862 	stb	,s
   0BD5 4F            [ 2]  863 	clra		;zero_extendqihi: R:b -> R:d
   0BD6 ED 61         [ 6]  864 	std	1,s
   0BD8 1F 01         [ 6]  865 	tfr	d,x
   0BDA 1E 01         [ 8]  866 	exg	d,x
   0BDC F3 C8 AD      [ 7]  867 	addd	_the_player+2; addhi3,3
   0BDF 1E 01         [ 8]  868 	exg	d,x
   0BE1 E6 84         [ 4]  869 	ldb	,x
   0BE3 F7 C8 AC      [ 5]  870 	stb	_the_player+1
   0BE6 E6 E4         [ 4]  871 	ldb	,s
   0BE8 5A            [ 2]  872 	decb
   0BE9 F7 C8 AF      [ 5]  873 	stb	_the_player+4
   0BEC BD F2 A5      [ 8]  874 	jsr	___Intensity_5F
   0BEF BD F3 54      [ 8]  875 	jsr	___Reset0Ref
   0BF2 C6 7F         [ 2]  876 	ldb	#127
   0BF4 D7 04         [ 4]  877 	stb	*_dp_VIA_t1_cnt_lo
   0BF6 CB 11         [ 2]  878 	addb	#17
   0BF8 E7 E2         [ 6]  879 	stb	,-s
   0BFA F6 C8 AC      [ 5]  880 	ldb	_the_player+1
   0BFD BD 10 5E      [ 8]  881 	jsr	__Moveto_d
   0C00 C6 10         [ 2]  882 	ldb	#16
   0C02 D7 04         [ 4]  883 	stb	*_dp_VIA_t1_cnt_lo
   0C04 8E 08 61      [ 3]  884 	ldx	#_vl_player_mid1
   0C07 BD F4 10      [ 8]  885 	jsr	___Draw_VLp
   0C0A BD F3 54      [ 8]  886 	jsr	___Reset0Ref
   0C0D C6 7F         [ 2]  887 	ldb	#127
   0C0F D7 04         [ 4]  888 	stb	*_dp_VIA_t1_cnt_lo
   0C11 CB 11         [ 2]  889 	addb	#17
   0C13 E7 E2         [ 6]  890 	stb	,-s
   0C15 F6 C8 AC      [ 5]  891 	ldb	_the_player+1
   0C18 BD 10 5E      [ 8]  892 	jsr	__Moveto_d
   0C1B C6 10         [ 2]  893 	ldb	#16
   0C1D D7 04         [ 4]  894 	stb	*_dp_VIA_t1_cnt_lo
   0C1F 8E 08 A1      [ 3]  895 	ldx	#_vl_player_mid2
   0C22 BD F4 10      [ 8]  896 	jsr	___Draw_VLp
   0C25 32 62         [ 5]  897 	leas	2,s
   0C27 7D C8 AF      [ 7]  898 	tst	_the_player+4
   0C2A 26 19         [ 3]  899 	bne	L14
   0C2C 8E 0C 48      [ 3]  900 	ldx	#_player_change_mid_to_right_step2
   0C2F BF C8 B0      [ 6]  901 	stx	_the_player+5
   0C32 F6 C8 A5      [ 5]  902 	ldb	_the_game+2
   0C35 4F            [ 2]  903 	clra		;zero_extendqihi: R:b -> R:d
   0C36 1F 01         [ 6]  904 	tfr	d,x
   0C38 E6 89 08 07   [ 8]  905 	ldb	_PLAYER_ANIMATION_FRAME_CNT_STAGE2_LUT,x
   0C3C F7 C8 AF      [ 5]  906 	stb	_the_player+4
   0C3F 8E 08 21      [ 3]  907 	ldx	#__SP1_MID_RIGHT_X_LUT_2
   0C42 BF C8 AD      [ 6]  908 	stx	_the_player+2
   0C45                     909 L14:
   0C45 32 63         [ 5]  910 	leas	3,s
   0C47 39            [ 5]  911 	rts
                            912 	.globl	_player_change_mid_to_right_step2
   0C48                     913 _player_change_mid_to_right_step2:
   0C48 32 7D         [ 5]  914 	leas	-3,s
   0C4A F6 C8 AF      [ 5]  915 	ldb	_the_player+4
   0C4D E7 E4         [ 4]  916 	stb	,s
   0C4F 4F            [ 2]  917 	clra		;zero_extendqihi: R:b -> R:d
   0C50 ED 61         [ 6]  918 	std	1,s
   0C52 1F 01         [ 6]  919 	tfr	d,x
   0C54 1E 01         [ 8]  920 	exg	d,x
   0C56 F3 C8 AD      [ 7]  921 	addd	_the_player+2; addhi3,3
   0C59 1E 01         [ 8]  922 	exg	d,x
   0C5B E6 84         [ 4]  923 	ldb	,x
   0C5D F7 C8 AC      [ 5]  924 	stb	_the_player+1
   0C60 E6 E4         [ 4]  925 	ldb	,s
   0C62 5A            [ 2]  926 	decb
   0C63 F7 C8 AF      [ 5]  927 	stb	_the_player+4
   0C66 BD F2 A5      [ 8]  928 	jsr	___Intensity_5F
   0C69 BD F3 54      [ 8]  929 	jsr	___Reset0Ref
   0C6C C6 7F         [ 2]  930 	ldb	#127
   0C6E D7 04         [ 4]  931 	stb	*_dp_VIA_t1_cnt_lo
   0C70 CB 11         [ 2]  932 	addb	#17
   0C72 E7 E2         [ 6]  933 	stb	,-s
   0C74 F6 C8 AC      [ 5]  934 	ldb	_the_player+1
   0C77 BD 10 5E      [ 8]  935 	jsr	__Moveto_d
   0C7A C6 10         [ 2]  936 	ldb	#16
   0C7C D7 04         [ 4]  937 	stb	*_dp_VIA_t1_cnt_lo
   0C7E 8E 09 DA      [ 3]  938 	ldx	#_vl_player_right1
   0C81 BD F4 10      [ 8]  939 	jsr	___Draw_VLp
   0C84 BD F3 54      [ 8]  940 	jsr	___Reset0Ref
   0C87 C6 7F         [ 2]  941 	ldb	#127
   0C89 D7 04         [ 4]  942 	stb	*_dp_VIA_t1_cnt_lo
   0C8B CB 11         [ 2]  943 	addb	#17
   0C8D E7 E2         [ 6]  944 	stb	,-s
   0C8F F6 C8 AC      [ 5]  945 	ldb	_the_player+1
   0C92 BD 10 5E      [ 8]  946 	jsr	__Moveto_d
   0C95 C6 10         [ 2]  947 	ldb	#16
   0C97 D7 04         [ 4]  948 	stb	*_dp_VIA_t1_cnt_lo
   0C99 8E 0A 26      [ 3]  949 	ldx	#_vl_player_right2
   0C9C BD F4 10      [ 8]  950 	jsr	___Draw_VLp
   0C9F BD F3 54      [ 8]  951 	jsr	___Reset0Ref
   0CA2 C6 7F         [ 2]  952 	ldb	#127
   0CA4 D7 04         [ 4]  953 	stb	*_dp_VIA_t1_cnt_lo
   0CA6 CB 11         [ 2]  954 	addb	#17
   0CA8 E7 E2         [ 6]  955 	stb	,-s
   0CAA F6 C8 AC      [ 5]  956 	ldb	_the_player+1
   0CAD BD 10 5E      [ 8]  957 	jsr	__Moveto_d
   0CB0 C6 10         [ 2]  958 	ldb	#16
   0CB2 D7 04         [ 4]  959 	stb	*_dp_VIA_t1_cnt_lo
   0CB4 8E 0A 8A      [ 3]  960 	ldx	#_vl_player_right3
   0CB7 BD F4 10      [ 8]  961 	jsr	___Draw_VLp
   0CBA 32 63         [ 5]  962 	leas	3,s
   0CBC 7D C8 AF      [ 7]  963 	tst	_the_player+4
   0CBF 26 10         [ 3]  964 	bne	L17
   0CC1 C6 02         [ 2]  965 	ldb	#2
   0CC3 F7 C8 AB      [ 5]  966 	stb	_the_player
   0CC6 C6 52         [ 2]  967 	ldb	#82
   0CC8 F7 C8 AC      [ 5]  968 	stb	_the_player+1
   0CCB 8E 08 4B      [ 3]  969 	ldx	#_player_draw
   0CCE BF C8 B0      [ 6]  970 	stx	_the_player+5
   0CD1                     971 L17:
   0CD1 32 63         [ 5]  972 	leas	3,s
   0CD3 39            [ 5]  973 	rts
                            974 	.globl	_player_change_right_to_mid_step1
   0CD4                     975 _player_change_right_to_mid_step1:
   0CD4 32 7D         [ 5]  976 	leas	-3,s
   0CD6 F6 C8 AF      [ 5]  977 	ldb	_the_player+4
   0CD9 E7 E4         [ 4]  978 	stb	,s
   0CDB 4F            [ 2]  979 	clra		;zero_extendqihi: R:b -> R:d
   0CDC ED 61         [ 6]  980 	std	1,s
   0CDE 1F 01         [ 6]  981 	tfr	d,x
   0CE0 1E 01         [ 8]  982 	exg	d,x
   0CE2 F3 C8 AD      [ 7]  983 	addd	_the_player+2; addhi3,3
   0CE5 1E 01         [ 8]  984 	exg	d,x
   0CE7 E6 84         [ 4]  985 	ldb	,x
   0CE9 F7 C8 AC      [ 5]  986 	stb	_the_player+1
   0CEC E6 E4         [ 4]  987 	ldb	,s
   0CEE 5A            [ 2]  988 	decb
   0CEF F7 C8 AF      [ 5]  989 	stb	_the_player+4
   0CF2 BD F2 A5      [ 8]  990 	jsr	___Intensity_5F
   0CF5 BD F3 54      [ 8]  991 	jsr	___Reset0Ref
   0CF8 C6 7F         [ 2]  992 	ldb	#127
   0CFA D7 04         [ 4]  993 	stb	*_dp_VIA_t1_cnt_lo
   0CFC CB 11         [ 2]  994 	addb	#17
   0CFE E7 E2         [ 6]  995 	stb	,-s
   0D00 F6 C8 AC      [ 5]  996 	ldb	_the_player+1
   0D03 BD 10 5E      [ 8]  997 	jsr	__Moveto_d
   0D06 C6 10         [ 2]  998 	ldb	#16
   0D08 D7 04         [ 4]  999 	stb	*_dp_VIA_t1_cnt_lo
   0D0A 8E 09 DA      [ 3] 1000 	ldx	#_vl_player_right1
   0D0D BD F4 10      [ 8] 1001 	jsr	___Draw_VLp
   0D10 BD F3 54      [ 8] 1002 	jsr	___Reset0Ref
   0D13 C6 7F         [ 2] 1003 	ldb	#127
   0D15 D7 04         [ 4] 1004 	stb	*_dp_VIA_t1_cnt_lo
   0D17 CB 11         [ 2] 1005 	addb	#17
   0D19 E7 E2         [ 6] 1006 	stb	,-s
   0D1B F6 C8 AC      [ 5] 1007 	ldb	_the_player+1
   0D1E BD 10 5E      [ 8] 1008 	jsr	__Moveto_d
   0D21 C6 10         [ 2] 1009 	ldb	#16
   0D23 D7 04         [ 4] 1010 	stb	*_dp_VIA_t1_cnt_lo
   0D25 8E 0A 26      [ 3] 1011 	ldx	#_vl_player_right2
   0D28 BD F4 10      [ 8] 1012 	jsr	___Draw_VLp
   0D2B BD F3 54      [ 8] 1013 	jsr	___Reset0Ref
   0D2E C6 7F         [ 2] 1014 	ldb	#127
   0D30 D7 04         [ 4] 1015 	stb	*_dp_VIA_t1_cnt_lo
   0D32 CB 11         [ 2] 1016 	addb	#17
   0D34 E7 E2         [ 6] 1017 	stb	,-s
   0D36 F6 C8 AC      [ 5] 1018 	ldb	_the_player+1
   0D39 BD 10 5E      [ 8] 1019 	jsr	__Moveto_d
   0D3C C6 10         [ 2] 1020 	ldb	#16
   0D3E D7 04         [ 4] 1021 	stb	*_dp_VIA_t1_cnt_lo
   0D40 8E 0A 8A      [ 3] 1022 	ldx	#_vl_player_right3
   0D43 BD F4 10      [ 8] 1023 	jsr	___Draw_VLp
   0D46 32 63         [ 5] 1024 	leas	3,s
   0D48 7D C8 AF      [ 7] 1025 	tst	_the_player+4
   0D4B 26 19         [ 3] 1026 	bne	L20
   0D4D 8E 0D 69      [ 3] 1027 	ldx	#_player_change_right_to_mid_step2
   0D50 BF C8 B0      [ 6] 1028 	stx	_the_player+5
   0D53 F6 C8 A5      [ 5] 1029 	ldb	_the_game+2
   0D56 4F            [ 2] 1030 	clra		;zero_extendqihi: R:b -> R:d
   0D57 1F 01         [ 6] 1031 	tfr	d,x
   0D59 E6 89 08 07   [ 8] 1032 	ldb	_PLAYER_ANIMATION_FRAME_CNT_STAGE2_LUT,x
   0D5D F7 C8 AF      [ 5] 1033 	stb	_the_player+4
   0D60 8E 08 27      [ 3] 1034 	ldx	#__SP1_RIGHT_MID_X_LUT_2
   0D63 BF C8 AD      [ 6] 1035 	stx	_the_player+2
   0D66                    1036 L20:
   0D66 32 63         [ 5] 1037 	leas	3,s
   0D68 39            [ 5] 1038 	rts
                           1039 	.globl	_player_change_right_to_mid_step2
   0D69                    1040 _player_change_right_to_mid_step2:
   0D69 32 7D         [ 5] 1041 	leas	-3,s
   0D6B F6 C8 AF      [ 5] 1042 	ldb	_the_player+4
   0D6E E7 E4         [ 4] 1043 	stb	,s
   0D70 4F            [ 2] 1044 	clra		;zero_extendqihi: R:b -> R:d
   0D71 ED 61         [ 6] 1045 	std	1,s
   0D73 1F 01         [ 6] 1046 	tfr	d,x
   0D75 1E 01         [ 8] 1047 	exg	d,x
   0D77 F3 C8 AD      [ 7] 1048 	addd	_the_player+2; addhi3,3
   0D7A 1E 01         [ 8] 1049 	exg	d,x
   0D7C E6 84         [ 4] 1050 	ldb	,x
   0D7E F7 C8 AC      [ 5] 1051 	stb	_the_player+1
   0D81 E6 E4         [ 4] 1052 	ldb	,s
   0D83 5A            [ 2] 1053 	decb
   0D84 F7 C8 AF      [ 5] 1054 	stb	_the_player+4
   0D87 BD F2 A5      [ 8] 1055 	jsr	___Intensity_5F
   0D8A BD F3 54      [ 8] 1056 	jsr	___Reset0Ref
   0D8D C6 7F         [ 2] 1057 	ldb	#127
   0D8F D7 04         [ 4] 1058 	stb	*_dp_VIA_t1_cnt_lo
   0D91 CB 11         [ 2] 1059 	addb	#17
   0D93 E7 E2         [ 6] 1060 	stb	,-s
   0D95 F6 C8 AC      [ 5] 1061 	ldb	_the_player+1
   0D98 BD 10 5E      [ 8] 1062 	jsr	__Moveto_d
   0D9B C6 10         [ 2] 1063 	ldb	#16
   0D9D D7 04         [ 4] 1064 	stb	*_dp_VIA_t1_cnt_lo
   0D9F 8E 08 61      [ 3] 1065 	ldx	#_vl_player_mid1
   0DA2 BD F4 10      [ 8] 1066 	jsr	___Draw_VLp
   0DA5 BD F3 54      [ 8] 1067 	jsr	___Reset0Ref
   0DA8 C6 7F         [ 2] 1068 	ldb	#127
   0DAA D7 04         [ 4] 1069 	stb	*_dp_VIA_t1_cnt_lo
   0DAC CB 11         [ 2] 1070 	addb	#17
   0DAE E7 E2         [ 6] 1071 	stb	,-s
   0DB0 F6 C8 AC      [ 5] 1072 	ldb	_the_player+1
   0DB3 BD 10 5E      [ 8] 1073 	jsr	__Moveto_d
   0DB6 C6 10         [ 2] 1074 	ldb	#16
   0DB8 D7 04         [ 4] 1075 	stb	*_dp_VIA_t1_cnt_lo
   0DBA 8E 08 A1      [ 3] 1076 	ldx	#_vl_player_mid2
   0DBD BD F4 10      [ 8] 1077 	jsr	___Draw_VLp
   0DC0 32 62         [ 5] 1078 	leas	2,s
   0DC2 7D C8 AF      [ 7] 1079 	tst	_the_player+4
   0DC5 26 0E         [ 3] 1080 	bne	L23
   0DC7 C6 01         [ 2] 1081 	ldb	#1
   0DC9 F7 C8 AB      [ 5] 1082 	stb	_the_player
   0DCC 7F C8 AC      [ 7] 1083 	clr	_the_player+1
   0DCF 8E 08 4B      [ 3] 1084 	ldx	#_player_draw
   0DD2 BF C8 B0      [ 6] 1085 	stx	_the_player+5
   0DD5                    1086 L23:
   0DD5 32 63         [ 5] 1087 	leas	3,s
   0DD7 39            [ 5] 1088 	rts
                           1089 	.globl	_player_change_mid_to_left_step1
   0DD8                    1090 _player_change_mid_to_left_step1:
   0DD8 32 7D         [ 5] 1091 	leas	-3,s
   0DDA F6 C8 AF      [ 5] 1092 	ldb	_the_player+4
   0DDD E7 E4         [ 4] 1093 	stb	,s
   0DDF 4F            [ 2] 1094 	clra		;zero_extendqihi: R:b -> R:d
   0DE0 ED 61         [ 6] 1095 	std	1,s
   0DE2 1F 01         [ 6] 1096 	tfr	d,x
   0DE4 1E 01         [ 8] 1097 	exg	d,x
   0DE6 F3 C8 AD      [ 7] 1098 	addd	_the_player+2; addhi3,3
   0DE9 1E 01         [ 8] 1099 	exg	d,x
   0DEB E6 84         [ 4] 1100 	ldb	,x
   0DED F7 C8 AC      [ 5] 1101 	stb	_the_player+1
   0DF0 E6 E4         [ 4] 1102 	ldb	,s
   0DF2 5A            [ 2] 1103 	decb
   0DF3 F7 C8 AF      [ 5] 1104 	stb	_the_player+4
   0DF6 BD F2 A5      [ 8] 1105 	jsr	___Intensity_5F
   0DF9 BD F3 54      [ 8] 1106 	jsr	___Reset0Ref
   0DFC C6 7F         [ 2] 1107 	ldb	#127
   0DFE D7 04         [ 4] 1108 	stb	*_dp_VIA_t1_cnt_lo
   0E00 CB 11         [ 2] 1109 	addb	#17
   0E02 E7 E2         [ 6] 1110 	stb	,-s
   0E04 F6 C8 AC      [ 5] 1111 	ldb	_the_player+1
   0E07 BD 10 5E      [ 8] 1112 	jsr	__Moveto_d
   0E0A C6 10         [ 2] 1113 	ldb	#16
   0E0C D7 04         [ 4] 1114 	stb	*_dp_VIA_t1_cnt_lo
   0E0E 8E 08 61      [ 3] 1115 	ldx	#_vl_player_mid1
   0E11 BD F4 10      [ 8] 1116 	jsr	___Draw_VLp
   0E14 BD F3 54      [ 8] 1117 	jsr	___Reset0Ref
   0E17 C6 7F         [ 2] 1118 	ldb	#127
   0E19 D7 04         [ 4] 1119 	stb	*_dp_VIA_t1_cnt_lo
   0E1B CB 11         [ 2] 1120 	addb	#17
   0E1D E7 E2         [ 6] 1121 	stb	,-s
   0E1F F6 C8 AC      [ 5] 1122 	ldb	_the_player+1
   0E22 BD 10 5E      [ 8] 1123 	jsr	__Moveto_d
   0E25 C6 10         [ 2] 1124 	ldb	#16
   0E27 D7 04         [ 4] 1125 	stb	*_dp_VIA_t1_cnt_lo
   0E29 8E 08 A1      [ 3] 1126 	ldx	#_vl_player_mid2
   0E2C BD F4 10      [ 8] 1127 	jsr	___Draw_VLp
   0E2F 32 62         [ 5] 1128 	leas	2,s
   0E31 7D C8 AF      [ 7] 1129 	tst	_the_player+4
   0E34 26 19         [ 3] 1130 	bne	L26
   0E36 8E 0E 52      [ 3] 1131 	ldx	#_player_change_mid_to_left_step2
   0E39 BF C8 B0      [ 6] 1132 	stx	_the_player+5
   0E3C F6 C8 A5      [ 5] 1133 	ldb	_the_game+2
   0E3F 4F            [ 2] 1134 	clra		;zero_extendqihi: R:b -> R:d
   0E40 1F 01         [ 6] 1135 	tfr	d,x
   0E42 E6 89 08 07   [ 8] 1136 	ldb	_PLAYER_ANIMATION_FRAME_CNT_STAGE2_LUT,x
   0E46 F7 C8 AF      [ 5] 1137 	stb	_the_player+4
   0E49 8E 08 2D      [ 3] 1138 	ldx	#__SP1_MID_LEFT_X_LUT_2
   0E4C BF C8 AD      [ 6] 1139 	stx	_the_player+2
   0E4F                    1140 L26:
   0E4F 32 63         [ 5] 1141 	leas	3,s
   0E51 39            [ 5] 1142 	rts
                           1143 	.globl	_player_change_mid_to_left_step2
   0E52                    1144 _player_change_mid_to_left_step2:
   0E52 32 7D         [ 5] 1145 	leas	-3,s
   0E54 F6 C8 AF      [ 5] 1146 	ldb	_the_player+4
   0E57 E7 E4         [ 4] 1147 	stb	,s
   0E59 4F            [ 2] 1148 	clra		;zero_extendqihi: R:b -> R:d
   0E5A ED 61         [ 6] 1149 	std	1,s
   0E5C 1F 01         [ 6] 1150 	tfr	d,x
   0E5E 1E 01         [ 8] 1151 	exg	d,x
   0E60 F3 C8 AD      [ 7] 1152 	addd	_the_player+2; addhi3,3
   0E63 1E 01         [ 8] 1153 	exg	d,x
   0E65 E6 84         [ 4] 1154 	ldb	,x
   0E67 F7 C8 AC      [ 5] 1155 	stb	_the_player+1
   0E6A E6 E4         [ 4] 1156 	ldb	,s
   0E6C 5A            [ 2] 1157 	decb
   0E6D F7 C8 AF      [ 5] 1158 	stb	_the_player+4
   0E70 BD F2 A5      [ 8] 1159 	jsr	___Intensity_5F
   0E73 BD F3 54      [ 8] 1160 	jsr	___Reset0Ref
   0E76 C6 7F         [ 2] 1161 	ldb	#127
   0E78 D7 04         [ 4] 1162 	stb	*_dp_VIA_t1_cnt_lo
   0E7A CB 11         [ 2] 1163 	addb	#17
   0E7C E7 E2         [ 6] 1164 	stb	,-s
   0E7E F6 C8 AC      [ 5] 1165 	ldb	_the_player+1
   0E81 BD 10 5E      [ 8] 1166 	jsr	__Moveto_d
   0E84 C6 10         [ 2] 1167 	ldb	#16
   0E86 D7 04         [ 4] 1168 	stb	*_dp_VIA_t1_cnt_lo
   0E88 8E 08 EA      [ 3] 1169 	ldx	#_vl_player_left1
   0E8B BD F4 10      [ 8] 1170 	jsr	___Draw_VLp
   0E8E BD F3 54      [ 8] 1171 	jsr	___Reset0Ref
   0E91 C6 7F         [ 2] 1172 	ldb	#127
   0E93 D7 04         [ 4] 1173 	stb	*_dp_VIA_t1_cnt_lo
   0E95 CB 11         [ 2] 1174 	addb	#17
   0E97 E7 E2         [ 6] 1175 	stb	,-s
   0E99 F6 C8 AC      [ 5] 1176 	ldb	_the_player+1
   0E9C BD 10 5E      [ 8] 1177 	jsr	__Moveto_d
   0E9F C6 10         [ 2] 1178 	ldb	#16
   0EA1 D7 04         [ 4] 1179 	stb	*_dp_VIA_t1_cnt_lo
   0EA3 8E 09 36      [ 3] 1180 	ldx	#_vl_player_left2
   0EA6 BD F4 10      [ 8] 1181 	jsr	___Draw_VLp
   0EA9 BD F3 54      [ 8] 1182 	jsr	___Reset0Ref
   0EAC C6 7F         [ 2] 1183 	ldb	#127
   0EAE D7 04         [ 4] 1184 	stb	*_dp_VIA_t1_cnt_lo
   0EB0 CB 11         [ 2] 1185 	addb	#17
   0EB2 E7 E2         [ 6] 1186 	stb	,-s
   0EB4 F6 C8 AC      [ 5] 1187 	ldb	_the_player+1
   0EB7 BD 10 5E      [ 8] 1188 	jsr	__Moveto_d
   0EBA C6 10         [ 2] 1189 	ldb	#16
   0EBC D7 04         [ 4] 1190 	stb	*_dp_VIA_t1_cnt_lo
   0EBE 8E 09 9A      [ 3] 1191 	ldx	#_vl_player_left3
   0EC1 BD F4 10      [ 8] 1192 	jsr	___Draw_VLp
   0EC4 32 63         [ 5] 1193 	leas	3,s
   0EC6 7D C8 AF      [ 7] 1194 	tst	_the_player+4
   0EC9 26 0E         [ 3] 1195 	bne	L29
   0ECB 7F C8 AB      [ 7] 1196 	clr	_the_player
   0ECE C6 AE         [ 2] 1197 	ldb	#-82
   0ED0 F7 C8 AC      [ 5] 1198 	stb	_the_player+1
   0ED3 8E 08 4B      [ 3] 1199 	ldx	#_player_draw
   0ED6 BF C8 B0      [ 6] 1200 	stx	_the_player+5
   0ED9                    1201 L29:
   0ED9 32 63         [ 5] 1202 	leas	3,s
   0EDB 39            [ 5] 1203 	rts
                           1204 	.globl	__player_draw_mid
   0EDC                    1205 __player_draw_mid:
   0EDC BD F3 54      [ 8] 1206 	jsr	___Reset0Ref
   0EDF C6 7F         [ 2] 1207 	ldb	#127
   0EE1 D7 04         [ 4] 1208 	stb	*_dp_VIA_t1_cnt_lo
   0EE3 CB 11         [ 2] 1209 	addb	#17
   0EE5 E7 E2         [ 6] 1210 	stb	,-s
   0EE7 F6 C8 AC      [ 5] 1211 	ldb	_the_player+1
   0EEA BD 10 5E      [ 8] 1212 	jsr	__Moveto_d
   0EED C6 10         [ 2] 1213 	ldb	#16
   0EEF D7 04         [ 4] 1214 	stb	*_dp_VIA_t1_cnt_lo
   0EF1 8E 08 61      [ 3] 1215 	ldx	#_vl_player_mid1
   0EF4 BD F4 10      [ 8] 1216 	jsr	___Draw_VLp
   0EF7 BD F3 54      [ 8] 1217 	jsr	___Reset0Ref
   0EFA C6 7F         [ 2] 1218 	ldb	#127
   0EFC D7 04         [ 4] 1219 	stb	*_dp_VIA_t1_cnt_lo
   0EFE CB 11         [ 2] 1220 	addb	#17
   0F00 E7 E2         [ 6] 1221 	stb	,-s
   0F02 F6 C8 AC      [ 5] 1222 	ldb	_the_player+1
   0F05 BD 10 5E      [ 8] 1223 	jsr	__Moveto_d
   0F08 C6 10         [ 2] 1224 	ldb	#16
   0F0A D7 04         [ 4] 1225 	stb	*_dp_VIA_t1_cnt_lo
   0F0C 32 62         [ 5] 1226 	leas	2,s
   0F0E 8E 08 A1      [ 3] 1227 	ldx	#_vl_player_mid2
   0F11 7E F4 10      [ 4] 1228 	jmp	___Draw_VLp
                           1229 	.globl	__player_draw_left
   0F14                    1230 __player_draw_left:
   0F14 BD F3 54      [ 8] 1231 	jsr	___Reset0Ref
   0F17 C6 7F         [ 2] 1232 	ldb	#127
   0F19 D7 04         [ 4] 1233 	stb	*_dp_VIA_t1_cnt_lo
   0F1B CB 11         [ 2] 1234 	addb	#17
   0F1D E7 E2         [ 6] 1235 	stb	,-s
   0F1F F6 C8 AC      [ 5] 1236 	ldb	_the_player+1
   0F22 BD 10 5E      [ 8] 1237 	jsr	__Moveto_d
   0F25 C6 10         [ 2] 1238 	ldb	#16
   0F27 D7 04         [ 4] 1239 	stb	*_dp_VIA_t1_cnt_lo
   0F29 8E 08 EA      [ 3] 1240 	ldx	#_vl_player_left1
   0F2C BD F4 10      [ 8] 1241 	jsr	___Draw_VLp
   0F2F BD F3 54      [ 8] 1242 	jsr	___Reset0Ref
   0F32 C6 7F         [ 2] 1243 	ldb	#127
   0F34 D7 04         [ 4] 1244 	stb	*_dp_VIA_t1_cnt_lo
   0F36 CB 11         [ 2] 1245 	addb	#17
   0F38 E7 E2         [ 6] 1246 	stb	,-s
   0F3A F6 C8 AC      [ 5] 1247 	ldb	_the_player+1
   0F3D BD 10 5E      [ 8] 1248 	jsr	__Moveto_d
   0F40 C6 10         [ 2] 1249 	ldb	#16
   0F42 D7 04         [ 4] 1250 	stb	*_dp_VIA_t1_cnt_lo
   0F44 8E 09 36      [ 3] 1251 	ldx	#_vl_player_left2
   0F47 BD F4 10      [ 8] 1252 	jsr	___Draw_VLp
   0F4A BD F3 54      [ 8] 1253 	jsr	___Reset0Ref
   0F4D C6 7F         [ 2] 1254 	ldb	#127
   0F4F D7 04         [ 4] 1255 	stb	*_dp_VIA_t1_cnt_lo
   0F51 CB 11         [ 2] 1256 	addb	#17
   0F53 E7 E2         [ 6] 1257 	stb	,-s
   0F55 F6 C8 AC      [ 5] 1258 	ldb	_the_player+1
   0F58 BD 10 5E      [ 8] 1259 	jsr	__Moveto_d
   0F5B C6 10         [ 2] 1260 	ldb	#16
   0F5D D7 04         [ 4] 1261 	stb	*_dp_VIA_t1_cnt_lo
   0F5F 32 63         [ 5] 1262 	leas	3,s
   0F61 8E 09 9A      [ 3] 1263 	ldx	#_vl_player_left3
   0F64 7E F4 10      [ 4] 1264 	jmp	___Draw_VLp
                           1265 	.globl	__player_draw_right
   0F67                    1266 __player_draw_right:
   0F67 BD F3 54      [ 8] 1267 	jsr	___Reset0Ref
   0F6A C6 7F         [ 2] 1268 	ldb	#127
   0F6C D7 04         [ 4] 1269 	stb	*_dp_VIA_t1_cnt_lo
   0F6E CB 11         [ 2] 1270 	addb	#17
   0F70 E7 E2         [ 6] 1271 	stb	,-s
   0F72 F6 C8 AC      [ 5] 1272 	ldb	_the_player+1
   0F75 BD 10 5E      [ 8] 1273 	jsr	__Moveto_d
   0F78 C6 10         [ 2] 1274 	ldb	#16
   0F7A D7 04         [ 4] 1275 	stb	*_dp_VIA_t1_cnt_lo
   0F7C 8E 09 DA      [ 3] 1276 	ldx	#_vl_player_right1
   0F7F BD F4 10      [ 8] 1277 	jsr	___Draw_VLp
   0F82 BD F3 54      [ 8] 1278 	jsr	___Reset0Ref
   0F85 C6 7F         [ 2] 1279 	ldb	#127
   0F87 D7 04         [ 4] 1280 	stb	*_dp_VIA_t1_cnt_lo
   0F89 CB 11         [ 2] 1281 	addb	#17
   0F8B E7 E2         [ 6] 1282 	stb	,-s
   0F8D F6 C8 AC      [ 5] 1283 	ldb	_the_player+1
   0F90 BD 10 5E      [ 8] 1284 	jsr	__Moveto_d
   0F93 C6 10         [ 2] 1285 	ldb	#16
   0F95 D7 04         [ 4] 1286 	stb	*_dp_VIA_t1_cnt_lo
   0F97 8E 0A 26      [ 3] 1287 	ldx	#_vl_player_right2
   0F9A BD F4 10      [ 8] 1288 	jsr	___Draw_VLp
   0F9D BD F3 54      [ 8] 1289 	jsr	___Reset0Ref
   0FA0 C6 7F         [ 2] 1290 	ldb	#127
   0FA2 D7 04         [ 4] 1291 	stb	*_dp_VIA_t1_cnt_lo
   0FA4 CB 11         [ 2] 1292 	addb	#17
   0FA6 E7 E2         [ 6] 1293 	stb	,-s
   0FA8 F6 C8 AC      [ 5] 1294 	ldb	_the_player+1
   0FAB BD 10 5E      [ 8] 1295 	jsr	__Moveto_d
   0FAE C6 10         [ 2] 1296 	ldb	#16
   0FB0 D7 04         [ 4] 1297 	stb	*_dp_VIA_t1_cnt_lo
   0FB2 32 63         [ 5] 1298 	leas	3,s
   0FB4 8E 0A 8A      [ 3] 1299 	ldx	#_vl_player_right3
   0FB7 7E F4 10      [ 4] 1300 	jmp	___Draw_VLp
                           1301 	.globl	_check_collision
   0FBA                    1302 _check_collision:
   0FBA 39            [ 5] 1303 	rts
                           1304 	.globl	__SP1_LEFT_MID_X_LUT_1
   0FBB                    1305 __SP1_LEFT_MID_X_LUT_1:
   0FBB D7                 1306 	.byte	-41
   0FBC D1                 1307 	.byte	-47
   0FBD CB                 1308 	.byte	-53
   0FBE C5                 1309 	.byte	-59
   0FBF C0                 1310 	.byte	-64
   0FC0 BA                 1311 	.byte	-70
   0FC1 B4                 1312 	.byte	-76
                           1313 	.globl	__SP1_MID_RIGHT_X_LUT_1
   0FC2                    1314 __SP1_MID_RIGHT_X_LUT_1:
   0FC2 29                 1315 	.byte	41
   0FC3 23                 1316 	.byte	35
   0FC4 1D                 1317 	.byte	29
   0FC5 17                 1318 	.byte	23
   0FC6 12                 1319 	.byte	18
   0FC7 0C                 1320 	.byte	12
   0FC8 06                 1321 	.byte	6
                           1322 	.globl	__SP1_RIGHT_MID_X_LUT_1
   0FC9                    1323 __SP1_RIGHT_MID_X_LUT_1:
   0FC9 29                 1324 	.byte	41
   0FCA 2F                 1325 	.byte	47
   0FCB 35                 1326 	.byte	53
   0FCC 3B                 1327 	.byte	59
   0FCD 40                 1328 	.byte	64
   0FCE 46                 1329 	.byte	70
   0FCF 4C                 1330 	.byte	76
                           1331 	.globl	__SP1_MID_LEFT_X_LUT_1
   0FD0                    1332 __SP1_MID_LEFT_X_LUT_1:
   0FD0 D7                 1333 	.byte	-41
   0FD1 DD                 1334 	.byte	-35
   0FD2 E3                 1335 	.byte	-29
   0FD3 E9                 1336 	.byte	-23
   0FD4 EE                 1337 	.byte	-18
   0FD5 F4                 1338 	.byte	-12
   0FD6 FA                 1339 	.byte	-6
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Sat Jun 14 01:03:03 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L11                03CF R   |   3 L14                0449 R
  3 L17                04D5 R   |   3 L20                056A R
  3 L23                05D9 R   |   3 L26                0653 R
  3 L29                06DD R   |   3 L7                 0360 R
  3 _PLAYER_ANIMAT     0000 GR  |   3 _PLAYER_ANIMAT     000B GR
  3 _PLAYER_DRAW_L     0019 GR  |   3 _PLAYER_STATIC     0016 GR
    __Moveto_d         **** GX  |   3 __SP1_LEFT_MID     07BF GR
  3 __SP1_LEFT_MID     001F GR  |   3 __SP1_MID_LEFT     07D4 GR
  3 __SP1_MID_LEFT     0031 GR  |   3 __SP1_MID_RIGH     07C6 GR
  3 __SP1_MID_RIGH     0025 GR  |   3 __SP1_RIGHT_MI     07CD GR
  3 __SP1_RIGHT_MI     002B GR  |     ___Draw_VLp        **** GX
    ___Intensity_5     **** GX  |     ___Reset0Ref       **** GX
  3 __player_draw_     0718 GR  |   3 __player_draw_     06E0 GR
  3 __player_draw_     076B GR  |   3 _check_collisi     07BE GR
    _dp_VIA_t1_cnt     **** GX  |   3 _player_change     02CE GR
  3 _player_change     0363 GR  |   3 _player_change     05DC GR
  3 _player_change     0656 GR  |   3 _player_change     03D2 GR
  3 _player_change     044C GR  |   3 _player_change     04D8 GR
  3 _player_change     056D GR  |   3 _player_draw       004F GR
  3 _player_init       0037 GR  |     _the_game          **** GX
  2 _the_player        0000 GR  |   3 _vl_player_lef     00EE GR
  3 _vl_player_lef     013A GR  |   3 _vl_player_lef     019E GR
  3 _vl_player_mid     0065 GR  |   3 _vl_player_mid     00A5 GR
  3 _vl_player_rig     01DE GR  |   3 _vl_player_rig     022A GR
  3 _vl_player_rig     028E GR  |   3 _vl_term_0_46      00A4 R
  3 _vl_term_1_83      00ED R   |   3 _vl_term_2_123     0139 R
  3 _vl_term_3_170     019D R   |   3 _vl_term_4_203     01DD R
  3 _vl_term_5_243     0229 R   |   3 _vl_term_6_290     028D R
  3 _vl_term_7_323     02CD R

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Sat Jun 14 01:03:03 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    7   flags    0
   3 .text            size  7DB   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

