;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module SpriteManager
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _SetBank
	.globl _memset
	.globl _PopBank
	.globl _PushBank
	.globl _RefreshScroll
	.globl _DrawSprite
	.globl _InitSprite
	.globl _ClearOAMs
	.globl _SwapOAMs
	.globl _VectorRemovePos
	.globl _VectorAdd
	.globl _set_sprite_data
	.globl _THIS
	.globl _THIS_IDX
	.globl _last_sprite_pal_loaded
	.globl _last_sprite_loaded
	.globl _sprite_manager_updatables
	.globl _sprite_manager_sprites_pool
	.globl _cachedSprite
	.globl _sprite_manager_removal_check
	.globl _sprite_manager_sprites_poolSTACK
	.globl _sprite_manager_sprites
	.globl _sprite_manager_sprites_mem
	.globl _SpriteManagerReset
	.globl _SpriteManagerLoad
	.globl _SpriteManagerAdd
	.globl _SpriteManagerRemove
	.globl _SpriteManagerRemoveSprite
	.globl _SpriteManagerFlushRemove
	.globl _SpriteManagerUpdate
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
G$sprite_manager_sprites_mem$0_0$0==.
_sprite_manager_sprites_mem::
	.ds 700
G$sprite_manager_sprites$0_0$0==.
_sprite_manager_sprites::
	.ds 40
G$sprite_manager_sprites_poolSTACK$0_0$0==.
_sprite_manager_sprites_poolSTACK::
	.ds 20
G$sprite_manager_removal_check$0_0$0==.
_sprite_manager_removal_check::
	.ds 1
G$cachedSprite$0_0$0==.
_cachedSprite::
	.ds 2
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
G$sprite_manager_sprites_pool$0_0$0==.
_sprite_manager_sprites_pool::
	.ds 2
G$sprite_manager_updatables$0_0$0==.
_sprite_manager_updatables::
	.ds 21
G$last_sprite_loaded$0_0$0==.
_last_sprite_loaded::
	.ds 2
G$last_sprite_pal_loaded$0_0$0==.
_last_sprite_pal_loaded::
	.ds 1
G$THIS_IDX$0_0$0==.
_THIS_IDX::
	.ds 1
G$THIS$0_0$0==.
_THIS::
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
	.area _CODE
	G$SpriteManagerReset$0$0	= .
	.globl	G$SpriteManagerReset$0$0
	C$SpriteManager.c$22$0_0$190	= .
	.globl	C$SpriteManager.c$22$0_0$190
;C:/ZGB-2023.0/common/src/SpriteManager.c:22: void SpriteManagerReset() {
;	---------------------------------
; Function SpriteManagerReset
; ---------------------------------
_SpriteManagerReset::
	add	sp, #-3
	C$SpriteManager.c$25$1_0$190	= .
	.globl	C$SpriteManager.c$25$1_0$190
;C:/ZGB-2023.0/common/src/SpriteManager.c:25: last_sprite_loaded = 128;
	ld	hl, #_last_sprite_loaded
	ld	a, #0x80
	ld	(hl+), a
	xor	a, a
	ld	(hl), a
	C$SpriteManager.c$26$1_0$190	= .
	.globl	C$SpriteManager.c$26$1_0$190
;C:/ZGB-2023.0/common/src/SpriteManager.c:26: last_sprite_pal_loaded = 0;
	ld	hl, #_last_sprite_pal_loaded
	C$SpriteManager.c$29$3_0$192	= .
	.globl	C$SpriteManager.c$29$3_0$192
;C:/ZGB-2023.0/common/src/SpriteManager.c:29: for(i = 0u; i != sprite_manager_updatables[0]; ++ i) {
	ld	(hl), #0x00
	ld	c, (hl)
00104$:
	ld	hl, #_sprite_manager_updatables
	ld	b, (hl)
	ld	a, c
	sub	a, b
	jr	Z, 00101$
	C$SpriteManager.c$30$3_0$192	= .
	.globl	C$SpriteManager.c$30$3_0$192
;C:/ZGB-2023.0/common/src/SpriteManager.c:30: THIS = sprite_manager_sprites[sprite_manager_updatables[i + 1]];
	ld	a, c
	inc	a
	ld	e, a
	rlca
	sbc	a, a
	ld	d, a
	ld	hl, #_sprite_manager_updatables
	add	hl, de
	ld	l, (hl)
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	ld	de, #_sprite_manager_sprites
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
	ld	hl, #_THIS
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	C$SpriteManager.c$31$3_0$192	= .
	.globl	C$SpriteManager.c$31$3_0$192
;C:/ZGB-2023.0/common/src/SpriteManager.c:31: PUSH_BANK(spriteBanks[THIS->type]);
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0013
	add	hl, de
	ld	e, (hl)
	ld	hl, #_spriteBanks
	ld	d, #0x00
	add	hl, de
	ld	a, (hl)
	push	bc
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	pop	bc
	C$SpriteManager.c$32$3_0$192	= .
	.globl	C$SpriteManager.c$32$3_0$192
;C:/ZGB-2023.0/common/src/SpriteManager.c:32: spriteDestroyFuncs[THIS->type]();
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0013
	add	hl, de
	ld	l, (hl)
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	ld	de, #_spriteDestroyFuncs
	add	hl, de
	ld	a, (hl+)
	ld	b, a
	ld	h, (hl)
;	spillPairReg hl
	push	bc
	ld	l, b
;	spillPairReg hl
;	spillPairReg hl
	call	___sdcc_call_hl
	call	_PopBank
	pop	bc
	C$SpriteManager.c$29$2_0$191	= .
	.globl	C$SpriteManager.c$29$2_0$191
;C:/ZGB-2023.0/common/src/SpriteManager.c:29: for(i = 0u; i != sprite_manager_updatables[0]; ++ i) {
	inc	c
	jr	00104$
00101$:
	C$SpriteManager.c$37$1_0$190	= .
	.globl	C$SpriteManager.c$37$1_0$190
;C:/ZGB-2023.0/common/src/SpriteManager.c:37: StackClear(sprite_manager_sprites_pool);
	ld	hl, #_sprite_manager_sprites_pool
	ld	(hl), #<((_sprite_manager_sprites_poolSTACK - 1))
	inc	hl
	ld	(hl), #>((_sprite_manager_sprites_poolSTACK - 1))
	C$SpriteManager.c$38$3_0$194	= .
	.globl	C$SpriteManager.c$38$3_0$194
;C:/ZGB-2023.0/common/src/SpriteManager.c:38: for(i = 0; i != N_SPRITE_MANAGER_SPRITES; ++i) {
	ldhl	sp,	#2
	ld	(hl), #0x00
00106$:
	C$SpriteManager.c$39$3_0$194	= .
	.globl	C$SpriteManager.c$39$3_0$194
;C:/ZGB-2023.0/common/src/SpriteManager.c:39: sprite_manager_sprites[i] = (Sprite*)&sprite_manager_sprites_mem[sizeof(Sprite) * (UINT16)i];
	ldhl	sp,	#2
	ld	a, (hl)
	ld	d, #0x00
	add	a, a
	rl	d
	ld	e, a
	ld	hl, #_sprite_manager_sprites
	add	hl, de
	inc	sp
	inc	sp
	push	hl
	ldhl	sp,	#2
	ld	c, (hl)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, bc
	ld	de, #_sprite_manager_sprites_mem
	add	hl, de
	ld	c, l
	ld	b, h
	pop	hl
	push	hl
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	C$SpriteManager.c$40$3_0$194	= .
	.globl	C$SpriteManager.c$40$3_0$194
;C:/ZGB-2023.0/common/src/SpriteManager.c:40: StackPush(sprite_manager_sprites_pool, i);		
	ld	hl, #_sprite_manager_sprites_pool
	inc	(hl)
	jr	NZ, 00142$
	inc	hl
	inc	(hl)
00142$:
	ld	hl, #_sprite_manager_sprites_pool
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ldhl	sp,	#2
	ld	a, (hl)
	ld	(bc), a
	C$SpriteManager.c$38$2_0$193	= .
	.globl	C$SpriteManager.c$38$2_0$193
;C:/ZGB-2023.0/common/src/SpriteManager.c:38: for(i = 0; i != N_SPRITE_MANAGER_SPRITES; ++i) {
	inc	(hl)
	ld	a, (hl)
	sub	a, #0x14
	jr	NZ, 00106$
	C$SpriteManager.c$42$1_0$190	= .
	.globl	C$SpriteManager.c$42$1_0$190
;C:/ZGB-2023.0/common/src/SpriteManager.c:42: ClearOAMs();
	call	_ClearOAMs
	C$SpriteManager.c$44$1_0$190	= .
	.globl	C$SpriteManager.c$44$1_0$190
;C:/ZGB-2023.0/common/src/SpriteManager.c:44: memset(spriteIdxs, 128, N_SPRITE_TYPES);
	ld	de, #0x0003
	push	de
	xor	a, a
	push	af
	ld	de, #_spriteIdxs
	push	de
	call	_memset
	add	sp, #6
	C$SpriteManager.c$47$1_0$190	= .
	.globl	C$SpriteManager.c$47$1_0$190
;C:/ZGB-2023.0/common/src/SpriteManager.c:47: sprite_manager_updatables[0] = 0;
	ld	hl, #_sprite_manager_updatables
	ld	(hl), #0x00
	C$SpriteManager.c$48$1_0$190	= .
	.globl	C$SpriteManager.c$48$1_0$190
;C:/ZGB-2023.0/common/src/SpriteManager.c:48: sprite_manager_removal_check = 0;
	ld	hl, #_sprite_manager_removal_check
	ld	(hl), #0x00
	C$SpriteManager.c$49$1_0$190	= .
	.globl	C$SpriteManager.c$49$1_0$190
;C:/ZGB-2023.0/common/src/SpriteManager.c:49: }
	add	sp, #3
	C$SpriteManager.c$49$1_0$190	= .
	.globl	C$SpriteManager.c$49$1_0$190
	XG$SpriteManagerReset$0$0	= .
	.globl	XG$SpriteManagerReset$0$0
	ret
	G$SpriteManagerLoad$0$0	= .
	.globl	G$SpriteManagerLoad$0$0
	C$SpriteManager.c$52$1_0$196	= .
	.globl	C$SpriteManager.c$52$1_0$196
;C:/ZGB-2023.0/common/src/SpriteManager.c:52: void SpriteManagerLoad(UINT8 sprite_type) {
;	---------------------------------
; Function SpriteManagerLoad
; ---------------------------------
_SpriteManagerLoad::
	add	sp, #-12
	ldhl	sp,	#11
	ld	(hl), a
	C$SpriteManager.c$56$1_0$196	= .
	.globl	C$SpriteManager.c$56$1_0$196
;C:/ZGB-2023.0/common/src/SpriteManager.c:56: if(spriteIdxs[sprite_type] != 128 || last_sprite_loaded < -127) //Already loaded or no room for this sprite
	ld	bc, #_spriteIdxs+0
	ld	l, (hl)
	ld	h, #0x00
	add	hl, bc
	ld	c, l
	ld	b, h
	ld	a, (bc)
	sub	a, #0x80
	jp	NZ,00107$
	ld	hl, #_last_sprite_loaded
	ld	a, (hl+)
	sub	a, #0x81
	ld	a, (hl)
	sbc	a, #0xff
	ld	d, (hl)
	ld	a, #0xff
	bit	7,a
	jr	Z, 00125$
	bit	7, d
	jr	NZ, 00126$
	cp	a, a
	jr	00126$
00125$:
	bit	7, d
	jr	Z, 00126$
	scf
00126$:
	C$SpriteManager.c$57$1_0$196	= .
	.globl	C$SpriteManager.c$57$1_0$196
;C:/ZGB-2023.0/common/src/SpriteManager.c:57: return;
	jp	C,00107$
	C$SpriteManager.c$59$1_0$196	= .
	.globl	C$SpriteManager.c$59$1_0$196
;C:/ZGB-2023.0/common/src/SpriteManager.c:59: PUSH_BANK(spriteDataBanks[sprite_type])
	ld	de, #_spriteDataBanks+0
	ldhl	sp,	#11
	ld	l, (hl)
	ld	h, #0x00
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
	push	bc
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	pop	bc
	C$SpriteManager.c$61$1_1$197	= .
	.globl	C$SpriteManager.c$61$1_1$197
;C:/ZGB-2023.0/common/src/SpriteManager.c:61: const struct MetaSpriteInfo* data = spriteDatas[sprite_type];
	ldhl	sp,	#11
	ld	l, (hl)
	ld	h, #0x00
	add	hl, hl
	ld	de, #_spriteDatas
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
	ldhl	sp,	#9
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	C$SpriteManager.c$62$1_1$197	= .
	.globl	C$SpriteManager.c$62$1_1$197
;C:/ZGB-2023.0/common/src/SpriteManager.c:62: UINT8 n_tiles = data->num_tiles;
	ldhl	sp,	#9
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	inc	de
	inc	de
	ld	a, (de)
	ldhl	sp,	#0
	ld	(hl), a
	C$SpriteManager.c$65$1_1$197	= .
	.globl	C$SpriteManager.c$65$1_1$197
;C:/ZGB-2023.0/common/src/SpriteManager.c:65: last_sprite_loaded -= n_tiles;
	ld	a, (hl+)
	ld	(hl+), a
	ld	(hl), #0x00
	ld	hl, #_last_sprite_loaded
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ldhl	sp,	#1
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ld	hl, #_last_sprite_loaded + 1
	ld	(hl-), a
	ld	(hl), e
	C$SpriteManager.c$66$1_1$197	= .
	.globl	C$SpriteManager.c$66$1_1$197
;C:/ZGB-2023.0/common/src/SpriteManager.c:66: spriteIdxs[sprite_type] = last_sprite_loaded;
	ld	a, (hl)
	ld	(bc), a
	C$SpriteManager.c$67$1_2$198	= .
	.globl	C$SpriteManager.c$67$1_2$198
;C:/ZGB-2023.0/common/src/SpriteManager.c:67: UINT8 end = last_sprite_loaded + n_tiles;
	ld	a, (hl)
	ldhl	sp,	#0
	ld	c, (hl)
	add	a, c
	ldhl	sp,	#3
	ld	(hl), a
	C$SpriteManager.c$68$1_2$198	= .
	.globl	C$SpriteManager.c$68$1_2$198
;C:/ZGB-2023.0/common/src/SpriteManager.c:68: if((end - 1u) >= (UINT8)last_sprite_loaded) {
	ld	a, (hl+)
	inc	hl
	ld	c, a
	ld	b, #0x00
	ld	de, #0x0001
	ld	a, c
	sub	a, e
	ld	e, a
	ld	a, b
	sbc	a, d
	ld	(hl-), a
	ld	(hl), e
	ld	a, (#_last_sprite_loaded)
	ldhl	sp,	#6
	ld	(hl), a
	ld	a, (hl+)
	ld	(hl+), a
	C$SpriteManager.c$69$1_2$196	= .
	.globl	C$SpriteManager.c$69$1_2$196
;C:/ZGB-2023.0/common/src/SpriteManager.c:69: set_sprite_data(last_sprite_loaded, n_tiles, data->data);
	xor	a, a
	ld	(hl+), a
	ld	a, (hl+)
	ld	c, a
	C$SpriteManager.c$71$1_2$196	= .
	.globl	C$SpriteManager.c$71$1_2$196
;C:/ZGB-2023.0/common/src/SpriteManager.c:71: set_sprite_data(last_sprite_loaded, n_tiles - end, data->data);
	ld	a, (hl-)
	ld	b, a
	inc	bc
	inc	bc
	inc	bc
	ld	e, c
	ld	d, b
	ld	a, (de)
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	C$SpriteManager.c$68$1_2$198	= .
	.globl	C$SpriteManager.c$68$1_2$198
;C:/ZGB-2023.0/common/src/SpriteManager.c:68: if((end - 1u) >= (UINT8)last_sprite_loaded) {
	ldhl	sp,	#4
	ld	e, l
	ld	d, h
	ldhl	sp,	#7
	ld	a, (de)
	inc	de
	sub	a, (hl)
	inc	hl
	ld	a, (de)
	sbc	a, (hl)
	jr	C, 00105$
	C$SpriteManager.c$69$2_2$199	= .
	.globl	C$SpriteManager.c$69$2_2$199
;C:/ZGB-2023.0/common/src/SpriteManager.c:69: set_sprite_data(last_sprite_loaded, n_tiles, data->data);
	ldhl	sp,	#9
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ldhl	sp,	#2
	ld	a, (hl)
	push	af
	inc	sp
	ldhl	sp,	#9
	ld	a, (hl)
	push	af
	inc	sp
	call	_set_sprite_data
	add	sp, #4
	jr	00106$
00105$:
	C$SpriteManager.c$71$2_2$200	= .
	.globl	C$SpriteManager.c$71$2_2$200
;C:/ZGB-2023.0/common/src/SpriteManager.c:71: set_sprite_data(last_sprite_loaded, n_tiles - end, data->data);
	ldhl	sp,	#0
	ld	a, (hl)
	ldhl	sp,	#3
	sub	a, (hl)
	ldhl	sp,	#9
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	push	de
	push	af
	inc	sp
	ldhl	sp,	#9
	ld	a, (hl)
	push	af
	inc	sp
	call	_set_sprite_data
	add	sp, #4
	C$SpriteManager.c$72$2_2$200	= .
	.globl	C$SpriteManager.c$72$2_2$200
;C:/ZGB-2023.0/common/src/SpriteManager.c:72: set_sprite_data(0, end, data->data + ((n_tiles - end) << 4));
	ld	e, c
	ld	d, b
	ld	a, (de)
	ldhl	sp,	#9
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	ldhl	sp,	#3
	ld	a, (hl-)
	dec	hl
	ld	c, a
	ld	b, #0x00
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, e
	sub	a, c
	ld	e, a
	ld	a, d
	sbc	a, b
	ld	b, a
	ld	c, e
	sla	c
	rl	b
	sla	c
	rl	b
	sla	c
	rl	b
	sla	c
	rl	b
	ldhl	sp,	#9
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	push	hl
	ldhl	sp,	#5
	ld	h, (hl)
	ld	l, #0x00
	push	hl
	call	_set_sprite_data
	add	sp, #4
00106$:
	C$SpriteManager.c$91$1_2$198	= .
	.globl	C$SpriteManager.c$91$1_2$198
;C:/ZGB-2023.0/common/src/SpriteManager.c:91: POP_BANK
	call	_PopBank
00107$:
	C$SpriteManager.c$92$1_2$196	= .
	.globl	C$SpriteManager.c$92$1_2$196
;C:/ZGB-2023.0/common/src/SpriteManager.c:92: }
	add	sp, #12
	C$SpriteManager.c$92$1_2$196	= .
	.globl	C$SpriteManager.c$92$1_2$196
	XG$SpriteManagerLoad$0$0	= .
	.globl	XG$SpriteManagerLoad$0$0
	ret
	G$SpriteManagerAdd$0$0	= .
	.globl	G$SpriteManagerAdd$0$0
	C$SpriteManager.c$95$1_2$202	= .
	.globl	C$SpriteManager.c$95$1_2$202
;C:/ZGB-2023.0/common/src/SpriteManager.c:95: Sprite* SpriteManagerAdd(UINT8 sprite_type, UINT16 x, UINT16 y) {
;	---------------------------------
; Function SpriteManagerAdd
; ---------------------------------
_SpriteManagerAdd::
	add	sp, #-11
	ldhl	sp,	#10
	ld	(hl-), a
	dec	hl
	ld	a, e
	ld	(hl+), a
	C$SpriteManager.c$100$1_0$202	= .
	.globl	C$SpriteManager.c$100$1_0$202
;C:/ZGB-2023.0/common/src/SpriteManager.c:100: SpriteManagerLoad(sprite_type);
	ld	a, d
	ld	(hl+), a
	ld	a, (hl)
	call	_SpriteManagerLoad
	C$SpriteManager.c$102$1_0$202	= .
	.globl	C$SpriteManager.c$102$1_0$202
;C:/ZGB-2023.0/common/src/SpriteManager.c:102: sprite_idx = StackPop(sprite_manager_sprites_pool);
	ld	hl, #_sprite_manager_sprites_pool
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	a, (bc)
	ldhl	sp,	#7
	ld	(hl), a
	ld	hl, #_sprite_manager_sprites_pool
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl-)
	ld	d, a
	dec	de
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
	C$SpriteManager.c$103$1_0$202	= .
	.globl	C$SpriteManager.c$103$1_0$202
;C:/ZGB-2023.0/common/src/SpriteManager.c:103: sprite = sprite_manager_sprites[sprite_idx];
	ld	bc, #_sprite_manager_sprites+0
	ldhl	sp,	#7
	ld	e, (hl)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, bc
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	C$SpriteManager.c$104$1_0$202	= .
	.globl	C$SpriteManager.c$104$1_0$202
;C:/ZGB-2023.0/common/src/SpriteManager.c:104: sprite->type = sprite_type;
	ld	hl, #0x0013
	add	hl, bc
	inc	sp
	inc	sp
	ld	e, l
	ld	d, h
	push	de
	ldhl	sp,	#10
	ld	a, (hl)
	ld	(de), a
	C$SpriteManager.c$105$1_0$202	= .
	.globl	C$SpriteManager.c$105$1_0$202
;C:/ZGB-2023.0/common/src/SpriteManager.c:105: sprite->marked_for_removal = 0;
	ld	hl, #0x0014
	add	hl, bc
	ld	(hl), #0x00
	C$SpriteManager.c$106$1_0$202	= .
	.globl	C$SpriteManager.c$106$1_0$202
;C:/ZGB-2023.0/common/src/SpriteManager.c:106: sprite->lim_x = 32u;
	ld	hl, #0x0015
	add	hl, bc
	ld	a, #0x20
	ld	(hl+), a
	ld	(hl), #0x00
	C$SpriteManager.c$107$1_0$202	= .
	.globl	C$SpriteManager.c$107$1_0$202
;C:/ZGB-2023.0/common/src/SpriteManager.c:107: sprite->lim_y = 32u;
	ld	hl, #0x0017
	add	hl, bc
	ld	a, #0x20
	ld	(hl+), a
	ld	(hl), #0x00
	C$SpriteManager.c$108$1_0$202	= .
	.globl	C$SpriteManager.c$108$1_0$202
;C:/ZGB-2023.0/common/src/SpriteManager.c:108: sprite->mirror = NO_MIRROR;
	ld	hl, #0x0010
	add	hl, bc
	ld	(hl), #0x00
	C$SpriteManager.c$110$1_0$202	= .
	.globl	C$SpriteManager.c$110$1_0$202
;C:/ZGB-2023.0/common/src/SpriteManager.c:110: VectorAdd(sprite_manager_updatables, sprite_idx);
	push	bc
	ldhl	sp,	#9
	ld	a, (hl)
	ld	de, #_sprite_manager_updatables
	call	_VectorAdd
	pop	bc
	C$SpriteManager.c$112$1_0$202	= .
	.globl	C$SpriteManager.c$112$1_0$202
;C:/ZGB-2023.0/common/src/SpriteManager.c:112: InitSprite(sprite, sprite_type);
	push	bc
	ldhl	sp,	#12
	ld	a, (hl)
	ld	e, c
	ld	d, b
	call	_InitSprite
	pop	bc
	C$SpriteManager.c$113$1_0$202	= .
	.globl	C$SpriteManager.c$113$1_0$202
;C:/ZGB-2023.0/common/src/SpriteManager.c:113: sprite->x = x;
	ld	hl, #0x000c
	add	hl, bc
	ld	e, l
	ld	d, h
	ldhl	sp,	#8
	ld	a, (hl+)
	ld	(de), a
	inc	de
	ld	a, (hl)
	ld	(de), a
	C$SpriteManager.c$114$1_0$202	= .
	.globl	C$SpriteManager.c$114$1_0$202
;C:/ZGB-2023.0/common/src/SpriteManager.c:114: sprite->y = y;
	ld	hl, #0x000e
	add	hl, bc
	ld	e, l
	ld	d, h
	ldhl	sp,	#13
	ld	a, (hl+)
	ld	(de), a
	inc	de
	ld	a, (hl)
	ld	(de), a
	C$SpriteManager.c$115$1_0$202	= .
	.globl	C$SpriteManager.c$115$1_0$202
;C:/ZGB-2023.0/common/src/SpriteManager.c:115: sprite->unique_id = SPRITE_UNIQUE_ID(x >> 3, (y + sprite->coll_h - 1) >> 3);
	ld	hl, #0x0019
	add	hl, bc
	push	hl
	ld	a, l
	ldhl	sp,	#4
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#3
	ld	(hl), a
	ldhl	sp,#8
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	srl	d
	rr	e
	srl	d
	rr	e
	srl	d
	rr	e
	ldhl	sp,	#4
	ld	a, e
	ld	(hl+), a
	ld	(hl), #0x00
	ld	hl, #0x0012
	add	hl, bc
	ld	e, (hl)
	ld	d, #0x00
	ldhl	sp,	#13
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, de
	ld	e, l
	ld	d, h
	dec	de
	srl	d
	rr	e
	srl	d
	rr	e
	srl	d
	rr	e
	ldhl	sp,	#4
	ld	a, (hl+)
	inc	hl
	ld	(hl+), a
	ld	(hl), e
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ldhl	sp,	#6
	ld	a, (hl+)
	ld	(de), a
	inc	de
	ld	a, (hl)
	ld	(de), a
	C$SpriteManager.c$118$1_0$202	= .
	.globl	C$SpriteManager.c$118$1_0$202
;C:/ZGB-2023.0/common/src/SpriteManager.c:118: cachedSprite = THIS;
	ld	a, (#_THIS)
	ld	(#_cachedSprite),a
	ld	a, (#_THIS + 1)
	ld	(#_cachedSprite + 1),a
	C$SpriteManager.c$119$1_0$202	= .
	.globl	C$SpriteManager.c$119$1_0$202
;C:/ZGB-2023.0/common/src/SpriteManager.c:119: spriteIdxTmp = THIS_IDX;
	ld	a, (#_THIS_IDX)
	ldhl	sp,	#7
	ld	(hl), a
	C$SpriteManager.c$120$1_0$202	= .
	.globl	C$SpriteManager.c$120$1_0$202
;C:/ZGB-2023.0/common/src/SpriteManager.c:120: THIS = sprite;
	ld	hl, #_THIS
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	C$SpriteManager.c$121$1_0$202	= .
	.globl	C$SpriteManager.c$121$1_0$202
;C:/ZGB-2023.0/common/src/SpriteManager.c:121: THIS_IDX = sprite_manager_updatables[0] - 1;
	ld	a, (#_sprite_manager_updatables + 0)
	dec	a
	ld	(#_THIS_IDX),a
	C$SpriteManager.c$122$1_0$202	= .
	.globl	C$SpriteManager.c$122$1_0$202
;C:/ZGB-2023.0/common/src/SpriteManager.c:122: PUSH_BANK(spriteBanks[sprite->type]);
	pop	de
	push	de
	ld	a, (de)
	add	a, #<(_spriteBanks)
	ld	e, a
	ld	a, #0x00
	adc	a, #>(_spriteBanks)
	ld	d, a
	ld	a, (de)
	push	bc
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	pop	bc
	C$SpriteManager.c$123$1_0$202	= .
	.globl	C$SpriteManager.c$123$1_0$202
;C:/ZGB-2023.0/common/src/SpriteManager.c:123: spriteStartFuncs[sprite->type]();
	pop	de
	push	de
	ld	a, (de)
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	ld	l, a
	add	hl, hl
	ld	de, #_spriteStartFuncs
	add	hl, de
	ld	a,	(hl+)
	ld	h, (hl)
;	spillPairReg hl
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	push	bc
	call	___sdcc_call_hl
	call	_PopBank
	pop	bc
	C$SpriteManager.c$126$1_0$202	= .
	.globl	C$SpriteManager.c$126$1_0$202
;C:/ZGB-2023.0/common/src/SpriteManager.c:126: THIS = cachedSprite;
	ld	a, (#_cachedSprite)
	ld	(#_THIS),a
	ld	a, (#_cachedSprite + 1)
	ld	(#_THIS + 1),a
	C$SpriteManager.c$127$1_0$202	= .
	.globl	C$SpriteManager.c$127$1_0$202
;C:/ZGB-2023.0/common/src/SpriteManager.c:127: THIS_IDX = spriteIdxTmp;
	ldhl	sp,	#7
	ld	a, (hl)
	ld	(#_THIS_IDX),a
	C$SpriteManager.c$128$1_0$202	= .
	.globl	C$SpriteManager.c$128$1_0$202
;C:/ZGB-2023.0/common/src/SpriteManager.c:128: return sprite;
	C$SpriteManager.c$129$1_0$202	= .
	.globl	C$SpriteManager.c$129$1_0$202
;C:/ZGB-2023.0/common/src/SpriteManager.c:129: }
	add	sp, #11
	pop	hl
	pop	af
	jp	(hl)
	G$SpriteManagerRemove$0$0	= .
	.globl	G$SpriteManagerRemove$0$0
	C$SpriteManager.c$131$1_0$204	= .
	.globl	C$SpriteManager.c$131$1_0$204
;C:/ZGB-2023.0/common/src/SpriteManager.c:131: void SpriteManagerRemove(int idx) {
;	---------------------------------
; Function SpriteManagerRemove
; ---------------------------------
_SpriteManagerRemove::
	C$SpriteManager.c$132$1_0$204	= .
	.globl	C$SpriteManager.c$132$1_0$204
;C:/ZGB-2023.0/common/src/SpriteManager.c:132: sprite_manager_removal_check = 1;
	ld	hl, #_sprite_manager_removal_check
	ld	(hl), #0x01
	C$SpriteManager.c$133$1_0$204	= .
	.globl	C$SpriteManager.c$133$1_0$204
;C:/ZGB-2023.0/common/src/SpriteManager.c:133: sprite_manager_sprites[sprite_manager_updatables[idx + 1]]->marked_for_removal = 1;
	ld	bc, #_sprite_manager_sprites+0
	inc	e
	ld	a, e
	rlca
	sbc	a, a
	ld	d, a
	ld	hl, #_sprite_manager_updatables
	add	hl, de
	ld	l, (hl)
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, bc
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #0x0014
	add	hl, bc
	ld	(hl), #0x01
	C$SpriteManager.c$134$1_0$204	= .
	.globl	C$SpriteManager.c$134$1_0$204
;C:/ZGB-2023.0/common/src/SpriteManager.c:134: }
	C$SpriteManager.c$134$1_0$204	= .
	.globl	C$SpriteManager.c$134$1_0$204
	XG$SpriteManagerRemove$0$0	= .
	.globl	XG$SpriteManagerRemove$0$0
	ret
	G$SpriteManagerRemoveSprite$0$0	= .
	.globl	G$SpriteManagerRemoveSprite$0$0
	C$SpriteManager.c$136$1_0$207	= .
	.globl	C$SpriteManager.c$136$1_0$207
;C:/ZGB-2023.0/common/src/SpriteManager.c:136: void SpriteManagerRemoveSprite(Sprite* sprite) {
;	---------------------------------
; Function SpriteManagerRemoveSprite
; ---------------------------------
_SpriteManagerRemoveSprite::
	add	sp, #-4
	ldhl	sp,	#2
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
	C$SpriteManager.c$139$2_0$207	= .
	.globl	C$SpriteManager.c$139$2_0$207
;C:/ZGB-2023.0/common/src/SpriteManager.c:139: for(i = 0u; i != sprite_manager_updatables[0]; ++i) {
	ld	bc, #0x0
00105$:
	ld	hl, #_sprite_manager_updatables
	ld	l, (hl)
;	spillPairReg hl
	C$SpriteManager.c$140$3_0$208	= .
	.globl	C$SpriteManager.c$140$3_0$208
;C:/ZGB-2023.0/common/src/SpriteManager.c:140: s = sprite_manager_sprites[sprite_manager_updatables[i + 1]];
	ld	a,b
	cp	a,l
	jr	Z, 00107$
	inc	a
	ld	e, a
	rlca
	sbc	a, a
	ld	d, a
	ld	hl, #_sprite_manager_updatables
	add	hl, de
	ld	l, (hl)
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	ld	de, #_sprite_manager_sprites
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
	ldhl	sp,	#0
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	C$SpriteManager.c$141$3_0$208	= .
	.globl	C$SpriteManager.c$141$3_0$208
;C:/ZGB-2023.0/common/src/SpriteManager.c:141: if(s == sprite) {
	ldhl	sp,	#2
	ld	a, (hl-)
	dec	hl
	sub	a, (hl)
	jr	NZ, 00106$
	ldhl	sp,	#3
	ld	a, (hl-)
	dec	hl
	C$SpriteManager.c$142$4_0$209	= .
	.globl	C$SpriteManager.c$142$4_0$209
;C:/ZGB-2023.0/common/src/SpriteManager.c:142: SpriteManagerRemove(i);
	sub	a,(hl)
	jr	NZ, 00106$
	ld	d,a
	ld	e, c
	call	_SpriteManagerRemove
	C$SpriteManager.c$143$4_0$209	= .
	.globl	C$SpriteManager.c$143$4_0$209
;C:/ZGB-2023.0/common/src/SpriteManager.c:143: break;
	jr	00107$
00106$:
	C$SpriteManager.c$139$2_0$207	= .
	.globl	C$SpriteManager.c$139$2_0$207
;C:/ZGB-2023.0/common/src/SpriteManager.c:139: for(i = 0u; i != sprite_manager_updatables[0]; ++i) {
	inc	b
	ld	c, b
	jr	00105$
00107$:
	C$SpriteManager.c$146$2_0$207	= .
	.globl	C$SpriteManager.c$146$2_0$207
;C:/ZGB-2023.0/common/src/SpriteManager.c:146: }
	add	sp, #4
	C$SpriteManager.c$146$2_0$207	= .
	.globl	C$SpriteManager.c$146$2_0$207
	XG$SpriteManagerRemoveSprite$0$0	= .
	.globl	XG$SpriteManagerRemoveSprite$0$0
	ret
	G$SpriteManagerFlushRemove$0$0	= .
	.globl	G$SpriteManagerFlushRemove$0$0
	C$SpriteManager.c$148$2_0$210	= .
	.globl	C$SpriteManager.c$148$2_0$210
;C:/ZGB-2023.0/common/src/SpriteManager.c:148: void SpriteManagerFlushRemove() {
;	---------------------------------
; Function SpriteManagerFlushRemove
; ---------------------------------
_SpriteManagerFlushRemove::
	dec	sp
	dec	sp
	C$SpriteManager.c$150$2_0$211	= .
	.globl	C$SpriteManager.c$150$2_0$211
;C:/ZGB-2023.0/common/src/SpriteManager.c:150: for(THIS_IDX = sprite_manager_updatables[0] - 1u; (UINT8)(THIS_IDX + 1u) != 0u; THIS_IDX --) {
	ld	a, (#_sprite_manager_updatables + 0)
	dec	a
	ld	(#_THIS_IDX),a
00105$:
	ld	hl, #_THIS_IDX
	ld	c, (hl)
	inc	c
	ld	a, c
	jp	Z, 00103$
	C$SpriteManager.c$151$3_0$212	= .
	.globl	C$SpriteManager.c$151$3_0$212
;C:/ZGB-2023.0/common/src/SpriteManager.c:151: THIS = sprite_manager_sprites[sprite_manager_updatables[THIS_IDX + 1u]];
	ld	e, c
	ld	d, #0x00
	ld	hl, #_sprite_manager_updatables
	add	hl, de
	inc	sp
	inc	sp
	ld	e, l
	ld	d, h
	push	de
	ld	a, (de)
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	ld	l, a
	add	hl, hl
	ld	de, #_sprite_manager_sprites
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
	ld	hl, #_THIS
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	C$SpriteManager.c$152$3_0$212	= .
	.globl	C$SpriteManager.c$152$3_0$212
;C:/ZGB-2023.0/common/src/SpriteManager.c:152: if(THIS->marked_for_removal) {
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #0x0014
	add	hl, bc
	ld	a, (hl)
	or	a, a
	jr	Z, 00106$
	C$SpriteManager.c$153$4_0$213	= .
	.globl	C$SpriteManager.c$153$4_0$213
;C:/ZGB-2023.0/common/src/SpriteManager.c:153: StackPush(sprite_manager_sprites_pool, sprite_manager_updatables[THIS_IDX + 1u]);
	ld	hl, #_sprite_manager_sprites_pool
	inc	(hl)
	jr	NZ, 00130$
	inc	hl
	inc	(hl)
00130$:
	ld	hl, #_sprite_manager_sprites_pool
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	pop	de
	push	de
	ld	a, (de)
	ld	(bc), a
	C$SpriteManager.c$154$4_0$213	= .
	.globl	C$SpriteManager.c$154$4_0$213
;C:/ZGB-2023.0/common/src/SpriteManager.c:154: VectorRemovePos(sprite_manager_updatables, THIS_IDX);
	ld	a, (#_THIS_IDX)
	ld	de, #_sprite_manager_updatables
	call	_VectorRemovePos
	C$SpriteManager.c$156$4_0$213	= .
	.globl	C$SpriteManager.c$156$4_0$213
;C:/ZGB-2023.0/common/src/SpriteManager.c:156: PUSH_BANK(spriteBanks[THIS->type]);
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #0x0013
	add	hl, bc
	ld	c, (hl)
	ld	hl, #_spriteBanks
	ld	b, #0x00
	add	hl, bc
	ld	a, (hl)
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	C$SpriteManager.c$157$4_0$213	= .
	.globl	C$SpriteManager.c$157$4_0$213
;C:/ZGB-2023.0/common/src/SpriteManager.c:157: spriteDestroyFuncs[THIS->type]();
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #0x0013
	add	hl, bc
	ld	l, (hl)
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	ld	de, #_spriteDestroyFuncs
	add	hl, de
	ld	a,	(hl+)
	ld	h, (hl)
;	spillPairReg hl
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	call	___sdcc_call_hl
	C$SpriteManager.c$158$4_0$213	= .
	.globl	C$SpriteManager.c$158$4_0$213
;C:/ZGB-2023.0/common/src/SpriteManager.c:158: POP_BANK;
	call	_PopBank
00106$:
	C$SpriteManager.c$150$2_0$211	= .
	.globl	C$SpriteManager.c$150$2_0$211
;C:/ZGB-2023.0/common/src/SpriteManager.c:150: for(THIS_IDX = sprite_manager_updatables[0] - 1u; (UINT8)(THIS_IDX + 1u) != 0u; THIS_IDX --) {
	ld	hl, #_THIS_IDX
	dec	(hl)
	jp	00105$
00103$:
	C$SpriteManager.c$161$1_0$210	= .
	.globl	C$SpriteManager.c$161$1_0$210
;C:/ZGB-2023.0/common/src/SpriteManager.c:161: sprite_manager_removal_check = 0;
	ld	hl, #_sprite_manager_removal_check
	ld	(hl), #0x00
	C$SpriteManager.c$162$1_0$210	= .
	.globl	C$SpriteManager.c$162$1_0$210
;C:/ZGB-2023.0/common/src/SpriteManager.c:162: }
	inc	sp
	inc	sp
	C$SpriteManager.c$162$1_0$210	= .
	.globl	C$SpriteManager.c$162$1_0$210
	XG$SpriteManagerFlushRemove$0$0	= .
	.globl	XG$SpriteManagerFlushRemove$0$0
	ret
	G$SetBank$0$0	= .
	.globl	G$SetBank$0$0
	C$SpriteManager.c$164$1_0$215	= .
	.globl	C$SpriteManager.c$164$1_0$215
;C:/ZGB-2023.0/common/src/SpriteManager.c:164: void SetBank(UINT8 bank) OLDCALL
;	---------------------------------
; Function SetBank
; ---------------------------------
_SetBank::
	C$SpriteManager.c$174$1_0$215	= .
	.globl	C$SpriteManager.c$174$1_0$215
;C:/ZGB-2023.0/common/src/SpriteManager.c:174: __endasm;
	ldhl	sp, #2
	ld	a, (hl)
	ld	(#__current_bank), a
	ld	(#0x2000), a
	C$SpriteManager.c$175$1_0$215	= .
	.globl	C$SpriteManager.c$175$1_0$215
;C:/ZGB-2023.0/common/src/SpriteManager.c:175: }
	C$SpriteManager.c$175$1_0$215	= .
	.globl	C$SpriteManager.c$175$1_0$215
	XG$SetBank$0$0	= .
	.globl	XG$SetBank$0$0
	ret
	G$SpriteManagerUpdate$0$0	= .
	.globl	G$SpriteManagerUpdate$0$0
	C$SpriteManager.c$182$1_0$216	= .
	.globl	C$SpriteManager.c$182$1_0$216
;C:/ZGB-2023.0/common/src/SpriteManager.c:182: void SpriteManagerUpdate() {
;	---------------------------------
; Function SpriteManagerUpdate
; ---------------------------------
_SpriteManagerUpdate::
	dec	sp
	dec	sp
	C$SpriteManager.c$183$2_0$217	= .
	.globl	C$SpriteManager.c$183$2_0$217
;C:/ZGB-2023.0/common/src/SpriteManager.c:183: SPRITEMANAGER_ITERATE(THIS_IDX, THIS) {
	ld	hl, #_THIS_IDX
	ld	(hl), #0x00
	ld	a, (#(_sprite_manager_updatables + 1) + 0)
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	ld	de, #_sprite_manager_sprites
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
	ld	hl, #_THIS
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
00109$:
	ld	hl, #_sprite_manager_updatables
	ld	c, (hl)
	ld	a, (#_THIS_IDX)
	sub	a, c
	jp	Z,00105$
	C$SpriteManager.c$184$1_0$216	= .
	.globl	C$SpriteManager.c$184$1_0$216
;C:/ZGB-2023.0/common/src/SpriteManager.c:184: if(!THIS->marked_for_removal) {
	ld	a, (#_THIS)
	ldhl	sp,	#0
	ld	(hl), a
	ld	a, (#_THIS + 1)
	ldhl	sp,	#1
	ld	(hl), a
	pop	de
	push	de
	ld	hl, #0x0014
	add	hl, de
	ld	c, l
	ld	b, h
	ld	a, (bc)
	or	a, a
	jr	NZ, 00110$
	C$SpriteManager.c$186$4_0$219	= .
	.globl	C$SpriteManager.c$186$4_0$219
;C:/ZGB-2023.0/common/src/SpriteManager.c:186: SetBank(spriteBanks[THIS->type]);
	pop	de
	push	de
	ld	hl, #0x0013
	add	hl, de
	ld	c, l
	ld	b, h
	ld	a, (bc)
	ld	c, a
	ld	hl, #_spriteBanks
	ld	b, #0x00
	add	hl, bc
	ld	a, (hl)
	push	af
	inc	sp
	call	_SetBank
	inc	sp
	C$SpriteManager.c$188$4_0$219	= .
	.globl	C$SpriteManager.c$188$4_0$219
;C:/ZGB-2023.0/common/src/SpriteManager.c:188: spriteUpdateFuncs[THIS->type]();
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #0x0013
	add	hl, bc
	ld	l, (hl)
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	ld	de, #_spriteUpdateFuncs
	add	hl, de
	ld	a, (hl+)
	ld	c, a
	ld	h, (hl)
;	spillPairReg hl
	ld	l, c
;	spillPairReg hl
;	spillPairReg hl
	call	___sdcc_call_hl
	C$SpriteManager.c$190$4_0$219	= .
	.globl	C$SpriteManager.c$190$4_0$219
;C:/ZGB-2023.0/common/src/SpriteManager.c:190: if(THIS == scroll_target)
	ld	a, (#_THIS)
	ld	hl, #_scroll_target
	sub	a, (hl)
	jr	NZ, 00102$
	ld	a, (#_THIS + 1)
	ld	hl, #_scroll_target + 1
	sub	a, (hl)
	jr	NZ, 00102$
	C$SpriteManager.c$191$4_0$219	= .
	.globl	C$SpriteManager.c$191$4_0$219
;C:/ZGB-2023.0/common/src/SpriteManager.c:191: RefreshScroll();
	call	_RefreshScroll
00102$:
	C$SpriteManager.c$193$4_0$219	= .
	.globl	C$SpriteManager.c$193$4_0$219
;C:/ZGB-2023.0/common/src/SpriteManager.c:193: DrawSprite(); //this needs to be done using the sprite bank because the animation array is stored there
	call	_DrawSprite
00110$:
	C$SpriteManager.c$183$2_0$217	= .
	.globl	C$SpriteManager.c$183$2_0$217
;C:/ZGB-2023.0/common/src/SpriteManager.c:183: SPRITEMANAGER_ITERATE(THIS_IDX, THIS) {
	ld	hl, #_THIS_IDX
	inc	(hl)
	ld	c, (hl)
	inc	c
	ld	hl, #_sprite_manager_updatables
	ld	b, #0x00
	add	hl, bc
	ld	l, (hl)
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	ld	de, #_sprite_manager_sprites
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
	ld	hl, #_THIS
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	jp	00109$
00105$:
	C$SpriteManager.c$197$1_0$216	= .
	.globl	C$SpriteManager.c$197$1_0$216
;C:/ZGB-2023.0/common/src/SpriteManager.c:197: SwapOAMs();
	call	_SwapOAMs
	C$SpriteManager.c$199$1_0$216	= .
	.globl	C$SpriteManager.c$199$1_0$216
;C:/ZGB-2023.0/common/src/SpriteManager.c:199: if(sprite_manager_removal_check) {
	ld	hl, #_sprite_manager_removal_check
	ld	a, (hl)
	or	a, a
	jr	Z, 00111$
	C$SpriteManager.c$200$2_0$220	= .
	.globl	C$SpriteManager.c$200$2_0$220
;C:/ZGB-2023.0/common/src/SpriteManager.c:200: SpriteManagerFlushRemove();
	inc	sp
	inc	sp
	jp	_SpriteManagerFlushRemove
00111$:
	C$SpriteManager.c$202$1_0$216	= .
	.globl	C$SpriteManager.c$202$1_0$216
;C:/ZGB-2023.0/common/src/SpriteManager.c:202: }
	inc	sp
	inc	sp
	C$SpriteManager.c$202$1_0$216	= .
	.globl	C$SpriteManager.c$202$1_0$216
	XG$SpriteManagerUpdate$0$0	= .
	.globl	XG$SpriteManagerUpdate$0$0
	ret
	.area _CODE
	.area _INITIALIZER
FSpriteManager$__xinit_sprite_manager_sprites_pool$0_0$0 == .
__xinit__sprite_manager_sprites_pool:
	.dw (_sprite_manager_sprites_poolSTACK - 1)
FSpriteManager$__xinit_sprite_manager_updatables$0_0$0 == .
__xinit__sprite_manager_updatables:
	.db #0x00	; 0
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
FSpriteManager$__xinit_last_sprite_loaded$0_0$0 == .
__xinit__last_sprite_loaded:
	.dw #0x0000
FSpriteManager$__xinit_last_sprite_pal_loaded$0_0$0 == .
__xinit__last_sprite_pal_loaded:
	.db #0x00	; 0
FSpriteManager$__xinit_THIS_IDX$0_0$0 == .
__xinit__THIS_IDX:
	.db #0x00	; 0
FSpriteManager$__xinit_THIS$0_0$0 == .
__xinit__THIS:
	.dw #0x0000
	.area _CABS (ABS)
