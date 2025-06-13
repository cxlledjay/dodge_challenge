                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	player.c
                              6 	.area	.bss
                              7 	.globl	_the_player
   C8AA                       8 _the_player:	.blkb	7
                              9 	.globl	_PLAYER_ANIMATION_FRAME_CNT_STAGE1_LUT
                             10 	.area	.text
   07D9                      11 _PLAYER_ANIMATION_FRAME_CNT_STAGE1_LUT:
   07D9 07                   12 	.byte	7
   07DA 07                   13 	.byte	7
   07DB 07                   14 	.byte	7
   07DC 07                   15 	.byte	7
   07DD 07                   16 	.byte	7
   07DE 07                   17 	.byte	7
   07DF 07                   18 	.byte	7
   07E0 07                   19 	.byte	7
   07E1 07                   20 	.byte	7
   07E2 07                   21 	.byte	7
   07E3 07                   22 	.byte	7
                             23 	.globl	_PLAYER_ANIMATION_FRAME_CNT_STAGE2_LUT
   07E4                      24 _PLAYER_ANIMATION_FRAME_CNT_STAGE2_LUT:
   07E4 06                   25 	.byte	6
   07E5 06                   26 	.byte	6
   07E6 06                   27 	.byte	6
   07E7 06                   28 	.byte	6
   07E8 06                   29 	.byte	6
   07E9 06                   30 	.byte	6
   07EA 06                   31 	.byte	6
   07EB 06                   32 	.byte	6
   07EC 06                   33 	.byte	6
   07ED 06                   34 	.byte	6
   07EE 06                   35 	.byte	6
                             36 	.globl	_PLAYER_STATIC_X_LUT
   07EF                      37 _PLAYER_STATIC_X_LUT:
   07EF AE                   38 	.byte	-82
   07F0 00                   39 	.byte	0
   07F1 52                   40 	.byte	82
                             41 	.globl	_PLAYER_DRAW_LUT
   07F2                      42 _PLAYER_DRAW_LUT:
   07F2 0E 91                43 	.word	__player_draw_left
   07F4 0E 59                44 	.word	__player_draw_mid
   07F6 0E E4                45 	.word	__player_draw_right
                             46 	.globl	__SP1_LEFT_MID_X_LUT_2
   07F8                      47 __SP1_LEFT_MID_X_LUT_2:
   07F8 FA                   48 	.byte	-6
   07F9 F4                   49 	.byte	-12
   07FA EE                   50 	.byte	-18
   07FB E9                   51 	.byte	-23
   07FC E3                   52 	.byte	-29
   07FD DD                   53 	.byte	-35
                             54 	.globl	__SP1_MID_RIGHT_X_LUT_2
   07FE                      55 __SP1_MID_RIGHT_X_LUT_2:
   07FE 4C                   56 	.byte	76
   07FF 46                   57 	.byte	70
   0800 40                   58 	.byte	64
   0801 3B                   59 	.byte	59
   0802 35                   60 	.byte	53
   0803 2F                   61 	.byte	47
                             62 	.globl	__SP1_RIGHT_MID_X_LUT_2
   0804                      63 __SP1_RIGHT_MID_X_LUT_2:
   0804 06                   64 	.byte	6
   0805 0C                   65 	.byte	12
   0806 12                   66 	.byte	18
   0807 17                   67 	.byte	23
   0808 1D                   68 	.byte	29
   0809 23                   69 	.byte	35
                             70 	.globl	__SP1_MID_LEFT_X_LUT_2
   080A                      71 __SP1_MID_LEFT_X_LUT_2:
   080A B4                   72 	.byte	-76
   080B BA                   73 	.byte	-70
   080C C0                   74 	.byte	-64
   080D C5                   75 	.byte	-59
   080E CB                   76 	.byte	-53
   080F D1                   77 	.byte	-47
                             78 	.globl	_player_init
   0810                      79 _player_init:
   0810 8E 08 28      [ 3]   80 	ldx	#_player_draw
   0813 BF C8 AF      [ 6]   81 	stx	_the_player+5
   0816 7F C8 AE      [ 7]   82 	clr	_the_player+4
   0819 CC 00 00      [ 3]   83 	ldd	#0
   081C FD C8 AC      [ 6]   84 	std	_the_player+2
   081F 7F C8 AB      [ 7]   85 	clr	_the_player+1
   0822 C6 01         [ 2]   86 	ldb	#1
   0824 F7 C8 AA      [ 5]   87 	stb	_the_player
   0827 39            [ 5]   88 	rts
                             89 	.globl	_player_draw
   0828                      90 _player_draw:
   0828 32 7E         [ 5]   91 	leas	-2,s
   082A BD F2 A5      [ 8]   92 	jsr	___Intensity_5F
   082D F6 C8 AA      [ 5]   93 	ldb	_the_player
   0830 4F            [ 2]   94 	clra		;zero_extendqihi: R:b -> R:d
   0831 ED E4         [ 5]   95 	std	,s
   0833 58            [ 2]   96 	aslb
   0834 49            [ 2]   97 	rola
   0835 1F 01         [ 6]   98 	tfr	d,x
   0837 AD 99 07 F2   [14]   99 	jsr	[_PLAYER_DRAW_LUT,x]
   083B 32 62         [ 5]  100 	leas	2,s
   083D 39            [ 5]  101 	rts
                            102 	.globl	_vl_player_mid1
   083E                     103 _vl_player_mid1:
   083E 00                  104 	.byte	0
   083F A0                  105 	.byte	-96
   0840 B0                  106 	.byte	-80
   0841 FF                  107 	.byte	-1
   0842 00                  108 	.byte	0
   0843 B0                  109 	.byte	-80
   0844 FF                  110 	.byte	-1
   0845 7F                  111 	.byte	127
   0846 00                  112 	.byte	0
   0847 FF                  113 	.byte	-1
   0848 00                  114 	.byte	0
   0849 50                  115 	.byte	80
   084A FF                  116 	.byte	-1
   084B 80                  117 	.byte	-128
   084C 00                  118 	.byte	0
   084D 00                  119 	.byte	0
   084E 10                  120 	.byte	16
   084F 00                  121 	.byte	0
   0850 FF                  122 	.byte	-1
   0851 10                  123 	.byte	16
   0852 3C                  124 	.byte	60
   0853 00                  125 	.byte	0
   0854 00                  126 	.byte	0
   0855 28                  127 	.byte	40
   0856 FF                  128 	.byte	-1
   0857 F0                  129 	.byte	-16
   0858 3C                  130 	.byte	60
   0859 00                  131 	.byte	0
   085A F0                  132 	.byte	-16
   085B 00                  133 	.byte	0
   085C FF                  134 	.byte	-1
   085D 00                  135 	.byte	0
   085E 50                  136 	.byte	80
   085F FF                  137 	.byte	-1
   0860 7F                  138 	.byte	127
   0861 00                  139 	.byte	0
   0862 FF                  140 	.byte	-1
   0863 00                  141 	.byte	0
   0864 B0                  142 	.byte	-80
   0865 FF                  143 	.byte	-1
   0866 80                  144 	.byte	-128
   0867 00                  145 	.byte	0
   0868 00                  146 	.byte	0
   0869 20                  147 	.byte	32
   086A 00                  148 	.byte	0
   086B FF                  149 	.byte	-1
   086C 00                  150 	.byte	0
   086D B0                  151 	.byte	-80
   086E FF                  152 	.byte	-1
   086F 00                  153 	.byte	0
   0870 B0                  154 	.byte	-80
   0871 00                  155 	.byte	0
   0872 40                  156 	.byte	64
   0873 00                  157 	.byte	0
   0874 FF                  158 	.byte	-1
   0875 10                  159 	.byte	16
   0876 3C                  160 	.byte	60
   0877 FF                  161 	.byte	-1
   0878 00                  162 	.byte	0
   0879 28                  163 	.byte	40
   087A FF                  164 	.byte	-1
   087B F0                  165 	.byte	-16
   087C 3C                  166 	.byte	60
   087D                     167 _vl_term_0_46:
   087D 01                  168 	.byte	1
                            169 	.globl	_vl_player_mid2
   087E                     170 _vl_player_mid2:
   087E 00                  171 	.byte	0
   087F 20                  172 	.byte	32
   0880 88                  173 	.byte	-120
   0881 FF                  174 	.byte	-1
   0882 28                  175 	.byte	40
   0883 00                  176 	.byte	0
   0884 FF                  177 	.byte	-1
   0885 00                  178 	.byte	0
   0886 3C                  179 	.byte	60
   0887 FF                  180 	.byte	-1
   0888 DC                  181 	.byte	-36
   0889 00                  182 	.byte	0
   088A 00                  183 	.byte	0
   088B E0                  184 	.byte	-32
   088C EC                  185 	.byte	-20
   088D FF                  186 	.byte	-1
   088E 70                  187 	.byte	112
   088F 40                  188 	.byte	64
   0890 FF                  189 	.byte	-1
   0891 00                  190 	.byte	0
   0892 20                  191 	.byte	32
   0893 FF                  192 	.byte	-1
   0894 90                  193 	.byte	-112
   0895 40                  194 	.byte	64
   0896 00                  195 	.byte	0
   0897 20                  196 	.byte	32
   0898 28                  197 	.byte	40
   0899 FF                  198 	.byte	-1
   089A 28                  199 	.byte	40
   089B 00                  200 	.byte	0
   089C FF                  201 	.byte	-1
   089D 00                  202 	.byte	0
   089E C4                  203 	.byte	-60
   089F FF                  204 	.byte	-1
   08A0 DC                  205 	.byte	-36
   08A1 00                  206 	.byte	0
   08A2 00                  207 	.byte	0
   08A3 2D                  208 	.byte	45
   08A4 E4                  209 	.byte	-28
   08A5 FF                  210 	.byte	-1
   08A6 00                  211 	.byte	0
   08A7 30                  212 	.byte	48
   08A8 FF                  213 	.byte	-1
   08A9 10                  214 	.byte	16
   08AA F8                  215 	.byte	-8
   08AB FF                  216 	.byte	-1
   08AC 00                  217 	.byte	0
   08AD D0                  218 	.byte	-48
   08AE 00                  219 	.byte	0
   08AF 00                  220 	.byte	0
   08B0 D0                  221 	.byte	-48
   08B1 FF                  222 	.byte	-1
   08B2 00                  223 	.byte	0
   08B3 D0                  224 	.byte	-48
   08B4 FF                  225 	.byte	-1
   08B5 F0                  226 	.byte	-16
   08B6 F8                  227 	.byte	-8
   08B7 FF                  228 	.byte	-1
   08B8 00                  229 	.byte	0
   08B9 30                  230 	.byte	48
   08BA 00                  231 	.byte	0
   08BB E4                  232 	.byte	-28
   08BC 0C                  233 	.byte	12
   08BD FF                  234 	.byte	-1
   08BE 10                  235 	.byte	16
   08BF 08                  236 	.byte	8
   08C0 FF                  237 	.byte	-1
   08C1 00                  238 	.byte	0
   08C2 18                  239 	.byte	24
   08C3 FF                  240 	.byte	-1
   08C4 F0                  241 	.byte	-16
   08C5 08                  242 	.byte	8
   08C6                     243 _vl_term_1_83:
   08C6 01                  244 	.byte	1
                            245 	.globl	_vl_player_left1
   08C7                     246 _vl_player_left1:
   08C7 00                  247 	.byte	0
   08C8 08                  248 	.byte	8
   08C9 50                  249 	.byte	80
   08CA FF                  250 	.byte	-1
   08CB B0                  251 	.byte	-80
   08CC 00                  252 	.byte	0
   08CD FF                  253 	.byte	-1
   08CE E8                  254 	.byte	-24
   08CF 10                  255 	.byte	16
   08D0 FF                  256 	.byte	-1
   08D1 00                  257 	.byte	0
   08D2 50                  258 	.byte	80
   08D3 FF                  259 	.byte	-1
   08D4 18                  260 	.byte	24
   08D5 10                  261 	.byte	16
   08D6 FF                  262 	.byte	-1
   08D7 50                  263 	.byte	80
   08D8 00                  264 	.byte	0
   08D9 FF                  265 	.byte	-1
   08DA 18                  266 	.byte	24
   08DB F0                  267 	.byte	-16
   08DC FF                  268 	.byte	-1
   08DD 00                  269 	.byte	0
   08DE B0                  270 	.byte	-80
   08DF FF                  271 	.byte	-1
   08E0 E8                  272 	.byte	-24
   08E1 F0                  273 	.byte	-16
   08E2 00                  274 	.byte	0
   08E3 F8                  275 	.byte	-8
   08E4 00                  276 	.byte	0
   08E5 FF                  277 	.byte	-1
   08E6 10                  278 	.byte	16
   08E7 C4                  279 	.byte	-60
   08E8 FF                  280 	.byte	-1
   08E9 00                  281 	.byte	0
   08EA D8                  282 	.byte	-40
   08EB FF                  283 	.byte	-1
   08EC F0                  284 	.byte	-16
   08ED C4                  285 	.byte	-60
   08EE 00                  286 	.byte	0
   08EF 08                  287 	.byte	8
   08F0 00                  288 	.byte	0
   08F1 FF                  289 	.byte	-1
   08F2 B0                  290 	.byte	-80
   08F3 00                  291 	.byte	0
   08F4 FF                  292 	.byte	-1
   08F5 E8                  293 	.byte	-24
   08F6 10                  294 	.byte	16
   08F7 FF                  295 	.byte	-1
   08F8 18                  296 	.byte	24
   08F9 10                  297 	.byte	16
   08FA FF                  298 	.byte	-1
   08FB 08                  299 	.byte	8
   08FC 00                  300 	.byte	0
   08FD 00                  301 	.byte	0
   08FE F0                  302 	.byte	-16
   08FF E8                  303 	.byte	-24
   0900 FF                  304 	.byte	-1
   0901 10                  305 	.byte	16
   0902 34                  306 	.byte	52
   0903 00                  307 	.byte	0
   0904 00                  308 	.byte	0
   0905 C4                  309 	.byte	-60
   0906 FF                  310 	.byte	-1
   0907 00                  311 	.byte	0
   0908 50                  312 	.byte	80
   0909 FF                  313 	.byte	-1
   090A 00                  314 	.byte	0
   090B 50                  315 	.byte	80
   090C 00                  316 	.byte	0
   090D 00                  317 	.byte	0
   090E C4                  318 	.byte	-60
   090F FF                  319 	.byte	-1
   0910 F0                  320 	.byte	-16
   0911 40                  321 	.byte	64
   0912                     322 _vl_term_2_123:
   0912 01                  323 	.byte	1
                            324 	.globl	_vl_player_left2
   0913                     325 _vl_player_left2:
   0913 00                  326 	.byte	0
   0914 D0                  327 	.byte	-48
   0915 58                  328 	.byte	88
   0916 00                  329 	.byte	0
   0917 D0                  330 	.byte	-48
   0918 58                  331 	.byte	88
   0919 FF                  332 	.byte	-1
   091A 18                  333 	.byte	24
   091B F0                  334 	.byte	-16
   091C FF                  335 	.byte	-1
   091D 50                  336 	.byte	80
   091E 00                  337 	.byte	0
   091F FF                  338 	.byte	-1
   0920 18                  339 	.byte	24
   0921 10                  340 	.byte	16
   0922 00                  341 	.byte	0
   0923 E0                  342 	.byte	-32
   0924 10                  343 	.byte	16
   0925 FF                  344 	.byte	-1
   0926 00                  345 	.byte	0
   0927 14                  346 	.byte	20
   0928 FF                  347 	.byte	-1
   0929 10                  348 	.byte	16
   092A 08                  349 	.byte	8
   092B FF                  350 	.byte	-1
   092C 38                  351 	.byte	56
   092D 00                  352 	.byte	0
   092E FF                  353 	.byte	-1
   092F 10                  354 	.byte	16
   0930 F8                  355 	.byte	-8
   0931 FF                  356 	.byte	-1
   0932 F0                  357 	.byte	-16
   0933 F8                  358 	.byte	-8
   0934 FF                  359 	.byte	-1
   0935 C8                  360 	.byte	-56
   0936 00                  361 	.byte	0
   0937 FF                  362 	.byte	-1
   0938 F0                  363 	.byte	-16
   0939 08                  364 	.byte	8
   093A 00                  365 	.byte	0
   093B 58                  366 	.byte	88
   093C 00                  367 	.byte	0
   093D FF                  368 	.byte	-1
   093E 00                  369 	.byte	0
   093F B8                  370 	.byte	-72
   0940 FF                  371 	.byte	-1
   0941 F0                  372 	.byte	-16
   0942 F8                  373 	.byte	-8
   0943 FF                  374 	.byte	-1
   0944 D8                  375 	.byte	-40
   0945 00                  376 	.byte	0
   0946 00                  377 	.byte	0
   0947 00                  378 	.byte	0
   0948 EC                  379 	.byte	-20
   0949 FF                  380 	.byte	-1
   094A 1C                  381 	.byte	28
   094B 14                  382 	.byte	20
   094C 00                  383 	.byte	0
   094D 1C                  384 	.byte	28
   094E 10                  385 	.byte	16
   094F FF                  386 	.byte	-1
   0950 28                  387 	.byte	40
   0951 1C                  388 	.byte	28
   0952 FF                  389 	.byte	-1
   0953 00                  390 	.byte	0
   0954 D8                  391 	.byte	-40
   0955 FF                  392 	.byte	-1
   0956 C0                  393 	.byte	-64
   0957 94                  394 	.byte	-108
   0958 FF                  395 	.byte	-1
   0959 C0                  396 	.byte	-64
   095A 94                  397 	.byte	-108
   095B 00                  398 	.byte	0
   095C 34                  399 	.byte	52
   095D 58                  400 	.byte	88
   095E 00                  401 	.byte	0
   095F 34                  402 	.byte	52
   0960 58                  403 	.byte	88
   0961 FF                  404 	.byte	-1
   0962 00                  405 	.byte	0
   0963 E4                  406 	.byte	-28
   0964 FF                  407 	.byte	-1
   0965 10                  408 	.byte	16
   0966 18                  409 	.byte	24
   0967 FF                  410 	.byte	-1
   0968 00                  411 	.byte	0
   0969 20                  412 	.byte	32
   096A 00                  413 	.byte	0
   096B 00                  414 	.byte	0
   096C 2E                  415 	.byte	46
   096D FF                  416 	.byte	-1
   096E 00                  417 	.byte	0
   096F 20                  418 	.byte	32
   0970 FF                  419 	.byte	-1
   0971 F0                  420 	.byte	-16
   0972 F8                  421 	.byte	-8
   0973 FF                  422 	.byte	-1
   0974 00                  423 	.byte	0
   0975 E0                  424 	.byte	-32
   0976                     425 _vl_term_3_170:
   0976 01                  426 	.byte	1
                            427 	.globl	_vl_player_left3
   0977                     428 _vl_player_left3:
   0977 00                  429 	.byte	0
   0978 08                  430 	.byte	8
   0979 B0                  431 	.byte	-80
   097A FF                  432 	.byte	-1
   097B 18                  433 	.byte	24
   097C 10                  434 	.byte	16
   097D FF                  435 	.byte	-1
   097E F0                  436 	.byte	-16
   097F 0C                  437 	.byte	12
   0980 00                  438 	.byte	0
   0981 90                  439 	.byte	-112
   0982 F4                  440 	.byte	-12
   0983 FF                  441 	.byte	-1
   0984 00                  442 	.byte	0
   0985 B0                  443 	.byte	-80
   0986 FF                  444 	.byte	-1
   0987 18                  445 	.byte	24
   0988 F0                  446 	.byte	-16
   0989 FF                  447 	.byte	-1
   098A 50                  448 	.byte	80
   098B 00                  449 	.byte	0
   098C FF                  450 	.byte	-1
   098D 18                  451 	.byte	24
   098E 10                  452 	.byte	16
   098F FF                  453 	.byte	-1
   0990 00                  454 	.byte	0
   0991 50                  455 	.byte	80
   0992 00                  456 	.byte	0
   0993 FC                  457 	.byte	-4
   0994 1C                  458 	.byte	28
   0995 FF                  459 	.byte	-1
   0996 30                  460 	.byte	48
   0997 00                  461 	.byte	0
   0998 FF                  462 	.byte	-1
   0999 10                  463 	.byte	16
   099A 08                  464 	.byte	8
   099B FF                  465 	.byte	-1
   099C 00                  466 	.byte	0
   099D 48                  467 	.byte	72
   099E FF                  468 	.byte	-1
   099F F0                  469 	.byte	-16
   09A0 F8                  470 	.byte	-8
   09A1 FF                  471 	.byte	-1
   09A2 F8                  472 	.byte	-8
   09A3 00                  473 	.byte	0
   09A4 00                  474 	.byte	0
   09A5 18                  475 	.byte	24
   09A6 08                  476 	.byte	8
   09A7 FF                  477 	.byte	-1
   09A8 F4                  478 	.byte	-12
   09A9 08                  479 	.byte	8
   09AA 00                  480 	.byte	0
   09AB DC                  481 	.byte	-36
   09AC EC                  482 	.byte	-20
   09AD FF                  483 	.byte	-1
   09AE 18                  484 	.byte	24
   09AF 2C                  485 	.byte	44
   09B0 FF                  486 	.byte	-1
   09B1 00                  487 	.byte	0
   09B2 1C                  488 	.byte	28
   09B3 FF                  489 	.byte	-1
   09B4 E8                  490 	.byte	-24
   09B5 F0                  491 	.byte	-16
   09B6                     492 _vl_term_4_203:
   09B6 01                  493 	.byte	1
                            494 	.globl	_vl_player_right1
   09B7                     495 _vl_player_right1:
   09B7 00                  496 	.byte	0
   09B8 08                  497 	.byte	8
   09B9 B0                  498 	.byte	-80
   09BA FF                  499 	.byte	-1
   09BB B0                  500 	.byte	-80
   09BC 00                  501 	.byte	0
   09BD FF                  502 	.byte	-1
   09BE E8                  503 	.byte	-24
   09BF F0                  504 	.byte	-16
   09C0 FF                  505 	.byte	-1
   09C1 00                  506 	.byte	0
   09C2 B0                  507 	.byte	-80
   09C3 FF                  508 	.byte	-1
   09C4 18                  509 	.byte	24
   09C5 F0                  510 	.byte	-16
   09C6 FF                  511 	.byte	-1
   09C7 50                  512 	.byte	80
   09C8 00                  513 	.byte	0
   09C9 FF                  514 	.byte	-1
   09CA 18                  515 	.byte	24
   09CB 10                  516 	.byte	16
   09CC FF                  517 	.byte	-1
   09CD 00                  518 	.byte	0
   09CE 50                  519 	.byte	80
   09CF FF                  520 	.byte	-1
   09D0 E8                  521 	.byte	-24
   09D1 10                  522 	.byte	16
   09D2 00                  523 	.byte	0
   09D3 F8                  524 	.byte	-8
   09D4 00                  525 	.byte	0
   09D5 FF                  526 	.byte	-1
   09D6 10                  527 	.byte	16
   09D7 3C                  528 	.byte	60
   09D8 FF                  529 	.byte	-1
   09D9 00                  530 	.byte	0
   09DA 28                  531 	.byte	40
   09DB FF                  532 	.byte	-1
   09DC F0                  533 	.byte	-16
   09DD 3C                  534 	.byte	60
   09DE 00                  535 	.byte	0
   09DF 08                  536 	.byte	8
   09E0 00                  537 	.byte	0
   09E1 FF                  538 	.byte	-1
   09E2 B0                  539 	.byte	-80
   09E3 00                  540 	.byte	0
   09E4 FF                  541 	.byte	-1
   09E5 E8                  542 	.byte	-24
   09E6 F0                  543 	.byte	-16
   09E7 FF                  544 	.byte	-1
   09E8 18                  545 	.byte	24
   09E9 F0                  546 	.byte	-16
   09EA FF                  547 	.byte	-1
   09EB 08                  548 	.byte	8
   09EC 00                  549 	.byte	0
   09ED 00                  550 	.byte	0
   09EE F0                  551 	.byte	-16
   09EF 18                  552 	.byte	24
   09F0 FF                  553 	.byte	-1
   09F1 10                  554 	.byte	16
   09F2 CC                  555 	.byte	-52
   09F3 00                  556 	.byte	0
   09F4 00                  557 	.byte	0
   09F5 3C                  558 	.byte	60
   09F6 FF                  559 	.byte	-1
   09F7 00                  560 	.byte	0
   09F8 B0                  561 	.byte	-80
   09F9 FF                  562 	.byte	-1
   09FA 00                  563 	.byte	0
   09FB B0                  564 	.byte	-80
   09FC 00                  565 	.byte	0
   09FD 00                  566 	.byte	0
   09FE 3C                  567 	.byte	60
   09FF FF                  568 	.byte	-1
   0A00 F0                  569 	.byte	-16
   0A01 C0                  570 	.byte	-64
   0A02                     571 _vl_term_5_243:
   0A02 01                  572 	.byte	1
                            573 	.globl	_vl_player_right2
   0A03                     574 _vl_player_right2:
   0A03 00                  575 	.byte	0
   0A04 D0                  576 	.byte	-48
   0A05 A8                  577 	.byte	-88
   0A06 00                  578 	.byte	0
   0A07 D0                  579 	.byte	-48
   0A08 A8                  580 	.byte	-88
   0A09 FF                  581 	.byte	-1
   0A0A 18                  582 	.byte	24
   0A0B 10                  583 	.byte	16
   0A0C FF                  584 	.byte	-1
   0A0D 50                  585 	.byte	80
   0A0E 00                  586 	.byte	0
   0A0F FF                  587 	.byte	-1
   0A10 18                  588 	.byte	24
   0A11 F0                  589 	.byte	-16
   0A12 00                  590 	.byte	0
   0A13 E0                  591 	.byte	-32
   0A14 F0                  592 	.byte	-16
   0A15 FF                  593 	.byte	-1
   0A16 00                  594 	.byte	0
   0A17 EC                  595 	.byte	-20
   0A18 FF                  596 	.byte	-1
   0A19 10                  597 	.byte	16
   0A1A F8                  598 	.byte	-8
   0A1B FF                  599 	.byte	-1
   0A1C 38                  600 	.byte	56
   0A1D 00                  601 	.byte	0
   0A1E FF                  602 	.byte	-1
   0A1F 10                  603 	.byte	16
   0A20 08                  604 	.byte	8
   0A21 FF                  605 	.byte	-1
   0A22 F0                  606 	.byte	-16
   0A23 08                  607 	.byte	8
   0A24 FF                  608 	.byte	-1
   0A25 C8                  609 	.byte	-56
   0A26 00                  610 	.byte	0
   0A27 FF                  611 	.byte	-1
   0A28 F0                  612 	.byte	-16
   0A29 F8                  613 	.byte	-8
   0A2A 00                  614 	.byte	0
   0A2B 58                  615 	.byte	88
   0A2C 00                  616 	.byte	0
   0A2D FF                  617 	.byte	-1
   0A2E 00                  618 	.byte	0
   0A2F 48                  619 	.byte	72
   0A30 FF                  620 	.byte	-1
   0A31 F0                  621 	.byte	-16
   0A32 08                  622 	.byte	8
   0A33 FF                  623 	.byte	-1
   0A34 D8                  624 	.byte	-40
   0A35 00                  625 	.byte	0
   0A36 00                  626 	.byte	0
   0A37 00                  627 	.byte	0
   0A38 14                  628 	.byte	20
   0A39 FF                  629 	.byte	-1
   0A3A 1C                  630 	.byte	28
   0A3B EC                  631 	.byte	-20
   0A3C 00                  632 	.byte	0
   0A3D 1C                  633 	.byte	28
   0A3E F0                  634 	.byte	-16
   0A3F FF                  635 	.byte	-1
   0A40 28                  636 	.byte	40
   0A41 E4                  637 	.byte	-28
   0A42 FF                  638 	.byte	-1
   0A43 00                  639 	.byte	0
   0A44 28                  640 	.byte	40
   0A45 FF                  641 	.byte	-1
   0A46 C0                  642 	.byte	-64
   0A47 6C                  643 	.byte	108
   0A48 FF                  644 	.byte	-1
   0A49 C0                  645 	.byte	-64
   0A4A 6C                  646 	.byte	108
   0A4B 00                  647 	.byte	0
   0A4C 34                  648 	.byte	52
   0A4D A8                  649 	.byte	-88
   0A4E 00                  650 	.byte	0
   0A4F 34                  651 	.byte	52
   0A50 A8                  652 	.byte	-88
   0A51 FF                  653 	.byte	-1
   0A52 00                  654 	.byte	0
   0A53 1C                  655 	.byte	28
   0A54 FF                  656 	.byte	-1
   0A55 10                  657 	.byte	16
   0A56 E8                  658 	.byte	-24
   0A57 FF                  659 	.byte	-1
   0A58 00                  660 	.byte	0
   0A59 E0                  661 	.byte	-32
   0A5A 00                  662 	.byte	0
   0A5B 00                  663 	.byte	0
   0A5C D2                  664 	.byte	-46
   0A5D FF                  665 	.byte	-1
   0A5E 00                  666 	.byte	0
   0A5F E0                  667 	.byte	-32
   0A60 FF                  668 	.byte	-1
   0A61 F0                  669 	.byte	-16
   0A62 08                  670 	.byte	8
   0A63 FF                  671 	.byte	-1
   0A64 00                  672 	.byte	0
   0A65 20                  673 	.byte	32
   0A66                     674 _vl_term_6_290:
   0A66 01                  675 	.byte	1
                            676 	.globl	_vl_player_right3
   0A67                     677 _vl_player_right3:
   0A67 00                  678 	.byte	0
   0A68 08                  679 	.byte	8
   0A69 50                  680 	.byte	80
   0A6A FF                  681 	.byte	-1
   0A6B 18                  682 	.byte	24
   0A6C F0                  683 	.byte	-16
   0A6D FF                  684 	.byte	-1
   0A6E F0                  685 	.byte	-16
   0A6F F4                  686 	.byte	-12
   0A70 00                  687 	.byte	0
   0A71 90                  688 	.byte	-112
   0A72 0C                  689 	.byte	12
   0A73 FF                  690 	.byte	-1
   0A74 00                  691 	.byte	0
   0A75 50                  692 	.byte	80
   0A76 FF                  693 	.byte	-1
   0A77 18                  694 	.byte	24
   0A78 10                  695 	.byte	16
   0A79 FF                  696 	.byte	-1
   0A7A 50                  697 	.byte	80
   0A7B 00                  698 	.byte	0
   0A7C FF                  699 	.byte	-1
   0A7D 18                  700 	.byte	24
   0A7E F0                  701 	.byte	-16
   0A7F FF                  702 	.byte	-1
   0A80 00                  703 	.byte	0
   0A81 B0                  704 	.byte	-80
   0A82 00                  705 	.byte	0
   0A83 FC                  706 	.byte	-4
   0A84 E4                  707 	.byte	-28
   0A85 FF                  708 	.byte	-1
   0A86 30                  709 	.byte	48
   0A87 00                  710 	.byte	0
   0A88 FF                  711 	.byte	-1
   0A89 10                  712 	.byte	16
   0A8A F8                  713 	.byte	-8
   0A8B FF                  714 	.byte	-1
   0A8C 00                  715 	.byte	0
   0A8D B8                  716 	.byte	-72
   0A8E FF                  717 	.byte	-1
   0A8F F0                  718 	.byte	-16
   0A90 08                  719 	.byte	8
   0A91 FF                  720 	.byte	-1
   0A92 F8                  721 	.byte	-8
   0A93 00                  722 	.byte	0
   0A94 00                  723 	.byte	0
   0A95 18                  724 	.byte	24
   0A96 F8                  725 	.byte	-8
   0A97 FF                  726 	.byte	-1
   0A98 F4                  727 	.byte	-12
   0A99 F8                  728 	.byte	-8
   0A9A 00                  729 	.byte	0
   0A9B DC                  730 	.byte	-36
   0A9C 14                  731 	.byte	20
   0A9D FF                  732 	.byte	-1
   0A9E 18                  733 	.byte	24
   0A9F D4                  734 	.byte	-44
   0AA0 FF                  735 	.byte	-1
   0AA1 00                  736 	.byte	0
   0AA2 E4                  737 	.byte	-28
   0AA3 FF                  738 	.byte	-1
   0AA4 E8                  739 	.byte	-24
   0AA5 10                  740 	.byte	16
   0AA6                     741 _vl_term_7_323:
   0AA6 01                  742 	.byte	1
                            743 	.globl	_player_change_left_to_mid_step1
   0AA7                     744 _player_change_left_to_mid_step1:
   0AA7 34 40         [ 6]  745 	pshs	u
   0AA9 7A C8 AE      [ 7]  746 	dec	_the_player+4
   0AAC F6 C8 AE      [ 5]  747 	ldb	_the_player+4
   0AAF 4F            [ 2]  748 	clra		;zero_extendqihi: R:b -> R:d
   0AB0 FE C8 AC      [ 6]  749 	ldu	_the_player+2
   0AB3 30 CB         [ 8]  750 	leax	d,u
   0AB5 E6 84         [ 4]  751 	ldb	,x
   0AB7 F7 C8 AB      [ 5]  752 	stb	_the_player+1
   0ABA BD F2 A5      [ 8]  753 	jsr	___Intensity_5F
   0ABD BD F3 54      [ 8]  754 	jsr	___Reset0Ref
   0AC0 C6 7F         [ 2]  755 	ldb	#127
   0AC2 D7 04         [ 4]  756 	stb	*_dp_VIA_t1_cnt_lo
   0AC4 CB 11         [ 2]  757 	addb	#17
   0AC6 E7 E2         [ 6]  758 	stb	,-s
   0AC8 F6 C8 AB      [ 5]  759 	ldb	_the_player+1
   0ACB BD 0F 6E      [ 8]  760 	jsr	__Moveto_d
   0ACE C6 10         [ 2]  761 	ldb	#16
   0AD0 D7 04         [ 4]  762 	stb	*_dp_VIA_t1_cnt_lo
   0AD2 8E 08 C7      [ 3]  763 	ldx	#_vl_player_left1
   0AD5 BD F4 10      [ 8]  764 	jsr	___Draw_VLp
   0AD8 BD F3 54      [ 8]  765 	jsr	___Reset0Ref
   0ADB C6 7F         [ 2]  766 	ldb	#127
   0ADD D7 04         [ 4]  767 	stb	*_dp_VIA_t1_cnt_lo
   0ADF CB 11         [ 2]  768 	addb	#17
   0AE1 E7 E2         [ 6]  769 	stb	,-s
   0AE3 F6 C8 AB      [ 5]  770 	ldb	_the_player+1
   0AE6 BD 0F 6E      [ 8]  771 	jsr	__Moveto_d
   0AE9 C6 10         [ 2]  772 	ldb	#16
   0AEB D7 04         [ 4]  773 	stb	*_dp_VIA_t1_cnt_lo
   0AED 8E 09 13      [ 3]  774 	ldx	#_vl_player_left2
   0AF0 BD F4 10      [ 8]  775 	jsr	___Draw_VLp
   0AF3 BD F3 54      [ 8]  776 	jsr	___Reset0Ref
   0AF6 C6 7F         [ 2]  777 	ldb	#127
   0AF8 D7 04         [ 4]  778 	stb	*_dp_VIA_t1_cnt_lo
   0AFA CB 11         [ 2]  779 	addb	#17
   0AFC E7 E2         [ 6]  780 	stb	,-s
   0AFE F6 C8 AB      [ 5]  781 	ldb	_the_player+1
   0B01 BD 0F 6E      [ 8]  782 	jsr	__Moveto_d
   0B04 C6 10         [ 2]  783 	ldb	#16
   0B06 D7 04         [ 4]  784 	stb	*_dp_VIA_t1_cnt_lo
   0B08 8E 09 77      [ 3]  785 	ldx	#_vl_player_left3
   0B0B BD F4 10      [ 8]  786 	jsr	___Draw_VLp
   0B0E 32 63         [ 5]  787 	leas	3,s
   0B10 7D C8 AE      [ 7]  788 	tst	_the_player+4
   0B13 26 19         [ 3]  789 	bne	L7
   0B15 8E 0B 30      [ 3]  790 	ldx	#_player_change_left_to_mid_step2
   0B18 BF C8 AF      [ 6]  791 	stx	_the_player+5
   0B1B F6 C8 A4      [ 5]  792 	ldb	_the_game+2
   0B1E 4F            [ 2]  793 	clra		;zero_extendqihi: R:b -> R:d
   0B1F 1F 01         [ 6]  794 	tfr	d,x
   0B21 E6 89 07 E4   [ 8]  795 	ldb	_PLAYER_ANIMATION_FRAME_CNT_STAGE2_LUT,x
   0B25 F7 C8 AE      [ 5]  796 	stb	_the_player+4
   0B28 8E 07 F8      [ 3]  797 	ldx	#__SP1_LEFT_MID_X_LUT_2
   0B2B BF C8 AC      [ 6]  798 	stx	_the_player+2
   0B2E                     799 L7:
   0B2E 35 C0         [ 7]  800 	puls	u,pc
                            801 	.globl	_player_change_left_to_mid_step2
   0B30                     802 _player_change_left_to_mid_step2:
   0B30 34 40         [ 6]  803 	pshs	u
   0B32 7A C8 AE      [ 7]  804 	dec	_the_player+4
   0B35 F6 C8 AE      [ 5]  805 	ldb	_the_player+4
   0B38 4F            [ 2]  806 	clra		;zero_extendqihi: R:b -> R:d
   0B39 FE C8 AC      [ 6]  807 	ldu	_the_player+2
   0B3C 30 CB         [ 8]  808 	leax	d,u
   0B3E E6 84         [ 4]  809 	ldb	,x
   0B40 F7 C8 AB      [ 5]  810 	stb	_the_player+1
   0B43 BD F2 A5      [ 8]  811 	jsr	___Intensity_5F
   0B46 BD F3 54      [ 8]  812 	jsr	___Reset0Ref
   0B49 C6 7F         [ 2]  813 	ldb	#127
   0B4B D7 04         [ 4]  814 	stb	*_dp_VIA_t1_cnt_lo
   0B4D CB 11         [ 2]  815 	addb	#17
   0B4F E7 E2         [ 6]  816 	stb	,-s
   0B51 F6 C8 AB      [ 5]  817 	ldb	_the_player+1
   0B54 BD 0F 6E      [ 8]  818 	jsr	__Moveto_d
   0B57 C6 10         [ 2]  819 	ldb	#16
   0B59 D7 04         [ 4]  820 	stb	*_dp_VIA_t1_cnt_lo
   0B5B 8E 08 3E      [ 3]  821 	ldx	#_vl_player_mid1
   0B5E BD F4 10      [ 8]  822 	jsr	___Draw_VLp
   0B61 BD F3 54      [ 8]  823 	jsr	___Reset0Ref
   0B64 C6 7F         [ 2]  824 	ldb	#127
   0B66 D7 04         [ 4]  825 	stb	*_dp_VIA_t1_cnt_lo
   0B68 CB 11         [ 2]  826 	addb	#17
   0B6A E7 E2         [ 6]  827 	stb	,-s
   0B6C F6 C8 AB      [ 5]  828 	ldb	_the_player+1
   0B6F BD 0F 6E      [ 8]  829 	jsr	__Moveto_d
   0B72 C6 10         [ 2]  830 	ldb	#16
   0B74 D7 04         [ 4]  831 	stb	*_dp_VIA_t1_cnt_lo
   0B76 8E 08 7E      [ 3]  832 	ldx	#_vl_player_mid2
   0B79 BD F4 10      [ 8]  833 	jsr	___Draw_VLp
   0B7C 32 62         [ 5]  834 	leas	2,s
   0B7E 7D C8 AE      [ 7]  835 	tst	_the_player+4
   0B81 26 0E         [ 3]  836 	bne	L11
   0B83 C6 01         [ 2]  837 	ldb	#1
   0B85 F7 C8 AA      [ 5]  838 	stb	_the_player
   0B88 7F C8 AB      [ 7]  839 	clr	_the_player+1
   0B8B 8E 08 28      [ 3]  840 	ldx	#_player_draw
   0B8E BF C8 AF      [ 6]  841 	stx	_the_player+5
   0B91                     842 L11:
   0B91 35 C0         [ 7]  843 	puls	u,pc
                            844 	.globl	_player_change_mid_to_right_step1
   0B93                     845 _player_change_mid_to_right_step1:
   0B93 34 40         [ 6]  846 	pshs	u
   0B95 7A C8 AE      [ 7]  847 	dec	_the_player+4
   0B98 F6 C8 AE      [ 5]  848 	ldb	_the_player+4
   0B9B 4F            [ 2]  849 	clra		;zero_extendqihi: R:b -> R:d
   0B9C FE C8 AC      [ 6]  850 	ldu	_the_player+2
   0B9F 30 CB         [ 8]  851 	leax	d,u
   0BA1 E6 84         [ 4]  852 	ldb	,x
   0BA3 F7 C8 AB      [ 5]  853 	stb	_the_player+1
   0BA6 BD F2 A5      [ 8]  854 	jsr	___Intensity_5F
   0BA9 BD F3 54      [ 8]  855 	jsr	___Reset0Ref
   0BAC C6 7F         [ 2]  856 	ldb	#127
   0BAE D7 04         [ 4]  857 	stb	*_dp_VIA_t1_cnt_lo
   0BB0 CB 11         [ 2]  858 	addb	#17
   0BB2 E7 E2         [ 6]  859 	stb	,-s
   0BB4 F6 C8 AB      [ 5]  860 	ldb	_the_player+1
   0BB7 BD 0F 6E      [ 8]  861 	jsr	__Moveto_d
   0BBA C6 10         [ 2]  862 	ldb	#16
   0BBC D7 04         [ 4]  863 	stb	*_dp_VIA_t1_cnt_lo
   0BBE 8E 08 3E      [ 3]  864 	ldx	#_vl_player_mid1
   0BC1 BD F4 10      [ 8]  865 	jsr	___Draw_VLp
   0BC4 BD F3 54      [ 8]  866 	jsr	___Reset0Ref
   0BC7 C6 7F         [ 2]  867 	ldb	#127
   0BC9 D7 04         [ 4]  868 	stb	*_dp_VIA_t1_cnt_lo
   0BCB CB 11         [ 2]  869 	addb	#17
   0BCD E7 E2         [ 6]  870 	stb	,-s
   0BCF F6 C8 AB      [ 5]  871 	ldb	_the_player+1
   0BD2 BD 0F 6E      [ 8]  872 	jsr	__Moveto_d
   0BD5 C6 10         [ 2]  873 	ldb	#16
   0BD7 D7 04         [ 4]  874 	stb	*_dp_VIA_t1_cnt_lo
   0BD9 8E 08 7E      [ 3]  875 	ldx	#_vl_player_mid2
   0BDC BD F4 10      [ 8]  876 	jsr	___Draw_VLp
   0BDF 32 62         [ 5]  877 	leas	2,s
   0BE1 7D C8 AE      [ 7]  878 	tst	_the_player+4
   0BE4 26 19         [ 3]  879 	bne	L14
   0BE6 8E 0C 01      [ 3]  880 	ldx	#_player_change_mid_to_right_step2
   0BE9 BF C8 AF      [ 6]  881 	stx	_the_player+5
   0BEC F6 C8 A4      [ 5]  882 	ldb	_the_game+2
   0BEF 4F            [ 2]  883 	clra		;zero_extendqihi: R:b -> R:d
   0BF0 1F 01         [ 6]  884 	tfr	d,x
   0BF2 E6 89 07 E4   [ 8]  885 	ldb	_PLAYER_ANIMATION_FRAME_CNT_STAGE2_LUT,x
   0BF6 F7 C8 AE      [ 5]  886 	stb	_the_player+4
   0BF9 8E 07 FE      [ 3]  887 	ldx	#__SP1_MID_RIGHT_X_LUT_2
   0BFC BF C8 AC      [ 6]  888 	stx	_the_player+2
   0BFF                     889 L14:
   0BFF 35 C0         [ 7]  890 	puls	u,pc
                            891 	.globl	_player_change_mid_to_right_step2
   0C01                     892 _player_change_mid_to_right_step2:
   0C01 34 40         [ 6]  893 	pshs	u
   0C03 7A C8 AE      [ 7]  894 	dec	_the_player+4
   0C06 F6 C8 AE      [ 5]  895 	ldb	_the_player+4
   0C09 4F            [ 2]  896 	clra		;zero_extendqihi: R:b -> R:d
   0C0A FE C8 AC      [ 6]  897 	ldu	_the_player+2
   0C0D 30 CB         [ 8]  898 	leax	d,u
   0C0F E6 84         [ 4]  899 	ldb	,x
   0C11 F7 C8 AB      [ 5]  900 	stb	_the_player+1
   0C14 BD F2 A5      [ 8]  901 	jsr	___Intensity_5F
   0C17 BD F3 54      [ 8]  902 	jsr	___Reset0Ref
   0C1A C6 7F         [ 2]  903 	ldb	#127
   0C1C D7 04         [ 4]  904 	stb	*_dp_VIA_t1_cnt_lo
   0C1E CB 11         [ 2]  905 	addb	#17
   0C20 E7 E2         [ 6]  906 	stb	,-s
   0C22 F6 C8 AB      [ 5]  907 	ldb	_the_player+1
   0C25 BD 0F 6E      [ 8]  908 	jsr	__Moveto_d
   0C28 C6 10         [ 2]  909 	ldb	#16
   0C2A D7 04         [ 4]  910 	stb	*_dp_VIA_t1_cnt_lo
   0C2C 8E 09 B7      [ 3]  911 	ldx	#_vl_player_right1
   0C2F BD F4 10      [ 8]  912 	jsr	___Draw_VLp
   0C32 BD F3 54      [ 8]  913 	jsr	___Reset0Ref
   0C35 C6 7F         [ 2]  914 	ldb	#127
   0C37 D7 04         [ 4]  915 	stb	*_dp_VIA_t1_cnt_lo
   0C39 CB 11         [ 2]  916 	addb	#17
   0C3B E7 E2         [ 6]  917 	stb	,-s
   0C3D F6 C8 AB      [ 5]  918 	ldb	_the_player+1
   0C40 BD 0F 6E      [ 8]  919 	jsr	__Moveto_d
   0C43 C6 10         [ 2]  920 	ldb	#16
   0C45 D7 04         [ 4]  921 	stb	*_dp_VIA_t1_cnt_lo
   0C47 8E 0A 03      [ 3]  922 	ldx	#_vl_player_right2
   0C4A BD F4 10      [ 8]  923 	jsr	___Draw_VLp
   0C4D BD F3 54      [ 8]  924 	jsr	___Reset0Ref
   0C50 C6 7F         [ 2]  925 	ldb	#127
   0C52 D7 04         [ 4]  926 	stb	*_dp_VIA_t1_cnt_lo
   0C54 CB 11         [ 2]  927 	addb	#17
   0C56 E7 E2         [ 6]  928 	stb	,-s
   0C58 F6 C8 AB      [ 5]  929 	ldb	_the_player+1
   0C5B BD 0F 6E      [ 8]  930 	jsr	__Moveto_d
   0C5E C6 10         [ 2]  931 	ldb	#16
   0C60 D7 04         [ 4]  932 	stb	*_dp_VIA_t1_cnt_lo
   0C62 8E 0A 67      [ 3]  933 	ldx	#_vl_player_right3
   0C65 BD F4 10      [ 8]  934 	jsr	___Draw_VLp
   0C68 32 63         [ 5]  935 	leas	3,s
   0C6A 7D C8 AE      [ 7]  936 	tst	_the_player+4
   0C6D 26 10         [ 3]  937 	bne	L17
   0C6F C6 02         [ 2]  938 	ldb	#2
   0C71 F7 C8 AA      [ 5]  939 	stb	_the_player
   0C74 C6 52         [ 2]  940 	ldb	#82
   0C76 F7 C8 AB      [ 5]  941 	stb	_the_player+1
   0C79 8E 08 28      [ 3]  942 	ldx	#_player_draw
   0C7C BF C8 AF      [ 6]  943 	stx	_the_player+5
   0C7F                     944 L17:
   0C7F 35 C0         [ 7]  945 	puls	u,pc
                            946 	.globl	_player_change_right_to_mid_step1
   0C81                     947 _player_change_right_to_mid_step1:
   0C81 34 40         [ 6]  948 	pshs	u
   0C83 7A C8 AE      [ 7]  949 	dec	_the_player+4
   0C86 F6 C8 AE      [ 5]  950 	ldb	_the_player+4
   0C89 4F            [ 2]  951 	clra		;zero_extendqihi: R:b -> R:d
   0C8A FE C8 AC      [ 6]  952 	ldu	_the_player+2
   0C8D 30 CB         [ 8]  953 	leax	d,u
   0C8F E6 84         [ 4]  954 	ldb	,x
   0C91 F7 C8 AB      [ 5]  955 	stb	_the_player+1
   0C94 BD F2 A5      [ 8]  956 	jsr	___Intensity_5F
   0C97 BD F3 54      [ 8]  957 	jsr	___Reset0Ref
   0C9A C6 7F         [ 2]  958 	ldb	#127
   0C9C D7 04         [ 4]  959 	stb	*_dp_VIA_t1_cnt_lo
   0C9E CB 11         [ 2]  960 	addb	#17
   0CA0 E7 E2         [ 6]  961 	stb	,-s
   0CA2 F6 C8 AB      [ 5]  962 	ldb	_the_player+1
   0CA5 BD 0F 6E      [ 8]  963 	jsr	__Moveto_d
   0CA8 C6 10         [ 2]  964 	ldb	#16
   0CAA D7 04         [ 4]  965 	stb	*_dp_VIA_t1_cnt_lo
   0CAC 8E 09 B7      [ 3]  966 	ldx	#_vl_player_right1
   0CAF BD F4 10      [ 8]  967 	jsr	___Draw_VLp
   0CB2 BD F3 54      [ 8]  968 	jsr	___Reset0Ref
   0CB5 C6 7F         [ 2]  969 	ldb	#127
   0CB7 D7 04         [ 4]  970 	stb	*_dp_VIA_t1_cnt_lo
   0CB9 CB 11         [ 2]  971 	addb	#17
   0CBB E7 E2         [ 6]  972 	stb	,-s
   0CBD F6 C8 AB      [ 5]  973 	ldb	_the_player+1
   0CC0 BD 0F 6E      [ 8]  974 	jsr	__Moveto_d
   0CC3 C6 10         [ 2]  975 	ldb	#16
   0CC5 D7 04         [ 4]  976 	stb	*_dp_VIA_t1_cnt_lo
   0CC7 8E 0A 03      [ 3]  977 	ldx	#_vl_player_right2
   0CCA BD F4 10      [ 8]  978 	jsr	___Draw_VLp
   0CCD BD F3 54      [ 8]  979 	jsr	___Reset0Ref
   0CD0 C6 7F         [ 2]  980 	ldb	#127
   0CD2 D7 04         [ 4]  981 	stb	*_dp_VIA_t1_cnt_lo
   0CD4 CB 11         [ 2]  982 	addb	#17
   0CD6 E7 E2         [ 6]  983 	stb	,-s
   0CD8 F6 C8 AB      [ 5]  984 	ldb	_the_player+1
   0CDB BD 0F 6E      [ 8]  985 	jsr	__Moveto_d
   0CDE C6 10         [ 2]  986 	ldb	#16
   0CE0 D7 04         [ 4]  987 	stb	*_dp_VIA_t1_cnt_lo
   0CE2 8E 0A 67      [ 3]  988 	ldx	#_vl_player_right3
   0CE5 BD F4 10      [ 8]  989 	jsr	___Draw_VLp
   0CE8 32 63         [ 5]  990 	leas	3,s
   0CEA 7D C8 AE      [ 7]  991 	tst	_the_player+4
   0CED 26 19         [ 3]  992 	bne	L20
   0CEF 8E 0D 0A      [ 3]  993 	ldx	#_player_change_right_to_mid_step2
   0CF2 BF C8 AF      [ 6]  994 	stx	_the_player+5
   0CF5 F6 C8 A4      [ 5]  995 	ldb	_the_game+2
   0CF8 4F            [ 2]  996 	clra		;zero_extendqihi: R:b -> R:d
   0CF9 1F 01         [ 6]  997 	tfr	d,x
   0CFB E6 89 07 E4   [ 8]  998 	ldb	_PLAYER_ANIMATION_FRAME_CNT_STAGE2_LUT,x
   0CFF F7 C8 AE      [ 5]  999 	stb	_the_player+4
   0D02 8E 08 04      [ 3] 1000 	ldx	#__SP1_RIGHT_MID_X_LUT_2
   0D05 BF C8 AC      [ 6] 1001 	stx	_the_player+2
   0D08                    1002 L20:
   0D08 35 C0         [ 7] 1003 	puls	u,pc
                           1004 	.globl	_player_change_right_to_mid_step2
   0D0A                    1005 _player_change_right_to_mid_step2:
   0D0A 34 40         [ 6] 1006 	pshs	u
   0D0C 7A C8 AE      [ 7] 1007 	dec	_the_player+4
   0D0F F6 C8 AE      [ 5] 1008 	ldb	_the_player+4
   0D12 4F            [ 2] 1009 	clra		;zero_extendqihi: R:b -> R:d
   0D13 FE C8 AC      [ 6] 1010 	ldu	_the_player+2
   0D16 30 CB         [ 8] 1011 	leax	d,u
   0D18 E6 84         [ 4] 1012 	ldb	,x
   0D1A F7 C8 AB      [ 5] 1013 	stb	_the_player+1
   0D1D BD F2 A5      [ 8] 1014 	jsr	___Intensity_5F
   0D20 BD F3 54      [ 8] 1015 	jsr	___Reset0Ref
   0D23 C6 7F         [ 2] 1016 	ldb	#127
   0D25 D7 04         [ 4] 1017 	stb	*_dp_VIA_t1_cnt_lo
   0D27 CB 11         [ 2] 1018 	addb	#17
   0D29 E7 E2         [ 6] 1019 	stb	,-s
   0D2B F6 C8 AB      [ 5] 1020 	ldb	_the_player+1
   0D2E BD 0F 6E      [ 8] 1021 	jsr	__Moveto_d
   0D31 C6 10         [ 2] 1022 	ldb	#16
   0D33 D7 04         [ 4] 1023 	stb	*_dp_VIA_t1_cnt_lo
   0D35 8E 08 3E      [ 3] 1024 	ldx	#_vl_player_mid1
   0D38 BD F4 10      [ 8] 1025 	jsr	___Draw_VLp
   0D3B BD F3 54      [ 8] 1026 	jsr	___Reset0Ref
   0D3E C6 7F         [ 2] 1027 	ldb	#127
   0D40 D7 04         [ 4] 1028 	stb	*_dp_VIA_t1_cnt_lo
   0D42 CB 11         [ 2] 1029 	addb	#17
   0D44 E7 E2         [ 6] 1030 	stb	,-s
   0D46 F6 C8 AB      [ 5] 1031 	ldb	_the_player+1
   0D49 BD 0F 6E      [ 8] 1032 	jsr	__Moveto_d
   0D4C C6 10         [ 2] 1033 	ldb	#16
   0D4E D7 04         [ 4] 1034 	stb	*_dp_VIA_t1_cnt_lo
   0D50 8E 08 7E      [ 3] 1035 	ldx	#_vl_player_mid2
   0D53 BD F4 10      [ 8] 1036 	jsr	___Draw_VLp
   0D56 32 62         [ 5] 1037 	leas	2,s
   0D58 7D C8 AE      [ 7] 1038 	tst	_the_player+4
   0D5B 26 0E         [ 3] 1039 	bne	L23
   0D5D C6 01         [ 2] 1040 	ldb	#1
   0D5F F7 C8 AA      [ 5] 1041 	stb	_the_player
   0D62 7F C8 AB      [ 7] 1042 	clr	_the_player+1
   0D65 8E 08 28      [ 3] 1043 	ldx	#_player_draw
   0D68 BF C8 AF      [ 6] 1044 	stx	_the_player+5
   0D6B                    1045 L23:
   0D6B 35 C0         [ 7] 1046 	puls	u,pc
                           1047 	.globl	_player_change_mid_to_left_step1
   0D6D                    1048 _player_change_mid_to_left_step1:
   0D6D 34 40         [ 6] 1049 	pshs	u
   0D6F 7A C8 AE      [ 7] 1050 	dec	_the_player+4
   0D72 F6 C8 AE      [ 5] 1051 	ldb	_the_player+4
   0D75 4F            [ 2] 1052 	clra		;zero_extendqihi: R:b -> R:d
   0D76 FE C8 AC      [ 6] 1053 	ldu	_the_player+2
   0D79 30 CB         [ 8] 1054 	leax	d,u
   0D7B E6 84         [ 4] 1055 	ldb	,x
   0D7D F7 C8 AB      [ 5] 1056 	stb	_the_player+1
   0D80 BD F2 A5      [ 8] 1057 	jsr	___Intensity_5F
   0D83 BD F3 54      [ 8] 1058 	jsr	___Reset0Ref
   0D86 C6 7F         [ 2] 1059 	ldb	#127
   0D88 D7 04         [ 4] 1060 	stb	*_dp_VIA_t1_cnt_lo
   0D8A CB 11         [ 2] 1061 	addb	#17
   0D8C E7 E2         [ 6] 1062 	stb	,-s
   0D8E F6 C8 AB      [ 5] 1063 	ldb	_the_player+1
   0D91 BD 0F 6E      [ 8] 1064 	jsr	__Moveto_d
   0D94 C6 10         [ 2] 1065 	ldb	#16
   0D96 D7 04         [ 4] 1066 	stb	*_dp_VIA_t1_cnt_lo
   0D98 8E 08 3E      [ 3] 1067 	ldx	#_vl_player_mid1
   0D9B BD F4 10      [ 8] 1068 	jsr	___Draw_VLp
   0D9E BD F3 54      [ 8] 1069 	jsr	___Reset0Ref
   0DA1 C6 7F         [ 2] 1070 	ldb	#127
   0DA3 D7 04         [ 4] 1071 	stb	*_dp_VIA_t1_cnt_lo
   0DA5 CB 11         [ 2] 1072 	addb	#17
   0DA7 E7 E2         [ 6] 1073 	stb	,-s
   0DA9 F6 C8 AB      [ 5] 1074 	ldb	_the_player+1
   0DAC BD 0F 6E      [ 8] 1075 	jsr	__Moveto_d
   0DAF C6 10         [ 2] 1076 	ldb	#16
   0DB1 D7 04         [ 4] 1077 	stb	*_dp_VIA_t1_cnt_lo
   0DB3 8E 08 7E      [ 3] 1078 	ldx	#_vl_player_mid2
   0DB6 BD F4 10      [ 8] 1079 	jsr	___Draw_VLp
   0DB9 32 62         [ 5] 1080 	leas	2,s
   0DBB 7D C8 AE      [ 7] 1081 	tst	_the_player+4
   0DBE 26 19         [ 3] 1082 	bne	L26
   0DC0 8E 0D DB      [ 3] 1083 	ldx	#_player_change_mid_to_left_step2
   0DC3 BF C8 AF      [ 6] 1084 	stx	_the_player+5
   0DC6 F6 C8 A4      [ 5] 1085 	ldb	_the_game+2
   0DC9 4F            [ 2] 1086 	clra		;zero_extendqihi: R:b -> R:d
   0DCA 1F 01         [ 6] 1087 	tfr	d,x
   0DCC E6 89 07 E4   [ 8] 1088 	ldb	_PLAYER_ANIMATION_FRAME_CNT_STAGE2_LUT,x
   0DD0 F7 C8 AE      [ 5] 1089 	stb	_the_player+4
   0DD3 8E 08 0A      [ 3] 1090 	ldx	#__SP1_MID_LEFT_X_LUT_2
   0DD6 BF C8 AC      [ 6] 1091 	stx	_the_player+2
   0DD9                    1092 L26:
   0DD9 35 C0         [ 7] 1093 	puls	u,pc
                           1094 	.globl	_player_change_mid_to_left_step2
   0DDB                    1095 _player_change_mid_to_left_step2:
   0DDB 34 40         [ 6] 1096 	pshs	u
   0DDD 7A C8 AE      [ 7] 1097 	dec	_the_player+4
   0DE0 F6 C8 AE      [ 5] 1098 	ldb	_the_player+4
   0DE3 4F            [ 2] 1099 	clra		;zero_extendqihi: R:b -> R:d
   0DE4 FE C8 AC      [ 6] 1100 	ldu	_the_player+2
   0DE7 30 CB         [ 8] 1101 	leax	d,u
   0DE9 E6 84         [ 4] 1102 	ldb	,x
   0DEB F7 C8 AB      [ 5] 1103 	stb	_the_player+1
   0DEE BD F2 A5      [ 8] 1104 	jsr	___Intensity_5F
   0DF1 BD F3 54      [ 8] 1105 	jsr	___Reset0Ref
   0DF4 C6 7F         [ 2] 1106 	ldb	#127
   0DF6 D7 04         [ 4] 1107 	stb	*_dp_VIA_t1_cnt_lo
   0DF8 CB 11         [ 2] 1108 	addb	#17
   0DFA E7 E2         [ 6] 1109 	stb	,-s
   0DFC F6 C8 AB      [ 5] 1110 	ldb	_the_player+1
   0DFF BD 0F 6E      [ 8] 1111 	jsr	__Moveto_d
   0E02 C6 10         [ 2] 1112 	ldb	#16
   0E04 D7 04         [ 4] 1113 	stb	*_dp_VIA_t1_cnt_lo
   0E06 8E 08 C7      [ 3] 1114 	ldx	#_vl_player_left1
   0E09 BD F4 10      [ 8] 1115 	jsr	___Draw_VLp
   0E0C BD F3 54      [ 8] 1116 	jsr	___Reset0Ref
   0E0F C6 7F         [ 2] 1117 	ldb	#127
   0E11 D7 04         [ 4] 1118 	stb	*_dp_VIA_t1_cnt_lo
   0E13 CB 11         [ 2] 1119 	addb	#17
   0E15 E7 E2         [ 6] 1120 	stb	,-s
   0E17 F6 C8 AB      [ 5] 1121 	ldb	_the_player+1
   0E1A BD 0F 6E      [ 8] 1122 	jsr	__Moveto_d
   0E1D C6 10         [ 2] 1123 	ldb	#16
   0E1F D7 04         [ 4] 1124 	stb	*_dp_VIA_t1_cnt_lo
   0E21 8E 09 13      [ 3] 1125 	ldx	#_vl_player_left2
   0E24 BD F4 10      [ 8] 1126 	jsr	___Draw_VLp
   0E27 BD F3 54      [ 8] 1127 	jsr	___Reset0Ref
   0E2A C6 7F         [ 2] 1128 	ldb	#127
   0E2C D7 04         [ 4] 1129 	stb	*_dp_VIA_t1_cnt_lo
   0E2E CB 11         [ 2] 1130 	addb	#17
   0E30 E7 E2         [ 6] 1131 	stb	,-s
   0E32 F6 C8 AB      [ 5] 1132 	ldb	_the_player+1
   0E35 BD 0F 6E      [ 8] 1133 	jsr	__Moveto_d
   0E38 C6 10         [ 2] 1134 	ldb	#16
   0E3A D7 04         [ 4] 1135 	stb	*_dp_VIA_t1_cnt_lo
   0E3C 8E 09 77      [ 3] 1136 	ldx	#_vl_player_left3
   0E3F BD F4 10      [ 8] 1137 	jsr	___Draw_VLp
   0E42 32 63         [ 5] 1138 	leas	3,s
   0E44 7D C8 AE      [ 7] 1139 	tst	_the_player+4
   0E47 26 0E         [ 3] 1140 	bne	L29
   0E49 7F C8 AA      [ 7] 1141 	clr	_the_player
   0E4C C6 AE         [ 2] 1142 	ldb	#-82
   0E4E F7 C8 AB      [ 5] 1143 	stb	_the_player+1
   0E51 8E 08 28      [ 3] 1144 	ldx	#_player_draw
   0E54 BF C8 AF      [ 6] 1145 	stx	_the_player+5
   0E57                    1146 L29:
   0E57 35 C0         [ 7] 1147 	puls	u,pc
                           1148 	.globl	__player_draw_mid
   0E59                    1149 __player_draw_mid:
   0E59 BD F3 54      [ 8] 1150 	jsr	___Reset0Ref
   0E5C C6 7F         [ 2] 1151 	ldb	#127
   0E5E D7 04         [ 4] 1152 	stb	*_dp_VIA_t1_cnt_lo
   0E60 CB 11         [ 2] 1153 	addb	#17
   0E62 E7 E2         [ 6] 1154 	stb	,-s
   0E64 F6 C8 AB      [ 5] 1155 	ldb	_the_player+1
   0E67 BD 0F 6E      [ 8] 1156 	jsr	__Moveto_d
   0E6A C6 10         [ 2] 1157 	ldb	#16
   0E6C D7 04         [ 4] 1158 	stb	*_dp_VIA_t1_cnt_lo
   0E6E 8E 08 3E      [ 3] 1159 	ldx	#_vl_player_mid1
   0E71 BD F4 10      [ 8] 1160 	jsr	___Draw_VLp
   0E74 BD F3 54      [ 8] 1161 	jsr	___Reset0Ref
   0E77 C6 7F         [ 2] 1162 	ldb	#127
   0E79 D7 04         [ 4] 1163 	stb	*_dp_VIA_t1_cnt_lo
   0E7B CB 11         [ 2] 1164 	addb	#17
   0E7D E7 E2         [ 6] 1165 	stb	,-s
   0E7F F6 C8 AB      [ 5] 1166 	ldb	_the_player+1
   0E82 BD 0F 6E      [ 8] 1167 	jsr	__Moveto_d
   0E85 C6 10         [ 2] 1168 	ldb	#16
   0E87 D7 04         [ 4] 1169 	stb	*_dp_VIA_t1_cnt_lo
   0E89 32 62         [ 5] 1170 	leas	2,s
   0E8B 8E 08 7E      [ 3] 1171 	ldx	#_vl_player_mid2
   0E8E 7E F4 10      [ 4] 1172 	jmp	___Draw_VLp
                           1173 	.globl	__player_draw_left
   0E91                    1174 __player_draw_left:
   0E91 BD F3 54      [ 8] 1175 	jsr	___Reset0Ref
   0E94 C6 7F         [ 2] 1176 	ldb	#127
   0E96 D7 04         [ 4] 1177 	stb	*_dp_VIA_t1_cnt_lo
   0E98 CB 11         [ 2] 1178 	addb	#17
   0E9A E7 E2         [ 6] 1179 	stb	,-s
   0E9C F6 C8 AB      [ 5] 1180 	ldb	_the_player+1
   0E9F BD 0F 6E      [ 8] 1181 	jsr	__Moveto_d
   0EA2 C6 10         [ 2] 1182 	ldb	#16
   0EA4 D7 04         [ 4] 1183 	stb	*_dp_VIA_t1_cnt_lo
   0EA6 8E 08 C7      [ 3] 1184 	ldx	#_vl_player_left1
   0EA9 BD F4 10      [ 8] 1185 	jsr	___Draw_VLp
   0EAC BD F3 54      [ 8] 1186 	jsr	___Reset0Ref
   0EAF C6 7F         [ 2] 1187 	ldb	#127
   0EB1 D7 04         [ 4] 1188 	stb	*_dp_VIA_t1_cnt_lo
   0EB3 CB 11         [ 2] 1189 	addb	#17
   0EB5 E7 E2         [ 6] 1190 	stb	,-s
   0EB7 F6 C8 AB      [ 5] 1191 	ldb	_the_player+1
   0EBA BD 0F 6E      [ 8] 1192 	jsr	__Moveto_d
   0EBD C6 10         [ 2] 1193 	ldb	#16
   0EBF D7 04         [ 4] 1194 	stb	*_dp_VIA_t1_cnt_lo
   0EC1 8E 09 13      [ 3] 1195 	ldx	#_vl_player_left2
   0EC4 BD F4 10      [ 8] 1196 	jsr	___Draw_VLp
   0EC7 BD F3 54      [ 8] 1197 	jsr	___Reset0Ref
   0ECA C6 7F         [ 2] 1198 	ldb	#127
   0ECC D7 04         [ 4] 1199 	stb	*_dp_VIA_t1_cnt_lo
   0ECE CB 11         [ 2] 1200 	addb	#17
   0ED0 E7 E2         [ 6] 1201 	stb	,-s
   0ED2 F6 C8 AB      [ 5] 1202 	ldb	_the_player+1
   0ED5 BD 0F 6E      [ 8] 1203 	jsr	__Moveto_d
   0ED8 C6 10         [ 2] 1204 	ldb	#16
   0EDA D7 04         [ 4] 1205 	stb	*_dp_VIA_t1_cnt_lo
   0EDC 32 63         [ 5] 1206 	leas	3,s
   0EDE 8E 09 77      [ 3] 1207 	ldx	#_vl_player_left3
   0EE1 7E F4 10      [ 4] 1208 	jmp	___Draw_VLp
                           1209 	.globl	__player_draw_right
   0EE4                    1210 __player_draw_right:
   0EE4 BD F3 54      [ 8] 1211 	jsr	___Reset0Ref
   0EE7 C6 7F         [ 2] 1212 	ldb	#127
   0EE9 D7 04         [ 4] 1213 	stb	*_dp_VIA_t1_cnt_lo
   0EEB CB 11         [ 2] 1214 	addb	#17
   0EED E7 E2         [ 6] 1215 	stb	,-s
   0EEF F6 C8 AB      [ 5] 1216 	ldb	_the_player+1
   0EF2 BD 0F 6E      [ 8] 1217 	jsr	__Moveto_d
   0EF5 C6 10         [ 2] 1218 	ldb	#16
   0EF7 D7 04         [ 4] 1219 	stb	*_dp_VIA_t1_cnt_lo
   0EF9 8E 09 B7      [ 3] 1220 	ldx	#_vl_player_right1
   0EFC BD F4 10      [ 8] 1221 	jsr	___Draw_VLp
   0EFF BD F3 54      [ 8] 1222 	jsr	___Reset0Ref
   0F02 C6 7F         [ 2] 1223 	ldb	#127
   0F04 D7 04         [ 4] 1224 	stb	*_dp_VIA_t1_cnt_lo
   0F06 CB 11         [ 2] 1225 	addb	#17
   0F08 E7 E2         [ 6] 1226 	stb	,-s
   0F0A F6 C8 AB      [ 5] 1227 	ldb	_the_player+1
   0F0D BD 0F 6E      [ 8] 1228 	jsr	__Moveto_d
   0F10 C6 10         [ 2] 1229 	ldb	#16
   0F12 D7 04         [ 4] 1230 	stb	*_dp_VIA_t1_cnt_lo
   0F14 8E 0A 03      [ 3] 1231 	ldx	#_vl_player_right2
   0F17 BD F4 10      [ 8] 1232 	jsr	___Draw_VLp
   0F1A BD F3 54      [ 8] 1233 	jsr	___Reset0Ref
   0F1D C6 7F         [ 2] 1234 	ldb	#127
   0F1F D7 04         [ 4] 1235 	stb	*_dp_VIA_t1_cnt_lo
   0F21 CB 11         [ 2] 1236 	addb	#17
   0F23 E7 E2         [ 6] 1237 	stb	,-s
   0F25 F6 C8 AB      [ 5] 1238 	ldb	_the_player+1
   0F28 BD 0F 6E      [ 8] 1239 	jsr	__Moveto_d
   0F2B C6 10         [ 2] 1240 	ldb	#16
   0F2D D7 04         [ 4] 1241 	stb	*_dp_VIA_t1_cnt_lo
   0F2F 32 63         [ 5] 1242 	leas	3,s
   0F31 8E 0A 67      [ 3] 1243 	ldx	#_vl_player_right3
   0F34 7E F4 10      [ 4] 1244 	jmp	___Draw_VLp
                           1245 	.globl	_check_collision
   0F37                    1246 _check_collision:
   0F37 39            [ 5] 1247 	rts
                           1248 	.globl	__SP1_LEFT_MID_X_LUT_1
   0F38                    1249 __SP1_LEFT_MID_X_LUT_1:
   0F38 D7                 1250 	.byte	-41
   0F39 D1                 1251 	.byte	-47
   0F3A CB                 1252 	.byte	-53
   0F3B C5                 1253 	.byte	-59
   0F3C C0                 1254 	.byte	-64
   0F3D BA                 1255 	.byte	-70
   0F3E B4                 1256 	.byte	-76
                           1257 	.globl	__SP1_MID_RIGHT_X_LUT_1
   0F3F                    1258 __SP1_MID_RIGHT_X_LUT_1:
   0F3F 29                 1259 	.byte	41
   0F40 23                 1260 	.byte	35
   0F41 1D                 1261 	.byte	29
   0F42 17                 1262 	.byte	23
   0F43 12                 1263 	.byte	18
   0F44 0C                 1264 	.byte	12
   0F45 06                 1265 	.byte	6
                           1266 	.globl	__SP1_RIGHT_MID_X_LUT_1
   0F46                    1267 __SP1_RIGHT_MID_X_LUT_1:
   0F46 29                 1268 	.byte	41
   0F47 2F                 1269 	.byte	47
   0F48 35                 1270 	.byte	53
   0F49 3B                 1271 	.byte	59
   0F4A 40                 1272 	.byte	64
   0F4B 46                 1273 	.byte	70
   0F4C 4C                 1274 	.byte	76
                           1275 	.globl	__SP1_MID_LEFT_X_LUT_1
   0F4D                    1276 __SP1_MID_LEFT_X_LUT_1:
   0F4D D7                 1277 	.byte	-41
   0F4E DD                 1278 	.byte	-35
   0F4F E3                 1279 	.byte	-29
   0F50 E9                 1280 	.byte	-23
   0F51 EE                 1281 	.byte	-18
   0F52 F4                 1282 	.byte	-12
   0F53 FA                 1283 	.byte	-6
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Sat Jun 14 01:20:49 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L11                03B8 R   |   3 L14                0426 R
  3 L17                04A6 R   |   3 L20                052F R
  3 L23                0592 R   |   3 L26                0600 R
  3 L29                067E R   |   3 L7                 0355 R
  3 _PLAYER_ANIMAT     0000 GR  |   3 _PLAYER_ANIMAT     000B GR
  3 _PLAYER_DRAW_L     0019 GR  |   3 _PLAYER_STATIC     0016 GR
    __Moveto_d         **** GX  |   3 __SP1_LEFT_MID     075F GR
  3 __SP1_LEFT_MID     001F GR  |   3 __SP1_MID_LEFT     0774 GR
  3 __SP1_MID_LEFT     0031 GR  |   3 __SP1_MID_RIGH     0766 GR
  3 __SP1_MID_RIGH     0025 GR  |   3 __SP1_RIGHT_MI     076D GR
  3 __SP1_RIGHT_MI     002B GR  |     ___Draw_VLp        **** GX
    ___Intensity_5     **** GX  |     ___Reset0Ref       **** GX
  3 __player_draw_     06B8 GR  |   3 __player_draw_     0680 GR
  3 __player_draw_     070B GR  |   3 _check_collisi     075E GR
    _dp_VIA_t1_cnt     **** GX  |   3 _player_change     02CE GR
  3 _player_change     0357 GR  |   3 _player_change     0594 GR
  3 _player_change     0602 GR  |   3 _player_change     03BA GR
  3 _player_change     0428 GR  |   3 _player_change     04A8 GR
  3 _player_change     0531 GR  |   3 _player_draw       004F GR
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
Hexadecimal [16-Bits]                                 Sat Jun 14 01:20:49 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    7   flags    0
   3 .text            size  77B   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

