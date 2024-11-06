;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module Sprite
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _update_attr
	.globl _SpriteManagerRemove
	.globl _PopBank
	.globl _PushBank
	.globl _tile_coll
	.globl _SetFrame
	.globl _InitSprite
	.globl _SetSpriteAnim
	.globl _DrawSprite
	.globl _TranslateSprite
	.globl _CheckCollision
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
G$tile_coll$0_0$0==.
_tile_coll::
	.ds 2
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
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
	G$update_attr$0$0	= .
	.globl	G$update_attr$0$0
	C$Sprite.c$53$1_0$186	= .
	.globl	C$Sprite.c$53$1_0$186
;C:/ZGB-2023.0/common/src/Sprite.c:53: void update_attr(uint8_t start, uint8_t count, uint8_t attr) __nonbanked __naked OLDCALL {
;	---------------------------------
; Function update_attr
; ---------------------------------
_update_attr::
	C$Sprite.c$80$1_0$186	= .
	.globl	C$Sprite.c$80$1_0$186
;C:/ZGB-2023.0/common/src/Sprite.c:80: __endasm;
	ldhl	sp, #4
	ld	a, (hl-)
	ld	d, a
	ld	a, (hl-)
	or	a
	ret	z
	ld	e, a
	ld	a, (hl)
	add	a
	add	a
	add	#3
	ld	l, a
	ld	a, (___render_shadow_OAM)
	ld	h, a
	ld	bc, #4
1$:
	ld	a, d
	add	(hl)
	ld	(hl), a
	add	hl, bc
	dec	e
	jr	nz, 1$
	ret
	C$Sprite.c$81$1_0$186	= .
	.globl	C$Sprite.c$81$1_0$186
;C:/ZGB-2023.0/common/src/Sprite.c:81: }
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
	G$SetFrame$0$0	= .
	.globl	G$SetFrame$0$0
	C$Sprite.c$8$0_0$179	= .
	.globl	C$Sprite.c$8$0_0$179
;C:/ZGB-2023.0/common/src/Sprite.c:8: void SetFrame(Sprite* sprite, UINT8 frame)
;	---------------------------------
; Function SetFrame
; ---------------------------------
_SetFrame::
	add	sp, #-5
	ldhl	sp,	#3
	ld	(hl), e
	inc	hl
	ld	(hl), d
	dec	hl
	dec	hl
	C$Sprite.c$10$1_0$179	= .
	.globl	C$Sprite.c$10$1_0$179
;C:/ZGB-2023.0/common/src/Sprite.c:10: PUSH_BANK(sprite->mt_sprite_bank);
	ld	(hl+), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	C$Sprite.c$11$1_0$179	= .
	.globl	C$Sprite.c$11$1_0$179
;C:/ZGB-2023.0/common/src/Sprite.c:11: sprite->mt_sprite = sprite->mt_sprite_info->metasprites[frame];
	ldhl	sp,#3
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x000a
	add	hl, de
	inc	sp
	inc	sp
	push	hl
	ldhl	sp,	#3
	ld	a, (hl+)
	ld	h, (hl)
;	spillPairReg hl
;	spillPairReg hl
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	inc	hl
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #0x0009
	add	hl, bc
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ldhl	sp,	#2
	ld	l, (hl)
	ld	h, #0x00
	add	hl, hl
	add	hl, bc
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	pop	hl
	push	hl
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	C$Sprite.c$12$1_0$179	= .
	.globl	C$Sprite.c$12$1_0$179
;C:/ZGB-2023.0/common/src/Sprite.c:12: POP_BANK;
	call	_PopBank
	C$Sprite.c$13$1_0$179	= .
	.globl	C$Sprite.c$13$1_0$179
;C:/ZGB-2023.0/common/src/Sprite.c:13: sprite->anim_frame = frame; //anim_frame contains the animation frame if anim_data is assigned or the metasprite index otherwise
	ldhl	sp,#3
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0009
	add	hl, de
	ld	c, l
	ld	b, h
	ldhl	sp,	#2
	ld	a, (hl)
	ld	(bc), a
	C$Sprite.c$14$1_0$179	= .
	.globl	C$Sprite.c$14$1_0$179
;C:/ZGB-2023.0/common/src/Sprite.c:14: }
	add	sp, #5
	C$Sprite.c$14$1_0$179	= .
	.globl	C$Sprite.c$14$1_0$179
	XG$SetFrame$0$0	= .
	.globl	XG$SetFrame$0$0
	ret
	G$InitSprite$0$0	= .
	.globl	G$InitSprite$0$0
	C$Sprite.c$16$1_0$181	= .
	.globl	C$Sprite.c$16$1_0$181
;C:/ZGB-2023.0/common/src/Sprite.c:16: void InitSprite(Sprite* sprite, UINT8 sprite_type) {
;	---------------------------------
; Function InitSprite
; ---------------------------------
_InitSprite::
	add	sp, #-7
	ld	c, e
	ld	b, d
	ldhl	sp,	#6
	ld	(hl), a
	C$Sprite.c$17$1_0$181	= .
	.globl	C$Sprite.c$17$1_0$181
;C:/ZGB-2023.0/common/src/Sprite.c:17: const struct MetaSpriteInfo* mt_sprite_info = spriteDatas[sprite_type];
	ld	l, (hl)
	ld	h, #0x00
	add	hl, hl
	ld	de, #_spriteDatas
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
	ldhl	sp,	#0
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	C$Sprite.c$19$1_0$181	= .
	.globl	C$Sprite.c$19$1_0$181
;C:/ZGB-2023.0/common/src/Sprite.c:19: sprite->mt_sprite_info = mt_sprite_info;
	ld	e, c
	ld	d, b
	inc	de
	ldhl	sp,	#0
	ld	a, (hl+)
	ld	(de), a
	inc	de
	ld	a, (hl)
	ld	(de), a
	C$Sprite.c$20$1_0$181	= .
	.globl	C$Sprite.c$20$1_0$181
;C:/ZGB-2023.0/common/src/Sprite.c:20: sprite->mt_sprite_bank = spriteDataBanks[sprite_type];
	ld	de, #_spriteDataBanks
	ldhl	sp,	#6
	ld	l, (hl)
	ld	h, #0x00
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#4
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#3
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	(bc), a
	C$Sprite.c$22$1_0$181	= .
	.globl	C$Sprite.c$22$1_0$181
;C:/ZGB-2023.0/common/src/Sprite.c:22: sprite->first_tile = spriteIdxs[sprite_type];
	ld	hl, #0x0003
	add	hl, bc
	push	hl
	ld	a, l
	ldhl	sp,	#6
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#5
	ld	(hl+), a
	ld	de, #_spriteIdxs+0
	ld	l, (hl)
	ld	h, #0x00
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
	ldhl	sp,	#4
	push	af
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	pop	af
	ld	(hl), a
	C$Sprite.c$26$1_0$181	= .
	.globl	C$Sprite.c$26$1_0$181
;C:/ZGB-2023.0/common/src/Sprite.c:26: sprite->attr_add = 0;
	ld	hl, #0x0004
	add	hl, bc
	ld	(hl), #0x00
	C$Sprite.c$28$1_0$181	= .
	.globl	C$Sprite.c$28$1_0$181
;C:/ZGB-2023.0/common/src/Sprite.c:28: sprite->anim_data = 0u;
	ld	hl, #0x0005
	add	hl, bc
	xor	a, a
	ld	(hl+), a
	ld	(hl), a
	C$Sprite.c$30$1_0$181	= .
	.globl	C$Sprite.c$30$1_0$181
;C:/ZGB-2023.0/common/src/Sprite.c:30: SetFrame(sprite, 0);
	push	bc
	xor	a, a
	ld	e, c
	ld	d, b
	call	_SetFrame
	pop	bc
	C$Sprite.c$32$1_0$181	= .
	.globl	C$Sprite.c$32$1_0$181
;C:/ZGB-2023.0/common/src/Sprite.c:32: sprite->anim_speed = 33u;
	ld	hl, #0x0008
	add	hl, bc
	ld	(hl), #0x21
	C$Sprite.c$34$1_0$181	= .
	.globl	C$Sprite.c$34$1_0$181
;C:/ZGB-2023.0/common/src/Sprite.c:34: sprite->x = 0;
	ld	hl, #0x000c
	add	hl, bc
	xor	a, a
	ld	(hl+), a
	ld	(hl), a
	C$Sprite.c$35$1_0$181	= .
	.globl	C$Sprite.c$35$1_0$181
;C:/ZGB-2023.0/common/src/Sprite.c:35: sprite->y = 0;
	ld	hl, #0x000e
	add	hl, bc
	xor	a, a
	ld	(hl+), a
	ld	(hl), a
	C$Sprite.c$37$1_0$181	= .
	.globl	C$Sprite.c$37$1_0$181
;C:/ZGB-2023.0/common/src/Sprite.c:37: PUSH_BANK(spriteDataBanks[sprite_type]);
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	push	bc
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	pop	bc
	C$Sprite.c$38$1_0$181	= .
	.globl	C$Sprite.c$38$1_0$181
;C:/ZGB-2023.0/common/src/Sprite.c:38: sprite->coll_w = mt_sprite_info->width;
	ld	hl, #0x0011
	add	hl, bc
	push	hl
	ld	a, l
	ldhl	sp,	#6
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#5
	ld	(hl-), a
	pop	de
	push	de
	ld	a, (de)
	push	af
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	pop	af
	ld	(hl), a
	C$Sprite.c$39$1_0$181	= .
	.globl	C$Sprite.c$39$1_0$181
;C:/ZGB-2023.0/common/src/Sprite.c:39: sprite->coll_h = mt_sprite_info->height;
	ld	hl, #0x0012
	add	hl, bc
	ld	c, l
	ld	b, h
	pop	de
	push	de
	inc	de
	ld	a, (de)
	ld	(bc), a
	C$Sprite.c$40$1_0$181	= .
	.globl	C$Sprite.c$40$1_0$181
;C:/ZGB-2023.0/common/src/Sprite.c:40: POP_BANK;
	call	_PopBank
	C$Sprite.c$41$1_0$181	= .
	.globl	C$Sprite.c$41$1_0$181
;C:/ZGB-2023.0/common/src/Sprite.c:41: }
	add	sp, #7
	C$Sprite.c$41$1_0$181	= .
	.globl	C$Sprite.c$41$1_0$181
	XG$InitSprite$0$0	= .
	.globl	XG$InitSprite$0$0
	ret
	G$SetSpriteAnim$0$0	= .
	.globl	G$SetSpriteAnim$0$0
	C$Sprite.c$43$1_0$183	= .
	.globl	C$Sprite.c$43$1_0$183
;C:/ZGB-2023.0/common/src/Sprite.c:43: void SetSpriteAnim(Sprite* sprite, const UINT8* data, UINT8 speed) {
;	---------------------------------
; Function SetSpriteAnim
; ---------------------------------
_SetSpriteAnim::
	add	sp, #-4
	ldhl	sp,	#2
	ld	a, e
	ld	(hl+), a
	C$Sprite.c$44$1_0$183	= .
	.globl	C$Sprite.c$44$1_0$183
;C:/ZGB-2023.0/common/src/Sprite.c:44: if(sprite->anim_data != data) {
	ld	a, d
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0005
	add	hl, de
	inc	sp
	inc	sp
	ld	e, l
	ld	d, h
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
	ld	a, l
	sub	a, c
	jr	NZ, 00112$
	ld	a, h
	sub	a, b
	jr	Z, 00103$
00112$:
	C$Sprite.c$45$2_0$184	= .
	.globl	C$Sprite.c$45$2_0$184
;C:/ZGB-2023.0/common/src/Sprite.c:45: sprite->anim_data = data;
	pop	hl
	push	hl
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	C$Sprite.c$46$2_0$184	= .
	.globl	C$Sprite.c$46$2_0$184
;C:/ZGB-2023.0/common/src/Sprite.c:46: SetFrame(sprite, data[1]);
	inc	bc
	ld	a, (bc)
	ldhl	sp,	#2
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	call	_SetFrame
	C$Sprite.c$47$2_0$184	= .
	.globl	C$Sprite.c$47$2_0$184
;C:/ZGB-2023.0/common/src/Sprite.c:47: sprite->anim_frame = 0;
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0009
	add	hl, de
	ld	c, l
	ld	b, h
	xor	a, a
	ld	(bc), a
	C$Sprite.c$48$2_0$184	= .
	.globl	C$Sprite.c$48$2_0$184
;C:/ZGB-2023.0/common/src/Sprite.c:48: sprite->anim_accum_ticks = 0;
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0007
	add	hl, de
	ld	c, l
	ld	b, h
	xor	a, a
	ld	(bc), a
	C$Sprite.c$49$2_0$184	= .
	.globl	C$Sprite.c$49$2_0$184
;C:/ZGB-2023.0/common/src/Sprite.c:49: sprite->anim_speed = speed;
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0008
	add	hl, de
	ld	c, l
	ld	b, h
	ldhl	sp,	#6
	ld	a, (hl)
	ld	(bc), a
00103$:
	C$Sprite.c$51$1_0$183	= .
	.globl	C$Sprite.c$51$1_0$183
;C:/ZGB-2023.0/common/src/Sprite.c:51: }
	add	sp, #4
	pop	hl
	inc	sp
	jp	(hl)
	G$DrawSprite$0$0	= .
	.globl	G$DrawSprite$0$0
	C$Sprite.c$88$1_0$187	= .
	.globl	C$Sprite.c$88$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:88: void DrawSprite() {
;	---------------------------------
; Function DrawSprite
; ---------------------------------
_DrawSprite::
	add	sp, #-11
	C$Sprite.c$96$1_0$187	= .
	.globl	C$Sprite.c$96$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:96: if(THIS->anim_data) {	
	ld	a, (#_THIS)
	ldhl	sp,	#8
	ld	(hl), a
	ld	a, (#_THIS + 1)
	ldhl	sp,	#9
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0005
	add	hl, de
	ld	a, (hl+)
	or	a,(hl)
	jp	Z, 00106$
	C$Sprite.c$97$1_0$187	= .
	.globl	C$Sprite.c$97$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:97: THIS->anim_accum_ticks += THIS->anim_speed << delta_time;
	ldhl	sp,#8
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0007
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
	ldhl	sp,	#10
	ld	(hl-), a
	dec	hl
	push	de
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0008
	add	hl, de
	pop	de
	ld	c, l
	ld	b, h
	ld	a, (bc)
	ld	hl, #_delta_time
	ld	b, (hl)
	inc	b
	jr	00223$
00222$:
	add	a, a
00223$:
	dec	b
	jr	NZ,00222$
	ldhl	sp,	#10
	add	a, (hl)
	ld	(de), a
	C$Sprite.c$96$1_0$187	= .
	.globl	C$Sprite.c$96$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:96: if(THIS->anim_data) {	
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	C$Sprite.c$98$2_0$188	= .
	.globl	C$Sprite.c$98$2_0$188
;C:/ZGB-2023.0/common/src/Sprite.c:98: if(THIS->anim_accum_ticks > (UINT8)100u) {
	ld	hl, #0x0007
	add	hl, bc
	ld	e, (hl)
	ld	a, #0x64
	sub	a, e
	jp	NC, 00106$
	C$Sprite.c$99$3_0$189	= .
	.globl	C$Sprite.c$99$3_0$189
;C:/ZGB-2023.0/common/src/Sprite.c:99: THIS->anim_frame ++;
	ld	hl, #0x0009
	add	hl, bc
	inc	(hl)
	ld	a, (hl)
	C$Sprite.c$96$1_0$187	= .
	.globl	C$Sprite.c$96$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:96: if(THIS->anim_data) {	
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	C$Sprite.c$99$1_0$187	= .
	.globl	C$Sprite.c$99$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:99: THIS->anim_frame ++;
	ld	hl, #0x0009
	add	hl, de
	ld	c, l
	ld	b, h
	C$Sprite.c$100$3_0$189	= .
	.globl	C$Sprite.c$100$3_0$189
;C:/ZGB-2023.0/common/src/Sprite.c:100: if(THIS->anim_frame == THIS->anim_data[0]){
	ld	a, (bc)
	ldhl	sp,	#10
	ld	(hl), a
	ld	hl, #0x0005
	add	hl, de
	ld	a,	(hl+)
	ld	h, (hl)
;	spillPairReg hl
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	e, (hl)
	ldhl	sp,	#10
	ld	a, (hl)
	sub	a, e
	jr	NZ, 00102$
	C$Sprite.c$101$4_0$190	= .
	.globl	C$Sprite.c$101$4_0$190
;C:/ZGB-2023.0/common/src/Sprite.c:101: THIS->anim_frame = 0;
	xor	a, a
	ld	(bc), a
00102$:
	C$Sprite.c$96$1_0$187	= .
	.globl	C$Sprite.c$96$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:96: if(THIS->anim_data) {	
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	C$Sprite.c$104$3_0$189	= .
	.globl	C$Sprite.c$104$3_0$189
;C:/ZGB-2023.0/common/src/Sprite.c:104: tmp = THIS->anim_data[(UINT8)1u + THIS->anim_frame]; //Do this before changing banks, anim_data is stored on current bank
	ld	hl, #0x0005
	add	hl, bc
	ld	a,	(hl+)
	ld	h, (hl)
;	spillPairReg hl
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	a, c
	add	a, #0x09
	ld	e, a
	ld	a, b
	adc	a, #0x00
	ld	d, a
	ld	a, (de)
	ld	d, #0x00
	ld	e, a
	inc	de
	add	hl, de
	ld	a, (hl)
	ldhl	sp,	#8
	ld	(hl), a
	C$Sprite.c$105$3_0$189	= .
	.globl	C$Sprite.c$105$3_0$189
;C:/ZGB-2023.0/common/src/Sprite.c:105: PUSH_BANK(THIS->mt_sprite_bank);
	ld	a, (bc)
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	C$Sprite.c$96$1_0$187	= .
	.globl	C$Sprite.c$96$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:96: if(THIS->anim_data) {	
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	C$Sprite.c$106$3_0$189	= .
	.globl	C$Sprite.c$106$3_0$189
;C:/ZGB-2023.0/common/src/Sprite.c:106: THIS->mt_sprite = THIS->mt_sprite_info->metasprites[tmp];
	ld	hl, #0x000a
	add	hl, bc
	push	hl
	ld	a, l
	ldhl	sp,	#11
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#10
	ld	(hl), a
	ld	l, c
	ld	h, b
	inc	hl
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #0x0009
	add	hl, bc
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ldhl	sp,	#8
	ld	l, (hl)
	ld	h, #0x00
	add	hl, hl
	add	hl, bc
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ldhl	sp,	#9
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	C$Sprite.c$107$3_0$189	= .
	.globl	C$Sprite.c$107$3_0$189
;C:/ZGB-2023.0/common/src/Sprite.c:107: POP_BANK;
	call	_PopBank
	C$Sprite.c$96$1_0$187	= .
	.globl	C$Sprite.c$96$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:96: if(THIS->anim_data) {	
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	C$Sprite.c$97$1_0$187	= .
	.globl	C$Sprite.c$97$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:97: THIS->anim_accum_ticks += THIS->anim_speed << delta_time;
	ld	hl, #0x0007
	add	hl, bc
	C$Sprite.c$108$3_0$189	= .
	.globl	C$Sprite.c$108$3_0$189
;C:/ZGB-2023.0/common/src/Sprite.c:108: THIS->anim_accum_ticks -= 100u;
	ld	a, (hl)
	add	a, #0x9c
	ld	(hl), a
00106$:
	C$Sprite.c$96$1_0$187	= .
	.globl	C$Sprite.c$96$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:96: if(THIS->anim_data) {	
	ld	a, (#_THIS)
	ldhl	sp,	#7
	ld	(hl), a
	ld	a, (#_THIS + 1)
	ldhl	sp,	#8
	C$Sprite.c$112$1_0$187	= .
	.globl	C$Sprite.c$112$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:112: screen_x = THIS->x - scroll_x;
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x000c
	add	hl, de
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	a, (#_scroll_x)
	ldhl	sp,	#9
	ld	(hl), a
	ld	a, (#_scroll_x + 1)
	ldhl	sp,	#10
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, c
	sub	a, e
	ld	e, a
	ld	a, b
	sbc	a, d
	ldhl	sp,	#4
	ld	(hl-), a
	ld	(hl), e
	C$Sprite.c$113$1_0$187	= .
	.globl	C$Sprite.c$113$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:113: screen_y = THIS->y - scroll_y;
	ldhl	sp,#7
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x000e
	add	hl, de
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	a, (#_scroll_y)
	ldhl	sp,	#9
	ld	(hl), a
	ld	a, (#_scroll_y + 1)
	ldhl	sp,	#10
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, c
	sub	a, e
	ld	e, a
	ld	a, b
	sbc	a, d
	ldhl	sp,	#6
	ld	(hl-), a
	C$Sprite.c$115$1_0$187	= .
	.globl	C$Sprite.c$115$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:115: if((screen_x + 32u < SCREENWIDTH_PLUS_32) && (screen_y + 32 < SCREENHEIGHT_PLUS_32)) {
	ld	a, e
	ld	(hl-), a
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0020
	add	hl, de
	ld	c, l
	ld	b, h
	ld	a, c
	sub	a, #0xc0
	ld	a, b
	sbc	a, #0x00
	jp	NC, 00118$
	ldhl	sp,#5
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0020
	add	hl, de
	ld	c, l
	ld	b, h
	ld	a, c
	sub	a, #0xb0
	ld	a, b
	sbc	a, #0x00
	jp	NC, 00118$
	C$Sprite.c$116$2_0$191	= .
	.globl	C$Sprite.c$116$2_0$191
;C:/ZGB-2023.0/common/src/Sprite.c:116: screen_x += 8u;
	ldhl	sp,#3
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0008
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#11
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#10
	ld	(hl), a
	C$Sprite.c$117$2_0$191	= .
	.globl	C$Sprite.c$117$2_0$191
;C:/ZGB-2023.0/common/src/Sprite.c:117: screen_y += 16u;
	ldhl	sp,#5
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0010
	add	hl, de
	ld	c, l
	ld	b, h
	C$Sprite.c$118$2_0$191	= .
	.globl	C$Sprite.c$118$2_0$191
;C:/ZGB-2023.0/common/src/Sprite.c:118: tmp = next_oam_idx;
	ld	a, (#_next_oam_idx)
	ldhl	sp,	#0
	ld	(hl), a
	C$Sprite.c$119$2_0$191	= .
	.globl	C$Sprite.c$119$2_0$191
;C:/ZGB-2023.0/common/src/Sprite.c:119: PUSH_BANK(THIS->mt_sprite_bank);
	ldhl	sp,#7
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	push	bc
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	pop	bc
	C$Sprite.c$96$1_0$187	= .
	.globl	C$Sprite.c$96$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:96: if(THIS->anim_data) {	
	ld	a, (#_THIS)
	ldhl	sp,	#1
	ld	(hl), a
	ld	a, (#_THIS + 1)
	ldhl	sp,	#2
	C$Sprite.c$120$2_0$191	= .
	.globl	C$Sprite.c$120$2_0$191
;C:/ZGB-2023.0/common/src/Sprite.c:120: switch(THIS->mirror)
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0010
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
	ldhl	sp,	#3
	ld	(hl), a
	C$Sprite.c$118$1_0$187	= .
	.globl	C$Sprite.c$118$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:118: tmp = next_oam_idx;
	ld	a, (#_next_oam_idx)
	ldhl	sp,	#4
	C$Sprite.c$122$1_0$187	= .
	.globl	C$Sprite.c$122$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:122: case NO_MIRROR: next_oam_idx += move_metasprite       (THIS->mt_sprite, THIS->first_tile, next_oam_idx, screen_x,                screen_y               ); break;
	ld	(hl+), a
	ld	(hl), c
	ldhl	sp,	#9
	ld	a, (hl)
	ldhl	sp,	#6
	ld	(hl), a
	C$Sprite.c$106$1_0$187	= .
	.globl	C$Sprite.c$106$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:106: THIS->mt_sprite = THIS->mt_sprite_info->metasprites[tmp];
	ldhl	sp,#1
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x000a
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#9
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#8
	ld	(hl), a
	C$Sprite.c$122$1_0$187	= .
	.globl	C$Sprite.c$122$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:122: case NO_MIRROR: next_oam_idx += move_metasprite       (THIS->mt_sprite, THIS->first_tile, next_oam_idx, screen_x,                screen_y               ); break;
	ldhl	sp,#1
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0003
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#11
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#10
	ld	(hl), a
	C$Sprite.c$120$2_0$191	= .
	.globl	C$Sprite.c$120$2_0$191
;C:/ZGB-2023.0/common/src/Sprite.c:120: switch(THIS->mirror)
	ldhl	sp,	#3
	ld	a, (hl)
	or	a, a
	jr	Z, 00107$
	C$Sprite.c$123$1_0$187	= .
	.globl	C$Sprite.c$123$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:123: case H_MIRROR:  next_oam_idx += move_metasprite_hflip (THIS->mt_sprite, THIS->first_tile, next_oam_idx, screen_x,                screen_y + THIS->coll_h); break;
	ldhl	sp,#1
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0012
	add	hl, de
	ld	c, l
	ld	b, h
	C$Sprite.c$120$2_0$191	= .
	.globl	C$Sprite.c$120$2_0$191
;C:/ZGB-2023.0/common/src/Sprite.c:120: switch(THIS->mirror)
	ldhl	sp,	#3
	ld	a, (hl)
	dec	a
	jr	Z, 00108$
	C$Sprite.c$124$1_0$187	= .
	.globl	C$Sprite.c$124$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:124: case V_MIRROR:  next_oam_idx += move_metasprite_vflip (THIS->mt_sprite, THIS->first_tile, next_oam_idx, screen_x + THIS->coll_w, screen_y               ); break;
	ldhl	sp,#1
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0011
	add	hl, de
	ld	e, l
	ld	d, h
	C$Sprite.c$120$2_0$191	= .
	.globl	C$Sprite.c$120$2_0$191
;C:/ZGB-2023.0/common/src/Sprite.c:120: switch(THIS->mirror)
	ldhl	sp,	#3
	ld	a, (hl)
	sub	a, #0x02
	jp	Z,00109$
	ldhl	sp,	#3
	ld	a, (hl)
	sub	a, #0x03
	jp	Z,00110$
	jp	00111$
	C$Sprite.c$122$3_0$192	= .
	.globl	C$Sprite.c$122$3_0$192
;C:/ZGB-2023.0/common/src/Sprite.c:122: case NO_MIRROR: next_oam_idx += move_metasprite       (THIS->mt_sprite, THIS->first_tile, next_oam_idx, screen_x,                screen_y               ); break;
00107$:
	ldhl	sp,	#5
	ld	a, (hl+)
	ld	b, a
	ld	c, (hl)
	ldhl	sp,#9
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	(#___current_base_tile),a
	ldhl	sp,#7
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	inc	de
	ld	a, (de)
;c:\zgb-2023.0\env\gbdk\include\gb\metasprites.h:160: __current_metasprite = metasprite;
	ld	e, l
	ld	d, a
	ld	hl, #___current_metasprite
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
;c:\zgb-2023.0\env\gbdk\include\gb\metasprites.h:162: __current_base_prop = 0;
	ld	hl, #___current_base_prop
	ld	(hl), #0x00
;c:\zgb-2023.0\env\gbdk\include\gb\metasprites.h:163: return __move_metasprite(base_sprite, (y << 8) | (uint8_t)x);
	ld	d, b
	xor	a, a
	or	a, c
	ld	e, a
	ldhl	sp,	#4
	ld	a, (hl)
	call	___move_metasprite
	C$Sprite.c$122$5_0$197	= .
	.globl	C$Sprite.c$122$5_0$197
;C:/ZGB-2023.0/common/src/Sprite.c:122: case NO_MIRROR: next_oam_idx += move_metasprite       (THIS->mt_sprite, THIS->first_tile, next_oam_idx, screen_x,                screen_y               ); break;
	ld	hl, #_next_oam_idx
	add	a, (hl)
	ld	(hl), a
	jp	00111$
	C$Sprite.c$123$3_0$192	= .
	.globl	C$Sprite.c$123$3_0$192
;C:/ZGB-2023.0/common/src/Sprite.c:123: case H_MIRROR:  next_oam_idx += move_metasprite_hflip (THIS->mt_sprite, THIS->first_tile, next_oam_idx, screen_x,                screen_y + THIS->coll_h); break;
00108$:
	ld	a, (bc)
	ldhl	sp,	#5
	add	a, (hl)
	ld	(hl+), a
	ld	c, (hl)
	ldhl	sp,#9
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	(#___current_base_tile),a
	ldhl	sp,#7
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	b, a
	inc	de
	ld	a, (de)
	push	af
	ldhl	sp,	#6
	ld	a, (hl)
	ldhl	sp,	#12
	ld	(hl), a
	pop	af
;c:\zgb-2023.0\env\gbdk\include\gb\metasprites.h:241: __current_metasprite = metasprite;
	ld	hl, #___current_metasprite
	ld	(hl), b
	inc	hl
	ld	(hl), a
;c:\zgb-2023.0\env\gbdk\include\gb\metasprites.h:243: __current_base_prop = 0;
	ld	hl, #___current_base_prop
	ld	(hl), #0x00
;c:\zgb-2023.0\env\gbdk\include\gb\metasprites.h:244: return __move_metasprite_hflip(base_sprite, ((y - ((LCDC_REG & LCDCF_OBJ16) ? 16u : 8u)) << 8) | x);
	ldhl	sp,	#5
	ld	b, (hl)
	ldh	a, (_LCDC_REG + 0)
	bit	2, a
	jr	Z, 00127$
	ld	de, #0x0010
	jr	00128$
00127$:
	ld	de, #0x0008
00128$:
	ld	a, b
	sub	a, e
	ld	d, a
	xor	a, a
	or	a, c
	ld	e, a
	ldhl	sp,	#10
	ld	a, (hl)
	call	___move_metasprite_hflip
	C$Sprite.c$123$5_0$200	= .
	.globl	C$Sprite.c$123$5_0$200
;C:/ZGB-2023.0/common/src/Sprite.c:123: case H_MIRROR:  next_oam_idx += move_metasprite_hflip (THIS->mt_sprite, THIS->first_tile, next_oam_idx, screen_x,                screen_y + THIS->coll_h); break;
	ld	hl, #_next_oam_idx
	add	a, (hl)
	ld	(hl), a
	jp	00111$
	C$Sprite.c$124$3_0$192	= .
	.globl	C$Sprite.c$124$3_0$192
;C:/ZGB-2023.0/common/src/Sprite.c:124: case V_MIRROR:  next_oam_idx += move_metasprite_vflip (THIS->mt_sprite, THIS->first_tile, next_oam_idx, screen_x + THIS->coll_w, screen_y               ); break;
00109$:
	ldhl	sp,	#5
	ld	a, (hl+)
	ld	b, a
	ld	a, (de)
	add	a, (hl)
	ld	c, a
	ldhl	sp,#9
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	(#___current_base_tile),a
	ldhl	sp,#7
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	inc	de
	ld	a, (de)
;c:\zgb-2023.0\env\gbdk\include\gb\metasprites.h:200: __current_metasprite = metasprite;
	ld	e, l
	ld	d, a
	ld	hl, #___current_metasprite
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
;c:\zgb-2023.0\env\gbdk\include\gb\metasprites.h:202: __current_base_prop = 0;
	ld	hl, #___current_base_prop
	ld	(hl), #0x00
;c:\zgb-2023.0\env\gbdk\include\gb\metasprites.h:203: return __move_metasprite_vflip(base_sprite, (y << 8) | (uint8_t)(x - 8u));
	ld	d, b
	ld	e, #0x00
	ld	a, c
	add	a, #0xf8
	or	a, e
	ld	e, a
	ldhl	sp,	#4
	ld	a, (hl)
	call	___move_metasprite_vflip
	C$Sprite.c$124$5_0$203	= .
	.globl	C$Sprite.c$124$5_0$203
;C:/ZGB-2023.0/common/src/Sprite.c:124: case V_MIRROR:  next_oam_idx += move_metasprite_vflip (THIS->mt_sprite, THIS->first_tile, next_oam_idx, screen_x + THIS->coll_w, screen_y               ); break;
	ld	hl, #_next_oam_idx
	add	a, (hl)
	ld	(hl), a
	jr	00111$
	C$Sprite.c$125$3_0$192	= .
	.globl	C$Sprite.c$125$3_0$192
;C:/ZGB-2023.0/common/src/Sprite.c:125: case HV_MIRROR: next_oam_idx += move_metasprite_hvflip(THIS->mt_sprite, THIS->first_tile, next_oam_idx, screen_x + THIS->coll_w, screen_y + THIS->coll_h); break;
00110$:
	ld	a, (bc)
	ldhl	sp,	#5
	add	a, (hl)
	ld	(hl+), a
	ld	a, (de)
	add	a, (hl)
	ld	c, a
	ldhl	sp,#9
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	(#___current_base_tile),a
	ldhl	sp,#7
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl+)
	ld	d, a
	ld	a, (de)
	ld	b, a
	inc	de
	ld	a, (de)
	ld	(hl), c
	push	af
	ldhl	sp,	#6
	ld	a, (hl)
	ldhl	sp,	#12
	ld	(hl), a
	pop	af
;c:\zgb-2023.0\env\gbdk\include\gb\metasprites.h:281: __current_metasprite = metasprite;
	ld	hl, #___current_metasprite
	ld	(hl), b
	inc	hl
	ld	(hl), a
;c:\zgb-2023.0\env\gbdk\include\gb\metasprites.h:283: __current_base_prop = 0;
	ld	hl, #___current_base_prop
	ld	(hl), #0x00
;c:\zgb-2023.0\env\gbdk\include\gb\metasprites.h:284: return __move_metasprite_hvflip(base_sprite, ((y - ((LCDC_REG & LCDCF_OBJ16) ? 16u : 8u)) << 8) | (uint8_t)(x - 8));
	ldhl	sp,	#5
	ld	a, (hl)
	ldhl	sp,	#8
	ld	(hl), a
	ldh	a, (_LCDC_REG + 0)
	bit	2, a
	jr	Z, 00129$
	ldhl	sp,	#6
	ld	a, #0x10
	ld	(hl+), a
	xor	a, a
	ld	(hl), a
	jr	00130$
00129$:
	ldhl	sp,	#6
	ld	a, #0x08
	ld	(hl+), a
	xor	a, a
	ld	(hl), a
00130$:
	ldhl	sp,	#8
	ld	a, (hl-)
	ld	e, a
	ld	a, (hl-)
	ld	l, (hl)
	ld	a, e
	sub	a, l
	ld	b, a
	ld	c, #0x00
	ldhl	sp,	#9
	ld	a, (hl+)
	add	a, #0xf8
	or	a, c
	ld	e, a
	ld	d, b
	ld	a, (hl)
	call	___move_metasprite_hvflip
	C$Sprite.c$125$5_0$206	= .
	.globl	C$Sprite.c$125$5_0$206
;C:/ZGB-2023.0/common/src/Sprite.c:125: case HV_MIRROR: next_oam_idx += move_metasprite_hvflip(THIS->mt_sprite, THIS->first_tile, next_oam_idx, screen_x + THIS->coll_w, screen_y + THIS->coll_h); break;
	ld	hl, #_next_oam_idx
	add	a, (hl)
	ld	(hl), a
	C$Sprite.c$126$2_0$191	= .
	.globl	C$Sprite.c$126$2_0$191
;C:/ZGB-2023.0/common/src/Sprite.c:126: }
00111$:
	C$Sprite.c$127$2_0$191	= .
	.globl	C$Sprite.c$127$2_0$191
;C:/ZGB-2023.0/common/src/Sprite.c:127: POP_BANK;
	call	_PopBank
	C$Sprite.c$96$1_0$187	= .
	.globl	C$Sprite.c$96$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:96: if(THIS->anim_data) {	
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	C$Sprite.c$130$1_0$187	= .
	.globl	C$Sprite.c$130$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:130: if (THIS->attr_add) {
	ld	hl, #0x0004
	add	hl, bc
	ld	b, (hl)
	ld	a, b
	or	a, a
	jp	Z, 00125$
	C$Sprite.c$131$3_0$193	= .
	.globl	C$Sprite.c$131$3_0$193
;C:/ZGB-2023.0/common/src/Sprite.c:131: update_attr(tmp, next_oam_idx - tmp, THIS->attr_add);
	ld	a, (#_next_oam_idx)
	ldhl	sp,	#0
	sub	a, (hl)
	push	bc
	inc	sp
	push	af
	inc	sp
	ld	a, (hl)
	push	af
	inc	sp
	call	_update_attr
	add	sp, #3
	jp	00125$
00118$:
	C$Sprite.c$135$1_0$187	= .
	.globl	C$Sprite.c$135$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:135: if((screen_x + THIS->lim_x + 16) > ((THIS->lim_x << 1) + 16 + SCREENWIDTH) ||
	ldhl	sp,#7
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0015
	add	hl, de
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ldhl	sp,	#3
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	ld	e, l
	ld	d, h
	ld	hl, #0x0010
	add	hl, de
	ld	e, l
	ld	d, h
	ld	l, c
	ld	h, b
	add	hl, hl
	ld	bc, #0x00b0
	add	hl, bc
	ld	a, l
	sub	a, e
	ld	a, h
	sbc	a, d
	jr	C, 00114$
	C$Sprite.c$136$1_0$187	= .
	.globl	C$Sprite.c$136$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:136: (screen_y + THIS->lim_y + 16) > ((THIS->lim_y << 1) + 16 + SCREENHEIGHT)
	ldhl	sp,#7
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0017
	add	hl, de
	ld	c, l
	ld	b, h
	ld	e, c
	ld	d, b
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
	ld	a, (hl+)
	ld	d, a
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#11
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#10
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0010
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#7
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#6
	ld	(hl+), a
	ld	a, (hl+)
	inc	hl
	ld	(hl-), a
	ld	a, (hl+)
	inc	hl
	ld	(hl-), a
	sla	(hl)
	inc	hl
	rl	(hl)
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x00a0
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#9
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#8
	ld	(hl), a
	ldhl	sp,	#7
	ld	e, l
	ld	d, h
	ldhl	sp,	#5
	ld	a, (de)
	inc	de
	sub	a, (hl)
	inc	hl
	ld	a, (de)
	sbc	a, (hl)
	jr	NC, 00125$
00114$:
	C$Sprite.c$138$3_0$195	= .
	.globl	C$Sprite.c$138$3_0$195
;C:/ZGB-2023.0/common/src/Sprite.c:138: SpriteManagerRemove(THIS_IDX);
	ld	a, (#_THIS_IDX)
	ldhl	sp,	#9
	ld	(hl+), a
	ld	(hl), #0x00
	dec	hl
	ld	e, (hl)
	ld	d, #0x00
	call	_SpriteManagerRemove
00125$:
	C$Sprite.c$141$1_0$187	= .
	.globl	C$Sprite.c$141$1_0$187
;C:/ZGB-2023.0/common/src/Sprite.c:141: }
	add	sp, #11
	C$Sprite.c$141$1_0$187	= .
	.globl	C$Sprite.c$141$1_0$187
	XG$DrawSprite$0$0	= .
	.globl	XG$DrawSprite$0$0
	ret
	G$TranslateSprite$0$0	= .
	.globl	G$TranslateSprite$0$0
	C$Sprite.c$144$1_0$209	= .
	.globl	C$Sprite.c$144$1_0$209
;C:/ZGB-2023.0/common/src/Sprite.c:144: UINT8 TranslateSprite(Sprite* sprite, INT8 x, INT8 y) {
;	---------------------------------
; Function TranslateSprite
; ---------------------------------
_TranslateSprite::
	add	sp, #-18
	ld	c, a
	C$Sprite.c$145$2_0$209	= .
	.globl	C$Sprite.c$145$2_0$209
;C:/ZGB-2023.0/common/src/Sprite.c:145: UINT8 ret = 0;
	ldhl	sp,	#0
	ld	(hl), #0x00
	C$Sprite.c$153$1_0$209	= .
	.globl	C$Sprite.c$153$1_0$209
;C:/ZGB-2023.0/common/src/Sprite.c:153: pivot_x = sprite->x + (UINT8)(sprite->coll_w - 1u);
	push	de
	ld	hl, #0x000c
	add	hl, de
	pop	de
	push	hl
	ld	a, l
	ldhl	sp,	#3
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#2
	ld	(hl), a
	push	de
	ld	hl, #0x0011
	add	hl, de
	pop	de
	push	hl
	ld	a, l
	ldhl	sp,	#5
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#4
	C$Sprite.c$160$1_0$209	= .
	.globl	C$Sprite.c$160$1_0$209
;C:/ZGB-2023.0/common/src/Sprite.c:160: pivot_x += x;
	ld	(hl+), a
	ld	a, c
	ld	(hl+), a
	rlca
	sbc	a, a
	ld	(hl), a
	C$Sprite.c$172$1_0$209	= .
	.globl	C$Sprite.c$172$1_0$209
;C:/ZGB-2023.0/common/src/Sprite.c:172: if(sprite->y >= scroll_h) { //This checks sprite->y < 0 || sprite->y >= scroll_h
	push	de
	ld	hl, #0x000e
	add	hl, de
	pop	de
	push	hl
	ld	a, l
	ldhl	sp,	#9
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#8
	ld	(hl), a
	C$Sprite.c$182$1_0$209	= .
	.globl	C$Sprite.c$182$1_0$209
;C:/ZGB-2023.0/common/src/Sprite.c:182: pivot_y = sprite->y + sprite->coll_h - 1;
	ld	hl, #0x0012
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#11
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#10
	ld	(hl), a
	C$Sprite.c$151$1_0$209	= .
	.globl	C$Sprite.c$151$1_0$209
;C:/ZGB-2023.0/common/src/Sprite.c:151: if(x) {
	ld	a, c
	or	a, a
	jp	Z, 00128$
	C$Sprite.c$152$2_0$210	= .
	.globl	C$Sprite.c$152$2_0$210
;C:/ZGB-2023.0/common/src/Sprite.c:152: if(x > 0) {
	ld	e, c
	xor	a, a
	ld	d, a
	sub	a, c
	bit	7, e
	jr	Z, 00344$
	bit	7, d
	jr	NZ, 00345$
	cp	a, a
	jr	00345$
00344$:
	bit	7, d
	jr	Z, 00345$
	scf
00345$:
	ld	a, #0x00
	rla
	ldhl	sp,	#11
	ld	(hl), a
	C$Sprite.c$153$1_0$209	= .
	.globl	C$Sprite.c$153$1_0$209
;C:/ZGB-2023.0/common/src/Sprite.c:153: pivot_x = sprite->x + (UINT8)(sprite->coll_w - 1u);
	ldhl	sp,#1
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	c, a
	inc	de
	ld	a, (de)
	ld	b, a
	C$Sprite.c$152$2_0$210	= .
	.globl	C$Sprite.c$152$2_0$210
;C:/ZGB-2023.0/common/src/Sprite.c:152: if(x > 0) {
	ldhl	sp,	#11
	ld	a, (hl)
	or	a, a
	jr	Z, 00102$
	C$Sprite.c$153$3_0$211	= .
	.globl	C$Sprite.c$153$3_0$211
;C:/ZGB-2023.0/common/src/Sprite.c:153: pivot_x = sprite->x + (UINT8)(sprite->coll_w - 1u);
	ldhl	sp,#3
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	dec	a
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, bc
	ld	c, l
	ld	b, h
	C$Sprite.c$155$3_0$212	= .
	.globl	C$Sprite.c$155$3_0$212
;C:/ZGB-2023.0/common/src/Sprite.c:155: pivot_x = sprite->x;
00102$:
	C$Sprite.c$159$2_0$210	= .
	.globl	C$Sprite.c$159$2_0$210
;C:/ZGB-2023.0/common/src/Sprite.c:159: tmp = pivot_x >> 3;
	ld	e, c
	ld	d, b
	sra	d
	rr	e
	sra	d
	rr	e
	sra	d
	rr	e
	C$Sprite.c$160$2_0$210	= .
	.globl	C$Sprite.c$160$2_0$210
;C:/ZGB-2023.0/common/src/Sprite.c:160: pivot_x += x;
	ldhl	sp,	#5
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	ld	c, l
	ld	b, h
	C$Sprite.c$161$2_0$210	= .
	.globl	C$Sprite.c$161$2_0$210
;C:/ZGB-2023.0/common/src/Sprite.c:161: start_tile_x = pivot_x >> 3;
	ld	l, c
;	spillPairReg hl
;	spillPairReg hl
	ld	d, b
	sra	d
	rr	l
	sra	d
	rr	l
	sra	d
	rr	l
	ld	a, l
	ldhl	sp,	#12
	ld	(hl), a
	C$Sprite.c$162$2_0$210	= .
	.globl	C$Sprite.c$162$2_0$210
;C:/ZGB-2023.0/common/src/Sprite.c:162: if(tmp == start_tile_x) {
	ld	a, e
	sub	a, (hl)
	jp	Z,00128$
	C$Sprite.c$167$2_0$210	= .
	.globl	C$Sprite.c$167$2_0$210
;C:/ZGB-2023.0/common/src/Sprite.c:167: if((UINT16)pivot_x >= scroll_w) { //This checks pivot_x < 0 || pivot_x >= scroll_W
	ld	hl, #_scroll_w
	ld	a, c
	sub	a, (hl)
	inc	hl
	ld	a, b
	sbc	a, (hl)
	jp	NC, 00128$
	C$Sprite.c$172$2_0$210	= .
	.globl	C$Sprite.c$172$2_0$210
;C:/ZGB-2023.0/common/src/Sprite.c:172: if(sprite->y >= scroll_h) { //This checks sprite->y < 0 || sprite->y >= scroll_h
	ldhl	sp,#7
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ldhl	sp,	#13
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	C$Sprite.c$176$1_0$209	= .
	.globl	C$Sprite.c$176$1_0$209
;C:/ZGB-2023.0/common/src/Sprite.c:176: start_tile_y = scroll_tiles_h - 1;
	ld	a, (#_scroll_tiles_h)
	dec	a
	ldhl	sp,	#15
	ld	(hl), a
	C$Sprite.c$172$2_0$210	= .
	.globl	C$Sprite.c$172$2_0$210
;C:/ZGB-2023.0/common/src/Sprite.c:172: if(sprite->y >= scroll_h) { //This checks sprite->y < 0 || sprite->y >= scroll_h
	ldhl	sp,	#13
	ld	e, l
	ld	d, h
	ld	hl, #_scroll_h
	ld	a, (de)
	inc	de
	sub	a, (hl)
	inc	hl
	ld	a, (de)
	sbc	a, (hl)
	jr	C, 00112$
	C$Sprite.c$173$3_0$215	= .
	.globl	C$Sprite.c$173$3_0$215
;C:/ZGB-2023.0/common/src/Sprite.c:173: if((INT16)sprite->y < 0) 
	ldhl	sp,	#13
	ld	a, (hl+)
	bit	7, (hl)
	jr	Z, 00109$
	C$Sprite.c$174$3_0$215	= .
	.globl	C$Sprite.c$174$3_0$215
;C:/ZGB-2023.0/common/src/Sprite.c:174: start_tile_y = 0;
	ldhl	sp,	#17
	ld	(hl), #0x00
	jr	00113$
00109$:
	C$Sprite.c$176$3_0$215	= .
	.globl	C$Sprite.c$176$3_0$215
;C:/ZGB-2023.0/common/src/Sprite.c:176: start_tile_y = scroll_tiles_h - 1;
	ldhl	sp,	#15
	ld	a, (hl+)
	inc	hl
	ld	(hl), a
	jr	00113$
00112$:
	C$Sprite.c$178$3_0$216	= .
	.globl	C$Sprite.c$178$3_0$216
;C:/ZGB-2023.0/common/src/Sprite.c:178: start_tile_y = sprite->y >> 3;
	ldhl	sp,	#13
	ld	a, (hl)
	ldhl	sp,	#16
	ld	(hl-), a
	dec	hl
	ld	a, (hl)
	ldhl	sp,	#17
	ld	(hl), a
	srl	(hl)
	dec	hl
	rr	(hl)
	inc	hl
	srl	(hl)
	dec	hl
	rr	(hl)
	inc	hl
	srl	(hl)
	dec	hl
	rr	(hl)
	ld	a, (hl+)
	ld	(hl), a
00113$:
	C$Sprite.c$182$2_0$210	= .
	.globl	C$Sprite.c$182$2_0$210
;C:/ZGB-2023.0/common/src/Sprite.c:182: pivot_y = sprite->y + sprite->coll_h - 1;
	ldhl	sp,#9
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	c, a
	ld	b, #0x00
	ldhl	sp,	#13
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	ld	c, l
	ld	b, h
	dec	bc
	C$Sprite.c$183$2_0$210	= .
	.globl	C$Sprite.c$183$2_0$210
;C:/ZGB-2023.0/common/src/Sprite.c:183: if((UINT16)pivot_y >= scroll_h) { //This checks pivot_y < 0 || pivot_y >= scroll_h
	ld	e, c
	ld	d, b
	ld	hl, #_scroll_h
	ld	a, e
	sub	a, (hl)
	inc	hl
	ld	a, d
	sbc	a, (hl)
	jr	C, 00118$
	C$Sprite.c$184$3_0$217	= .
	.globl	C$Sprite.c$184$3_0$217
;C:/ZGB-2023.0/common/src/Sprite.c:184: if(pivot_y < 0) 
	bit	7, b
	jr	Z, 00115$
	C$Sprite.c$185$3_0$217	= .
	.globl	C$Sprite.c$185$3_0$217
;C:/ZGB-2023.0/common/src/Sprite.c:185: end_tile_y = 0;
	ldhl	sp,	#16
	ld	(hl), #0x00
	jr	00119$
00115$:
	C$Sprite.c$187$3_0$217	= .
	.globl	C$Sprite.c$187$3_0$217
;C:/ZGB-2023.0/common/src/Sprite.c:187: end_tile_y = scroll_tiles_h - 1;
	ldhl	sp,	#15
	ld	a, (hl+)
	ld	(hl), a
	jr	00119$
00118$:
	C$Sprite.c$189$3_0$218	= .
	.globl	C$Sprite.c$189$3_0$218
;C:/ZGB-2023.0/common/src/Sprite.c:189: end_tile_y = pivot_y >> 3;
	sra	b
	rr	c
	sra	b
	rr	c
	sra	b
	rr	c
	ldhl	sp,	#16
	ld	(hl), c
00119$:
	C$Sprite.c$192$2_0$210	= .
	.globl	C$Sprite.c$192$2_0$210
;C:/ZGB-2023.0/common/src/Sprite.c:192: PUSH_BANK(scroll_bank);
	ld	a, (#_scroll_bank)
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	C$Sprite.c$193$2_0$210	= .
	.globl	C$Sprite.c$193$2_0$210
;C:/ZGB-2023.0/common/src/Sprite.c:193: tile_coll = scroll_map + (scroll_tiles_w * start_tile_y + start_tile_x);
	ldhl	sp,	#17
	ld	c, (hl)
	ld	b, #0x00
	ld	hl, #_scroll_tiles_w
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	__mulint
	ldhl	sp,	#12
	ld	a, (hl+)
	inc	hl
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl)
	ld	e, #0x00
	add	a, c
	ld	c, a
	ld	a, e
	adc	a, b
	ld	b, a
	ld	a, (#_scroll_map)
	add	a, c
	ld	(#_tile_coll),a
	ld	a, (#_scroll_map + 1)
	adc	a, b
	ld	(#_tile_coll + 1),a
	C$Sprite.c$194$2_0$210	= .
	.globl	C$Sprite.c$194$2_0$210
;C:/ZGB-2023.0/common/src/Sprite.c:194: end_tile_y ++;
	ldhl	sp,	#16
	C$Sprite.c$195$4_0$220	= .
	.globl	C$Sprite.c$195$4_0$220
;C:/ZGB-2023.0/common/src/Sprite.c:195: for(tmp = start_tile_y; tmp != end_tile_y; tmp ++, tile_coll += scroll_tiles_w) {
	ld	a, (hl+)
	ld	c, a
	inc	c
	ld	b, (hl)
00160$:
	ld	a, c
	sub	a, b
	jp	Z,00125$
	C$Sprite.c$196$4_0$220	= .
	.globl	C$Sprite.c$196$4_0$220
;C:/ZGB-2023.0/common/src/Sprite.c:196: if(scroll_collisions[*tile_coll] == 1u) {
	ld	hl, #_tile_coll
	ld	l, (hl)
;	spillPairReg hl
;	spillPairReg hl
	ld	a, (_tile_coll + 1)
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	ld	e, (hl)
	ld	hl, #_scroll_collisions
	ld	d, #0x00
	add	hl, de
	ld	a, (hl)
	dec	a
	jp	NZ,00161$
	C$Sprite.c$197$5_0$221	= .
	.globl	C$Sprite.c$197$5_0$221
;C:/ZGB-2023.0/common/src/Sprite.c:197: if(x > 0) {
	ldhl	sp,	#11
	ld	a, (hl)
	or	a, a
	jr	Z, 00121$
	C$Sprite.c$198$6_0$222	= .
	.globl	C$Sprite.c$198$6_0$222
;C:/ZGB-2023.0/common/src/Sprite.c:198: sprite->x = (start_tile_x << 3) - sprite->coll_w;
	ldhl	sp,	#14
	ld	a, (hl+)
	inc	hl
	ld	(hl+), a
	ld	(hl), #0x00
	ld	a, #0x03
00350$:
	ldhl	sp,	#16
	sla	(hl)
	inc	hl
	rl	(hl)
	dec	a
	jr	NZ, 00350$
	ldhl	sp,#3
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ldhl	sp,	#15
	ld	(hl), a
	ldhl	sp,	#12
	ld	(hl+), a
	ld	(hl), #0x00
	ldhl	sp,#16
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ldhl	sp,	#12
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ldhl	sp,	#15
	ld	(hl-), a
	ld	(hl), e
	ldhl	sp,#1
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ldhl	sp,	#14
	ld	a, (hl+)
	ld	(de), a
	inc	de
	ld	a, (hl)
	ld	(de), a
	jr	00122$
00121$:
	C$Sprite.c$200$6_0$223	= .
	.globl	C$Sprite.c$200$6_0$223
;C:/ZGB-2023.0/common/src/Sprite.c:200: sprite->x = (start_tile_x + 1) << 3;
	ldhl	sp,#14
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	l, e
	ld	h, d
	inc	hl
	push	hl
	ld	a, l
	ldhl	sp,	#18
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#17
	ld	(hl), a
	ld	a, #0x03
00351$:
	ldhl	sp,	#16
	sla	(hl)
	inc	hl
	rl	(hl)
	dec	a
	jr	NZ, 00351$
	ldhl	sp,#1
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ldhl	sp,	#16
	ld	a, (hl+)
	ld	(de), a
	inc	de
	ld	a, (hl)
	ld	(de), a
00122$:
	C$Sprite.c$203$5_0$221	= .
	.globl	C$Sprite.c$203$5_0$221
;C:/ZGB-2023.0/common/src/Sprite.c:203: ret = *tile_coll;
	ld	hl, #_tile_coll
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	a, (bc)
	ldhl	sp,	#0
	ld	(hl), a
	C$Sprite.c$204$5_0$221	= .
	.globl	C$Sprite.c$204$5_0$221
;C:/ZGB-2023.0/common/src/Sprite.c:204: POP_BANK;
	call	_PopBank
	C$Sprite.c$205$5_0$221	= .
	.globl	C$Sprite.c$205$5_0$221
;C:/ZGB-2023.0/common/src/Sprite.c:205: goto done_x;
	jr	00129$
00161$:
	C$Sprite.c$195$3_0$219	= .
	.globl	C$Sprite.c$195$3_0$219
;C:/ZGB-2023.0/common/src/Sprite.c:195: for(tmp = start_tile_y; tmp != end_tile_y; tmp ++, tile_coll += scroll_tiles_w) {
	inc	b
	ld	a, (#_tile_coll)
	ld	hl, #_scroll_tiles_w
	add	a, (hl)
	ld	hl, #_tile_coll
	ld	(hl+), a
	ld	a, (hl)
	ld	hl, #_scroll_tiles_w + 1
	adc	a, (hl)
	ld	(#_tile_coll + 1),a
	jp	00160$
00125$:
	C$Sprite.c$208$2_0$210	= .
	.globl	C$Sprite.c$208$2_0$210
;C:/ZGB-2023.0/common/src/Sprite.c:208: POP_BANK;
	call	_PopBank
	C$Sprite.c$211$1_0$209	= .
	.globl	C$Sprite.c$211$1_0$209
;C:/ZGB-2023.0/common/src/Sprite.c:211: inc_x:
00128$:
	C$Sprite.c$212$1_0$209	= .
	.globl	C$Sprite.c$212$1_0$209
;C:/ZGB-2023.0/common/src/Sprite.c:212: sprite->x += x;
	ldhl	sp,#1
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	c, a
	inc	de
	ld	a, (de)
	ld	b, a
	ldhl	sp,	#5
	ld	a, (hl+)
	ld	e, (hl)
	add	a, c
	ld	c, a
	ld	a, e
	adc	a, b
	ld	b, a
	ldhl	sp,	#1
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	C$Sprite.c$213$1_0$209	= .
	.globl	C$Sprite.c$213$1_0$209
;C:/ZGB-2023.0/common/src/Sprite.c:213: done_x:
00129$:
	C$Sprite.c$224$1_0$209	= .
	.globl	C$Sprite.c$224$1_0$209
;C:/ZGB-2023.0/common/src/Sprite.c:224: pivot_y += y;
	ldhl	sp,	#20
	ld	a, (hl)
	ldhl	sp,	#5
	ld	(hl+), a
	rlca
	sbc	a, a
	ld	(hl), a
	C$Sprite.c$215$1_0$209	= .
	.globl	C$Sprite.c$215$1_0$209
;C:/ZGB-2023.0/common/src/Sprite.c:215: if(y) {
	ldhl	sp,	#20
	ld	a, (hl)
	or	a, a
	jp	Z, 00157$
	C$Sprite.c$216$2_0$224	= .
	.globl	C$Sprite.c$216$2_0$224
;C:/ZGB-2023.0/common/src/Sprite.c:216: if(y > 0) {
	ld	e, (hl)
	xor	a, a
	ld	d, a
	sub	a, (hl)
	bit	7, e
	jr	Z, 00352$
	bit	7, d
	jr	NZ, 00353$
	cp	a, a
	jr	00353$
00352$:
	bit	7, d
	jr	Z, 00353$
	scf
00353$:
	ld	a, #0x00
	rla
	ldhl	sp,	#11
	ld	(hl), a
	C$Sprite.c$172$1_0$209	= .
	.globl	C$Sprite.c$172$1_0$209
;C:/ZGB-2023.0/common/src/Sprite.c:172: if(sprite->y >= scroll_h) { //This checks sprite->y < 0 || sprite->y >= scroll_h
	ldhl	sp,#7
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ldhl	sp,	#12
	ld	(hl+), a
	inc	de
	ld	a, (de)
	C$Sprite.c$216$2_0$224	= .
	.globl	C$Sprite.c$216$2_0$224
;C:/ZGB-2023.0/common/src/Sprite.c:216: if(y > 0) {
	ld	(hl-), a
	dec	hl
	ld	a, (hl)
	or	a, a
	jr	Z, 00131$
	C$Sprite.c$217$3_0$225	= .
	.globl	C$Sprite.c$217$3_0$225
;C:/ZGB-2023.0/common/src/Sprite.c:217: pivot_y = sprite->y + (UINT8)(sprite->coll_h - 1u);
	dec	hl
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	dec	a
	ldhl	sp,	#17
	ld	(hl), a
	ldhl	sp,	#14
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ldhl	sp,	#12
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#18
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#17
	ld	(hl-), a
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	jr	00132$
00131$:
	C$Sprite.c$219$3_0$226	= .
	.globl	C$Sprite.c$219$3_0$226
;C:/ZGB-2023.0/common/src/Sprite.c:219: pivot_y = sprite->y;
	ldhl	sp,	#12
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
00132$:
	C$Sprite.c$223$2_0$224	= .
	.globl	C$Sprite.c$223$2_0$224
;C:/ZGB-2023.0/common/src/Sprite.c:223: tmp = pivot_y >> 3;
	ld	e, c
	ld	d, b
	sra	d
	rr	e
	sra	d
	rr	e
	sra	d
	rr	e
	C$Sprite.c$224$2_0$224	= .
	.globl	C$Sprite.c$224$2_0$224
;C:/ZGB-2023.0/common/src/Sprite.c:224: pivot_y += y;
	ldhl	sp,	#5
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	ld	c, l
	ld	b, h
	C$Sprite.c$225$2_0$224	= .
	.globl	C$Sprite.c$225$2_0$224
;C:/ZGB-2023.0/common/src/Sprite.c:225: start_tile_y = pivot_y >> 3;
	ld	l, c
;	spillPairReg hl
;	spillPairReg hl
	ld	d, b
	sra	d
	rr	l
	sra	d
	rr	l
	sra	d
	rr	l
	ld	a, l
	ldhl	sp,	#17
	C$Sprite.c$226$2_0$224	= .
	.globl	C$Sprite.c$226$2_0$224
;C:/ZGB-2023.0/common/src/Sprite.c:226: if(tmp == start_tile_y) {
	ld	(hl), a
	sub	a, e
	jp	Z,00157$
	C$Sprite.c$231$2_0$224	= .
	.globl	C$Sprite.c$231$2_0$224
;C:/ZGB-2023.0/common/src/Sprite.c:231: if((UINT16)pivot_y >= scroll_h) {
	ld	hl, #_scroll_h
	ld	a, c
	sub	a, (hl)
	inc	hl
	ld	a, b
	sbc	a, (hl)
	jp	NC, 00157$
	C$Sprite.c$236$2_0$224	= .
	.globl	C$Sprite.c$236$2_0$224
;C:/ZGB-2023.0/common/src/Sprite.c:236: if(sprite->x >= scroll_w){
	ldhl	sp,#1
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	c, a
	inc	de
	ld	a, (de)
	ld	b, a
	C$Sprite.c$240$1_0$209	= .
	.globl	C$Sprite.c$240$1_0$209
;C:/ZGB-2023.0/common/src/Sprite.c:240: start_tile_x = scroll_tiles_w - 1;
	ld	a, (#_scroll_tiles_w)
	dec	a
	ldhl	sp,	#15
	ld	(hl), a
	C$Sprite.c$236$2_0$224	= .
	.globl	C$Sprite.c$236$2_0$224
;C:/ZGB-2023.0/common/src/Sprite.c:236: if(sprite->x >= scroll_w){
	ld	hl, #_scroll_w
	ld	a, c
	sub	a, (hl)
	inc	hl
	ld	a, b
	sbc	a, (hl)
	jr	C, 00141$
	C$Sprite.c$237$3_0$229	= .
	.globl	C$Sprite.c$237$3_0$229
;C:/ZGB-2023.0/common/src/Sprite.c:237: if((INT16)sprite->x < 0) 
;	spillPairReg hl
;	spillPairReg hl
	ld	h, b
;	spillPairReg hl
;	spillPairReg hl
	bit	7, h
	jr	Z, 00138$
	C$Sprite.c$238$3_0$229	= .
	.globl	C$Sprite.c$238$3_0$229
;C:/ZGB-2023.0/common/src/Sprite.c:238: start_tile_x = 0;
	ldhl	sp,	#16
	ld	(hl), #0x00
	jr	00142$
00138$:
	C$Sprite.c$240$3_0$229	= .
	.globl	C$Sprite.c$240$3_0$229
;C:/ZGB-2023.0/common/src/Sprite.c:240: start_tile_x = scroll_tiles_w - 1;
	ldhl	sp,	#15
	ld	a, (hl+)
	ld	(hl), a
	jr	00142$
00141$:
	C$Sprite.c$242$3_0$230	= .
	.globl	C$Sprite.c$242$3_0$230
;C:/ZGB-2023.0/common/src/Sprite.c:242: start_tile_x = (sprite->x >> 3);
	ld	e, c
	ld	d, b
	srl	d
	rr	e
	srl	d
	rr	e
	srl	d
	rr	e
	ldhl	sp,	#16
	ld	(hl), e
00142$:
	C$Sprite.c$246$2_0$224	= .
	.globl	C$Sprite.c$246$2_0$224
;C:/ZGB-2023.0/common/src/Sprite.c:246: pivot_x = sprite->x + sprite->coll_w - 1;
	ldhl	sp,#3
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, bc
	ld	c, l
	ld	b, h
	ld	de, #0x0001
	ld	a, c
	sub	a, e
	ld	e, a
	ld	a, b
	sbc	a, d
	ldhl	sp,	#14
	ld	(hl-), a
	ld	(hl), e
	C$Sprite.c$247$2_0$224	= .
	.globl	C$Sprite.c$247$2_0$224
;C:/ZGB-2023.0/common/src/Sprite.c:247: if((UINT16)pivot_x >= scroll_w) {
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #_scroll_w
	ld	a, c
	sub	a, (hl)
	inc	hl
	ld	a, b
	sbc	a, (hl)
	jr	C, 00147$
	C$Sprite.c$248$3_0$231	= .
	.globl	C$Sprite.c$248$3_0$231
;C:/ZGB-2023.0/common/src/Sprite.c:248: if(pivot_x < 0) 
	ldhl	sp,	#14
	bit	7, (hl)
	jr	Z, 00144$
	C$Sprite.c$249$3_0$231	= .
	.globl	C$Sprite.c$249$3_0$231
;C:/ZGB-2023.0/common/src/Sprite.c:249: end_tile_x = 0;
	ld	e, #0x00
	jr	00148$
00144$:
	C$Sprite.c$251$3_0$231	= .
	.globl	C$Sprite.c$251$3_0$231
;C:/ZGB-2023.0/common/src/Sprite.c:251: end_tile_x = scroll_tiles_w - 1;
	ldhl	sp,	#15
	ld	e, (hl)
	jr	00148$
00147$:
	C$Sprite.c$253$3_0$232	= .
	.globl	C$Sprite.c$253$3_0$232
;C:/ZGB-2023.0/common/src/Sprite.c:253: end_tile_x = (pivot_x >> 3);
	ldhl	sp,	#13
	ld	a, (hl+)
	ld	e, a
	ld	c, (hl)
	sra	c
	rr	e
	sra	c
	rr	e
	sra	c
	rr	e
00148$:
	C$Sprite.c$256$2_0$224	= .
	.globl	C$Sprite.c$256$2_0$224
;C:/ZGB-2023.0/common/src/Sprite.c:256: PUSH_BANK(scroll_bank);
	push	de
	ld	a, (#_scroll_bank)
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	pop	de
	C$Sprite.c$257$2_0$224	= .
	.globl	C$Sprite.c$257$2_0$224
;C:/ZGB-2023.0/common/src/Sprite.c:257: tile_coll = scroll_map + (scroll_tiles_w * start_tile_y + start_tile_x);
	ldhl	sp,	#17
	ld	c, (hl)
	ld	b, #0x00
	push	de
	ld	hl, #_scroll_tiles_w
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	__mulint
	pop	de
	ldhl	sp,	#16
	ld	l, (hl)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, bc
	ld	c, l
	ld	b, h
	ld	a, (#_scroll_map)
	add	a, c
	ld	(#_tile_coll),a
	ld	a, (#_scroll_map + 1)
	adc	a, b
	ld	(#_tile_coll + 1),a
	C$Sprite.c$258$2_0$224	= .
	.globl	C$Sprite.c$258$2_0$224
;C:/ZGB-2023.0/common/src/Sprite.c:258: end_tile_x ++;
	ld	a, e
	inc	a
	ldhl	sp,	#15
	ld	(hl), a
	C$Sprite.c$259$2_0$224	= .
	.globl	C$Sprite.c$259$2_0$224
;C:/ZGB-2023.0/common/src/Sprite.c:259: scroll_coll_v = y < 0 ? scroll_collisions : scroll_collisions_down;
	ldhl	sp,	#20
	bit	7, (hl)
	jr	Z, 00167$
	ld	de, #_scroll_collisions+0
	ldhl	sp,	#13
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
	jr	00168$
00167$:
	ld	de, #_scroll_collisions_down+0
	ldhl	sp,	#13
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
00168$:
	ldhl	sp,	#13
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	C$Sprite.c$260$1_0$209	= .
	.globl	C$Sprite.c$260$1_0$209
;C:/ZGB-2023.0/common/src/Sprite.c:260: for(tmp = start_tile_x; tmp != end_tile_x; tmp ++, tile_coll += 1) {
00163$:
	ldhl	sp,	#15
	ld	a, (hl+)
	sub	a, (hl)
	jr	Z, 00154$
	C$Sprite.c$261$4_0$234	= .
	.globl	C$Sprite.c$261$4_0$234
;C:/ZGB-2023.0/common/src/Sprite.c:261: if(scroll_coll_v[*tile_coll] == 1u) {
	ld	hl, #_tile_coll
	ld	l, (hl)
;	spillPairReg hl
;	spillPairReg hl
	ld	a, (_tile_coll + 1)
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	ld	l, (hl)
;	spillPairReg hl
	ld	h, #0x00
	add	hl, bc
	ld	a, (hl)
	dec	a
	jr	NZ, 00164$
	C$Sprite.c$263$1_0$209	= .
	.globl	C$Sprite.c$263$1_0$209
;C:/ZGB-2023.0/common/src/Sprite.c:263: sprite->y = (start_tile_y << 3) - sprite->coll_h;
	ldhl	sp,	#17
	ld	c, (hl)
	ld	b, #0x00
	C$Sprite.c$262$5_0$235	= .
	.globl	C$Sprite.c$262$5_0$235
;C:/ZGB-2023.0/common/src/Sprite.c:262: if(y > 0) {
	ldhl	sp,	#11
	ld	a, (hl)
	or	a, a
	jr	Z, 00150$
	C$Sprite.c$263$6_0$236	= .
	.globl	C$Sprite.c$263$6_0$236
;C:/ZGB-2023.0/common/src/Sprite.c:263: sprite->y = (start_tile_y << 3) - sprite->coll_h;
	dec	hl
	dec	hl
	ld	a, c
	add	a, a
	rl	b
	add	a, a
	rl	b
	add	a, a
	rl	b
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	push	af
	ld	a, (de)
	ld	c, a
	pop	af
	ld	e, c
	ld	d, #0x00
	sub	a, e
	ld	c, a
	ld	a, b
	sbc	a, d
	ld	b, a
	ldhl	sp,	#7
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	jr	00151$
00150$:
	C$Sprite.c$265$6_0$237	= .
	.globl	C$Sprite.c$265$6_0$237
;C:/ZGB-2023.0/common/src/Sprite.c:265: sprite->y = (start_tile_y + 1) << 3;
	ld	l, c
;	spillPairReg hl
;	spillPairReg hl
	ld	h, b
;	spillPairReg hl
;	spillPairReg hl
	inc	hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	c, l
	ld	b, h
	ldhl	sp,	#7
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
00151$:
	C$Sprite.c$268$5_0$235	= .
	.globl	C$Sprite.c$268$5_0$235
;C:/ZGB-2023.0/common/src/Sprite.c:268: ret = *tile_coll;
	ld	hl, #_tile_coll
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	a, (bc)
	ldhl	sp,	#0
	ld	(hl), a
	C$Sprite.c$269$5_0$235	= .
	.globl	C$Sprite.c$269$5_0$235
;C:/ZGB-2023.0/common/src/Sprite.c:269: POP_BANK;
	call	_PopBank
	C$Sprite.c$270$5_0$235	= .
	.globl	C$Sprite.c$270$5_0$235
;C:/ZGB-2023.0/common/src/Sprite.c:270: goto done_y;
	jr	00158$
00164$:
	C$Sprite.c$260$3_0$233	= .
	.globl	C$Sprite.c$260$3_0$233
;C:/ZGB-2023.0/common/src/Sprite.c:260: for(tmp = start_tile_x; tmp != end_tile_x; tmp ++, tile_coll += 1) {
	ldhl	sp,	#16
	inc	(hl)
	ld	hl, #_tile_coll
	inc	(hl)
	jr	NZ, 00163$
	inc	hl
	inc	(hl)
	jr	00163$
00154$:
	C$Sprite.c$273$2_0$224	= .
	.globl	C$Sprite.c$273$2_0$224
;C:/ZGB-2023.0/common/src/Sprite.c:273: POP_BANK;
	call	_PopBank
	C$Sprite.c$276$1_0$209	= .
	.globl	C$Sprite.c$276$1_0$209
;C:/ZGB-2023.0/common/src/Sprite.c:276: inc_y:
00157$:
	C$Sprite.c$277$1_0$209	= .
	.globl	C$Sprite.c$277$1_0$209
;C:/ZGB-2023.0/common/src/Sprite.c:277: sprite->y += y;
	ldhl	sp,#7
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	c, a
	inc	de
	ld	a, (de)
	ld	b, a
	ldhl	sp,	#5
	ld	a, (hl+)
	ld	e, (hl)
	inc	hl
	add	a, c
	ld	c, a
	ld	a, e
	adc	a, b
	ld	b, a
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	C$Sprite.c$278$1_0$209	= .
	.globl	C$Sprite.c$278$1_0$209
;C:/ZGB-2023.0/common/src/Sprite.c:278: done_y:
00158$:
	C$Sprite.c$280$1_0$209	= .
	.globl	C$Sprite.c$280$1_0$209
;C:/ZGB-2023.0/common/src/Sprite.c:280: return ret;
	ldhl	sp,	#0
	ld	a, (hl)
	C$Sprite.c$281$1_0$209	= .
	.globl	C$Sprite.c$281$1_0$209
;C:/ZGB-2023.0/common/src/Sprite.c:281: }
	add	sp, #18
	pop	hl
	inc	sp
	jp	(hl)
	G$CheckCollision$0$0	= .
	.globl	G$CheckCollision$0$0
	C$Sprite.c$283$1_0$239	= .
	.globl	C$Sprite.c$283$1_0$239
;C:/ZGB-2023.0/common/src/Sprite.c:283: UINT8 CheckCollision(Sprite* sprite1, Sprite* sprite2) {
;	---------------------------------
; Function CheckCollision
; ---------------------------------
_CheckCollision::
	add	sp, #-7
	ldhl	sp,	#5
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
	ldhl	sp,	#3
	ld	a, c
	ld	(hl+), a
	C$Sprite.c$287$1_0$239	= .
	.globl	C$Sprite.c$287$1_0$239
;C:/ZGB-2023.0/common/src/Sprite.c:287: diff16 = sprite1->x - sprite2->x;
	ld	a, b
	ld	(hl+), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x000c
	add	hl, de
	ld	c, l
	ld	b, h
	ld	e, c
	ld	d, b
	ld	a, (de)
	ldhl	sp,	#1
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl+), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x000c
	add	hl, de
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ldhl	sp,#1
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
	C$Sprite.c$288$1_0$239	= .
	.globl	C$Sprite.c$288$1_0$239
;C:/ZGB-2023.0/common/src/Sprite.c:288: if((UINT16)(diff16 + 32) > 64) //diff16 > 32 || diff16 < -32
	ld	hl, #0x0020
	add	hl, bc
	ld	a, #0x40
	cp	a, l
	ld	a, #0x00
	sbc	a, h
	jr	NC, 00102$
	C$Sprite.c$289$1_0$239	= .
	.globl	C$Sprite.c$289$1_0$239
;C:/ZGB-2023.0/common/src/Sprite.c:289: return 0;
	xor	a, a
	jp	00111$
00102$:
	C$Sprite.c$291$1_0$239	= .
	.globl	C$Sprite.c$291$1_0$239
;C:/ZGB-2023.0/common/src/Sprite.c:291: diff = (INT8)diff16;
	ldhl	sp,	#0
	ld	(hl), c
	C$Sprite.c$293$1_0$239	= .
	.globl	C$Sprite.c$293$1_0$239
;C:/ZGB-2023.0/common/src/Sprite.c:293: diff16 = sprite1->y - sprite2->y;
	ldhl	sp,#5
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
	ldhl	sp,	#1
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl+), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x000e
	add	hl, de
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ldhl	sp,#1
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl-)
	ld	d, a
	ld	a, e
	sub	a, c
	ld	e, a
	ld	a, d
	sbc	a, b
	ld	b, a
	ld	a, e
	ld	(hl+), a
	C$Sprite.c$294$1_0$239	= .
	.globl	C$Sprite.c$294$1_0$239
;C:/ZGB-2023.0/common/src/Sprite.c:294: if((UINT16)(diff16 + 32) > 64)
	ld	a, b
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0020
	add	hl, de
	ld	c, l
	ld	b, h
	ld	a, #0x40
	cp	a, c
	ld	a, #0x00
	sbc	a, b
	jr	NC, 00104$
	C$Sprite.c$295$1_0$239	= .
	.globl	C$Sprite.c$295$1_0$239
;C:/ZGB-2023.0/common/src/Sprite.c:295: return 0;
	xor	a, a
	jr	00111$
00104$:
	C$Sprite.c$297$1_0$239	= .
	.globl	C$Sprite.c$297$1_0$239
;C:/ZGB-2023.0/common/src/Sprite.c:297: if( (diff + sprite1->coll_w) < 0 ||
	ldhl	sp,	#0
	ld	a, (hl)
	ld	c, a
	rlca
	sbc	a, a
	ld	b, a
	ldhl	sp,#5
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0011
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	ld	l, a
	add	hl, bc
	bit	7, h
	jr	NZ, 00105$
	C$Sprite.c$298$1_0$239	= .
	.globl	C$Sprite.c$298$1_0$239
;C:/ZGB-2023.0/common/src/Sprite.c:298: (sprite2->coll_w - diff) < 0) {
	ldhl	sp,#3
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0011
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
	ld	e, #0x00
	sub	a, c
	ld	a, e
	sbc	a, b
	bit	7,a
	jr	Z, 00106$
00105$:
	C$Sprite.c$299$2_0$240	= .
	.globl	C$Sprite.c$299$2_0$240
;C:/ZGB-2023.0/common/src/Sprite.c:299: return 0;
	xor	a, a
	jr	00111$
00106$:
	C$Sprite.c$302$1_0$239	= .
	.globl	C$Sprite.c$302$1_0$239
;C:/ZGB-2023.0/common/src/Sprite.c:302: diff = (INT8)diff16; 
	ldhl	sp,	#1
	ld	a, (hl)
	C$Sprite.c$303$1_0$239	= .
	.globl	C$Sprite.c$303$1_0$239
;C:/ZGB-2023.0/common/src/Sprite.c:303: if( (diff + sprite1->coll_h) < 0 ||
	ld	c, a
	rlca
	sbc	a, a
	ld	b, a
	ldhl	sp,#5
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0012
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	ld	l, a
	add	hl, bc
	bit	7, h
	jr	NZ, 00108$
	C$Sprite.c$304$1_0$239	= .
	.globl	C$Sprite.c$304$1_0$239
;C:/ZGB-2023.0/common/src/Sprite.c:304: (sprite2->coll_h - diff) < 0) {
	ldhl	sp,#3
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0012
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
	ld	e, #0x00
	sub	a, c
	ld	a, e
	sbc	a, b
	bit	7,a
	jr	Z, 00109$
00108$:
	C$Sprite.c$305$2_0$241	= .
	.globl	C$Sprite.c$305$2_0$241
;C:/ZGB-2023.0/common/src/Sprite.c:305: return 0;
	xor	a, a
	jr	00111$
00109$:
	C$Sprite.c$308$1_0$239	= .
	.globl	C$Sprite.c$308$1_0$239
;C:/ZGB-2023.0/common/src/Sprite.c:308: return 1;
	ld	a, #0x01
00111$:
	C$Sprite.c$309$1_0$239	= .
	.globl	C$Sprite.c$309$1_0$239
;C:/ZGB-2023.0/common/src/Sprite.c:309: }
	add	sp, #7
	C$Sprite.c$309$1_0$239	= .
	.globl	C$Sprite.c$309$1_0$239
	XG$CheckCollision$0$0	= .
	.globl	XG$CheckCollision$0$0
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
