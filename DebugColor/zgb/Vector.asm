;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module Vector
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _memcpy
	.globl _VectorAdd
	.globl _VectorRemovePos
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
	G$VectorAdd$0$0	= .
	.globl	G$VectorAdd$0$0
	C$Vector.c$5$0_0$138	= .
	.globl	C$Vector.c$5$0_0$138
;C:/ZGB-2023.0/common/src/Vector.c:5: void VectorAdd(UINT8* v, UINT8 elem) {
;	---------------------------------
; Function VectorAdd
; ---------------------------------
_VectorAdd::
	ld	c, a
	C$Vector.c$6$1_0$138	= .
	.globl	C$Vector.c$6$1_0$138
;C:/ZGB-2023.0/common/src/Vector.c:6: v[++ v[0]] = elem;
	ld	a, (de)
	inc	a
	ld	(de), a
	ld	l, a
	ld	h, #0x00
	add	hl, de
	ld	(hl), c
	C$Vector.c$7$1_0$138	= .
	.globl	C$Vector.c$7$1_0$138
;C:/ZGB-2023.0/common/src/Vector.c:7: }
	C$Vector.c$7$1_0$138	= .
	.globl	C$Vector.c$7$1_0$138
	XG$VectorAdd$0$0	= .
	.globl	XG$VectorAdd$0$0
	ret
	G$VectorRemovePos$0$0	= .
	.globl	G$VectorRemovePos$0$0
	C$Vector.c$9$1_0$140	= .
	.globl	C$Vector.c$9$1_0$140
;C:/ZGB-2023.0/common/src/Vector.c:9: void VectorRemovePos(UINT8* v, UINT8 pos) {
;	---------------------------------
; Function VectorRemovePos
; ---------------------------------
_VectorRemovePos::
	add	sp, #-6
	ldhl	sp,	#4
	ld	(hl), e
	inc	hl
	ld	(hl), d
	C$Vector.c$10$1_0$140	= .
	.globl	C$Vector.c$10$1_0$140
;C:/ZGB-2023.0/common/src/Vector.c:10: memcpy(&v[pos + 1], &v[pos + 2], v[0] - pos);
	dec	hl
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	push	af
	ld	a, (de)
	ld	c, a
	pop	af
	ld	b, #0x00
	ldhl	sp,	#0
	ld	(hl+), a
	xor	a, a
	ld	(hl+), a
	inc	hl
	pop	de
	push	de
	ld	a, c
	sub	a, e
	ld	e, a
	ld	a, b
	sbc	a, d
	ld	(hl-), a
	ld	a, e
	ld	(hl+), a
	inc	hl
	pop	bc
	push	bc
	inc	bc
	inc	bc
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	ld	c, l
	ld	b, h
	pop	de
	push	de
	inc	de
	ldhl	sp,	#4
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, de
	ld	e, l
	ld	d, h
	ldhl	sp,	#2
	ld	a, (hl+)
	ld	h, (hl)
;	spillPairReg hl
;	spillPairReg hl
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	push	hl
	call	_memcpy
	C$Vector.c$11$1_0$140	= .
	.globl	C$Vector.c$11$1_0$140
;C:/ZGB-2023.0/common/src/Vector.c:11: v[0] --;
	ldhl	sp,#4
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	c, a
	dec	c
	ld	a, (hl-)
	ld	l, (hl)
	ld	h, a
	ld	(hl), c
	C$Vector.c$12$1_0$140	= .
	.globl	C$Vector.c$12$1_0$140
;C:/ZGB-2023.0/common/src/Vector.c:12: }
	add	sp, #6
	C$Vector.c$12$1_0$140	= .
	.globl	C$Vector.c$12$1_0$140
	XG$VectorRemovePos$0$0	= .
	.globl	XG$VectorRemovePos$0$0
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
