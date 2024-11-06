;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module SGB
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _set_sgb_border
	.globl _PopBank
	.globl _PushBank
	.globl _memset
	.globl _sgb_transfer
	.globl _sgb_check
	.globl _fill_bkg_rect
	.globl _set_bkg_tiles
	.globl _set_bkg_data
	.globl _LoadSGBBorder
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
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
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
	G$set_sgb_border$0$0	= .
	.globl	G$set_sgb_border$0$0
	C$SGB.c$18$0_0$140	= .
	.globl	C$SGB.c$18$0_0$140
;C:/ZGB-2023.0/common/src/SGB.c:18: void set_sgb_border(unsigned char * tiledata, size_t tiledata_size,
;	---------------------------------
; Function set_sgb_border
; ---------------------------------
_set_sgb_border::
	add	sp, #-27
	ldhl	sp,	#20
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
	ldhl	sp,	#25
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	C$SGB.c$21$1_0$140	= .
	.globl	C$SGB.c$21$1_0$140
;C:/ZGB-2023.0/common/src/SGB.c:21: if (sgb_check()) {
	call	_sgb_check
	ldhl	sp,#24
	ld	(hl), e
	ld	a, (hl)
	or	a, a
	jp	Z, 00117$
	C$SGB.c$23$2_0$141	= .
	.globl	C$SGB.c$23$2_0$141
;C:/ZGB-2023.0/common/src/SGB.c:23: memset(map_buf, 0, sizeof(map_buf));
	ld	hl, #0
	add	hl, sp
	ld	de, #0x0014
	push	de
	ld	de, #0x0000
	push	de
	push	hl
	call	_memset
	add	sp, #6
	C$SGB.c$25$2_0$141	= .
	.globl	C$SGB.c$25$2_0$141
;C:/ZGB-2023.0/common/src/SGB.c:25: SGB_TRANSFER((SGB_MASK_EN << 3) | 1, SGB_SCR_FREEZE); 
	ldhl	sp,	#0
	ld	a, #0xb9
	ld	(hl+), a
	ld	(hl), #0x01
	ld	hl, #0
	add	hl, sp
	push	hl
	call	_sgb_transfer
	pop	hl
	C$SGB.c$27$2_0$141	= .
	.globl	C$SGB.c$27$2_0$141
;C:/ZGB-2023.0/common/src/SGB.c:27: BGP_REG = OBP0_REG = OBP1_REG = 0xE4U;
	ld	a, #0xe4
	ldh	(_OBP1_REG + 0), a
	ld	a, #0xe4
	ldh	(_OBP0_REG + 0), a
	ld	a, #0xe4
	ldh	(_BGP_REG + 0), a
	C$SGB.c$28$2_0$141	= .
	.globl	C$SGB.c$28$2_0$141
;C:/ZGB-2023.0/common/src/SGB.c:28: SCX_REG = SCY_REG = 0U;
	xor	a, a
	ldh	(_SCY_REG + 0), a
	xor	a, a
	ldh	(_SCX_REG + 0), a
	C$SGB.c$30$3_0$142	= .
	.globl	C$SGB.c$30$3_0$142
;C:/ZGB-2023.0/common/src/SGB.c:30: uint8_t tmp_lcdc = LCDC_REG;
	ldh	a, (_LCDC_REG + 0)
	ldhl	sp,	#22
	ld	(hl), a
	C$SGB.c$32$2_1$142	= .
	.globl	C$SGB.c$32$2_1$142
;C:/ZGB-2023.0/common/src/SGB.c:32: HIDE_SPRITES, HIDE_WIN, SHOW_BKG;
	ldh	a, (_LCDC_REG + 0)
	and	a, #0xfd
	ldh	(_LCDC_REG + 0), a
	ldh	a, (_LCDC_REG + 0)
	and	a, #0xdf
	ldh	(_LCDC_REG + 0), a
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x01
	ldh	(_LCDC_REG + 0), a
	C$SGB.c$33$2_1$142	= .
	.globl	C$SGB.c$33$2_1$142
;C:/ZGB-2023.0/common/src/SGB.c:33: DISPLAY_ON;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x80
	ldh	(_LCDC_REG + 0), a
	C$SGB.c$35$3_1$143	= .
	.globl	C$SGB.c$35$3_1$143
;C:/ZGB-2023.0/common/src/SGB.c:35: uint8_t i = 0U;
	C$SGB.c$36$5_2$145	= .
	.globl	C$SGB.c$36$5_2$145
;C:/ZGB-2023.0/common/src/SGB.c:36: for (uint8_t y = 0; y != 14U; ++y) {
	ld	bc, #0x0
00115$:
	ld	a, b
	sub	a, #0x0e
	jr	Z, 00102$
	C$SGB.c$37$5_2$145	= .
	.globl	C$SGB.c$37$5_2$145
;C:/ZGB-2023.0/common/src/SGB.c:37: uint8_t * dout = map_buf;
	ld	hl, #0
	add	hl, sp
	ld	e, l
	ld	d, h
	C$SGB.c$38$1_0$140	= .
	.globl	C$SGB.c$38$1_0$140
;C:/ZGB-2023.0/common/src/SGB.c:38: for (uint8_t x = 0U; x != 20U; ++x) {
	xor	a, a
00112$:
	cp	a, #0x14
	jr	Z, 00129$
	C$SGB.c$39$6_2$147	= .
	.globl	C$SGB.c$39$6_2$147
;C:/ZGB-2023.0/common/src/SGB.c:39: *dout++ = i++;
	push	af
	ld	a, c
	ld	(de), a
	pop	af
	inc	c
	inc	de
	C$SGB.c$38$5_2$146	= .
	.globl	C$SGB.c$38$5_2$146
;C:/ZGB-2023.0/common/src/SGB.c:38: for (uint8_t x = 0U; x != 20U; ++x) {
	inc	a
	jr	00112$
00129$:
	C$SGB.c$41$4_2$145	= .
	.globl	C$SGB.c$41$4_2$145
;C:/ZGB-2023.0/common/src/SGB.c:41: set_bkg_tiles(0, y, 20, 1, map_buf);
	ld	hl, #0
	add	hl, sp
	push	hl
	ld	hl, #0x114
	push	hl
	push	bc
	inc	sp
	xor	a, a
	push	af
	inc	sp
	call	_set_bkg_tiles
	add	sp, #6
	C$SGB.c$36$3_2$144	= .
	.globl	C$SGB.c$36$3_2$144
;C:/ZGB-2023.0/common/src/SGB.c:36: for (uint8_t y = 0; y != 14U; ++y) {
	inc	b
	jr	00115$
00102$:
	C$SGB.c$43$2_2$143	= .
	.globl	C$SGB.c$43$2_2$143
;C:/ZGB-2023.0/common/src/SGB.c:43: memset(map_buf, 0, sizeof(map_buf));
	ld	hl, #0
	add	hl, sp
	ld	de, #0x0014
	push	de
	ld	de, #0x0000
	push	de
	push	hl
	call	_memset
	add	sp, #6
	C$SGB.c$46$2_3$148	= .
	.globl	C$SGB.c$46$2_3$148
;C:/ZGB-2023.0/common/src/SGB.c:46: uint8_t ntiles = (tiledata_size > 256 * 32) ? 0 : tiledata_size >> 5;
	ldhl	sp,	#25
	xor	a, a
	sub	a, (hl)
	inc	hl
	ld	a, #0x20
	sbc	a, (hl)
	jr	NC, 00119$
	xor	a, a
	ldhl	sp,	#23
	ld	(hl+), a
	ld	(hl), a
	jr	00120$
00119$:
	ldhl	sp,	#25
	ld	a, (hl-)
	dec	hl
	ld	(hl), a
	ldhl	sp,	#26
	ld	a, (hl-)
	dec	hl
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
	inc	hl
	srl	(hl)
	dec	hl
	rr	(hl)
	inc	hl
	srl	(hl)
	dec	hl
	rr	(hl)
00120$:
	ldhl	sp,	#23
	ld	c, (hl)
	C$SGB.c$47$2_3$148	= .
	.globl	C$SGB.c$47$2_3$148
;C:/ZGB-2023.0/common/src/SGB.c:47: if ((!ntiles) || (ntiles > 128U)) { 
	ld	a, c
	or	a, a
	jr	Z, 00105$
	ld	a, #0x80
	sub	a, c
	jr	NC, 00106$
00105$:
	C$SGB.c$48$3_3$149	= .
	.globl	C$SGB.c$48$3_3$149
;C:/ZGB-2023.0/common/src/SGB.c:48: set_bkg_data(0, 0, tiledata); 
	ldhl	sp,	#20
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	xor	a, a
	rrca
	push	af
	call	_set_bkg_data
	add	sp, #4
	C$SGB.c$49$3_3$149	= .
	.globl	C$SGB.c$49$3_3$149
;C:/ZGB-2023.0/common/src/SGB.c:49: SGB_TRANSFER((SGB_CHR_TRN << 3) | 1, SGB_CHR_BLOCK0);
	ldhl	sp,	#0
	ld	a, #0x99
	ld	(hl+), a
	ld	(hl), #0x00
	ld	hl, #0
	add	hl, sp
	push	hl
	call	_sgb_transfer
	pop	hl
	C$SGB.c$50$3_3$149	= .
	.globl	C$SGB.c$50$3_3$149
;C:/ZGB-2023.0/common/src/SGB.c:50: if (ntiles) ntiles -= 128U; 
	ld	a, c
	or	a, a
	jr	Z, 00104$
	ld	a, c
	add	a, #0x80
	ld	c, a
00104$:
	C$SGB.c$51$3_3$149	= .
	.globl	C$SGB.c$51$3_3$149
;C:/ZGB-2023.0/common/src/SGB.c:51: tiledata += (128 * 32);
	ldhl	sp,#20
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x1000
	add	hl, de
	ld	e, l
	ld	d, h
	C$SGB.c$52$3_3$149	= .
	.globl	C$SGB.c$52$3_3$149
;C:/ZGB-2023.0/common/src/SGB.c:52: set_bkg_data(0, ntiles << 1, tiledata); 
	ld	a, c
	add	a, a
	push	de
	ld	h, a
	ld	l, #0x00
	push	hl
	call	_set_bkg_data
	add	sp, #4
	C$SGB.c$53$3_3$149	= .
	.globl	C$SGB.c$53$3_3$149
;C:/ZGB-2023.0/common/src/SGB.c:53: SGB_TRANSFER((SGB_CHR_TRN << 3) | 1, SGB_CHR_BLOCK1);
	ldhl	sp,	#0
	ld	a, #0x99
	ld	(hl+), a
	ld	(hl), #0x01
	ld	hl, #0
	add	hl, sp
	push	hl
	call	_sgb_transfer
	pop	hl
	jr	00107$
00106$:
	C$SGB.c$55$3_3$150	= .
	.globl	C$SGB.c$55$3_3$150
;C:/ZGB-2023.0/common/src/SGB.c:55: set_bkg_data(0, ntiles << 1, tiledata); 
	ld	a, c
	add	a, a
	ldhl	sp,	#20
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	push	de
	ld	h, a
	ld	l, #0x00
	push	hl
	call	_set_bkg_data
	add	sp, #4
	C$SGB.c$56$3_3$150	= .
	.globl	C$SGB.c$56$3_3$150
;C:/ZGB-2023.0/common/src/SGB.c:56: SGB_TRANSFER((SGB_CHR_TRN << 3) | 1, SGB_CHR_BLOCK0);
	ldhl	sp,	#0
	ld	a, #0x99
	ld	(hl+), a
	ld	(hl), #0x00
	ld	hl, #0
	add	hl, sp
	push	hl
	call	_sgb_transfer
	pop	hl
00107$:
	C$SGB.c$60$2_3$148	= .
	.globl	C$SGB.c$60$2_3$148
;C:/ZGB-2023.0/common/src/SGB.c:60: set_bkg_data(0, (uint8_t)(tilemap_size >> 4), tilemap);
	ldhl	sp,	#31
	ld	a, (hl+)
	ld	b, a
	ld	c, (hl)
	srl	c
	rr	b
	srl	c
	rr	b
	srl	c
	rr	b
	srl	c
	rr	b
	ldhl	sp,	#29
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	push	bc
	inc	sp
	xor	a, a
	push	af
	inc	sp
	call	_set_bkg_data
	add	sp, #4
	C$SGB.c$61$2_3$148	= .
	.globl	C$SGB.c$61$2_3$148
;C:/ZGB-2023.0/common/src/SGB.c:61: set_bkg_data(128, (uint8_t)(palette_size >> 4), palette);
	ldhl	sp,	#35
	ld	a, (hl+)
	ld	b, a
	ld	c, (hl)
	srl	c
	rr	b
	srl	c
	rr	b
	srl	c
	rr	b
	srl	c
	rr	b
	ldhl	sp,	#33
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	push	bc
	inc	sp
	ld	a, #0x80
	push	af
	inc	sp
	call	_set_bkg_data
	add	sp, #4
	C$SGB.c$62$2_3$148	= .
	.globl	C$SGB.c$62$2_3$148
;C:/ZGB-2023.0/common/src/SGB.c:62: SGB_TRANSFER((SGB_PCT_TRN << 3) | 1, 0);
	ldhl	sp,	#0
	ld	a, #0xa1
	ld	(hl+), a
	ld	(hl), #0x00
	ld	hl, #0
	add	hl, sp
	push	hl
	call	_sgb_transfer
	pop	hl
	C$SGB.c$64$2_3$148	= .
	.globl	C$SGB.c$64$2_3$148
;C:/ZGB-2023.0/common/src/SGB.c:64: LCDC_REG = tmp_lcdc;
	ldhl	sp,	#22
	ld	a, (hl)
	ldh	(_LCDC_REG + 0), a
	C$SGB.c$67$2_3$148	= .
	.globl	C$SGB.c$67$2_3$148
;C:/ZGB-2023.0/common/src/SGB.c:67: fill_bkg_rect(0, 0, 20, 18, 0);
	xor	a, a
	ld	h, a
	ld	l, #0x12
	push	hl
	ld	a, #0x14
	push	af
	inc	sp
	xor	a, a
	rrca
	push	af
	xor	a, a
	call	_fill_bkg_rect
	add	sp, #5
	C$SGB.c$69$2_3$148	= .
	.globl	C$SGB.c$69$2_3$148
;C:/ZGB-2023.0/common/src/SGB.c:69: SGB_TRANSFER((SGB_MASK_EN << 3) | 1, SGB_SCR_UNFREEZE); 
	ldhl	sp,	#0
	ld	(hl), #0xb9
	inc	hl
	ld	(hl), #0x00
	ld	hl, #0
	add	hl, sp
	push	hl
	call	_sgb_transfer
	pop	hl
00117$:
	C$SGB.c$71$1_0$140	= .
	.globl	C$SGB.c$71$1_0$140
;C:/ZGB-2023.0/common/src/SGB.c:71: }
	add	sp, #27
	pop	hl
	add	sp, #8
	jp	(hl)
	G$LoadSGBBorder$0$0	= .
	.globl	G$LoadSGBBorder$0$0
	C$SGB.c$73$1_0$152	= .
	.globl	C$SGB.c$73$1_0$152
;C:/ZGB-2023.0/common/src/SGB.c:73: void LoadSGBBorder(UINT8 map_bank, struct MapInfo* map) {
;	---------------------------------
; Function LoadSGBBorder
; ---------------------------------
_LoadSGBBorder::
	add	sp, #-12
	ldhl	sp,	#10
	ld	(hl), e
	inc	hl
	ld	(hl), d
	C$SGB.c$74$1_0$152	= .
	.globl	C$SGB.c$74$1_0$152
;C:/ZGB-2023.0/common/src/SGB.c:74: PUSH_BANK(map_bank);
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	C$SGB.c$75$1_0$152	= .
	.globl	C$SGB.c$75$1_0$152
;C:/ZGB-2023.0/common/src/SGB.c:75: set_sgb_border(map->tiles->data, map->tiles->num_frames << 5, map->data, 1792, map->tiles->pals, map->tiles->num_pals << 5);
	ldhl	sp,#10
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0007
	add	hl, de
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	e, c
	ld	d, b
	inc	de
	inc	de
	inc	de
	ld	a, (de)
	ld	e, #0x00
	add	a, a
	rl	e
	add	a, a
	rl	e
	add	a, a
	rl	e
	add	a, a
	rl	e
	add	a, a
	rl	e
	ldhl	sp,	#0
	ld	(hl+), a
	ld	(hl), e
	ld	hl, #0x0004
	add	hl, bc
	ld	e, l
	ld	d, h
	ld	a, (de)
	ldhl	sp,	#8
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	ldhl	sp,	#8
	ld	a, (hl)
	ldhl	sp,	#2
	ld	(hl), a
	ldhl	sp,	#9
	ld	a, (hl)
	ldhl	sp,	#3
	ld	(hl), a
	ldhl	sp,#10
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ldhl	sp,	#4
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl+), a
	ld	a, (bc)
	ld	e, #0x00
	add	a, a
	rl	e
	add	a, a
	rl	e
	add	a, a
	rl	e
	add	a, a
	rl	e
	add	a, a
	rl	e
	ld	(hl+), a
	ld	a, e
	ld	(hl+), a
	inc	bc
	ld	e, c
	ld	d, b
	ld	a, (de)
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	pop	de
	push	de
	push	de
	ldhl	sp,	#4
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl+)
	ld	d, a
	push	de
	ld	de, #0x0700
	push	de
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl+)
	ld	d, a
	push	de
	ld	a, (hl+)
	ld	c, a
	ld	a, (hl+)
	ld	b, a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	_set_sgb_border
	C$SGB.c$76$1_0$152	= .
	.globl	C$SGB.c$76$1_0$152
;C:/ZGB-2023.0/common/src/SGB.c:76: POP_BANK;
	call	_PopBank
	C$SGB.c$77$1_0$152	= .
	.globl	C$SGB.c$77$1_0$152
;C:/ZGB-2023.0/common/src/SGB.c:77: }
	add	sp, #12
	C$SGB.c$77$1_0$152	= .
	.globl	C$SGB.c$77$1_0$152
	XG$LoadSGBBorder$0$0	= .
	.globl	XG$LoadSGBBorder$0$0
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
