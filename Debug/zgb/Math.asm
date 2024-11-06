;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module Math
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _DespRight
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
	G$DespRight$0$0	= .
	.globl	G$DespRight$0$0
	C$Math.c$3$0_0$3	= .
	.globl	C$Math.c$3$0_0$3
;C:/ZGB-2023.0/common/src/Math.c:3: INT16 DespRight(INT16 a, INT16 b) {
;	---------------------------------
; Function DespRight
; ---------------------------------
_DespRight::
	C$Math.c$4$1_0$3	= .
	.globl	C$Math.c$4$1_0$3
;C:/ZGB-2023.0/common/src/Math.c:4: return a >> b;
	inc	c
	jr	00104$
00103$:
	sra	d
	rr	e
00104$:
	dec	c
	jr	NZ, 00103$
	ld	c, e
	ld	b, d
	C$Math.c$5$1_0$3	= .
	.globl	C$Math.c$5$1_0$3
;C:/ZGB-2023.0/common/src/Math.c:5: }
	C$Math.c$5$1_0$3	= .
	.globl	C$Math.c$5$1_0$3
	XG$DespRight$0$0	= .
	.globl	XG$DespRight$0$0
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
