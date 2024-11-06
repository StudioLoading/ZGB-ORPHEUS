;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module SpriteSkeleton
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _Destroy_SpriteSkeleton
	.globl _Update_SpriteSkeleton
	.globl _Start_SpriteSkeleton
	.globl b_e_destroy
	.globl _e_destroy
	.globl b_e_management
	.globl _e_management
	.globl b_e_change_state
	.globl _e_change_state
	.globl b_e_start
	.globl _e_start
	.globl _SetSpriteAnim
	.globl _a_skeleton_repelled
	.globl _a_skeleton_h
	.globl _a_skeleton_down
	.globl _a_skeleton_up
	.globl _a_skeleton_hidden
	.globl ___bank_SpriteSkeleton
	.globl b_skeleton_update_anim
	.globl _skeleton_update_anim
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
	G$Start_SpriteSkeleton$0$0	= .
	.globl	G$Start_SpriteSkeleton$0$0
	C$SpriteSkeleton.c$29$0_0$185	= .
	.globl	C$SpriteSkeleton.c$29$0_0$185
;SpriteSkeleton.c:29: void START(){
;	---------------------------------
; Function Start_SpriteSkeleton
; ---------------------------------
_Start_SpriteSkeleton::
	C$SpriteSkeleton.c$30$1_0$185	= .
	.globl	C$SpriteSkeleton.c$30$1_0$185
;SpriteSkeleton.c:30: SetSpriteAnim(THIS, a_skeleton_hidden, 6);
	ld	a, #0x06
	push	af
	inc	sp
	ld	bc, #_a_skeleton_hidden
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	_SetSpriteAnim
	C$SpriteSkeleton.c$31$1_1$186	= .
	.globl	C$SpriteSkeleton.c$31$1_1$186
;SpriteSkeleton.c:31: struct EnemyInfo* e_data = (struct EnemyInfo*) THIS->custom_data;
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	b, (hl)
	add	a, #0x1b
	ld	c, a
	jr	NC, 00112$
	inc	b
00112$:
	C$SpriteSkeleton.c$32$1_1$186	= .
	.globl	C$SpriteSkeleton.c$32$1_1$186
;SpriteSkeleton.c:32: e_data->frmskip = 16u;
	ld	hl, #0x0007
	add	hl, bc
	ld	(hl), #0x10
	C$SpriteSkeleton.c$33$1_1$186	= .
	.globl	C$SpriteSkeleton.c$33$1_1$186
;SpriteSkeleton.c:33: e_start(e_data, IDLE_DOWN);
	ld	a, #0x03
	push	af
	inc	sp
	push	bc
	ld	e, #b_e_start
	ld	hl, #_e_start
	call	___sdcc_bcall_ehl
	add	sp, #3
	C$SpriteSkeleton.c$34$1_1$186	= .
	.globl	C$SpriteSkeleton.c$34$1_1$186
;SpriteSkeleton.c:34: if(_cpu != CGB_TYPE){
	ld	a, (#__cpu)
	sub	a, #0x11
	jr	Z, 00102$
	C$SpriteSkeleton.c$35$2_1$187	= .
	.globl	C$SpriteSkeleton.c$35$2_1$187
;SpriteSkeleton.c:35: OBP1_REG = PAL_DEF(0, 0, 1, 3);
	ld	a, #0xd0
	ldh	(_OBP1_REG + 0), a
	C$SpriteSkeleton.c$31$1_1$185	= .
	.globl	C$SpriteSkeleton.c$31$1_1$185
;SpriteSkeleton.c:31: struct EnemyInfo* e_data = (struct EnemyInfo*) THIS->custom_data;
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	C$SpriteSkeleton.c$36$1_1$185	= .
	.globl	C$SpriteSkeleton.c$36$1_1$185
;SpriteSkeleton.c:36: SPRITE_SET_PALETTE(THIS,1);
	inc	bc
	inc	bc
	inc	bc
	inc	bc
	ld	a, (bc)
	res	4, a
	set	4, a
	ld	(bc), a
00102$:
	C$SpriteSkeleton.c$38$1_1$186	= .
	.globl	C$SpriteSkeleton.c$38$1_1$186
;SpriteSkeleton.c:38: e_change_state(THIS, WALK_DOWN, THIS->type);
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #0x0013
	add	hl, bc
	ld	h, (hl)
	ld	l, #0x09
	push	hl
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	e, #b_e_change_state
	ld	hl, #_e_change_state
	call	___sdcc_bcall_ehl
	add	sp, #4
	C$SpriteSkeleton.c$39$1_1$185	= .
	.globl	C$SpriteSkeleton.c$39$1_1$185
;SpriteSkeleton.c:39: }
	C$SpriteSkeleton.c$39$1_1$185	= .
	.globl	C$SpriteSkeleton.c$39$1_1$185
	XG$Start_SpriteSkeleton$0$0	= .
	.globl	XG$Start_SpriteSkeleton$0$0
	ret
G$__bank_SpriteSkeleton$0_0$0 == 0x00ff
___bank_SpriteSkeleton	=	0x00ff
G$a_skeleton_hidden$0_0$0 == .
_a_skeleton_hidden:
	.db #0x01	; 1
	.db #0x00	; 0
G$a_skeleton_up$0_0$0 == .
_a_skeleton_up:
	.db #0x02	; 2
	.db #0x01	; 1
	.db #0x02	; 2
G$a_skeleton_down$0_0$0 == .
_a_skeleton_down:
	.db #0x02	; 2
	.db #0x03	; 3
	.db #0x04	; 4
G$a_skeleton_h$0_0$0 == .
_a_skeleton_h:
	.db #0x02	; 2
	.db #0x05	; 5
	.db #0x06	; 6
G$a_skeleton_repelled$0_0$0 == .
_a_skeleton_repelled:
	.db #0x04	; 4
	.db #0x01	; 1
	.db #0x05	; 5
	.db #0x03	; 3
	.db #0x06	; 6
	G$Update_SpriteSkeleton$0$0	= .
	.globl	G$Update_SpriteSkeleton$0$0
	C$SpriteSkeleton.c$41$1_1$188	= .
	.globl	C$SpriteSkeleton.c$41$1_1$188
;SpriteSkeleton.c:41: void UPDATE(){
;	---------------------------------
; Function Update_SpriteSkeleton
; ---------------------------------
_Update_SpriteSkeleton::
	C$SpriteSkeleton.c$42$1_0$188	= .
	.globl	C$SpriteSkeleton.c$42$1_0$188
;SpriteSkeleton.c:42: struct EnemyInfo* e_data = (struct EnemyInfo*) THIS->custom_data;
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	C$SpriteSkeleton.c$43$1_0$188	= .
	.globl	C$SpriteSkeleton.c$43$1_0$188
;SpriteSkeleton.c:43: if(e_data->e_configured == 0){
	ld	hl, #0x21
	add	hl,bc
	ld	a, (hl)
	or	a, a
	C$SpriteSkeleton.c$44$2_0$189	= .
	.globl	C$SpriteSkeleton.c$44$2_0$189
;SpriteSkeleton.c:44: return;
	ret	Z
	C$SpriteSkeleton.c$46$1_0$188	= .
	.globl	C$SpriteSkeleton.c$46$1_0$188
;SpriteSkeleton.c:46: e_management(THIS);
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	e, #b_e_management
	ld	hl, #_e_management
	call	___sdcc_bcall_ehl
	pop	hl
	C$SpriteSkeleton.c$47$1_0$188	= .
	.globl	C$SpriteSkeleton.c$47$1_0$188
;SpriteSkeleton.c:47: }
	C$SpriteSkeleton.c$47$1_0$188	= .
	.globl	C$SpriteSkeleton.c$47$1_0$188
	XG$Update_SpriteSkeleton$0$0	= .
	.globl	XG$Update_SpriteSkeleton$0$0
	ret
	G$skeleton_update_anim$0$0	= .
	.globl	G$skeleton_update_anim$0$0
	C$SpriteSkeleton.c$49$1_0$191	= .
	.globl	C$SpriteSkeleton.c$49$1_0$191
;SpriteSkeleton.c:49: void skeleton_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED{
;	---------------------------------
; Function skeleton_update_anim
; ---------------------------------
	b_skeleton_update_anim	= 255
_skeleton_update_anim::
	C$SpriteSkeleton.c$50$1_0$191	= .
	.globl	C$SpriteSkeleton.c$50$1_0$191
;SpriteSkeleton.c:50: switch(new_state){
	ld	a, #0x0c
	ldhl	sp,	#8
	sub	a, (hl)
	ret	C
	C$SpriteSkeleton.c$58$1_0$191	= .
	.globl	C$SpriteSkeleton.c$58$1_0$191
;SpriteSkeleton.c:58: s_enemy->mirror = V_MIRROR;
	dec	hl
	dec	hl
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	hl, #0x0010
	add	hl, de
	ld	c, l
	ld	b, h
	C$SpriteSkeleton.c$50$1_0$191	= .
	.globl	C$SpriteSkeleton.c$50$1_0$191
;SpriteSkeleton.c:50: switch(new_state){
	push	de
	ldhl	sp,	#10
	ld	e, (hl)
	ld	d, #0x00
	ld	hl, #00120$
	add	hl, de
	add	hl, de
	add	hl, de
	pop	de
	jp	(hl)
00120$:
	jp	00111$
	jp	00111$
	jp	00102$
	jp	00104$
	jp	00106$
	jp	00108$
	jp	00106$
	jp	00108$
	jp	00102$
	jp	00104$
	jp	00111$
	jp	00111$
	jp	00109$
	C$SpriteSkeleton.c$51$2_0$192	= .
	.globl	C$SpriteSkeleton.c$51$2_0$192
;SpriteSkeleton.c:51: case IDLE_UP: case WALK_UP: 
00102$:
	C$SpriteSkeleton.c$52$2_0$192	= .
	.globl	C$SpriteSkeleton.c$52$2_0$192
;SpriteSkeleton.c:52: SetSpriteAnim(s_enemy, a_skeleton_up, 6);
	ld	a, #0x06
	push	af
	inc	sp
	ld	bc, #_a_skeleton_up
	ldhl	sp,	#7
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	_SetSpriteAnim
	C$SpriteSkeleton.c$53$2_0$192	= .
	.globl	C$SpriteSkeleton.c$53$2_0$192
;SpriteSkeleton.c:53: break;
	ret
	C$SpriteSkeleton.c$54$2_0$192	= .
	.globl	C$SpriteSkeleton.c$54$2_0$192
;SpriteSkeleton.c:54: case IDLE_DOWN: case WALK_DOWN:
00104$:
	C$SpriteSkeleton.c$55$2_0$192	= .
	.globl	C$SpriteSkeleton.c$55$2_0$192
;SpriteSkeleton.c:55: SetSpriteAnim(s_enemy, a_skeleton_down, 6);
	ld	a, #0x06
	push	af
	inc	sp
	ld	bc, #_a_skeleton_down
	ldhl	sp,	#7
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	_SetSpriteAnim
	C$SpriteSkeleton.c$56$2_0$192	= .
	.globl	C$SpriteSkeleton.c$56$2_0$192
;SpriteSkeleton.c:56: break;
	ret
	C$SpriteSkeleton.c$57$2_0$192	= .
	.globl	C$SpriteSkeleton.c$57$2_0$192
;SpriteSkeleton.c:57: case IDLE_LEFT: case WALK_LEFT:
00106$:
	C$SpriteSkeleton.c$58$2_0$192	= .
	.globl	C$SpriteSkeleton.c$58$2_0$192
;SpriteSkeleton.c:58: s_enemy->mirror = V_MIRROR;
	ld	a, #0x02
	ld	(bc), a
	C$SpriteSkeleton.c$59$2_0$192	= .
	.globl	C$SpriteSkeleton.c$59$2_0$192
;SpriteSkeleton.c:59: SetSpriteAnim(s_enemy, a_skeleton_h, 8);
	ld	a, #0x08
	push	af
	inc	sp
	ld	bc, #_a_skeleton_h
	call	_SetSpriteAnim
	C$SpriteSkeleton.c$60$2_0$192	= .
	.globl	C$SpriteSkeleton.c$60$2_0$192
;SpriteSkeleton.c:60: break;
	ret
	C$SpriteSkeleton.c$61$2_0$192	= .
	.globl	C$SpriteSkeleton.c$61$2_0$192
;SpriteSkeleton.c:61: case IDLE_RIGHT: case WALK_RIGHT: 
00108$:
	C$SpriteSkeleton.c$62$2_0$192	= .
	.globl	C$SpriteSkeleton.c$62$2_0$192
;SpriteSkeleton.c:62: s_enemy->mirror = NO_MIRROR;
	xor	a, a
	ld	(bc), a
	C$SpriteSkeleton.c$63$2_0$192	= .
	.globl	C$SpriteSkeleton.c$63$2_0$192
;SpriteSkeleton.c:63: SetSpriteAnim(s_enemy, a_skeleton_h, 8);
	ld	a, #0x08
	push	af
	inc	sp
	ld	bc, #_a_skeleton_h
	call	_SetSpriteAnim
	C$SpriteSkeleton.c$64$2_0$192	= .
	.globl	C$SpriteSkeleton.c$64$2_0$192
;SpriteSkeleton.c:64: break;
	ret
	C$SpriteSkeleton.c$65$2_0$192	= .
	.globl	C$SpriteSkeleton.c$65$2_0$192
;SpriteSkeleton.c:65: case HIT:
00109$:
	C$SpriteSkeleton.c$66$2_0$192	= .
	.globl	C$SpriteSkeleton.c$66$2_0$192
;SpriteSkeleton.c:66: SetSpriteAnim(s_enemy, a_skeleton_repelled, 12);
	ld	a, #0x0c
	push	af
	inc	sp
	ld	bc, #_a_skeleton_repelled
	ldhl	sp,	#7
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	call	_SetSpriteAnim
	C$SpriteSkeleton.c$68$1_0$191	= .
	.globl	C$SpriteSkeleton.c$68$1_0$191
;SpriteSkeleton.c:68: }
00111$:
	C$SpriteSkeleton.c$69$1_0$191	= .
	.globl	C$SpriteSkeleton.c$69$1_0$191
;SpriteSkeleton.c:69: }
	C$SpriteSkeleton.c$69$1_0$191	= .
	.globl	C$SpriteSkeleton.c$69$1_0$191
	XG$skeleton_update_anim$0$0	= .
	.globl	XG$skeleton_update_anim$0$0
	ret
	G$Destroy_SpriteSkeleton$0$0	= .
	.globl	G$Destroy_SpriteSkeleton$0$0
	C$SpriteSkeleton.c$71$1_0$193	= .
	.globl	C$SpriteSkeleton.c$71$1_0$193
;SpriteSkeleton.c:71: void DESTROY(){
;	---------------------------------
; Function Destroy_SpriteSkeleton
; ---------------------------------
_Destroy_SpriteSkeleton::
	C$SpriteSkeleton.c$72$1_0$193	= .
	.globl	C$SpriteSkeleton.c$72$1_0$193
;SpriteSkeleton.c:72: e_destroy(THIS, THIS->type);
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #0x0013
	add	hl, bc
	ld	a, (hl)
	push	af
	inc	sp
	ld	hl, #_THIS
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	e, #b_e_destroy
	ld	hl, #_e_destroy
	call	___sdcc_bcall_ehl
	add	sp, #3
	C$SpriteSkeleton.c$73$1_0$193	= .
	.globl	C$SpriteSkeleton.c$73$1_0$193
;SpriteSkeleton.c:73: }
	C$SpriteSkeleton.c$73$1_0$193	= .
	.globl	C$SpriteSkeleton.c$73$1_0$193
	XG$Destroy_SpriteSkeleton$0$0	= .
	.globl	XG$Destroy_SpriteSkeleton$0$0
	ret
	.area _CODE_255
	.area _INITIALIZER
	.area _CABS (ABS)
