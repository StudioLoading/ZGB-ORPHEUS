;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module SpriteCamera
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _Destroy_SpriteCamera
	.globl _Update_SpriteCamera
	.globl _Start_SpriteCamera
	.globl ___bank_SpriteCamera
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
	.area _CODE_255
	G$Start_SpriteCamera$0$0	= .
	.globl	G$Start_SpriteCamera$0$0
	C$SpriteCamera.c$3$0_0$2	= .
	.globl	C$SpriteCamera.c$3$0_0$2
;SpriteCamera.c:3: void START() {
;	---------------------------------
; Function Start_SpriteCamera
; ---------------------------------
_Start_SpriteCamera::
	C$SpriteCamera.c$4$0_0$2	= .
	.globl	C$SpriteCamera.c$4$0_0$2
;SpriteCamera.c:4: }
	C$SpriteCamera.c$4$0_0$2	= .
	.globl	C$SpriteCamera.c$4$0_0$2
	XG$Start_SpriteCamera$0$0	= .
	.globl	XG$Start_SpriteCamera$0$0
	ret
G$__bank_SpriteCamera$0_0$0 == 0x00ff
___bank_SpriteCamera	=	0x00ff
	G$Update_SpriteCamera$0$0	= .
	.globl	G$Update_SpriteCamera$0$0
	C$SpriteCamera.c$6$0_0$4	= .
	.globl	C$SpriteCamera.c$6$0_0$4
;SpriteCamera.c:6: void UPDATE() {
;	---------------------------------
; Function Update_SpriteCamera
; ---------------------------------
_Update_SpriteCamera::
	C$SpriteCamera.c$7$0_0$4	= .
	.globl	C$SpriteCamera.c$7$0_0$4
;SpriteCamera.c:7: }
	C$SpriteCamera.c$7$0_0$4	= .
	.globl	C$SpriteCamera.c$7$0_0$4
	XG$Update_SpriteCamera$0$0	= .
	.globl	XG$Update_SpriteCamera$0$0
	ret
	G$Destroy_SpriteCamera$0$0	= .
	.globl	G$Destroy_SpriteCamera$0$0
	C$SpriteCamera.c$9$0_0$6	= .
	.globl	C$SpriteCamera.c$9$0_0$6
;SpriteCamera.c:9: void DESTROY() {
;	---------------------------------
; Function Destroy_SpriteCamera
; ---------------------------------
_Destroy_SpriteCamera::
	C$SpriteCamera.c$10$0_0$6	= .
	.globl	C$SpriteCamera.c$10$0_0$6
;SpriteCamera.c:10: }
	C$SpriteCamera.c$10$0_0$6	= .
	.globl	C$SpriteCamera.c$10$0_0$6
	XG$Destroy_SpriteCamera$0$0	= .
	.globl	XG$Destroy_SpriteCamera$0$0
	ret
	.area _CODE_255
	.area _INITIALIZER
	.area _CABS (ABS)
