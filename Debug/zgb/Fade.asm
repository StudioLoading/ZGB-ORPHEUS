;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module Fade
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl b_FadeOut_b
	.globl _FadeOut_b
	.globl b_FadeIn_b
	.globl _FadeIn_b
	.globl _FadeIn
	.globl _FadeOut
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
	G$FadeIn$0$0	= .
	.globl	G$FadeIn$0$0
	C$Fade.c$7$0_0$124	= .
	.globl	C$Fade.c$7$0_0$124
;C:/ZGB-2023.0/common/src/Fade.c:7: void FadeIn() {
;	---------------------------------
; Function FadeIn
; ---------------------------------
_FadeIn::
	C$Fade.c$8$1_0$124	= .
	.globl	C$Fade.c$8$1_0$124
;C:/ZGB-2023.0/common/src/Fade.c:8: FadeIn_b();
	ld	e, #b_FadeIn_b
	ld	hl, #_FadeIn_b
	C$Fade.c$9$1_0$124	= .
	.globl	C$Fade.c$9$1_0$124
;C:/ZGB-2023.0/common/src/Fade.c:9: }
	C$Fade.c$9$1_0$124	= .
	.globl	C$Fade.c$9$1_0$124
	XG$FadeIn$0$0	= .
	.globl	XG$FadeIn$0$0
	jp  ___sdcc_bcall_ehl
	G$FadeOut$0$0	= .
	.globl	G$FadeOut$0$0
	C$Fade.c$11$1_0$125	= .
	.globl	C$Fade.c$11$1_0$125
;C:/ZGB-2023.0/common/src/Fade.c:11: void FadeOut() {
;	---------------------------------
; Function FadeOut
; ---------------------------------
_FadeOut::
	C$Fade.c$12$1_0$125	= .
	.globl	C$Fade.c$12$1_0$125
;C:/ZGB-2023.0/common/src/Fade.c:12: FadeOut_b();
	ld	e, #b_FadeOut_b
	ld	hl, #_FadeOut_b
	C$Fade.c$13$1_0$125	= .
	.globl	C$Fade.c$13$1_0$125
;C:/ZGB-2023.0/common/src/Fade.c:13: }
	C$Fade.c$13$1_0$125	= .
	.globl	C$Fade.c$13$1_0$125
	XG$FadeOut$0$0	= .
	.globl	XG$FadeOut$0$0
	jp  ___sdcc_bcall_ehl
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
