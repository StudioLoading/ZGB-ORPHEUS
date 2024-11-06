;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module SRAM
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _memset
	.globl _strcmp
	.globl _strcpy
	.globl b_CheckSRAMIntegrity
	.globl _CheckSRAMIntegrity
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
	.area _CODE_1
	G$CheckSRAMIntegrity$0$0	= .
	.globl	G$CheckSRAMIntegrity$0$0
	C$SRAM.c$9$0_0$137	= .
	.globl	C$SRAM.c$9$0_0$137
;C:/ZGB-2023.0/common/src/SRAM.c:9: void CheckSRAMIntegrity(UINT8* ptr, UINT16 size) BANKED {
;	---------------------------------
; Function CheckSRAMIntegrity
; ---------------------------------
	b_CheckSRAMIntegrity	= 1
_CheckSRAMIntegrity::
	add	sp, #-4
	C$SRAM.c$10$1_0$137	= .
	.globl	C$SRAM.c$10$1_0$137
;C:/ZGB-2023.0/common/src/SRAM.c:10: ENABLE_RAM;
	ld	hl, #_rRAMG
	ld	(hl), #0x0a
	C$SRAM.c$11$2_0$138	= .
	.globl	C$SRAM.c$11$2_0$138
;C:/ZGB-2023.0/common/src/SRAM.c:11: UINT16 bytes_to_clear = 0;
	ld	bc, #0x0000
	C$SRAM.c$12$1_1$138	= .
	.globl	C$SRAM.c$12$1_1$138
;C:/ZGB-2023.0/common/src/SRAM.c:12: UINT16* bytes_stored = (UINT16*)(ptr + MAGIC_LENGTH);
	ldhl	sp,#10
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0009
	add	hl, de
	ld	e, l
	ld	a, h
	ldhl	sp,	#0
	ld	(hl), e
	inc	hl
	ld	(hl), a
	C$SRAM.c$13$1_1$138	= .
	.globl	C$SRAM.c$13$1_1$138
;C:/ZGB-2023.0/common/src/SRAM.c:13: if(strcmp((char*)ptr, MAGIC) != 0) {
	ldhl	sp,	#10
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #___str_0
	push	hl
	push	de
	call	_strcmp
	add	sp, #4
	ld	a, d
	or	a, e
	jr	Z, 00104$
	C$SRAM.c$14$2_1$139	= .
	.globl	C$SRAM.c$14$2_1$139
;C:/ZGB-2023.0/common/src/SRAM.c:14: strcpy(ptr, MAGIC);
	ld	de, #___str_0
	push	de
	ldhl	sp,	#12
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	call	_strcpy
	add	sp, #4
	C$SRAM.c$16$2_1$139	= .
	.globl	C$SRAM.c$16$2_1$139
;C:/ZGB-2023.0/common/src/SRAM.c:16: bytes_to_clear = size - MAGIC_LENGTH - 2;
	ldhl	sp,#12
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x000b
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ld	b, a
	ld	c, e
	jr	00105$
00104$:
	C$SRAM.c$18$2_1$140	= .
	.globl	C$SRAM.c$18$2_1$140
;C:/ZGB-2023.0/common/src/SRAM.c:18: if(*bytes_stored < size) {
	pop	de
	push	de
	ld	a, (de)
	ldhl	sp,	#2
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	ldhl	sp,	#2
	ld	e, l
	ld	d, h
	ldhl	sp,	#12
	ld	a, (de)
	inc	de
	sub	a, (hl)
	inc	hl
	ld	a, (de)
	sbc	a, (hl)
	jr	NC, 00105$
	C$SRAM.c$19$3_1$141	= .
	.globl	C$SRAM.c$19$3_1$141
;C:/ZGB-2023.0/common/src/SRAM.c:19: bytes_to_clear = size - *bytes_stored;
	ldhl	sp,#12
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ldhl	sp,	#2
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ld	b, a
	ld	c, e
00105$:
	C$SRAM.c$23$1_1$138	= .
	.globl	C$SRAM.c$23$1_1$138
;C:/ZGB-2023.0/common/src/SRAM.c:23: if(*bytes_stored != size) {
	pop	de
	push	de
	ld	a, (de)
	ldhl	sp,	#2
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	ldhl	sp,	#12
	ld	a, (hl)
	ldhl	sp,	#2
	sub	a, (hl)
	jr	NZ, 00140$
	ldhl	sp,	#13
	ld	a, (hl)
	ldhl	sp,	#3
	sub	a, (hl)
	jr	Z, 00107$
00140$:
	C$SRAM.c$24$2_1$142	= .
	.globl	C$SRAM.c$24$2_1$142
;C:/ZGB-2023.0/common/src/SRAM.c:24: *bytes_stored = size;
	pop	de
	push	de
	ldhl	sp,	#12
	ld	a, (hl+)
	ld	(de), a
	inc	de
	ld	a, (hl)
	ld	(de), a
00107$:
	C$SRAM.c$27$1_1$138	= .
	.globl	C$SRAM.c$27$1_1$138
;C:/ZGB-2023.0/common/src/SRAM.c:27: if(bytes_to_clear > 0) {
	ld	a, b
	or	a, c
	jr	Z, 00109$
	C$SRAM.c$28$2_1$143	= .
	.globl	C$SRAM.c$28$2_1$143
;C:/ZGB-2023.0/common/src/SRAM.c:28: memset(ptr + size - bytes_to_clear, 0, bytes_to_clear);
	ldhl	sp,#10
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl+)
	ld	d, a
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, e
	sub	a, c
	ld	e, a
	ld	a, d
	sbc	a, b
	push	bc
	ld	bc, #0x0000
	push	bc
	ld	d, a
	push	de
	call	_memset
	add	sp, #6
00109$:
	C$SRAM.c$30$1_1$138	= .
	.globl	C$SRAM.c$30$1_1$138
;C:/ZGB-2023.0/common/src/SRAM.c:30: DISABLE_RAM;
	ld	hl, #_rRAMG
	ld	(hl), #0x00
	C$SRAM.c$31$1_1$137	= .
	.globl	C$SRAM.c$31$1_1$137
;C:/ZGB-2023.0/common/src/SRAM.c:31: }
	add	sp, #4
	C$SRAM.c$31$1_1$137	= .
	.globl	C$SRAM.c$31$1_1$137
	XG$CheckSRAMIntegrity$0$0	= .
	.globl	XG$CheckSRAMIntegrity$0$0
	ret
FSRAM$__str_0$0_0$0 == .
___str_0:
	.ascii "ZGB-SAVE"
	.db 0x00
	.area _CODE_1
	.area _INITIALIZER
	.area _CABS (ABS)
