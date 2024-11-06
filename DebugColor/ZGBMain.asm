;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module ZGBMain
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _GetTileReplacement
	.globl _next_state
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
G$next_state$0_0$0==.
_next_state::
	.ds 1
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
	G$GetTileReplacement$0$0	= .
	.globl	G$GetTileReplacement$0$0
	C$ZGBMain.c$6$0_0$161	= .
	.globl	C$ZGBMain.c$6$0_0$161
;ZGBMain.c:6: UINT8 GetTileReplacement(UINT8* tile_ptr, UINT8* tile) {
;	---------------------------------
; Function GetTileReplacement
; ---------------------------------
_GetTileReplacement::
	add	sp, #-3
	ldhl	sp,	#1
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
	C$ZGBMain.c$7$1_0$161	= .
	.globl	C$ZGBMain.c$7$1_0$161
;ZGBMain.c:7: if(current_state == StateGame) {
	ld	a, (#_current_state)
	or	a, a
	jr	NZ, 00104$
	C$ZGBMain.c$8$2_0$162	= .
	.globl	C$ZGBMain.c$8$2_0$162
;ZGBMain.c:8: if(U_LESS_THAN(255 - (UINT16)*tile_ptr, N_SPRITE_TYPES)) {
	ldhl	sp,#1
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl-)
	dec	hl
	ld	d, a
	ld	a, (de)
	ld	(hl), a
	ld	e, (hl)
	ld	d, #0x00
	ld	a, #0xfc
	sub	a, e
	sbc	a, a
	sub	a, d
	rlca
	jr	NC, 00102$
	C$ZGBMain.c$9$3_0$163	= .
	.globl	C$ZGBMain.c$9$3_0$163
;ZGBMain.c:9: *tile = 0;
	xor	a, a
	ld	(bc), a
	C$ZGBMain.c$10$3_0$163	= .
	.globl	C$ZGBMain.c$10$3_0$163
;ZGBMain.c:10: return 255 - (UINT16)*tile_ptr;
	ldhl	sp,#1
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	c, a
	ld	a, #0xff
	sub	a, c
	jr	00105$
00102$:
	C$ZGBMain.c$13$2_0$162	= .
	.globl	C$ZGBMain.c$13$2_0$162
;ZGBMain.c:13: *tile = *tile_ptr;
	ldhl	sp,	#0
	ld	a, (hl)
	ld	(bc), a
00104$:
	C$ZGBMain.c$16$1_0$161	= .
	.globl	C$ZGBMain.c$16$1_0$161
;ZGBMain.c:16: return 255u;
	ld	a, #0xff
00105$:
	C$ZGBMain.c$17$1_0$161	= .
	.globl	C$ZGBMain.c$17$1_0$161
;ZGBMain.c:17: }
	add	sp, #3
	C$ZGBMain.c$17$1_0$161	= .
	.globl	C$ZGBMain.c$17$1_0$161
	XG$GetTileReplacement$0$0	= .
	.globl	XG$GetTileReplacement$0$0
	ret
	.area _CODE
	.area _INITIALIZER
FZGBMain$__xinit_next_state$0_0$0 == .
__xinit__next_state:
	.db #0x00	; 0
	.area _CABS (ABS)
