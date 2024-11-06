;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module SpriteOrpheus
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _Destroy_SpriteOrpheus
	.globl _Update_SpriteOrpheus
	.globl _Start_SpriteOrpheus
	.globl b_e_change_state
	.globl _e_change_state
	.globl _CheckCollision
	.globl _TranslateSprite
	.globl _SetSpriteAnim
	.globl _countdown_verso
	.globl _countdown_step
	.globl _countdown
	.globl _orpheus_wait
	.globl _push_vy
	.globl _push_vx
	.globl _orpheus_state_before
	.globl _hit_frameskip_max
	.globl _hit_frameskip
	.globl _orpheus_hitted
	.globl _a_walk_counter_y
	.globl _a_walk_counter_x
	.globl _orpheus_hit_countdown
	.globl _orpheus_hp
	.globl _orpheus_hp_max
	.globl _orpheus_power_max
	.globl _new_state
	.globl _orpheus_info
	.globl _a_orpheus_hit_h
	.globl _a_orpheus_hit_up
	.globl _a_orpheus_hit_down
	.globl _a_orpheus_walk_h
	.globl _a_orpheus_walk_down
	.globl _a_orpheus_walk_up
	.globl _a_orpheus_idleh
	.globl _a_orpheus_idledown
	.globl _a_orpheus_idleup
	.globl ___bank_SpriteOrpheus
	.globl b_orpheus_recharge
	.globl _orpheus_recharge
	.globl b_orpheus_update_position
	.globl _orpheus_update_position
	.globl b_orhpeus_change_state
	.globl _orhpeus_change_state
	.globl b_orpheus_hit
	.globl _orpheus_hit
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
G$orpheus_info$0_0$0==.
_orpheus_info::
	.ds 2
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
G$new_state$0_0$0==.
_new_state::
	.ds 1
G$orpheus_power_max$0_0$0==.
_orpheus_power_max::
	.ds 1
G$orpheus_hp_max$0_0$0==.
_orpheus_hp_max::
	.ds 1
G$orpheus_hp$0_0$0==.
_orpheus_hp::
	.ds 1
G$orpheus_hit_countdown$0_0$0==.
_orpheus_hit_countdown::
	.ds 1
G$a_walk_counter_x$0_0$0==.
_a_walk_counter_x::
	.ds 1
G$a_walk_counter_y$0_0$0==.
_a_walk_counter_y::
	.ds 1
G$orpheus_hitted$0_0$0==.
_orpheus_hitted::
	.ds 1
G$hit_frameskip$0_0$0==.
_hit_frameskip::
	.ds 1
G$hit_frameskip_max$0_0$0==.
_hit_frameskip_max::
	.ds 1
G$orpheus_state_before$0_0$0==.
_orpheus_state_before::
	.ds 1
G$push_vx$0_0$0==.
_push_vx::
	.ds 1
G$push_vy$0_0$0==.
_push_vy::
	.ds 1
G$orpheus_wait$0_0$0==.
_orpheus_wait::
	.ds 1
G$countdown$0_0$0==.
_countdown::
	.ds 1
G$countdown_step$0_0$0==.
_countdown_step::
	.ds 1
G$countdown_verso$0_0$0==.
_countdown_verso::
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
	.area _CODE_255
	G$Start_SpriteOrpheus$0$0	= .
	.globl	G$Start_SpriteOrpheus$0$0
	C$SpriteOrpheus.c$62$0_0$181	= .
	.globl	C$SpriteOrpheus.c$62$0_0$181
;SpriteOrpheus.c:62: void START() {
;	---------------------------------
; Function Start_SpriteOrpheus
; ---------------------------------
_Start_SpriteOrpheus::
	C$SpriteOrpheus.c$63$1_0$181	= .
	.globl	C$SpriteOrpheus.c$63$1_0$181
;SpriteOrpheus.c:63: SetSpriteAnim(THIS, a_orpheus_idleup, 8u);
	ld	a, #0x08
	push	af
	inc	sp
	ld	bc, #_a_orpheus_idleup
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	_SetSpriteAnim
	C$SpriteOrpheus.c$64$1_0$181	= .
	.globl	C$SpriteOrpheus.c$64$1_0$181
;SpriteOrpheus.c:64: orpheus_info = (struct OrpheusInfo*) THIS->custom_data;
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	b, (hl)
	add	a, #0x1b
	ld	c, a
	ld	a, b
	adc	a, #0x00
	ld	hl, #_orpheus_info
	ld	(hl), c
	inc	hl
	C$SpriteOrpheus.c$65$1_0$181	= .
	.globl	C$SpriteOrpheus.c$65$1_0$181
;SpriteOrpheus.c:65: orpheus_info->vx = 0;
	ld	(hl-), a
	ld	a, (hl+)
	ld	c, a
	C$SpriteOrpheus.c$66$1_0$181	= .
	.globl	C$SpriteOrpheus.c$66$1_0$181
;SpriteOrpheus.c:66: orpheus_info->vy = 0;
	ld	a, (hl-)
	ld	b, a
	inc	bc
	inc	bc
	xor	a, a
	ld	(bc), a
	ld	a, (hl+)
	ld	c, a
	C$SpriteOrpheus.c$67$1_0$181	= .
	.globl	C$SpriteOrpheus.c$67$1_0$181
;SpriteOrpheus.c:67: orpheus_info->tile_collision = 0u;
	ld	a, (hl-)
	ld	b, a
	inc	bc
	inc	bc
	inc	bc
	xor	a, a
	ld	(bc), a
	ld	a, (hl+)
	ld	c, a
	C$SpriteOrpheus.c$68$1_0$181	= .
	.globl	C$SpriteOrpheus.c$68$1_0$181
;SpriteOrpheus.c:68: orpheus_info->ow_state = GENERIC_IDLE;
	ld	a, (hl-)
	ld	b, a
	inc	bc
	xor	a, a
	ld	(bc), a
	ld	a, (hl+)
	ld	c, a
	C$SpriteOrpheus.c$69$1_0$181	= .
	.globl	C$SpriteOrpheus.c$69$1_0$181
;SpriteOrpheus.c:69: orpheus_info->charming = 0;
	ld	a, (hl-)
	ld	b, a
	xor	a, a
	ld	(bc), a
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	inc	bc
	inc	bc
	inc	bc
	inc	bc
	xor	a, a
	ld	(bc), a
	C$SpriteOrpheus.c$70$1_0$181	= .
	.globl	C$SpriteOrpheus.c$70$1_0$181
;SpriteOrpheus.c:70: if(_cpu != CGB_TYPE){
	ld	a, (#__cpu)
	sub	a, #0x11
	jr	Z, 00102$
	C$SpriteOrpheus.c$71$2_0$182	= .
	.globl	C$SpriteOrpheus.c$71$2_0$182
;SpriteOrpheus.c:71: OBP1_REG = PAL_DEF(0, 0, 1, 3);
	ld	a, #0xd0
	ldh	(_OBP1_REG + 0), a
	C$SpriteOrpheus.c$64$1_0$181	= .
	.globl	C$SpriteOrpheus.c$64$1_0$181
;SpriteOrpheus.c:64: orpheus_info = (struct OrpheusInfo*) THIS->custom_data;
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	C$SpriteOrpheus.c$72$1_0$181	= .
	.globl	C$SpriteOrpheus.c$72$1_0$181
;SpriteOrpheus.c:72: SPRITE_SET_PALETTE(THIS,1);
	inc	bc
	inc	bc
	inc	bc
	inc	bc
	ld	a, (bc)
	res	4, a
	set	4, a
	ld	(bc), a
00102$:
	C$SpriteOrpheus.c$74$1_0$181	= .
	.globl	C$SpriteOrpheus.c$74$1_0$181
;SpriteOrpheus.c:74: orpheus_hitted = 0u;
	ld	hl, #_orpheus_hitted
	ld	(hl), #0x00
	C$SpriteOrpheus.c$75$1_0$181	= .
	.globl	C$SpriteOrpheus.c$75$1_0$181
;SpriteOrpheus.c:75: orpheus_hit_countdown = 0;
	ld	hl, #_orpheus_hit_countdown
	ld	(hl), #0x00
	C$SpriteOrpheus.c$76$1_0$181	= .
	.globl	C$SpriteOrpheus.c$76$1_0$181
;SpriteOrpheus.c:76: a_walk_counter_x = 0;
	ld	hl, #_a_walk_counter_x
	ld	(hl), #0x00
	C$SpriteOrpheus.c$77$1_0$181	= .
	.globl	C$SpriteOrpheus.c$77$1_0$181
;SpriteOrpheus.c:77: a_walk_counter_y = 0;
	ld	hl, #_a_walk_counter_y
	ld	(hl), #0x00
	C$SpriteOrpheus.c$78$1_0$181	= .
	.globl	C$SpriteOrpheus.c$78$1_0$181
;SpriteOrpheus.c:78: hit_frameskip = 0;
	ld	hl, #_hit_frameskip
	ld	(hl), #0x00
	C$SpriteOrpheus.c$79$1_0$181	= .
	.globl	C$SpriteOrpheus.c$79$1_0$181
;SpriteOrpheus.c:79: hit_frameskip_max = 0;
	ld	hl, #_hit_frameskip_max
	ld	(hl), #0x00
	C$SpriteOrpheus.c$80$1_0$181	= .
	.globl	C$SpriteOrpheus.c$80$1_0$181
;SpriteOrpheus.c:80: orpheus_wait = 0u;
	ld	hl, #_orpheus_wait
	ld	(hl), #0x00
	C$SpriteOrpheus.c$81$1_0$181	= .
	.globl	C$SpriteOrpheus.c$81$1_0$181
;SpriteOrpheus.c:81: countdown_step = COUNTDOWN_STEP_MAX;
	ld	hl, #_countdown_step
	ld	(hl), #0x01
	C$SpriteOrpheus.c$82$1_0$181	= .
	.globl	C$SpriteOrpheus.c$82$1_0$181
;SpriteOrpheus.c:82: orpheus_power_max = POWER_MAX;
	ld	hl, #_orpheus_power_max
	ld	(hl), #0x28
	C$SpriteOrpheus.c$83$1_0$181	= .
	.globl	C$SpriteOrpheus.c$83$1_0$181
;SpriteOrpheus.c:83: countdown = orpheus_power_max;
	ld	hl, #_countdown
	ld	(hl), #0x28
	C$SpriteOrpheus.c$84$1_0$181	= .
	.globl	C$SpriteOrpheus.c$84$1_0$181
;SpriteOrpheus.c:84: countdown_verso = 0;
	ld	hl, #_countdown_verso
	ld	(hl), #0x00
	C$SpriteOrpheus.c$85$1_0$181	= .
	.globl	C$SpriteOrpheus.c$85$1_0$181
;SpriteOrpheus.c:85: }
	C$SpriteOrpheus.c$85$1_0$181	= .
	.globl	C$SpriteOrpheus.c$85$1_0$181
	XG$Start_SpriteOrpheus$0$0	= .
	.globl	XG$Start_SpriteOrpheus$0$0
	ret
G$__bank_SpriteOrpheus$0_0$0 == 0x00ff
___bank_SpriteOrpheus	=	0x00ff
G$a_orpheus_idleup$0_0$0 == .
_a_orpheus_idleup:
	.db #0x01	; 1
	.db #0x05	; 5
G$a_orpheus_idledown$0_0$0 == .
_a_orpheus_idledown:
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x03	; 3
G$a_orpheus_idleh$0_0$0 == .
_a_orpheus_idleh:
	.db #0x04	; 4
	.db #0x0a	; 10
	.db #0x0a	; 10
	.db #0x0a	; 10
	.db #0x09	; 9
G$a_orpheus_walk_up$0_0$0 == .
_a_orpheus_walk_up:
	.db #0x02	; 2
	.db #0x05	; 5
	.db #0x06	; 6
G$a_orpheus_walk_down$0_0$0 == .
_a_orpheus_walk_down:
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x03	; 3
G$a_orpheus_walk_h$0_0$0 == .
_a_orpheus_walk_h:
	.db #0x04	; 4
	.db #0x09	; 9
	.db #0x0a	; 10
	.db #0x09	; 9
	.db #0x08	; 8
G$a_orpheus_hit_down$0_0$0 == .
_a_orpheus_hit_down:
	.db #0x02	; 2
	.db #0x00	; 0
	.db #0x02	; 2
G$a_orpheus_hit_up$0_0$0 == .
_a_orpheus_hit_up:
	.db #0x02	; 2
	.db #0x00	; 0
	.db #0x05	; 5
G$a_orpheus_hit_h$0_0$0 == .
_a_orpheus_hit_h:
	.db #0x02	; 2
	.db #0x00	; 0
	.db #0x09	; 9
	G$Update_SpriteOrpheus$0$0	= .
	.globl	G$Update_SpriteOrpheus$0$0
	C$SpriteOrpheus.c$87$1_0$183	= .
	.globl	C$SpriteOrpheus.c$87$1_0$183
;SpriteOrpheus.c:87: void UPDATE() {
;	---------------------------------
; Function Update_SpriteOrpheus
; ---------------------------------
_Update_SpriteOrpheus::
	add	sp, #-9
	C$SpriteOrpheus.c$89$1_0$183	= .
	.globl	C$SpriteOrpheus.c$89$1_0$183
;SpriteOrpheus.c:89: if(a_walk_counter_y < 0){
	ld	hl, #_a_walk_counter_y
	bit	7, (hl)
	jr	Z, 00118$
	C$SpriteOrpheus.c$90$2_0$184	= .
	.globl	C$SpriteOrpheus.c$90$2_0$184
;SpriteOrpheus.c:90: a_walk_counter_y++;
	inc	(hl)
	C$SpriteOrpheus.c$91$2_0$184	= .
	.globl	C$SpriteOrpheus.c$91$2_0$184
;SpriteOrpheus.c:91: orhpeus_change_state(WALK_UP);
	ld	a, #0x08
	push	af
	inc	sp
	ld	e, #b_orhpeus_change_state
	ld	hl, #_orhpeus_change_state
	call	___sdcc_bcall_ehl
	inc	sp
	C$SpriteOrpheus.c$92$2_0$184	= .
	.globl	C$SpriteOrpheus.c$92$2_0$184
;SpriteOrpheus.c:92: if(a_walk_counter_y == 0){
	ld	a, (#_a_walk_counter_y)
	or	a, a
	jr	NZ, 00102$
	C$SpriteOrpheus.c$93$3_0$185	= .
	.globl	C$SpriteOrpheus.c$93$3_0$185
;SpriteOrpheus.c:93: orhpeus_change_state(IDLE_UP);    
	ld	a, #0x02
	push	af
	inc	sp
	ld	e, #b_orhpeus_change_state
	ld	hl, #_orhpeus_change_state
	call	___sdcc_bcall_ehl
	inc	sp
00102$:
	C$SpriteOrpheus.c$95$2_0$184	= .
	.globl	C$SpriteOrpheus.c$95$2_0$184
;SpriteOrpheus.c:95: orpheus_update_position();
	ld	e, #b_orpheus_update_position
	ld	hl, #_orpheus_update_position
	call	___sdcc_bcall_ehl
	C$SpriteOrpheus.c$96$2_0$184	= .
	.globl	C$SpriteOrpheus.c$96$2_0$184
;SpriteOrpheus.c:96: return;
	jp	00226$
00118$:
	C$SpriteOrpheus.c$97$1_0$183	= .
	.globl	C$SpriteOrpheus.c$97$1_0$183
;SpriteOrpheus.c:97: }else if(a_walk_counter_y > 0){
	ld	hl, #_a_walk_counter_y
	ld	e, (hl)
	xor	a, a
	ld	d, a
	sub	a, (hl)
	bit	7, e
	jr	Z, 00565$
	bit	7, d
	jr	NZ, 00566$
	cp	a, a
	jr	00566$
00565$:
	bit	7, d
	jr	Z, 00566$
	scf
00566$:
	jr	NC, 00115$
	C$SpriteOrpheus.c$98$2_0$186	= .
	.globl	C$SpriteOrpheus.c$98$2_0$186
;SpriteOrpheus.c:98: a_walk_counter_y--;
	ld	hl, #_a_walk_counter_y
	dec	(hl)
	C$SpriteOrpheus.c$99$2_0$186	= .
	.globl	C$SpriteOrpheus.c$99$2_0$186
;SpriteOrpheus.c:99: orhpeus_change_state(WALK_DOWN);
	ld	a, #0x09
	push	af
	inc	sp
	ld	e, #b_orhpeus_change_state
	ld	hl, #_orhpeus_change_state
	call	___sdcc_bcall_ehl
	inc	sp
	C$SpriteOrpheus.c$100$2_0$186	= .
	.globl	C$SpriteOrpheus.c$100$2_0$186
;SpriteOrpheus.c:100: if(a_walk_counter_y == 0){
	ld	a, (#_a_walk_counter_y)
	or	a, a
	jr	NZ, 00104$
	C$SpriteOrpheus.c$101$3_0$187	= .
	.globl	C$SpriteOrpheus.c$101$3_0$187
;SpriteOrpheus.c:101: orhpeus_change_state(IDLE_DOWN);    
	ld	a, #0x03
	push	af
	inc	sp
	ld	e, #b_orhpeus_change_state
	ld	hl, #_orhpeus_change_state
	call	___sdcc_bcall_ehl
	inc	sp
00104$:
	C$SpriteOrpheus.c$103$2_0$186	= .
	.globl	C$SpriteOrpheus.c$103$2_0$186
;SpriteOrpheus.c:103: orpheus_update_position();
	ld	e, #b_orpheus_update_position
	ld	hl, #_orpheus_update_position
	call	___sdcc_bcall_ehl
	C$SpriteOrpheus.c$104$2_0$186	= .
	.globl	C$SpriteOrpheus.c$104$2_0$186
;SpriteOrpheus.c:104: return;
	jp	00226$
00115$:
	C$SpriteOrpheus.c$105$1_0$183	= .
	.globl	C$SpriteOrpheus.c$105$1_0$183
;SpriteOrpheus.c:105: }else if(a_walk_counter_x < 0){
	ld	hl, #_a_walk_counter_x
	bit	7, (hl)
	jr	Z, 00112$
	C$SpriteOrpheus.c$106$2_0$188	= .
	.globl	C$SpriteOrpheus.c$106$2_0$188
;SpriteOrpheus.c:106: a_walk_counter_x++;
	inc	(hl)
	C$SpriteOrpheus.c$107$2_0$188	= .
	.globl	C$SpriteOrpheus.c$107$2_0$188
;SpriteOrpheus.c:107: orhpeus_change_state(WALK_LEFT);
	ld	a, #0x06
	push	af
	inc	sp
	ld	e, #b_orhpeus_change_state
	ld	hl, #_orhpeus_change_state
	call	___sdcc_bcall_ehl
	inc	sp
	C$SpriteOrpheus.c$108$2_0$188	= .
	.globl	C$SpriteOrpheus.c$108$2_0$188
;SpriteOrpheus.c:108: if(a_walk_counter_x == 0){
	ld	a, (#_a_walk_counter_x)
	or	a, a
	jr	NZ, 00106$
	C$SpriteOrpheus.c$109$3_0$189	= .
	.globl	C$SpriteOrpheus.c$109$3_0$189
;SpriteOrpheus.c:109: orhpeus_change_state(IDLE_LEFT);    
	ld	a, #0x04
	push	af
	inc	sp
	ld	e, #b_orhpeus_change_state
	ld	hl, #_orhpeus_change_state
	call	___sdcc_bcall_ehl
	inc	sp
00106$:
	C$SpriteOrpheus.c$111$2_0$188	= .
	.globl	C$SpriteOrpheus.c$111$2_0$188
;SpriteOrpheus.c:111: orpheus_update_position();
	ld	e, #b_orpheus_update_position
	ld	hl, #_orpheus_update_position
	call	___sdcc_bcall_ehl
	C$SpriteOrpheus.c$112$2_0$188	= .
	.globl	C$SpriteOrpheus.c$112$2_0$188
;SpriteOrpheus.c:112: return;
	jp	00226$
00112$:
	C$SpriteOrpheus.c$113$1_0$183	= .
	.globl	C$SpriteOrpheus.c$113$1_0$183
;SpriteOrpheus.c:113: }else if(a_walk_counter_x > 0){
	ld	hl, #_a_walk_counter_x
	ld	e, (hl)
	xor	a, a
	ld	d, a
	sub	a, (hl)
	bit	7, e
	jr	Z, 00567$
	bit	7, d
	jr	NZ, 00568$
	cp	a, a
	jr	00568$
00567$:
	bit	7, d
	jr	Z, 00568$
	scf
00568$:
	jr	NC, 00116$
	C$SpriteOrpheus.c$114$2_0$190	= .
	.globl	C$SpriteOrpheus.c$114$2_0$190
;SpriteOrpheus.c:114: a_walk_counter_x--;
	ld	hl, #_a_walk_counter_x
	dec	(hl)
	C$SpriteOrpheus.c$115$2_0$190	= .
	.globl	C$SpriteOrpheus.c$115$2_0$190
;SpriteOrpheus.c:115: orhpeus_change_state(WALK_RIGHT);
	ld	a, #0x07
	push	af
	inc	sp
	ld	e, #b_orhpeus_change_state
	ld	hl, #_orhpeus_change_state
	call	___sdcc_bcall_ehl
	inc	sp
	C$SpriteOrpheus.c$116$2_0$190	= .
	.globl	C$SpriteOrpheus.c$116$2_0$190
;SpriteOrpheus.c:116: if(a_walk_counter_x == 0){
	ld	a, (#_a_walk_counter_x)
	or	a, a
	jr	NZ, 00108$
	C$SpriteOrpheus.c$117$3_0$191	= .
	.globl	C$SpriteOrpheus.c$117$3_0$191
;SpriteOrpheus.c:117: orhpeus_change_state(IDLE_RIGHT);    
	ld	a, #0x05
	push	af
	inc	sp
	ld	e, #b_orhpeus_change_state
	ld	hl, #_orhpeus_change_state
	call	___sdcc_bcall_ehl
	inc	sp
00108$:
	C$SpriteOrpheus.c$119$2_0$190	= .
	.globl	C$SpriteOrpheus.c$119$2_0$190
;SpriteOrpheus.c:119: orpheus_update_position();
	ld	e, #b_orpheus_update_position
	ld	hl, #_orpheus_update_position
	call	___sdcc_bcall_ehl
	C$SpriteOrpheus.c$120$2_0$190	= .
	.globl	C$SpriteOrpheus.c$120$2_0$190
;SpriteOrpheus.c:120: return;
	jp	00226$
00116$:
	C$SpriteOrpheus.c$122$1_0$183	= .
	.globl	C$SpriteOrpheus.c$122$1_0$183
;SpriteOrpheus.c:122: if(move_camera_up || move_camera_down  
	ld	a, (#_move_camera_up)
	or	a, a
	jp	NZ,00226$
	ld	a, (#_move_camera_down)
	or	a, a
	jp	NZ,00226$
	C$SpriteOrpheus.c$123$1_0$183	= .
	.globl	C$SpriteOrpheus.c$123$1_0$183
;SpriteOrpheus.c:123: || move_camera_left || move_camera_right){
	ld	a, (#_move_camera_left)
	or	a, a
	jp	NZ,00226$
	ld	a, (#_move_camera_right)
	or	a, a
	C$SpriteOrpheus.c$124$2_0$192	= .
	.globl	C$SpriteOrpheus.c$124$2_0$192
;SpriteOrpheus.c:124: return;
	jp	NZ,00226$
	C$SpriteOrpheus.c$127$2_1$183	= .
	.globl	C$SpriteOrpheus.c$127$2_1$183
;SpriteOrpheus.c:127: new_state = orpheus_info->ow_state;
	ld	hl, #_orpheus_info
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	a, (bc)
	ld	(#_new_state),a
	ld	a, (bc)
	ldhl	sp,	#6
	ld	(hl), a
	C$SpriteOrpheus.c$129$2_1$183	= .
	.globl	C$SpriteOrpheus.c$129$2_1$183
;SpriteOrpheus.c:129: if(KEY_PRESSED(J_DOWN)){new_state = WALK_DOWN;}
	ld	a, (#_keys)
	ldhl	sp,	#7
	ld	(hl), a
	C$SpriteOrpheus.c$133$2_1$183	= .
	.globl	C$SpriteOrpheus.c$133$2_1$183
;SpriteOrpheus.c:133: else if(KEY_RELEASED(J_DOWN)){new_state = IDLE_DOWN;}
	ld	a, (#_previous_keys)
	ldhl	sp,	#8
	C$SpriteOrpheus.c$128$1_0$183	= .
	.globl	C$SpriteOrpheus.c$128$1_0$183
;SpriteOrpheus.c:128: if((orpheus_info->ow_state != HIT || orpheus_hit_countdown < 10) && orpheus_info->ow_state != ATTACK){
	ld	(hl-), a
	dec	hl
	ld	a, (hl)
	sub	a, #0x0c
	jr	NZ, 00155$
	ld	hl, #_orpheus_hit_countdown
	ld	a, (hl)
	xor	a, #0x80
	sub	a, #0x8a
	jp	NC, 00153$
00155$:
	ldhl	sp,	#6
	ld	a, (hl)
	sub	a, #0x0b
	jp	Z,00153$
	C$SpriteOrpheus.c$129$2_1$183	= .
	.globl	C$SpriteOrpheus.c$129$2_1$183
;SpriteOrpheus.c:129: if(KEY_PRESSED(J_DOWN)){new_state = WALK_DOWN;}
	ldhl	sp,	#7
	ld	a, (hl)
	and	a, #0x08
	ld	d, a
	or	a, a
	jr	Z, 00150$
	ld	hl, #_new_state
	ld	(hl), #0x09
	jr	00153$
00150$:
	C$SpriteOrpheus.c$130$2_1$183	= .
	.globl	C$SpriteOrpheus.c$130$2_1$183
;SpriteOrpheus.c:130: else if(KEY_PRESSED(J_UP)){new_state = WALK_UP;}
	ldhl	sp,	#7
	ld	a, (hl)
	and	a, #0x04
	ld	e, a
	or	a, a
	jr	Z, 00147$
	ld	hl, #_new_state
	ld	(hl), #0x08
	jr	00153$
00147$:
	C$SpriteOrpheus.c$131$2_1$183	= .
	.globl	C$SpriteOrpheus.c$131$2_1$183
;SpriteOrpheus.c:131: else if(KEY_PRESSED(J_LEFT)){new_state = WALK_LEFT;}
	ldhl	sp,	#7
	ld	a, (hl)
	and	a, #0x02
;	spillPairReg hl
;	spillPairReg hl
	ld	h, a
	or	a, a
	jr	Z, 00144$
	ld	hl, #_new_state
	ld	(hl), #0x06
	jr	00153$
00144$:
	C$SpriteOrpheus.c$132$2_1$183	= .
	.globl	C$SpriteOrpheus.c$132$2_1$183
;SpriteOrpheus.c:132: else if(KEY_PRESSED(J_RIGHT)){new_state = WALK_RIGHT;}
	push	hl
	ldhl	sp,	#9
	ld	a, (hl)
	pop	hl
	and	a, #0x01
;	spillPairReg hl
;	spillPairReg hl
	ld	l, a
	or	a, a
	jr	Z, 00141$
	ld	hl, #_new_state
	ld	(hl), #0x07
	jr	00153$
00141$:
	C$SpriteOrpheus.c$133$2_0$193	= .
	.globl	C$SpriteOrpheus.c$133$2_0$193
;SpriteOrpheus.c:133: else if(KEY_RELEASED(J_DOWN)){new_state = IDLE_DOWN;}
	push	hl
	ldhl	sp,	#10
	bit	3, (hl)
	pop	hl
	jr	Z, 00137$
	ld	a, d
	or	a, a
	jr	NZ, 00137$
	ld	hl, #_new_state
	ld	(hl), #0x03
	jr	00153$
00137$:
	C$SpriteOrpheus.c$134$2_0$193	= .
	.globl	C$SpriteOrpheus.c$134$2_0$193
;SpriteOrpheus.c:134: else if(KEY_RELEASED(J_UP)){new_state = IDLE_UP;}
	push	hl
	ldhl	sp,	#10
	bit	2, (hl)
	pop	hl
	jr	Z, 00133$
	ld	a, e
	or	a, a
	jr	NZ, 00133$
	ld	hl, #_new_state
	ld	(hl), #0x02
	jr	00153$
00133$:
	C$SpriteOrpheus.c$135$2_0$193	= .
	.globl	C$SpriteOrpheus.c$135$2_0$193
;SpriteOrpheus.c:135: else if(KEY_RELEASED(J_LEFT)){new_state = IDLE_LEFT;}
	push	hl
	ldhl	sp,	#10
	bit	1, (hl)
	pop	hl
	jr	Z, 00129$
	ld	a, h
	or	a, a
	jr	NZ, 00129$
	ld	hl, #_new_state
	ld	(hl), #0x04
	jr	00153$
00129$:
	C$SpriteOrpheus.c$136$2_0$193	= .
	.globl	C$SpriteOrpheus.c$136$2_0$193
;SpriteOrpheus.c:136: else if(KEY_RELEASED(J_RIGHT)){new_state = IDLE_RIGHT;}
	push	hl
	ldhl	sp,	#10
	bit	0, (hl)
	pop	hl
	jr	Z, 00153$
	ld	a, l
	or	a, a
	jr	NZ, 00153$
	ld	hl, #_new_state
	ld	(hl), #0x05
00153$:
	C$SpriteOrpheus.c$127$2_1$183	= .
	.globl	C$SpriteOrpheus.c$127$2_1$183
;SpriteOrpheus.c:127: new_state = orpheus_info->ow_state;
	ld	a, (bc)
	C$SpriteOrpheus.c$139$1_0$183	= .
	.globl	C$SpriteOrpheus.c$139$1_0$183
;SpriteOrpheus.c:139: if(orpheus_info->ow_state != HIT && orpheus_info->ow_state != ATTACK){
	cp	a, #0x0c
	jr	Z, 00160$
	cp	a, #0x0b
	jr	Z, 00160$
	C$SpriteOrpheus.c$140$2_0$202	= .
	.globl	C$SpriteOrpheus.c$140$2_0$202
;SpriteOrpheus.c:140: if (KEY_TICKED(J_B)) { //countdown == orpheus_power_max && ){
	push	hl
	ldhl	sp,	#9
	bit	5, (hl)
	pop	hl
	jr	Z, 00160$
	push	hl
	ldhl	sp,	#10
	bit	5, (hl)
	pop	hl
	jr	NZ, 00160$
	C$SpriteOrpheus.c$141$3_0$203	= .
	.globl	C$SpriteOrpheus.c$141$3_0$203
;SpriteOrpheus.c:141: orpheus_state_before = orpheus_info->ow_state;
	ld	(#_orpheus_state_before),a
	C$SpriteOrpheus.c$142$3_0$203	= .
	.globl	C$SpriteOrpheus.c$142$3_0$203
;SpriteOrpheus.c:142: new_state = ATTACK;
	ld	hl, #_new_state
	ld	(hl), #0x0b
00160$:
	C$SpriteOrpheus.c$145$1_0$183	= .
	.globl	C$SpriteOrpheus.c$145$1_0$183
;SpriteOrpheus.c:145: orhpeus_change_state(new_state);
	ld	a, (#_new_state)
	push	af
	inc	sp
	ld	e, #b_orhpeus_change_state
	ld	hl, #_orhpeus_change_state
	call	___sdcc_bcall_ehl
	inc	sp
	C$SpriteOrpheus.c$147$1_0$183	= .
	.globl	C$SpriteOrpheus.c$147$1_0$183
;SpriteOrpheus.c:147: switch(new_state){
	ld	a, #0x0c
	ld	hl, #_new_state
	sub	a, (hl)
	jp	C, 00205$
	ld	c, (hl)
	ld	b, #0x00
	ld	hl, #00581$
	add	hl, bc
	add	hl, bc
	add	hl, bc
	jp	(hl)
00581$:
	jp	00205$
	jp	00205$
	jp	00165$
	jp	00165$
	jp	00165$
	jp	00165$
	jp	00169$
	jp	00169$
	jp	00169$
	jp	00169$
	jp	00205$
	jp	00202$
	jp	00170$
	C$SpriteOrpheus.c$148$2_0$204	= .
	.globl	C$SpriteOrpheus.c$148$2_0$204
;SpriteOrpheus.c:148: case IDLE_DOWN: case IDLE_LEFT: case IDLE_RIGHT: case IDLE_UP:
00165$:
	C$SpriteOrpheus.c$149$2_0$204	= .
	.globl	C$SpriteOrpheus.c$149$2_0$204
;SpriteOrpheus.c:149: orpheus_recharge();
	ld	e, #b_orpheus_recharge
	ld	hl, #_orpheus_recharge
	call	___sdcc_bcall_ehl
	C$SpriteOrpheus.c$150$2_0$204	= .
	.globl	C$SpriteOrpheus.c$150$2_0$204
;SpriteOrpheus.c:150: break;
	jp	00205$
	C$SpriteOrpheus.c$152$2_0$204	= .
	.globl	C$SpriteOrpheus.c$152$2_0$204
;SpriteOrpheus.c:152: case WALK_LEFT: case WALK_RIGHT:
00169$:
	C$SpriteOrpheus.c$153$2_0$204	= .
	.globl	C$SpriteOrpheus.c$153$2_0$204
;SpriteOrpheus.c:153: orpheus_update_position();
	ld	e, #b_orpheus_update_position
	ld	hl, #_orpheus_update_position
	call	___sdcc_bcall_ehl
	C$SpriteOrpheus.c$154$2_0$204	= .
	.globl	C$SpriteOrpheus.c$154$2_0$204
;SpriteOrpheus.c:154: break;
	jp	00205$
	C$SpriteOrpheus.c$155$2_0$204	= .
	.globl	C$SpriteOrpheus.c$155$2_0$204
;SpriteOrpheus.c:155: case HIT:
00170$:
	C$SpriteOrpheus.c$156$2_0$204	= .
	.globl	C$SpriteOrpheus.c$156$2_0$204
;SpriteOrpheus.c:156: hit_frameskip--;
	ld	hl, #_hit_frameskip
	C$SpriteOrpheus.c$157$2_0$204	= .
	.globl	C$SpriteOrpheus.c$157$2_0$204
;SpriteOrpheus.c:157: if(hit_frameskip == 0){
	dec	(hl)
	jp	NZ, 00185$
	C$SpriteOrpheus.c$158$3_0$205	= .
	.globl	C$SpriteOrpheus.c$158$3_0$205
;SpriteOrpheus.c:158: hit_frameskip_max++;
	ld	hl, #_hit_frameskip_max
	inc	(hl)
	C$SpriteOrpheus.c$159$3_0$205	= .
	.globl	C$SpriteOrpheus.c$159$3_0$205
;SpriteOrpheus.c:159: hit_frameskip = hit_frameskip_max;
	ld	a, (hl)
	ld	(#_hit_frameskip),a
	C$SpriteOrpheus.c$127$2_1$183	= .
	.globl	C$SpriteOrpheus.c$127$2_1$183
;SpriteOrpheus.c:127: new_state = orpheus_info->ow_state;
	ld	hl, #_orpheus_info
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	C$SpriteOrpheus.c$160$3_0$205	= .
	.globl	C$SpriteOrpheus.c$160$3_0$205
;SpriteOrpheus.c:160: if(push_vx != 0 || push_vy != 0){
	ld	a, (#_push_vx)
	or	a, a
	jr	NZ, 00180$
	ld	a, (#_push_vy)
	or	a, a
	jr	Z, 00181$
00180$:
	C$SpriteOrpheus.c$161$4_0$206	= .
	.globl	C$SpriteOrpheus.c$161$4_0$206
;SpriteOrpheus.c:161: orpheus_info->vx = push_vx;
	inc	bc
	inc	bc
	ld	a, (#_push_vx)
	ld	(bc), a
	C$SpriteOrpheus.c$162$4_0$206	= .
	.globl	C$SpriteOrpheus.c$162$4_0$206
;SpriteOrpheus.c:162: orpheus_info->vy = push_vy;
	ld	hl, #_orpheus_info
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	inc	bc
	inc	bc
	inc	bc
	ld	a, (#_push_vy)
	ld	(bc), a
	jr	00182$
00181$:
	C$SpriteOrpheus.c$164$4_0$207	= .
	.globl	C$SpriteOrpheus.c$164$4_0$207
;SpriteOrpheus.c:164: switch(orpheus_state_before){
	ld	a, #0x09
	ld	hl, #_orpheus_state_before
	sub	a, (hl)
	jr	C, 00182$
	C$SpriteOrpheus.c$166$2_1$183	= .
	.globl	C$SpriteOrpheus.c$166$2_1$183
;SpriteOrpheus.c:166: orpheus_info->vy = -1;
	inc	bc
	inc	bc
	inc	bc
	C$SpriteOrpheus.c$164$4_0$207	= .
	.globl	C$SpriteOrpheus.c$164$4_0$207
;SpriteOrpheus.c:164: switch(orpheus_state_before){
	ld	e, (hl)
	ld	d, #0x00
	ld	hl, #00582$
	add	hl, de
	add	hl, de
	add	hl, de
	jp	(hl)
00582$:
	jp	00182$
	jp	00182$
	jp	00174$
	jp	00172$
	jp	00176$
	jp	00178$
	jp	00176$
	jp	00178$
	jp	00174$
	jp	00172$
	C$SpriteOrpheus.c$165$5_0$208	= .
	.globl	C$SpriteOrpheus.c$165$5_0$208
;SpriteOrpheus.c:165: case WALK_DOWN: case IDLE_DOWN:
00172$:
	C$SpriteOrpheus.c$166$5_0$208	= .
	.globl	C$SpriteOrpheus.c$166$5_0$208
;SpriteOrpheus.c:166: orpheus_info->vy = -1;
	ld	a, #0xff
	ld	(bc), a
	C$SpriteOrpheus.c$167$5_0$208	= .
	.globl	C$SpriteOrpheus.c$167$5_0$208
;SpriteOrpheus.c:167: orpheus_info->vx = 0;
	ld	hl, #_orpheus_info
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	inc	bc
	inc	bc
	xor	a, a
	ld	(bc), a
	C$SpriteOrpheus.c$168$5_0$208	= .
	.globl	C$SpriteOrpheus.c$168$5_0$208
;SpriteOrpheus.c:168: break;
	jr	00182$
	C$SpriteOrpheus.c$169$5_0$208	= .
	.globl	C$SpriteOrpheus.c$169$5_0$208
;SpriteOrpheus.c:169: case WALK_UP: case IDLE_UP:
00174$:
	C$SpriteOrpheus.c$170$5_0$208	= .
	.globl	C$SpriteOrpheus.c$170$5_0$208
;SpriteOrpheus.c:170: orpheus_info->vy = 1;
	ld	a, #0x01
	ld	(bc), a
	C$SpriteOrpheus.c$171$5_0$208	= .
	.globl	C$SpriteOrpheus.c$171$5_0$208
;SpriteOrpheus.c:171: orpheus_info->vx = 0;
	ld	hl, #_orpheus_info
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	inc	bc
	inc	bc
	xor	a, a
	ld	(bc), a
	C$SpriteOrpheus.c$172$5_0$208	= .
	.globl	C$SpriteOrpheus.c$172$5_0$208
;SpriteOrpheus.c:172: break;
	jr	00182$
	C$SpriteOrpheus.c$173$5_0$208	= .
	.globl	C$SpriteOrpheus.c$173$5_0$208
;SpriteOrpheus.c:173: case WALK_LEFT: case IDLE_LEFT:
00176$:
	C$SpriteOrpheus.c$174$5_0$208	= .
	.globl	C$SpriteOrpheus.c$174$5_0$208
;SpriteOrpheus.c:174: orpheus_info->vy = 0;
	xor	a, a
	ld	(bc), a
	C$SpriteOrpheus.c$175$5_0$208	= .
	.globl	C$SpriteOrpheus.c$175$5_0$208
;SpriteOrpheus.c:175: orpheus_info->vx = 1;
	ld	hl, #_orpheus_info
	ld	l, (hl)
;	spillPairReg hl
;	spillPairReg hl
	ld	a, (_orpheus_info + 1)
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	inc	hl
	inc	hl
	ld	(hl), #0x01
	C$SpriteOrpheus.c$176$5_0$208	= .
	.globl	C$SpriteOrpheus.c$176$5_0$208
;SpriteOrpheus.c:176: break;
	jr	00182$
	C$SpriteOrpheus.c$177$5_0$208	= .
	.globl	C$SpriteOrpheus.c$177$5_0$208
;SpriteOrpheus.c:177: case WALK_RIGHT: case IDLE_RIGHT:
00178$:
	C$SpriteOrpheus.c$178$5_0$208	= .
	.globl	C$SpriteOrpheus.c$178$5_0$208
;SpriteOrpheus.c:178: orpheus_info->vy = 0;
	xor	a, a
	ld	(bc), a
	C$SpriteOrpheus.c$179$5_0$208	= .
	.globl	C$SpriteOrpheus.c$179$5_0$208
;SpriteOrpheus.c:179: orpheus_info->vx = -1;
	ld	hl, #_orpheus_info
	ld	l, (hl)
;	spillPairReg hl
;	spillPairReg hl
	ld	a, (_orpheus_info + 1)
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	inc	hl
	inc	hl
	ld	(hl), #0xff
	C$SpriteOrpheus.c$181$3_0$205	= .
	.globl	C$SpriteOrpheus.c$181$3_0$205
;SpriteOrpheus.c:181: }
00182$:
	C$SpriteOrpheus.c$183$3_0$205	= .
	.globl	C$SpriteOrpheus.c$183$3_0$205
;SpriteOrpheus.c:183: orpheus_update_position();
	ld	e, #b_orpheus_update_position
	ld	hl, #_orpheus_update_position
	call	___sdcc_bcall_ehl
00185$:
	C$SpriteOrpheus.c$185$2_1$183	= .
	.globl	C$SpriteOrpheus.c$185$2_1$183
;SpriteOrpheus.c:185: if(orpheus_hit_countdown > 0){//going backwards
	ld	hl, #_orpheus_hit_countdown
	ld	e, (hl)
	xor	a, a
	ld	d, a
	sub	a, (hl)
	bit	7, e
	jr	Z, 00583$
	bit	7, d
	jr	NZ, 00584$
	cp	a, a
	jr	00584$
00583$:
	bit	7, d
	jr	Z, 00584$
	scf
00584$:
	ld	a, #0x00
	rla
	or	a, a
	jr	Z, 00200$
	C$SpriteOrpheus.c$186$3_0$209	= .
	.globl	C$SpriteOrpheus.c$186$3_0$209
;SpriteOrpheus.c:186: orpheus_hit_countdown--;
	ld	hl, #_orpheus_hit_countdown
	dec	(hl)
	jp	00205$
00200$:
	C$SpriteOrpheus.c$187$2_0$204	= .
	.globl	C$SpriteOrpheus.c$187$2_0$204
;SpriteOrpheus.c:187: }else if(orpheus_hit_countdown <= 0){//hit effect ends
	ld	c, a
	bit	0, c
	jp	NZ, 00205$
	C$SpriteOrpheus.c$189$3_0$210	= .
	.globl	C$SpriteOrpheus.c$189$3_0$210
;SpriteOrpheus.c:189: orpheus_hit_countdown = 0;
	ld	hl, #_orpheus_hit_countdown
	ld	(hl), #0x00
	C$SpriteOrpheus.c$190$3_0$210	= .
	.globl	C$SpriteOrpheus.c$190$3_0$210
;SpriteOrpheus.c:190: orpheus_hitted = 0u;
	ld	hl, #_orpheus_hitted
	ld	(hl), #0x00
	C$SpriteOrpheus.c$191$3_0$210	= .
	.globl	C$SpriteOrpheus.c$191$3_0$210
;SpriteOrpheus.c:191: push_vx = 0;
	ld	hl, #_push_vx
	ld	(hl), #0x00
	C$SpriteOrpheus.c$192$3_0$210	= .
	.globl	C$SpriteOrpheus.c$192$3_0$210
;SpriteOrpheus.c:192: push_vy = 0;
	ld	hl, #_push_vy
	ld	(hl), #0x00
	C$SpriteOrpheus.c$193$3_0$210	= .
	.globl	C$SpriteOrpheus.c$193$3_0$210
;SpriteOrpheus.c:193: switch(orpheus_state_before){
	ld	a, #0x09
	ld	hl, #_orpheus_state_before
	sub	a, (hl)
	jp	C, 00205$
	ld	c, (hl)
	ld	b, #0x00
	ld	hl, #00585$
	add	hl, bc
	add	hl, bc
	add	hl, bc
	jp	(hl)
00585$:
	jp	00191$
	jp	00191$
	jp	00191$
	jp	00187$
	jp	00193$
	jp	00195$
	jp	00193$
	jp	00195$
	jp	00191$
	jp	00187$
	C$SpriteOrpheus.c$194$4_0$211	= .
	.globl	C$SpriteOrpheus.c$194$4_0$211
;SpriteOrpheus.c:194: case WALK_DOWN: case IDLE_DOWN:
00187$:
	C$SpriteOrpheus.c$195$4_0$211	= .
	.globl	C$SpriteOrpheus.c$195$4_0$211
;SpriteOrpheus.c:195: orhpeus_change_state(IDLE_DOWN);
	ld	a, #0x03
	push	af
	inc	sp
	ld	e, #b_orhpeus_change_state
	ld	hl, #_orhpeus_change_state
	call	___sdcc_bcall_ehl
	inc	sp
	C$SpriteOrpheus.c$196$4_0$211	= .
	.globl	C$SpriteOrpheus.c$196$4_0$211
;SpriteOrpheus.c:196: break;
	jr	00205$
	C$SpriteOrpheus.c$197$4_0$211	= .
	.globl	C$SpriteOrpheus.c$197$4_0$211
;SpriteOrpheus.c:197: case WALK_UP: case IDLE_UP: case GENERIC_IDLE: case GENERIC_WALK:
00191$:
	C$SpriteOrpheus.c$198$4_0$211	= .
	.globl	C$SpriteOrpheus.c$198$4_0$211
;SpriteOrpheus.c:198: orhpeus_change_state(IDLE_UP);
	ld	a, #0x02
	push	af
	inc	sp
	ld	e, #b_orhpeus_change_state
	ld	hl, #_orhpeus_change_state
	call	___sdcc_bcall_ehl
	inc	sp
	C$SpriteOrpheus.c$199$4_0$211	= .
	.globl	C$SpriteOrpheus.c$199$4_0$211
;SpriteOrpheus.c:199: break;
	jr	00205$
	C$SpriteOrpheus.c$200$4_0$211	= .
	.globl	C$SpriteOrpheus.c$200$4_0$211
;SpriteOrpheus.c:200: case WALK_LEFT: case IDLE_LEFT:
00193$:
	C$SpriteOrpheus.c$201$4_0$211	= .
	.globl	C$SpriteOrpheus.c$201$4_0$211
;SpriteOrpheus.c:201: orhpeus_change_state(IDLE_LEFT);
	ld	a, #0x04
	push	af
	inc	sp
	ld	e, #b_orhpeus_change_state
	ld	hl, #_orhpeus_change_state
	call	___sdcc_bcall_ehl
	inc	sp
	C$SpriteOrpheus.c$202$4_0$211	= .
	.globl	C$SpriteOrpheus.c$202$4_0$211
;SpriteOrpheus.c:202: break;
	jr	00205$
	C$SpriteOrpheus.c$203$4_0$211	= .
	.globl	C$SpriteOrpheus.c$203$4_0$211
;SpriteOrpheus.c:203: case WALK_RIGHT: case IDLE_RIGHT:
00195$:
	C$SpriteOrpheus.c$204$4_0$211	= .
	.globl	C$SpriteOrpheus.c$204$4_0$211
;SpriteOrpheus.c:204: orhpeus_change_state(IDLE_RIGHT);
	ld	a, #0x05
	push	af
	inc	sp
	ld	e, #b_orhpeus_change_state
	ld	hl, #_orhpeus_change_state
	call	___sdcc_bcall_ehl
	inc	sp
	C$SpriteOrpheus.c$208$2_0$204	= .
	.globl	C$SpriteOrpheus.c$208$2_0$204
;SpriteOrpheus.c:208: break;
	jr	00205$
	C$SpriteOrpheus.c$209$2_0$204	= .
	.globl	C$SpriteOrpheus.c$209$2_0$204
;SpriteOrpheus.c:209: case ATTACK:
00202$:
	C$SpriteOrpheus.c$210$2_0$204	= .
	.globl	C$SpriteOrpheus.c$210$2_0$204
;SpriteOrpheus.c:210: orpheus_wait--;
	ld	hl, #_orpheus_wait
	dec	(hl)
	C$SpriteOrpheus.c$211$2_0$204	= .
	.globl	C$SpriteOrpheus.c$211$2_0$204
;SpriteOrpheus.c:211: if(orpheus_wait <= 1){
	ld	a, #0x01
	sub	a, (hl)
	jr	C, 00205$
	C$SpriteOrpheus.c$212$3_0$212	= .
	.globl	C$SpriteOrpheus.c$212$3_0$212
;SpriteOrpheus.c:212: orhpeus_change_state(orpheus_state_before);
	ld	a, (#_orpheus_state_before)
	push	af
	inc	sp
	ld	e, #b_orhpeus_change_state
	ld	hl, #_orhpeus_change_state
	call	___sdcc_bcall_ehl
	inc	sp
	C$SpriteOrpheus.c$213$3_0$212	= .
	.globl	C$SpriteOrpheus.c$213$3_0$212
;SpriteOrpheus.c:213: return;
	jp	00226$
	C$SpriteOrpheus.c$216$1_0$183	= .
	.globl	C$SpriteOrpheus.c$216$1_0$183
;SpriteOrpheus.c:216: }
00205$:
	C$SpriteOrpheus.c$220$2_1$214	= .
	.globl	C$SpriteOrpheus.c$220$2_1$214
;SpriteOrpheus.c:220: SPRITEMANAGER_ITERATE(scroll_o_tile, iospr) {
	ld	a, (#(_sprite_manager_updatables + 1) + 0)
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	ld	de, #_sprite_manager_sprites
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
	ldhl	sp,	#4
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	ldhl	sp,	#8
	ld	(hl), #0x00
00224$:
	ld	hl, #_sprite_manager_updatables
	ld	b, (hl)
	ldhl	sp,	#8
	ld	a, (hl)
	sub	a, b
	jp	Z,00226$
	C$SpriteOrpheus.c$221$3_1$215	= .
	.globl	C$SpriteOrpheus.c$221$3_1$215
;SpriteOrpheus.c:221: if(orpheus_info->ow_state == ATTACK){
	ld	hl, #_orpheus_info
	ld	l, (hl)
;	spillPairReg hl
;	spillPairReg hl
	ld	a, (_orpheus_info + 1)
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	ld	c, (hl)
	C$SpriteOrpheus.c$222$2_1$183	= .
	.globl	C$SpriteOrpheus.c$222$2_1$183
;SpriteOrpheus.c:222: switch(iospr->type){
	ldhl	sp,#4
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0013
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#4
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#3
	ld	(hl), a
	C$SpriteOrpheus.c$221$3_1$215	= .
	.globl	C$SpriteOrpheus.c$221$3_1$215
;SpriteOrpheus.c:221: if(orpheus_info->ow_state == ATTACK){
	ld	a, c
	sub	a, #0x0b
	jr	NZ, 00209$
	C$SpriteOrpheus.c$222$4_1$216	= .
	.globl	C$SpriteOrpheus.c$222$4_1$216
;SpriteOrpheus.c:222: switch(iospr->type){
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	cp	a, #0x02
	jr	NZ, 00209$
	C$SpriteOrpheus.c$224$5_1$217	= .
	.globl	C$SpriteOrpheus.c$224$5_1$217
;SpriteOrpheus.c:224: e_change_state(iospr, HIT, iospr->type);
	inc	hl
	push	af
	inc	sp
	ld	a, #0x0c
	push	af
	inc	sp
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	push	de
	ld	e, #b_e_change_state
	ld	hl, #_e_change_state
	call	___sdcc_bcall_ehl
	add	sp, #4
	C$SpriteOrpheus.c$226$3_1$215	= .
	.globl	C$SpriteOrpheus.c$226$3_1$215
;SpriteOrpheus.c:226: }
00209$:
	C$SpriteOrpheus.c$228$3_1$215	= .
	.globl	C$SpriteOrpheus.c$228$3_1$215
;SpriteOrpheus.c:228: if(CheckCollision(THIS, iospr)) {
	ldhl	sp,	#4
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	hl, #_THIS
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	call	_CheckCollision
	ldhl	sp,#7
	ld	(hl), a
	or	a, a
	jp	Z, 00225$
	C$SpriteOrpheus.c$229$4_1$218	= .
	.globl	C$SpriteOrpheus.c$229$4_1$218
;SpriteOrpheus.c:229: switch(iospr->type){
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	sub	a, #0x02
	jp	NZ,00225$
	C$SpriteOrpheus.c$127$2_1$183	= .
	.globl	C$SpriteOrpheus.c$127$2_1$183
;SpriteOrpheus.c:127: new_state = orpheus_info->ow_state;
	ld	a, (#_orpheus_info)
	ldhl	sp,	#0
	ld	(hl), a
	ld	a, (#_orpheus_info + 1)
	ldhl	sp,	#1
	ld	(hl), a
	C$SpriteOrpheus.c$231$5_1$219	= .
	.globl	C$SpriteOrpheus.c$231$5_1$219
;SpriteOrpheus.c:231: if(orpheus_info->ow_state != HIT){
	pop	de
	push	de
	ld	a, (de)
	sub	a, #0x0c
	jp	Z,00225$
	C$SpriteOrpheus.c$232$6_1$220	= .
	.globl	C$SpriteOrpheus.c$232$6_1$220
;SpriteOrpheus.c:232: struct EnemyInfo* e_data = (struct EnemyInfo*) iospr->custom_data;
	ldhl	sp,#4
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x001b
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#8
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#7
	C$SpriteOrpheus.c$233$6_1$220	= .
	.globl	C$SpriteOrpheus.c$233$6_1$220
;SpriteOrpheus.c:233: if(e_data->vx != orpheus_info->vx && orpheus_info->vy == 0){
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0002
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#6
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#5
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	c, a
	C$SpriteOrpheus.c$161$2_1$183	= .
	.globl	C$SpriteOrpheus.c$161$2_1$183
;SpriteOrpheus.c:161: orpheus_info->vx = push_vx;
	pop	de
	push	de
	ld	hl, #0x0002
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#4
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#3
	C$SpriteOrpheus.c$233$6_1$220	= .
	.globl	C$SpriteOrpheus.c$233$6_1$220
;SpriteOrpheus.c:233: if(e_data->vx != orpheus_info->vx && orpheus_info->vy == 0){
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	b, a
	C$SpriteOrpheus.c$166$2_1$183	= .
	.globl	C$SpriteOrpheus.c$166$2_1$183
;SpriteOrpheus.c:166: orpheus_info->vy = -1;
	pop	de
	push	de
	ld	hl, #0x0003
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#6
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#5
	ld	(hl), a
	C$SpriteOrpheus.c$233$6_1$220	= .
	.globl	C$SpriteOrpheus.c$233$6_1$220
;SpriteOrpheus.c:233: if(e_data->vx != orpheus_info->vx && orpheus_info->vy == 0){
	ld	a, c
	sub	a, b
	jr	Z, 00212$
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	or	a, a
	jr	NZ, 00212$
	C$SpriteOrpheus.c$234$7_1$221	= .
	.globl	C$SpriteOrpheus.c$234$7_1$221
;SpriteOrpheus.c:234: push_vx = e_data->vx;
	ld	hl, #_push_vx
	ld	(hl), c
00212$:
	C$SpriteOrpheus.c$236$6_1$220	= .
	.globl	C$SpriteOrpheus.c$236$6_1$220
;SpriteOrpheus.c:236: if(e_data->vy != orpheus_info->vy && orpheus_info->vx == 0){
	ldhl	sp,#6
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0003
	add	hl, de
	inc	sp
	inc	sp
	ld	e, l
	ld	d, h
	push	de
	ld	a, (de)
	ldhl	sp,	#6
	ld	(hl-), a
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl+)
	inc	hl
	ld	d, a
	ld	a, (de)
	ld	(hl-), a
	ld	a, (hl+)
	sub	a, (hl)
	jr	Z, 00215$
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	or	a, a
	jr	NZ, 00215$
	C$SpriteOrpheus.c$237$7_1$222	= .
	.globl	C$SpriteOrpheus.c$237$7_1$222
;SpriteOrpheus.c:237: push_vy = e_data->vy;
	ldhl	sp,	#6
	ld	a, (hl)
	ld	(#_push_vy),a
00215$:
	C$SpriteOrpheus.c$239$6_1$220	= .
	.globl	C$SpriteOrpheus.c$239$6_1$220
;SpriteOrpheus.c:239: orhpeus_change_state(HIT);
	ld	a, #0x0c
	push	af
	inc	sp
	ld	e, #b_orhpeus_change_state
	ld	hl, #_orhpeus_change_state
	call	___sdcc_bcall_ehl
	inc	sp
	C$SpriteOrpheus.c$242$3_1$215	= .
	.globl	C$SpriteOrpheus.c$242$3_1$215
;SpriteOrpheus.c:242: }
00225$:
	C$SpriteOrpheus.c$220$2_1$214	= .
	.globl	C$SpriteOrpheus.c$220$2_1$214
;SpriteOrpheus.c:220: SPRITEMANAGER_ITERATE(scroll_o_tile, iospr) {
	ldhl	sp,	#8
	inc	(hl)
	ld	a, (hl-)
	dec	hl
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	l, e
	ld	h, d
	inc	hl
	push	hl
	ld	a, l
	ldhl	sp,	#6
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#5
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #_sprite_manager_updatables
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#8
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#7
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	(hl), a
	ld	a, (hl-)
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl-)
	dec	hl
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	sla	(hl)
	inc	hl
	rl	(hl)
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #_sprite_manager_sprites
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#8
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#7
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ldhl	sp,	#4
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	jp	00224$
00226$:
	C$SpriteOrpheus.c$245$2_1$183	= .
	.globl	C$SpriteOrpheus.c$245$2_1$183
;SpriteOrpheus.c:245: }
	add	sp, #9
	C$SpriteOrpheus.c$245$2_1$183	= .
	.globl	C$SpriteOrpheus.c$245$2_1$183
	XG$Update_SpriteOrpheus$0$0	= .
	.globl	XG$Update_SpriteOrpheus$0$0
	ret
	G$orpheus_recharge$0$0	= .
	.globl	G$orpheus_recharge$0$0
	C$SpriteOrpheus.c$247$2_1$223	= .
	.globl	C$SpriteOrpheus.c$247$2_1$223
;SpriteOrpheus.c:247: void orpheus_recharge() BANKED{
;	---------------------------------
; Function orpheus_recharge
; ---------------------------------
	b_orpheus_recharge	= 255
_orpheus_recharge::
	C$SpriteOrpheus.c$248$1_0$223	= .
	.globl	C$SpriteOrpheus.c$248$1_0$223
;SpriteOrpheus.c:248: if(countdown_verso != 0){
	ld	a, (#_countdown_verso)
	or	a, a
	ret	Z
	C$SpriteOrpheus.c$249$2_0$224	= .
	.globl	C$SpriteOrpheus.c$249$2_0$224
;SpriteOrpheus.c:249: countdown_step--;
	ld	hl, #_countdown_step
	C$SpriteOrpheus.c$250$2_0$224	= .
	.globl	C$SpriteOrpheus.c$250$2_0$224
;SpriteOrpheus.c:250: if(countdown_step == 0){
	dec	(hl)
	ret	NZ
	C$SpriteOrpheus.c$251$3_0$225	= .
	.globl	C$SpriteOrpheus.c$251$3_0$225
;SpriteOrpheus.c:251: countdown_step = COUNTDOWN_STEP_MAX;
	ld	(hl), #0x01
	C$SpriteOrpheus.c$252$3_0$225	= .
	.globl	C$SpriteOrpheus.c$252$3_0$225
;SpriteOrpheus.c:252: countdown += countdown_verso;
	ld	a, (#_countdown)
	ld	hl, #_countdown_verso
	add	a, (hl)
	C$SpriteOrpheus.c$253$3_0$225	= .
	.globl	C$SpriteOrpheus.c$253$3_0$225
;SpriteOrpheus.c:253: if(countdown == orpheus_power_max){//RICHARGE COMPLETA
	ld	(#_countdown),a
	ld	c, a
	rlca
	sbc	a, a
	ld	b, a
	ld	hl, #_orpheus_power_max
	ld	e, (hl)
	ld	d, #0x00
	ld	a, e
	sub	a, c
	jr	NZ, 00102$
	ld	a, d
	sub	a, b
	jr	NZ, 00102$
	C$SpriteOrpheus.c$254$4_0$226	= .
	.globl	C$SpriteOrpheus.c$254$4_0$226
;SpriteOrpheus.c:254: orpheus_info->charming = -1;
	ld	hl, #_orpheus_info
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #0x0004
	add	hl, bc
	ld	(hl), #0xff
	C$SpriteOrpheus.c$255$4_0$226	= .
	.globl	C$SpriteOrpheus.c$255$4_0$226
;SpriteOrpheus.c:255: countdown_verso = 0;
	ld	hl, #_countdown_verso
	ld	(hl), #0x00
	C$SpriteOrpheus.c$256$4_0$226	= .
	.globl	C$SpriteOrpheus.c$256$4_0$226
;SpriteOrpheus.c:256: orpheus_info->charming = 0;
	ld	hl, #_orpheus_info
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	inc	bc
	inc	bc
	inc	bc
	inc	bc
	xor	a, a
	ld	(bc), a
00102$:
	C$SpriteOrpheus.c$258$3_0$225	= .
	.globl	C$SpriteOrpheus.c$258$3_0$225
;SpriteOrpheus.c:258: update_hud = 1;
	ld	hl, #_update_hud
	ld	(hl), #0x01
	C$SpriteOrpheus.c$261$1_0$223	= .
	.globl	C$SpriteOrpheus.c$261$1_0$223
;SpriteOrpheus.c:261: }
	C$SpriteOrpheus.c$261$1_0$223	= .
	.globl	C$SpriteOrpheus.c$261$1_0$223
	XG$orpheus_recharge$0$0	= .
	.globl	XG$orpheus_recharge$0$0
	ret
	G$orpheus_update_position$0$0	= .
	.globl	G$orpheus_update_position$0$0
	C$SpriteOrpheus.c$263$1_0$227	= .
	.globl	C$SpriteOrpheus.c$263$1_0$227
;SpriteOrpheus.c:263: void orpheus_update_position() BANKED{
;	---------------------------------
; Function orpheus_update_position
; ---------------------------------
	b_orpheus_update_position	= 255
_orpheus_update_position::
	dec	sp
	dec	sp
	C$SpriteOrpheus.c$264$1_0$227	= .
	.globl	C$SpriteOrpheus.c$264$1_0$227
;SpriteOrpheus.c:264: orpheus_info->tile_collision = TranslateSprite(THIS, orpheus_info->vx << delta_time, orpheus_info->vy << delta_time);
	ld	hl, #_orpheus_info
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	l, c
	ld	h, b
	inc	hl
	inc	sp
	inc	sp
	push	hl
	ld	l, c
;	spillPairReg hl
;	spillPairReg hl
	ld	h, b
;	spillPairReg hl
;	spillPairReg hl
	inc	hl
	inc	hl
	inc	hl
	ld	d, (hl)
	ld	hl, #_delta_time
	ld	a, (hl)
	inc	a
	jr	00130$
00129$:
	sla	d
00130$:
	dec	a
	jr	NZ,00129$
	inc	bc
	inc	bc
	ld	a, (bc)
	ld	b, (hl)
	ld	c, a
	inc	b
	jr	00132$
00131$:
	sla	c
00132$:
	dec	b
	jr	NZ,00131$
	push	de
	inc	sp
	ld	a, c
	ld	hl, #_THIS
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	call	_TranslateSprite
	ld	c, a
	pop	hl
	push	hl
	ld	(hl), c
	ld	hl, #_orpheus_info
	ld	l, (hl)
;	spillPairReg hl
;	spillPairReg hl
	ld	a, (_orpheus_info + 1)
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	inc	hl
	C$SpriteOrpheus.c$265$1_0$227	= .
	.globl	C$SpriteOrpheus.c$265$1_0$227
;SpriteOrpheus.c:265: if(orpheus_info->tile_collision){
	ld	c, (hl)
	ld	a, c
	or	a, a
	jr	Z, 00106$
	C$SpriteOrpheus.c$267$2_0$228	= .
	.globl	C$SpriteOrpheus.c$267$2_0$228
;SpriteOrpheus.c:267: if(orpheus_info->tile_collision >= 120u && orpheus_info->tile_collision <= 127) {
	ld	a, c
	sub	a, #0x78
	jr	C, 00106$
	ld	a, #0x7f
	sub	a, c
	jr	C, 00106$
	C$SpriteOrpheus.c$268$3_0$229	= .
	.globl	C$SpriteOrpheus.c$268$3_0$229
;SpriteOrpheus.c:268: orhpeus_change_state(HIT);
	ld	a, #0x0c
	push	af
	inc	sp
	ld	e, #b_orhpeus_change_state
	ld	hl, #_orhpeus_change_state
	call	___sdcc_bcall_ehl
	inc	sp
00106$:
	C$SpriteOrpheus.c$273$1_0$227	= .
	.globl	C$SpriteOrpheus.c$273$1_0$227
;SpriteOrpheus.c:273: }
	inc	sp
	inc	sp
	C$SpriteOrpheus.c$273$1_0$227	= .
	.globl	C$SpriteOrpheus.c$273$1_0$227
	XG$orpheus_update_position$0$0	= .
	.globl	XG$orpheus_update_position$0$0
	ret
	G$orhpeus_change_state$0$0	= .
	.globl	G$orhpeus_change_state$0$0
	C$SpriteOrpheus.c$275$1_0$231	= .
	.globl	C$SpriteOrpheus.c$275$1_0$231
;SpriteOrpheus.c:275: void orhpeus_change_state(SPRITE_STATES new_state) BANKED{
;	---------------------------------
; Function orhpeus_change_state
; ---------------------------------
	b_orhpeus_change_state	= 255
_orhpeus_change_state::
	C$SpriteOrpheus.c$276$1_0$231	= .
	.globl	C$SpriteOrpheus.c$276$1_0$231
;SpriteOrpheus.c:276: if(orpheus_info->ow_state == new_state){
	ld	hl, #_orpheus_info
	ld	l, (hl)
;	spillPairReg hl
;	spillPairReg hl
	ld	a, (_orpheus_info + 1)
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	ld	c, (hl)
	ldhl	sp,	#6
	ld	a, (hl)
	sub	a, c
	ret	Z
	C$SpriteOrpheus.c$277$2_0$232	= .
	.globl	C$SpriteOrpheus.c$277$2_0$232
;SpriteOrpheus.c:277: return;
	jr	00102$
00102$:
	C$SpriteOrpheus.c$279$1_0$231	= .
	.globl	C$SpriteOrpheus.c$279$1_0$231
;SpriteOrpheus.c:279: switch(new_state){
	ld	a, #0x0c
	ldhl	sp,	#6
	sub	a, (hl)
	jp	C, 00126$
	ld	c, (hl)
	ld	b, #0x00
	ld	hl, #00173$
	add	hl, bc
	add	hl, bc
	add	hl, bc
	jp	(hl)
00173$:
	jp	00126$
	jp	00126$
	jp	00104$
	jp	00103$
	jp	00105$
	jp	00106$
	jp	00109$
	jp	00110$
	jp	00108$
	jp	00107$
	jp	00126$
	jp	00121$
	jp	00111$
	C$SpriteOrpheus.c$280$2_0$233	= .
	.globl	C$SpriteOrpheus.c$280$2_0$233
;SpriteOrpheus.c:280: case IDLE_DOWN:
00103$:
	C$SpriteOrpheus.c$281$2_0$233	= .
	.globl	C$SpriteOrpheus.c$281$2_0$233
;SpriteOrpheus.c:281: orpheus_info->vy = 0;
	ld	hl, #_orpheus_info
	ld	a, (hl+)
	ld	c, a
	C$SpriteOrpheus.c$282$2_0$233	= .
	.globl	C$SpriteOrpheus.c$282$2_0$233
;SpriteOrpheus.c:282: orpheus_info->vx = 0;
	ld	a, (hl-)
	ld	b, a
	inc	bc
	inc	bc
	inc	bc
	xor	a, a
	ld	(bc), a
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	inc	bc
	inc	bc
	xor	a, a
	ld	(bc), a
	C$SpriteOrpheus.c$283$2_0$233	= .
	.globl	C$SpriteOrpheus.c$283$2_0$233
;SpriteOrpheus.c:283: SetSpriteAnim(THIS, a_orpheus_idledown, 4u);
	ld	a, #0x04
	push	af
	inc	sp
	ld	bc, #_a_orpheus_idledown
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	_SetSpriteAnim
	C$SpriteOrpheus.c$284$2_0$233	= .
	.globl	C$SpriteOrpheus.c$284$2_0$233
;SpriteOrpheus.c:284: break;
	jp	00126$
	C$SpriteOrpheus.c$285$2_0$233	= .
	.globl	C$SpriteOrpheus.c$285$2_0$233
;SpriteOrpheus.c:285: case IDLE_UP:
00104$:
	C$SpriteOrpheus.c$286$2_0$233	= .
	.globl	C$SpriteOrpheus.c$286$2_0$233
;SpriteOrpheus.c:286: orpheus_info->vy = 0;
	ld	hl, #_orpheus_info
	ld	a, (hl+)
	ld	c, a
	C$SpriteOrpheus.c$287$2_0$233	= .
	.globl	C$SpriteOrpheus.c$287$2_0$233
;SpriteOrpheus.c:287: orpheus_info->vx = 0;
	ld	a, (hl-)
	ld	b, a
	inc	bc
	inc	bc
	inc	bc
	xor	a, a
	ld	(bc), a
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	inc	bc
	inc	bc
	xor	a, a
	ld	(bc), a
	C$SpriteOrpheus.c$288$2_0$233	= .
	.globl	C$SpriteOrpheus.c$288$2_0$233
;SpriteOrpheus.c:288: SetSpriteAnim(THIS, a_orpheus_idleup, 4u);
	ld	a, #0x04
	push	af
	inc	sp
	ld	bc, #_a_orpheus_idleup
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	_SetSpriteAnim
	C$SpriteOrpheus.c$289$2_0$233	= .
	.globl	C$SpriteOrpheus.c$289$2_0$233
;SpriteOrpheus.c:289: break;
	jp	00126$
	C$SpriteOrpheus.c$290$2_0$233	= .
	.globl	C$SpriteOrpheus.c$290$2_0$233
;SpriteOrpheus.c:290: case IDLE_LEFT:
00105$:
	C$SpriteOrpheus.c$291$2_0$233	= .
	.globl	C$SpriteOrpheus.c$291$2_0$233
;SpriteOrpheus.c:291: orpheus_info->vy = 0;
	ld	hl, #_orpheus_info
	ld	a, (hl+)
	ld	c, a
	C$SpriteOrpheus.c$292$2_0$233	= .
	.globl	C$SpriteOrpheus.c$292$2_0$233
;SpriteOrpheus.c:292: orpheus_info->vx = 0;
	ld	a, (hl-)
	ld	b, a
	inc	bc
	inc	bc
	inc	bc
	xor	a, a
	ld	(bc), a
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	inc	bc
	inc	bc
	xor	a, a
	ld	(bc), a
	C$SpriteOrpheus.c$293$2_0$233	= .
	.globl	C$SpriteOrpheus.c$293$2_0$233
;SpriteOrpheus.c:293: SetSpriteAnim(THIS, a_orpheus_idleh, 4u);
	ld	a, #0x04
	push	af
	inc	sp
	ld	bc, #_a_orpheus_idleh
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	_SetSpriteAnim
	C$SpriteOrpheus.c$294$2_0$233	= .
	.globl	C$SpriteOrpheus.c$294$2_0$233
;SpriteOrpheus.c:294: THIS->mirror = V_MIRROR;
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #0x0010
	add	hl, bc
	ld	(hl), #0x02
	C$SpriteOrpheus.c$295$2_0$233	= .
	.globl	C$SpriteOrpheus.c$295$2_0$233
;SpriteOrpheus.c:295: break;
	jp	00126$
	C$SpriteOrpheus.c$296$2_0$233	= .
	.globl	C$SpriteOrpheus.c$296$2_0$233
;SpriteOrpheus.c:296: case IDLE_RIGHT:
00106$:
	C$SpriteOrpheus.c$297$2_0$233	= .
	.globl	C$SpriteOrpheus.c$297$2_0$233
;SpriteOrpheus.c:297: orpheus_info->vx = 0;
	ld	hl, #_orpheus_info
	ld	a, (hl+)
	ld	c, a
	C$SpriteOrpheus.c$298$2_0$233	= .
	.globl	C$SpriteOrpheus.c$298$2_0$233
;SpriteOrpheus.c:298: orpheus_info->vy = 0;
	ld	a, (hl-)
	ld	b, a
	inc	bc
	inc	bc
	xor	a, a
	ld	(bc), a
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	inc	bc
	inc	bc
	inc	bc
	xor	a, a
	ld	(bc), a
	C$SpriteOrpheus.c$299$2_0$233	= .
	.globl	C$SpriteOrpheus.c$299$2_0$233
;SpriteOrpheus.c:299: SetSpriteAnim(THIS, a_orpheus_idleh, 4u);
	ld	a, #0x04
	push	af
	inc	sp
	ld	bc, #_a_orpheus_idleh
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	_SetSpriteAnim
	C$SpriteOrpheus.c$300$2_0$233	= .
	.globl	C$SpriteOrpheus.c$300$2_0$233
;SpriteOrpheus.c:300: THIS->mirror = NO_MIRROR;
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #0x0010
	add	hl, bc
	ld	(hl), #0x00
	C$SpriteOrpheus.c$301$2_0$233	= .
	.globl	C$SpriteOrpheus.c$301$2_0$233
;SpriteOrpheus.c:301: break;
	jp	00126$
	C$SpriteOrpheus.c$302$2_0$233	= .
	.globl	C$SpriteOrpheus.c$302$2_0$233
;SpriteOrpheus.c:302: case WALK_DOWN:
00107$:
	C$SpriteOrpheus.c$303$2_0$233	= .
	.globl	C$SpriteOrpheus.c$303$2_0$233
;SpriteOrpheus.c:303: orpheus_info->vx = 0;
	ld	hl, #_orpheus_info
	ld	a, (hl+)
	ld	c, a
	C$SpriteOrpheus.c$304$2_0$233	= .
	.globl	C$SpriteOrpheus.c$304$2_0$233
;SpriteOrpheus.c:304: orpheus_info->vy = 1;
	ld	a, (hl-)
	ld	b, a
	inc	bc
	inc	bc
	xor	a, a
	ld	(bc), a
	ld	l, (hl)
;	spillPairReg hl
;	spillPairReg hl
	ld	a, (_orpheus_info + 1)
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	inc	hl
	inc	hl
	inc	hl
	ld	(hl), #0x01
	C$SpriteOrpheus.c$305$2_0$233	= .
	.globl	C$SpriteOrpheus.c$305$2_0$233
;SpriteOrpheus.c:305: SetSpriteAnim(THIS, a_orpheus_walk_down, 12u);
	ld	a, #0x0c
	push	af
	inc	sp
	ld	bc, #_a_orpheus_walk_down
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	_SetSpriteAnim
	C$SpriteOrpheus.c$306$2_0$233	= .
	.globl	C$SpriteOrpheus.c$306$2_0$233
;SpriteOrpheus.c:306: break;
	jp	00126$
	C$SpriteOrpheus.c$307$2_0$233	= .
	.globl	C$SpriteOrpheus.c$307$2_0$233
;SpriteOrpheus.c:307: case WALK_UP:
00108$:
	C$SpriteOrpheus.c$308$2_0$233	= .
	.globl	C$SpriteOrpheus.c$308$2_0$233
;SpriteOrpheus.c:308: orpheus_info->vx = 0;
	ld	hl, #_orpheus_info
	ld	a, (hl+)
	ld	c, a
	C$SpriteOrpheus.c$309$2_0$233	= .
	.globl	C$SpriteOrpheus.c$309$2_0$233
;SpriteOrpheus.c:309: orpheus_info->vy = -1;
	ld	a, (hl-)
	ld	b, a
	inc	bc
	inc	bc
	xor	a, a
	ld	(bc), a
	ld	l, (hl)
;	spillPairReg hl
;	spillPairReg hl
	ld	a, (_orpheus_info + 1)
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	inc	hl
	inc	hl
	inc	hl
	ld	(hl), #0xff
	C$SpriteOrpheus.c$310$2_0$233	= .
	.globl	C$SpriteOrpheus.c$310$2_0$233
;SpriteOrpheus.c:310: SetSpriteAnim(THIS, a_orpheus_walk_up, 8u);
	ld	a, #0x08
	push	af
	inc	sp
	ld	bc, #_a_orpheus_walk_up
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	_SetSpriteAnim
	C$SpriteOrpheus.c$311$2_0$233	= .
	.globl	C$SpriteOrpheus.c$311$2_0$233
;SpriteOrpheus.c:311: break;
	jp	00126$
	C$SpriteOrpheus.c$312$2_0$233	= .
	.globl	C$SpriteOrpheus.c$312$2_0$233
;SpriteOrpheus.c:312: case WALK_LEFT:
00109$:
	C$SpriteOrpheus.c$313$2_0$233	= .
	.globl	C$SpriteOrpheus.c$313$2_0$233
;SpriteOrpheus.c:313: orpheus_info->vx = -1;
	ld	hl, #_orpheus_info
	ld	l, (hl)
;	spillPairReg hl
;	spillPairReg hl
	ld	a, (_orpheus_info + 1)
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	inc	hl
	inc	hl
	ld	(hl), #0xff
	C$SpriteOrpheus.c$314$2_0$233	= .
	.globl	C$SpriteOrpheus.c$314$2_0$233
;SpriteOrpheus.c:314: orpheus_info->vy = 0;
	ld	hl, #_orpheus_info
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	inc	bc
	inc	bc
	inc	bc
	xor	a, a
	ld	(bc), a
	C$SpriteOrpheus.c$315$2_0$233	= .
	.globl	C$SpriteOrpheus.c$315$2_0$233
;SpriteOrpheus.c:315: SetSpriteAnim(THIS, a_orpheus_walk_h, 12u);
	ld	a, #0x0c
	push	af
	inc	sp
	ld	bc, #_a_orpheus_walk_h
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	_SetSpriteAnim
	C$SpriteOrpheus.c$316$2_0$233	= .
	.globl	C$SpriteOrpheus.c$316$2_0$233
;SpriteOrpheus.c:316: THIS->mirror = V_MIRROR;
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #0x0010
	add	hl, bc
	ld	(hl), #0x02
	C$SpriteOrpheus.c$317$2_0$233	= .
	.globl	C$SpriteOrpheus.c$317$2_0$233
;SpriteOrpheus.c:317: break;
	jp	00126$
	C$SpriteOrpheus.c$318$2_0$233	= .
	.globl	C$SpriteOrpheus.c$318$2_0$233
;SpriteOrpheus.c:318: case WALK_RIGHT:
00110$:
	C$SpriteOrpheus.c$319$2_0$233	= .
	.globl	C$SpriteOrpheus.c$319$2_0$233
;SpriteOrpheus.c:319: orpheus_info->vx = 1;
	ld	hl, #_orpheus_info
	ld	l, (hl)
;	spillPairReg hl
;	spillPairReg hl
	ld	a, (_orpheus_info + 1)
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	inc	hl
	inc	hl
	ld	(hl), #0x01
	C$SpriteOrpheus.c$320$2_0$233	= .
	.globl	C$SpriteOrpheus.c$320$2_0$233
;SpriteOrpheus.c:320: orpheus_info->vy = 0;
	ld	hl, #_orpheus_info
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	inc	bc
	inc	bc
	inc	bc
	xor	a, a
	ld	(bc), a
	C$SpriteOrpheus.c$321$2_0$233	= .
	.globl	C$SpriteOrpheus.c$321$2_0$233
;SpriteOrpheus.c:321: SetSpriteAnim(THIS, a_orpheus_walk_h, 12u);
	ld	a, #0x0c
	push	af
	inc	sp
	ld	bc, #_a_orpheus_walk_h
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	_SetSpriteAnim
	C$SpriteOrpheus.c$322$2_0$233	= .
	.globl	C$SpriteOrpheus.c$322$2_0$233
;SpriteOrpheus.c:322: THIS->mirror = NO_MIRROR;
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #0x0010
	add	hl, bc
	ld	(hl), #0x00
	C$SpriteOrpheus.c$323$2_0$233	= .
	.globl	C$SpriteOrpheus.c$323$2_0$233
;SpriteOrpheus.c:323: break;
	jp	00126$
	C$SpriteOrpheus.c$324$2_0$233	= .
	.globl	C$SpriteOrpheus.c$324$2_0$233
;SpriteOrpheus.c:324: case HIT:
00111$:
	C$SpriteOrpheus.c$325$2_0$233	= .
	.globl	C$SpriteOrpheus.c$325$2_0$233
;SpriteOrpheus.c:325: hit_frameskip_max = 1;
	ld	hl, #_hit_frameskip_max
	ld	(hl), #0x01
	C$SpriteOrpheus.c$326$2_0$233	= .
	.globl	C$SpriteOrpheus.c$326$2_0$233
;SpriteOrpheus.c:326: hit_frameskip = 1;
	ld	hl, #_hit_frameskip
	ld	(hl), #0x01
	C$SpriteOrpheus.c$327$2_0$233	= .
	.globl	C$SpriteOrpheus.c$327$2_0$233
;SpriteOrpheus.c:327: switch(orpheus_info->ow_state){
	ld	hl, #_orpheus_info
	ld	l, (hl)
;	spillPairReg hl
;	spillPairReg hl
	ld	a, (_orpheus_info + 1)
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	ld	c, (hl)
	ld	a, #0x09
	sub	a, c
	jr	C, 00120$
	ld	b, #0x00
	ld	hl, #00174$
	add	hl, bc
	add	hl, bc
	add	hl, bc
	jp	(hl)
00174$:
	jp	00120$
	jp	00120$
	jp	00115$
	jp	00113$
	jp	00119$
	jp	00119$
	jp	00119$
	jp	00119$
	jp	00115$
	jp	00113$
	C$SpriteOrpheus.c$329$3_0$234	= .
	.globl	C$SpriteOrpheus.c$329$3_0$234
;SpriteOrpheus.c:329: case IDLE_DOWN:
00113$:
	C$SpriteOrpheus.c$330$3_0$234	= .
	.globl	C$SpriteOrpheus.c$330$3_0$234
;SpriteOrpheus.c:330: SetSpriteAnim(THIS, a_orpheus_hit_down, 24u);
	ld	a, #0x18
	push	af
	inc	sp
	ld	bc, #_a_orpheus_hit_down
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	_SetSpriteAnim
	C$SpriteOrpheus.c$331$3_0$234	= .
	.globl	C$SpriteOrpheus.c$331$3_0$234
;SpriteOrpheus.c:331: break;
	jr	00120$
	C$SpriteOrpheus.c$333$3_0$234	= .
	.globl	C$SpriteOrpheus.c$333$3_0$234
;SpriteOrpheus.c:333: case IDLE_UP:
00115$:
	C$SpriteOrpheus.c$334$3_0$234	= .
	.globl	C$SpriteOrpheus.c$334$3_0$234
;SpriteOrpheus.c:334: SetSpriteAnim(THIS, a_orpheus_hit_up, 24u);
	ld	a, #0x18
	push	af
	inc	sp
	ld	bc, #_a_orpheus_hit_up
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	_SetSpriteAnim
	C$SpriteOrpheus.c$335$3_0$234	= .
	.globl	C$SpriteOrpheus.c$335$3_0$234
;SpriteOrpheus.c:335: break;
	jr	00120$
	C$SpriteOrpheus.c$337$3_0$234	= .
	.globl	C$SpriteOrpheus.c$337$3_0$234
;SpriteOrpheus.c:337: case IDLE_LEFT: case IDLE_RIGHT:
00119$:
	C$SpriteOrpheus.c$338$3_0$234	= .
	.globl	C$SpriteOrpheus.c$338$3_0$234
;SpriteOrpheus.c:338: SetSpriteAnim(THIS, a_orpheus_hit_h, 24u);
	ld	a, #0x18
	push	af
	inc	sp
	ld	bc, #_a_orpheus_hit_h
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	_SetSpriteAnim
	C$SpriteOrpheus.c$340$2_0$233	= .
	.globl	C$SpriteOrpheus.c$340$2_0$233
;SpriteOrpheus.c:340: }
00120$:
	C$SpriteOrpheus.c$341$2_0$233	= .
	.globl	C$SpriteOrpheus.c$341$2_0$233
;SpriteOrpheus.c:341: orpheus_state_before = orpheus_info->ow_state;
	ld	hl, #_orpheus_info
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	a, (bc)
	ld	(#_orpheus_state_before),a
	C$SpriteOrpheus.c$342$2_0$233	= .
	.globl	C$SpriteOrpheus.c$342$2_0$233
;SpriteOrpheus.c:342: orpheus_hit();
	ld	e, #b_orpheus_hit
	ld	hl, #_orpheus_hit
	call	___sdcc_bcall_ehl
	C$SpriteOrpheus.c$343$2_0$233	= .
	.globl	C$SpriteOrpheus.c$343$2_0$233
;SpriteOrpheus.c:343: break;
	jr	00126$
	C$SpriteOrpheus.c$344$2_0$233	= .
	.globl	C$SpriteOrpheus.c$344$2_0$233
;SpriteOrpheus.c:344: case ATTACK:
00121$:
	C$SpriteOrpheus.c$345$2_0$233	= .
	.globl	C$SpriteOrpheus.c$345$2_0$233
;SpriteOrpheus.c:345: countdown_step = COUNTDOWN_STEP_MAX;
	ld	hl, #_countdown_step
	ld	(hl), #0x01
	C$SpriteOrpheus.c$346$2_0$233	= .
	.globl	C$SpriteOrpheus.c$346$2_0$233
;SpriteOrpheus.c:346: countdown = 0;
	ld	hl, #_countdown
	ld	(hl), #0x00
	C$SpriteOrpheus.c$347$2_0$233	= .
	.globl	C$SpriteOrpheus.c$347$2_0$233
;SpriteOrpheus.c:347: countdown_verso = 1;
	ld	hl, #_countdown_verso
	ld	(hl), #0x01
	C$SpriteOrpheus.c$348$2_0$233	= .
	.globl	C$SpriteOrpheus.c$348$2_0$233
;SpriteOrpheus.c:348: update_hud = 1;
	ld	hl, #_update_hud
	ld	(hl), #0x01
	C$SpriteOrpheus.c$349$2_0$233	= .
	.globl	C$SpriteOrpheus.c$349$2_0$233
;SpriteOrpheus.c:349: orpheus_info->charming = 1;
	ld	hl, #_orpheus_info
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #0x0004
	add	hl, bc
	ld	(hl), #0x01
	C$SpriteOrpheus.c$350$2_0$233	= .
	.globl	C$SpriteOrpheus.c$350$2_0$233
;SpriteOrpheus.c:350: switch(song_selection){
	ld	a, (#_song_selection)
	or	a, a
	jr	Z, 00122$
	ld	a, (#_song_selection)
	dec	a
	jr	Z, 00124$
	ld	a, (#_song_selection)
	sub	a, #0x02
	jr	Z, 00123$
	jr	00126$
	C$SpriteOrpheus.c$351$3_0$235	= .
	.globl	C$SpriteOrpheus.c$351$3_0$235
;SpriteOrpheus.c:351: case ATTRACT://charm
00122$:
	C$SpriteOrpheus.c$352$3_0$235	= .
	.globl	C$SpriteOrpheus.c$352$3_0$235
;SpriteOrpheus.c:352: orpheus_wait = 120u;
	ld	hl, #_orpheus_wait
	ld	(hl), #0x78
	C$SpriteOrpheus.c$353$3_0$235	= .
	.globl	C$SpriteOrpheus.c$353$3_0$235
;SpriteOrpheus.c:353: break;
	jr	00126$
	C$SpriteOrpheus.c$354$3_0$235	= .
	.globl	C$SpriteOrpheus.c$354$3_0$235
;SpriteOrpheus.c:354: case REPEL://repell
00123$:
	C$SpriteOrpheus.c$355$3_0$235	= .
	.globl	C$SpriteOrpheus.c$355$3_0$235
;SpriteOrpheus.c:355: orpheus_wait = 120u;
	ld	hl, #_orpheus_wait
	ld	(hl), #0x78
	C$SpriteOrpheus.c$356$3_0$235	= .
	.globl	C$SpriteOrpheus.c$356$3_0$235
;SpriteOrpheus.c:356: break;
	jr	00126$
	C$SpriteOrpheus.c$357$3_0$235	= .
	.globl	C$SpriteOrpheus.c$357$3_0$235
;SpriteOrpheus.c:357: case SLEEP://attract
00124$:
	C$SpriteOrpheus.c$358$3_0$235	= .
	.globl	C$SpriteOrpheus.c$358$3_0$235
;SpriteOrpheus.c:358: orpheus_wait = 200u;
	ld	hl, #_orpheus_wait
	ld	(hl), #0xc8
	C$SpriteOrpheus.c$362$1_0$231	= .
	.globl	C$SpriteOrpheus.c$362$1_0$231
;SpriteOrpheus.c:362: }
00126$:
	C$SpriteOrpheus.c$363$1_0$231	= .
	.globl	C$SpriteOrpheus.c$363$1_0$231
;SpriteOrpheus.c:363: orpheus_info->ow_state = new_state;
	ld	hl, #_orpheus_info
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ldhl	sp,	#6
	ld	a, (hl)
	ld	(bc), a
	C$SpriteOrpheus.c$364$1_0$231	= .
	.globl	C$SpriteOrpheus.c$364$1_0$231
;SpriteOrpheus.c:364: }
	C$SpriteOrpheus.c$364$1_0$231	= .
	.globl	C$SpriteOrpheus.c$364$1_0$231
	XG$orhpeus_change_state$0$0	= .
	.globl	XG$orhpeus_change_state$0$0
	ret
	G$orpheus_hit$0$0	= .
	.globl	G$orpheus_hit$0$0
	C$SpriteOrpheus.c$366$1_0$236	= .
	.globl	C$SpriteOrpheus.c$366$1_0$236
;SpriteOrpheus.c:366: void orpheus_hit() BANKED{
;	---------------------------------
; Function orpheus_hit
; ---------------------------------
	b_orpheus_hit	= 255
_orpheus_hit::
	C$SpriteOrpheus.c$367$1_0$236	= .
	.globl	C$SpriteOrpheus.c$367$1_0$236
;SpriteOrpheus.c:367: if(orpheus_hitted == 0u){
	ld	a, (#_orpheus_hitted)
	or	a, a
	ret	NZ
	C$SpriteOrpheus.c$368$2_0$237	= .
	.globl	C$SpriteOrpheus.c$368$2_0$237
;SpriteOrpheus.c:368: orpheus_hp--;
	ld	hl, #_orpheus_hp
	dec	(hl)
	C$SpriteOrpheus.c$369$2_0$237	= .
	.globl	C$SpriteOrpheus.c$369$2_0$237
;SpriteOrpheus.c:369: orpheus_hit_countdown = 32;
	ld	hl, #_orpheus_hit_countdown
	ld	(hl), #0x20
	C$SpriteOrpheus.c$370$2_0$237	= .
	.globl	C$SpriteOrpheus.c$370$2_0$237
;SpriteOrpheus.c:370: orpheus_hitted = 1u;
	ld	hl, #_orpheus_hitted
	ld	(hl), #0x01
	C$SpriteOrpheus.c$371$2_0$237	= .
	.globl	C$SpriteOrpheus.c$371$2_0$237
;SpriteOrpheus.c:371: update_hud = 1;
	ld	hl, #_update_hud
	ld	(hl), #0x01
	C$SpriteOrpheus.c$373$1_0$236	= .
	.globl	C$SpriteOrpheus.c$373$1_0$236
;SpriteOrpheus.c:373: }
	C$SpriteOrpheus.c$373$1_0$236	= .
	.globl	C$SpriteOrpheus.c$373$1_0$236
	XG$orpheus_hit$0$0	= .
	.globl	XG$orpheus_hit$0$0
	ret
	G$Destroy_SpriteOrpheus$0$0	= .
	.globl	G$Destroy_SpriteOrpheus$0$0
	C$SpriteOrpheus.c$375$1_0$239	= .
	.globl	C$SpriteOrpheus.c$375$1_0$239
;SpriteOrpheus.c:375: void DESTROY() {
;	---------------------------------
; Function Destroy_SpriteOrpheus
; ---------------------------------
_Destroy_SpriteOrpheus::
	C$SpriteOrpheus.c$376$1_0$239	= .
	.globl	C$SpriteOrpheus.c$376$1_0$239
;SpriteOrpheus.c:376: }
	C$SpriteOrpheus.c$376$1_0$239	= .
	.globl	C$SpriteOrpheus.c$376$1_0$239
	XG$Destroy_SpriteOrpheus$0$0	= .
	.globl	XG$Destroy_SpriteOrpheus$0$0
	ret
	.area _CODE_255
	.area _INITIALIZER
FSpriteOrpheus$__xinit_new_state$0_0$0 == .
__xinit__new_state:
	.db #0x00	; 0
FSpriteOrpheus$__xinit_orpheus_power_max$0_0$0 == .
__xinit__orpheus_power_max:
	.db #0x00	; 0
FSpriteOrpheus$__xinit_orpheus_hp_max$0_0$0 == .
__xinit__orpheus_hp_max:
	.db #0x04	; 4
FSpriteOrpheus$__xinit_orpheus_hp$0_0$0 == .
__xinit__orpheus_hp:
	.db #0x04	;  4
FSpriteOrpheus$__xinit_orpheus_hit_countdown$0_0$0 == .
__xinit__orpheus_hit_countdown:
	.db #0x00	;  0
FSpriteOrpheus$__xinit_a_walk_counter_x$0_0$0 == .
__xinit__a_walk_counter_x:
	.db #0x00	;  0
FSpriteOrpheus$__xinit_a_walk_counter_y$0_0$0 == .
__xinit__a_walk_counter_y:
	.db #0x00	;  0
FSpriteOrpheus$__xinit_orpheus_hitted$0_0$0 == .
__xinit__orpheus_hitted:
	.db #0x00	; 0
FSpriteOrpheus$__xinit_hit_frameskip$0_0$0 == .
__xinit__hit_frameskip:
	.db #0x00	;  0
FSpriteOrpheus$__xinit_hit_frameskip_max$0_0$0 == .
__xinit__hit_frameskip_max:
	.db #0x00	;  0
FSpriteOrpheus$__xinit_orpheus_state_before$0_0$0 == .
__xinit__orpheus_state_before:
	.db #0x00	; 0
FSpriteOrpheus$__xinit_push_vx$0_0$0 == .
__xinit__push_vx:
	.db #0x00	;  0
FSpriteOrpheus$__xinit_push_vy$0_0$0 == .
__xinit__push_vy:
	.db #0x00	;  0
FSpriteOrpheus$__xinit_orpheus_wait$0_0$0 == .
__xinit__orpheus_wait:
	.db #0x00	; 0
FSpriteOrpheus$__xinit_countdown$0_0$0 == .
__xinit__countdown:
	.db #0x00	;  0
FSpriteOrpheus$__xinit_countdown_step$0_0$0 == .
__xinit__countdown_step:
	.db #0x00	; 0
FSpriteOrpheus$__xinit_countdown_verso$0_0$0 == .
__xinit__countdown_verso:
	.db #0x00	;  0
	.area _CABS (ABS)
