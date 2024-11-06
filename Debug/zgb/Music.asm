;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module Music
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _hUGE_mute_channel
	.globl _hUGE_dosound
	.globl _hUGE_init
	.globl _stop_music_on_new_state
	.globl _last_music
	.globl _hUGE_paused
	.globl _hUGE_current_track_bank
	.globl _hUGE_current_track
	.globl _MusicCallback
	.globl _hUGE_mute
	.globl ___PlayMusic
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
G$hUGE_current_track$0_0$0==.
_hUGE_current_track::
	.ds 2
G$hUGE_current_track_bank$0_0$0==.
_hUGE_current_track_bank::
	.ds 1
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
G$hUGE_paused$0_0$0==.
_hUGE_paused::
	.ds 1
G$last_music$0_0$0==.
_last_music::
	.ds 2
G$stop_music_on_new_state$0_0$0==.
_stop_music_on_new_state::
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
	G$MusicCallback$0$0	= .
	.globl	G$MusicCallback$0$0
	C$Music.c$8$0_0$142	= .
	.globl	C$Music.c$8$0_0$142
;C:/ZGB-2023.0/common/src/Music.c:8: void MusicCallback() __nonbanked {
;	---------------------------------
; Function MusicCallback
; ---------------------------------
_MusicCallback::
	C$Music.c$9$1_0$142	= .
	.globl	C$Music.c$9$1_0$142
;C:/ZGB-2023.0/common/src/Music.c:9: if (hUGE_paused) 
	ld	a, (#_hUGE_paused)
	or	a, a
	C$Music.c$10$1_0$142	= .
	.globl	C$Music.c$10$1_0$142
;C:/ZGB-2023.0/common/src/Music.c:10: return;
	ret	NZ
	C$Music.c$12$2_0$143	= .
	.globl	C$Music.c$12$2_0$143
;C:/ZGB-2023.0/common/src/Music.c:12: UBYTE __save = _current_bank;
	ldh	a, (__current_bank + 0)
	ld	c, a
	C$Music.c$13$1_1$142	= .
	.globl	C$Music.c$13$1_1$142
;C:/ZGB-2023.0/common/src/Music.c:13: SWITCH_ROM_MBC1(hUGE_current_track_bank);
	ld	a, (#_hUGE_current_track_bank)
	ldh	(__current_bank + 0), a
	ld	(#_rROMB0),a
	C$Music.c$14$1_1$143	= .
	.globl	C$Music.c$14$1_1$143
;C:/ZGB-2023.0/common/src/Music.c:14: hUGE_dosound();
	push	bc
	call	_hUGE_dosound
	pop	bc
	C$Music.c$15$1_1$143	= .
	.globl	C$Music.c$15$1_1$143
;C:/ZGB-2023.0/common/src/Music.c:15: SWITCH_ROM_MBC1(__save);
	ld	a, c
	ldh	(__current_bank + 0), a
	ld	hl, #_rROMB0
	ld	(hl), c
	C$Music.c$16$1_1$142	= .
	.globl	C$Music.c$16$1_1$142
;C:/ZGB-2023.0/common/src/Music.c:16: }
	C$Music.c$16$1_1$142	= .
	.globl	C$Music.c$16$1_1$142
	XG$MusicCallback$0$0	= .
	.globl	XG$MusicCallback$0$0
	ret
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
	G$hUGE_mute$0$0	= .
	.globl	G$hUGE_mute$0$0
	C$Music.c$18$1_1$145	= .
	.globl	C$Music.c$18$1_1$145
;C:/ZGB-2023.0/common/src/Music.c:18: void hUGE_mute(UBYTE mute) {
;	---------------------------------
; Function hUGE_mute
; ---------------------------------
_hUGE_mute::
	ld	c, a
	C$Music.c$19$1_0$145	= .
	.globl	C$Music.c$19$1_0$145
;C:/ZGB-2023.0/common/src/Music.c:19: hUGE_mute_channel(HT_CH1, mute);
	xor	a, a
	cp	a, c
	rla
	ld	e, a
	push	de
	xor	a, a
	call	_hUGE_mute_channel
	pop	de
	C$Music.c$20$1_0$145	= .
	.globl	C$Music.c$20$1_0$145
;C:/ZGB-2023.0/common/src/Music.c:20: hUGE_mute_channel(HT_CH2, mute);
	push	de
	ld	a, #0x01
	call	_hUGE_mute_channel
	pop	de
	C$Music.c$21$1_0$145	= .
	.globl	C$Music.c$21$1_0$145
;C:/ZGB-2023.0/common/src/Music.c:21: hUGE_mute_channel(HT_CH3, mute);
	push	de
	ld	a, #0x02
	call	_hUGE_mute_channel
	pop	de
	C$Music.c$22$1_0$145	= .
	.globl	C$Music.c$22$1_0$145
;C:/ZGB-2023.0/common/src/Music.c:22: hUGE_mute_channel(HT_CH4, mute);
	ld	a, #0x03
	C$Music.c$23$1_0$145	= .
	.globl	C$Music.c$23$1_0$145
;C:/ZGB-2023.0/common/src/Music.c:23: }
	C$Music.c$23$1_0$145	= .
	.globl	C$Music.c$23$1_0$145
	XG$hUGE_mute$0$0	= .
	.globl	XG$hUGE_mute$0$0
	jp	_hUGE_mute_channel
	G$__PlayMusic$0$0	= .
	.globl	G$__PlayMusic$0$0
	C$Music.c$40$1_0$147	= .
	.globl	C$Music.c$40$1_0$147
;C:/ZGB-2023.0/common/src/Music.c:40: void __PlayMusic(void* music, unsigned char bank, unsigned char loop) {
;	---------------------------------
; Function __PlayMusic
; ---------------------------------
___PlayMusic::
	ld	c, a
	C$Music.c$42$1_0$147	= .
	.globl	C$Music.c$42$1_0$147
;C:/ZGB-2023.0/common/src/Music.c:42: if(music != last_music) {
	ld	hl, #_last_music
	ld	a, (hl)
	sub	a, e
	jr	NZ, 00112$
	inc	hl
	ld	a, (hl)
	sub	a, d
	jr	Z, 00103$
00112$:
	C$Music.c$43$2_0$148	= .
	.globl	C$Music.c$43$2_0$148
;C:/ZGB-2023.0/common/src/Music.c:43: last_music = music;
	ld	hl, #_last_music
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
	C$Music.c$50$2_0$148	= .
	.globl	C$Music.c$50$2_0$148
;C:/ZGB-2023.0/common/src/Music.c:50: NR52_REG = 0x80;
	ld	a, #0x80
	ldh	(_NR52_REG + 0), a
	C$Music.c$51$2_0$148	= .
	.globl	C$Music.c$51$2_0$148
;C:/ZGB-2023.0/common/src/Music.c:51: NR51_REG = 0xFF;
	ld	a, #0xff
	ldh	(_NR51_REG + 0), a
	C$Music.c$52$2_0$148	= .
	.globl	C$Music.c$52$2_0$148
;C:/ZGB-2023.0/common/src/Music.c:52: NR50_REG = 0x77;
	ld	a, #0x77
	ldh	(_NR50_REG + 0), a
	C$Music.c$54$2_0$148	= .
	.globl	C$Music.c$54$2_0$148
;C:/ZGB-2023.0/common/src/Music.c:54: hUGE_paused = 1;
	ld	hl, #_hUGE_paused
	ld	(hl), #0x01
	C$Music.c$55$2_0$148	= .
	.globl	C$Music.c$55$2_0$148
;C:/ZGB-2023.0/common/src/Music.c:55: hUGE_current_track = music; hUGE_current_track_bank = bank;
	ld	hl, #_hUGE_current_track
	ld	(hl), e
	inc	hl
	ld	(hl), d
	ld	hl, #_hUGE_current_track_bank
	ld	(hl), c
	C$Music.c$56$3_0$149	= .
	.globl	C$Music.c$56$3_0$149
;C:/ZGB-2023.0/common/src/Music.c:56: UBYTE __save = _current_bank;
	ldh	a, (__current_bank + 0)
	ld	c, a
	C$Music.c$57$1_0$147	= .
	.globl	C$Music.c$57$1_0$147
;C:/ZGB-2023.0/common/src/Music.c:57: SWITCH_ROM_MBC1(hUGE_current_track_bank);
	ld	a, (hl)
	ldh	(__current_bank + 0), a
	ld	(#_rROMB0),a
	C$Music.c$58$2_1$149	= .
	.globl	C$Music.c$58$2_1$149
;C:/ZGB-2023.0/common/src/Music.c:58: hUGE_init(hUGE_current_track);
	push	bc
	ld	hl, #_hUGE_current_track
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	_hUGE_init
	pop	bc
	C$Music.c$59$2_1$149	= .
	.globl	C$Music.c$59$2_1$149
;C:/ZGB-2023.0/common/src/Music.c:59: SWITCH_ROM_MBC1(__save);
	ld	a, c
	ldh	(__current_bank + 0), a
	ld	hl, #_rROMB0
	ld	(hl), c
	C$Music.c$60$2_1$149	= .
	.globl	C$Music.c$60$2_1$149
;C:/ZGB-2023.0/common/src/Music.c:60: hUGE_paused = 0;
	ld	hl, #_hUGE_paused
	ld	(hl), #0x00
00103$:
	C$Music.c$63$1_0$147	= .
	.globl	C$Music.c$63$1_0$147
;C:/ZGB-2023.0/common/src/Music.c:63: }
	pop	hl
	inc	sp
	jp	(hl)
	.area _CODE
	.area _INITIALIZER
FMusic$__xinit_hUGE_paused$0_0$0 == .
__xinit__hUGE_paused:
	.db #0x01	;  1
FMusic$__xinit_last_music$0_0$0 == .
__xinit__last_music:
	.dw #0x0000
FMusic$__xinit_stop_music_on_new_state$0_0$0 == .
__xinit__stop_music_on_new_state:
	.db #0x01	; 1
	.area _CABS (ABS)
