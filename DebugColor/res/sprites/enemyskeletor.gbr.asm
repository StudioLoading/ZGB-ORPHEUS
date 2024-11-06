;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module enemyskeletor_gbr
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _enemyskeletor
	.globl _enemyskeletor_metasprites
	.globl _enemyskeletor_metasprite6
	.globl _enemyskeletor_metasprite5
	.globl _enemyskeletor_metasprite4
	.globl _enemyskeletor_metasprite3
	.globl _enemyskeletor_metasprite2
	.globl _enemyskeletor_metasprite1
	.globl _enemyskeletor_metasprite0
	.globl _enemyskeletor_tiles
	.globl _enemyskeletor_palettes
	.globl b___func_enemyskeletor
	.globl ___func_enemyskeletor
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
	G$__func_enemyskeletor$0$0	= .
	.globl	G$__func_enemyskeletor$0$0
	C$enemyskeletor.gbr.c$9$0_0$161	= .
	.globl	C$enemyskeletor.gbr.c$9$0_0$161
;../DebugColor/res/sprites/enemyskeletor.gbr.c:9: BANKREF(enemyskeletor)
;	---------------------------------
; Function __func_enemyskeletor
; ---------------------------------
	b___func_enemyskeletor	= 255
___func_enemyskeletor::
	.local b___func_enemyskeletor 
	___bank_enemyskeletor = b___func_enemyskeletor 
	.globl ___bank_enemyskeletor 
	.area _CODE_255
G$enemyskeletor_palettes$0_0$0 == .
_enemyskeletor_palettes:
	.dw #0x7fff
	.dw #0x739c
	.dw #0x294a
	.dw #0x0000
G$enemyskeletor_tiles$0_0$0 == .
_enemyskeletor_tiles:
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x08	; 8
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
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x0f	; 15
	.db #0x0f	; 15
	.db #0x12	; 18
	.db #0x1f	; 31
	.db #0x2f	; 47
	.db #0x30	; 48	'0'
	.db #0x3f	; 63
	.db #0x20	; 32
	.db #0x3f	; 63
	.db #0x20	; 32
	.db #0x3f	; 63
	.db #0x20	; 32
	.db #0x2f	; 47
	.db #0x30	; 48	'0'
	.db #0x2f	; 47
	.db #0x30	; 48	'0'
	.db #0x13	; 19
	.db #0x1c	; 28
	.db #0x18	; 24
	.db #0x1f	; 31
	.db #0x1f	; 31
	.db #0x1f	; 31
	.db #0x2d	; 45
	.db #0x3e	; 62
	.db #0x2f	; 47
	.db #0x3f	; 63
	.db #0x1f	; 31
	.db #0x1f	; 31
	.db #0x07	; 7
	.db #0x07	; 7
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x08	; 8
	.db #0xf8	; 248
	.db #0xf4	; 244
	.db #0x0c	; 12
	.db #0xfc	; 252
	.db #0x04	; 4
	.db #0xfc	; 252
	.db #0x04	; 4
	.db #0xfc	; 252
	.db #0x04	; 4
	.db #0xf4	; 244
	.db #0x0c	; 12
	.db #0xf4	; 244
	.db #0x0c	; 12
	.db #0xc8	; 200
	.db #0x38	; 56	'8'
	.db #0x18	; 24
	.db #0xf8	; 248
	.db #0xf4	; 244
	.db #0xfc	; 252
	.db #0xd2	; 210
	.db #0x3e	; 62
	.db #0xf2	; 242
	.db #0xfe	; 254
	.db #0x9c	; 156
	.db #0xfc	; 252
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x0f	; 15
	.db #0x0f	; 15
	.db #0x12	; 18
	.db #0x1f	; 31
	.db #0x2d	; 45
	.db #0x32	; 50	'2'
	.db #0x3f	; 63
	.db #0x20	; 32
	.db #0x3f	; 63
	.db #0x20	; 32
	.db #0x3f	; 63
	.db #0x20	; 32
	.db #0x2f	; 47
	.db #0x30	; 48	'0'
	.db #0x2f	; 47
	.db #0x30	; 48	'0'
	.db #0x13	; 19
	.db #0x1c	; 28
	.db #0x18	; 24
	.db #0x1f	; 31
	.db #0x2f	; 47
	.db #0x3f	; 63
	.db #0x4b	; 75	'K'
	.db #0x7c	; 124
	.db #0x4f	; 79	'O'
	.db #0x7f	; 127
	.db #0x3f	; 63
	.db #0x3f	; 63
	.db #0x19	; 25
	.db #0x1f	; 31
	.db #0x0f	; 15
	.db #0x0f	; 15
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x08	; 8
	.db #0xf8	; 248
	.db #0xf4	; 244
	.db #0x0c	; 12
	.db #0xfc	; 252
	.db #0x04	; 4
	.db #0xfc	; 252
	.db #0x04	; 4
	.db #0xfc	; 252
	.db #0x04	; 4
	.db #0xf4	; 244
	.db #0x0c	; 12
	.db #0xf4	; 244
	.db #0x0c	; 12
	.db #0xc8	; 200
	.db #0x38	; 56	'8'
	.db #0x18	; 24
	.db #0xf8	; 248
	.db #0xf8	; 248
	.db #0xf8	; 248
	.db #0xb4	; 180
	.db #0x7c	; 124
	.db #0xf4	; 244
	.db #0xfc	; 252
	.db #0xf8	; 248
	.db #0xf8	; 248
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0xe0	; 224
	.db #0xe0	; 224
	.db #0x0f	; 15
	.db #0x0f	; 15
	.db #0x10	; 16
	.db #0x1f	; 31
	.db #0x2f	; 47
	.db #0x30	; 48	'0'
	.db #0x3f	; 63
	.db #0x20	; 32
	.db #0x33	; 51	'3'
	.db #0x2c	; 44
	.db #0x3f	; 63
	.db #0x2c	; 44
	.db #0x3f	; 63
	.db #0x2c	; 44
	.db #0x2e	; 46
	.db #0x31	; 49	'1'
	.db #0x15	; 21
	.db #0x1a	; 26
	.db #0x0a	; 10
	.db #0x0f	; 15
	.db #0x1f	; 31
	.db #0x1f	; 31
	.db #0x2d	; 45
	.db #0x3e	; 62
	.db #0x2f	; 47
	.db #0x37	; 55	'7'
	.db #0x1c	; 28
	.db #0x1f	; 31
	.db #0x0f	; 15
	.db #0x0f	; 15
	.db #0x07	; 7
	.db #0x07	; 7
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x08	; 8
	.db #0xf8	; 248
	.db #0xf4	; 244
	.db #0x0c	; 12
	.db #0xfc	; 252
	.db #0x04	; 4
	.db #0xcc	; 204
	.db #0x34	; 52	'4'
	.db #0xfc	; 252
	.db #0x34	; 52	'4'
	.db #0xfc	; 252
	.db #0x34	; 52	'4'
	.db #0x74	; 116	't'
	.db #0x8c	; 140
	.db #0xa8	; 168
	.db #0x58	; 88	'X'
	.db #0x58	; 88	'X'
	.db #0xf8	; 248
	.db #0xf4	; 244
	.db #0xfc	; 252
	.db #0xde	; 222
	.db #0x32	; 50	'2'
	.db #0xee	; 238
	.db #0xf2	; 242
	.db #0xbc	; 188
	.db #0x7c	; 124
	.db #0x98	; 152
	.db #0xf8	; 248
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x0f	; 15
	.db #0x0f	; 15
	.db #0x10	; 16
	.db #0x1f	; 31
	.db #0x2f	; 47
	.db #0x30	; 48	'0'
	.db #0x3f	; 63
	.db #0x20	; 32
	.db #0x33	; 51	'3'
	.db #0x2c	; 44
	.db #0x3f	; 63
	.db #0x2c	; 44
	.db #0x3f	; 63
	.db #0x2c	; 44
	.db #0x2e	; 46
	.db #0x31	; 49	'1'
	.db #0x15	; 21
	.db #0x1a	; 26
	.db #0x1a	; 26
	.db #0x1f	; 31
	.db #0x2f	; 47
	.db #0x3f	; 63
	.db #0x7b	; 123
	.db #0x4c	; 76	'L'
	.db #0x77	; 119	'w'
	.db #0x4f	; 79	'O'
	.db #0x39	; 57	'9'
	.db #0x3f	; 63
	.db #0x0f	; 15
	.db #0x0f	; 15
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x08	; 8
	.db #0xf8	; 248
	.db #0xf4	; 244
	.db #0x0c	; 12
	.db #0xfc	; 252
	.db #0x04	; 4
	.db #0xcc	; 204
	.db #0x34	; 52	'4'
	.db #0xfc	; 252
	.db #0x34	; 52	'4'
	.db #0xfc	; 252
	.db #0x34	; 52	'4'
	.db #0x74	; 116	't'
	.db #0x8c	; 140
	.db #0xa8	; 168
	.db #0x58	; 88	'X'
	.db #0x50	; 80	'P'
	.db #0xf0	; 240
	.db #0xf8	; 248
	.db #0xf8	; 248
	.db #0xb4	; 180
	.db #0x7c	; 124
	.db #0xf4	; 244
	.db #0xec	; 236
	.db #0xf8	; 248
	.db #0xf8	; 248
	.db #0xe0	; 224
	.db #0xe0	; 224
	.db #0x0f	; 15
	.db #0x0f	; 15
	.db #0x10	; 16
	.db #0x1f	; 31
	.db #0x2f	; 47
	.db #0x30	; 48	'0'
	.db #0x3f	; 63
	.db #0x20	; 32
	.db #0x3c	; 60
	.db #0x23	; 35
	.db #0x3f	; 63
	.db #0x23	; 35
	.db #0x3f	; 63
	.db #0x23	; 35
	.db #0x2f	; 47
	.db #0x30	; 48	'0'
	.db #0x16	; 22
	.db #0x19	; 25
	.db #0x19	; 25
	.db #0x1f	; 31
	.db #0x1f	; 31
	.db #0x1f	; 31
	.db #0x3d	; 61
	.db #0x26	; 38
	.db #0x3b	; 59
	.db #0x27	; 39
	.db #0x1e	; 30
	.db #0x1f	; 31
	.db #0x09	; 9
	.db #0x0f	; 15
	.db #0x1f	; 31
	.db #0x1f	; 31
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x08	; 8
	.db #0xf8	; 248
	.db #0xf4	; 244
	.db #0x0c	; 12
	.db #0xfc	; 252
	.db #0x04	; 4
	.db #0xcc	; 204
	.db #0x34	; 52	'4'
	.db #0xfc	; 252
	.db #0x34	; 52	'4'
	.db #0xfc	; 252
	.db #0x34	; 52	'4'
	.db #0xf4	; 244
	.db #0x0c	; 12
	.db #0xa8	; 168
	.db #0x58	; 88	'X'
	.db #0x58	; 88	'X'
	.db #0xf8	; 248
	.db #0xf8	; 248
	.db #0xf8	; 248
	.db #0xf4	; 244
	.db #0x3c	; 60
	.db #0xf4	; 244
	.db #0xec	; 236
	.db #0x78	; 120	'x'
	.db #0xb8	; 184
	.db #0xf8	; 248
	.db #0xf8	; 248
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x0f	; 15
	.db #0x0f	; 15
	.db #0x10	; 16
	.db #0x1f	; 31
	.db #0x2f	; 47
	.db #0x30	; 48	'0'
	.db #0x3f	; 63
	.db #0x20	; 32
	.db #0x3c	; 60
	.db #0x23	; 35
	.db #0x3f	; 63
	.db #0x23	; 35
	.db #0x3f	; 63
	.db #0x23	; 35
	.db #0x2f	; 47
	.db #0x30	; 48	'0'
	.db #0x16	; 22
	.db #0x19	; 25
	.db #0x19	; 25
	.db #0x1f	; 31
	.db #0x0f	; 15
	.db #0x0f	; 15
	.db #0x1f	; 31
	.db #0x16	; 22
	.db #0x1f	; 31
	.db #0x19	; 25
	.db #0x0f	; 15
	.db #0x0f	; 15
	.db #0x1f	; 31
	.db #0x1f	; 31
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x08	; 8
	.db #0xf8	; 248
	.db #0xf4	; 244
	.db #0x0c	; 12
	.db #0xfc	; 252
	.db #0x04	; 4
	.db #0xcc	; 204
	.db #0x34	; 52	'4'
	.db #0xfc	; 252
	.db #0x34	; 52	'4'
	.db #0xfc	; 252
	.db #0x34	; 52	'4'
	.db #0xf4	; 244
	.db #0x0c	; 12
	.db #0xa8	; 168
	.db #0x58	; 88	'X'
	.db #0x58	; 88	'X'
	.db #0xf8	; 248
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0xf8	; 248
	.db #0x38	; 56	'8'
	.db #0xf8	; 248
	.db #0xe8	; 232
	.db #0x10	; 16
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0xf0	; 240
G$enemyskeletor_metasprite0$0_0$0 == .
_enemyskeletor_metasprite0:
	.db #0xfd	; -3
	.db #0x05	;  5
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
G$enemyskeletor_metasprite1$0_0$0 == .
_enemyskeletor_metasprite1:
	.db #0xfd	; -3
	.db #0xfd	; -3
	.db #0x02	; 2
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x04	; 4
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
G$enemyskeletor_metasprite2$0_0$0 == .
_enemyskeletor_metasprite2:
	.db #0xfd	; -3
	.db #0xfd	; -3
	.db #0x06	; 6
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x08	; 8
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
G$enemyskeletor_metasprite3$0_0$0 == .
_enemyskeletor_metasprite3:
	.db #0xfd	; -3
	.db #0xfd	; -3
	.db #0x0a	; 10
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x0c	; 12
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
G$enemyskeletor_metasprite4$0_0$0 == .
_enemyskeletor_metasprite4:
	.db #0xfd	; -3
	.db #0xfd	; -3
	.db #0x0e	; 14
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x10	; 16
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
G$enemyskeletor_metasprite5$0_0$0 == .
_enemyskeletor_metasprite5:
	.db #0xfd	; -3
	.db #0xfd	; -3
	.db #0x12	; 18
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x14	; 20
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
G$enemyskeletor_metasprite6$0_0$0 == .
_enemyskeletor_metasprite6:
	.db #0xfd	; -3
	.db #0xfd	; -3
	.db #0x16	; 22
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x18	; 24
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
G$enemyskeletor_metasprites$0_0$0 == .
_enemyskeletor_metasprites:
	.dw _enemyskeletor_metasprite0
	.dw _enemyskeletor_metasprite1
	.dw _enemyskeletor_metasprite2
	.dw _enemyskeletor_metasprite3
	.dw _enemyskeletor_metasprite4
	.dw _enemyskeletor_metasprite5
	.dw _enemyskeletor_metasprite6
G$enemyskeletor$0_0$0 == .
_enemyskeletor:
	.db #0x0a	; 10
	.db #0x0a	; 10
	.db #0x1a	; 26
	.dw _enemyskeletor_tiles
	.db #0x01	; 1
	.dw _enemyskeletor_palettes
	.db #0x07	; 7
	.dw _enemyskeletor_metasprites
	.area _INITIALIZER
	.area _CABS (ABS)
