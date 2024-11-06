;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module OAMManager
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _memset
	.globl _oam_end
	.globl _oam1
	.globl _oam0
	.globl _oam
	.globl _next_oam_idx
	.globl _oam_mirror
	.globl _SwapOAMs
	.globl _ClearOAMs
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
G$oam_mirror$0_0$0 == 0xdf00
_oam_mirror	=	0xdf00
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
G$next_oam_idx$0_0$0==.
_next_oam_idx::
	.ds 1
G$oam$0_0$0==.
_oam::
	.ds 2
G$oam0$0_0$0==.
_oam0::
	.ds 2
G$oam1$0_0$0==.
_oam1::
	.ds 2
G$oam_end$0_0$0==.
_oam_end::
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
	G$SwapOAMs$0$0	= .
	.globl	G$SwapOAMs$0$0
	C$OAMManager.c$21$0_0$185	= .
	.globl	C$OAMManager.c$21$0_0$185
;C:/ZGB-2023.0/common/src/OAMManager.c:21: void SwapOAMs() {
;	---------------------------------
; Function SwapOAMs
; ---------------------------------
_SwapOAMs::
	C$OAMManager.c$23$1_0$185	= .
	.globl	C$OAMManager.c$23$1_0$185
;C:/ZGB-2023.0/common/src/OAMManager.c:23: oam += (next_oam_idx << 2);
	ld	hl, #_next_oam_idx
	ld	l, (hl)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, hl
	ld	c, l
	ld	b, h
	ld	hl, #_oam
	ld	a, (hl)
	add	a, c
	ld	(hl+), a
	ld	a, (hl)
	adc	a, b
	C$OAMManager.c$24$2_0$186	= .
	.globl	C$OAMManager.c$24$2_0$186
;C:/ZGB-2023.0/common/src/OAMManager.c:24: UINT8* tmp = oam;
	ld	(hl-), a
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	C$OAMManager.c$25$1_1$186	= .
	.globl	C$OAMManager.c$25$1_1$186
;C:/ZGB-2023.0/common/src/OAMManager.c:25: while(oam < oam_end) { //TODO: check if memset is faster
00101$:
	ld	de, #_oam
	ld	hl, #_oam_end
	ld	a, (de)
	inc	de
	sub	a, (hl)
	inc	hl
	ld	a, (de)
	sbc	a, (hl)
	jr	NC, 00103$
	C$OAMManager.c$26$2_1$187	= .
	.globl	C$OAMManager.c$26$2_1$187
;C:/ZGB-2023.0/common/src/OAMManager.c:26: *oam = 0;
	ld	hl, #_oam
	ld	a, (hl+)
	ld	e, a
	C$OAMManager.c$27$2_1$187	= .
	.globl	C$OAMManager.c$27$2_1$187
;C:/ZGB-2023.0/common/src/OAMManager.c:27: oam += 4;
	ld	a, (hl-)
	ld	d, a
	xor	a, a
	ld	(de), a
	ld	a, (hl)
	add	a, #0x04
	ld	(hl+), a
	ld	a, (hl)
	adc	a, #0x00
	ld	(hl), a
	jr	00101$
00103$:
	C$OAMManager.c$30$1_1$186	= .
	.globl	C$OAMManager.c$30$1_1$186
;C:/ZGB-2023.0/common/src/OAMManager.c:30: if((0xFF00 & (UINT16)oam) == 0xC000) {
	ld	hl, #_oam
	ld	a, (hl+)
	ld	e, (hl)
	ld	d, #0x00
	ld	a, d
	or	a, a
	jr	NZ, 00105$
	ld	a, e
	sub	a, #0xc0
	jr	NZ, 00105$
;c:\zgb-2023.0\env\gbdk\include\gb\gb.h:1784: _shadow_OAM_base = (uint8_t)((uint16_t)address >> 8);
	ld	a, #0xc0
	ldh	(__shadow_OAM_base + 0), a
	C$OAMManager.c$32$2_1$188	= .
	.globl	C$OAMManager.c$32$2_1$188
;C:/ZGB-2023.0/common/src/OAMManager.c:32: oam0 = tmp;
	ld	hl, #_oam0
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	C$OAMManager.c$33$2_1$188	= .
	.globl	C$OAMManager.c$33$2_1$188
;C:/ZGB-2023.0/common/src/OAMManager.c:33: oam = (UINT8*)OAM_MIRROR_ADDRESS;
	ld	hl, #_oam
	xor	a, a
	ld	(hl+), a
	ld	(hl), #0xdf
	C$OAMManager.c$34$2_1$188	= .
	.globl	C$OAMManager.c$34$2_1$188
;C:/ZGB-2023.0/common/src/OAMManager.c:34: oam_end = oam1;
	ld	a, (#_oam1)
	ld	(#_oam_end),a
	ld	a, (#_oam1 + 1)
	ld	(#_oam_end + 1),a
	jr	00106$
00105$:
;c:\zgb-2023.0\env\gbdk\include\gb\gb.h:1784: _shadow_OAM_base = (uint8_t)((uint16_t)address >> 8);
	ld	a, #0xdf
	ldh	(__shadow_OAM_base + 0), a
	C$OAMManager.c$37$2_1$189	= .
	.globl	C$OAMManager.c$37$2_1$189
;C:/ZGB-2023.0/common/src/OAMManager.c:37: oam1 = tmp;
	ld	hl, #_oam1
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	C$OAMManager.c$38$2_1$189	= .
	.globl	C$OAMManager.c$38$2_1$189
;C:/ZGB-2023.0/common/src/OAMManager.c:38: oam = (UINT8*)0xC000;
	ld	hl, #_oam
	xor	a, a
	ld	(hl+), a
	ld	(hl), #0xc0
	C$OAMManager.c$39$2_1$189	= .
	.globl	C$OAMManager.c$39$2_1$189
;C:/ZGB-2023.0/common/src/OAMManager.c:39: oam_end = oam0;
	ld	a, (#_oam0)
	ld	(#_oam_end),a
	ld	a, (#_oam0 + 1)
	ld	(#_oam_end + 1),a
00106$:
	C$OAMManager.c$41$1_1$186	= .
	.globl	C$OAMManager.c$41$1_1$186
;C:/ZGB-2023.0/common/src/OAMManager.c:41: __render_shadow_OAM = ((UWORD)oam) >> 8;
	ld	hl, #_oam
	ld	a, (hl+)
	ld	c, (hl)
	ld	hl, #___render_shadow_OAM
	ld	(hl), c
	C$OAMManager.c$42$1_1$186	= .
	.globl	C$OAMManager.c$42$1_1$186
;C:/ZGB-2023.0/common/src/OAMManager.c:42: next_oam_idx = 0;
	ld	hl, #_next_oam_idx
	ld	(hl), #0x00
	C$OAMManager.c$44$1_1$186	= .
	.globl	C$OAMManager.c$44$1_1$186
;C:/ZGB-2023.0/common/src/OAMManager.c:44: scroll_x_vblank = scroll_x;
	ld	a, (#_scroll_x)
	ld	(#_scroll_x_vblank),a
	C$OAMManager.c$45$1_1$186	= .
	.globl	C$OAMManager.c$45$1_1$186
;C:/ZGB-2023.0/common/src/OAMManager.c:45: scroll_y_vblank = scroll_y;
	ld	a, (#_scroll_y)
	ld	(#_scroll_y_vblank),a
	C$OAMManager.c$46$1_1$185	= .
	.globl	C$OAMManager.c$46$1_1$185
;C:/ZGB-2023.0/common/src/OAMManager.c:46: }
	C$OAMManager.c$46$1_1$185	= .
	.globl	C$OAMManager.c$46$1_1$185
	XG$SwapOAMs$0$0	= .
	.globl	XG$SwapOAMs$0$0
	ret
	G$ClearOAMs$0$0	= .
	.globl	G$ClearOAMs$0$0
	C$OAMManager.c$48$1_1$196	= .
	.globl	C$OAMManager.c$48$1_1$196
;C:/ZGB-2023.0/common/src/OAMManager.c:48: void ClearOAMs() {
;	---------------------------------
; Function ClearOAMs
; ---------------------------------
_ClearOAMs::
	C$OAMManager.c$49$1_0$196	= .
	.globl	C$OAMManager.c$49$1_0$196
;C:/ZGB-2023.0/common/src/OAMManager.c:49: oam0 = (UINT8*)0xC000;
	ld	hl, #_oam0
	xor	a, a
	ld	(hl+), a
	ld	(hl), #0xc0
	C$OAMManager.c$50$1_0$196	= .
	.globl	C$OAMManager.c$50$1_0$196
;C:/ZGB-2023.0/common/src/OAMManager.c:50: oam1 = (UINT8*)OAM_MIRROR_ADDRESS;
	ld	hl, #_oam1
	xor	a, a
	ld	(hl+), a
	ld	(hl), #0xdf
	C$OAMManager.c$51$1_0$196	= .
	.globl	C$OAMManager.c$51$1_0$196
;C:/ZGB-2023.0/common/src/OAMManager.c:51: memset(oam0, 0, sizeof(oam_mirror));
	xor	a, a
	and	a
	push	af
	ld	de, #0x0000
	push	de
	ld	de, #0xc000
	push	de
	call	_memset
	add	sp, #6
	C$OAMManager.c$52$1_0$196	= .
	.globl	C$OAMManager.c$52$1_0$196
;C:/ZGB-2023.0/common/src/OAMManager.c:52: memset(oam1, 0, sizeof(oam_mirror));
	ld	hl, #_oam1
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	xor	a, a
	and	a
	push	af
	ld	de, #0x0000
	push	de
	push	bc
	call	_memset
	add	sp, #6
	C$OAMManager.c$53$1_0$196	= .
	.globl	C$OAMManager.c$53$1_0$196
;C:/ZGB-2023.0/common/src/OAMManager.c:53: next_oam_idx = 0;
	ld	hl, #_next_oam_idx
	ld	(hl), #0x00
	C$OAMManager.c$54$1_0$196	= .
	.globl	C$OAMManager.c$54$1_0$196
;C:/ZGB-2023.0/common/src/OAMManager.c:54: }
	C$OAMManager.c$54$1_0$196	= .
	.globl	C$OAMManager.c$54$1_0$196
	XG$ClearOAMs$0$0	= .
	.globl	XG$ClearOAMs$0$0
	ret
	.area _CODE
	.area _INITIALIZER
FOAMManager$__xinit_next_oam_idx$0_0$0 == .
__xinit__next_oam_idx:
	.db #0x00	; 0
FOAMManager$__xinit_oam$0_0$0 == .
__xinit__oam:
	.dw #0xc000
FOAMManager$__xinit_oam0$0_0$0 == .
__xinit__oam0:
	.dw #0xc000
FOAMManager$__xinit_oam1$0_0$0 == .
__xinit__oam1:
	.dw #0xdf00
FOAMManager$__xinit_oam_end$0_0$0 == .
__xinit__oam_end:
	.dw #0xc000
	.area _CABS (ABS)
