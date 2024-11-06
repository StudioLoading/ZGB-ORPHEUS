;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module main
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _InitSprites
	.globl _InitStates
	.globl _vbl_update
	.globl _FadeOut
	.globl _FadeIn
	.globl _PopBank
	.globl _PushBank
	.globl _SpriteManagerUpdate
	.globl _SpriteManagerReset
	.globl _hUGE_mute
	.globl _cpu_fast
	.globl _set_sprite_palette
	.globl _set_bkg_palette
	.globl _MusicCallback
	.globl _memcpy
	.globl _display_off
	.globl _wait_vbl_done
	.globl _set_interrupts
	.globl _joypad
	.globl _add_low_priority_TIM
	.globl _add_LCD
	.globl _add_VBL
	.globl _default_palette
	.globl _music_mute_frames
	.globl _vbl_count
	.globl _state_running
	.globl _current_state
	.globl _delta_time
	.globl _SetState
	.globl _SetPalette
	.globl _LCD_isr
	.globl _SetWindowY
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
G$delta_time$0_0$0==.
_delta_time::
	.ds 1
G$current_state$0_0$0==.
_current_state::
	.ds 1
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
G$state_running$0_0$0==.
_state_running::
	.ds 1
G$vbl_count$0_0$0==.
_vbl_count::
	.ds 1
G$music_mute_frames$0_0$0==.
_music_mute_frames::
	.ds 1
G$default_palette$0_0$0==.
_default_palette::
	.ds 8
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
	G$LCD_isr$0$0	= .
	.globl	G$LCD_isr$0$0
	C$main.c$70$1_1$220	= .
	.globl	C$main.c$70$1_1$220
;C:/ZGB-2023.0/common/src/main.c:70: void LCD_isr() NONBANKED {
;	---------------------------------
; Function LCD_isr
; ---------------------------------
_LCD_isr::
	C$main.c$71$1_0$220	= .
	.globl	C$main.c$71$1_0$220
;C:/ZGB-2023.0/common/src/main.c:71: if (LYC_REG == 0) {
	ld	a, (#_LYC_REG)
	or	a, a
	jr	NZ, 00105$
	C$main.c$72$2_0$221	= .
	.globl	C$main.c$72$2_0$221
;C:/ZGB-2023.0/common/src/main.c:72: if (WY_REG == 0) {
	ld	a, (#_WY_REG)
	or	a, a
	jr	NZ, 00102$
	C$main.c$73$3_0$222	= .
	.globl	C$main.c$73$3_0$222
;C:/ZGB-2023.0/common/src/main.c:73: HIDE_SPRITES;
	ldh	a, (_LCDC_REG + 0)
	and	a, #0xfd
	ldh	(_LCDC_REG + 0), a
	ret
00102$:
	C$main.c$75$3_0$223	= .
	.globl	C$main.c$75$3_0$223
;C:/ZGB-2023.0/common/src/main.c:75: SHOW_SPRITES;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x02
	ldh	(_LCDC_REG + 0), a
	C$main.c$76$3_0$223	= .
	.globl	C$main.c$76$3_0$223
;C:/ZGB-2023.0/common/src/main.c:76: LYC_REG = WY_REG - 1;
	ldh	a, (_WY_REG + 0)
	dec	a
	ldh	(_LYC_REG + 0), a
	ret
00105$:
	C$main.c$79$2_0$224	= .
	.globl	C$main.c$79$2_0$224
;C:/ZGB-2023.0/common/src/main.c:79: HIDE_SPRITES;
	ldh	a, (_LCDC_REG + 0)
	and	a, #0xfd
	ldh	(_LCDC_REG + 0), a
	C$main.c$80$2_0$224	= .
	.globl	C$main.c$80$2_0$224
;C:/ZGB-2023.0/common/src/main.c:80: LYC_REG = 0;
	xor	a, a
	ldh	(_LYC_REG + 0), a
	C$main.c$82$1_0$220	= .
	.globl	C$main.c$82$1_0$220
;C:/ZGB-2023.0/common/src/main.c:82: }
	C$main.c$82$1_0$220	= .
	.globl	C$main.c$82$1_0$220
	XG$LCD_isr$0$0	= .
	.globl	XG$LCD_isr$0$0
	ret
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
	G$SetState$0$0	= .
	.globl	G$SetState$0$0
	C$main.c$27$0_0$211	= .
	.globl	C$main.c$27$0_0$211
;C:/ZGB-2023.0/common/src/main.c:27: void SetState(UINT8 state) {
;	---------------------------------
; Function SetState
; ---------------------------------
_SetState::
	ld	(#_next_state),a
	C$main.c$28$1_0$211	= .
	.globl	C$main.c$28$1_0$211
;C:/ZGB-2023.0/common/src/main.c:28: state_running = 0;
	ld	hl, #_state_running
	ld	(hl), #0x00
	C$main.c$29$1_0$211	= .
	.globl	C$main.c$29$1_0$211
;C:/ZGB-2023.0/common/src/main.c:29: next_state = state;
	C$main.c$30$1_0$211	= .
	.globl	C$main.c$30$1_0$211
;C:/ZGB-2023.0/common/src/main.c:30: }
	C$main.c$30$1_0$211	= .
	.globl	C$main.c$30$1_0$211
	XG$SetState$0$0	= .
	.globl	XG$SetState$0$0
	ret
	G$vbl_update$0$0	= .
	.globl	G$vbl_update$0$0
	C$main.c$34$1_0$212	= .
	.globl	C$main.c$34$1_0$212
;C:/ZGB-2023.0/common/src/main.c:34: void vbl_update() {
;	---------------------------------
; Function vbl_update
; ---------------------------------
_vbl_update::
	C$main.c$35$1_0$212	= .
	.globl	C$main.c$35$1_0$212
;C:/ZGB-2023.0/common/src/main.c:35: vbl_count ++;
	ld	hl, #_vbl_count
	inc	(hl)
	C$main.c$37$1_0$212	= .
	.globl	C$main.c$37$1_0$212
;C:/ZGB-2023.0/common/src/main.c:37: SCX_REG = scroll_x_vblank + (scroll_offset_x << 3);
	ld	a, (#_scroll_offset_x)
	add	a, a
	add	a, a
	add	a, a
	ld	hl, #_scroll_x_vblank
	ld	c, (hl)
	add	a, c
	ldh	(_SCX_REG + 0), a
	C$main.c$38$1_0$212	= .
	.globl	C$main.c$38$1_0$212
;C:/ZGB-2023.0/common/src/main.c:38: SCY_REG = scroll_y_vblank + (scroll_offset_y << 3);
	ld	a, (#_scroll_offset_y)
	add	a, a
	add	a, a
	add	a, a
	ld	hl, #_scroll_y_vblank
	ld	c, (hl)
	add	a, c
	ldh	(_SCY_REG + 0), a
	C$main.c$40$1_0$212	= .
	.globl	C$main.c$40$1_0$212
;C:/ZGB-2023.0/common/src/main.c:40: if(music_mute_frames != 0) {
	ld	hl, #_music_mute_frames
	ld	a, (hl)
	or	a, a
	ret	Z
	C$main.c$41$2_0$213	= .
	.globl	C$main.c$41$2_0$213
;C:/ZGB-2023.0/common/src/main.c:41: music_mute_frames --;
	C$main.c$42$2_0$213	= .
	.globl	C$main.c$42$2_0$213
;C:/ZGB-2023.0/common/src/main.c:42: if(music_mute_frames == 0) {
	dec	(hl)
	ld	a, (hl)
	ret	NZ
	C$main.c$43$3_0$214	= .
	.globl	C$main.c$43$3_0$214
;C:/ZGB-2023.0/common/src/main.c:43: UNMUTE_ALL_CHANNELS;
	xor	a, a
	C$main.c$46$1_0$212	= .
	.globl	C$main.c$46$1_0$212
;C:/ZGB-2023.0/common/src/main.c:46: }
	C$main.c$46$1_0$212	= .
	.globl	C$main.c$46$1_0$212
	XG$vbl_update$0$0	= .
	.globl	XG$vbl_update$0$0
	jp	_hUGE_mute
	G$SetPalette$0$0	= .
	.globl	G$SetPalette$0$0
	C$main.c$54$1_0$216	= .
	.globl	C$main.c$54$1_0$216
;C:/ZGB-2023.0/common/src/main.c:54: void SetPalette(PALETTE_TYPE t, UINT8 first_palette, UINT8 nb_palettes, UINT16 *rgb_data, UINT8 bank) {
;	---------------------------------
; Function SetPalette
; ---------------------------------
_SetPalette::
	add	sp, #-6
	ldhl	sp,	#5
	ld	(hl-), a
	ld	(hl), e
	C$main.c$55$1_0$216	= .
	.globl	C$main.c$55$1_0$216
;C:/ZGB-2023.0/common/src/main.c:55: if(first_palette + nb_palettes > 8)
	ld	c, (hl)
	ld	b, #0x00
	ldhl	sp,	#8
	ld	a, (hl)
	ldhl	sp,	#2
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	inc	sp
	inc	sp
	push	hl
	ldhl	sp,	#0
	ld	a, #0x08
	sub	a, (hl)
	inc	hl
	ld	a, #0x00
	sbc	a, (hl)
	ld	a, #0x00
	ld	d, a
	ld	e, (hl)
	bit	7, e
	jr	Z, 00131$
	bit	7, d
	jr	NZ, 00132$
	cp	a, a
	jr	00132$
00131$:
	bit	7, d
	jr	Z, 00132$
	scf
00132$:
	C$main.c$56$1_0$216	= .
	.globl	C$main.c$56$1_0$216
;C:/ZGB-2023.0/common/src/main.c:56: return; //Adding more palettes than supported
	jp	C,00106$
	C$main.c$58$1_1$217	= .
	.globl	C$main.c$58$1_1$217
;C:/ZGB-2023.0/common/src/main.c:58: UWORD* pal_ptr = (t == BG_PALETTE) ? ZGB_Fading_BPal : ZGB_Fading_SPal;
	ldhl	sp,	#5
	bit	0, (hl)
	jr	NZ, 00108$
	ld	de, #_ZGB_Fading_BPal+0
	jr	00109$
00108$:
	ld	de, #_ZGB_Fading_SPal+0
00109$:
	inc	sp
	inc	sp
	push	de
	C$main.c$59$1_1$217	= .
	.globl	C$main.c$59$1_1$217
;C:/ZGB-2023.0/common/src/main.c:59: PUSH_BANK(bank);
	push	bc
	ldhl	sp,	#13
	ld	a, (hl)
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	pop	bc
	C$main.c$61$1_1$216	= .
	.globl	C$main.c$61$1_1$216
;C:/ZGB-2023.0/common/src/main.c:61: set_bkg_palette(first_palette, nb_palettes, rgb_data);
	ldhl	sp,	#9
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	C$main.c$60$1_1$217	= .
	.globl	C$main.c$60$1_1$217
;C:/ZGB-2023.0/common/src/main.c:60: if(t == BG_PALETTE) {
	ldhl	sp,	#5
	bit	0, (hl)
	jr	NZ, 00104$
	C$main.c$61$2_1$218	= .
	.globl	C$main.c$61$2_1$218
;C:/ZGB-2023.0/common/src/main.c:61: set_bkg_palette(first_palette, nb_palettes, rgb_data);
	push	bc
	push	de
	ldhl	sp,	#12
	ld	a, (hl)
	push	af
	inc	sp
	ldhl	sp,	#9
	ld	a, (hl)
	push	af
	inc	sp
	call	_set_bkg_palette
	add	sp, #4
	pop	bc
	jr	00105$
00104$:
	C$main.c$63$2_1$219	= .
	.globl	C$main.c$63$2_1$219
;C:/ZGB-2023.0/common/src/main.c:63: set_sprite_palette(first_palette, nb_palettes, rgb_data);
	push	bc
	push	de
	ldhl	sp,	#12
	ld	a, (hl)
	push	af
	inc	sp
	ldhl	sp,	#9
	ld	a, (hl)
	push	af
	inc	sp
	call	_set_sprite_palette
	add	sp, #4
	pop	bc
00105$:
	C$main.c$65$1_1$217	= .
	.globl	C$main.c$65$1_1$217
;C:/ZGB-2023.0/common/src/main.c:65: memcpy(&pal_ptr[first_palette << 2], rgb_data, nb_palettes << 3);
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	sla	e
	rl	d
	sla	e
	rl	d
	sla	e
	rl	d
	ldhl	sp,	#9
	ld	a, (hl)
	ldhl	sp,	#2
	ld	(hl), a
	ldhl	sp,	#10
	ld	a, (hl)
	ldhl	sp,	#3
	ld	(hl), a
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	c, l
	ld	b, h
	pop	hl
	push	hl
	add	hl, bc
;	spillPairReg hl
;	spillPairReg hl
	ld	a,h
;	spillPairReg hl
;	spillPairReg hl
	push	de
	push	hl
	ldhl	sp,	#6
	ld	c, (hl)
	ldhl	sp,	#7
	ld	b, (hl)
	pop	de
	call	_memcpy
	C$main.c$66$1_1$217	= .
	.globl	C$main.c$66$1_1$217
;C:/ZGB-2023.0/common/src/main.c:66: POP_BANK;
	call	_PopBank
00106$:
	C$main.c$67$1_1$216	= .
	.globl	C$main.c$67$1_1$216
;C:/ZGB-2023.0/common/src/main.c:67: }
	add	sp, #6
	pop	hl
	add	sp, #4
	jp	(hl)
	G$SetWindowY$0$0	= .
	.globl	G$SetWindowY$0$0
	C$main.c$84$1_0$226	= .
	.globl	C$main.c$84$1_0$226
;C:/ZGB-2023.0/common/src/main.c:84: void SetWindowY(UINT8 y) {
;	---------------------------------
; Function SetWindowY
; ---------------------------------
_SetWindowY::
	C$main.c$85$1_0$226	= .
	.globl	C$main.c$85$1_0$226
;C:/ZGB-2023.0/common/src/main.c:85: WY_REG = y;
	ld	c, a
	ldh	(_WY_REG + 0), a
	C$main.c$86$1_0$226	= .
	.globl	C$main.c$86$1_0$226
;C:/ZGB-2023.0/common/src/main.c:86: LYC_REG = y - 1;
	ld	a, c
	dec	a
	ldh	(_LYC_REG + 0), a
	C$main.c$87$1_0$226	= .
	.globl	C$main.c$87$1_0$226
;C:/ZGB-2023.0/common/src/main.c:87: if (y < 144u) {
	ld	a, c
	sub	a, #0x90
	jr	NC, 00102$
	C$main.c$88$2_0$227	= .
	.globl	C$main.c$88$2_0$227
;C:/ZGB-2023.0/common/src/main.c:88: SHOW_WIN; 
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x20
	ldh	(_LCDC_REG + 0), a
	ret
00102$:
	C$main.c$90$2_0$228	= .
	.globl	C$main.c$90$2_0$228
;C:/ZGB-2023.0/common/src/main.c:90: HIDE_WIN; 
	ldh	a, (_LCDC_REG + 0)
	and	a, #0xdf
	ldh	(_LCDC_REG + 0), a
	C$main.c$91$2_0$228	= .
	.globl	C$main.c$91$2_0$228
;C:/ZGB-2023.0/common/src/main.c:91: LYC_REG = 160u; 
	ld	a, #0xa0
	ldh	(_LYC_REG + 0), a
	C$main.c$93$1_0$226	= .
	.globl	C$main.c$93$1_0$226
;C:/ZGB-2023.0/common/src/main.c:93: }
	C$main.c$93$1_0$226	= .
	.globl	C$main.c$93$1_0$226
	XG$SetWindowY$0$0	= .
	.globl	XG$SetWindowY$0$0
	ret
	G$main$0$0	= .
	.globl	G$main$0$0
	C$main.c$104$1_0$229	= .
	.globl	C$main.c$104$1_0$229
;C:/ZGB-2023.0/common/src/main.c:104: void main() {
;	---------------------------------
; Function main
; ---------------------------------
_main::
	C$main.c$106$1_1$229	= .
	.globl	C$main.c$106$1_1$229
;C:/ZGB-2023.0/common/src/main.c:106: for (UINT8 i = 4; i != 0; i--) {
	ld	c, #0x04
00119$:
	ld	a, c
	or	a, a
	jr	Z, 00101$
	C$main.c$107$3_0$231	= .
	.globl	C$main.c$107$3_0$231
;C:/ZGB-2023.0/common/src/main.c:107: wait_vbl_done();
	call	_wait_vbl_done
	C$main.c$106$2_0$230	= .
	.globl	C$main.c$106$2_0$230
;C:/ZGB-2023.0/common/src/main.c:106: for (UINT8 i = 4; i != 0; i--) {
	dec	c
	jr	00119$
00101$:
	C$main.c$116$1_1$232	= .
	.globl	C$main.c$116$1_1$232
;C:/ZGB-2023.0/common/src/main.c:116: cpu_fast();
	call	_cpu_fast
	C$main.c$120$1_1$232	= .
	.globl	C$main.c$120$1_1$232
;C:/ZGB-2023.0/common/src/main.c:120: PUSH_BANK(1);
	ld	a, #0x01
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	C$main.c$121$1_1$232	= .
	.globl	C$main.c$121$1_1$232
;C:/ZGB-2023.0/common/src/main.c:121: InitStates();
	call	_InitStates
	C$main.c$122$1_1$232	= .
	.globl	C$main.c$122$1_1$232
;C:/ZGB-2023.0/common/src/main.c:122: InitSprites();
	call	_InitSprites
	C$main.c$123$1_1$232	= .
	.globl	C$main.c$123$1_1$232
;C:/ZGB-2023.0/common/src/main.c:123: POP_BANK;
	call	_PopBank
	C$main.c$140$1_1$232	= .
	.globl	C$main.c$140$1_1$232
;C:/ZGB-2023.0/common/src/main.c:140: }
	di
	C$main.c$127$2_1$233	= .
	.globl	C$main.c$127$2_1$233
;C:/ZGB-2023.0/common/src/main.c:127: TMA_REG = _cpu == CGB_TYPE ? 120U : 0xBCU;
	ld	a, (#__cpu)
	sub	a, #0x11
	ld	a, #0x78
	jr	Z, 00126$
	ld	a, #0xbc
00126$:
	ldh	(_TMA_REG + 0), a
	C$main.c$131$2_1$233	= .
	.globl	C$main.c$131$2_1$233
;C:/ZGB-2023.0/common/src/main.c:131: TAC_REG = 0x04U;
	ld	a, #0x04
	ldh	(_TAC_REG + 0), a
	C$main.c$134$2_1$233	= .
	.globl	C$main.c$134$2_1$233
;C:/ZGB-2023.0/common/src/main.c:134: add_low_priority_TIM(MusicCallback); 
	ld	de, #_MusicCallback
	call	_add_low_priority_TIM
	C$main.c$136$2_1$233	= .
	.globl	C$main.c$136$2_1$233
;C:/ZGB-2023.0/common/src/main.c:136: add_VBL(vbl_update);
	ld	de, #_vbl_update
	call	_add_VBL
	C$main.c$138$2_1$233	= .
	.globl	C$main.c$138$2_1$233
;C:/ZGB-2023.0/common/src/main.c:138: STAT_REG |= 0x40; 
	ldh	a, (_STAT_REG + 0)
	or	a, #0x40
	ldh	(_STAT_REG + 0), a
	C$main.c$139$2_1$233	= .
	.globl	C$main.c$139$2_1$233
;C:/ZGB-2023.0/common/src/main.c:139: add_LCD(LCD_isr);
	ld	de, #_LCD_isr
	call	_add_LCD
	ei
	C$main.c$142$1_1$232	= .
	.globl	C$main.c$142$1_1$232
;C:/ZGB-2023.0/common/src/main.c:142: set_interrupts(VBL_IFLAG | TIM_IFLAG | LCD_IFLAG);
	ld	a, #0x07
	call	_set_interrupts
	C$main.c$144$1_1$232	= .
	.globl	C$main.c$144$1_1$232
;C:/ZGB-2023.0/common/src/main.c:144: LCDC_REG |= LCDCF_OBJDEFAULT | LCDCF_OBJON | LCDCF_BGON;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x07
	ldh	(_LCDC_REG + 0), a
	C$main.c$145$1_1$232	= .
	.globl	C$main.c$145$1_1$232
;C:/ZGB-2023.0/common/src/main.c:145: WY_REG = 145;
	ld	a, #0x91
	ldh	(_WY_REG + 0), a
	C$main.c$147$1_1$232	= .
	.globl	C$main.c$147$1_1$232
;C:/ZGB-2023.0/common/src/main.c:147: while(1) {
00116$:
	C$main.c$148$2_1$234	= .
	.globl	C$main.c$148$2_1$234
;C:/ZGB-2023.0/common/src/main.c:148: DISPLAY_OFF
	call	_display_off
	C$main.c$150$2_1$234	= .
	.globl	C$main.c$150$2_1$234
;C:/ZGB-2023.0/common/src/main.c:150: if(stop_music_on_new_state)
	ld	a, (#_stop_music_on_new_state)
	or	a, a
	jr	Z, 00103$
	C$main.c$152$3_1$235	= .
	.globl	C$main.c$152$3_1$235
;C:/ZGB-2023.0/common/src/main.c:152: StopMusic;
	ld	hl, #_hUGE_paused
	ld	(hl), #0x01
	ld	a, #0x01
	call	_hUGE_mute
	xor	a, a
	ld	hl, #_last_music
	ld	(hl+), a
	ld	(hl), a
00103$:
	C$main.c$155$2_1$234	= .
	.globl	C$main.c$155$2_1$234
;C:/ZGB-2023.0/common/src/main.c:155: SpriteManagerReset();
	call	_SpriteManagerReset
	C$main.c$156$2_1$234	= .
	.globl	C$main.c$156$2_1$234
;C:/ZGB-2023.0/common/src/main.c:156: state_running = 1;
	ld	hl, #_state_running
	ld	(hl), #0x01
	C$main.c$157$2_1$234	= .
	.globl	C$main.c$157$2_1$234
;C:/ZGB-2023.0/common/src/main.c:157: current_state = next_state;
	ld	a, (#_next_state)
	ld	(#_current_state),a
	C$main.c$158$2_1$234	= .
	.globl	C$main.c$158$2_1$234
;C:/ZGB-2023.0/common/src/main.c:158: scroll_target = 0;
	xor	a, a
	ld	hl, #_scroll_target
	ld	(hl+), a
	ld	(hl), a
	C$main.c$159$2_1$234	= .
	.globl	C$main.c$159$2_1$234
;C:/ZGB-2023.0/common/src/main.c:159: last_bg_pal_loaded = 0;
	ld	hl, #_last_bg_pal_loaded
	ld	(hl), #0x00
	C$main.c$160$2_1$234	= .
	.globl	C$main.c$160$2_1$234
;C:/ZGB-2023.0/common/src/main.c:160: last_tile_loaded = 0;
	ld	hl, #_last_tile_loaded
	ld	(hl), #0x00
	C$main.c$163$2_1$234	= .
	.globl	C$main.c$163$2_1$234
;C:/ZGB-2023.0/common/src/main.c:163: if (_cpu == CGB_TYPE) {
	ld	a, (#__cpu)
	C$main.c$164$5_1$238	= .
	.globl	C$main.c$164$5_1$238
;C:/ZGB-2023.0/common/src/main.c:164: for(i = 0; i < 8; ++ i)
	sub	a,#0x11
	jr	NZ, 00106$
	ld	e,a
00121$:
	C$main.c$166$5_1$238	= .
	.globl	C$main.c$166$5_1$238
;C:/ZGB-2023.0/common/src/main.c:166: SetPalette(BG_PALETTE, i, 1, default_palette, 1);
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	bc, #_default_palette
	push	bc
	ld	a, #0x01
	push	af
	inc	sp
	xor	a, a
	call	_SetPalette
	pop	de
	C$main.c$167$5_1$238	= .
	.globl	C$main.c$167$5_1$238
;C:/ZGB-2023.0/common/src/main.c:167: SetPalette(SPRITES_PALETTE, i, 1, default_palette, 1);
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	bc, #_default_palette
	push	bc
	ld	a, #0x01
	push	af
	inc	sp
	ld	a, #0x01
	call	_SetPalette
	pop	de
	C$main.c$164$4_1$237	= .
	.globl	C$main.c$164$4_1$237
;C:/ZGB-2023.0/common/src/main.c:164: for(i = 0; i < 8; ++ i)
	inc	e
	ld	a, e
	sub	a, #0x08
	jr	C, 00121$
	jr	00107$
00106$:
	C$main.c$171$2_1$234	= .
	.globl	C$main.c$171$2_1$234
;C:/ZGB-2023.0/common/src/main.c:171: BGP_REG = OBP0_REG = OBP1_REG = PAL_DEF(0, 1, 2, 3);
	ld	a, #0xe4
	ldh	(_OBP1_REG + 0), a
	ld	a, #0xe4
	ldh	(_OBP0_REG + 0), a
	ld	a, #0xe4
	ldh	(_BGP_REG + 0), a
00107$:
	C$main.c$173$2_1$234	= .
	.globl	C$main.c$173$2_1$234
;C:/ZGB-2023.0/common/src/main.c:173: PUSH_BANK(stateBanks[current_state]);
	ld	a, #<(_stateBanks)
	ld	hl, #_current_state
	add	a, (hl)
	ld	c, a
	ld	a, #>(_stateBanks)
	adc	a, #0x00
	ld	b, a
	ld	a, (bc)
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	C$main.c$174$2_1$234	= .
	.globl	C$main.c$174$2_1$234
;C:/ZGB-2023.0/common/src/main.c:174: (startFuncs[current_state])();
	ld	hl, #_current_state
	ld	l, (hl)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	ld	de, #_startFuncs
	add	hl, de
	ld	a,	(hl+)
	ld	h, (hl)
;	spillPairReg hl
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	call	___sdcc_call_hl
	C$main.c$175$2_1$234	= .
	.globl	C$main.c$175$2_1$234
;C:/ZGB-2023.0/common/src/main.c:175: POP_BANK;
	call	_PopBank
	C$main.c$176$2_1$234	= .
	.globl	C$main.c$176$2_1$234
;C:/ZGB-2023.0/common/src/main.c:176: scroll_x_vblank = scroll_x;
	ld	a, (#_scroll_x)
	ld	(#_scroll_x_vblank),a
	C$main.c$177$2_1$234	= .
	.globl	C$main.c$177$2_1$234
;C:/ZGB-2023.0/common/src/main.c:177: scroll_y_vblank = scroll_y;
	ld	a, (#_scroll_y)
	ld	(#_scroll_y_vblank),a
	C$main.c$179$2_1$234	= .
	.globl	C$main.c$179$2_1$234
;C:/ZGB-2023.0/common/src/main.c:179: if(state_running) {
	ld	a, (#_state_running)
	or	a, a
	jr	Z, 00140$
	C$main.c$180$3_1$239	= .
	.globl	C$main.c$180$3_1$239
;C:/ZGB-2023.0/common/src/main.c:180: DISPLAY_ON;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x80
	ldh	(_LCDC_REG + 0), a
	C$main.c$181$3_1$239	= .
	.globl	C$main.c$181$3_1$239
;C:/ZGB-2023.0/common/src/main.c:181: FadeOut();
	call	_FadeOut
	C$main.c$184$1_1$229	= .
	.globl	C$main.c$184$1_1$229
;C:/ZGB-2023.0/common/src/main.c:184: while (state_running) {
00140$:
00112$:
	ld	a, (#_state_running)
	or	a, a
	jr	Z, 00114$
	C$main.c$185$3_1$240	= .
	.globl	C$main.c$185$3_1$240
;C:/ZGB-2023.0/common/src/main.c:185: if(!vbl_count)
	ld	a, (#_vbl_count)
	or	a, a
	jr	NZ, 00111$
	C$main.c$186$3_1$240	= .
	.globl	C$main.c$186$3_1$240
;C:/ZGB-2023.0/common/src/main.c:186: wait_vbl_done();
	call	_wait_vbl_done
00111$:
	C$main.c$187$3_1$240	= .
	.globl	C$main.c$187$3_1$240
;C:/ZGB-2023.0/common/src/main.c:187: delta_time = vbl_count == 1u ? 0u : 1u;
	ld	a, (#_vbl_count)
	dec	a
	jr	NZ, 00127$
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	jr	00128$
00127$:
	ld	a, #0x01
	ld	l, #0x00
;	spillPairReg hl
;	spillPairReg hl
00128$:
	ld	(_delta_time), a
	C$main.c$188$3_1$240	= .
	.globl	C$main.c$188$3_1$240
;C:/ZGB-2023.0/common/src/main.c:188: vbl_count = 0;
	ld	hl, #_vbl_count
	ld	(hl), #0x00
	C$main.c$190$3_1$240	= .
	.globl	C$main.c$190$3_1$240
;C:/ZGB-2023.0/common/src/main.c:190: UPDATE_KEYS();
	ld	a, (#_keys)
	ld	(#_previous_keys),a
	call	_joypad
	ld	(#_keys),a
	C$main.c$192$3_1$240	= .
	.globl	C$main.c$192$3_1$240
;C:/ZGB-2023.0/common/src/main.c:192: SpriteManagerUpdate();
	call	_SpriteManagerUpdate
	C$main.c$193$3_1$240	= .
	.globl	C$main.c$193$3_1$240
;C:/ZGB-2023.0/common/src/main.c:193: PUSH_BANK(stateBanks[current_state]);
	ld	a, #<(_stateBanks)
	ld	hl, #_current_state
	add	a, (hl)
	ld	c, a
	ld	a, #>(_stateBanks)
	adc	a, #0x00
	ld	b, a
	ld	a, (bc)
	push	af
	inc	sp
	call	_PushBank
	inc	sp
	C$main.c$194$3_1$240	= .
	.globl	C$main.c$194$3_1$240
;C:/ZGB-2023.0/common/src/main.c:194: updateFuncs[current_state]();
	ld	hl, #_current_state
	ld	l, (hl)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	ld	de, #_updateFuncs
	add	hl, de
	ld	c, (hl)
	inc	hl
	ld	h, (hl)
;	spillPairReg hl
	ld	l, c
;	spillPairReg hl
;	spillPairReg hl
	call	___sdcc_call_hl
	C$main.c$195$3_1$240	= .
	.globl	C$main.c$195$3_1$240
;C:/ZGB-2023.0/common/src/main.c:195: POP_BANK;
	call	_PopBank
	jr	00112$
00114$:
	C$main.c$198$2_1$234	= .
	.globl	C$main.c$198$2_1$234
;C:/ZGB-2023.0/common/src/main.c:198: FadeIn();
	call	_FadeIn
	C$main.c$200$1_1$229	= .
	.globl	C$main.c$200$1_1$229
;C:/ZGB-2023.0/common/src/main.c:200: }
	C$main.c$200$1_1$229	= .
	.globl	C$main.c$200$1_1$229
	XG$main$0$0	= .
	.globl	XG$main$0$0
	jp	00116$
	.area _CODE
	.area _INITIALIZER
Fmain$__xinit_state_running$0_0$0 == .
__xinit__state_running:
	.db #0x00	; 0
Fmain$__xinit_vbl_count$0_0$0 == .
__xinit__vbl_count:
	.db #0x00	; 0
Fmain$__xinit_music_mute_frames$0_0$0 == .
__xinit__music_mute_frames:
	.db #0x00	; 0
Fmain$__xinit_default_palette$0_0$0 == .
__xinit__default_palette:
	.dw #0x7fff
	.dw #0x5294
	.dw #0x294a
	.dw #0x0000
	.area _CABS (ABS)
