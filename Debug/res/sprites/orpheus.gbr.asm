;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module orpheus_gbr
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _orpheus
	.globl _orpheus_metasprites
	.globl _orpheus_metasprite10
	.globl _orpheus_metasprite9
	.globl _orpheus_metasprite8
	.globl _orpheus_metasprite7
	.globl _orpheus_metasprite6
	.globl _orpheus_metasprite5
	.globl _orpheus_metasprite4
	.globl _orpheus_metasprite3
	.globl _orpheus_metasprite2
	.globl _orpheus_metasprite1
	.globl _orpheus_metasprite0
	.globl _orpheus_tiles
	.globl _orpheus_palettes
	.globl b___func_orpheus
	.globl ___func_orpheus
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
	G$__func_orpheus$0$0	= .
	.globl	G$__func_orpheus$0$0
	C$orpheus.gbr.c$9$0_0$161	= .
	.globl	C$orpheus.gbr.c$9$0_0$161
;../Debug/res/sprites/orpheus.gbr.c:9: BANKREF(orpheus)
;	---------------------------------
; Function __func_orpheus
; ---------------------------------
	b___func_orpheus	= 255
___func_orpheus::
	.local b___func_orpheus 
	___bank_orpheus = b___func_orpheus 
	.globl ___bank_orpheus 
	.area _CODE_255
G$orpheus_palettes$0_0$0 == .
_orpheus_palettes:
	.dw #0x7fff
	.dw #0x531e
	.dw #0x4d20
	.dw #0x0000
G$orpheus_tiles$0_0$0 == .
_orpheus_tiles:
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
	.db #0x06	; 6
	.db #0x06	; 6
	.db #0x29	; 41
	.db #0x2f	; 47
	.db #0x54	; 84	'T'
	.db #0x7f	; 127
	.db #0x42	; 66	'B'
	.db #0x7f	; 127
	.db #0x20	; 32
	.db #0x3f	; 63
	.db #0x46	; 70	'F'
	.db #0x7d	; 125
	.db #0x8c	; 140
	.db #0xfb	; 251
	.db #0x0c	; 12
	.db #0xfb	; 251
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
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x08	; 8
	.db #0xf8	; 248
	.db #0xd4	; 212
	.db #0x3c	; 60
	.db #0xfe	; 254
	.db #0x12	; 18
	.db #0x0f	; 15
	.db #0xfb	; 251
	.db #0x25	; 37
	.db #0xff	; 255
	.db #0x84	; 132
	.db #0xff	; 255
	.db #0x97	; 151
	.db #0xff	; 255
	.db #0x08	; 8
	.db #0xff	; 255
	.db #0x8f	; 143
	.db #0xfa	; 250
	.db #0x7f	; 127
	.db #0x72	; 114	'r'
	.db #0x1f	; 31
	.db #0x12	; 18
	.db #0x1b	; 27
	.db #0x1c	; 28
	.db #0x3f	; 63
	.db #0x37	; 55	'7'
	.db #0x7f	; 127
	.db #0x4c	; 76	'L'
	.db #0x7f	; 127
	.db #0x4f	; 79	'O'
	.db #0x38	; 56	'8'
	.db #0x3f	; 63
	.db #0x1c	; 28
	.db #0x1f	; 31
	.db #0x0f	; 15
	.db #0x1f	; 31
	.db #0x1f	; 31
	.db #0x1f	; 31
	.db #0x0f	; 15
	.db #0x0f	; 15
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x20	; 32
	.db #0xff	; 255
	.db #0x75	; 117	'u'
	.db #0xff	; 255
	.db #0x95	; 149
	.db #0xff	; 255
	.db #0xfe	; 254
	.db #0x5e	; 94
	.db #0xf8	; 248
	.db #0x48	; 72	'H'
	.db #0xf8	; 248
	.db #0x48	; 72	'H'
	.db #0xd8	; 216
	.db #0x38	; 56	'8'
	.db #0xf4	; 244
	.db #0xfc	; 252
	.db #0x9e	; 158
	.db #0xf2	; 242
	.db #0x1f	; 31
	.db #0xf3	; 243
	.db #0xff	; 255
	.db #0xfd	; 253
	.db #0x37	; 55	'7'
	.db #0xfd	; 253
	.db #0xff	; 255
	.db #0x1d	; 29
	.db #0x1e	; 30
	.db #0xfe	; 254
	.db #0xe0	; 224
	.db #0xe0	; 224
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
	.db #0x06	; 6
	.db #0x06	; 6
	.db #0x29	; 41
	.db #0x2f	; 47
	.db #0x54	; 84	'T'
	.db #0x7f	; 127
	.db #0x42	; 66	'B'
	.db #0x7f	; 127
	.db #0x20	; 32
	.db #0x3f	; 63
	.db #0x46	; 70	'F'
	.db #0x7d	; 125
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
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x08	; 8
	.db #0xf8	; 248
	.db #0xd4	; 212
	.db #0x3c	; 60
	.db #0xfe	; 254
	.db #0x12	; 18
	.db #0x8c	; 140
	.db #0xfb	; 251
	.db #0x0c	; 12
	.db #0xfb	; 251
	.db #0x97	; 151
	.db #0xff	; 255
	.db #0x08	; 8
	.db #0xff	; 255
	.db #0x8f	; 143
	.db #0xfa	; 250
	.db #0x7f	; 127
	.db #0x72	; 114	'r'
	.db #0x1f	; 31
	.db #0x12	; 18
	.db #0x1b	; 27
	.db #0x1c	; 28
	.db #0x2f	; 47
	.db #0x3f	; 63
	.db #0x78	; 120	'x'
	.db #0x4f	; 79	'O'
	.db #0xff	; 255
	.db #0xcf	; 207
	.db #0xfc	; 252
	.db #0xbf	; 191
	.db #0xef	; 239
	.db #0xb8	; 184
	.db #0xf8	; 248
	.db #0xbf	; 191
	.db #0x67	; 103	'g'
	.db #0x67	; 103	'g'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x0f	; 15
	.db #0xfb	; 251
	.db #0x25	; 37
	.db #0xff	; 255
	.db #0x75	; 117	'u'
	.db #0xff	; 255
	.db #0x95	; 149
	.db #0xff	; 255
	.db #0xfe	; 254
	.db #0x5e	; 94
	.db #0xf8	; 248
	.db #0x48	; 72	'H'
	.db #0xf8	; 248
	.db #0x48	; 72	'H'
	.db #0xd8	; 216
	.db #0x38	; 56	'8'
	.db #0xfc	; 252
	.db #0xec	; 236
	.db #0xfe	; 254
	.db #0xf2	; 242
	.db #0x1e	; 30
	.db #0xf2	; 242
	.db #0x3c	; 60
	.db #0xfc	; 252
	.db #0xe8	; 232
	.db #0xf8	; 248
	.db #0xf8	; 248
	.db #0xf8	; 248
	.db #0xf0	; 240
	.db #0xf0	; 240
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
	.db #0x06	; 6
	.db #0x06	; 6
	.db #0x29	; 41
	.db #0x2f	; 47
	.db #0x54	; 84	'T'
	.db #0x7f	; 127
	.db #0x42	; 66	'B'
	.db #0x7f	; 127
	.db #0x20	; 32
	.db #0x3f	; 63
	.db #0x54	; 84	'T'
	.db #0x5f	; 95
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
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x08	; 8
	.db #0xf8	; 248
	.db #0x04	; 4
	.db #0xfc	; 252
	.db #0x0e	; 14
	.db #0xfa	; 250
	.db #0xd8	; 216
	.db #0xff	; 255
	.db #0x28	; 40
	.db #0xff	; 255
	.db #0x84	; 132
	.db #0xff	; 255
	.db #0x94	; 148
	.db #0xff	; 255
	.db #0x08	; 8
	.db #0xff	; 255
	.db #0x88	; 136
	.db #0xff	; 255
	.db #0x7c	; 124
	.db #0x7f	; 127
	.db #0x1f	; 31
	.db #0x1f	; 31
	.db #0x0d	; 13
	.db #0x0e	; 14
	.db #0x3f	; 63
	.db #0x30	; 48	'0'
	.db #0x5a	; 90	'Z'
	.db #0x77	; 119	'w'
	.db #0x5d	; 93
	.db #0x7f	; 127
	.db #0x39	; 57	'9'
	.db #0x3f	; 63
	.db #0x1f	; 31
	.db #0x1f	; 31
	.db #0x0f	; 15
	.db #0x0f	; 15
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x0b	; 11
	.db #0xff	; 255
	.db #0x25	; 37
	.db #0xff	; 255
	.db #0x20	; 32
	.db #0xff	; 255
	.db #0x15	; 21
	.db #0xff	; 255
	.db #0x15	; 21
	.db #0xff	; 255
	.db #0x0e	; 14
	.db #0xfe	; 254
	.db #0x18	; 24
	.db #0xf8	; 248
	.db #0xf8	; 248
	.db #0xf8	; 248
	.db #0xc8	; 200
	.db #0x38	; 56	'8'
	.db #0xf4	; 244
	.db #0x0c	; 12
	.db #0xee	; 238
	.db #0x12	; 18
	.db #0x77	; 119	'w'
	.db #0x89	; 137
	.db #0x7f	; 127
	.db #0x81	; 129
	.db #0x7f	; 127
	.db #0x81	; 129
	.db #0xd2	; 210
	.db #0xae	; 174
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
	.db #0x06	; 6
	.db #0x06	; 6
	.db #0x29	; 41
	.db #0x2f	; 47
	.db #0x54	; 84	'T'
	.db #0x7f	; 127
	.db #0x42	; 66	'B'
	.db #0x7f	; 127
	.db #0x20	; 32
	.db #0x3f	; 63
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
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x08	; 8
	.db #0xf8	; 248
	.db #0x04	; 4
	.db #0xfc	; 252
	.db #0x74	; 116	't'
	.db #0x5f	; 95
	.db #0xd8	; 216
	.db #0xff	; 255
	.db #0x28	; 40
	.db #0xff	; 255
	.db #0x84	; 132
	.db #0xff	; 255
	.db #0x94	; 148
	.db #0xff	; 255
	.db #0x08	; 8
	.db #0xff	; 255
	.db #0x8c	; 140
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0x7f	; 127
	.db #0x13	; 19
	.db #0x1c	; 28
	.db #0x2f	; 47
	.db #0x30	; 48	'0'
	.db #0x77	; 119	'w'
	.db #0x48	; 72	'H'
	.db #0xee	; 238
	.db #0x91	; 145
	.db #0xfe	; 254
	.db #0x81	; 129
	.db #0xfe	; 254
	.db #0x81	; 129
	.db #0x4b	; 75	'K'
	.db #0x75	; 117	'u'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x0e	; 14
	.db #0xfa	; 250
	.db #0x0b	; 11
	.db #0xff	; 255
	.db #0x25	; 37
	.db #0xff	; 255
	.db #0x20	; 32
	.db #0xff	; 255
	.db #0x15	; 21
	.db #0xff	; 255
	.db #0x15	; 21
	.db #0xff	; 255
	.db #0x0e	; 14
	.db #0xfe	; 254
	.db #0xd8	; 216
	.db #0xf8	; 248
	.db #0xb0	; 176
	.db #0x70	; 112	'p'
	.db #0xfc	; 252
	.db #0x0c	; 12
	.db #0x5a	; 90	'Z'
	.db #0xee	; 238
	.db #0xba	; 186
	.db #0xfe	; 254
	.db #0x9c	; 156
	.db #0xfc	; 252
	.db #0xf8	; 248
	.db #0xf8	; 248
	.db #0xf0	; 240
	.db #0xf0	; 240
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
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x08	; 8
	.db #0xf8	; 248
	.db #0xd4	; 212
	.db #0x3c	; 60
	.db #0xfe	; 254
	.db #0x12	; 18
	.db #0x0e	; 14
	.db #0xfa	; 250
	.db #0x25	; 37
	.db #0xff	; 255
	.db #0x84	; 132
	.db #0xff	; 255
	.db #0x97	; 151
	.db #0xff	; 255
	.db #0x08	; 8
	.db #0xff	; 255
	.db #0x8b	; 139
	.db #0xfd	; 253
	.db #0x77	; 119	'w'
	.db #0x79	; 121	'y'
	.db #0x17	; 23
	.db #0x19	; 25
	.db #0x1b	; 27
	.db #0x1c	; 28
	.db #0x3f	; 63
	.db #0x37	; 55	'7'
	.db #0x73	; 115	's'
	.db #0x5f	; 95
	.db #0xf3	; 243
	.db #0xbe	; 190
	.db #0xff	; 255
	.db #0x4c	; 76	'L'
	.db #0xfb	; 251
	.db #0x4f	; 79	'O'
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xee	; 238
	.db #0x6f	; 111	'o'
	.db #0xdf	; 223
	.db #0xdf	; 223
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x20	; 32
	.db #0xff	; 255
	.db #0x75	; 117	'u'
	.db #0xff	; 255
	.db #0x95	; 149
	.db #0xff	; 255
	.db #0xee	; 238
	.db #0x3e	; 62
	.db #0xf8	; 248
	.db #0x28	; 40
	.db #0xf8	; 248
	.db #0x28	; 40
	.db #0xd0	; 208
	.db #0x30	; 48	'0'
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0xf8	; 248
	.db #0x18	; 24
	.db #0xf8	; 248
	.db #0xb8	; 184
	.db #0xf0	; 240
	.db #0x70	; 112	'p'
	.db #0xb0	; 176
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x18	; 24
	.db #0xf8	; 248
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x8c	; 140
	.db #0xfb	; 251
	.db #0x0c	; 12
	.db #0xfb	; 251
	.db #0x97	; 151
	.db #0xff	; 255
	.db #0x08	; 8
	.db #0xff	; 255
	.db #0x8b	; 139
	.db #0xfd	; 253
	.db #0x77	; 119	'w'
	.db #0x79	; 121	'y'
	.db #0x17	; 23
	.db #0x19	; 25
	.db #0x3b	; 59
	.db #0x3c	; 60
	.db #0x3f	; 63
	.db #0x3f	; 63
	.db #0x79	; 121	'y'
	.db #0x4f	; 79	'O'
	.db #0xff	; 255
	.db #0x98	; 152
	.db #0xef	; 239
	.db #0xbf	; 191
	.db #0xef	; 239
	.db #0xb9	; 185
	.db #0xf8	; 248
	.db #0xbf	; 191
	.db #0x7f	; 127
	.db #0x7f	; 127
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x0e	; 14
	.db #0xfa	; 250
	.db #0x25	; 37
	.db #0xff	; 255
	.db #0x75	; 117	'u'
	.db #0xff	; 255
	.db #0x95	; 149
	.db #0xff	; 255
	.db #0xee	; 238
	.db #0x3e	; 62
	.db #0xf8	; 248
	.db #0x28	; 40
	.db #0xf8	; 248
	.db #0x28	; 40
	.db #0xd8	; 216
	.db #0x38	; 56	'8'
	.db #0xe8	; 232
	.db #0xf8	; 248
	.db #0xe8	; 232
	.db #0xb8	; 184
	.db #0xf8	; 248
	.db #0xf8	; 248
	.db #0xa8	; 168
	.db #0xf8	; 248
	.db #0xf8	; 248
	.db #0xf8	; 248
	.db #0x78	; 120	'x'
	.db #0xf8	; 248
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x84	; 132
	.db #0xff	; 255
	.db #0x97	; 151
	.db #0xff	; 255
	.db #0x08	; 8
	.db #0xff	; 255
	.db #0x8b	; 139
	.db #0xfd	; 253
	.db #0x77	; 119	'w'
	.db #0x79	; 121	'y'
	.db #0x17	; 23
	.db #0x19	; 25
	.db #0x1f	; 31
	.db #0x1c	; 28
	.db #0x3f	; 63
	.db #0x33	; 51	'3'
	.db #0x3f	; 63
	.db #0x3e	; 62
	.db #0x73	; 115	's'
	.db #0x5f	; 95
	.db #0xff	; 255
	.db #0x9c	; 156
	.db #0xef	; 239
	.db #0xbc	; 188
	.db #0xef	; 239
	.db #0xbf	; 191
	.db #0xf1	; 241
	.db #0xbf	; 191
	.db #0x6f	; 111	'o'
	.db #0x6f	; 111	'o'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x20	; 32
	.db #0xff	; 255
	.db #0x75	; 117	'u'
	.db #0xff	; 255
	.db #0x95	; 149
	.db #0xff	; 255
	.db #0xee	; 238
	.db #0x3e	; 62
	.db #0xf8	; 248
	.db #0x28	; 40
	.db #0xf8	; 248
	.db #0x28	; 40
	.db #0xd0	; 208
	.db #0x30	; 48	'0'
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x10	; 16
	.db #0xe8	; 232
	.db #0xb8	; 184
	.db #0xf8	; 248
	.db #0xf8	; 248
	.db #0xa8	; 168
	.db #0xf8	; 248
	.db #0xf8	; 248
	.db #0xb8	; 184
	.db #0x88	; 136
	.db #0xf8	; 248
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x00	; 0
	.db #0x00	; 0
G$orpheus_metasprite0$0_0$0 == .
_orpheus_metasprite0:
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
G$orpheus_metasprite1$0_0$0 == .
_orpheus_metasprite1:
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
G$orpheus_metasprite2$0_0$0 == .
_orpheus_metasprite2:
	.db #0xf2	; -14
	.db #0xfc	; -4
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x02	; 2
	.db #0x00	; 0
	.db #0x10	;  16
	.db #0xf8	; -8
	.db #0x04	; 4
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x06	; 6
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
G$orpheus_metasprite3$0_0$0 == .
_orpheus_metasprite3:
	.db #0xf2	; -14
	.db #0xfc	; -4
	.db #0x08	; 8
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x0a	; 10
	.db #0x00	; 0
	.db #0x10	;  16
	.db #0xf8	; -8
	.db #0x0c	; 12
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x0e	; 14
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
G$orpheus_metasprite4$0_0$0 == .
_orpheus_metasprite4:
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
G$orpheus_metasprite5$0_0$0 == .
_orpheus_metasprite5:
	.db #0xf2	; -14
	.db #0xfc	; -4
	.db #0x10	; 16
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x12	; 18
	.db #0x00	; 0
	.db #0x10	;  16
	.db #0xf8	; -8
	.db #0x14	; 20
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x16	; 22
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
G$orpheus_metasprite6$0_0$0 == .
_orpheus_metasprite6:
	.db #0xf2	; -14
	.db #0xfc	; -4
	.db #0x18	; 24
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x1a	; 26
	.db #0x00	; 0
	.db #0x10	;  16
	.db #0xf8	; -8
	.db #0x1c	; 28
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x1e	; 30
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
G$orpheus_metasprite7$0_0$0 == .
_orpheus_metasprite7:
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
G$orpheus_metasprite8$0_0$0 == .
_orpheus_metasprite8:
	.db #0xf2	; -14
	.db #0xfc	; -4
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x20	; 32
	.db #0x00	; 0
	.db #0x10	;  16
	.db #0xf8	; -8
	.db #0x22	; 34
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x24	; 36
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
G$orpheus_metasprite9$0_0$0 == .
_orpheus_metasprite9:
	.db #0xf2	; -14
	.db #0xfc	; -4
	.db #0x08	; 8
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x0a	; 10
	.db #0x00	; 0
	.db #0x10	;  16
	.db #0xf8	; -8
	.db #0x26	; 38
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x28	; 40
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
G$orpheus_metasprite10$0_0$0 == .
_orpheus_metasprite10:
	.db #0xf2	; -14
	.db #0xfc	; -4
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x20	; 32
	.db #0x00	; 0
	.db #0x10	;  16
	.db #0xf8	; -8
	.db #0x2a	; 42
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x2c	; 44
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
G$orpheus_metasprites$0_0$0 == .
_orpheus_metasprites:
	.dw _orpheus_metasprite0
	.dw _orpheus_metasprite1
	.dw _orpheus_metasprite2
	.dw _orpheus_metasprite3
	.dw _orpheus_metasprite4
	.dw _orpheus_metasprite5
	.dw _orpheus_metasprite6
	.dw _orpheus_metasprite7
	.dw _orpheus_metasprite8
	.dw _orpheus_metasprite9
	.dw _orpheus_metasprite10
G$orpheus$0_0$0 == .
_orpheus:
	.db #0x08	; 8
	.db #0x10	; 16
	.db #0x2e	; 46
	.dw _orpheus_tiles
	.db #0x01	; 1
	.dw _orpheus_palettes
	.db #0x0b	; 11
	.dw _orpheus_metasprites
	.area _INITIALIZER
	.area _CABS (ABS)
