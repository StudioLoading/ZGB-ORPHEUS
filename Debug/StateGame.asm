;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module StateGame
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _Update_StateGame
	.globl _Start_StateGame
	.globl b_e_configure
	.globl _e_configure
	.globl _SpriteManagerAdd
	.globl _GetMapSize
	.globl _UpdateMapTile
	.globl _LoadMap
	.globl _InitScroll
	.globl _ScrollSetTiles
	.globl _move_camera_destx
	.globl _move_camera_desty
	.globl _move_camera_right
	.globl _move_camera_left
	.globl _move_camera_down
	.globl _move_camera_up
	.globl _update_hud
	.globl _song_selection
	.globl _s_orpheus
	.globl _s_camera
	.globl _coll_surface_intro
	.globl _coll_tiles_intro
	.globl ___bank_StateGame
	.globl b_UpdateHUD
	.globl _UpdateHUD
	.globl _fill_bar_idx
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
G$s_camera$0_0$0==.
_s_camera::
	.ds 2
G$s_orpheus$0_0$0==.
_s_orpheus::
	.ds 2
G$song_selection$0_0$0==.
_song_selection::
	.ds 1
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
G$update_hud$0_0$0==.
_update_hud::
	.ds 1
G$move_camera_up$0_0$0==.
_move_camera_up::
	.ds 1
G$move_camera_down$0_0$0==.
_move_camera_down::
	.ds 1
G$move_camera_left$0_0$0==.
_move_camera_left::
	.ds 1
G$move_camera_right$0_0$0==.
_move_camera_right::
	.ds 1
G$move_camera_desty$0_0$0==.
_move_camera_desty::
	.ds 2
G$move_camera_destx$0_0$0==.
_move_camera_destx::
	.ds 2
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area _DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE_255
	G$Start_StateGame$0$0	= .
	.globl	G$Start_StateGame$0$0
	C$StateGame.c$55$0_0$194	= .
	.globl	C$StateGame.c$55$0_0$194
;StateGame.c:55: void START() {
;	---------------------------------
; Function Start_StateGame
; ---------------------------------
_Start_StateGame::
	C$StateGame.c$57$1_0$194	= .
	.globl	C$StateGame.c$57$1_0$194
;StateGame.c:57: scroll_top_movement_limit = 72u;
	ld	hl, #_scroll_top_movement_limit
	ld	(hl), #0x48
	C$StateGame.c$58$1_0$194	= .
	.globl	C$StateGame.c$58$1_0$194
;StateGame.c:58: scroll_bottom_movement_limit = 72u;
	ld	hl, #_scroll_bottom_movement_limit
	ld	(hl), #0x48
	C$StateGame.c$60$1_0$194	= .
	.globl	C$StateGame.c$60$1_0$194
;StateGame.c:60: scroll_target = SpriteManagerAdd(SpriteCamera, ((UINT16) 30u << 3), ((UINT16) 64u << 3));
	ld	de, #0x0200
	push	de
	ld	de, #0x00f0
	ld	a, #0x01
	call	_SpriteManagerAdd
	ld	hl, #_scroll_target
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	C$StateGame.c$61$1_0$194	= .
	.globl	C$StateGame.c$61$1_0$194
;StateGame.c:61: s_orpheus = SpriteManagerAdd(SpriteOrpheus, ((UINT16) 26u << 3) + 3u, ((UINT16) 67u << 3));
	ld	de, #0x0218
	push	de
	ld	de, #0x00d3
	xor	a, a
	call	_SpriteManagerAdd
	ld	hl, #_s_orpheus
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	C$StateGame.c$62$1_1$195	= .
	.globl	C$StateGame.c$62$1_1$195
;StateGame.c:62: Sprite* e_enemy = SpriteManagerAdd(SpriteSkeleton, ((UINT16) 28u << 3), ((UINT16) 60u << 3));
	ld	de, #0x01e0
	push	de
	ld	de, #0x00e0
	ld	a, #0x02
	call	_SpriteManagerAdd
	C$StateGame.c$63$1_1$195	= .
	.globl	C$StateGame.c$63$1_1$195
;StateGame.c:63: e_configure(e_enemy, SKELETON);
	xor	a, a
	push	af
	inc	sp
	push	bc
	ld	e, #b_e_configure
	ld	hl, #_e_configure
	call	___sdcc_bcall_ehl
	add	sp, #3
	C$StateGame.c$65$1_1$195	= .
	.globl	C$StateGame.c$65$1_1$195
;StateGame.c:65: InitScroll(BANK(omapintro), &omapintro, coll_tiles_intro, coll_surface_intro);
	ld	de, #_omapintro+0
	ld	c, #<(___bank_omapintro)
	ld	hl, #_coll_surface_intro
	push	hl
	ld	hl, #_coll_tiles_intro
	push	hl
	ld	a, c
	call	_InitScroll
	C$StateGame.c$67$1_1$195	= .
	.globl	C$StateGame.c$67$1_1$195
;StateGame.c:67: INIT_FONT(font, PRINT_BKG);
	ld	hl, #_print_target
	ld	(hl), #0x00
	ld	bc, #_font+0
	ld	e, #<(___bank_font)
	push	bc
	ld	a, (#_last_tile_loaded)
	call	_ScrollSetTiles
	ld	hl, #_font_offset
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	C$StateGame.c$68$1_1$195	= .
	.globl	C$StateGame.c$68$1_1$195
;StateGame.c:68: INIT_HUD(hudmap);
	ld	de, #_hudmap
	ld	c, #<(___bank_hudmap)
	ld	hl, #_scroll_h_border
	push	hl
	ld	hl, #0x0000
	push	hl
	ld	a, c
	call	_GetMapSize
	ld	hl, #_scroll_h_border
	ld	a, (hl)
	add	a, a
	add	a, a
	add	a, a
	ld	(hl), a
	ld	a, #0x07
	ldh	(_WX_REG + 0), a
	ld	a, #0x90
	sub	a, (hl)
	ldh	(_WY_REG + 0), a
	ld	bc, #_hudmap
	ld	a, #<(___bank_hudmap)
	push	bc
	ld	h, a
	ld	l, #0x00
	push	hl
	ld	e, #0x00
	ld	a, #0x01
	call	_LoadMap
	ld	hl, #_hud_map_offset
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x20
	ldh	(_LCDC_REG + 0), a
	C$StateGame.c$72$1_1$195	= .
	.globl	C$StateGame.c$72$1_1$195
;StateGame.c:72: update_hud = 1;
	ld	hl, #_update_hud
	ld	(hl), #0x01
	C$StateGame.c$73$1_1$195	= .
	.globl	C$StateGame.c$73$1_1$195
;StateGame.c:73: move_camera_up = 0u;
	ld	hl, #_move_camera_up
	ld	(hl), #0x00
	C$StateGame.c$74$1_1$195	= .
	.globl	C$StateGame.c$74$1_1$195
;StateGame.c:74: move_camera_desty = 0u;
	xor	a, a
	ld	hl, #_move_camera_desty
	ld	(hl+), a
	ld	(hl), a
	C$StateGame.c$75$1_1$195	= .
	.globl	C$StateGame.c$75$1_1$195
;StateGame.c:75: move_camera_destx = 0u;
	xor	a, a
	ld	hl, #_move_camera_destx
	ld	(hl+), a
	ld	(hl), a
	C$StateGame.c$76$1_1$195	= .
	.globl	C$StateGame.c$76$1_1$195
;StateGame.c:76: move_camera_down = 0u;
	ld	hl, #_move_camera_down
	ld	(hl), #0x00
	C$StateGame.c$77$1_1$195	= .
	.globl	C$StateGame.c$77$1_1$195
;StateGame.c:77: move_camera_left = 0u;
	ld	hl, #_move_camera_left
	ld	(hl), #0x00
	C$StateGame.c$78$1_1$194	= .
	.globl	C$StateGame.c$78$1_1$194
;StateGame.c:78: }
	C$StateGame.c$78$1_1$194	= .
	.globl	C$StateGame.c$78$1_1$194
	XG$Start_StateGame$0$0	= .
	.globl	XG$Start_StateGame$0$0
	ret
G$__bank_StateGame$0_0$0 == 0x00ff
___bank_StateGame	=	0x00ff
G$coll_tiles_intro$0_0$0 == .
_coll_tiles_intro:
	.db #0x04	; 4
	.db #0x33	; 51	'3'
	.db #0x29	; 41
	.db #0x35	; 53	'5'
	.db #0x3c	; 60
	.db #0x3d	; 61
	.db #0x3e	; 62
	.db #0x3f	; 63
	.db #0x40	; 64
	.db #0x41	; 65	'A'
	.db #0x52	; 82	'R'
	.db #0x57	; 87	'W'
	.db #0x58	; 88	'X'
	.db #0x59	; 89	'Y'
	.db #0x5a	; 90	'Z'
	.db #0x5b	; 91
	.db #0x5c	; 92
	.db #0x5d	; 93
	.db #0x5e	; 94
	.db #0x5f	; 95
	.db #0x60	; 96
	.db #0x69	; 105	'i'
	.db #0x6a	; 106	'j'
	.db #0x6c	; 108	'l'
	.db #0x6d	; 109	'm'
	.db #0x70	; 112	'p'
	.db #0x71	; 113	'q'
	.db #0x78	; 120	'x'
	.db #0x79	; 121	'y'
	.db #0x7a	; 122	'z'
	.db #0x7b	; 123
	.db #0x7c	; 124
	.db #0x7d	; 125
	.db #0x7e	; 126
	.db #0x7f	; 127
	.db #0x00	; 0
G$coll_surface_intro$0_0$0 == .
_coll_surface_intro:
	.db #0x01	; 1
	.db #0x42	; 66	'B'
	.db #0x43	; 67	'C'
	.db #0x45	; 69	'E'
	.db #0x46	; 70	'F'
	.db #0x61	; 97	'a'
	.db #0x62	; 98	'b'
	.db #0x00	; 0
	G$Update_StateGame$0$0	= .
	.globl	G$Update_StateGame$0$0
	C$StateGame.c$80$1_1$196	= .
	.globl	C$StateGame.c$80$1_1$196
;StateGame.c:80: void UPDATE() {
;	---------------------------------
; Function Update_StateGame
; ---------------------------------
_Update_StateGame::
	add	sp, #-6
	C$StateGame.c$82$1_2$196	= .
	.globl	C$StateGame.c$82$1_2$196
;StateGame.c:82: if(scroll_target->y > move_camera_desty){
	ld	hl, #_scroll_target
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #0x000e
	add	hl, bc
	inc	sp
	inc	sp
	push	hl
	C$StateGame.c$81$1_0$196	= .
	.globl	C$StateGame.c$81$1_0$196
;StateGame.c:81: if(move_camera_up){
	ld	a, (#_move_camera_up)
	or	a, a
	jr	Z, 00122$
	C$StateGame.c$82$1_2$196	= .
	.globl	C$StateGame.c$82$1_2$196
;StateGame.c:82: if(scroll_target->y > move_camera_desty){
	pop	de
	push	de
	ld	a, (de)
	ld	c, a
	inc	de
	ld	a, (de)
	ld	b, a
	ld	hl, #_move_camera_desty
	ld	a, (hl+)
	sub	a, c
	ld	a, (hl)
	sbc	a, b
	jr	NC, 00102$
	C$StateGame.c$83$3_0$198	= .
	.globl	C$StateGame.c$83$3_0$198
;StateGame.c:83: scroll_target->y -= V_CAMERA;
	dec	bc
	dec	bc
	pop	hl
	push	hl
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	jp	00141$
00102$:
	C$StateGame.c$85$3_0$199	= .
	.globl	C$StateGame.c$85$3_0$199
;StateGame.c:85: a_walk_counter_y = -8;
	ld	hl, #_a_walk_counter_y
	ld	(hl), #0xf8
	C$StateGame.c$86$3_0$199	= .
	.globl	C$StateGame.c$86$3_0$199
;StateGame.c:86: move_camera_up = 0;
	ld	hl, #_move_camera_up
	ld	(hl), #0x00
	C$StateGame.c$88$2_0$197	= .
	.globl	C$StateGame.c$88$2_0$197
;StateGame.c:88: return;
	jp	00141$
00122$:
	C$StateGame.c$89$1_0$196	= .
	.globl	C$StateGame.c$89$1_0$196
;StateGame.c:89: }else if(move_camera_down){
	ld	a, (#_move_camera_down)
	or	a, a
	jr	Z, 00119$
	C$StateGame.c$82$1_2$196	= .
	.globl	C$StateGame.c$82$1_2$196
;StateGame.c:82: if(scroll_target->y > move_camera_desty){
	pop	de
	push	de
	ld	a, (de)
	ld	c, a
	inc	de
	ld	a, (de)
	ld	b, a
	C$StateGame.c$90$2_0$200	= .
	.globl	C$StateGame.c$90$2_0$200
;StateGame.c:90: if(scroll_target->y < move_camera_desty){
	ld	hl, #_move_camera_desty
	ld	a, c
	sub	a, (hl)
	inc	hl
	ld	a, b
	sbc	a, (hl)
	jr	NC, 00105$
	C$StateGame.c$91$3_0$201	= .
	.globl	C$StateGame.c$91$3_0$201
;StateGame.c:91: scroll_target->y+=V_CAMERA;
	inc	bc
	inc	bc
	pop	hl
	push	hl
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	jp	00141$
00105$:
	C$StateGame.c$93$3_0$202	= .
	.globl	C$StateGame.c$93$3_0$202
;StateGame.c:93: a_walk_counter_y = +4;
	ld	hl, #_a_walk_counter_y
	ld	(hl), #0x04
	C$StateGame.c$94$3_0$202	= .
	.globl	C$StateGame.c$94$3_0$202
;StateGame.c:94: move_camera_down = 0;
	ld	hl, #_move_camera_down
	ld	(hl), #0x00
	C$StateGame.c$96$2_0$200	= .
	.globl	C$StateGame.c$96$2_0$200
;StateGame.c:96: return;
	jp	00141$
00119$:
	C$StateGame.c$98$1_2$196	= .
	.globl	C$StateGame.c$98$1_2$196
;StateGame.c:98: if(scroll_target->x > move_camera_destx){
	ld	hl, #0x000c
	add	hl, bc
	push	hl
	ld	a, l
	ldhl	sp,	#4
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#3
	ld	(hl), a
	C$StateGame.c$97$1_0$196	= .
	.globl	C$StateGame.c$97$1_0$196
;StateGame.c:97: }else if(move_camera_left){
	ld	a, (#_move_camera_left)
	or	a, a
	jr	Z, 00116$
	C$StateGame.c$98$1_2$196	= .
	.globl	C$StateGame.c$98$1_2$196
;StateGame.c:98: if(scroll_target->x > move_camera_destx){
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	c, a
	inc	de
	ld	a, (de)
	ld	b, a
	ld	hl, #_move_camera_destx
	ld	a, (hl+)
	sub	a, c
	ld	a, (hl)
	sbc	a, b
	jr	NC, 00108$
	C$StateGame.c$99$3_0$204	= .
	.globl	C$StateGame.c$99$3_0$204
;StateGame.c:99: scroll_target->x-=V_CAMERA;
	dec	bc
	dec	bc
	ldhl	sp,	#2
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	jp	00141$
00108$:
	C$StateGame.c$101$3_0$205	= .
	.globl	C$StateGame.c$101$3_0$205
;StateGame.c:101: a_walk_counter_x = -4;
	ld	hl, #_a_walk_counter_x
	ld	(hl), #0xfc
	C$StateGame.c$102$3_0$205	= .
	.globl	C$StateGame.c$102$3_0$205
;StateGame.c:102: move_camera_left = 0;
	ld	hl, #_move_camera_left
	ld	(hl), #0x00
	C$StateGame.c$104$2_0$203	= .
	.globl	C$StateGame.c$104$2_0$203
;StateGame.c:104: return;
	jp	00141$
00116$:
	C$StateGame.c$105$1_0$196	= .
	.globl	C$StateGame.c$105$1_0$196
;StateGame.c:105: }else if(move_camera_right){
	ld	a, (#_move_camera_right)
	or	a, a
	jr	Z, 00120$
	C$StateGame.c$98$1_2$196	= .
	.globl	C$StateGame.c$98$1_2$196
;StateGame.c:98: if(scroll_target->x > move_camera_destx){
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	c, a
	inc	de
	ld	a, (de)
	ld	b, a
	C$StateGame.c$106$2_0$206	= .
	.globl	C$StateGame.c$106$2_0$206
;StateGame.c:106: if(scroll_target->x < move_camera_destx){
	ld	hl, #_move_camera_destx
	ld	a, c
	sub	a, (hl)
	inc	hl
	ld	a, b
	sbc	a, (hl)
	jr	NC, 00111$
	C$StateGame.c$107$3_0$207	= .
	.globl	C$StateGame.c$107$3_0$207
;StateGame.c:107: scroll_target->x+=V_CAMERA;
	inc	bc
	inc	bc
	ldhl	sp,	#2
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	jp	00141$
00111$:
	C$StateGame.c$109$3_0$208	= .
	.globl	C$StateGame.c$109$3_0$208
;StateGame.c:109: a_walk_counter_x = +4;
	ld	hl, #_a_walk_counter_x
	ld	(hl), #0x04
	C$StateGame.c$110$3_0$208	= .
	.globl	C$StateGame.c$110$3_0$208
;StateGame.c:110: move_camera_right = 0;
	ld	hl, #_move_camera_right
	ld	(hl), #0x00
	C$StateGame.c$112$2_0$206	= .
	.globl	C$StateGame.c$112$2_0$206
;StateGame.c:112: return;
	jp	00141$
00120$:
	C$StateGame.c$114$1_2$196	= .
	.globl	C$StateGame.c$114$1_2$196
;StateGame.c:114: INT16 orpheus_scroll_deltay = s_orpheus->y - scroll_target->y;
	ld	a, (#_s_orpheus)
	ldhl	sp,	#4
	ld	(hl), a
	ld	a, (#_s_orpheus + 1)
	ldhl	sp,	#5
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x000e
	add	hl, de
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	pop	de
	push	de
	ld	a, (de)
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	inc	de
	ld	a, (de)
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	ld	a, c
	sub	a, l
	ld	c, a
	ld	a, b
	sbc	a, h
	ld	b, a
	C$StateGame.c$115$1_1$209	= .
	.globl	C$StateGame.c$115$1_1$209
;StateGame.c:115: if(orpheus_scroll_deltay < -72){
	ld	a, c
	sub	a, #0xb8
	ld	a, b
	rla
	ccf
	rra
	sbc	a, #0x7f
	jr	NC, 00127$
	C$StateGame.c$116$2_1$210	= .
	.globl	C$StateGame.c$116$2_1$210
;StateGame.c:116: move_camera_up = 1;
	ld	hl, #_move_camera_up
	ld	(hl), #0x01
	C$StateGame.c$117$2_1$210	= .
	.globl	C$StateGame.c$117$2_1$210
;StateGame.c:117: move_camera_desty = scroll_target->y - 144u;
	pop	de
	push	de
	ld	a, (de)
	ld	c, a
	inc	de
	ld	a, (de)
	ld	b, a
	ld	a, c
	add	a, #0x70
	ld	hl, #_move_camera_desty
	ld	(hl+), a
	ld	a, b
	adc	a, #0xff
	ld	(hl), a
	C$StateGame.c$118$2_1$210	= .
	.globl	C$StateGame.c$118$2_1$210
;StateGame.c:118: a_walk_counter_y = -24;
	ld	hl, #_a_walk_counter_y
	ld	(hl), #0xe8
	C$StateGame.c$119$2_1$210	= .
	.globl	C$StateGame.c$119$2_1$210
;StateGame.c:119: return;
	jp	00141$
00127$:
	C$StateGame.c$120$1_1$209	= .
	.globl	C$StateGame.c$120$1_1$209
;StateGame.c:120: }else if(orpheus_scroll_deltay > 48){
	ld	e, b
	ld	d, #0x00
	ld	a, #0x30
	cp	a, c
	ld	a, #0x00
	sbc	a, b
	bit	7, e
	jr	Z, 00255$
	bit	7, d
	jr	NZ, 00256$
	cp	a, a
	jr	00256$
00255$:
	bit	7, d
	jr	Z, 00256$
	scf
00256$:
	jr	NC, 00128$
	C$StateGame.c$121$2_1$211	= .
	.globl	C$StateGame.c$121$2_1$211
;StateGame.c:121: move_camera_down = 1;
	ld	hl, #_move_camera_down
	ld	(hl), #0x01
	C$StateGame.c$122$2_1$211	= .
	.globl	C$StateGame.c$122$2_1$211
;StateGame.c:122: move_camera_desty = scroll_target->y + 144u;
	pop	de
	push	de
	ld	a, (de)
	ld	c, a
	inc	de
	ld	a, (de)
	ld	b, a
	ld	hl, #0x0090
	add	hl, bc
	ld	e, l
	ld	d, h
	ld	hl, #_move_camera_desty
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
	C$StateGame.c$123$2_1$211	= .
	.globl	C$StateGame.c$123$2_1$211
;StateGame.c:123: a_walk_counter_y = +24;
	ld	hl, #_a_walk_counter_y
	ld	(hl), #0x18
	C$StateGame.c$124$2_1$211	= .
	.globl	C$StateGame.c$124$2_1$211
;StateGame.c:124: return;
	jp	00141$
00128$:
	C$StateGame.c$126$1_2$212	= .
	.globl	C$StateGame.c$126$1_2$212
;StateGame.c:126: INT16 orpheus_scroll_deltax = s_orpheus->x - scroll_target->x;
	ldhl	sp,#4
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x000c
	add	hl, de
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	inc	de
	ld	a, (de)
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	ld	a, c
	sub	a, l
	ld	c, a
	ld	a, b
	sbc	a, h
	ld	b, a
	C$StateGame.c$127$1_2$212	= .
	.globl	C$StateGame.c$127$1_2$212
;StateGame.c:127: if(orpheus_scroll_deltax < - 80){
	ld	a, c
	sub	a, #0xb0
	ld	a, b
	rla
	ccf
	rra
	sbc	a, #0x7f
	jr	NC, 00132$
	C$StateGame.c$128$2_2$213	= .
	.globl	C$StateGame.c$128$2_2$213
;StateGame.c:128: move_camera_left= 1;
	ld	hl, #_move_camera_left
	ld	(hl), #0x01
	C$StateGame.c$129$2_2$213	= .
	.globl	C$StateGame.c$129$2_2$213
;StateGame.c:129: move_camera_destx = scroll_target->x - 160u;
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	c, a
	inc	de
	ld	a, (de)
	ld	b, a
	ld	a, c
	add	a, #0x60
	ld	hl, #_move_camera_destx
	ld	(hl+), a
	ld	a, b
	adc	a, #0xff
	ld	(hl), a
	C$StateGame.c$130$2_2$213	= .
	.globl	C$StateGame.c$130$2_2$213
;StateGame.c:130: a_walk_counter_x = -8;
	ld	hl, #_a_walk_counter_x
	ld	(hl), #0xf8
	C$StateGame.c$131$2_2$213	= .
	.globl	C$StateGame.c$131$2_2$213
;StateGame.c:131: return;
	jr	00141$
00132$:
	C$StateGame.c$132$1_2$212	= .
	.globl	C$StateGame.c$132$1_2$212
;StateGame.c:132: }else if(orpheus_scroll_deltax > 72){
	ld	e, b
	ld	d, #0x00
	ld	a, #0x48
	cp	a, c
	ld	a, #0x00
	sbc	a, b
	bit	7, e
	jr	Z, 00257$
	bit	7, d
	jr	NZ, 00258$
	cp	a, a
	jr	00258$
00257$:
	bit	7, d
	jr	Z, 00258$
	scf
00258$:
	jr	NC, 00133$
	C$StateGame.c$133$2_2$214	= .
	.globl	C$StateGame.c$133$2_2$214
;StateGame.c:133: move_camera_right = 1;
	ld	hl, #_move_camera_right
	ld	(hl), #0x01
	C$StateGame.c$134$2_2$214	= .
	.globl	C$StateGame.c$134$2_2$214
;StateGame.c:134: move_camera_destx = scroll_target->x + 160u;
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	c, a
	inc	de
	ld	a, (de)
	ld	b, a
	ld	hl, #0x00a0
	add	hl, bc
	ld	e, l
	ld	d, h
	ld	hl, #_move_camera_destx
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
	C$StateGame.c$135$2_2$214	= .
	.globl	C$StateGame.c$135$2_2$214
;StateGame.c:135: a_walk_counter_x = +8;
	ld	hl, #_a_walk_counter_x
	ld	(hl), #0x08
	C$StateGame.c$136$2_2$214	= .
	.globl	C$StateGame.c$136$2_2$214
;StateGame.c:136: return;
	jr	00141$
00133$:
	C$StateGame.c$139$1_2$212	= .
	.globl	C$StateGame.c$139$1_2$212
;StateGame.c:139: if(KEY_TICKED(J_SELECT)){
	ld	a, (#_keys)
	bit	6, a
	jr	Z, 00137$
	ld	a, (#_previous_keys)
	bit	6, a
	jr	NZ, 00137$
	C$StateGame.c$140$2_2$215	= .
	.globl	C$StateGame.c$140$2_2$215
;StateGame.c:140: song_selection++;
	ld	hl, #_song_selection
	inc	(hl)
	C$StateGame.c$141$2_2$215	= .
	.globl	C$StateGame.c$141$2_2$215
;StateGame.c:141: if(song_selection == 3){
	ld	a, (hl)
	sub	a, #0x03
	jr	NZ, 00135$
	C$StateGame.c$142$3_2$216	= .
	.globl	C$StateGame.c$142$3_2$216
;StateGame.c:142: song_selection = ATTRACT;
	ld	hl, #_song_selection
	ld	(hl), #0x00
00135$:
	C$StateGame.c$144$2_2$215	= .
	.globl	C$StateGame.c$144$2_2$215
;StateGame.c:144: update_hud = 1;
	ld	hl, #_update_hud
	ld	(hl), #0x01
00137$:
	C$StateGame.c$146$1_2$212	= .
	.globl	C$StateGame.c$146$1_2$212
;StateGame.c:146: if(update_hud != 0){
	ld	a, (#_update_hud)
	or	a, a
	jr	Z, 00141$
	C$StateGame.c$147$2_2$217	= .
	.globl	C$StateGame.c$147$2_2$217
;StateGame.c:147: UpdateHUD();
	ld	e, #b_UpdateHUD
	ld	hl, #_UpdateHUD
	call	___sdcc_bcall_ehl
00141$:
	C$StateGame.c$149$1_2$196	= .
	.globl	C$StateGame.c$149$1_2$196
;StateGame.c:149: }
	add	sp, #6
	C$StateGame.c$149$1_2$196	= .
	.globl	C$StateGame.c$149$1_2$196
	XG$Update_StateGame$0$0	= .
	.globl	XG$Update_StateGame$0$0
	ret
	G$UpdateHUD$0$0	= .
	.globl	G$UpdateHUD$0$0
	C$StateGame.c$151$1_2$218	= .
	.globl	C$StateGame.c$151$1_2$218
;StateGame.c:151: void UpdateHUD() BANKED{
;	---------------------------------
; Function UpdateHUD
; ---------------------------------
	b_UpdateHUD	= 255
_UpdateHUD::
	dec	sp
	dec	sp
	C$StateGame.c$152$1_0$218	= .
	.globl	C$StateGame.c$152$1_0$218
;StateGame.c:152: update_hud = 0;
	ld	hl, #_update_hud
	ld	(hl), #0x00
	C$StateGame.c$155$1_2$218	= .
	.globl	C$StateGame.c$155$1_2$218
;StateGame.c:155: for(idx = 1; idx <= orpheus_hp_max; idx++){
	ld	c, #0x01
00130$:
	ld	e, c
	ld	a, (#_orpheus_hp_max)
	ld	d,a
	sub	a, c
	bit	7, e
	jr	Z, 00226$
	bit	7, d
	jr	NZ, 00227$
	cp	a, a
	jr	00227$
00226$:
	bit	7, d
	jr	Z, 00227$
	scf
00227$:
	jp	C, 00104$
	C$StateGame.c$156$3_1$221	= .
	.globl	C$StateGame.c$156$3_1$221
;StateGame.c:156: if(idx <= orpheus_hp){
	ld	e, c
	ld	a, (#_orpheus_hp)
	ld	d,a
	sub	a, c
	bit	7, e
	jr	Z, 00228$
	bit	7, d
	jr	NZ, 00229$
	cp	a, a
	jr	00229$
00228$:
	bit	7, d
	jr	Z, 00229$
	scf
00229$:
	jr	C, 00102$
	C$StateGame.c$157$4_1$222	= .
	.globl	C$StateGame.c$157$4_1$222
;StateGame.c:157: UPDATE_HUD_TILE(idx,0,1);
	push	bc
	ld	de, #0x0000
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, c
	ld	a, #0x01
	call	_UpdateMapTile
	pop	bc
	C$StateGame.c$158$4_1$222	= .
	.globl	C$StateGame.c$158$4_1$222
;StateGame.c:158: UPDATE_HUD_TILE(idx,1,2);
	push	bc
	ld	de, #0x0000
	push	de
	ld	a, #0x02
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, c
	ld	a, #0x01
	call	_UpdateMapTile
	pop	bc
	jr	00131$
00102$:
	C$StateGame.c$160$4_1$223	= .
	.globl	C$StateGame.c$160$4_1$223
;StateGame.c:160: UPDATE_HUD_TILE(idx,0,3);
	push	bc
	ld	de, #0x0000
	push	de
	ld	a, #0x03
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, c
	ld	a, #0x01
	call	_UpdateMapTile
	pop	bc
	C$StateGame.c$161$4_1$223	= .
	.globl	C$StateGame.c$161$4_1$223
;StateGame.c:161: UPDATE_HUD_TILE(idx,1,4);
	push	bc
	ld	de, #0x0000
	push	de
	ld	a, #0x04
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, c
	ld	a, #0x01
	call	_UpdateMapTile
	pop	bc
00131$:
	C$StateGame.c$155$2_1$220	= .
	.globl	C$StateGame.c$155$2_1$220
;StateGame.c:155: for(idx = 1; idx <= orpheus_hp_max; idx++){
	inc	c
	jp	00130$
00104$:
	C$StateGame.c$165$1_1$219	= .
	.globl	C$StateGame.c$165$1_1$219
;StateGame.c:165: switch(song_selection){
	ld	a, (#_song_selection)
	or	a, a
	jr	Z, 00105$
	ld	a, (#_song_selection)
	dec	a
	jp	Z,00106$
	ld	a, (#_song_selection)
	sub	a, #0x02
	jp	Z,00107$
	jp	00108$
	C$StateGame.c$166$2_1$224	= .
	.globl	C$StateGame.c$166$2_1$224
;StateGame.c:166: case ATTRACT:
00105$:
	C$StateGame.c$167$2_1$224	= .
	.globl	C$StateGame.c$167$2_1$224
;StateGame.c:167: UPDATE_HUD_TILE(7,0,5);
	ld	de, #0x0000
	push	de
	ld	a, #0x05
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, #0x07
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$168$2_1$224	= .
	.globl	C$StateGame.c$168$2_1$224
;StateGame.c:168: UPDATE_HUD_TILE(7,1,6);
	ld	de, #0x0000
	push	de
	ld	a, #0x06
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, #0x07
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$169$2_1$224	= .
	.globl	C$StateGame.c$169$2_1$224
;StateGame.c:169: UPDATE_HUD_TILE(8,0,7);
	ld	de, #0x0000
	push	de
	ld	a, #0x07
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, #0x08
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$170$2_1$224	= .
	.globl	C$StateGame.c$170$2_1$224
;StateGame.c:170: UPDATE_HUD_TILE(8,1,8);
	ld	de, #0x0000
	push	de
	ld	a, #0x08
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, #0x08
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$172$2_1$224	= .
	.globl	C$StateGame.c$172$2_1$224
;StateGame.c:172: UPDATE_HUD_TILE(9,0,17);
	ld	de, #0x0000
	push	de
	ld	a, #0x11
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, #0x09
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$173$2_1$224	= .
	.globl	C$StateGame.c$173$2_1$224
;StateGame.c:173: UPDATE_HUD_TILE(9,1,18);
	ld	de, #0x0000
	push	de
	ld	a, #0x12
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, #0x09
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$174$2_1$224	= .
	.globl	C$StateGame.c$174$2_1$224
;StateGame.c:174: UPDATE_HUD_TILE(10,0,19);
	ld	de, #0x0000
	push	de
	ld	a, #0x13
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, #0x0a
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$175$2_1$224	= .
	.globl	C$StateGame.c$175$2_1$224
;StateGame.c:175: UPDATE_HUD_TILE(10,1,20);
	ld	de, #0x0000
	push	de
	ld	a, #0x14
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, #0x0a
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$177$2_1$224	= .
	.globl	C$StateGame.c$177$2_1$224
;StateGame.c:177: UPDATE_HUD_TILE(11,0,21);
	ld	de, #0x0000
	push	de
	ld	a, #0x15
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, #0x0b
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$178$2_1$224	= .
	.globl	C$StateGame.c$178$2_1$224
;StateGame.c:178: UPDATE_HUD_TILE(11,1,22);
	ld	de, #0x0000
	push	de
	ld	a, #0x16
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, #0x0b
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$179$2_1$224	= .
	.globl	C$StateGame.c$179$2_1$224
;StateGame.c:179: UPDATE_HUD_TILE(12,0,23);
	ld	de, #0x0000
	push	de
	ld	a, #0x17
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, #0x0c
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$180$2_1$224	= .
	.globl	C$StateGame.c$180$2_1$224
;StateGame.c:180: UPDATE_HUD_TILE(12,1,24);
	ld	de, #0x0000
	push	de
	ld	a, #0x18
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, #0x0c
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$181$2_1$224	= .
	.globl	C$StateGame.c$181$2_1$224
;StateGame.c:181: break;
	jp	00108$
	C$StateGame.c$182$2_1$224	= .
	.globl	C$StateGame.c$182$2_1$224
;StateGame.c:182: case SLEEP:
00106$:
	C$StateGame.c$183$2_1$224	= .
	.globl	C$StateGame.c$183$2_1$224
;StateGame.c:183: UPDATE_HUD_TILE(7,0,9);
	ld	de, #0x0000
	push	de
	ld	a, #0x09
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, #0x07
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$184$2_1$224	= .
	.globl	C$StateGame.c$184$2_1$224
;StateGame.c:184: UPDATE_HUD_TILE(7,1,10);
	ld	de, #0x0000
	push	de
	ld	a, #0x0a
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, #0x07
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$185$2_1$224	= .
	.globl	C$StateGame.c$185$2_1$224
;StateGame.c:185: UPDATE_HUD_TILE(8,0,11);
	ld	de, #0x0000
	push	de
	ld	a, #0x0b
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, #0x08
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$186$2_1$224	= .
	.globl	C$StateGame.c$186$2_1$224
;StateGame.c:186: UPDATE_HUD_TILE(8,1,12);
	ld	de, #0x0000
	push	de
	ld	a, #0x0c
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, #0x08
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$188$2_1$224	= .
	.globl	C$StateGame.c$188$2_1$224
;StateGame.c:188: UPDATE_HUD_TILE(9,0,13);
	ld	de, #0x0000
	push	de
	ld	a, #0x0d
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, #0x09
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$189$2_1$224	= .
	.globl	C$StateGame.c$189$2_1$224
;StateGame.c:189: UPDATE_HUD_TILE(9,1,14);
	ld	de, #0x0000
	push	de
	ld	a, #0x0e
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, #0x09
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$190$2_1$224	= .
	.globl	C$StateGame.c$190$2_1$224
;StateGame.c:190: UPDATE_HUD_TILE(10,0,15);
	ld	de, #0x0000
	push	de
	ld	a, #0x0f
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, #0x0a
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$191$2_1$224	= .
	.globl	C$StateGame.c$191$2_1$224
;StateGame.c:191: UPDATE_HUD_TILE(10,1,16);
	ld	de, #0x0000
	push	de
	ld	a, #0x10
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, #0x0a
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$193$2_1$224	= .
	.globl	C$StateGame.c$193$2_1$224
;StateGame.c:193: UPDATE_HUD_TILE(11,0,21);
	ld	de, #0x0000
	push	de
	ld	a, #0x15
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, #0x0b
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$194$2_1$224	= .
	.globl	C$StateGame.c$194$2_1$224
;StateGame.c:194: UPDATE_HUD_TILE(11,1,22);
	ld	de, #0x0000
	push	de
	ld	a, #0x16
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, #0x0b
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$195$2_1$224	= .
	.globl	C$StateGame.c$195$2_1$224
;StateGame.c:195: UPDATE_HUD_TILE(12,0,23);
	ld	de, #0x0000
	push	de
	ld	a, #0x17
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, #0x0c
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$196$2_1$224	= .
	.globl	C$StateGame.c$196$2_1$224
;StateGame.c:196: UPDATE_HUD_TILE(12,1,24);
	ld	de, #0x0000
	push	de
	ld	a, #0x18
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, #0x0c
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$197$2_1$224	= .
	.globl	C$StateGame.c$197$2_1$224
;StateGame.c:197: break;
	jp	00108$
	C$StateGame.c$198$2_1$224	= .
	.globl	C$StateGame.c$198$2_1$224
;StateGame.c:198: case REPEL:
00107$:
	C$StateGame.c$199$2_1$224	= .
	.globl	C$StateGame.c$199$2_1$224
;StateGame.c:199: UPDATE_HUD_TILE(7,0,9);
	ld	de, #0x0000
	push	de
	ld	a, #0x09
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, #0x07
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$200$2_1$224	= .
	.globl	C$StateGame.c$200$2_1$224
;StateGame.c:200: UPDATE_HUD_TILE(7,1,10);
	ld	de, #0x0000
	push	de
	ld	a, #0x0a
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, #0x07
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$201$2_1$224	= .
	.globl	C$StateGame.c$201$2_1$224
;StateGame.c:201: UPDATE_HUD_TILE(8,0,11);
	ld	de, #0x0000
	push	de
	ld	a, #0x0b
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, #0x08
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$202$2_1$224	= .
	.globl	C$StateGame.c$202$2_1$224
;StateGame.c:202: UPDATE_HUD_TILE(8,1,12);
	ld	de, #0x0000
	push	de
	ld	a, #0x0c
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, #0x08
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$204$2_1$224	= .
	.globl	C$StateGame.c$204$2_1$224
;StateGame.c:204: UPDATE_HUD_TILE(9,0,17);
	ld	de, #0x0000
	push	de
	ld	a, #0x11
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, #0x09
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$205$2_1$224	= .
	.globl	C$StateGame.c$205$2_1$224
;StateGame.c:205: UPDATE_HUD_TILE(9,1,18);
	ld	de, #0x0000
	push	de
	ld	a, #0x12
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, #0x09
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$206$2_1$224	= .
	.globl	C$StateGame.c$206$2_1$224
;StateGame.c:206: UPDATE_HUD_TILE(10,0,19);
	ld	de, #0x0000
	push	de
	ld	a, #0x13
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, #0x0a
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$207$2_1$224	= .
	.globl	C$StateGame.c$207$2_1$224
;StateGame.c:207: UPDATE_HUD_TILE(10,1,20);
	ld	de, #0x0000
	push	de
	ld	a, #0x14
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, #0x0a
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$209$2_1$224	= .
	.globl	C$StateGame.c$209$2_1$224
;StateGame.c:209: UPDATE_HUD_TILE(11,0,48);
	ld	de, #0x0000
	push	de
	ld	a, #0x30
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, #0x0b
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$210$2_1$224	= .
	.globl	C$StateGame.c$210$2_1$224
;StateGame.c:210: UPDATE_HUD_TILE(11,1,49);
	ld	de, #0x0000
	push	de
	ld	a, #0x31
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, #0x0b
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$211$2_1$224	= .
	.globl	C$StateGame.c$211$2_1$224
;StateGame.c:211: UPDATE_HUD_TILE(12,0,50);
	ld	de, #0x0000
	push	de
	ld	a, #0x32
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, #0x0c
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$212$2_1$224	= .
	.globl	C$StateGame.c$212$2_1$224
;StateGame.c:212: UPDATE_HUD_TILE(12,1,51);
	ld	de, #0x0000
	push	de
	ld	a, #0x33
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, #0x0c
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$214$1_1$219	= .
	.globl	C$StateGame.c$214$1_1$219
;StateGame.c:214: }
00108$:
	C$StateGame.c$216$1_1$219	= .
	.globl	C$StateGame.c$216$1_1$219
;StateGame.c:216: if(countdown < orpheus_power_max){
	ld	hl, #_orpheus_power_max
	ld	e, (hl)
	ld	a, (#_countdown)
	ld	d,a
	ld	hl, #_orpheus_power_max
	sub	a, (hl)
	bit	7, e
	jr	Z, 00233$
	bit	7, d
	jr	NZ, 00234$
	cp	a, a
	jr	00234$
00233$:
	bit	7, d
	jr	Z, 00234$
	scf
00234$:
	jp	NC, 00110$
	C$StateGame.c$217$2_1$225	= .
	.globl	C$StateGame.c$217$2_1$225
;StateGame.c:217: UPDATE_HUD_TILE(14,0,45);
	ld	de, #0x0000
	push	de
	ld	a, #0x2d
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, #0x0e
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$218$2_1$225	= .
	.globl	C$StateGame.c$218$2_1$225
;StateGame.c:218: UPDATE_HUD_TILE(14,1,46);
	ld	de, #0x0000
	push	de
	ld	a, #0x2e
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, #0x0e
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$219$2_1$225	= .
	.globl	C$StateGame.c$219$2_1$225
;StateGame.c:219: UPDATE_HUD_TILE(15,0,45);
	ld	de, #0x0000
	push	de
	ld	a, #0x2d
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, #0x0f
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$220$2_1$225	= .
	.globl	C$StateGame.c$220$2_1$225
;StateGame.c:220: UPDATE_HUD_TILE(15,1,46);
	ld	de, #0x0000
	push	de
	ld	a, #0x2e
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, #0x0f
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$221$2_1$225	= .
	.globl	C$StateGame.c$221$2_1$225
;StateGame.c:221: UPDATE_HUD_TILE(16,0,45);
	ld	de, #0x0000
	push	de
	ld	a, #0x2d
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, #0x10
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$222$2_1$225	= .
	.globl	C$StateGame.c$222$2_1$225
;StateGame.c:222: UPDATE_HUD_TILE(16,1,46);
	ld	de, #0x0000
	push	de
	ld	a, #0x2e
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, #0x10
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$223$2_1$225	= .
	.globl	C$StateGame.c$223$2_1$225
;StateGame.c:223: UPDATE_HUD_TILE(17,0,45);
	ld	de, #0x0000
	push	de
	ld	a, #0x2d
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, #0x11
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$224$2_1$225	= .
	.globl	C$StateGame.c$224$2_1$225
;StateGame.c:224: UPDATE_HUD_TILE(17,1,46);
	ld	de, #0x0000
	push	de
	ld	a, #0x2e
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, #0x11
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$225$2_1$225	= .
	.globl	C$StateGame.c$225$2_1$225
;StateGame.c:225: UPDATE_HUD_TILE(18,0,45);
	ld	de, #0x0000
	push	de
	ld	a, #0x2d
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	push	af
	inc	sp
	ld	e, #0x12
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$226$2_1$225	= .
	.globl	C$StateGame.c$226$2_1$225
;StateGame.c:226: UPDATE_HUD_TILE(18,1,46);
	ld	de, #0x0000
	push	de
	ld	a, #0x2e
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	e, #0x12
	ld	a, #0x01
	call	_UpdateMapTile
00110$:
	C$StateGame.c$231$1_2$226	= .
	.globl	C$StateGame.c$231$1_2$226
;StateGame.c:231: UINT8 countdown_unita = countdown >> 3;
	ld	a, (#_countdown)
	sra	a
	sra	a
	sra	a
	ldhl	sp,	#0
	ld	(hl), a
	C$StateGame.c$233$1_2$226	= .
	.globl	C$StateGame.c$233$1_2$226
;StateGame.c:233: if(countdown < 8){
	ld	hl, #_countdown
	ld	a, (hl)
	xor	a, #0x80
	sub	a, #0x88
	jr	NC, 00112$
	C$StateGame.c$234$2_2$227	= .
	.globl	C$StateGame.c$234$2_2$227
;StateGame.c:234: resto = countdown;
	ld	a, (hl)
	jr	00113$
00112$:
	C$StateGame.c$236$2_2$228	= .
	.globl	C$StateGame.c$236$2_2$228
;StateGame.c:236: resto = countdown%8;
	ld	a, (#_countdown)
	ld	e, a
	rlca
	sbc	a, a
	ld	d, a
	ld	bc, #0x0008
	call	__modsint
	ld	a, c
00113$:
	C$StateGame.c$239$1_2$218	= .
	.globl	C$StateGame.c$239$1_2$218
;StateGame.c:239: fill_bar_idx(0, resto << 1);
	add	a, a
	ldhl	sp,	#1
	C$StateGame.c$238$1_2$226	= .
	.globl	C$StateGame.c$238$1_2$226
;StateGame.c:238: if(countdown_unita < 1){
	ld	(hl-), a
	ld	a, (hl)
	sub	a, #0x01
	jr	NC, 00127$
	C$StateGame.c$239$2_2$229	= .
	.globl	C$StateGame.c$239$2_2$229
;StateGame.c:239: fill_bar_idx(0, resto << 1);
	inc	hl
	ld	e, (hl)
	xor	a, a
	inc	sp
	inc	sp
	jp	_fill_bar_idx
	jp	00132$
00127$:
	C$StateGame.c$240$1_2$226	= .
	.globl	C$StateGame.c$240$1_2$226
;StateGame.c:240: }else if(countdown_unita < 2){
	ldhl	sp,	#0
	ld	a, (hl)
	sub	a, #0x02
	jr	NC, 00124$
	C$StateGame.c$241$2_2$230	= .
	.globl	C$StateGame.c$241$2_2$230
;StateGame.c:241: fill_bar_idx(0, 16);
	ld	e, #0x10
	xor	a, a
	call	_fill_bar_idx
	C$StateGame.c$242$2_2$230	= .
	.globl	C$StateGame.c$242$2_2$230
;StateGame.c:242: fill_bar_idx(1, resto << 1);
	ldhl	sp,	#1
	ld	e, (hl)
	ld	a, #0x01
	inc	sp
	inc	sp
	jp	_fill_bar_idx
	jp	00132$
00124$:
	C$StateGame.c$243$1_2$226	= .
	.globl	C$StateGame.c$243$1_2$226
;StateGame.c:243: }else if(countdown_unita < 3){
	ldhl	sp,	#0
	ld	a, (hl)
	sub	a, #0x03
	jr	NC, 00121$
	C$StateGame.c$244$2_2$231	= .
	.globl	C$StateGame.c$244$2_2$231
;StateGame.c:244: fill_bar_idx(0, 16);
	ld	e, #0x10
	xor	a, a
	call	_fill_bar_idx
	C$StateGame.c$245$2_2$231	= .
	.globl	C$StateGame.c$245$2_2$231
;StateGame.c:245: fill_bar_idx(1, 16);
	ld	e, #0x10
	ld	a, #0x01
	call	_fill_bar_idx
	C$StateGame.c$246$2_2$231	= .
	.globl	C$StateGame.c$246$2_2$231
;StateGame.c:246: fill_bar_idx(2, resto << 1);
	ldhl	sp,	#1
	ld	e, (hl)
	ld	a, #0x02
	inc	sp
	inc	sp
	jp	_fill_bar_idx
	jr	00132$
00121$:
	C$StateGame.c$247$1_2$226	= .
	.globl	C$StateGame.c$247$1_2$226
;StateGame.c:247: }else if(countdown_unita < 4){
	ldhl	sp,	#0
	ld	a, (hl)
	sub	a, #0x04
	jr	NC, 00118$
	C$StateGame.c$248$2_2$232	= .
	.globl	C$StateGame.c$248$2_2$232
;StateGame.c:248: fill_bar_idx(0, 16);
	ld	e, #0x10
	xor	a, a
	call	_fill_bar_idx
	C$StateGame.c$249$2_2$232	= .
	.globl	C$StateGame.c$249$2_2$232
;StateGame.c:249: fill_bar_idx(1, 16);
	ld	e, #0x10
	ld	a, #0x01
	call	_fill_bar_idx
	C$StateGame.c$250$2_2$232	= .
	.globl	C$StateGame.c$250$2_2$232
;StateGame.c:250: fill_bar_idx(2, 16);
	ld	e, #0x10
	ld	a, #0x02
	call	_fill_bar_idx
	C$StateGame.c$251$2_2$232	= .
	.globl	C$StateGame.c$251$2_2$232
;StateGame.c:251: fill_bar_idx(3, resto << 1);
	ldhl	sp,	#1
	ld	e, (hl)
	ld	a, #0x03
	inc	sp
	inc	sp
	jp	_fill_bar_idx
	jr	00132$
00118$:
	C$StateGame.c$252$1_2$226	= .
	.globl	C$StateGame.c$252$1_2$226
;StateGame.c:252: }else if(countdown_unita < 5){
	ldhl	sp,	#0
	ld	a, (hl)
	sub	a, #0x05
	jr	NC, 00115$
	C$StateGame.c$253$2_2$233	= .
	.globl	C$StateGame.c$253$2_2$233
;StateGame.c:253: fill_bar_idx(0, 16);
	ld	e, #0x10
	xor	a, a
	call	_fill_bar_idx
	C$StateGame.c$254$2_2$233	= .
	.globl	C$StateGame.c$254$2_2$233
;StateGame.c:254: fill_bar_idx(1, 16);
	ld	e, #0x10
	ld	a, #0x01
	call	_fill_bar_idx
	C$StateGame.c$255$2_2$233	= .
	.globl	C$StateGame.c$255$2_2$233
;StateGame.c:255: fill_bar_idx(2, 16);
	ld	e, #0x10
	ld	a, #0x02
	call	_fill_bar_idx
	C$StateGame.c$256$2_2$233	= .
	.globl	C$StateGame.c$256$2_2$233
;StateGame.c:256: fill_bar_idx(3, 16);
	ld	e, #0x10
	ld	a, #0x03
	call	_fill_bar_idx
	C$StateGame.c$257$2_2$233	= .
	.globl	C$StateGame.c$257$2_2$233
;StateGame.c:257: fill_bar_idx(4, resto << 1);
	ldhl	sp,	#1
	ld	e, (hl)
	ld	a, #0x04
	inc	sp
	inc	sp
	jp	_fill_bar_idx
	jr	00132$
00115$:
	C$StateGame.c$259$2_2$234	= .
	.globl	C$StateGame.c$259$2_2$234
;StateGame.c:259: fill_bar_idx(0, 16);
	ld	e, #0x10
	xor	a, a
	call	_fill_bar_idx
	C$StateGame.c$260$2_2$234	= .
	.globl	C$StateGame.c$260$2_2$234
;StateGame.c:260: fill_bar_idx(1, 16);
	ld	e, #0x10
	ld	a, #0x01
	call	_fill_bar_idx
	C$StateGame.c$261$2_2$234	= .
	.globl	C$StateGame.c$261$2_2$234
;StateGame.c:261: fill_bar_idx(2, 16);
	ld	e, #0x10
	ld	a, #0x02
	call	_fill_bar_idx
	C$StateGame.c$262$2_2$234	= .
	.globl	C$StateGame.c$262$2_2$234
;StateGame.c:262: fill_bar_idx(3, 16);
	ld	e, #0x10
	ld	a, #0x03
	call	_fill_bar_idx
	C$StateGame.c$263$2_2$234	= .
	.globl	C$StateGame.c$263$2_2$234
;StateGame.c:263: fill_bar_idx(4, 16);
	ld	e, #0x10
	ld	a, #0x04
	inc	sp
	inc	sp
	jp	_fill_bar_idx
00132$:
	C$StateGame.c$265$1_2$218	= .
	.globl	C$StateGame.c$265$1_2$218
;StateGame.c:265: }
	inc	sp
	inc	sp
	C$StateGame.c$265$1_2$218	= .
	.globl	C$StateGame.c$265$1_2$218
	XG$UpdateHUD$0$0	= .
	.globl	XG$UpdateHUD$0$0
	ret
	G$fill_bar_idx$0$0	= .
	.globl	G$fill_bar_idx$0$0
	C$StateGame.c$267$1_2$236	= .
	.globl	C$StateGame.c$267$1_2$236
;StateGame.c:267: void fill_bar_idx(UINT8 i, UINT8 r){
;	---------------------------------
; Function fill_bar_idx
; ---------------------------------
_fill_bar_idx::
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	C$StateGame.c$268$1_0$236	= .
	.globl	C$StateGame.c$268$1_0$236
;StateGame.c:268: UPDATE_HUD_TILE(14+i,0,45-r);
	ld	d, e
	ld	a, #0x2d
	sub	a, d
	ld	c, a
	ld	a, l
	add	a, #0x0e
	ld	e, a
	push	de
	ld	hl, #0x0000
	push	hl
	ld	a, c
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	push	bc
	xor	a, a
	push	af
	inc	sp
	ld	a, #0x01
	call	_UpdateMapTile
	pop	de
	C$StateGame.c$269$1_0$236	= .
	.globl	C$StateGame.c$269$1_0$236
;StateGame.c:269: UPDATE_HUD_TILE(14+i,1,46-r);
	ld	a, #0x2e
	sub	a, d
	ld	bc, #0x0000
	push	bc
	push	af
	inc	sp
	ld	hl, #_hud_map_offset
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	push	bc
	ld	a, #0x01
	push	af
	inc	sp
	ld	a, #0x01
	call	_UpdateMapTile
	C$StateGame.c$270$1_0$236	= .
	.globl	C$StateGame.c$270$1_0$236
;StateGame.c:270: }
	C$StateGame.c$270$1_0$236	= .
	.globl	C$StateGame.c$270$1_0$236
	XG$fill_bar_idx$0$0	= .
	.globl	XG$fill_bar_idx$0$0
	ret
	.area _CODE_255
	.area _INITIALIZER
FStateGame$__xinit_update_hud$0_0$0 == .
__xinit__update_hud:
	.db #0x00	; 0
FStateGame$__xinit_move_camera_up$0_0$0 == .
__xinit__move_camera_up:
	.db #0x00	; 0
FStateGame$__xinit_move_camera_down$0_0$0 == .
__xinit__move_camera_down:
	.db #0x00	; 0
FStateGame$__xinit_move_camera_left$0_0$0 == .
__xinit__move_camera_left:
	.db #0x00	; 0
FStateGame$__xinit_move_camera_right$0_0$0 == .
__xinit__move_camera_right:
	.db #0x00	; 0
FStateGame$__xinit_move_camera_desty$0_0$0 == .
__xinit__move_camera_desty:
	.dw #0x0000
FStateGame$__xinit_move_camera_destx$0_0$0 == .
__xinit__move_camera_destx:
	.dw #0x0000
	.area _CABS (ABS)
