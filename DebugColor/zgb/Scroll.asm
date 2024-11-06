;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module Scroll
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _ScrollUpdateColumnWithDelay
	.globl _ScrollUpdateColumnR
	.globl _ScrollUpdateRowWithDelay
	.globl _ScrollUpdateRowR
	.globl _ClampScrollLimits
	.globl _UPDATE_TILE
	.globl _SetTile
	.globl _GetTileReplacement
	.globl _memcmp
	.globl _memset
	.globl _SetPalette
	.globl _PopBank
	.globl _PushBank
	.globl _SpriteManagerAdd
	.globl _set_win_tile_xy
	.globl _set_bkg_tile_xy
	.globl _set_bkg_data
	.globl _clamp_enabled
	.globl _scroll_h_border
	.globl _last_bg_pal_loaded
	.globl _last_tile_loaded
	.globl _pending_w_cmap
	.globl _pending_h_cmap
	.globl _pending_w_map
	.globl _pending_h_map
	.globl _scroll_offset_y
	.globl _scroll_offset_x
	.globl _scroll_target
	.globl _scroll_y_vblank
	.globl _scroll_x_vblank
	.globl _scroll_y
	.globl _scroll_x
	.globl _scroll_cmap
	.globl _scroll_map
	.globl _scroll_bottom_movement_limit
	.globl _scroll_top_movement_limit
	.globl _current_vbl_count
	.globl _tiles_0
	.globl _tiles_bank_0
	.globl _hud_map_offset
	.globl _pending_w_i
	.globl _pending_w_y
	.globl _pending_w_x
	.globl _pending_h_i
	.globl _pending_h_y
	.globl _pending_h_x
	.globl _scroll_bank
	.globl _scroll_tile_info
	.globl _scroll_collisions_down
	.globl _scroll_collisions
	.globl _scroll_tiles_h
	.globl _scroll_tiles_w
	.globl _scroll_h
	.globl _scroll_w
	.globl _ScrollSetTiles
	.globl _UpdateMapTile
	.globl _LoadMap
	.globl _ScrollSetMap
	.globl _InitScroll
	.globl _InitScrollWithTiles
	.globl _ScrollUpdateRow
	.globl _ScrollUpdateColumn
	.globl _RefreshScroll
	.globl _MoveScroll
	.globl _GetScrollTilePtr
	.globl _GetScrollTile
	.globl _GetMapSize
	.globl _ScrollFindTile
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
G$scroll_w$0_0$0==.
_scroll_w::
	.ds 2
G$scroll_h$0_0$0==.
_scroll_h::
	.ds 2
G$scroll_tiles_w$0_0$0==.
_scroll_tiles_w::
	.ds 2
G$scroll_tiles_h$0_0$0==.
_scroll_tiles_h::
	.ds 2
G$scroll_collisions$0_0$0==.
_scroll_collisions::
	.ds 256
G$scroll_collisions_down$0_0$0==.
_scroll_collisions_down::
	.ds 256
G$scroll_tile_info$0_0$0==.
_scroll_tile_info::
	.ds 256
G$scroll_bank$0_0$0==.
_scroll_bank::
	.ds 1
G$pending_h_x$0_0$0==.
_pending_h_x::
	.ds 2
G$pending_h_y$0_0$0==.
_pending_h_y::
	.ds 2
G$pending_h_i$0_0$0==.
_pending_h_i::
	.ds 1
G$pending_w_x$0_0$0==.
_pending_w_x::
	.ds 2
G$pending_w_y$0_0$0==.
_pending_w_y::
	.ds 2
G$pending_w_i$0_0$0==.
_pending_w_i::
	.ds 1
G$hud_map_offset$0_0$0==.
_hud_map_offset::
	.ds 2
G$tiles_bank_0$0_0$0==.
_tiles_bank_0::
	.ds 1
G$tiles_0$0_0$0==.
_tiles_0::
	.ds 2
G$current_vbl_count$0_0$0==.
_current_vbl_count::
	.ds 1
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
G$scroll_top_movement_limit$0_0$0==.
_scroll_top_movement_limit::
	.ds 1
G$scroll_bottom_movement_limit$0_0$0==.
_scroll_bottom_movement_limit::
	.ds 1
G$scroll_map$0_0$0==.
_scroll_map::
	.ds 2
G$scroll_cmap$0_0$0==.
_scroll_cmap::
	.ds 2
G$scroll_x$0_0$0==.
_scroll_x::
	.ds 2
G$scroll_y$0_0$0==.
_scroll_y::
	.ds 2
G$scroll_x_vblank$0_0$0==.
_scroll_x_vblank::
	.ds 1
G$scroll_y_vblank$0_0$0==.
_scroll_y_vblank::
	.ds 1
G$scroll_target$0_0$0==.
_scroll_target::
	.ds 2
G$scroll_offset_x$0_0$0==.
_scroll_offset_x::
	.ds 1
G$scroll_offset_y$0_0$0==.
_scroll_offset_y::
	.ds 1
G$pending_h_map$0_0$0==.
_pending_h_map::
	.ds 2
G$pending_w_map$0_0$0==.
_pending_w_map::
	.ds 2
G$pending_h_cmap$0_0$0==.
_pending_h_cmap::
	.ds 2
G$pending_w_cmap$0_0$0==.
_pending_w_cmap::
	.ds 2
G$last_tile_loaded$0_0$0==.
_last_tile_loaded::
	.ds 1
G$last_bg_pal_loaded$0_0$0==.
_last_bg_pal_loaded::
	.ds 1
G$scroll_h_border$0_0$0==.
_scroll_h_border::
	.ds 1
G$clamp_enabled$0_0$0==.
_clamp_enabled::
	.ds 1
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
	.area _CODE
	G$SetTile$0$0	= .
	.globl	G$SetTile$0$0
	C$Scroll.c$66$0_0$194	= .
	.globl	C$Scroll.c$66$0_0$194
;C:/ZGB-2023.0/common/src/Scroll.c:66: void SetTile(UINT16 r, UINT8 t) OLDCALL{
;	---------------------------------
; Function SetTile
; ---------------------------------
_SetTile::
	C$Scroll.c$88$1_0$194	= .
	.globl	C$Scroll.c$88$1_0$194
;C:/ZGB-2023.0/common/src/Scroll.c:88: __endasm;
;bc	= r, hl = t
	ldhl	sp,#2
	ld	c,(hl)
	inc	hl
	ld	b,(hl)
	ldhl	sp,#4
;while	0xff41 & 02 != 0 (cannot write)
1$:
	ld	a,(#_STAT_REG)
	and	a, #0x02
	jr	NZ,1$
;Write	tile
	ld	a,(hl)
	ld	(bc),a
	ret
	C$Scroll.c$89$1_0$194	= .
	.globl	C$Scroll.c$89$1_0$194
;C:/ZGB-2023.0/common/src/Scroll.c:89: }
	C$Scroll.c$89$1_0$194	= .
	.globl	C$Scroll.c$89$1_0$194
	XG$SetTile$0$0	= .
	.globl	XG$SetTile$0$0
	ret
	G$UPDATE_TILE$0$0	= .
	.globl	G$UPDATE_TILE$0$0
	C$Scroll.c$91$1_0$196	= .
	.globl	C$Scroll.c$91$1_0$196
;C:/ZGB-2023.0/common/src/Scroll.c:91: void UPDATE_TILE(INT16 x, INT16 y, UINT8* t, UINT8* c) {
;	---------------------------------
; Function UPDATE_TILE
; ---------------------------------
_UPDATE_TILE::
	add	sp, #-10
	ldhl	sp,	#7
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
	ldhl	sp,	#5
	ld	a, c
	ld	(hl+), a
	C$Scroll.c$100$1_0$196	= .
	.globl	C$Scroll.c$100$1_0$196
;C:/ZGB-2023.0/common/src/Scroll.c:100: if((UINT16)x >= scroll_tiles_w || (UINT16)y >= scroll_tiles_h) { //This also checks x < 0 || y < 0
	ld	a, b
	ld	(hl+), a
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #_scroll_tiles_w
	ld	a, c
	sub	a, (hl)
	inc	hl
	ld	a, b
	sbc	a, (hl)
	jr	NC, 00109$
	ldhl	sp,	#5
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #_scroll_tiles_h
	ld	a, c
	sub	a, (hl)
	inc	hl
	ld	a, b
	sbc	a, (hl)
	jr	C, 00110$
00109$:
	C$Scroll.c$101$2_0$197	= .
	.globl	C$Scroll.c$101$2_0$197
;C:/ZGB-2023.0/common/src/Scroll.c:101: replacement = 0;
	ldhl	sp,	#0
	ld	(hl), #0x00
	jp	00111$
00110$:
	C$Scroll.c$103$2_0$198	= .
	.globl	C$Scroll.c$103$2_0$198
;C:/ZGB-2023.0/common/src/Scroll.c:103: replacement = *t;
	ldhl	sp,	#12
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	C$Scroll.c$104$2_0$198	= .
	.globl	C$Scroll.c$104$2_0$198
;C:/ZGB-2023.0/common/src/Scroll.c:104: type = GetTileReplacement(t, &replacement);
	ldhl	sp,#0
	ld	(hl), a
	ld	c, l
	ld	b, h
	call	_GetTileReplacement
	C$Scroll.c$105$2_0$198	= .
	.globl	C$Scroll.c$105$2_0$198
;C:/ZGB-2023.0/common/src/Scroll.c:105: if(type != 255u) {
	ldhl	sp,#1
	ld	(hl), a
	ld	a, (hl)
	inc	a
	jp	Z,00111$
	C$Scroll.c$106$3_0$199	= .
	.globl	C$Scroll.c$106$3_0$199
;C:/ZGB-2023.0/common/src/Scroll.c:106: id = SPRITE_UNIQUE_ID(x, y);
	ldhl	sp,	#7
	ld	a, (hl-)
	dec	hl
	ld	c, a
	ld	d, (hl)
	ldhl	sp,	#2
	ld	a, c
	ld	(hl+), a
	ld	(hl), d
	C$Scroll.c$107$5_0$201	= .
	.globl	C$Scroll.c$107$5_0$201
;C:/ZGB-2023.0/common/src/Scroll.c:107: for(i = 0u; i != sprite_manager_updatables[0]; ++i) {
	ldhl	sp,	#9
	ld	(hl), #0x00
00118$:
	ld	a, (#_sprite_manager_updatables + 0)
	ldhl	sp,	#4
	ld	(hl), a
	ldhl	sp,	#9
	ld	a, (hl)
	ldhl	sp,	#4
	sub	a, (hl)
	ld	a, #0x01
	jr	Z, 00181$
	xor	a, a
00181$:
	ldhl	sp,	#4
	ld	(hl), a
	bit	0, (hl)
	jr	NZ, 00104$
	C$Scroll.c$108$5_0$201	= .
	.globl	C$Scroll.c$108$5_0$201
;C:/ZGB-2023.0/common/src/Scroll.c:108: s = sprite_manager_sprites[sprite_manager_updatables[i + 1]];
	ldhl	sp,	#9
	ld	c, (hl)
	ld	b, #0x00
	inc	bc
	ld	hl, #_sprite_manager_updatables
	add	hl, bc
	ld	l, (hl)
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	ld	de, #_sprite_manager_sprites
	add	hl, de
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	C$Scroll.c$109$5_0$201	= .
	.globl	C$Scroll.c$109$5_0$201
;C:/ZGB-2023.0/common/src/Scroll.c:109: if((s->type == type) && (s->unique_id == id)) {
	ld	hl, #0x0013
	add	hl, bc
	ld	e, (hl)
	ldhl	sp,	#1
	ld	a, (hl)
	sub	a, e
	jr	NZ, 00119$
	ld	hl, #0x0019
	add	hl, bc
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ldhl	sp,	#2
	ld	a, (hl)
	sub	a, c
	jr	NZ, 00184$
	inc	hl
	ld	a, (hl)
	sub	a, b
	jr	Z, 00104$
00184$:
	C$Scroll.c$110$5_0$201	= .
	.globl	C$Scroll.c$110$5_0$201
;C:/ZGB-2023.0/common/src/Scroll.c:110: break;
00119$:
	C$Scroll.c$107$4_0$200	= .
	.globl	C$Scroll.c$107$4_0$200
;C:/ZGB-2023.0/common/src/Scroll.c:107: for(i = 0u; i != sprite_manager_updatables[0]; ++i) {
	ldhl	sp,	#9
	inc	(hl)
	jr	00118$
00104$:
	C$Scroll.c$114$3_0$199	= .
	.globl	C$Scroll.c$114$3_0$199
;C:/ZGB-2023.0/common/src/Scroll.c:114: if(i == sprite_manager_updatables[0]) {
	ldhl	sp,	#4
	ld	a, (hl)
	or	a, a
	jr	Z, 00111$
	C$Scroll.c$115$4_0$203	= .
	.globl	C$Scroll.c$115$4_0$203
;C:/ZGB-2023.0/common/src/Scroll.c:115: PUSH_BANK(spriteDataBanks[type]);
	ld	de, #_spriteDataBanks
	ldhl	sp,	#1
	ld	l, (hl)
	ld	h, #0x00
	add	hl, de
	ld	c, l
	ld	b, h
	ld	a, (bc)
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	C$Scroll.c$116$4_0$203	= .
	.globl	C$Scroll.c$116$4_0$203
;C:/ZGB-2023.0/common/src/Scroll.c:116: sprite_y = ((y + 1) << 3) - spriteDatas[type]->height;
	ldhl	sp,	#5
	ld	a, (hl+)
	ld	h, (hl)
;	spillPairReg hl
;	spillPairReg hl
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	inc	hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	c, l
	ld	b, h
	ldhl	sp,	#1
	ld	l, (hl)
	ld	h, #0x00
	add	hl, hl
	ld	de, #_spriteDatas
	add	hl, de
	ld	a, (hl+)
	ld	h, (hl)
;	spillPairReg hl
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	inc	hl
	ld	e, (hl)
	ld	d, #0x00
	ld	a, c
	sub	a, e
	ld	c, a
	ld	a, b
	sbc	a, d
	ld	b, a
	C$Scroll.c$117$4_0$203	= .
	.globl	C$Scroll.c$117$4_0$203
;C:/ZGB-2023.0/common/src/Scroll.c:117: POP_BANK;
	push	bc
	call	_PopBank
	pop	bc
	C$Scroll.c$118$4_0$203	= .
	.globl	C$Scroll.c$118$4_0$203
;C:/ZGB-2023.0/common/src/Scroll.c:118: s = SpriteManagerAdd(type, x << 3, sprite_y);
	ldhl	sp,#7
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	sla	e
	rl	d
	sla	e
	rl	d
	sla	e
	rl	d
	push	bc
	ldhl	sp,	#3
	ld	a, (hl)
	call	_SpriteManagerAdd
00111$:
	C$Scroll.c$123$1_0$196	= .
	.globl	C$Scroll.c$123$1_0$196
;C:/ZGB-2023.0/common/src/Scroll.c:123: id = 0x9800 + (0x1F & (x + scroll_offset_x)) + ((0x1F & (y + scroll_offset_y)) << 5);
	ld	hl, #_scroll_offset_x
	ld	c, (hl)
	ld	b, #0x00
	ldhl	sp,	#7
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	ld	a, l
	and	a, #0x1f
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
;	spillPairReg hl
;	spillPairReg hl
	ld	c, a
	ld	a, h
	add	a, #0x98
	ld	b, a
	ld	hl, #_scroll_offset_y
	ld	e, (hl)
	ld	d, #0x00
	ldhl	sp,	#5
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, de
	ld	a, l
	and	a, #0x1f
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	ld	l, a
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, bc
	ld	c, l
	ld	b, h
	C$Scroll.c$124$1_0$196	= .
	.globl	C$Scroll.c$124$1_0$196
;C:/ZGB-2023.0/common/src/Scroll.c:124: SetTile(id, replacement);
	ldhl	sp,	#0
	ld	a, (hl)
	push	af
	inc	sp
	push	bc
	call	_SetTile
	add	sp, #3
	C$Scroll.c$128$1_0$196	= .
	.globl	C$Scroll.c$128$1_0$196
;C:/ZGB-2023.0/common/src/Scroll.c:128: if (_cpu == CGB_TYPE) {
	ld	a, (#__cpu)
	sub	a, #0x11
	jr	NZ, 00120$
	C$Scroll.c$129$2_0$204	= .
	.globl	C$Scroll.c$129$2_0$204
;C:/ZGB-2023.0/common/src/Scroll.c:129: VBK_REG = 1;
	ld	a, #0x01
	ldh	(_VBK_REG + 0), a
	C$Scroll.c$130$2_0$204	= .
	.globl	C$Scroll.c$130$2_0$204
;C:/ZGB-2023.0/common/src/Scroll.c:130: if(!scroll_cmap) {
	ld	hl, #_scroll_cmap + 1
	ld	a, (hl-)
	or	a, (hl)
	jr	NZ, 00114$
	C$Scroll.c$131$3_0$205	= .
	.globl	C$Scroll.c$131$3_0$205
;C:/ZGB-2023.0/common/src/Scroll.c:131: c = &scroll_tile_info[replacement];
	ld	bc, #_scroll_tile_info+0
	ldhl	sp,	#0
	ld	l, (hl)
	ld	h, #0x00
	add	hl, bc
	ld	c, l
	ld	a, h
	ldhl	sp,	#14
	ld	(hl), c
	inc	hl
	ld	(hl), a
00114$:
	C$Scroll.c$133$2_0$204	= .
	.globl	C$Scroll.c$133$2_0$204
;C:/ZGB-2023.0/common/src/Scroll.c:133: set_bkg_tile_xy(0x1F & (x + scroll_offset_x), 0x1F & (y + scroll_offset_y), *c);
	ldhl	sp,	#14
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	a, (bc)
	ld	c, a
	ldhl	sp,	#5
	ld	a, (hl)
	ld	hl, #_scroll_offset_y
	ld	b, (hl)
	add	a, b
	and	a, #0x1f
	ld	e, a
	ldhl	sp,	#7
	ld	a, (hl)
	ld	hl, #_scroll_offset_x
	ld	b, (hl)
	add	a, b
	and	a, #0x1f
	ld	h, c
;	spillPairReg hl
;	spillPairReg hl
	push	hl
	inc	sp
	ld	h, e
;	spillPairReg hl
;	spillPairReg hl
	push	hl
	inc	sp
	push	af
	inc	sp
	call	_set_bkg_tile_xy
	add	sp, #3
	C$Scroll.c$134$2_0$204	= .
	.globl	C$Scroll.c$134$2_0$204
;C:/ZGB-2023.0/common/src/Scroll.c:134: VBK_REG = 0;
	ld	a, #0x00
	ldh	(_VBK_REG + 0), a
00120$:
	C$Scroll.c$137$1_0$196	= .
	.globl	C$Scroll.c$137$1_0$196
;C:/ZGB-2023.0/common/src/Scroll.c:137: }
	add	sp, #10
	pop	hl
	add	sp, #4
	jp	(hl)
	G$ScrollSetTiles$0$0	= .
	.globl	G$ScrollSetTiles$0$0
	C$Scroll.c$140$1_0$207	= .
	.globl	C$Scroll.c$140$1_0$207
;C:/ZGB-2023.0/common/src/Scroll.c:140: UINT16 ScrollSetTiles(UINT8 first_tile, UINT8 tiles_bank, const struct TilesInfo* tiles) {
;	---------------------------------
; Function ScrollSetTiles
; ---------------------------------
_ScrollSetTiles::
	add	sp, #-11
	ldhl	sp,	#9
	ld	(hl-), a
	C$Scroll.c$145$2_0$207	= .
	.globl	C$Scroll.c$145$2_0$207
;C:/ZGB-2023.0/common/src/Scroll.c:145: UINT16 offset = first_tile;
	ld	a, e
	ld	(hl+), a
	ld	a, (hl)
	ldhl	sp,	#0
	ld	(hl+), a
	ld	(hl), #0x00
	C$Scroll.c$150$1_0$207	= .
	.globl	C$Scroll.c$150$1_0$207
;C:/ZGB-2023.0/common/src/Scroll.c:150: tiles_0 = tiles;
	ldhl	sp,	#13
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	C$Scroll.c$147$1_0$207	= .
	.globl	C$Scroll.c$147$1_0$207
;C:/ZGB-2023.0/common/src/Scroll.c:147: if(first_tile == 0)
	ldhl	sp,	#9
	ld	a, (hl)
	or	a, a
	jr	NZ, 00102$
	C$Scroll.c$149$2_0$208	= .
	.globl	C$Scroll.c$149$2_0$208
;C:/ZGB-2023.0/common/src/Scroll.c:149: tiles_bank_0 = tiles_bank;
	dec	hl
	ld	a, (hl)
	ld	(#_tiles_bank_0),a
	C$Scroll.c$150$2_0$208	= .
	.globl	C$Scroll.c$150$2_0$208
;C:/ZGB-2023.0/common/src/Scroll.c:150: tiles_0 = tiles;
	ld	hl, #_tiles_0
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
00102$:
	C$Scroll.c$153$1_0$207	= .
	.globl	C$Scroll.c$153$1_0$207
;C:/ZGB-2023.0/common/src/Scroll.c:153: PUSH_BANK(tiles_bank);
	push	bc
	ldhl	sp,	#10
	ld	a, (hl)
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	pop	bc
	C$Scroll.c$154$1_0$207	= .
	.globl	C$Scroll.c$154$1_0$207
;C:/ZGB-2023.0/common/src/Scroll.c:154: n_tiles = tiles->num_frames;
	ldhl	sp,	#6
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	ld	a, (bc)
	ldhl	sp,	#10
	ld	(hl), a
	C$Scroll.c$155$1_0$207	= .
	.globl	C$Scroll.c$155$1_0$207
;C:/ZGB-2023.0/common/src/Scroll.c:155: palette_entries = tiles->color_data;
	ld	hl, #0x0006
	add	hl, bc
	ld	e, l
	ld	d, h
	ld	a, (de)
	ldhl	sp,	#2
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	C$Scroll.c$157$1_0$207	= .
	.globl	C$Scroll.c$157$1_0$207
;C:/ZGB-2023.0/common/src/Scroll.c:157: set_bkg_data(first_tile, n_tiles, tiles->data);
	ld	l, c
	ld	h, b
	inc	hl
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	push	bc
	ldhl	sp,	#12
	ld	a, (hl-)
	ld	d, a
	ld	e, (hl)
	push	de
	call	_set_bkg_data
	add	sp, #4
	C$Scroll.c$158$1_0$207	= .
	.globl	C$Scroll.c$158$1_0$207
;C:/ZGB-2023.0/common/src/Scroll.c:158: last_tile_loaded = first_tile + n_tiles;
	ldhl	sp,	#9
	ld	a, (hl+)
	add	a, (hl)
	ld	(#_last_tile_loaded),a
	C$Scroll.c$159$3_0$210	= .
	.globl	C$Scroll.c$159$3_0$210
;C:/ZGB-2023.0/common/src/Scroll.c:159: for(i = first_tile; i != last_tile_loaded; ++i) {
	ldhl	sp,	#9
	ld	c, (hl)
00110$:
	ld	a, (#_last_tile_loaded)
	sub	a, c
	jr	Z, 00103$
	C$Scroll.c$160$3_0$210	= .
	.globl	C$Scroll.c$160$3_0$210
;C:/ZGB-2023.0/common/src/Scroll.c:160: scroll_tile_info[i] = palette_entries ? palette_entries[i - first_tile] : 0;
	ld	de, #_scroll_tile_info
	ld	l, c
	ld	h, #0x00
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#6
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#5
	ld	(hl-), a
	dec	hl
	ld	a, (hl-)
	or	a, (hl)
	jr	Z, 00117$
	ld	a, c
	ld	b, #0x00
	ldhl	sp,	#9
	ld	e, (hl)
	ld	d, #0x00
	sub	a, e
	ld	e, a
	ld	a, b
	sbc	a, d
	ld	d, a
	ldhl	sp,	#2
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
	jr	00118$
00117$:
	xor	a, a
00118$:
	ld	b, a
	ldhl	sp,	#4
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	(hl), b
	C$Scroll.c$159$2_0$209	= .
	.globl	C$Scroll.c$159$2_0$209
;C:/ZGB-2023.0/common/src/Scroll.c:159: for(i = first_tile; i != last_tile_loaded; ++i) {
	inc	c
	jr	00110$
00103$:
	C$Scroll.c$165$3_0$212	= .
	.globl	C$Scroll.c$165$3_0$212
;C:/ZGB-2023.0/common/src/Scroll.c:165: for(i = 0; i != last_bg_pal_loaded; ++ i)
	ldhl	sp,#6
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0003
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#4
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#3
	ld	(hl), a
	ldhl	sp,#6
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0004
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#6
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#5
	ld	(hl), a
	ldhl	sp,	#10
	ld	(hl), #0x00
00113$:
	ldhl	sp,	#10
	ld	a, (hl)
	ld	hl, #_last_bg_pal_loaded
	sub	a, (hl)
	jr	Z, 00106$
	C$Scroll.c$167$3_0$212	= .
	.globl	C$Scroll.c$167$3_0$212
;C:/ZGB-2023.0/common/src/Scroll.c:167: if(memcmp(&ZGB_Fading_BPal[i << 2], tiles->pals, tiles->num_pals << 3) == 0)
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ldhl	sp,	#7
	ld	(hl), a
	ld	a, (hl-)
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	ld	c, a
	ld	a, (hl-)
	dec	hl
	dec	hl
	ld	b, a
	sla	c
	rl	b
	sla	c
	rl	b
	sla	c
	rl	b
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	inc	de
	ld	a, (de)
	ld	e, l
	ld	d, a
	ldhl	sp,	#10
	ld	a, (hl)
	add	a, a
	add	a, a
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	rlca
	sbc	a, a
	ld	h, a
	add	hl, hl
	push	de
	ld	de, #_ZGB_Fading_BPal
	add	hl, de
	pop	de
	push	bc
	push	de
	push	hl
	call	_memcmp
	add	sp, #6
	ld	a, d
	or	a, e
	jr	Z, 00106$
	C$Scroll.c$165$2_0$211	= .
	.globl	C$Scroll.c$165$2_0$211
;C:/ZGB-2023.0/common/src/Scroll.c:165: for(i = 0; i != last_bg_pal_loaded; ++ i)
	ldhl	sp,	#10
	inc	(hl)
	jr	00113$
00106$:
	C$Scroll.c$171$1_0$207	= .
	.globl	C$Scroll.c$171$1_0$207
;C:/ZGB-2023.0/common/src/Scroll.c:171: offset |= (i << 8);
	ldhl	sp,	#10
	ld	c, (hl)
	ld	b, #0x00
	ldhl	sp,	#0
	ld	a, (hl)
	or	a, b
	ldhl	sp,	#6
	ld	(hl+), a
	ld	(hl), c
	C$Scroll.c$172$1_0$207	= .
	.globl	C$Scroll.c$172$1_0$207
;C:/ZGB-2023.0/common/src/Scroll.c:172: if(i == last_bg_pal_loaded)
	ld	a, (#_last_bg_pal_loaded)
	ldhl	sp,	#10
	sub	a, (hl)
	jr	NZ, 00108$
	C$Scroll.c$174$2_0$213	= .
	.globl	C$Scroll.c$174$2_0$213
;C:/ZGB-2023.0/common/src/Scroll.c:174: SetPalette(BG_PALETTE, last_bg_pal_loaded, tiles->num_pals, tiles->pals, tiles_bank);
	ldhl	sp,#4
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl-)
	dec	hl
	dec	hl
	ld	d, a
	ld	a, (de)
	ld	c, a
	inc	de
	ld	a, (de)
	ld	b, a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ldhl	sp,	#8
	ld	h, (hl)
;	spillPairReg hl
;	spillPairReg hl
	push	hl
	inc	sp
	push	bc
	push	af
	inc	sp
	ld	hl, #_last_bg_pal_loaded
	ld	e, (hl)
	xor	a, a
	call	_SetPalette
	C$Scroll.c$175$2_0$213	= .
	.globl	C$Scroll.c$175$2_0$213
;C:/ZGB-2023.0/common/src/Scroll.c:175: last_bg_pal_loaded += tiles->num_pals;
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	hl, #_last_bg_pal_loaded
	add	a, (hl)
	ld	(hl), a
00108$:
	C$Scroll.c$179$1_0$207	= .
	.globl	C$Scroll.c$179$1_0$207
;C:/ZGB-2023.0/common/src/Scroll.c:179: POP_BANK;
	call	_PopBank
	C$Scroll.c$181$1_0$207	= .
	.globl	C$Scroll.c$181$1_0$207
;C:/ZGB-2023.0/common/src/Scroll.c:181: return offset;
	ldhl	sp,	#6
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	C$Scroll.c$182$1_0$207	= .
	.globl	C$Scroll.c$182$1_0$207
;C:/ZGB-2023.0/common/src/Scroll.c:182: }
	add	sp, #11
	pop	hl
	pop	af
	jp	(hl)
	G$UpdateMapTile$0$0	= .
	.globl	G$UpdateMapTile$0$0
	C$Scroll.c$184$1_0$215	= .
	.globl	C$Scroll.c$184$1_0$215
;C:/ZGB-2023.0/common/src/Scroll.c:184: void UpdateMapTile(UINT8 bg_or_win, UINT8 x, UINT8 y, UINT16 map_offset, UINT8 data, UINT8* attr)
;	---------------------------------
; Function UpdateMapTile
; ---------------------------------
_UpdateMapTile::
	ld	c, a
	ld	b, e
	C$Scroll.c$187$1_1$216	= .
	.globl	C$Scroll.c$187$1_1$216
;C:/ZGB-2023.0/common/src/Scroll.c:187: UINT8* offsetts = &map_offset;
	C$Scroll.c$188$1_1$216	= .
	.globl	C$Scroll.c$188$1_1$216
;C:/ZGB-2023.0/common/src/Scroll.c:188: data += offsetts[0];
	ldhl	sp,	#3
	ld	a, (hl+)
	inc	hl
	add	a, (hl)
	ld	(hl), a
	C$Scroll.c$189$1_1$216	= .
	.globl	C$Scroll.c$189$1_1$216
;C:/ZGB-2023.0/common/src/Scroll.c:189: if(bg_or_win == 0)
	ld	a, c
	or	a, a
	jr	NZ, 00102$
	C$Scroll.c$190$1_1$216	= .
	.globl	C$Scroll.c$190$1_1$216
;C:/ZGB-2023.0/common/src/Scroll.c:190: set_bkg_tile_xy(x, y, data);
	ld	a, (hl)
	push	af
	inc	sp
	ldhl	sp,	#3
	ld	a, (hl)
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_set_bkg_tile_xy
	add	sp, #3
	jr	00103$
00102$:
	C$Scroll.c$192$1_1$216	= .
	.globl	C$Scroll.c$192$1_1$216
;C:/ZGB-2023.0/common/src/Scroll.c:192: set_win_tile_xy(x, y, data);
	ldhl	sp,	#5
	ld	a, (hl)
	push	af
	inc	sp
	ldhl	sp,	#3
	ld	a, (hl)
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_set_win_tile_xy
	add	sp, #3
00103$:
	C$Scroll.c$195$1_1$216	= .
	.globl	C$Scroll.c$195$1_1$216
;C:/ZGB-2023.0/common/src/Scroll.c:195: if (_cpu == CGB_TYPE) {
	ld	a, (#__cpu)
	sub	a, #0x11
	jr	NZ, 00109$
	C$Scroll.c$196$2_1$217	= .
	.globl	C$Scroll.c$196$2_1$217
;C:/ZGB-2023.0/common/src/Scroll.c:196: VBK_REG = 1;
	ld	a, #0x01
	ldh	(_VBK_REG + 0), a
	C$Scroll.c$198$2_2$218	= .
	.globl	C$Scroll.c$198$2_2$218
;C:/ZGB-2023.0/common/src/Scroll.c:198: UINT8 c = attr ? *attr : scroll_tile_info[data];
	ldhl	sp,	#7
	ld	a, (hl-)
	or	a, (hl)
	jr	Z, 00111$
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	jr	00112$
00111$:
	ld	de, #_scroll_tile_info+0
	ldhl	sp,	#5
	ld	l, (hl)
	ld	h, #0x00
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
00112$:
	C$Scroll.c$199$2_2$218	= .
	.globl	C$Scroll.c$199$2_2$218
;C:/ZGB-2023.0/common/src/Scroll.c:199: c += offsetts[1];
	ld	hl,#0x4
	add	hl,sp
	ld	e, (hl)
	add	a, e
	ld	d, a
	C$Scroll.c$201$2_2$218	= .
	.globl	C$Scroll.c$201$2_2$218
;C:/ZGB-2023.0/common/src/Scroll.c:201: if (bg_or_win == 0)
	ld	a, c
	or	a, a
	jr	NZ, 00105$
	C$Scroll.c$202$2_2$218	= .
	.globl	C$Scroll.c$202$2_2$218
;C:/ZGB-2023.0/common/src/Scroll.c:202: set_bkg_tile_xy(x, y, c);
	push	de
	inc	sp
	ldhl	sp,	#3
	ld	a, (hl)
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_set_bkg_tile_xy
	add	sp, #3
	jr	00106$
00105$:
	C$Scroll.c$204$2_2$218	= .
	.globl	C$Scroll.c$204$2_2$218
;C:/ZGB-2023.0/common/src/Scroll.c:204: set_win_tile_xy(x, y, c);
	push	de
	inc	sp
	ldhl	sp,	#3
	ld	a, (hl)
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_set_win_tile_xy
	add	sp, #3
00106$:
	C$Scroll.c$205$2_2$218	= .
	.globl	C$Scroll.c$205$2_2$218
;C:/ZGB-2023.0/common/src/Scroll.c:205: VBK_REG = 0;
	ld	a, #0x00
	ldh	(_VBK_REG + 0), a
00109$:
	C$Scroll.c$208$1_1$215	= .
	.globl	C$Scroll.c$208$1_1$215
;C:/ZGB-2023.0/common/src/Scroll.c:208: }
	pop	hl
	add	sp, #6
	jp	(hl)
	G$LoadMap$0$0	= .
	.globl	G$LoadMap$0$0
	C$Scroll.c$210$1_1$220	= .
	.globl	C$Scroll.c$210$1_1$220
;C:/ZGB-2023.0/common/src/Scroll.c:210: UINT16 LoadMap(UINT8 bg_or_win, UINT8 x, UINT8 y, UINT8 map_bank, struct MapInfo* map) {
;	---------------------------------
; Function LoadMap
; ---------------------------------
_LoadMap::
	add	sp, #-17
	ldhl	sp,	#10
	ld	(hl-), a
	ld	(hl), e
	C$Scroll.c$211$1_0$220	= .
	.globl	C$Scroll.c$211$1_0$220
;C:/ZGB-2023.0/common/src/Scroll.c:211: PUSH_BANK(map_bank);
	ldhl	sp,	#20
	ld	a, (hl)
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	C$Scroll.c$214$1_1$221	= .
	.globl	C$Scroll.c$214$1_1$221
;C:/ZGB-2023.0/common/src/Scroll.c:214: UINT8 load_tiles = tiles_bank_0 != map->tiles_bank || tiles_0 != map->tiles; //If the tile set is the same as the one used for the scroll or the bg (which is stored in tiles_bank_0 and tiles0) then do not load the tiles again
	ldhl	sp,	#21
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #0x0006
	add	hl, bc
	ld	a, (hl)
	ldhl	sp,	#14
	ld	(hl), a
	ld	hl, #0x0007
	add	hl, bc
	push	hl
	ld	a, l
	ldhl	sp,	#17
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#16
	ld	(hl), a
	ld	a, (#_tiles_bank_0)
	ldhl	sp,	#14
	sub	a, (hl)
	jr	NZ, 00116$
	ldhl	sp,#15
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ldhl	sp,	#12
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	ld	a, (#_tiles_0)
	ldhl	sp,	#12
	sub	a, (hl)
	jr	NZ, 00116$
	ld	a, (#_tiles_0 + 1)
	ldhl	sp,	#13
	sub	a, (hl)
	jr	NZ, 00116$
	xor	a, a
	jr	00117$
00116$:
	ld	a, #0x01
00117$:
	C$Scroll.c$215$1_1$221	= .
	.globl	C$Scroll.c$215$1_1$221
;C:/ZGB-2023.0/common/src/Scroll.c:215: UINT16 map_offset = 0;
	ldhl	sp,	#2
	ld	(hl), #0x00
	inc	hl
	ld	(hl), #0x00
	C$Scroll.c$216$1_1$221	= .
	.globl	C$Scroll.c$216$1_1$221
;C:/ZGB-2023.0/common/src/Scroll.c:216: if(load_tiles)
	or	a, a
	jr	Z, 00102$
	C$Scroll.c$217$1_1$221	= .
	.globl	C$Scroll.c$217$1_1$221
;C:/ZGB-2023.0/common/src/Scroll.c:217: map_offset = ScrollSetTiles(last_tile_loaded, map->tiles_bank, map->tiles);
	ldhl	sp,#15
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
	push	bc
	push	hl
	ldhl	sp,	#18
	ld	e, (hl)
	ld	a, (#_last_tile_loaded)
	call	_ScrollSetTiles
	ldhl	sp,	#4
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	pop	bc
00102$:
	C$Scroll.c$220$1_2$222	= .
	.globl	C$Scroll.c$220$1_2$222
;C:/ZGB-2023.0/common/src/Scroll.c:220: UINT8* data = map->data;
	ld	e, c
	ld	d, b
	ld	a, (de)
	ldhl	sp,	#0
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	C$Scroll.c$221$1_2$222	= .
	.globl	C$Scroll.c$221$1_2$222
;C:/ZGB-2023.0/common/src/Scroll.c:221: UINT8* attrs = map->attributes;
	ld	hl, #0x0004
	add	hl, bc
	ld	e, l
	ld	d, h
	ld	a, (de)
	ldhl	sp,	#12
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	C$Scroll.c$222$4_2$225	= .
	.globl	C$Scroll.c$222$4_2$225
;C:/ZGB-2023.0/common/src/Scroll.c:222: for(UINT8 j = 0; j < map->height; ++j) {
	ld	hl, #0x0002
	add	hl, bc
	push	hl
	ld	a, l
	ldhl	sp,	#6
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#5
	ld	(hl+), a
	inc	bc
	inc	bc
	inc	bc
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	ldhl	sp,	#11
	ld	(hl), #0x00
00111$:
	ldhl	sp,#6
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	c, a
	ldhl	sp,	#11
	ld	a, (hl)
	sub	a, c
	jr	NC, 00106$
	C$Scroll.c$223$5_2$226	= .
	.globl	C$Scroll.c$223$5_2$226
;C:/ZGB-2023.0/common/src/Scroll.c:223: for(UINT8 i = 0; i < map->width; ++i) {
	ldhl	sp,	#19
	ld	a, (hl)
	ldhl	sp,	#11
	add	a, (hl)
	ldhl	sp,	#8
	ld	(hl), a
	ldhl	sp,	#0
	ld	a, (hl)
	ldhl	sp,	#14
	ld	(hl), a
	ldhl	sp,	#1
	ld	a, (hl)
	ldhl	sp,	#15
	ld	(hl+), a
	ld	(hl), #0x00
00108$:
	ldhl	sp,#4
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	c, a
	ldhl	sp,	#16
	ld	a, (hl)
	sub	a, c
	jr	NC, 00126$
	C$Scroll.c$224$5_2$226	= .
	.globl	C$Scroll.c$224$5_2$226
;C:/ZGB-2023.0/common/src/Scroll.c:224: UpdateMapTile(bg_or_win, x + i, y + j, map_offset, *data, attrs);
	dec	hl
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	b, a
	ldhl	sp,	#9
	ld	a, (hl)
	ldhl	sp,	#16
	add	a, (hl)
	ld	c, a
	ldhl	sp,	#12
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	push	bc
	inc	sp
	ldhl	sp,	#5
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ldhl	sp,	#13
	ld	a, (hl+)
	inc	hl
	push	af
	inc	sp
	ld	e, c
	ld	a, (hl)
	call	_UpdateMapTile
	C$Scroll.c$226$5_2$226	= .
	.globl	C$Scroll.c$226$5_2$226
;C:/ZGB-2023.0/common/src/Scroll.c:226: ++ data;
	ldhl	sp,	#14
	inc	(hl)
	jr	NZ, 00180$
	inc	hl
	inc	(hl)
00180$:
	C$Scroll.c$227$5_2$226	= .
	.globl	C$Scroll.c$227$5_2$226
;C:/ZGB-2023.0/common/src/Scroll.c:227: if(attrs)
	ldhl	sp,	#13
	ld	a, (hl-)
	or	a, (hl)
	jr	Z, 00109$
	C$Scroll.c$228$5_2$226	= .
	.globl	C$Scroll.c$228$5_2$226
;C:/ZGB-2023.0/common/src/Scroll.c:228: ++ attrs;
	inc	(hl)
	jr	NZ, 00181$
	inc	hl
	inc	(hl)
00181$:
00109$:
	C$Scroll.c$223$4_2$225	= .
	.globl	C$Scroll.c$223$4_2$225
;C:/ZGB-2023.0/common/src/Scroll.c:223: for(UINT8 i = 0; i < map->width; ++i) {
	ldhl	sp,	#16
	inc	(hl)
	jr	00108$
00126$:
	ldhl	sp,	#14
	ld	a, (hl)
	ldhl	sp,	#0
	ld	(hl), a
	ldhl	sp,	#15
	ld	a, (hl)
	ldhl	sp,	#1
	ld	(hl), a
	C$Scroll.c$222$2_2$223	= .
	.globl	C$Scroll.c$222$2_2$223
;C:/ZGB-2023.0/common/src/Scroll.c:222: for(UINT8 j = 0; j < map->height; ++j) {
	ldhl	sp,	#11
	inc	(hl)
	jp	00111$
00106$:
	C$Scroll.c$232$1_2$222	= .
	.globl	C$Scroll.c$232$1_2$222
;C:/ZGB-2023.0/common/src/Scroll.c:232: POP_BANK;
	call	_PopBank
	C$Scroll.c$235$1_2$222	= .
	.globl	C$Scroll.c$235$1_2$222
;C:/ZGB-2023.0/common/src/Scroll.c:235: return map_offset;
	ldhl	sp,	#2
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	C$Scroll.c$236$1_2$220	= .
	.globl	C$Scroll.c$236$1_2$220
;C:/ZGB-2023.0/common/src/Scroll.c:236: }
	add	sp, #17
	pop	hl
	add	sp, #4
	jp	(hl)
	G$ClampScrollLimits$0$0	= .
	.globl	G$ClampScrollLimits$0$0
	C$Scroll.c$240$1_2$227	= .
	.globl	C$Scroll.c$240$1_2$227
;C:/ZGB-2023.0/common/src/Scroll.c:240: void ClampScrollLimits() {
;	---------------------------------
; Function ClampScrollLimits
; ---------------------------------
_ClampScrollLimits::
	C$Scroll.c$241$1_0$227	= .
	.globl	C$Scroll.c$241$1_0$227
;C:/ZGB-2023.0/common/src/Scroll.c:241: if(clamp_enabled) {
	ld	a, (#_clamp_enabled)
	or	a, a
	ret	Z
	C$Scroll.c$242$2_0$228	= .
	.globl	C$Scroll.c$242$2_0$228
;C:/ZGB-2023.0/common/src/Scroll.c:242: if(U_LESS_THAN(scroll_x, 0u)) {
	ld	hl, #_scroll_x
	ld	a, (hl+)
	ld	h, (hl)
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	jr	NC, 00102$
	C$Scroll.c$243$3_0$229	= .
	.globl	C$Scroll.c$243$3_0$229
;C:/ZGB-2023.0/common/src/Scroll.c:243: scroll_x = 0u;		
	xor	a, a
	ld	hl, #_scroll_x
	ld	(hl+), a
	ld	(hl), a
00102$:
	C$Scroll.c$245$2_0$228	= .
	.globl	C$Scroll.c$245$2_0$228
;C:/ZGB-2023.0/common/src/Scroll.c:245: if(scroll_x > (scroll_w - SCREENWIDTH)) {
	ld	hl, #_scroll_w
	ld	a, (hl+)
	add	a, #0x60
	ld	c, a
	ld	a, (hl)
	adc	a, #0xff
	ld	b, a
	ld	hl, #_scroll_x
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, c
	sub	a, e
	ld	a, b
	sbc	a, d
	jr	NC, 00104$
	C$Scroll.c$246$3_0$230	= .
	.globl	C$Scroll.c$246$3_0$230
;C:/ZGB-2023.0/common/src/Scroll.c:246: scroll_x = (scroll_w - SCREENWIDTH);
	dec	hl
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
00104$:
	C$Scroll.c$248$2_0$228	= .
	.globl	C$Scroll.c$248$2_0$228
;C:/ZGB-2023.0/common/src/Scroll.c:248: if(U_LESS_THAN(scroll_y, 0u)) {
	ld	hl, #_scroll_y
	ld	a, (hl+)
	ld	h, (hl)
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	jr	NC, 00106$
	C$Scroll.c$249$3_0$231	= .
	.globl	C$Scroll.c$249$3_0$231
;C:/ZGB-2023.0/common/src/Scroll.c:249: scroll_y = 0u;		
	xor	a, a
	ld	hl, #_scroll_y
	ld	(hl+), a
	ld	(hl), a
00106$:
	C$Scroll.c$251$2_0$228	= .
	.globl	C$Scroll.c$251$2_0$228
;C:/ZGB-2023.0/common/src/Scroll.c:251: if(scroll_y > (scroll_h - SCREENHEIGHT + scroll_h_border)) {
	ld	hl, #_scroll_h
	ld	a, (hl+)
	add	a, #0x70
	ld	c, a
	ld	a, (hl)
	adc	a, #0xff
	ld	b, a
	ld	a, (#_scroll_h_border)
	ld	e, a
	rlca
	sbc	a, a
	ld	l, e
;	spillPairReg hl
;	spillPairReg hl
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	add	hl, bc
	ld	c, l
	ld	b, h
	ld	hl, #_scroll_y
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, c
	sub	a, e
	ld	a, b
	sbc	a, d
	ret	NC
	C$Scroll.c$252$3_0$232	= .
	.globl	C$Scroll.c$252$3_0$232
;C:/ZGB-2023.0/common/src/Scroll.c:252: scroll_y = (scroll_h - SCREENHEIGHT + scroll_h_border);
	dec	hl
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	C$Scroll.c$255$1_0$227	= .
	.globl	C$Scroll.c$255$1_0$227
;C:/ZGB-2023.0/common/src/Scroll.c:255: }
	C$Scroll.c$255$1_0$227	= .
	.globl	C$Scroll.c$255$1_0$227
	XG$ClampScrollLimits$0$0	= .
	.globl	XG$ClampScrollLimits$0$0
	ret
	G$ScrollSetMap$0$0	= .
	.globl	G$ScrollSetMap$0$0
	C$Scroll.c$257$1_0$234	= .
	.globl	C$Scroll.c$257$1_0$234
;C:/ZGB-2023.0/common/src/Scroll.c:257: void ScrollSetMap(UINT8 map_bank, const struct MapInfo* map) {
;	---------------------------------
; Function ScrollSetMap
; ---------------------------------
_ScrollSetMap::
	add	sp, #-3
	ldhl	sp,	#2
	ld	(hl), a
	C$Scroll.c$258$1_0$234	= .
	.globl	C$Scroll.c$258$1_0$234
;C:/ZGB-2023.0/common/src/Scroll.c:258: PUSH_BANK(map_bank);
	push	de
	ld	a, (hl)
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	pop	bc
	C$Scroll.c$259$1_0$234	= .
	.globl	C$Scroll.c$259$1_0$234
;C:/ZGB-2023.0/common/src/Scroll.c:259: scroll_tiles_w = map->width;
	ld	e, c
	ld	d, b
	inc	de
	inc	de
	ld	a, (de)
	ld	hl, #_scroll_tiles_w
	ld	(hl+), a
	ld	(hl), #0x00
	C$Scroll.c$260$1_0$234	= .
	.globl	C$Scroll.c$260$1_0$234
;C:/ZGB-2023.0/common/src/Scroll.c:260: scroll_tiles_h = map->height;
	ld	e, c
	ld	d, b
	inc	de
	inc	de
	inc	de
	ld	a, (de)
	ld	hl, #_scroll_tiles_h
	ld	(hl+), a
	ld	(hl), #0x00
	C$Scroll.c$261$1_0$234	= .
	.globl	C$Scroll.c$261$1_0$234
;C:/ZGB-2023.0/common/src/Scroll.c:261: scroll_map = map->data;
	ld	e, c
	ld	d, b
	ld	a, (de)
	ld	hl, #_scroll_map
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	C$Scroll.c$262$1_0$234	= .
	.globl	C$Scroll.c$262$1_0$234
;C:/ZGB-2023.0/common/src/Scroll.c:262: scroll_cmap = map->attributes;
	inc	bc
	inc	bc
	inc	bc
	inc	bc
	ld	e, c
	ld	d, b
	ld	a, (de)
	ld	hl, #_scroll_cmap
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	C$Scroll.c$263$1_0$234	= .
	.globl	C$Scroll.c$263$1_0$234
;C:/ZGB-2023.0/common/src/Scroll.c:263: scroll_x = 0;
	xor	a, a
	ld	hl, #_scroll_x
	ld	(hl+), a
	ld	(hl), a
	C$Scroll.c$264$1_0$234	= .
	.globl	C$Scroll.c$264$1_0$234
;C:/ZGB-2023.0/common/src/Scroll.c:264: scroll_y = 0;
	xor	a, a
	ld	hl, #_scroll_y
	ld	(hl+), a
	ld	(hl), a
	C$Scroll.c$265$1_0$234	= .
	.globl	C$Scroll.c$265$1_0$234
;C:/ZGB-2023.0/common/src/Scroll.c:265: scroll_w = scroll_tiles_w << 3;
	ld	a, (#_scroll_tiles_w)
	ld	(#_scroll_w),a
	ld	a, (#_scroll_tiles_w + 1)
	ld	(#_scroll_w + 1),a
	ld	a, #0x03
00112$:
	ld	hl, #_scroll_w
	sla	(hl)
	inc	hl
	rl	(hl)
	dec	a
	jr	NZ, 00112$
	C$Scroll.c$266$1_0$234	= .
	.globl	C$Scroll.c$266$1_0$234
;C:/ZGB-2023.0/common/src/Scroll.c:266: scroll_h = scroll_tiles_h << 3;
	ld	a, (#_scroll_tiles_h)
	ld	(#_scroll_h),a
	ld	a, (#_scroll_tiles_h + 1)
	ld	(#_scroll_h + 1),a
	ld	a, #0x03
00113$:
	ld	hl, #_scroll_h
	sla	(hl)
	inc	hl
	rl	(hl)
	dec	a
	jr	NZ, 00113$
	C$Scroll.c$267$1_0$234	= .
	.globl	C$Scroll.c$267$1_0$234
;C:/ZGB-2023.0/common/src/Scroll.c:267: scroll_bank = map_bank;
	ldhl	sp,	#2
	ld	a, (hl)
	ld	(#_scroll_bank),a
	C$Scroll.c$268$1_0$234	= .
	.globl	C$Scroll.c$268$1_0$234
;C:/ZGB-2023.0/common/src/Scroll.c:268: if(scroll_target) {
	ld	hl, #_scroll_target + 1
	ld	a, (hl-)
	or	a, (hl)
	jr	Z, 00102$
	C$Scroll.c$269$1_0$234	= .
	.globl	C$Scroll.c$269$1_0$234
;C:/ZGB-2023.0/common/src/Scroll.c:269: scroll_x = scroll_target->x - (SCREENWIDTH >> 1);
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #0x000c
	add	hl, bc
	ld	e, l
	ld	d, h
	ld	a, (de)
	ldhl	sp,	#0
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	pop	de
	push	de
	ld	hl, #0x0050
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ld	hl, #_scroll_x + 1
	ld	(hl-), a
	ld	(hl), e
	C$Scroll.c$270$2_0$235	= .
	.globl	C$Scroll.c$270$2_0$235
;C:/ZGB-2023.0/common/src/Scroll.c:270: scroll_y = scroll_target->y - scroll_bottom_movement_limit; //Move the camera to its bottom limit
	ld	hl, #0x000e
	add	hl, bc
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #_scroll_bottom_movement_limit
	ld	e, (hl)
	ld	d, #0x00
	ld	a, c
	sub	a, e
	ld	hl, #_scroll_y
	ld	(hl+), a
	ld	a, b
	sbc	a, d
	ld	(hl), a
	C$Scroll.c$271$2_0$235	= .
	.globl	C$Scroll.c$271$2_0$235
;C:/ZGB-2023.0/common/src/Scroll.c:271: ClampScrollLimits();
	call	_ClampScrollLimits
00102$:
	C$Scroll.c$273$1_0$234	= .
	.globl	C$Scroll.c$273$1_0$234
;C:/ZGB-2023.0/common/src/Scroll.c:273: pending_h_i = 0;
	ld	hl, #_pending_h_i
	ld	(hl), #0x00
	C$Scroll.c$274$1_0$234	= .
	.globl	C$Scroll.c$274$1_0$234
;C:/ZGB-2023.0/common/src/Scroll.c:274: pending_w_i = 0;
	ld	hl, #_pending_w_i
	ld	(hl), #0x00
	C$Scroll.c$275$1_0$234	= .
	.globl	C$Scroll.c$275$1_0$234
;C:/ZGB-2023.0/common/src/Scroll.c:275: POP_BANK;
	call	_PopBank
	C$Scroll.c$276$1_0$234	= .
	.globl	C$Scroll.c$276$1_0$234
;C:/ZGB-2023.0/common/src/Scroll.c:276: }
	add	sp, #3
	C$Scroll.c$276$1_0$234	= .
	.globl	C$Scroll.c$276$1_0$234
	XG$ScrollSetMap$0$0	= .
	.globl	XG$ScrollSetMap$0$0
	ret
	G$InitScroll$0$0	= .
	.globl	G$InitScroll$0$0
	C$Scroll.c$278$1_0$237	= .
	.globl	C$Scroll.c$278$1_0$237
;C:/ZGB-2023.0/common/src/Scroll.c:278: void InitScroll(UINT8 map_bank, const struct MapInfo* map, const UINT8* coll_list, const UINT8* coll_list_down) {
;	---------------------------------
; Function InitScroll
; ---------------------------------
_InitScroll::
	add	sp, #-4
	ldhl	sp,	#3
	ld	(hl), a
	C$Scroll.c$283$1_0$237	= .
	.globl	C$Scroll.c$283$1_0$237
;C:/ZGB-2023.0/common/src/Scroll.c:283: PUSH_BANK(map_bank)
	push	de
	ld	a, (hl)
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	pop	bc
	C$Scroll.c$284$1_0$237	= .
	.globl	C$Scroll.c$284$1_0$237
;C:/ZGB-2023.0/common/src/Scroll.c:284: tiles_bank = map->tiles_bank;
	ld	hl, #0x0006
	add	hl, bc
	ld	a, (hl)
	ldhl	sp,	#0
	ld	(hl), a
	C$Scroll.c$285$1_0$237	= .
	.globl	C$Scroll.c$285$1_0$237
;C:/ZGB-2023.0/common/src/Scroll.c:285: tiles = map->tiles;
	ld	hl, #0x0007
	add	hl, bc
	ld	e, l
	ld	d, h
	ld	a, (de)
	ldhl	sp,	#1
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	C$Scroll.c$286$1_0$237	= .
	.globl	C$Scroll.c$286$1_0$237
;C:/ZGB-2023.0/common/src/Scroll.c:286: POP_BANK;
	push	bc
	call	_PopBank
	pop	bc
	C$Scroll.c$288$1_0$237	= .
	.globl	C$Scroll.c$288$1_0$237
;C:/ZGB-2023.0/common/src/Scroll.c:288: InitScrollWithTiles(map_bank, map, tiles_bank, tiles, coll_list, coll_list_down);
	ldhl	sp,	#8
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ldhl	sp,	#8
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ldhl	sp,	#5
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl-)
	dec	hl
	ld	d, a
	push	de
	ld	a, (hl)
	push	af
	inc	sp
	ld	e, c
	ld	d, b
	ldhl	sp,	#10
	ld	a, (hl)
	call	_InitScrollWithTiles
	C$Scroll.c$289$1_0$237	= .
	.globl	C$Scroll.c$289$1_0$237
;C:/ZGB-2023.0/common/src/Scroll.c:289: }
	add	sp, #4
	pop	hl
	add	sp, #4
	jp	(hl)
	G$InitScrollWithTiles$0$0	= .
	.globl	G$InitScrollWithTiles$0$0
	C$Scroll.c$291$1_0$239	= .
	.globl	C$Scroll.c$291$1_0$239
;C:/ZGB-2023.0/common/src/Scroll.c:291: void InitScrollWithTiles(UINT8 map_bank, const struct MapInfo* map, UINT8 tiles_info_bank, const struct TilesInfo* tiles_info, const UINT8* coll_list, const UINT8* coll_list_down)
;	---------------------------------
; Function InitScrollWithTiles
; ---------------------------------
_InitScrollWithTiles::
	add	sp, #-4
	ldhl	sp,	#0
	ld	(hl), a
	C$Scroll.c$296$1_0$239	= .
	.globl	C$Scroll.c$296$1_0$239
;C:/ZGB-2023.0/common/src/Scroll.c:296: ScrollSetTiles(0, tiles_info_bank, tiles_info);
	push	de
	ldhl	sp,	#9
	ld	a, (hl+)
	ld	c, a
	ld	a, (hl-)
	dec	hl
	ld	b, a
	push	bc
	ld	e, (hl)
	xor	a, a
	call	_ScrollSetTiles
	pop	de
	C$Scroll.c$298$1_0$239	= .
	.globl	C$Scroll.c$298$1_0$239
;C:/ZGB-2023.0/common/src/Scroll.c:298: ScrollSetMap(map_bank, map);
	ldhl	sp,	#0
	ld	a, (hl)
	call	_ScrollSetMap
	C$Scroll.c$300$1_0$239	= .
	.globl	C$Scroll.c$300$1_0$239
;C:/ZGB-2023.0/common/src/Scroll.c:300: memset(scroll_collisions, 0, sizeof(scroll_collisions));
	xor	a, a
	inc	a
	push	af
	ld	de, #0x0000
	push	de
	ld	de, #_scroll_collisions
	push	de
	call	_memset
	add	sp, #6
	C$Scroll.c$301$1_0$239	= .
	.globl	C$Scroll.c$301$1_0$239
;C:/ZGB-2023.0/common/src/Scroll.c:301: memset(scroll_collisions_down, 0, sizeof(scroll_collisions_down));
	xor	a, a
	inc	a
	push	af
	ld	de, #0x0000
	push	de
	ld	de, #_scroll_collisions_down
	push	de
	call	_memset
	add	sp, #6
	C$Scroll.c$303$1_0$239	= .
	.globl	C$Scroll.c$303$1_0$239
;C:/ZGB-2023.0/common/src/Scroll.c:303: if(coll_list) {
	ldhl	sp,	#10
	ld	a, (hl-)
	or	a, (hl)
	jr	Z, 00103$
	C$Scroll.c$304$1_0$239	= .
	.globl	C$Scroll.c$304$1_0$239
;C:/ZGB-2023.0/common/src/Scroll.c:304: for(i = 0u; coll_list[i] != 0u; ++i) {
	ld	e, #0x00
00109$:
	push	de
	ld	d, #0x00
	ldhl	sp,	#11
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, de
	pop	de
	ld	c, l
	ld	b, h
	ld	a, (bc)
	or	a, a
	jr	Z, 00103$
	C$Scroll.c$305$4_0$242	= .
	.globl	C$Scroll.c$305$4_0$242
;C:/ZGB-2023.0/common/src/Scroll.c:305: scroll_collisions[coll_list[i]] = 1u;
	add	a, #<(_scroll_collisions)
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	a, #0x00
	adc	a, #>(_scroll_collisions)
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	ld	(hl), #0x01
	C$Scroll.c$306$4_0$242	= .
	.globl	C$Scroll.c$306$4_0$242
;C:/ZGB-2023.0/common/src/Scroll.c:306: scroll_collisions_down[coll_list[i]] = 1u;
	ld	a, (bc)
	ld	c, a
	ld	hl, #_scroll_collisions_down
	ld	b, #0x00
	add	hl, bc
	ld	(hl), #0x01
	C$Scroll.c$304$3_0$241	= .
	.globl	C$Scroll.c$304$3_0$241
;C:/ZGB-2023.0/common/src/Scroll.c:304: for(i = 0u; coll_list[i] != 0u; ++i) {
	inc	e
	jr	00109$
00103$:
	C$Scroll.c$309$1_0$239	= .
	.globl	C$Scroll.c$309$1_0$239
;C:/ZGB-2023.0/common/src/Scroll.c:309: if(coll_list_down) {
	ldhl	sp,	#12
	ld	a, (hl-)
	or	a, (hl)
	jr	Z, 00106$
	C$Scroll.c$310$1_0$239	= .
	.globl	C$Scroll.c$310$1_0$239
;C:/ZGB-2023.0/common/src/Scroll.c:310: for(i = 0u; coll_list_down[i] != 0u; ++i) {
	ld	e, #0x00
00112$:
	push	de
	ld	d, #0x00
	ldhl	sp,	#13
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, de
	pop	de
	ld	c, l
	ld	b, h
	ld	a, (bc)
	or	a, a
	jr	Z, 00106$
	C$Scroll.c$311$4_0$245	= .
	.globl	C$Scroll.c$311$4_0$245
;C:/ZGB-2023.0/common/src/Scroll.c:311: scroll_collisions_down[coll_list_down[i]] = 1u;
	add	a, #<(_scroll_collisions_down)
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	a, #0x00
	adc	a, #>(_scroll_collisions_down)
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	ld	(hl), #0x01
	C$Scroll.c$310$3_0$244	= .
	.globl	C$Scroll.c$310$3_0$244
;C:/ZGB-2023.0/common/src/Scroll.c:310: for(i = 0u; coll_list_down[i] != 0u; ++i) {
	inc	e
	jr	00112$
00106$:
	C$Scroll.c$316$1_0$239	= .
	.globl	C$Scroll.c$316$1_0$239
;C:/ZGB-2023.0/common/src/Scroll.c:316: PUSH_BANK(map_bank);
	ldhl	sp,	#0
	ld	a, (hl)
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	C$Scroll.c$317$1_0$239	= .
	.globl	C$Scroll.c$317$1_0$239
;C:/ZGB-2023.0/common/src/Scroll.c:317: y = scroll_y >> 3;
	ld	a, (#_scroll_y)
	ldhl	sp,	#1
	ld	(hl), a
	ld	a, (#_scroll_y + 1)
	ldhl	sp,	#2
	ld	(hl), a
	sra	(hl)
	dec	hl
	rr	(hl)
	inc	hl
	sra	(hl)
	dec	hl
	rr	(hl)
	inc	hl
	sra	(hl)
	dec	hl
	rr	(hl)
	C$Scroll.c$318$1_0$239	= .
	.globl	C$Scroll.c$318$1_0$239
;C:/ZGB-2023.0/common/src/Scroll.c:318: for(i = 0u; i != (SCREEN_TILE_REFRES_H) && y != scroll_h; ++i, y ++) {
	inc	hl
	inc	hl
	ld	(hl), #0x00
00116$:
	ldhl	sp,	#3
	ld	a, (hl)
	sub	a, #0x15
	jr	Z, 00107$
	ldhl	sp,	#1
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #_scroll_h
	ld	a, (hl)
	sub	a, c
	jr	NZ, 00187$
	inc	hl
	ld	a, (hl)
	sub	a, b
	jr	Z, 00107$
00187$:
	C$Scroll.c$319$3_0$247	= .
	.globl	C$Scroll.c$319$3_0$247
;C:/ZGB-2023.0/common/src/Scroll.c:319: ScrollUpdateRow((scroll_x >> 3) - SCREEN_PAD_LEFT,  y - SCREEN_PAD_TOP);
	ldhl	sp,#1
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	dec	bc
	ld	hl, #_scroll_x
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	sra	d
	rr	e
	sra	d
	rr	e
	sra	d
	rr	e
	dec	de
	call	_ScrollUpdateRow
	C$Scroll.c$318$2_0$246	= .
	.globl	C$Scroll.c$318$2_0$246
;C:/ZGB-2023.0/common/src/Scroll.c:318: for(i = 0u; i != (SCREEN_TILE_REFRES_H) && y != scroll_h; ++i, y ++) {
	ldhl	sp,	#3
	inc	(hl)
	dec	hl
	dec	hl
	inc	(hl)
	jr	NZ, 00116$
	inc	hl
	inc	(hl)
	jr	00116$
00107$:
	C$Scroll.c$321$1_0$239	= .
	.globl	C$Scroll.c$321$1_0$239
;C:/ZGB-2023.0/common/src/Scroll.c:321: POP_BANK;
	call	_PopBank
	C$Scroll.c$322$1_0$239	= .
	.globl	C$Scroll.c$322$1_0$239
;C:/ZGB-2023.0/common/src/Scroll.c:322: }
	add	sp, #4
	pop	hl
	add	sp, #7
	jp	(hl)
	G$ScrollUpdateRowR$0$0	= .
	.globl	G$ScrollUpdateRowR$0$0
	C$Scroll.c$324$1_0$249	= .
	.globl	C$Scroll.c$324$1_0$249
;C:/ZGB-2023.0/common/src/Scroll.c:324: void ScrollUpdateRowR() {
;	---------------------------------
; Function ScrollUpdateRowR
; ---------------------------------
_ScrollUpdateRowR::
	add	sp, #-3
	C$Scroll.c$327$2_0$249	= .
	.globl	C$Scroll.c$327$2_0$249
;C:/ZGB-2023.0/common/src/Scroll.c:327: for(i = 0u; i != 5 && pending_w_i != 0; ++i, -- pending_w_i)  {
	ldhl	sp,	#2
	ld	(hl), #0x00
00104$:
	ldhl	sp,	#2
	ld	a, (hl)
	sub	a, #0x05
	jr	Z, 00106$
	ld	a, (#_pending_w_i)
	or	a, a
	jr	Z, 00106$
	C$Scroll.c$329$3_0$250	= .
	.globl	C$Scroll.c$329$3_0$250
;C:/ZGB-2023.0/common/src/Scroll.c:329: UPDATE_TILE(pending_w_x ++, pending_w_y, pending_w_map ++, pending_w_cmap++);
	ld	hl, #_pending_w_cmap
	ld	a, (hl+)
	ld	c, a
	ld	a, (hl-)
	ld	b, a
	inc	(hl)
	jr	NZ, 00131$
	inc	hl
	inc	(hl)
00131$:
	ld	a, (#_pending_w_map)
	ldhl	sp,	#0
	ld	(hl), a
	ld	a, (#_pending_w_map + 1)
	ldhl	sp,	#1
	ld	(hl), a
	ld	hl, #_pending_w_map
	inc	(hl)
	jr	NZ, 00132$
	inc	hl
	inc	(hl)
00132$:
	ld	hl, #_pending_w_x
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl-)
	ld	d, a
	inc	(hl)
	jr	NZ, 00133$
	inc	hl
	inc	(hl)
00133$:
	push	bc
	ldhl	sp,	#2
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	push	bc
	ld	hl, #_pending_w_y
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	call	_UPDATE_TILE
	C$Scroll.c$327$2_0$249	= .
	.globl	C$Scroll.c$327$2_0$249
;C:/ZGB-2023.0/common/src/Scroll.c:327: for(i = 0u; i != 5 && pending_w_i != 0; ++i, -- pending_w_i)  {
	ldhl	sp,	#2
	inc	(hl)
	ld	hl, #_pending_w_i
	dec	(hl)
	jr	00104$
00106$:
	C$Scroll.c$334$2_0$249	= .
	.globl	C$Scroll.c$334$2_0$249
;C:/ZGB-2023.0/common/src/Scroll.c:334: }
	add	sp, #3
	C$Scroll.c$334$2_0$249	= .
	.globl	C$Scroll.c$334$2_0$249
	XG$ScrollUpdateRowR$0$0	= .
	.globl	XG$ScrollUpdateRowR$0$0
	ret
	G$ScrollUpdateRowWithDelay$0$0	= .
	.globl	G$ScrollUpdateRowWithDelay$0$0
	C$Scroll.c$336$2_0$252	= .
	.globl	C$Scroll.c$336$2_0$252
;C:/ZGB-2023.0/common/src/Scroll.c:336: void ScrollUpdateRowWithDelay(INT16 x, INT16 y) {
;	---------------------------------
; Function ScrollUpdateRowWithDelay
; ---------------------------------
_ScrollUpdateRowWithDelay::
	dec	sp
	dec	sp
	C$Scroll.c$337$1_0$252	= .
	.globl	C$Scroll.c$337$1_0$252
;C:/ZGB-2023.0/common/src/Scroll.c:337: while(pending_w_i) {
00101$:
	ld	a, (#_pending_w_i)
	or	a, a
	jr	Z, 00103$
	C$Scroll.c$338$2_0$253	= .
	.globl	C$Scroll.c$338$2_0$253
;C:/ZGB-2023.0/common/src/Scroll.c:338: ScrollUpdateRowR();
	push	bc
	push	de
	call	_ScrollUpdateRowR
	pop	de
	pop	bc
	jr	00101$
00103$:
	C$Scroll.c$341$1_0$252	= .
	.globl	C$Scroll.c$341$1_0$252
;C:/ZGB-2023.0/common/src/Scroll.c:341: pending_w_x = x;
	ld	hl, #_pending_w_x
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
	C$Scroll.c$342$1_0$252	= .
	.globl	C$Scroll.c$342$1_0$252
;C:/ZGB-2023.0/common/src/Scroll.c:342: pending_w_y = y;
	ld	hl, #_pending_w_y
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	C$Scroll.c$343$1_0$252	= .
	.globl	C$Scroll.c$343$1_0$252
;C:/ZGB-2023.0/common/src/Scroll.c:343: pending_w_i = SCREEN_TILE_REFRES_W;
	ld	hl, #_pending_w_i
	ld	(hl), #0x17
	C$Scroll.c$344$1_0$252	= .
	.globl	C$Scroll.c$344$1_0$252
;C:/ZGB-2023.0/common/src/Scroll.c:344: pending_w_map = scroll_map + scroll_tiles_w * y + x;
	push	de
	ld	hl, #_scroll_tiles_w
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	__mulint
	pop	de
	ld	hl, #_scroll_map
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	inc	sp
	inc	sp
	push	hl
	push	de
	ldhl	sp,	#2
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, de
	pop	de
	ld	a, l
	ld	(_pending_w_map), a
	ld	a, h
	ld	(_pending_w_map + 1), a
	C$Scroll.c$347$1_0$252	= .
	.globl	C$Scroll.c$347$1_0$252
;C:/ZGB-2023.0/common/src/Scroll.c:347: pending_w_cmap = scroll_cmap + scroll_tiles_w * y + x;
	ld	a, c
	ld	hl, #_scroll_cmap
	add	a, (hl)
	inc	hl
	ld	c, a
	ld	a, b
	adc	a, (hl)
	ld	b, a
	ld	a, c
	add	a, e
	ld	hl, #_pending_w_cmap
	ld	(hl+), a
	ld	a, b
	adc	a, d
	ld	(hl), a
	C$Scroll.c$349$1_0$252	= .
	.globl	C$Scroll.c$349$1_0$252
;C:/ZGB-2023.0/common/src/Scroll.c:349: }
	inc	sp
	inc	sp
	C$Scroll.c$349$1_0$252	= .
	.globl	C$Scroll.c$349$1_0$252
	XG$ScrollUpdateRowWithDelay$0$0	= .
	.globl	XG$ScrollUpdateRowWithDelay$0$0
	ret
	G$ScrollUpdateRow$0$0	= .
	.globl	G$ScrollUpdateRow$0$0
	C$Scroll.c$351$1_0$255	= .
	.globl	C$Scroll.c$351$1_0$255
;C:/ZGB-2023.0/common/src/Scroll.c:351: void ScrollUpdateRow(INT16 x, INT16 y) {
;	---------------------------------
; Function ScrollUpdateRow
; ---------------------------------
_ScrollUpdateRow::
	add	sp, #-11
	ldhl	sp,	#4
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
	ldhl	sp,	#2
	ld	a, c
	ld	(hl+), a
	C$Scroll.c$353$1_0$255	= .
	.globl	C$Scroll.c$353$1_0$255
;C:/ZGB-2023.0/common/src/Scroll.c:353: unsigned char* map = scroll_map + scroll_tiles_w * y + x;
	ld	a, b
	ld	(hl-), a
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #_scroll_tiles_w
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	__mulint
	ld	a, c
	ld	hl, #_scroll_map
	add	a, (hl)
	inc	hl
	ld	e, a
	ld	a, b
	adc	a, (hl)
	ld	d, a
	ldhl	sp,	#4
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, de
	ld	e, l
	ld	d, h
	C$Scroll.c$356$1_0$255	= .
	.globl	C$Scroll.c$356$1_0$255
;C:/ZGB-2023.0/common/src/Scroll.c:356: unsigned char* cmap = scroll_cmap + scroll_tiles_w * y + x;
	ld	a, c
	ld	hl, #_scroll_cmap
	add	a, (hl)
	inc	hl
	ld	c, a
	ld	a, b
	adc	a, (hl)
	ld	b, a
	ldhl	sp,	#4
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	C$Scroll.c$359$1_0$255	= .
	.globl	C$Scroll.c$359$1_0$255
;C:/ZGB-2023.0/common/src/Scroll.c:359: PUSH_BANK(scroll_bank);
	push	hl
	push	de
	ld	a, (#_scroll_bank)
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	pop	de
	pop	bc
	C$Scroll.c$360$1_0$255	= .
	.globl	C$Scroll.c$360$1_0$255
;C:/ZGB-2023.0/common/src/Scroll.c:360: for(i = 0u; i != SCREEN_TILE_REFRES_W; ++i) {
	ldhl	sp,	#6
	ld	a, c
	ld	(hl+), a
	ld	a, b
	ld	(hl+), a
	ld	a, e
	ld	(hl+), a
	ld	a, d
	ld	(hl+), a
	ld	(hl), #0x00
00102$:
	C$Scroll.c$362$3_0$257	= .
	.globl	C$Scroll.c$362$3_0$257
;C:/ZGB-2023.0/common/src/Scroll.c:362: UPDATE_TILE(x + i, y, map ++, cmap ++);
	ldhl	sp,	#6
	ld	a, (hl+)
	ld	c, a
	ld	a, (hl-)
	ld	b, a
	inc	(hl)
	jr	NZ, 00121$
	inc	hl
	inc	(hl)
00121$:
	ldhl	sp,	#8
	ld	a, (hl)
	ldhl	sp,	#0
	ld	(hl), a
	ldhl	sp,	#9
	ld	a, (hl)
	ldhl	sp,	#1
	ld	(hl), a
	ldhl	sp,	#8
	inc	(hl)
	jr	NZ, 00122$
	inc	hl
	inc	(hl)
00122$:
	ldhl	sp,	#10
	ld	e, (hl)
	ld	d, #0x00
	ldhl	sp,	#4
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, de
	ld	e, l
	ld	d, h
	push	bc
	ldhl	sp,	#2
	ld	a, (hl+)
	ld	c, a
	ld	a, (hl+)
	ld	b, a
	push	bc
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	call	_UPDATE_TILE
	C$Scroll.c$360$2_0$256	= .
	.globl	C$Scroll.c$360$2_0$256
;C:/ZGB-2023.0/common/src/Scroll.c:360: for(i = 0u; i != SCREEN_TILE_REFRES_W; ++i) {
	ldhl	sp,	#10
	inc	(hl)
	ld	a, (hl)
	sub	a, #0x17
	jr	NZ, 00102$
	C$Scroll.c$367$1_0$255	= .
	.globl	C$Scroll.c$367$1_0$255
;C:/ZGB-2023.0/common/src/Scroll.c:367: POP_BANK;
	call	_PopBank
	C$Scroll.c$368$1_0$255	= .
	.globl	C$Scroll.c$368$1_0$255
;C:/ZGB-2023.0/common/src/Scroll.c:368: }
	add	sp, #11
	C$Scroll.c$368$1_0$255	= .
	.globl	C$Scroll.c$368$1_0$255
	XG$ScrollUpdateRow$0$0	= .
	.globl	XG$ScrollUpdateRow$0$0
	ret
	G$ScrollUpdateColumnR$0$0	= .
	.globl	G$ScrollUpdateColumnR$0$0
	C$Scroll.c$370$1_0$259	= .
	.globl	C$Scroll.c$370$1_0$259
;C:/ZGB-2023.0/common/src/Scroll.c:370: void ScrollUpdateColumnR() {
;	---------------------------------
; Function ScrollUpdateColumnR
; ---------------------------------
_ScrollUpdateColumnR::
	C$Scroll.c$373$2_0$259	= .
	.globl	C$Scroll.c$373$2_0$259
;C:/ZGB-2023.0/common/src/Scroll.c:373: for(i = 0u; i != 5 && pending_h_i != 0; ++i, pending_h_i --) {
	ld	e, #0x00
00104$:
	ld	a, e
	sub	a, #0x05
	ret	Z
	ld	a, (#_pending_h_i)
	or	a, a
	ret	Z
	C$Scroll.c$375$3_0$260	= .
	.globl	C$Scroll.c$375$3_0$260
;C:/ZGB-2023.0/common/src/Scroll.c:375: UPDATE_TILE(pending_h_x, pending_h_y ++, pending_h_map, pending_h_cmap);
	ld	hl, #_pending_h_y
	ld	a, (hl+)
	ld	c, a
	ld	a, (hl-)
	ld	b, a
	inc	(hl)
	jr	NZ, 00131$
	inc	hl
	inc	(hl)
00131$:
	push	de
	ld	hl, #_pending_h_cmap
	ld	l, (hl)
;	spillPairReg hl
;	spillPairReg hl
	ld	a, (_pending_h_cmap + 1)
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	push	hl
	ld	hl, #_pending_h_map
	ld	l, (hl)
;	spillPairReg hl
;	spillPairReg hl
	ld	a, (_pending_h_map + 1)
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	push	hl
	ld	hl, #_pending_h_x
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	_UPDATE_TILE
	pop	de
	C$Scroll.c$376$3_0$260	= .
	.globl	C$Scroll.c$376$3_0$260
;C:/ZGB-2023.0/common/src/Scroll.c:376: pending_h_map += scroll_tiles_w;
	ld	a, (#_pending_h_map)
	ld	hl, #_scroll_tiles_w
	add	a, (hl)
	ld	hl, #_pending_h_map
	ld	(hl+), a
	ld	a, (hl)
	ld	hl, #_scroll_tiles_w + 1
	adc	a, (hl)
	ld	(#_pending_h_map + 1),a
	C$Scroll.c$377$3_0$260	= .
	.globl	C$Scroll.c$377$3_0$260
;C:/ZGB-2023.0/common/src/Scroll.c:377: pending_h_cmap += scroll_tiles_w;
	ld	a, (#_pending_h_cmap)
	ld	hl, #_scroll_tiles_w
	add	a, (hl)
	ld	hl, #_pending_h_cmap
	ld	(hl+), a
	ld	a, (hl)
	ld	hl, #_scroll_tiles_w + 1
	adc	a, (hl)
	ld	(#_pending_h_cmap + 1),a
	C$Scroll.c$373$2_0$259	= .
	.globl	C$Scroll.c$373$2_0$259
;C:/ZGB-2023.0/common/src/Scroll.c:373: for(i = 0u; i != 5 && pending_h_i != 0; ++i, pending_h_i --) {
	inc	e
	ld	hl, #_pending_h_i
	dec	(hl)
	C$Scroll.c$383$2_0$259	= .
	.globl	C$Scroll.c$383$2_0$259
;C:/ZGB-2023.0/common/src/Scroll.c:383: }
	C$Scroll.c$383$2_0$259	= .
	.globl	C$Scroll.c$383$2_0$259
	XG$ScrollUpdateColumnR$0$0	= .
	.globl	XG$ScrollUpdateColumnR$0$0
	jr	00104$
	G$ScrollUpdateColumnWithDelay$0$0	= .
	.globl	G$ScrollUpdateColumnWithDelay$0$0
	C$Scroll.c$385$2_0$262	= .
	.globl	C$Scroll.c$385$2_0$262
;C:/ZGB-2023.0/common/src/Scroll.c:385: void ScrollUpdateColumnWithDelay(INT16 x, INT16 y) {
;	---------------------------------
; Function ScrollUpdateColumnWithDelay
; ---------------------------------
_ScrollUpdateColumnWithDelay::
	dec	sp
	dec	sp
	C$Scroll.c$386$1_0$262	= .
	.globl	C$Scroll.c$386$1_0$262
;C:/ZGB-2023.0/common/src/Scroll.c:386: while(pending_h_i) {
00101$:
	ld	a, (#_pending_h_i)
	or	a, a
	jr	Z, 00103$
	C$Scroll.c$387$2_0$263	= .
	.globl	C$Scroll.c$387$2_0$263
;C:/ZGB-2023.0/common/src/Scroll.c:387: ScrollUpdateColumnR();
	push	bc
	push	de
	call	_ScrollUpdateColumnR
	pop	de
	pop	bc
	jr	00101$
00103$:
	C$Scroll.c$390$1_0$262	= .
	.globl	C$Scroll.c$390$1_0$262
;C:/ZGB-2023.0/common/src/Scroll.c:390: pending_h_x = x;
	ld	hl, #_pending_h_x
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
	C$Scroll.c$391$1_0$262	= .
	.globl	C$Scroll.c$391$1_0$262
;C:/ZGB-2023.0/common/src/Scroll.c:391: pending_h_y = y;
	ld	hl, #_pending_h_y
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	C$Scroll.c$392$1_0$262	= .
	.globl	C$Scroll.c$392$1_0$262
;C:/ZGB-2023.0/common/src/Scroll.c:392: pending_h_i = SCREEN_TILE_REFRES_H;
	ld	hl, #_pending_h_i
	ld	(hl), #0x15
	C$Scroll.c$393$1_0$262	= .
	.globl	C$Scroll.c$393$1_0$262
;C:/ZGB-2023.0/common/src/Scroll.c:393: pending_h_map = scroll_map + scroll_tiles_w * y + x;
	push	de
	ld	hl, #_scroll_tiles_w
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	__mulint
	pop	de
	ld	hl, #_scroll_map
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	inc	sp
	inc	sp
	push	hl
	push	de
	ldhl	sp,	#2
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, de
	pop	de
	ld	a, l
	ld	(_pending_h_map), a
	ld	a, h
	ld	(_pending_h_map + 1), a
	C$Scroll.c$396$1_0$262	= .
	.globl	C$Scroll.c$396$1_0$262
;C:/ZGB-2023.0/common/src/Scroll.c:396: pending_h_cmap = scroll_cmap + scroll_tiles_w * y + x;
	ld	a, c
	ld	hl, #_scroll_cmap
	add	a, (hl)
	inc	hl
	ld	c, a
	ld	a, b
	adc	a, (hl)
	ld	b, a
	ld	a, c
	add	a, e
	ld	hl, #_pending_h_cmap
	ld	(hl+), a
	ld	a, b
	adc	a, d
	ld	(hl), a
	C$Scroll.c$398$1_0$262	= .
	.globl	C$Scroll.c$398$1_0$262
;C:/ZGB-2023.0/common/src/Scroll.c:398: }
	inc	sp
	inc	sp
	C$Scroll.c$398$1_0$262	= .
	.globl	C$Scroll.c$398$1_0$262
	XG$ScrollUpdateColumnWithDelay$0$0	= .
	.globl	XG$ScrollUpdateColumnWithDelay$0$0
	ret
	G$ScrollUpdateColumn$0$0	= .
	.globl	G$ScrollUpdateColumn$0$0
	C$Scroll.c$400$1_0$265	= .
	.globl	C$Scroll.c$400$1_0$265
;C:/ZGB-2023.0/common/src/Scroll.c:400: void ScrollUpdateColumn(INT16 x, INT16 y) {
;	---------------------------------
; Function ScrollUpdateColumn
; ---------------------------------
_ScrollUpdateColumn::
	add	sp, #-7
	ldhl	sp,	#2
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
	inc	sp
	inc	sp
	push	bc
	ld	hl, #_scroll_tiles_w
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	__mulint
	ldhl	sp,	#2
	ld	a, (hl+)
	ld	e, (hl)
	add	a, c
	ld	c, a
	ld	a, e
	adc	a, b
	ld	b, a
	ld	a, c
	ld	hl, #_scroll_map
	add	a, (hl)
	inc	hl
	ld	e, a
	ld	a, b
	adc	a, (hl)
	ld	d, a
	C$Scroll.c$404$1_0$265	= .
	.globl	C$Scroll.c$404$1_0$265
;C:/ZGB-2023.0/common/src/Scroll.c:404: unsigned char* cmap = &scroll_cmap[scroll_tiles_w * y + x];
	ld	hl, #_scroll_cmap
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	push	hl
	ld	a, l
	ldhl	sp,	#6
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#5
	ld	(hl), a
	C$Scroll.c$407$1_0$265	= .
	.globl	C$Scroll.c$407$1_0$265
;C:/ZGB-2023.0/common/src/Scroll.c:407: PUSH_BANK(scroll_bank);
	push	de
	ld	a, (#_scroll_bank)
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	pop	de
	C$Scroll.c$408$1_0$265	= .
	.globl	C$Scroll.c$408$1_0$265
;C:/ZGB-2023.0/common/src/Scroll.c:408: for(i = 0u; i != SCREEN_TILE_REFRES_H; ++i) {
	ldhl	sp,	#6
	ld	(hl), #0x00
00102$:
	C$Scroll.c$410$3_0$267	= .
	.globl	C$Scroll.c$410$3_0$267
;C:/ZGB-2023.0/common/src/Scroll.c:410: UPDATE_TILE(x, y + i, map, cmap);
	ldhl	sp,	#6
	ld	c, (hl)
	ld	b, #0x00
	pop	hl
	push	hl
	add	hl, bc
	ld	c, l
	ld	b, h
	push	de
	ldhl	sp,	#6
	ld	a, (hl+)
	ld	h, (hl)
;	spillPairReg hl
;	spillPairReg hl
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	push	hl
	push	de
	ldhl	sp,	#8
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	_UPDATE_TILE
	pop	de
	C$Scroll.c$411$3_0$267	= .
	.globl	C$Scroll.c$411$3_0$267
;C:/ZGB-2023.0/common/src/Scroll.c:411: map += scroll_tiles_w;
	ld	a, e
	ld	hl, #_scroll_tiles_w
	add	a, (hl)
	inc	hl
	ld	e, a
	ld	a, d
	adc	a, (hl)
	ld	d, a
	C$Scroll.c$412$3_0$267	= .
	.globl	C$Scroll.c$412$3_0$267
;C:/ZGB-2023.0/common/src/Scroll.c:412: cmap += scroll_tiles_w;
	push	de
	ldhl	sp,#6
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #_scroll_tiles_w
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, de
	pop	de
	push	hl
	ld	a, l
	ldhl	sp,	#6
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#5
	C$Scroll.c$408$2_0$266	= .
	.globl	C$Scroll.c$408$2_0$266
;C:/ZGB-2023.0/common/src/Scroll.c:408: for(i = 0u; i != SCREEN_TILE_REFRES_H; ++i) {
	ld	(hl+), a
	inc	(hl)
	ld	a, (hl)
	sub	a, #0x15
	jr	NZ, 00102$
	C$Scroll.c$418$1_0$265	= .
	.globl	C$Scroll.c$418$1_0$265
;C:/ZGB-2023.0/common/src/Scroll.c:418: POP_BANK;
	call	_PopBank
	C$Scroll.c$419$1_0$265	= .
	.globl	C$Scroll.c$419$1_0$265
;C:/ZGB-2023.0/common/src/Scroll.c:419: }
	add	sp, #7
	C$Scroll.c$419$1_0$265	= .
	.globl	C$Scroll.c$419$1_0$265
	XG$ScrollUpdateColumn$0$0	= .
	.globl	XG$ScrollUpdateColumn$0$0
	ret
	G$RefreshScroll$0$0	= .
	.globl	G$RefreshScroll$0$0
	C$Scroll.c$421$1_0$268	= .
	.globl	C$Scroll.c$421$1_0$268
;C:/ZGB-2023.0/common/src/Scroll.c:421: void RefreshScroll() {
;	---------------------------------
; Function RefreshScroll
; ---------------------------------
_RefreshScroll::
	add	sp, #-10
	C$Scroll.c$422$2_0$268	= .
	.globl	C$Scroll.c$422$2_0$268
;C:/ZGB-2023.0/common/src/Scroll.c:422: UINT16 ny = scroll_y;
	ld	a, (#_scroll_y)
	ldhl	sp,	#0
	ld	(hl), a
	ld	a, (#_scroll_y + 1)
	ldhl	sp,	#1
	ld	(hl), a
	C$Scroll.c$424$1_0$268	= .
	.globl	C$Scroll.c$424$1_0$268
;C:/ZGB-2023.0/common/src/Scroll.c:424: if(scroll_target) {
	ld	hl, #_scroll_target + 1
	ld	a, (hl-)
	or	a, (hl)
	jp	Z, 00108$
	C$Scroll.c$425$2_0$269	= .
	.globl	C$Scroll.c$425$2_0$269
;C:/ZGB-2023.0/common/src/Scroll.c:425: if(U_LESS_THAN(scroll_bottom_movement_limit, scroll_target->y - scroll_y)) {
	ld	a, (#_scroll_bottom_movement_limit)
	ldhl	sp,	#9
	ld	(hl), a
	ld	a, (#_scroll_target)
	ldhl	sp,	#2
	ld	(hl), a
	ld	a, (#_scroll_target + 1)
	ldhl	sp,	#3
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x000e
	add	hl, de
	ld	c, l
	ld	b, h
	ld	e, c
	ld	d, b
	ld	a, (de)
	ldhl	sp,	#4
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	ld	hl, #_scroll_y
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ldhl	sp,#4
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl+)
	inc	hl
	ld	d, a
	ld	a, e
	sub	a, c
	ld	e, a
	ld	a, d
	sbc	a, b
	ld	(hl-), a
	ld	(hl), e
	ldhl	sp,	#9
	ld	a, (hl-)
	dec	hl
	dec	hl
	ld	c, a
	ld	b, #0x00
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl+)
	inc	hl
	ld	d, a
	ld	a, c
	sub	a, e
	ld	e, a
	ld	a, b
	sbc	a, d
	ld	(hl-), a
	ld	(hl), e
	push	hl
	inc	hl
	bit	7, (hl)
	pop	hl
	jr	Z, 00104$
	C$Scroll.c$426$3_0$270	= .
	.globl	C$Scroll.c$426$3_0$270
;C:/ZGB-2023.0/common/src/Scroll.c:426: ny = scroll_target->y - scroll_bottom_movement_limit;
	ldhl	sp,#4
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, e
	sub	a, c
	ld	e, a
	ld	a, d
	sbc	a, b
	ldhl	sp,	#1
	ld	(hl-), a
	ld	(hl), e
	jr	00105$
00104$:
	C$Scroll.c$427$2_0$269	= .
	.globl	C$Scroll.c$427$2_0$269
;C:/ZGB-2023.0/common/src/Scroll.c:427: } else if(U_LESS_THAN(scroll_target->y - scroll_y, scroll_top_movement_limit)) {
	ld	hl, #_scroll_top_movement_limit
	ld	c, (hl)
	ld	b, #0x00
	ldhl	sp,#6
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl+)
	inc	hl
	ld	d, a
	ld	a, e
	sub	a, c
	ld	e, a
	ld	a, d
	sbc	a, b
	ld	(hl-), a
	ld	(hl), e
	push	hl
	inc	hl
	bit	7, (hl)
	pop	hl
	jr	Z, 00105$
	C$Scroll.c$428$3_0$271	= .
	.globl	C$Scroll.c$428$3_0$271
;C:/ZGB-2023.0/common/src/Scroll.c:428: ny = scroll_target->y - scroll_top_movement_limit;
	ldhl	sp,#4
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, e
	sub	a, c
	ld	e, a
	ld	a, d
	sbc	a, b
	ldhl	sp,	#1
	ld	(hl-), a
	ld	(hl), e
00105$:
	C$Scroll.c$431$2_0$269	= .
	.globl	C$Scroll.c$431$2_0$269
;C:/ZGB-2023.0/common/src/Scroll.c:431: MoveScroll(scroll_target->x - (SCREENWIDTH >> 1), ny);
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x000c
	add	hl, de
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	a, c
	add	a, #0xb0
	ld	e, a
	ld	a, b
	adc	a, #0xff
	ld	d, a
	pop	bc
	push	bc
	call	_MoveScroll
00108$:
	C$Scroll.c$433$1_0$268	= .
	.globl	C$Scroll.c$433$1_0$268
;C:/ZGB-2023.0/common/src/Scroll.c:433: }
	add	sp, #10
	C$Scroll.c$433$1_0$268	= .
	.globl	C$Scroll.c$433$1_0$268
	XG$RefreshScroll$0$0	= .
	.globl	XG$RefreshScroll$0$0
	ret
	G$MoveScroll$0$0	= .
	.globl	G$MoveScroll$0$0
	C$Scroll.c$435$1_0$273	= .
	.globl	C$Scroll.c$435$1_0$273
;C:/ZGB-2023.0/common/src/Scroll.c:435: void MoveScroll(INT16 x, INT16 y) {
;	---------------------------------
; Function MoveScroll
; ---------------------------------
_MoveScroll::
	add	sp, #-10
	C$Scroll.c$438$1_0$273	= .
	.globl	C$Scroll.c$438$1_0$273
;C:/ZGB-2023.0/common/src/Scroll.c:438: PUSH_BANK(scroll_bank);
	push	bc
	push	de
	ld	a, (#_scroll_bank)
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	pop	de
	pop	bc
	C$Scroll.c$440$1_0$273	= .
	.globl	C$Scroll.c$440$1_0$273
;C:/ZGB-2023.0/common/src/Scroll.c:440: current_column = scroll_x >> 3;
	ld	a, (#_scroll_x)
	ldhl	sp,	#0
	ld	(hl), a
	ld	a, (#_scroll_x + 1)
	ldhl	sp,	#1
	ld	(hl), a
	sra	(hl)
	dec	hl
	rr	(hl)
	inc	hl
	sra	(hl)
	dec	hl
	rr	(hl)
	inc	hl
	sra	(hl)
	dec	hl
	rr	(hl)
	C$Scroll.c$441$1_0$273	= .
	.globl	C$Scroll.c$441$1_0$273
;C:/ZGB-2023.0/common/src/Scroll.c:441: current_row    = scroll_y >> 3;
	ld	a, (#_scroll_y)
	ldhl	sp,	#2
	ld	(hl), a
	ld	a, (#_scroll_y + 1)
	ldhl	sp,	#3
	ld	(hl), a
	sra	(hl)
	dec	hl
	rr	(hl)
	inc	hl
	sra	(hl)
	dec	hl
	rr	(hl)
	inc	hl
	sra	(hl)
	dec	hl
	rr	(hl)
	C$Scroll.c$443$1_0$273	= .
	.globl	C$Scroll.c$443$1_0$273
;C:/ZGB-2023.0/common/src/Scroll.c:443: scroll_x = x;
	ld	hl, #_scroll_x
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
	C$Scroll.c$444$1_0$273	= .
	.globl	C$Scroll.c$444$1_0$273
;C:/ZGB-2023.0/common/src/Scroll.c:444: scroll_y = y;
	ld	hl, #_scroll_y
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	C$Scroll.c$445$1_0$273	= .
	.globl	C$Scroll.c$445$1_0$273
;C:/ZGB-2023.0/common/src/Scroll.c:445: ClampScrollLimits();
	call	_ClampScrollLimits
	C$Scroll.c$447$1_0$273	= .
	.globl	C$Scroll.c$447$1_0$273
;C:/ZGB-2023.0/common/src/Scroll.c:447: new_column     = scroll_x >> 3;
	ld	hl, #_scroll_x
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	sra	b
	rr	c
	sra	b
	rr	c
	sra	b
	rr	c
	C$Scroll.c$448$1_0$273	= .
	.globl	C$Scroll.c$448$1_0$273
;C:/ZGB-2023.0/common/src/Scroll.c:448: new_row        = scroll_y >> 3;
	ld	a, (#_scroll_y)
	ldhl	sp,	#4
	ld	(hl), a
	ld	a, (#_scroll_y + 1)
	ldhl	sp,	#5
	ld	(hl), a
	sra	(hl)
	dec	hl
	rr	(hl)
	inc	hl
	sra	(hl)
	dec	hl
	rr	(hl)
	inc	hl
	sra	(hl)
	dec	hl
	rr	(hl)
	C$Scroll.c$452$1_0$273	= .
	.globl	C$Scroll.c$452$1_0$273
;C:/ZGB-2023.0/common/src/Scroll.c:452: ScrollUpdateColumnWithDelay(new_column - SCREEN_PAD_LEFT + SCREEN_TILE_REFRES_W - 1, new_row - SCREEN_PAD_TOP);
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0001
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ldhl	sp,	#7
	ld	(hl-), a
	ld	(hl), e
	C$Scroll.c$454$1_0$273	= .
	.globl	C$Scroll.c$454$1_0$273
;C:/ZGB-2023.0/common/src/Scroll.c:454: ScrollUpdateColumnWithDelay(new_column - SCREEN_PAD_LEFT, new_row - SCREEN_PAD_TOP);
	ld	de, #0x0001
	ld	a, c
	sub	a, e
	ld	e, a
	ld	a, b
	sbc	a, d
	ldhl	sp,	#9
	ld	(hl-), a
	ld	(hl), e
	C$Scroll.c$450$1_0$273	= .
	.globl	C$Scroll.c$450$1_0$273
;C:/ZGB-2023.0/common/src/Scroll.c:450: if(current_column != new_column) {
	ldhl	sp,	#0
	ld	a, (hl)
	sub	a, c
	jr	NZ, 00159$
	inc	hl
	ld	a, (hl)
	sub	a, b
	jr	Z, 00105$
00159$:
	C$Scroll.c$451$2_0$274	= .
	.globl	C$Scroll.c$451$2_0$274
;C:/ZGB-2023.0/common/src/Scroll.c:451: if(new_column > current_column) {
	ldhl	sp,	#0
	ld	a, (hl+)
	sub	a, c
	ld	a, (hl)
	sbc	a, b
	ld	d, (hl)
	ld	a, b
	bit	7,a
	jr	Z, 00160$
	bit	7, d
	jr	NZ, 00161$
	cp	a, a
	jr	00161$
00160$:
	bit	7, d
	jr	Z, 00161$
	scf
00161$:
	jr	NC, 00102$
	C$Scroll.c$452$3_0$275	= .
	.globl	C$Scroll.c$452$3_0$275
;C:/ZGB-2023.0/common/src/Scroll.c:452: ScrollUpdateColumnWithDelay(new_column - SCREEN_PAD_LEFT + SCREEN_TILE_REFRES_W - 1, new_row - SCREEN_PAD_TOP);
	ld	hl, #0x0015
	add	hl, bc
	ld	e, l
	ld	d, h
	ldhl	sp,	#6
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	call	_ScrollUpdateColumnWithDelay
	jr	00105$
00102$:
	C$Scroll.c$454$3_0$276	= .
	.globl	C$Scroll.c$454$3_0$276
;C:/ZGB-2023.0/common/src/Scroll.c:454: ScrollUpdateColumnWithDelay(new_column - SCREEN_PAD_LEFT, new_row - SCREEN_PAD_TOP);
	ldhl	sp,	#6
	ld	a, (hl+)
	ld	c, a
	ld	a, (hl+)
	ld	b, a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	_ScrollUpdateColumnWithDelay
00105$:
	C$Scroll.c$458$1_0$273	= .
	.globl	C$Scroll.c$458$1_0$273
;C:/ZGB-2023.0/common/src/Scroll.c:458: if(current_row != new_row) {
	ldhl	sp,	#2
	ld	a, (hl+)
	inc	hl
	sub	a, (hl)
	jr	NZ, 00162$
	dec	hl
	ld	a, (hl+)
	inc	hl
	sub	a, (hl)
	jr	Z, 00110$
00162$:
	C$Scroll.c$459$2_0$277	= .
	.globl	C$Scroll.c$459$2_0$277
;C:/ZGB-2023.0/common/src/Scroll.c:459: if(new_row > current_row) {
	ldhl	sp,	#2
	ld	e, l
	ld	d, h
	ldhl	sp,	#4
	ld	a, (de)
	inc	de
	sub	a, (hl)
	inc	hl
	ld	a, (de)
	sbc	a, (hl)
	ld	a, (de)
	ld	d, a
	bit	7, (hl)
	jr	Z, 00163$
	bit	7, d
	jr	NZ, 00164$
	cp	a, a
	jr	00164$
00163$:
	bit	7, d
	jr	Z, 00164$
	scf
00164$:
	jr	NC, 00107$
	C$Scroll.c$460$3_0$278	= .
	.globl	C$Scroll.c$460$3_0$278
;C:/ZGB-2023.0/common/src/Scroll.c:460: ScrollUpdateRowWithDelay(new_column - SCREEN_PAD_LEFT, new_row - SCREEN_PAD_TOP + SCREEN_TILE_REFRES_H - 1);
	ldhl	sp,#4
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0013
	add	hl, de
	ld	c, l
	ld	b, h
	ldhl	sp,	#8
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	_ScrollUpdateRowWithDelay
	jr	00110$
00107$:
	C$Scroll.c$462$3_0$279	= .
	.globl	C$Scroll.c$462$3_0$279
;C:/ZGB-2023.0/common/src/Scroll.c:462: ScrollUpdateRowWithDelay(new_column - SCREEN_PAD_LEFT, new_row - SCREEN_PAD_TOP);
	ldhl	sp,	#6
	ld	a, (hl+)
	ld	c, a
	ld	a, (hl+)
	ld	b, a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	_ScrollUpdateRowWithDelay
00110$:
	C$Scroll.c$466$1_0$273	= .
	.globl	C$Scroll.c$466$1_0$273
;C:/ZGB-2023.0/common/src/Scroll.c:466: if(pending_w_i) {
	ld	a, (#_pending_w_i)
	or	a, a
	jr	Z, 00112$
	C$Scroll.c$467$2_0$280	= .
	.globl	C$Scroll.c$467$2_0$280
;C:/ZGB-2023.0/common/src/Scroll.c:467: ScrollUpdateRowR();
	call	_ScrollUpdateRowR
00112$:
	C$Scroll.c$469$1_0$273	= .
	.globl	C$Scroll.c$469$1_0$273
;C:/ZGB-2023.0/common/src/Scroll.c:469: if(pending_h_i) {
	ld	a, (#_pending_h_i)
	or	a, a
	jr	Z, 00114$
	C$Scroll.c$470$2_0$281	= .
	.globl	C$Scroll.c$470$2_0$281
;C:/ZGB-2023.0/common/src/Scroll.c:470: ScrollUpdateColumnR();
	call	_ScrollUpdateColumnR
00114$:
	C$Scroll.c$472$1_0$273	= .
	.globl	C$Scroll.c$472$1_0$273
;C:/ZGB-2023.0/common/src/Scroll.c:472: POP_BANK;
	call	_PopBank
	C$Scroll.c$473$1_0$273	= .
	.globl	C$Scroll.c$473$1_0$273
;C:/ZGB-2023.0/common/src/Scroll.c:473: }
	add	sp, #10
	C$Scroll.c$473$1_0$273	= .
	.globl	C$Scroll.c$473$1_0$273
	XG$MoveScroll$0$0	= .
	.globl	XG$MoveScroll$0$0
	ret
	G$GetScrollTilePtr$0$0	= .
	.globl	G$GetScrollTilePtr$0$0
	C$Scroll.c$475$1_0$283	= .
	.globl	C$Scroll.c$475$1_0$283
;C:/ZGB-2023.0/common/src/Scroll.c:475: UINT8* GetScrollTilePtr(UINT16 x, UINT16 y) {
;	---------------------------------
; Function GetScrollTilePtr
; ---------------------------------
_GetScrollTilePtr::
	C$Scroll.c$479$1_0$283	= .
	.globl	C$Scroll.c$479$1_0$283
;C:/ZGB-2023.0/common/src/Scroll.c:479: return scroll_map + (scroll_tiles_w * y + x); //TODO: fix this mult!!
	push	de
	ld	hl, #_scroll_tiles_w
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	__mulint
	ld	l, c
;	spillPairReg hl
;	spillPairReg hl
	ld	h, b
;	spillPairReg hl
;	spillPairReg hl
	pop	de
	add	hl, de
	ld	c, l
	ld	b, h
	ld	a, c
	ld	hl, #_scroll_map
	add	a, (hl)
	inc	hl
	ld	c, a
	ld	a, b
	adc	a, (hl)
	ld	b, a
	C$Scroll.c$480$1_0$283	= .
	.globl	C$Scroll.c$480$1_0$283
;C:/ZGB-2023.0/common/src/Scroll.c:480: }
	C$Scroll.c$480$1_0$283	= .
	.globl	C$Scroll.c$480$1_0$283
	XG$GetScrollTilePtr$0$0	= .
	.globl	XG$GetScrollTilePtr$0$0
	ret
	G$GetScrollTile$0$0	= .
	.globl	G$GetScrollTile$0$0
	C$Scroll.c$482$1_0$285	= .
	.globl	C$Scroll.c$482$1_0$285
;C:/ZGB-2023.0/common/src/Scroll.c:482: UINT8 GetScrollTile(UINT16 x, UINT16 y) {
;	---------------------------------
; Function GetScrollTile
; ---------------------------------
_GetScrollTile::
	C$Scroll.c$484$1_0$285	= .
	.globl	C$Scroll.c$484$1_0$285
;C:/ZGB-2023.0/common/src/Scroll.c:484: PUSH_BANK(scroll_bank);
	push	bc
	push	de
	ld	a, (#_scroll_bank)
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	pop	de
	pop	bc
	C$Scroll.c$485$1_0$285	= .
	.globl	C$Scroll.c$485$1_0$285
;C:/ZGB-2023.0/common/src/Scroll.c:485: ret = *GetScrollTilePtr(x, y);
	call	_GetScrollTilePtr
	ld	a, (bc)
	ld	c, a
	C$Scroll.c$486$1_0$285	= .
	.globl	C$Scroll.c$486$1_0$285
;C:/ZGB-2023.0/common/src/Scroll.c:486: POP_BANK;
	push	bc
	call	_PopBank
	pop	bc
	C$Scroll.c$487$1_0$285	= .
	.globl	C$Scroll.c$487$1_0$285
;C:/ZGB-2023.0/common/src/Scroll.c:487: return ret;
	ld	a, c
	C$Scroll.c$488$1_0$285	= .
	.globl	C$Scroll.c$488$1_0$285
;C:/ZGB-2023.0/common/src/Scroll.c:488: }
	C$Scroll.c$488$1_0$285	= .
	.globl	C$Scroll.c$488$1_0$285
	XG$GetScrollTile$0$0	= .
	.globl	XG$GetScrollTile$0$0
	ret
	G$GetMapSize$0$0	= .
	.globl	G$GetMapSize$0$0
	C$Scroll.c$490$1_0$287	= .
	.globl	C$Scroll.c$490$1_0$287
;C:/ZGB-2023.0/common/src/Scroll.c:490: void GetMapSize(UINT8 map_bank, const struct MapInfo* map, UINT8* tiles_w, UINT8* tiles_h)
;	---------------------------------
; Function GetMapSize
; ---------------------------------
_GetMapSize::
	C$Scroll.c$492$1_0$287	= .
	.globl	C$Scroll.c$492$1_0$287
;C:/ZGB-2023.0/common/src/Scroll.c:492: PUSH_BANK(map_bank);
	push	de
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	pop	de
	C$Scroll.c$493$1_0$287	= .
	.globl	C$Scroll.c$493$1_0$287
;C:/ZGB-2023.0/common/src/Scroll.c:493: if(tiles_w) *tiles_w = map->width;
	ldhl	sp,	#3
	ld	a, (hl-)
	or	a, (hl)
	jr	Z, 00102$
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	l, e
;	spillPairReg hl
;	spillPairReg hl
	ld	h, d
;	spillPairReg hl
;	spillPairReg hl
	inc	hl
	inc	hl
	ld	a, (hl)
	ld	(bc), a
00102$:
	C$Scroll.c$494$1_0$287	= .
	.globl	C$Scroll.c$494$1_0$287
;C:/ZGB-2023.0/common/src/Scroll.c:494: if(tiles_h) *tiles_h = map->height;
	ldhl	sp,	#5
	ld	a, (hl-)
	or	a, (hl)
	jr	Z, 00104$
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	inc	de
	inc	de
	inc	de
	ld	a, (de)
	ld	(bc), a
00104$:
	C$Scroll.c$495$1_0$287	= .
	.globl	C$Scroll.c$495$1_0$287
;C:/ZGB-2023.0/common/src/Scroll.c:495: POP_BANK;
	call	_PopBank
	C$Scroll.c$496$1_0$287	= .
	.globl	C$Scroll.c$496$1_0$287
;C:/ZGB-2023.0/common/src/Scroll.c:496: }
	pop	hl
	add	sp, #4
	jp	(hl)
	G$ScrollFindTile$0$0	= .
	.globl	G$ScrollFindTile$0$0
	C$Scroll.c$498$1_0$289	= .
	.globl	C$Scroll.c$498$1_0$289
;C:/ZGB-2023.0/common/src/Scroll.c:498: UINT8 ScrollFindTile(UINT8 map_bank, const struct MapInfo* map, UINT8 tile,
;	---------------------------------
; Function ScrollFindTile
; ---------------------------------
_ScrollFindTile::
	add	sp, #-16
	ldhl	sp,	#12
	ld	(hl), e
	inc	hl
	ld	(hl), d
	C$Scroll.c$502$2_0$289	= .
	.globl	C$Scroll.c$502$2_0$289
;C:/ZGB-2023.0/common/src/Scroll.c:502: UINT16 yt = 0;
	ldhl	sp,	#0
	ld	(hl), #0x00
	inc	hl
	ld	(hl), #0x00
	C$Scroll.c$503$2_0$289	= .
	.globl	C$Scroll.c$503$2_0$289
;C:/ZGB-2023.0/common/src/Scroll.c:503: UINT8 found = 1;
	inc	hl
	ld	(hl), #0x01
	C$Scroll.c$505$1_0$289	= .
	.globl	C$Scroll.c$505$1_0$289
;C:/ZGB-2023.0/common/src/Scroll.c:505: PUSH_BANK(map_bank);
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	C$Scroll.c$506$2_0$290	= .
	.globl	C$Scroll.c$506$2_0$290
;C:/ZGB-2023.0/common/src/Scroll.c:506: for(xt = start_x; xt != start_x + w; ++ xt) {
	ldhl	sp,	#19
	ld	a, (hl)
	ldhl	sp,	#3
	ld	(hl+), a
	ld	(hl), #0x00
	ldhl	sp,#12
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0002
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#7
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#6
	ld	(hl), a
	ldhl	sp,	#3
	ld	a, (hl)
	ldhl	sp,	#14
	ld	(hl+), a
	ld	(hl), #0x00
00110$:
	ldhl	sp,	#19
	ld	a, (hl+)
	inc	hl
	ld	b, #0x00
	ld	e, (hl)
	add	a, e
	ld	c, a
	jr	NC, 00149$
	inc	b
00149$:
	ldhl	sp,	#14
	ld	a, (hl)
	sub	a, c
	jr	NZ, 00150$
	inc	hl
	ld	a, (hl)
	sub	a, b
	jp	Z,00104$
00150$:
	C$Scroll.c$507$4_0$292	= .
	.globl	C$Scroll.c$507$4_0$292
;C:/ZGB-2023.0/common/src/Scroll.c:507: for(yt = start_y; yt != start_y + h; ++ yt) {
	ldhl	sp,	#20
	ld	a, (hl)
	ldhl	sp,	#0
	ld	(hl+), a
	ld	(hl), #0x00
	ldhl	sp,#12
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ldhl	sp,	#7
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl-), a
	dec	hl
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ldhl	sp,	#9
	ld	(hl), a
	pop	de
	push	de
00107$:
	ldhl	sp,	#20
	ld	a, (hl)
	ldhl	sp,	#10
	ld	(hl+), a
	ld	(hl), #0x00
	ldhl	sp,	#22
	ld	c, (hl)
	ld	b, #0x00
	ldhl	sp,	#10
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	ld	c, l
	ld	b, h
	ld	a, c
	sub	a, e
	jr	NZ, 00151$
	ld	a, b
	sub	a, d
	jr	Z, 00111$
00151$:
	C$Scroll.c$508$5_0$293	= .
	.globl	C$Scroll.c$508$5_0$293
;C:/ZGB-2023.0/common/src/Scroll.c:508: if(map->data[map->width * yt + xt] == (UINT16)tile) { //That cast over there is mandatory and gave me a lot of headaches
	ldhl	sp,	#9
	ld	a, (hl+)
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	push	de
	ld	c, e
	ld	b, d
	ld	e, (hl)
	ld	d, #0x00
	call	__mulint
	pop	de
	ldhl	sp,	#14
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	ld	c, l
	ld	b, h
	ldhl	sp,	#7
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	ld	c, l
	ld	b, h
	ld	a, (bc)
	ld	c, a
	ldhl	sp,	#18
	ld	a, (hl)
	sub	a, c
	jr	Z, 00105$
	C$Scroll.c$507$4_0$292	= .
	.globl	C$Scroll.c$507$4_0$292
;C:/ZGB-2023.0/common/src/Scroll.c:507: for(yt = start_y; yt != start_y + h; ++ yt) {
	inc	de
	inc	sp
	inc	sp
	push	de
	jr	00107$
00111$:
	C$Scroll.c$506$2_0$290	= .
	.globl	C$Scroll.c$506$2_0$290
;C:/ZGB-2023.0/common/src/Scroll.c:506: for(xt = start_x; xt != start_x + w; ++ xt) {
	ldhl	sp,	#14
	inc	(hl)
	jr	NZ, 00153$
	inc	hl
	inc	(hl)
00153$:
	ldhl	sp,	#14
	ld	a, (hl)
	ldhl	sp,	#3
	ld	(hl), a
	ldhl	sp,	#15
	ld	a, (hl)
	ldhl	sp,	#4
	ld	(hl), a
	jp	00110$
00104$:
	C$Scroll.c$513$1_0$289	= .
	.globl	C$Scroll.c$513$1_0$289
;C:/ZGB-2023.0/common/src/Scroll.c:513: found = 0;
	ldhl	sp,	#2
	ld	(hl), #0x00
	C$Scroll.c$515$1_0$289	= .
	.globl	C$Scroll.c$515$1_0$289
;C:/ZGB-2023.0/common/src/Scroll.c:515: done:
00105$:
	C$Scroll.c$516$1_0$289	= .
	.globl	C$Scroll.c$516$1_0$289
;C:/ZGB-2023.0/common/src/Scroll.c:516: POP_BANK;
	call	_PopBank
	C$Scroll.c$517$1_0$289	= .
	.globl	C$Scroll.c$517$1_0$289
;C:/ZGB-2023.0/common/src/Scroll.c:517: *x = xt;
	ldhl	sp,	#23
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ldhl	sp,	#3
	ld	a, (hl+)
	ld	(bc), a
	inc	bc
	ld	a, (hl)
	ld	(bc), a
	C$Scroll.c$518$1_0$289	= .
	.globl	C$Scroll.c$518$1_0$289
;C:/ZGB-2023.0/common/src/Scroll.c:518: *y = yt;
	ldhl	sp,	#25
	ld	a, (hl)
	ldhl	sp,	#14
	ld	(hl), a
	ldhl	sp,	#26
	ld	a, (hl)
	ldhl	sp,	#15
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ldhl	sp,	#0
	ld	a, (hl+)
	ld	(de), a
	inc	de
	C$Scroll.c$520$1_0$289	= .
	.globl	C$Scroll.c$520$1_0$289
;C:/ZGB-2023.0/common/src/Scroll.c:520: return found;
	ld	a, (hl+)
	ld	(de), a
	ld	a, (hl)
	C$Scroll.c$521$1_0$289	= .
	.globl	C$Scroll.c$521$1_0$289
;C:/ZGB-2023.0/common/src/Scroll.c:521: }
	add	sp, #16
	pop	hl
	add	sp, #9
	jp	(hl)
	.area _CODE
	.area _INITIALIZER
FScroll$__xinit_scroll_top_movement_limit$0_0$0 == .
__xinit__scroll_top_movement_limit:
	.db #0x1e	; 30
FScroll$__xinit_scroll_bottom_movement_limit$0_0$0 == .
__xinit__scroll_bottom_movement_limit:
	.db #0x64	; 100	'd'
FScroll$__xinit_scroll_map$0_0$0 == .
__xinit__scroll_map:
	.dw #0x0000
FScroll$__xinit_scroll_cmap$0_0$0 == .
__xinit__scroll_cmap:
	.dw #0x0000
FScroll$__xinit_scroll_x$0_0$0 == .
__xinit__scroll_x:
	.dw #0x0000
FScroll$__xinit_scroll_y$0_0$0 == .
__xinit__scroll_y:
	.dw #0x0000
FScroll$__xinit_scroll_x_vblank$0_0$0 == .
__xinit__scroll_x_vblank:
	.db #0x00	; 0
FScroll$__xinit_scroll_y_vblank$0_0$0 == .
__xinit__scroll_y_vblank:
	.db #0x00	; 0
FScroll$__xinit_scroll_target$0_0$0 == .
__xinit__scroll_target:
	.dw #0x0000
FScroll$__xinit_scroll_offset_x$0_0$0 == .
__xinit__scroll_offset_x:
	.db #0x00	; 0
FScroll$__xinit_scroll_offset_y$0_0$0 == .
__xinit__scroll_offset_y:
	.db #0x00	; 0
FScroll$__xinit_pending_h_map$0_0$0 == .
__xinit__pending_h_map:
	.dw #0x0000
FScroll$__xinit_pending_w_map$0_0$0 == .
__xinit__pending_w_map:
	.dw #0x0000
FScroll$__xinit_pending_h_cmap$0_0$0 == .
__xinit__pending_h_cmap:
	.dw #0x0000
FScroll$__xinit_pending_w_cmap$0_0$0 == .
__xinit__pending_w_cmap:
	.dw #0x0000
FScroll$__xinit_last_tile_loaded$0_0$0 == .
__xinit__last_tile_loaded:
	.db #0x00	; 0
FScroll$__xinit_last_bg_pal_loaded$0_0$0 == .
__xinit__last_bg_pal_loaded:
	.db #0x00	; 0
FScroll$__xinit_scroll_h_border$0_0$0 == .
__xinit__scroll_h_border:
	.db #0x00	;  0
FScroll$__xinit_clamp_enabled$0_0$0 == .
__xinit__clamp_enabled:
	.db #0x01	; 1
	.area _CABS (ABS)
