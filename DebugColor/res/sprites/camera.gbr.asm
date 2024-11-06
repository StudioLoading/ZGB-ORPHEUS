;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module camera_gbr
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _camera
	.globl _camera_metasprites
	.globl _camera_metasprite0
	.globl _camera_tiles
	.globl _camera_palettes
	.globl b___func_camera
	.globl ___func_camera
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
	G$__func_camera$0$0	= .
	.globl	G$__func_camera$0$0
	C$camera.gbr.c$9$0_0$161	= .
	.globl	C$camera.gbr.c$9$0_0$161
;../DebugColor/res/sprites/camera.gbr.c:9: BANKREF(camera)
;	---------------------------------
; Function __func_camera
; ---------------------------------
	b___func_camera	= 255
___func_camera::
	.local b___func_camera 
	___bank_camera = b___func_camera 
	.globl ___bank_camera 
	.area _CODE_255
G$camera_palettes$0_0$0 == .
_camera_palettes:
	.dw #0x7fff
	.dw #0x56b5
	.dw #0x294a
	.dw #0x0000
G$camera_tiles$0_0$0 == .
_camera_tiles:
	.db #0xe0	; 224
	.db #0xe0	; 224
	.db #0xc0	; 192
	.db #0xa0	; 160
	.db #0xa0	; 160
	.db #0xc0	; 192
	.db #0x10	; 16
	.db #0x20	; 32
	.db #0x08	; 8
	.db #0x10	; 16
	.db #0x04	; 4
	.db #0x08	; 8
	.db #0x00	; 0
	.db #0x04	; 4
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
G$camera_metasprite0$0_0$0 == .
_camera_metasprite0:
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
G$camera_metasprites$0_0$0 == .
_camera_metasprites:
	.dw _camera_metasprite0
G$camera$0_0$0 == .
_camera:
	.db #0x08	; 8
	.db #0x10	; 16
	.db #0x02	; 2
	.dw _camera_tiles
	.db #0x01	; 1
	.dw _camera_palettes
	.db #0x01	; 1
	.dw _camera_metasprites
	.area _INITIALIZER
	.area _CABS (ABS)
