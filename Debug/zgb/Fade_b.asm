;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module Fade_b
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl b_FadeOut_b
	.globl _FadeOut_b
	.globl _FadeOutColor
	.globl _FadeOutDMG
	.globl b_FadeIn_b
	.globl _FadeIn_b
	.globl _FadeInCOLOR
	.globl _FadeStepColor
	.globl _UpdateColor
	.globl _FadeInDMG
	.globl _FadeDMG
	.globl _FadeInOp
	.globl _DespRight
	.globl _set_sprite_palette
	.globl _set_bkg_palette
	.globl _delay
	.globl _ZGB_Fading_SPal
	.globl _ZGB_Fading_BPal
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
G$ZGB_Fading_BPal$0_0$0==.
_ZGB_Fading_BPal::
	.ds 64
G$ZGB_Fading_SPal$0_0$0==.
_ZGB_Fading_SPal::
	.ds 64
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
	.area _CODE_1
	G$FadeInOp$0$0	= .
	.globl	G$FadeInOp$0$0
	C$Fade_b.c$11$0_0$133	= .
	.globl	C$Fade_b.c$11$0_0$133
;C:/ZGB-2023.0/common/src/Fade_b.c:11: UINT8 FadeInOp(UINT16 c, UINT16 i) {
;	---------------------------------
; Function FadeInOp
; ---------------------------------
_FadeInOp::
	C$Fade_b.c$12$1_0$133	= .
	.globl	C$Fade_b.c$12$1_0$133
;C:/ZGB-2023.0/common/src/Fade_b.c:12: return U_LESS_THAN(c, i) ? 0: (c - i);
	ld	a, e
	sub	a, c
;	spillPairReg hl
;	spillPairReg hl
	ld	a, d
	sbc	a, b
	rlca
	jr	NC, 00103$
	xor	a, a
	ret
00103$:
	ld	a, e
	sub	a, c
	C$Fade_b.c$13$1_0$133	= .
	.globl	C$Fade_b.c$13$1_0$133
;C:/ZGB-2023.0/common/src/Fade_b.c:13: }
	C$Fade_b.c$13$1_0$133	= .
	.globl	C$Fade_b.c$13$1_0$133
	XG$FadeInOp$0$0	= .
	.globl	XG$FadeInOp$0$0
	ret
	G$FadeDMG$0$0	= .
	.globl	G$FadeDMG$0$0
	C$Fade_b.c$15$1_0$135	= .
	.globl	C$Fade_b.c$15$1_0$135
;C:/ZGB-2023.0/common/src/Fade_b.c:15: void FadeDMG(UINT8 fadeout) {
;	---------------------------------
; Function FadeDMG
; ---------------------------------
_FadeDMG::
	add	sp, #-29
	ldhl	sp,	#26
	ld	(hl), a
	C$Fade_b.c$17$2_0$135	= .
	.globl	C$Fade_b.c$17$2_0$135
;C:/ZGB-2023.0/common/src/Fade_b.c:17: UINT8* pals[] = {(UINT8*)0xFF47, (UINT8*)0xFF48, (UINT8*)0xFF49};
	ldhl	sp,	#12
	ld	a, #0x47
	ld	(hl+), a
	ld	a, #0xff
	ld	(hl+), a
	ld	a, #0x48
	ld	(hl+), a
	ld	a, #0xff
	ld	(hl+), a
	ld	a, #0x49
	ld	(hl+), a
	ld	(hl), #0xff
	C$Fade_b.c$19$2_0$135	= .
	.globl	C$Fade_b.c$19$2_0$135
;C:/ZGB-2023.0/common/src/Fade_b.c:19: UINT8* c = colors;
	ld	hl, #0
	add	hl, sp
	push	hl
	ld	a, l
	ldhl	sp,	#26
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#25
	ld	(hl), a
	C$Fade_b.c$23$2_0$135	= .
	.globl	C$Fade_b.c$23$2_0$135
;C:/ZGB-2023.0/common/src/Fade_b.c:23: for(i = 0; i != 3; ++i) {
	ldhl	sp,	#28
	ld	(hl), #0x00
00107$:
	C$Fade_b.c$24$3_0$137	= .
	.globl	C$Fade_b.c$24$3_0$137
;C:/ZGB-2023.0/common/src/Fade_b.c:24: p = (UINT8)*(pals[i]);
	ldhl	sp,	#28
	ld	a, (hl)
	ldhl	sp,	#22
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl-)
	dec	hl
	ld	(hl), a
	ldhl	sp,	#23
	ld	a, (hl-)
	dec	hl
	ld	(hl-), a
	sla	(hl)
	inc	hl
	rl	(hl)
	push	hl
	ld	hl, #14
	add	hl, sp
	ld	e, l
	ld	d, h
	pop	hl
	ldhl	sp,	#20
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#24
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#23
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	c, a
	inc	de
	ld	a, (de)
	ld	b, a
	ld	a, (bc)
	ld	(hl), a
	C$Fade_b.c$25$4_0$138	= .
	.globl	C$Fade_b.c$25$4_0$138
;C:/ZGB-2023.0/common/src/Fade_b.c:25: for(j = 0; j != 8; j += 2, ++c) {
	ldhl	sp,	#27
	ld	(hl), #0x00
	ldhl	sp,	#24
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
00105$:
	C$Fade_b.c$26$5_0$139	= .
	.globl	C$Fade_b.c$26$5_0$139
;C:/ZGB-2023.0/common/src/Fade_b.c:26: *c = (DespRight(p, j)) & 0x3;
	ldhl	sp,	#27
	ld	c, (hl)
	ld	b, #0x00
	ldhl	sp,	#23
	ld	a, (hl+)
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	push	de
	ld	e, (hl)
	ld	d, #0x00
	call	_DespRight
	pop	de
	ld	a, c
	and	a, #0x03
	ld	(de), a
	C$Fade_b.c$25$4_0$138	= .
	.globl	C$Fade_b.c$25$4_0$138
;C:/ZGB-2023.0/common/src/Fade_b.c:25: for(j = 0; j != 8; j += 2, ++c) {
	ldhl	sp,	#27
	ld	a, (hl)
	add	a, #0x02
	ld	(hl), a
	inc	de
	ld	a, (hl)
	sub	a, #0x08
	jr	NZ, 00105$
	C$Fade_b.c$23$2_0$135	= .
	.globl	C$Fade_b.c$23$2_0$135
;C:/ZGB-2023.0/common/src/Fade_b.c:23: for(i = 0; i != 3; ++i) {
	ldhl	sp,	#24
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
	ldhl	sp,	#28
	inc	(hl)
	ld	a, (hl)
	sub	a, #0x03
	jr	NZ, 00107$
	C$Fade_b.c$30$2_0$135	= .
	.globl	C$Fade_b.c$30$2_0$135
;C:/ZGB-2023.0/common/src/Fade_b.c:30: for(i = 0; i != 4; ++i) {
	ldhl	sp,	#27
	ld	(hl), #0x00
00111$:
	C$Fade_b.c$31$3_0$141	= .
	.globl	C$Fade_b.c$31$3_0$141
;C:/ZGB-2023.0/common/src/Fade_b.c:31: p = fadeout ? 3 - i : i;
	ldhl	sp,	#26
	ld	a, (hl)
	or	a, a
	jr	Z, 00115$
	inc	hl
	ld	c, (hl)
	ld	a, #0x03
	sub	a, c
	jr	00116$
00115$:
	ldhl	sp,	#27
	ld	a, (hl)
00116$:
	ldhl	sp,	#18
	ld	(hl), a
	C$Fade_b.c$32$2_0$135	= .
	.globl	C$Fade_b.c$32$2_0$135
;C:/ZGB-2023.0/common/src/Fade_b.c:32: for(j = 0; j != 3; ++j) {
	ldhl	sp,	#28
	ld	(hl), #0x00
00109$:
	C$Fade_b.c$33$5_0$143	= .
	.globl	C$Fade_b.c$33$5_0$143
;C:/ZGB-2023.0/common/src/Fade_b.c:33: c = &colors[j << 2];
	ldhl	sp,	#28
	ld	a, (hl)
	ldhl	sp,	#25
	ld	(hl), a
	sla	(hl)
	sla	(hl)
	ld	a, (hl)
	ldhl	sp,	#22
	ld	(hl+), a
	rlca
	sbc	a, a
	ld	(hl), a
	push	hl
	ld	hl, #2
	add	hl, sp
	ld	e, l
	ld	d, h
	pop	hl
	ldhl	sp,	#22
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#26
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#25
	ld	(hl-), a
	ld	a, (hl)
	ldhl	sp,	#19
	ld	(hl), a
	ldhl	sp,	#25
	ld	a, (hl)
	ldhl	sp,	#20
	ld	(hl), a
	C$Fade_b.c$34$5_0$143	= .
	.globl	C$Fade_b.c$34$5_0$143
;C:/ZGB-2023.0/common/src/Fade_b.c:34: *pals[j] = PAL_DEF(FadeInOp(c[0], p), FadeInOp(c[1], p), FadeInOp(c[2], p), FadeInOp(c[3], p));
	ldhl	sp,	#28
	ld	a, (hl)
	ldhl	sp,	#24
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl-)
	dec	hl
	ld	(hl), a
	ldhl	sp,	#25
	ld	a, (hl-)
	dec	hl
	ld	(hl-), a
	sla	(hl)
	inc	hl
	rl	(hl)
	push	hl
	ld	hl, #14
	add	hl, sp
	ld	e, l
	ld	d, h
	pop	hl
	ldhl	sp,	#22
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#26
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#25
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ldhl	sp,	#21
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	ldhl	sp,	#18
	ld	a, (hl)
	ldhl	sp,	#23
	ld	(hl+), a
	ld	(hl), #0x00
	ldhl	sp,	#19
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	inc	bc
	inc	bc
	inc	bc
	ld	a, (bc)
	ld	e, a
	ld	d, #0x00
	ldhl	sp,	#23
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	call	_FadeInOp
	swap	a
	and	a, #0xf0
	add	a, a
	add	a, a
	ldhl	sp,	#25
	ld	(hl), a
	ldhl	sp,	#19
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	inc	bc
	inc	bc
	ld	a, (bc)
	ld	e, a
	ld	d, #0x00
	ldhl	sp,	#23
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	call	_FadeInOp
	swap	a
	and	a, #0xf0
	ldhl	sp,	#25
	or	a, (hl)
	ld	(hl), a
	ldhl	sp,	#19
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	inc	bc
	ld	a, (bc)
	ld	e, a
	ld	d, #0x00
	ldhl	sp,	#23
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	call	_FadeInOp
	add	a, a
	add	a, a
	ldhl	sp,	#25
	or	a, (hl)
	ld	(hl), a
	ldhl	sp,#19
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	e, a
	ld	d, #0x00
	ldhl	sp,	#23
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	call	_FadeInOp
	ldhl	sp,	#25
	or	a, (hl)
	ld	c, a
	ldhl	sp,	#21
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	(hl), c
	C$Fade_b.c$32$4_0$142	= .
	.globl	C$Fade_b.c$32$4_0$142
;C:/ZGB-2023.0/common/src/Fade_b.c:32: for(j = 0; j != 3; ++j) {
	ldhl	sp,	#28
	inc	(hl)
	ld	a, (hl)
	sub	a, #0x03
	jp	NZ,00109$
	C$Fade_b.c$36$3_0$141	= .
	.globl	C$Fade_b.c$36$3_0$141
;C:/ZGB-2023.0/common/src/Fade_b.c:36: delay(50);
	ld	de, #0x0032
	call	_delay
	C$Fade_b.c$30$2_0$140	= .
	.globl	C$Fade_b.c$30$2_0$140
;C:/ZGB-2023.0/common/src/Fade_b.c:30: for(i = 0; i != 4; ++i) {
	ldhl	sp,	#27
	inc	(hl)
	ld	a, (hl)
	sub	a, #0x04
	jp	NZ,00111$
	C$Fade_b.c$38$2_0$135	= .
	.globl	C$Fade_b.c$38$2_0$135
;C:/ZGB-2023.0/common/src/Fade_b.c:38: }
	add	sp, #29
	C$Fade_b.c$38$2_0$135	= .
	.globl	C$Fade_b.c$38$2_0$135
	XG$FadeDMG$0$0	= .
	.globl	XG$FadeDMG$0$0
	ret
	G$FadeInDMG$0$0	= .
	.globl	G$FadeInDMG$0$0
	C$Fade_b.c$40$2_0$144	= .
	.globl	C$Fade_b.c$40$2_0$144
;C:/ZGB-2023.0/common/src/Fade_b.c:40: void FadeInDMG() {
;	---------------------------------
; Function FadeInDMG
; ---------------------------------
_FadeInDMG::
	C$Fade_b.c$41$1_0$144	= .
	.globl	C$Fade_b.c$41$1_0$144
;C:/ZGB-2023.0/common/src/Fade_b.c:41: FadeDMG(0);
	xor	a, a
	C$Fade_b.c$42$1_0$144	= .
	.globl	C$Fade_b.c$42$1_0$144
;C:/ZGB-2023.0/common/src/Fade_b.c:42: }
	C$Fade_b.c$42$1_0$144	= .
	.globl	C$Fade_b.c$42$1_0$144
	XG$FadeInDMG$0$0	= .
	.globl	XG$FadeInDMG$0$0
	jp	_FadeDMG
	G$UpdateColor$0$0	= .
	.globl	G$UpdateColor$0$0
	C$Fade_b.c$44$1_0$146	= .
	.globl	C$Fade_b.c$44$1_0$146
;C:/ZGB-2023.0/common/src/Fade_b.c:44: UWORD UpdateColor(UINT8 i, UWORD col) {
;	---------------------------------
; Function UpdateColor
; ---------------------------------
_UpdateColor::
	add	sp, #-4
	ld	c, a
	ldhl	sp,	#2
	ld	a, e
	ld	(hl+), a
	C$Fade_b.c$46$1_0$146	= .
	.globl	C$Fade_b.c$46$1_0$146
;C:/ZGB-2023.0/common/src/Fade_b.c:46: return RGB2(PAL_RED(col) | DespRight(0x1F, 5 - i), PAL_GREEN(col) | DespRight(0x1F, 5 - i), PAL_BLUE(col) | DespRight(0x1F, 5 - i));
	ld	a, d
	ld	(hl-), a
	ld	a, (hl)
	and	a, #0x1f
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
	ld	b, h
	ld	a, #0x05
	sub	a, c
	ld	c, a
	sbc	a, a
	sub	a, b
	ld	b, a
	push	hl
	push	bc
	ld	de, #0x001f
	call	_DespRight
	ld	e, c
	ld	d, b
	pop	bc
	pop	hl
	ld	a, l
	or	a, e
	push	hl
	ldhl	sp,	#2
	ld	(hl), a
	ldhl	sp,	#3
	ld	(hl), d
	pop	hl
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	srl	d
	rr	e
	srl	d
	rr	e
	srl	d
	rr	e
	srl	d
	rr	e
	srl	d
	rr	e
	ld	a, e
	and	a, #0x1f
	ld	e, a
	ld	d, #0x00
	push	bc
	push	de
	ld	de, #0x001f
	call	_DespRight
	ld	l, c
;	spillPairReg hl
;	spillPairReg hl
	ld	h, b
;	spillPairReg hl
;	spillPairReg hl
	pop	de
	pop	bc
	ld	a, l
	or	a, e
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	push	hl
	ldhl	sp,	#2
	ld	a, (hl)
	pop	hl
	or	a, l
	ld	e, a
	push	hl
	ldhl	sp,	#3
	ld	a, (hl)
	pop	hl
	or	a, h
	ld	d, a
	ldhl	sp,	#3
	ld	a, (hl)
	rrca
	rrca
	and	a, #0x3f
	ldhl	sp,	#0
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl)
	and	a, #0x1f
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	push	hl
	push	de
	ld	de, #0x001f
	call	_DespRight
	pop	de
	pop	hl
	ld	a, c
	or	a, l
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	ld	l, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, hl
	ld	a, l
	or	a, e
	ld	c, a
	ld	a, h
	or	a, d
	ld	b, a
	C$Fade_b.c$47$1_0$146	= .
	.globl	C$Fade_b.c$47$1_0$146
;C:/ZGB-2023.0/common/src/Fade_b.c:47: }
	add	sp, #4
	C$Fade_b.c$47$1_0$146	= .
	.globl	C$Fade_b.c$47$1_0$146
	XG$UpdateColor$0$0	= .
	.globl	XG$UpdateColor$0$0
	ret
	G$FadeStepColor$0$0	= .
	.globl	G$FadeStepColor$0$0
	C$Fade_b.c$49$1_0$148	= .
	.globl	C$Fade_b.c$49$1_0$148
;C:/ZGB-2023.0/common/src/Fade_b.c:49: void FadeStepColor(UINT8 i) {
;	---------------------------------
; Function FadeStepColor
; ---------------------------------
_FadeStepColor::
	add	sp, #-25
	ldhl	sp,	#18
	C$Fade_b.c$53$2_0$148	= .
	.globl	C$Fade_b.c$53$2_0$148
;C:/ZGB-2023.0/common/src/Fade_b.c:53: UWORD* col = ZGB_Fading_BPal;
	C$Fade_b.c$54$2_0$148	= .
	.globl	C$Fade_b.c$54$2_0$148
;C:/ZGB-2023.0/common/src/Fade_b.c:54: UWORD* col_s = ZGB_Fading_SPal;
	C$Fade_b.c$56$5_0$152	= .
	.globl	C$Fade_b.c$56$5_0$152
;C:/ZGB-2023.0/common/src/Fade_b.c:56: for(pal = 0; pal < 8; pal ++) {
	ld	(hl+), a
	ld	bc, #_ZGB_Fading_BPal+0
	ld	de, #_ZGB_Fading_SPal+0
	ld	(hl), #0x00
	C$Fade_b.c$57$1_0$148	= .
	.globl	C$Fade_b.c$57$1_0$148
;C:/ZGB-2023.0/common/src/Fade_b.c:57: for(c = 0; c < 4; ++c, ++col, ++col_s) {
00109$:
	ldhl	sp,	#20
	xor	a, a
	ld	(hl+), a
	ld	a, c
	ld	(hl+), a
	ld	a, b
	ld	(hl+), a
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
00103$:
	C$Fade_b.c$58$5_0$152	= .
	.globl	C$Fade_b.c$58$5_0$152
;C:/ZGB-2023.0/common/src/Fade_b.c:58: palette[c] = UpdateColor(i, *col);
	ldhl	sp,	#20
	ld	a, (hl)
	ld	c, #0x00
	add	a, a
	rl	c
	ldhl	sp,	#16
	ld	(hl+), a
	ld	(hl), c
	push	hl
	ld	hl, #2
	add	hl, sp
	ld	e, l
	ld	d, h
	pop	hl
	ldhl	sp,	#16
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, de
	ld	c, l
	ld	b, h
	ldhl	sp,#21
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
	ld	e, l
	ld	d, h
	ldhl	sp,	#20
	ld	a, (hl)
	call	_UpdateColor
	ld	e, c
	ld	d, b
	pop	bc
	ld	a, e
	ld	(bc), a
	inc	bc
	ld	a, d
	ld	(bc), a
	C$Fade_b.c$59$5_0$152	= .
	.globl	C$Fade_b.c$59$5_0$152
;C:/ZGB-2023.0/common/src/Fade_b.c:59: palette_s[c] = UpdateColor(i, *col_s);
	push	hl
	ld	hl, #10
	add	hl, sp
	ld	e, l
	ld	d, h
	pop	hl
	ldhl	sp,	#16
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, de
	ld	c, l
	ld	b, h
	ldhl	sp,#23
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
	ld	e, l
	ld	d, h
	ldhl	sp,	#20
	ld	a, (hl)
	call	_UpdateColor
	ld	e, c
	ld	d, b
	pop	bc
	ld	a, e
	ld	(bc), a
	inc	bc
	ld	a, d
	ld	(bc), a
	C$Fade_b.c$57$4_0$151	= .
	.globl	C$Fade_b.c$57$4_0$151
;C:/ZGB-2023.0/common/src/Fade_b.c:57: for(c = 0; c < 4; ++c, ++col, ++col_s) {
	ldhl	sp,	#20
	inc	(hl)
	inc	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0002
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#23
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#22
	ld	(hl+), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0002
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#25
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#24
	ld	(hl), a
	ldhl	sp,	#20
	ld	a, (hl)
	sub	a, #0x04
	jp	C, 00103$
	C$Fade_b.c$61$1_0$148	= .
	.globl	C$Fade_b.c$61$1_0$148
;C:/ZGB-2023.0/common/src/Fade_b.c:61: set_bkg_palette(pal, 1, palette);
	inc	hl
	ld	a, (hl+)
	ld	c, a
	ld	a, (hl+)
	ld	b, a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	bc
	push	de
	ld	hl, #4
	add	hl, sp
	push	hl
	ld	a, #0x01
	push	af
	inc	sp
	ldhl	sp,	#26
	ld	a, (hl)
	push	af
	inc	sp
	call	_set_bkg_palette
	add	sp, #4
	ld	hl, #12
	add	hl, sp
	push	hl
	ld	a, #0x01
	push	af
	inc	sp
	ldhl	sp,	#26
	ld	a, (hl)
	push	af
	inc	sp
	call	_set_sprite_palette
	add	sp, #4
	pop	de
	pop	bc
	C$Fade_b.c$56$2_0$149	= .
	.globl	C$Fade_b.c$56$2_0$149
;C:/ZGB-2023.0/common/src/Fade_b.c:56: for(pal = 0; pal < 8; pal ++) {
	ldhl	sp,	#19
	inc	(hl)
	ld	a, (hl)
	sub	a, #0x08
	jp	C, 00109$
	C$Fade_b.c$64$1_0$148	= .
	.globl	C$Fade_b.c$64$1_0$148
;C:/ZGB-2023.0/common/src/Fade_b.c:64: delay(20);
	ld	de, #0x0014
	call	_delay
	C$Fade_b.c$65$1_0$148	= .
	.globl	C$Fade_b.c$65$1_0$148
;C:/ZGB-2023.0/common/src/Fade_b.c:65: }
	add	sp, #25
	C$Fade_b.c$65$1_0$148	= .
	.globl	C$Fade_b.c$65$1_0$148
	XG$FadeStepColor$0$0	= .
	.globl	XG$FadeStepColor$0$0
	ret
	G$FadeInCOLOR$0$0	= .
	.globl	G$FadeInCOLOR$0$0
	C$Fade_b.c$67$1_0$154	= .
	.globl	C$Fade_b.c$67$1_0$154
;C:/ZGB-2023.0/common/src/Fade_b.c:67: void FadeInCOLOR() {
;	---------------------------------
; Function FadeInCOLOR
; ---------------------------------
_FadeInCOLOR::
	C$Fade_b.c$69$2_0$154	= .
	.globl	C$Fade_b.c$69$2_0$154
;C:/ZGB-2023.0/common/src/Fade_b.c:69: for(i = 0; i != 6; i ++) {
	ld	c, #0x00
00102$:
	C$Fade_b.c$70$3_0$155	= .
	.globl	C$Fade_b.c$70$3_0$155
;C:/ZGB-2023.0/common/src/Fade_b.c:70: FadeStepColor(i);	
	push	bc
	ld	a, c
	call	_FadeStepColor
	pop	bc
	C$Fade_b.c$69$2_0$154	= .
	.globl	C$Fade_b.c$69$2_0$154
;C:/ZGB-2023.0/common/src/Fade_b.c:69: for(i = 0; i != 6; i ++) {
	inc	c
	ld	a, c
	sub	a, #0x06
	jr	NZ, 00102$
	C$Fade_b.c$72$2_0$154	= .
	.globl	C$Fade_b.c$72$2_0$154
;C:/ZGB-2023.0/common/src/Fade_b.c:72: }
	C$Fade_b.c$72$2_0$154	= .
	.globl	C$Fade_b.c$72$2_0$154
	XG$FadeInCOLOR$0$0	= .
	.globl	XG$FadeInCOLOR$0$0
	ret
	G$FadeIn_b$0$0	= .
	.globl	G$FadeIn_b$0$0
	C$Fade_b.c$74$2_0$156	= .
	.globl	C$Fade_b.c$74$2_0$156
;C:/ZGB-2023.0/common/src/Fade_b.c:74: void FadeIn_b() BANKED{
;	---------------------------------
; Function FadeIn_b
; ---------------------------------
	b_FadeIn_b	= 1
_FadeIn_b::
	C$Fade_b.c$80$1_0$156	= .
	.globl	C$Fade_b.c$80$1_0$156
;C:/ZGB-2023.0/common/src/Fade_b.c:80: FadeInDMG();
	C$Fade_b.c$81$1_0$156	= .
	.globl	C$Fade_b.c$81$1_0$156
;C:/ZGB-2023.0/common/src/Fade_b.c:81: }
	C$Fade_b.c$81$1_0$156	= .
	.globl	C$Fade_b.c$81$1_0$156
	XG$FadeIn_b$0$0	= .
	.globl	XG$FadeIn_b$0$0
	jp	_FadeInDMG
	G$FadeOutDMG$0$0	= .
	.globl	G$FadeOutDMG$0$0
	C$Fade_b.c$83$1_0$157	= .
	.globl	C$Fade_b.c$83$1_0$157
;C:/ZGB-2023.0/common/src/Fade_b.c:83: void FadeOutDMG() {
;	---------------------------------
; Function FadeOutDMG
; ---------------------------------
_FadeOutDMG::
	C$Fade_b.c$84$1_0$157	= .
	.globl	C$Fade_b.c$84$1_0$157
;C:/ZGB-2023.0/common/src/Fade_b.c:84: FadeDMG(1);
	ld	a, #0x01
	C$Fade_b.c$85$1_0$157	= .
	.globl	C$Fade_b.c$85$1_0$157
;C:/ZGB-2023.0/common/src/Fade_b.c:85: }
	C$Fade_b.c$85$1_0$157	= .
	.globl	C$Fade_b.c$85$1_0$157
	XG$FadeOutDMG$0$0	= .
	.globl	XG$FadeOutDMG$0$0
	jp	_FadeDMG
	G$FadeOutColor$0$0	= .
	.globl	G$FadeOutColor$0$0
	C$Fade_b.c$87$1_0$159	= .
	.globl	C$Fade_b.c$87$1_0$159
;C:/ZGB-2023.0/common/src/Fade_b.c:87: void FadeOutColor() {
;	---------------------------------
; Function FadeOutColor
; ---------------------------------
_FadeOutColor::
	C$Fade_b.c$89$2_0$159	= .
	.globl	C$Fade_b.c$89$2_0$159
;C:/ZGB-2023.0/common/src/Fade_b.c:89: for(i = 5; i != 0xFF; -- i) {
	ld	c, #0x05
00102$:
	C$Fade_b.c$90$3_0$160	= .
	.globl	C$Fade_b.c$90$3_0$160
;C:/ZGB-2023.0/common/src/Fade_b.c:90: FadeStepColor(i);	
	push	bc
	ld	a, c
	call	_FadeStepColor
	pop	bc
	C$Fade_b.c$89$2_0$159	= .
	.globl	C$Fade_b.c$89$2_0$159
;C:/ZGB-2023.0/common/src/Fade_b.c:89: for(i = 5; i != 0xFF; -- i) {
	dec	c
	ld	a, c
	inc	a
	jr	NZ, 00102$
	C$Fade_b.c$92$2_0$159	= .
	.globl	C$Fade_b.c$92$2_0$159
;C:/ZGB-2023.0/common/src/Fade_b.c:92: }
	C$Fade_b.c$92$2_0$159	= .
	.globl	C$Fade_b.c$92$2_0$159
	XG$FadeOutColor$0$0	= .
	.globl	XG$FadeOutColor$0$0
	ret
	G$FadeOut_b$0$0	= .
	.globl	G$FadeOut_b$0$0
	C$Fade_b.c$94$2_0$161	= .
	.globl	C$Fade_b.c$94$2_0$161
;C:/ZGB-2023.0/common/src/Fade_b.c:94: void FadeOut_b() BANKED{
;	---------------------------------
; Function FadeOut_b
; ---------------------------------
	b_FadeOut_b	= 1
_FadeOut_b::
	C$Fade_b.c$100$1_0$161	= .
	.globl	C$Fade_b.c$100$1_0$161
;C:/ZGB-2023.0/common/src/Fade_b.c:100: FadeOutDMG();
	C$Fade_b.c$101$1_0$161	= .
	.globl	C$Fade_b.c$101$1_0$161
;C:/ZGB-2023.0/common/src/Fade_b.c:101: }
	C$Fade_b.c$101$1_0$161	= .
	.globl	C$Fade_b.c$101$1_0$161
	XG$FadeOut_b$0$0	= .
	.globl	XG$FadeOut_b$0$0
	jp	_FadeOutDMG
	.area _CODE_1
	.area _INITIALIZER
	.area _CABS (ABS)
