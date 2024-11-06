;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module UtilEnemy
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _Update_UtilEnemy
	.globl _Start_UtilEnemy
	.globl b_skeleton_update_anim
	.globl _skeleton_update_anim
	.globl _TranslateSprite
	.globl ___bank_UtilEnemy
	.globl b_e_start
	.globl _e_start
	.globl b_e_configure
	.globl _e_configure
	.globl b_e_update_anim
	.globl _e_update_anim
	.globl b_e_change_state
	.globl _e_change_state
	.globl b_e_management
	.globl _e_management
	.globl b_e_check_tile_collision
	.globl _e_check_tile_collision
	.globl b_e_turn
	.globl _e_turn
	.globl b_e_destroy
	.globl _e_destroy
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
	G$Start_UtilEnemy$0$0	= .
	.globl	G$Start_UtilEnemy$0$0
	C$UtilEnemy.c$33$0_0$189	= .
	.globl	C$UtilEnemy.c$33$0_0$189
;UtilEnemy.c:33: void START(){
;	---------------------------------
; Function Start_UtilEnemy
; ---------------------------------
_Start_UtilEnemy::
	C$UtilEnemy.c$34$0_0$189	= .
	.globl	C$UtilEnemy.c$34$0_0$189
;UtilEnemy.c:34: }
	C$UtilEnemy.c$34$0_0$189	= .
	.globl	C$UtilEnemy.c$34$0_0$189
	XG$Start_UtilEnemy$0$0	= .
	.globl	XG$Start_UtilEnemy$0$0
	ret
G$__bank_UtilEnemy$0_0$0 == 0x00ff
___bank_UtilEnemy	=	0x00ff
	G$e_start$0$0	= .
	.globl	G$e_start$0$0
	C$UtilEnemy.c$36$0_0$191	= .
	.globl	C$UtilEnemy.c$36$0_0$191
;UtilEnemy.c:36: void e_start(struct EnemyInfo* e_data, SPRITE_STATES new_state) BANKED{
;	---------------------------------
; Function e_start
; ---------------------------------
	b_e_start	= 255
_e_start::
	C$UtilEnemy.c$37$1_0$191	= .
	.globl	C$UtilEnemy.c$37$1_0$191
;UtilEnemy.c:37: e_data->e_state = new_state;
	ldhl	sp,	#6
	ld	a, (hl+)
	ld	c, a
	ld	a, (hl+)
	ld	b, a
	ld	a, (hl)
	ld	(bc), a
	C$UtilEnemy.c$38$1_0$191	= .
	.globl	C$UtilEnemy.c$38$1_0$191
;UtilEnemy.c:38: e_data->frmskip_wait = e_data->frmskip;
	ld	hl, #0x0005
	add	hl, bc
	ld	e, l
	ld	d, h
	ld	hl, #0x0007
	add	hl, bc
	ld	a, (hl)
	ld	(de), a
	C$UtilEnemy.c$39$1_0$191	= .
	.globl	C$UtilEnemy.c$39$1_0$191
;UtilEnemy.c:39: e_data->vx = 0;
	ld	e, c
	ld	d, b
	inc	de
	inc	de
	xor	a, a
	ld	(de), a
	C$UtilEnemy.c$40$1_0$191	= .
	.globl	C$UtilEnemy.c$40$1_0$191
;UtilEnemy.c:40: e_data->vy = 0;
	ld	e, c
	ld	d, b
	inc	de
	inc	de
	inc	de
	xor	a, a
	ld	(de), a
	C$UtilEnemy.c$41$1_0$191	= .
	.globl	C$UtilEnemy.c$41$1_0$191
;UtilEnemy.c:41: e_data->tile_collision = 0;
	ld	e, c
	ld	d, b
	inc	de
	xor	a, a
	ld	(de), a
	C$UtilEnemy.c$42$1_0$191	= .
	.globl	C$UtilEnemy.c$42$1_0$191
;UtilEnemy.c:42: e_data->wait = 0;
	ld	hl, #0x0004
	add	hl, bc
	ld	(hl), #0x00
	C$UtilEnemy.c$43$1_0$191	= .
	.globl	C$UtilEnemy.c$43$1_0$191
;UtilEnemy.c:43: e_data->e_configured = 0;
	ld	hl, #0x0006
	add	hl, bc
	ld	(hl), #0x00
	C$UtilEnemy.c$44$1_0$191	= .
	.globl	C$UtilEnemy.c$44$1_0$191
;UtilEnemy.c:44: }
	C$UtilEnemy.c$44$1_0$191	= .
	.globl	C$UtilEnemy.c$44$1_0$191
	XG$e_start$0$0	= .
	.globl	XG$e_start$0$0
	ret
	G$e_configure$0$0	= .
	.globl	G$e_configure$0$0
	C$UtilEnemy.c$46$1_0$193	= .
	.globl	C$UtilEnemy.c$46$1_0$193
;UtilEnemy.c:46: void e_configure(Sprite* s_enemy, UINT8 sprite_type) BANKED{
;	---------------------------------
; Function e_configure
; ---------------------------------
	b_e_configure	= 255
_e_configure::
	C$UtilEnemy.c$47$1_0$193	= .
	.globl	C$UtilEnemy.c$47$1_0$193
;UtilEnemy.c:47: e_update_anim(s_enemy, sprite_type);
	ldhl	sp,	#8
	ld	a, (hl-)
	dec	hl
	push	af
	inc	sp
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	e, #b_e_update_anim
	ld	hl, #_e_update_anim
	call	___sdcc_bcall_ehl
	add	sp, #3
	C$UtilEnemy.c$48$1_1$194	= .
	.globl	C$UtilEnemy.c$48$1_1$194
;UtilEnemy.c:48: struct EnemyInfo* e_data = (struct EnemyInfo*) s_enemy->custom_data;
	ldhl	sp,	#6
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	C$UtilEnemy.c$49$1_1$194	= .
	.globl	C$UtilEnemy.c$49$1_1$194
;UtilEnemy.c:49: e_data->e_configured = 1;
	ld	hl, #0x21
	add	hl,bc
	ld	(hl), #0x01
	C$UtilEnemy.c$50$1_1$193	= .
	.globl	C$UtilEnemy.c$50$1_1$193
;UtilEnemy.c:50: }
	C$UtilEnemy.c$50$1_1$193	= .
	.globl	C$UtilEnemy.c$50$1_1$193
	XG$e_configure$0$0	= .
	.globl	XG$e_configure$0$0
	ret
	G$e_update_anim$0$0	= .
	.globl	G$e_update_anim$0$0
	C$UtilEnemy.c$52$1_1$196	= .
	.globl	C$UtilEnemy.c$52$1_1$196
;UtilEnemy.c:52: void e_update_anim(Sprite* s_enemy, UINT8 sprite_type) BANKED{
;	---------------------------------
; Function e_update_anim
; ---------------------------------
	b_e_update_anim	= 255
_e_update_anim::
	C$UtilEnemy.c$53$1_0$196	= .
	.globl	C$UtilEnemy.c$53$1_0$196
;UtilEnemy.c:53: struct EnemyInfo* e_data = (struct EnemyInfo*) s_enemy->custom_data;
	ldhl	sp,	#6
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #0x001b
	add	hl, bc
	ld	e, l
	ld	d, h
	C$UtilEnemy.c$54$1_0$196	= .
	.globl	C$UtilEnemy.c$54$1_0$196
;UtilEnemy.c:54: switch(sprite_type){
	ldhl	sp,	#8
	ld	a, (hl)
	sub	a, #0x02
	ret	NZ
	C$UtilEnemy.c$56$2_0$197	= .
	.globl	C$UtilEnemy.c$56$2_0$197
;UtilEnemy.c:56: skeleton_update_anim(s_enemy, e_data->e_state);
	ld	a, (de)
	push	af
	inc	sp
	push	bc
	ld	e, #b_skeleton_update_anim
	ld	hl, #_skeleton_update_anim
	call	___sdcc_bcall_ehl
	add	sp, #3
	C$UtilEnemy.c$58$1_0$196	= .
	.globl	C$UtilEnemy.c$58$1_0$196
;UtilEnemy.c:58: }
	C$UtilEnemy.c$59$1_0$196	= .
	.globl	C$UtilEnemy.c$59$1_0$196
;UtilEnemy.c:59: }
	C$UtilEnemy.c$59$1_0$196	= .
	.globl	C$UtilEnemy.c$59$1_0$196
	XG$e_update_anim$0$0	= .
	.globl	XG$e_update_anim$0$0
	ret
	G$e_change_state$0$0	= .
	.globl	G$e_change_state$0$0
	C$UtilEnemy.c$61$1_0$199	= .
	.globl	C$UtilEnemy.c$61$1_0$199
;UtilEnemy.c:61: void e_change_state(Sprite* s_enemy, SPRITE_STATES new_state, UINT8 e_sprite_type) BANKED{
;	---------------------------------
; Function e_change_state
; ---------------------------------
	b_e_change_state	= 255
_e_change_state::
	add	sp, #-7
	C$UtilEnemy.c$62$1_0$199	= .
	.globl	C$UtilEnemy.c$62$1_0$199
;UtilEnemy.c:62: struct EnemyInfo* e_data = (struct EnemyInfo*) s_enemy->custom_data;
	ldhl	sp,	#13
	ld	a, (hl)
	ldhl	sp,	#0
	ld	(hl), a
	ldhl	sp,	#14
	ld	a, (hl)
	ldhl	sp,	#1
	ld	(hl), a
	pop	de
	push	de
	ld	hl, #0x001b
	add	hl, de
	ld	c, l
	ld	a, h
	ldhl	sp,	#2
	ld	(hl), c
	inc	hl
	C$UtilEnemy.c$63$1_0$199	= .
	.globl	C$UtilEnemy.c$63$1_0$199
;UtilEnemy.c:63: if(e_data->e_state == new_state){
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	c, a
	ldhl	sp,	#15
	ld	a, (hl)
	sub	a, c
	jp	Z,00122$
	C$UtilEnemy.c$64$2_0$200	= .
	.globl	C$UtilEnemy.c$64$2_0$200
;UtilEnemy.c:64: return;
	jr	00102$
00102$:
	C$UtilEnemy.c$66$1_0$199	= .
	.globl	C$UtilEnemy.c$66$1_0$199
;UtilEnemy.c:66: switch(new_state){
	ld	a, #0x0c
	ldhl	sp,	#15
	sub	a, (hl)
	jp	C, 00116$
	C$UtilEnemy.c$67$1_0$199	= .
	.globl	C$UtilEnemy.c$67$1_0$199
;UtilEnemy.c:67: case WALK_DOWN: e_data->wait = 0; e_data->vx = 0; e_data->vy = 1;break;
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0004
	add	hl, de
	ld	c, l
	ld	b, h
	ldhl	sp,	#2
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl-)
	ld	d, a
	inc	de
	inc	de
	push	de
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0003
	add	hl, de
	pop	de
	push	hl
	ld	a, l
	ldhl	sp,	#6
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#5
	ld	(hl), a
	C$UtilEnemy.c$72$1_0$199	= .
	.globl	C$UtilEnemy.c$72$1_0$199
;UtilEnemy.c:72: switch(e_sprite_type){
	ldhl	sp,	#16
	ld	a, (hl)
	sub	a, #0x02
	ld	a, #0x01
	jr	Z, 00169$
	xor	a, a
00169$:
	ldhl	sp,	#6
	ld	(hl), a
	C$UtilEnemy.c$66$1_0$199	= .
	.globl	C$UtilEnemy.c$66$1_0$199
;UtilEnemy.c:66: switch(new_state){
	push	de
	ldhl	sp,	#17
	ld	e, (hl)
	ld	d, #0x00
	ld	hl, #00170$
	add	hl, de
	add	hl, de
	add	hl, de
	pop	de
	jp	(hl)
00170$:
	jp	00116$
	jp	00116$
	jp	00110$
	jp	00110$
	jp	00110$
	jp	00110$
	jp	00106$
	jp	00105$
	jp	00104$
	jp	00103$
	jp	00116$
	jp	00116$
	jp	00113$
	C$UtilEnemy.c$67$2_0$201	= .
	.globl	C$UtilEnemy.c$67$2_0$201
;UtilEnemy.c:67: case WALK_DOWN: e_data->wait = 0; e_data->vx = 0; e_data->vy = 1;break;
00103$:
	xor	a, a
	ld	(bc), a
	xor	a, a
	ld	(de), a
	ldhl	sp,	#4
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	(hl), #0x01
	jr	00116$
	C$UtilEnemy.c$68$2_0$201	= .
	.globl	C$UtilEnemy.c$68$2_0$201
;UtilEnemy.c:68: case WALK_UP: e_data->wait = 0; e_data->vx = 0; e_data->vy = -1;break;
00104$:
	xor	a, a
	ld	(bc), a
	xor	a, a
	ld	(de), a
	ldhl	sp,	#4
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	(hl), #0xff
	jr	00116$
	C$UtilEnemy.c$69$2_0$201	= .
	.globl	C$UtilEnemy.c$69$2_0$201
;UtilEnemy.c:69: case WALK_RIGHT: e_data->wait = 0; e_data->vx = 1; e_data->vy = 0; break;
00105$:
	xor	a, a
	ld	(bc), a
	ld	a, #0x01
	ld	(de), a
	ldhl	sp,	#4
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	(hl), #0x00
	jr	00116$
	C$UtilEnemy.c$70$2_0$201	= .
	.globl	C$UtilEnemy.c$70$2_0$201
;UtilEnemy.c:70: case WALK_LEFT: e_data->wait = 0; e_data->vx = -1; e_data->vy = 0; break;
00106$:
	xor	a, a
	ld	(bc), a
	ld	a, #0xff
	ld	(de), a
	ldhl	sp,	#4
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	(hl), #0x00
	jr	00116$
	C$UtilEnemy.c$71$2_0$201	= .
	.globl	C$UtilEnemy.c$71$2_0$201
;UtilEnemy.c:71: case IDLE_DOWN: case IDLE_UP: case IDLE_LEFT: case IDLE_RIGHT:
00110$:
	C$UtilEnemy.c$72$2_0$201	= .
	.globl	C$UtilEnemy.c$72$2_0$201
;UtilEnemy.c:72: switch(e_sprite_type){
	ldhl	sp,	#6
	ld	a, (hl)
	or	a, a
	jr	Z, 00116$
	C$UtilEnemy.c$74$3_0$202	= .
	.globl	C$UtilEnemy.c$74$3_0$202
;UtilEnemy.c:74: e_data->wait = 160u;
	ld	a, #0xa0
	ld	(bc), a
	C$UtilEnemy.c$77$2_0$201	= .
	.globl	C$UtilEnemy.c$77$2_0$201
;UtilEnemy.c:77: break;
	jr	00116$
	C$UtilEnemy.c$78$2_0$201	= .
	.globl	C$UtilEnemy.c$78$2_0$201
;UtilEnemy.c:78: case HIT:
00113$:
	C$UtilEnemy.c$79$2_0$201	= .
	.globl	C$UtilEnemy.c$79$2_0$201
;UtilEnemy.c:79: switch(e_sprite_type){
	ldhl	sp,	#6
	ld	a, (hl)
	or	a, a
	jr	Z, 00116$
	C$UtilEnemy.c$81$3_0$203	= .
	.globl	C$UtilEnemy.c$81$3_0$203
;UtilEnemy.c:81: e_data->wait = orpheus_wait;
	ld	a, (#_orpheus_wait)
	ld	(bc), a
	C$UtilEnemy.c$85$1_0$199	= .
	.globl	C$UtilEnemy.c$85$1_0$199
;UtilEnemy.c:85: }
00116$:
	C$UtilEnemy.c$86$1_0$199	= .
	.globl	C$UtilEnemy.c$86$1_0$199
;UtilEnemy.c:86: switch(e_data->e_state){
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	or	a, a
	jr	NZ, 00121$
	C$UtilEnemy.c$88$2_0$204	= .
	.globl	C$UtilEnemy.c$88$2_0$204
;UtilEnemy.c:88: if(s_orpheus->x > s_enemy->x){new_state = IDLE_RIGHT;}
	ld	hl, #_s_orpheus
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #0x000c
	add	hl, bc
	ld	e, l
	ld	d, h
	ld	a, (de)
	ldhl	sp,	#5
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	pop	de
	push	de
	ld	hl, #0x000c
	add	hl, de
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ldhl	sp,	#5
	ld	a, c
	sub	a, (hl)
	inc	hl
	ld	a, b
	sbc	a, (hl)
	jr	NC, 00119$
	ldhl	sp,	#15
	ld	(hl), #0x05
	jr	00121$
00119$:
	C$UtilEnemy.c$89$3_0$206	= .
	.globl	C$UtilEnemy.c$89$3_0$206
;UtilEnemy.c:89: else{new_state = IDLE_LEFT;}
	ldhl	sp,	#15
	ld	(hl), #0x04
	C$UtilEnemy.c$91$1_0$199	= .
	.globl	C$UtilEnemy.c$91$1_0$199
;UtilEnemy.c:91: }
00121$:
	C$UtilEnemy.c$92$1_0$199	= .
	.globl	C$UtilEnemy.c$92$1_0$199
;UtilEnemy.c:92: e_data->e_state = new_state;
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ldhl	sp,	#15
	C$UtilEnemy.c$93$1_0$199	= .
	.globl	C$UtilEnemy.c$93$1_0$199
;UtilEnemy.c:93: e_update_anim(s_enemy, e_sprite_type);
	ld	a, (hl+)
	ld	(de), a
	ld	a, (hl)
	push	af
	inc	sp
	ldhl	sp,	#1
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	e, #b_e_update_anim
	ld	hl, #_e_update_anim
	call	___sdcc_bcall_ehl
	add	sp, #3
00122$:
	C$UtilEnemy.c$94$1_0$199	= .
	.globl	C$UtilEnemy.c$94$1_0$199
;UtilEnemy.c:94: }
	add	sp, #7
	C$UtilEnemy.c$94$1_0$199	= .
	.globl	C$UtilEnemy.c$94$1_0$199
	XG$e_change_state$0$0	= .
	.globl	XG$e_change_state$0$0
	ret
	G$e_management$0$0	= .
	.globl	G$e_management$0$0
	C$UtilEnemy.c$96$1_0$208	= .
	.globl	C$UtilEnemy.c$96$1_0$208
;UtilEnemy.c:96: void e_management(Sprite* s_enemy) BANKED{
;	---------------------------------
; Function e_management
; ---------------------------------
	b_e_management	= 255
_e_management::
	add	sp, #-23
	C$UtilEnemy.c$97$1_0$208	= .
	.globl	C$UtilEnemy.c$97$1_0$208
;UtilEnemy.c:97: struct EnemyInfo* e_data = (struct EnemyInfo*) s_enemy->custom_data;
	ldhl	sp,	#29
	ld	a, (hl)
	ldhl	sp,	#0
	ld	(hl), a
	ldhl	sp,	#30
	ld	a, (hl)
	ldhl	sp,	#1
	ld	(hl), a
	pop	de
	push	de
	ld	hl, #0x001b
	add	hl, de
	ld	c, l
	ld	a, h
	ldhl	sp,	#2
	ld	(hl), c
	inc	hl
	ld	(hl), a
	C$UtilEnemy.c$98$1_0$208	= .
	.globl	C$UtilEnemy.c$98$1_0$208
;UtilEnemy.c:98: UINT8 e_sprite_type = s_enemy->type;
	pop	de
	push	de
	ld	hl, #0x0013
	add	hl, de
	ld	c, l
	ld	b, h
	ld	a, (bc)
	ldhl	sp,	#4
	C$UtilEnemy.c$99$1_0$208	= .
	.globl	C$UtilEnemy.c$99$1_0$208
;UtilEnemy.c:99: if(e_data->frmskip_wait > 0){
	ld	(hl-), a
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0005
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#7
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#6
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	or	a, a
	jr	Z, 00102$
	C$UtilEnemy.c$100$2_0$209	= .
	.globl	C$UtilEnemy.c$100$2_0$209
;UtilEnemy.c:100: e_data->frmskip_wait--;
	ld	c, a
	dec	c
	ld	a, (hl-)
	ld	l, (hl)
	ld	h, a
	ld	(hl), c
00102$:
	C$UtilEnemy.c$102$1_0$208	= .
	.globl	C$UtilEnemy.c$102$1_0$208
;UtilEnemy.c:102: if(e_data->e_state != WALK_DOWN && e_data->e_state != WALK_UP && 
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	C$UtilEnemy.c$105$1_0$208	= .
	.globl	C$UtilEnemy.c$105$1_0$208
;UtilEnemy.c:105: if(e_data->wait > 0){
	ld	a, (hl-)
	ld	d, a
	ld	a, (de)
	ld	c, a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0004
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#9
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#8
	ld	(hl), a
	C$UtilEnemy.c$102$1_0$208	= .
	.globl	C$UtilEnemy.c$102$1_0$208
;UtilEnemy.c:102: if(e_data->e_state != WALK_DOWN && e_data->e_state != WALK_UP && 
	ld	a,c
	cp	a,#0x09
	jr	Z, 00107$
	C$UtilEnemy.c$103$1_0$208	= .
	.globl	C$UtilEnemy.c$103$1_0$208
;UtilEnemy.c:103: e_data->e_state != WALK_LEFT && e_data->e_state != WALK_RIGHT &&
	cp	a,#0x08
	jr	Z, 00107$
	cp	a,#0x06
	jr	Z, 00107$
	C$UtilEnemy.c$104$1_0$208	= .
	.globl	C$UtilEnemy.c$104$1_0$208
;UtilEnemy.c:104: e_data->e_state != HIT){
	cp	a,#0x07
	jr	Z, 00107$
	sub	a, #0x0c
	jr	Z, 00107$
	C$UtilEnemy.c$105$2_0$210	= .
	.globl	C$UtilEnemy.c$105$2_0$210
;UtilEnemy.c:105: if(e_data->wait > 0){
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	or	a, a
	jr	Z, 00104$
	C$UtilEnemy.c$106$3_0$211	= .
	.globl	C$UtilEnemy.c$106$3_0$211
;UtilEnemy.c:106: e_data->wait--;
	ld	c, a
	dec	c
	ld	a, (hl-)
	ld	l, (hl)
	ld	h, a
	ld	(hl), c
	jr	00107$
00104$:
	C$UtilEnemy.c$108$3_0$212	= .
	.globl	C$UtilEnemy.c$108$3_0$212
;UtilEnemy.c:108: e_turn(s_enemy, e_sprite_type);
	ldhl	sp,	#4
	ld	a, (hl)
	push	af
	inc	sp
	ldhl	sp,	#1
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	push	de
	ld	e, #b_e_turn
	ld	hl, #_e_turn
	call	___sdcc_bcall_ehl
	add	sp, #3
00107$:
	C$UtilEnemy.c$111$1_0$208	= .
	.globl	C$UtilEnemy.c$111$1_0$208
;UtilEnemy.c:111: if(e_data->e_state == HIT){
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	C$UtilEnemy.c$119$1_0$208	= .
	.globl	C$UtilEnemy.c$119$1_0$208
;UtilEnemy.c:119: e_data->vx = 2;
	ld	a, (hl-)
	ld	d, a
	ld	a, (de)
	ld	c, a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0002
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#11
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#10
	ld	(hl), a
	C$UtilEnemy.c$120$1_0$208	= .
	.globl	C$UtilEnemy.c$120$1_0$208
;UtilEnemy.c:120: e_data->vy = 2;
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0003
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#13
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#12
	ld	(hl), a
	C$UtilEnemy.c$126$1_0$208	= .
	.globl	C$UtilEnemy.c$126$1_0$208
;UtilEnemy.c:126: if(s_orpheus->y < s_enemy->y){
	pop	de
	push	de
	ld	hl, #0x000e
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#15
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#14
	ld	(hl), a
	C$UtilEnemy.c$111$1_0$208	= .
	.globl	C$UtilEnemy.c$111$1_0$208
;UtilEnemy.c:111: if(e_data->e_state == HIT){
	ld	a, c
	sub	a, #0x0c
	jp	NZ,00134$
	C$UtilEnemy.c$114$3_0$214	= .
	.globl	C$UtilEnemy.c$114$3_0$214
;UtilEnemy.c:114: if(s_enemy->anim_frame == 3){
	pop	de
	push	de
	ld	hl, #0x0009
	add	hl, de
	ld	c, l
	ld	b, h
	ld	a, (bc)
	ld	c, a
	C$UtilEnemy.c$115$1_0$208	= .
	.globl	C$UtilEnemy.c$115$1_0$208
;UtilEnemy.c:115: s_enemy->mirror = V_MIRROR;
	pop	de
	push	de
	ld	hl, #0x0010
	add	hl, de
	ld	e, l
	ld	d, h
	C$UtilEnemy.c$114$3_0$214	= .
	.globl	C$UtilEnemy.c$114$3_0$214
;UtilEnemy.c:114: if(s_enemy->anim_frame == 3){
	ld	a, c
	sub	a, #0x03
	jr	NZ, 00113$
	C$UtilEnemy.c$115$4_0$215	= .
	.globl	C$UtilEnemy.c$115$4_0$215
;UtilEnemy.c:115: s_enemy->mirror = V_MIRROR;
	ld	a, #0x02
	ld	(de), a
	jr	00114$
00113$:
	C$UtilEnemy.c$116$4_0$216	= .
	.globl	C$UtilEnemy.c$116$4_0$216
;UtilEnemy.c:116: }else{s_enemy->mirror = NO_MIRROR;}
	xor	a, a
	ld	(de), a
00114$:
	C$UtilEnemy.c$119$3_1$217	= .
	.globl	C$UtilEnemy.c$119$3_1$217
;UtilEnemy.c:119: e_data->vx = 2;
	ldhl	sp,	#9
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	(hl), #0x02
	C$UtilEnemy.c$120$3_1$217	= .
	.globl	C$UtilEnemy.c$120$3_1$217
;UtilEnemy.c:120: e_data->vy = 2;
	ldhl	sp,	#11
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	(hl), #0x02
	C$UtilEnemy.c$121$1_0$208	= .
	.globl	C$UtilEnemy.c$121$1_0$208
;UtilEnemy.c:121: if(s_orpheus->x < s_enemy->x){
	ld	a, (#_s_orpheus)
	ldhl	sp,	#15
	ld	(hl), a
	ld	a, (#_s_orpheus + 1)
	ldhl	sp,	#16
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x000c
	add	hl, de
	ld	c, l
	ld	b, h
	ld	e, c
	ld	d, b
	ld	a, (de)
	ldhl	sp,	#17
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	pop	de
	push	de
	ld	hl, #0x000c
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#23
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#22
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ldhl	sp,	#19
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	ldhl	sp,	#17
	ld	e, l
	ld	d, h
	ldhl	sp,	#19
	ld	a, (de)
	inc	de
	sub	a, (hl)
	inc	hl
	ld	a, (de)
	sbc	a, (hl)
	jr	NC, 00116$
	C$UtilEnemy.c$122$4_1$218	= .
	.globl	C$UtilEnemy.c$122$4_1$218
;UtilEnemy.c:122: e_data->vx = -2;
	ldhl	sp,	#9
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	(hl), #0xfe
	C$UtilEnemy.c$123$4_1$218	= .
	.globl	C$UtilEnemy.c$123$4_1$218
;UtilEnemy.c:123: delta_x = s_enemy->x - s_orpheus->x;
	ldhl	sp,#21
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ldhl	sp,	#18
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	C$UtilEnemy.c$121$1_0$208	= .
	.globl	C$UtilEnemy.c$121$1_0$208
;UtilEnemy.c:121: if(s_orpheus->x < s_enemy->x){
	ld	a, (#_s_orpheus)
	ldhl	sp,	#15
	ld	(hl), a
	ld	a, (#_s_orpheus + 1)
	ldhl	sp,	#16
	C$UtilEnemy.c$123$4_1$218	= .
	.globl	C$UtilEnemy.c$123$4_1$218
;UtilEnemy.c:123: delta_x = s_enemy->x - s_orpheus->x;
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x000c
	add	hl, de
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ldhl	sp,#18
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, e
	sub	a, c
	ld	e, a
	ld	a, d
	sbc	a, b
	ldhl	sp,	#22
	ld	(hl-), a
	ld	(hl), e
	jr	00117$
00116$:
	C$UtilEnemy.c$124$4_1$219	= .
	.globl	C$UtilEnemy.c$124$4_1$219
;UtilEnemy.c:124: }else{delta_x = s_orpheus->x - s_enemy->x;}
	ldhl	sp,#17
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl+)
	ld	d, a
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ldhl	sp,	#22
	ld	(hl-), a
	ld	(hl), e
00117$:
	C$UtilEnemy.c$126$1_0$208	= .
	.globl	C$UtilEnemy.c$126$1_0$208
;UtilEnemy.c:126: if(s_orpheus->y < s_enemy->y){
	ldhl	sp,#15
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x000e
	add	hl, de
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ldhl	sp,#13
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ldhl	sp,	#17
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl-), a
	ld	a, c
	sub	a, (hl)
	inc	hl
	ld	a, b
	sbc	a, (hl)
	jr	NC, 00119$
	C$UtilEnemy.c$127$4_2$221	= .
	.globl	C$UtilEnemy.c$127$4_2$221
;UtilEnemy.c:127: e_data->vy = -2;
	ldhl	sp,	#11
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	(hl), #0xfe
	C$UtilEnemy.c$128$4_2$221	= .
	.globl	C$UtilEnemy.c$128$4_2$221
;UtilEnemy.c:128: delta_y = s_enemy->y - s_orpheus->y;
	ldhl	sp,#13
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ldhl	sp,	#17
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	ld	hl, #_s_orpheus
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #0x000e
	add	hl, bc
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ldhl	sp,#17
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl+)
	inc	hl
	ld	d, a
	ld	a, e
	sub	a, c
	ld	e, a
	ld	a, d
	sbc	a, b
	ld	(hl-), a
	ld	(hl), e
	jr	00120$
00119$:
	C$UtilEnemy.c$130$4_2$222	= .
	.globl	C$UtilEnemy.c$130$4_2$222
;UtilEnemy.c:130: delta_y = s_orpheus->y - s_enemy->y;
	ldhl	sp,#17
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl+)
	inc	hl
	ld	d, a
	ld	a, c
	sub	a, e
	ld	e, a
	ld	a, b
	sbc	a, d
	ld	(hl-), a
	ld	(hl), e
00120$:
	C$UtilEnemy.c$132$3_2$220	= .
	.globl	C$UtilEnemy.c$132$3_2$220
;UtilEnemy.c:132: if((delta_x << 1) < delta_y){
	ldhl	sp,#21
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	sla	c
	rl	b
	ldhl	sp,	#19
	ld	a, c
	sub	a, (hl)
	inc	hl
	ld	a, b
	sbc	a, (hl)
	jr	NC, 00124$
	C$UtilEnemy.c$133$4_2$223	= .
	.globl	C$UtilEnemy.c$133$4_2$223
;UtilEnemy.c:133: e_data->vy = e_data->vy*2;
	ldhl	sp,#11
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	add	a, a
	ld	c, a
	ld	a, (hl-)
	ld	l, (hl)
	ld	h, a
	ld	(hl), c
	C$UtilEnemy.c$134$4_2$223	= .
	.globl	C$UtilEnemy.c$134$4_2$223
;UtilEnemy.c:134: e_data->vx = 0;
	ldhl	sp,	#9
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	(hl), #0x00
	jr	00125$
00124$:
	C$UtilEnemy.c$135$3_2$220	= .
	.globl	C$UtilEnemy.c$135$3_2$220
;UtilEnemy.c:135: }else if((delta_y <<1) < delta_x){
	ldhl	sp,#19
	ld	a, (hl+)
	ld	c, a
	ld	a, (hl+)
	ld	b, a
	sla	c
	rl	b
	ld	a, c
	sub	a, (hl)
	inc	hl
	ld	a, b
	sbc	a, (hl)
	jr	NC, 00125$
	C$UtilEnemy.c$136$4_2$224	= .
	.globl	C$UtilEnemy.c$136$4_2$224
;UtilEnemy.c:136: e_data->vx = e_data->vx*2;
	ldhl	sp,#9
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	add	a, a
	ld	c, a
	ld	a, (hl-)
	ld	l, (hl)
	ld	h, a
	ld	(hl), c
	C$UtilEnemy.c$137$4_2$224	= .
	.globl	C$UtilEnemy.c$137$4_2$224
;UtilEnemy.c:137: e_data->vy = 0;
	ldhl	sp,	#11
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	(hl), #0x00
00125$:
	C$UtilEnemy.c$139$3_2$220	= .
	.globl	C$UtilEnemy.c$139$3_2$220
;UtilEnemy.c:139: switch(song_selection){
	ld	a, (#_song_selection)
	or	a, a
	jr	Z, 00129$
	ld	a, (#_song_selection)
	dec	a
	jr	Z, 00128$
	ld	a, (#_song_selection)
	sub	a, #0x02
	jr	NZ, 00129$
	C$UtilEnemy.c$142$4_2$225	= .
	.globl	C$UtilEnemy.c$142$4_2$225
;UtilEnemy.c:142: e_data->vx = -e_data->vx;
	ldhl	sp,#9
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	c, a
	xor	a, a
	sub	a, c
	ld	c, a
	ld	a, (hl-)
	ld	l, (hl)
	ld	h, a
	ld	(hl), c
	C$UtilEnemy.c$143$4_2$225	= .
	.globl	C$UtilEnemy.c$143$4_2$225
;UtilEnemy.c:143: e_data->vy = -e_data->vy;
	ldhl	sp,#11
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	c, a
	xor	a, a
	sub	a, c
	ld	c, a
	ld	a, (hl-)
	ld	l, (hl)
	ld	h, a
	ld	(hl), c
	C$UtilEnemy.c$144$4_2$225	= .
	.globl	C$UtilEnemy.c$144$4_2$225
;UtilEnemy.c:144: break;
	jr	00129$
	C$UtilEnemy.c$145$4_2$225	= .
	.globl	C$UtilEnemy.c$145$4_2$225
;UtilEnemy.c:145: case SLEEP:
00128$:
	C$UtilEnemy.c$146$4_2$225	= .
	.globl	C$UtilEnemy.c$146$4_2$225
;UtilEnemy.c:146: e_data->vx = 0;
	ldhl	sp,	#9
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	(hl), #0x00
	C$UtilEnemy.c$147$4_2$225	= .
	.globl	C$UtilEnemy.c$147$4_2$225
;UtilEnemy.c:147: e_data->vy = 0;
	ldhl	sp,	#11
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	(hl), #0x00
	C$UtilEnemy.c$149$3_2$220	= .
	.globl	C$UtilEnemy.c$149$3_2$220
;UtilEnemy.c:149: }
00129$:
	C$UtilEnemy.c$151$2_0$213	= .
	.globl	C$UtilEnemy.c$151$2_0$213
;UtilEnemy.c:151: if(e_data->wait > 0){
	ldhl	sp,#7
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	or	a, a
	jr	Z, 00131$
	C$UtilEnemy.c$152$3_0$226	= .
	.globl	C$UtilEnemy.c$152$3_0$226
;UtilEnemy.c:152: e_data->wait--;
	ld	c, a
	dec	c
	ld	a, (hl-)
	ld	l, (hl)
	ld	h, a
	ld	(hl), c
	jr	00135$
00131$:
	C$UtilEnemy.c$154$3_0$227	= .
	.globl	C$UtilEnemy.c$154$3_0$227
;UtilEnemy.c:154: e_change_state(s_enemy, GENERIC_WALK, e_sprite_type);
	ldhl	sp,	#4
	ld	a, (hl)
	push	af
	inc	sp
	ld	a, #0x01
	push	af
	inc	sp
	ldhl	sp,	#2
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	push	de
	ld	e, #b_e_change_state
	ld	hl, #_e_change_state
	call	___sdcc_bcall_ehl
	add	sp, #4
	jr	00135$
00134$:
	C$UtilEnemy.c$157$2_0$228	= .
	.globl	C$UtilEnemy.c$157$2_0$228
;UtilEnemy.c:157: e_data->wait++;//USING AS RANDOM TO CLOCKWISE TURNING
	ldhl	sp,#7
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	c, a
	inc	c
	ld	a, (hl-)
	ld	l, (hl)
	ld	h, a
	ld	(hl), c
00135$:
	C$UtilEnemy.c$159$1_0$208	= .
	.globl	C$UtilEnemy.c$159$1_0$208
;UtilEnemy.c:159: if(e_data->frmskip_wait == 0){
	ldhl	sp,#5
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ldhl	sp,	#22
	ld	(hl), a
	or	a, a
	jp	NZ, 00155$
	C$UtilEnemy.c$160$2_0$229	= .
	.globl	C$UtilEnemy.c$160$2_0$229
;UtilEnemy.c:160: e_data->frmskip_wait = e_data->frmskip;
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0007
	add	hl, de
	ld	c, l
	ld	b, h
	ld	a, (bc)
	ld	c, a
	ldhl	sp,	#5
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	(hl), c
	C$UtilEnemy.c$161$2_0$229	= .
	.globl	C$UtilEnemy.c$161$2_0$229
;UtilEnemy.c:161: switch (e_data->e_state){
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ldhl	sp,	#22
	ld	(hl), a
	sub	a, #0x06
	jr	Z, 00137$
	ldhl	sp,	#22
	ld	a, (hl)
	sub	a, #0x07
	jp	NZ,00144$
	C$UtilEnemy.c$163$3_0$230	= .
	.globl	C$UtilEnemy.c$163$3_0$230
;UtilEnemy.c:163: case WALK_RIGHT:
00137$:
	C$UtilEnemy.c$164$3_0$230	= .
	.globl	C$UtilEnemy.c$164$3_0$230
;UtilEnemy.c:164: if(e_data->wait < 100){//check if Orpheus is over or above enemy
	ldhl	sp,#7
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	sub	a, #0x64
	jp	NC, 00144$
	C$UtilEnemy.c$165$4_0$231	= .
	.globl	C$UtilEnemy.c$165$4_0$231
;UtilEnemy.c:165: INT8 delta_y = s_enemy->y - s_orpheus->y; 
	ldhl	sp,#13
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ldhl	sp,	#22
	ld	(hl), a
	ld	a, (#_s_orpheus)
	ldhl	sp,	#18
	ld	(hl), a
	ld	a, (#_s_orpheus + 1)
	ldhl	sp,	#19
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x000e
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#22
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#21
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl+)
	ld	d, a
	ld	a, (de)
	ld	c, a
	ld	a, (hl)
	sub	a, c
	ld	c, a
	C$UtilEnemy.c$166$4_0$231	= .
	.globl	C$UtilEnemy.c$166$4_0$231
;UtilEnemy.c:166: if(delta_y > 40){//enemy molto sotto orpheus
	ld	e, c
	ld	a,#0x28
	ld	d,a
	sub	a, c
	bit	7, e
	jr	Z, 00364$
	bit	7, d
	jr	NZ, 00365$
	cp	a, a
	jr	00365$
00364$:
	bit	7, d
	jr	Z, 00365$
	scf
00365$:
	jr	NC, 00139$
	C$UtilEnemy.c$167$5_0$232	= .
	.globl	C$UtilEnemy.c$167$5_0$232
;UtilEnemy.c:167: e_change_state(s_enemy, WALK_UP, e_sprite_type);
	push	bc
	ldhl	sp,	#6
	ld	a, (hl)
	push	af
	inc	sp
	ld	a, #0x08
	push	af
	inc	sp
	ldhl	sp,	#4
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	push	de
	ld	e, #b_e_change_state
	ld	hl, #_e_change_state
	call	___sdcc_bcall_ehl
	add	sp, #4
	pop	bc
00139$:
	C$UtilEnemy.c$169$4_0$231	= .
	.globl	C$UtilEnemy.c$169$4_0$231
;UtilEnemy.c:169: if(delta_y < -40){//enemy molto sopra orpheus
	ld	a, c
	xor	a, #0x80
	sub	a, #0x58
	jr	NC, 00144$
	C$UtilEnemy.c$170$5_0$233	= .
	.globl	C$UtilEnemy.c$170$5_0$233
;UtilEnemy.c:170: e_change_state(s_enemy, WALK_DOWN, e_sprite_type);
	ldhl	sp,	#4
	ld	a, (hl)
	push	af
	inc	sp
	ld	a, #0x09
	push	af
	inc	sp
	ldhl	sp,	#2
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	push	de
	ld	e, #b_e_change_state
	ld	hl, #_e_change_state
	call	___sdcc_bcall_ehl
	add	sp, #4
	C$UtilEnemy.c$174$2_0$229	= .
	.globl	C$UtilEnemy.c$174$2_0$229
;UtilEnemy.c:174: }
00144$:
	C$UtilEnemy.c$175$2_0$229	= .
	.globl	C$UtilEnemy.c$175$2_0$229
;UtilEnemy.c:175: switch (e_data->e_state){
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	cp	a, #0x06
	jr	Z, 00149$
	cp	a, #0x07
	jr	Z, 00149$
	cp	a, #0x08
	jr	Z, 00149$
	cp	a, #0x09
	jr	Z, 00149$
	sub	a, #0x0c
	jr	NZ, 00155$
	C$UtilEnemy.c$180$3_0$234	= .
	.globl	C$UtilEnemy.c$180$3_0$234
;UtilEnemy.c:180: case HIT:
00149$:
	C$UtilEnemy.c$181$3_0$234	= .
	.globl	C$UtilEnemy.c$181$3_0$234
;UtilEnemy.c:181: e_data->tile_collision = TranslateSprite(THIS, e_data->vx, e_data->vy);
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	l, e
	ld	h, d
	inc	hl
	push	hl
	ld	a, l
	ldhl	sp,	#23
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#22
	ld	(hl), a
	ldhl	sp,#11
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl-)
	dec	hl
	dec	hl
	ld	d, a
	ld	a, (de)
	ld	b, a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ldhl	sp,	#20
	ld	(hl), a
	push	bc
	inc	sp
	ld	a, (hl)
	ld	hl, #_THIS
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	call	_TranslateSprite
	ldhl	sp,	#20
	ld	(hl), a
	ldhl	sp,#21
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl-)
	dec	hl
	ld	d, a
	ld	a, (hl)
	ld	(de), a
	C$UtilEnemy.c$182$3_0$234	= .
	.globl	C$UtilEnemy.c$182$3_0$234
;UtilEnemy.c:182: if(e_data->tile_collision){
	ld	a, (hl)
	or	a, a
	jr	Z, 00155$
	C$UtilEnemy.c$183$4_0$235	= .
	.globl	C$UtilEnemy.c$183$4_0$235
;UtilEnemy.c:183: e_check_tile_collision(s_enemy, e_sprite_type);
	ldhl	sp,	#4
	ld	a, (hl)
	push	af
	inc	sp
	ldhl	sp,	#30
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	push	de
	ld	e, #b_e_check_tile_collision
	ld	hl, #_e_check_tile_collision
	call	___sdcc_bcall_ehl
	add	sp, #3
	C$UtilEnemy.c$186$1_0$208	= .
	.globl	C$UtilEnemy.c$186$1_0$208
;UtilEnemy.c:186: }
00155$:
	C$UtilEnemy.c$188$1_0$208	= .
	.globl	C$UtilEnemy.c$188$1_0$208
;UtilEnemy.c:188: }
	add	sp, #23
	C$UtilEnemy.c$188$1_0$208	= .
	.globl	C$UtilEnemy.c$188$1_0$208
	XG$e_management$0$0	= .
	.globl	XG$e_management$0$0
	ret
	G$e_check_tile_collision$0$0	= .
	.globl	G$e_check_tile_collision$0$0
	C$UtilEnemy.c$190$1_0$237	= .
	.globl	C$UtilEnemy.c$190$1_0$237
;UtilEnemy.c:190: void e_check_tile_collision(Sprite* s_enemy, UINT8 e_sprite_type) BANKED{
;	---------------------------------
; Function e_check_tile_collision
; ---------------------------------
	b_e_check_tile_collision	= 255
_e_check_tile_collision::
	C$UtilEnemy.c$191$1_0$237	= .
	.globl	C$UtilEnemy.c$191$1_0$237
;UtilEnemy.c:191: struct EnemyInfo* e_data = (struct EnemyInfo*) s_enemy->custom_data;
	ldhl	sp,	#6
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	C$UtilEnemy.c$192$1_0$237	= .
	.globl	C$UtilEnemy.c$192$1_0$237
;UtilEnemy.c:192: if(e_data->tile_collision){
	ld	hl,#0x1c
	add	hl,bc
	ld	a, (hl)
	or	a, a
	ret	Z
	C$UtilEnemy.c$193$2_0$238	= .
	.globl	C$UtilEnemy.c$193$2_0$238
;UtilEnemy.c:193: e_turn(s_enemy, e_sprite_type);
	ldhl	sp,	#8
	ld	a, (hl)
	push	af
	inc	sp
	push	bc
	ld	e, #b_e_turn
	ld	hl, #_e_turn
	call	___sdcc_bcall_ehl
	add	sp, #3
	C$UtilEnemy.c$195$1_0$237	= .
	.globl	C$UtilEnemy.c$195$1_0$237
;UtilEnemy.c:195: }
	C$UtilEnemy.c$195$1_0$237	= .
	.globl	C$UtilEnemy.c$195$1_0$237
	XG$e_check_tile_collision$0$0	= .
	.globl	XG$e_check_tile_collision$0$0
	ret
	G$e_turn$0$0	= .
	.globl	G$e_turn$0$0
	C$UtilEnemy.c$197$1_0$240	= .
	.globl	C$UtilEnemy.c$197$1_0$240
;UtilEnemy.c:197: void e_turn(Sprite* s_enemy, UINT8 e_sprite_type) BANKED{
;	---------------------------------
; Function e_turn
; ---------------------------------
	b_e_turn	= 255
_e_turn::
	add	sp, #-4
	C$UtilEnemy.c$198$1_0$240	= .
	.globl	C$UtilEnemy.c$198$1_0$240
;UtilEnemy.c:198: struct EnemyInfo* e_data = (struct EnemyInfo*) s_enemy->custom_data;
	ldhl	sp,	#10
	ld	a, (hl)
	ldhl	sp,	#0
	ld	(hl), a
	ldhl	sp,	#11
	ld	a, (hl)
	ldhl	sp,	#1
	ld	(hl), a
	pop	de
	push	de
	ld	hl, #0x001b
	add	hl, de
	ld	c, l
	ld	b, h
	ldhl	sp,	#2
	ld	a, c
	ld	(hl+), a
	C$UtilEnemy.c$200$1_0$240	= .
	.globl	C$UtilEnemy.c$200$1_0$240
;UtilEnemy.c:200: if(e_data->wait > 120u){
	ld	a, b
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0004
	add	hl, de
	ld	c, l
	ld	b, h
	ld	a, (bc)
	ld	c, a
	ld	a, #0x78
	sub	a, c
	jr	NC, 00102$
	C$UtilEnemy.c$201$2_0$241	= .
	.globl	C$UtilEnemy.c$201$2_0$241
;UtilEnemy.c:201: wise = TURN_CLOCKWISE;
	ld	b, #0x01
	jr	00103$
00102$:
	C$UtilEnemy.c$203$2_0$242	= .
	.globl	C$UtilEnemy.c$203$2_0$242
;UtilEnemy.c:203: wise = TURN_COUNTERCLOCKWISE;
	ld	b, #0x02
00103$:
	C$UtilEnemy.c$205$1_0$240	= .
	.globl	C$UtilEnemy.c$205$1_0$240
;UtilEnemy.c:205: e_data->e_configured++;//used as a counter on same turn wise
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0006
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
	inc	a
	ld	(de), a
	C$UtilEnemy.c$206$1_0$240	= .
	.globl	C$UtilEnemy.c$206$1_0$240
;UtilEnemy.c:206: if(e_data->e_configured < 5 && wise == TURN_COUNTERCLOCKWISE){
	sub	a, #0x05
	jr	NC, 00111$
	ld	a, b
	sub	a, #0x02
	jr	NZ, 00111$
	C$UtilEnemy.c$207$2_0$243	= .
	.globl	C$UtilEnemy.c$207$2_0$243
;UtilEnemy.c:207: wise = TURN_CLOCKWISE;
	ld	b, #0x01
	jr	00112$
00111$:
	C$UtilEnemy.c$205$1_0$240	= .
	.globl	C$UtilEnemy.c$205$1_0$240
;UtilEnemy.c:205: e_data->e_configured++;//used as a counter on same turn wise
	ld	a, (de)
	C$UtilEnemy.c$208$1_0$240	= .
	.globl	C$UtilEnemy.c$208$1_0$240
;UtilEnemy.c:208: }else if(e_data->e_configured < 9 && wise == TURN_CLOCKWISE){
	sub	a, #0x09
	ld	a, #0x00
	rla
	ld	c, a
	or	a, a
	jr	Z, 00107$
	ld	a, b
	dec	a
	jr	NZ, 00107$
	C$UtilEnemy.c$209$2_0$244	= .
	.globl	C$UtilEnemy.c$209$2_0$244
;UtilEnemy.c:209: wise = TURN_COUNTERCLOCKWISE;
	ld	b, #0x02
	jr	00112$
00107$:
	C$UtilEnemy.c$210$1_0$240	= .
	.globl	C$UtilEnemy.c$210$1_0$240
;UtilEnemy.c:210: }else if(e_data->e_configured >= 9){
	bit	0, c
	jr	NZ, 00112$
	C$UtilEnemy.c$211$2_0$245	= .
	.globl	C$UtilEnemy.c$211$2_0$245
;UtilEnemy.c:211: wise = TURN_OPPOSITE;
	ld	b, #0x03
	C$UtilEnemy.c$212$2_0$245	= .
	.globl	C$UtilEnemy.c$212$2_0$245
;UtilEnemy.c:212: e_data->e_configured = 1;
	ld	a, #0x01
	ld	(de), a
00112$:
	C$UtilEnemy.c$216$1_0$240	= .
	.globl	C$UtilEnemy.c$216$1_0$240
;UtilEnemy.c:216: switch(e_data->e_state){
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
;	spillPairReg hl
;	spillPairReg hl
	ld	l, a
	sub	a, #0x06
	ld	a, #0x01
	jr	Z, 00328$
	xor	a, a
00328$:
	ld	c, a
	ld	a, l
	sub	a, #0x07
	ld	a, #0x01
	jr	Z, 00330$
	xor	a, a
00330$:
	ld	e, a
	ld	a, l
	sub	a, #0x08
	ld	a, #0x01
	jr	Z, 00332$
	xor	a, a
00332$:
	ld	d, a
	ld	a, l
	sub	a, #0x09
	ld	a, #0x01
	jr	Z, 00334$
	xor	a, a
00334$:
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	C$UtilEnemy.c$214$1_0$240	= .
	.globl	C$UtilEnemy.c$214$1_0$240
;UtilEnemy.c:214: switch(wise){
	ld	a, b
	dec	a
	jr	Z, 00114$
	ld	a,b
	cp	a,#0x02
	jr	Z, 00120$
	sub	a, #0x03
	jp	Z,00126$
	jp	00132$
	C$UtilEnemy.c$215$2_0$246	= .
	.globl	C$UtilEnemy.c$215$2_0$246
;UtilEnemy.c:215: case TURN_CLOCKWISE:
00114$:
	C$UtilEnemy.c$216$2_0$246	= .
	.globl	C$UtilEnemy.c$216$2_0$246
;UtilEnemy.c:216: switch(e_data->e_state){
	ld	a, c
	or	a,a
	jr	NZ, 00116$
	or	a,e
	jr	NZ, 00118$
	or	a,d
	jr	NZ, 00117$
	or	a,l
	jp	Z, 00132$
	C$UtilEnemy.c$217$3_0$247	= .
	.globl	C$UtilEnemy.c$217$3_0$247
;UtilEnemy.c:217: case WALK_DOWN: e_change_state(s_enemy, IDLE_LEFT, e_sprite_type); break;
	ldhl	sp,	#12
	ld	h, (hl)
	ld	l, #0x04
	push	hl
	ldhl	sp,	#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	e, #b_e_change_state
	ld	hl, #_e_change_state
	call	___sdcc_bcall_ehl
	add	sp, #4
	jp	00132$
	C$UtilEnemy.c$218$3_0$247	= .
	.globl	C$UtilEnemy.c$218$3_0$247
;UtilEnemy.c:218: case WALK_LEFT: e_change_state(s_enemy, IDLE_UP, e_sprite_type); break;
00116$:
	ldhl	sp,	#12
	ld	h, (hl)
	ld	l, #0x02
	push	hl
	ldhl	sp,	#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	e, #b_e_change_state
	ld	hl, #_e_change_state
	call	___sdcc_bcall_ehl
	add	sp, #4
	jp	00132$
	C$UtilEnemy.c$219$3_0$247	= .
	.globl	C$UtilEnemy.c$219$3_0$247
;UtilEnemy.c:219: case WALK_UP: e_change_state(s_enemy, IDLE_RIGHT, e_sprite_type); break;
00117$:
	ldhl	sp,	#12
	ld	h, (hl)
	ld	l, #0x05
	push	hl
	ldhl	sp,	#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	e, #b_e_change_state
	ld	hl, #_e_change_state
	call	___sdcc_bcall_ehl
	add	sp, #4
	jp	00132$
	C$UtilEnemy.c$220$3_0$247	= .
	.globl	C$UtilEnemy.c$220$3_0$247
;UtilEnemy.c:220: case WALK_RIGHT: e_change_state(s_enemy, IDLE_DOWN, e_sprite_type); break;
00118$:
	ldhl	sp,	#12
	ld	h, (hl)
	ld	l, #0x03
	push	hl
	ldhl	sp,	#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	e, #b_e_change_state
	ld	hl, #_e_change_state
	call	___sdcc_bcall_ehl
	add	sp, #4
	C$UtilEnemy.c$222$2_0$246	= .
	.globl	C$UtilEnemy.c$222$2_0$246
;UtilEnemy.c:222: break;
	jp	00132$
	C$UtilEnemy.c$223$2_0$246	= .
	.globl	C$UtilEnemy.c$223$2_0$246
;UtilEnemy.c:223: case TURN_COUNTERCLOCKWISE:        
00120$:
	C$UtilEnemy.c$224$2_0$246	= .
	.globl	C$UtilEnemy.c$224$2_0$246
;UtilEnemy.c:224: switch(e_data->e_state){
	ld	a, c
	or	a,a
	jr	NZ, 00122$
	or	a,e
	jr	NZ, 00124$
	or	a,d
	jr	NZ, 00123$
	or	a,l
	jp	Z, 00132$
	C$UtilEnemy.c$225$3_0$248	= .
	.globl	C$UtilEnemy.c$225$3_0$248
;UtilEnemy.c:225: case WALK_DOWN: e_change_state(s_enemy, IDLE_RIGHT, e_sprite_type); break;
	ldhl	sp,	#12
	ld	h, (hl)
	ld	l, #0x05
	push	hl
	ldhl	sp,	#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	e, #b_e_change_state
	ld	hl, #_e_change_state
	call	___sdcc_bcall_ehl
	add	sp, #4
	jp	00132$
	C$UtilEnemy.c$226$3_0$248	= .
	.globl	C$UtilEnemy.c$226$3_0$248
;UtilEnemy.c:226: case WALK_LEFT: e_change_state(s_enemy, IDLE_DOWN, e_sprite_type); break;
00122$:
	ldhl	sp,	#12
	ld	h, (hl)
	ld	l, #0x03
	push	hl
	ldhl	sp,	#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	e, #b_e_change_state
	ld	hl, #_e_change_state
	call	___sdcc_bcall_ehl
	add	sp, #4
	jp	00132$
	C$UtilEnemy.c$227$3_0$248	= .
	.globl	C$UtilEnemy.c$227$3_0$248
;UtilEnemy.c:227: case WALK_UP: e_change_state(s_enemy, IDLE_LEFT, e_sprite_type); break;
00123$:
	ldhl	sp,	#12
	ld	h, (hl)
	ld	l, #0x04
	push	hl
	ldhl	sp,	#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	e, #b_e_change_state
	ld	hl, #_e_change_state
	call	___sdcc_bcall_ehl
	add	sp, #4
	jp	00132$
	C$UtilEnemy.c$228$3_0$248	= .
	.globl	C$UtilEnemy.c$228$3_0$248
;UtilEnemy.c:228: case WALK_RIGHT: e_change_state(s_enemy, IDLE_UP, e_sprite_type); break;
00124$:
	ldhl	sp,	#12
	ld	h, (hl)
	ld	l, #0x02
	push	hl
	ldhl	sp,	#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	e, #b_e_change_state
	ld	hl, #_e_change_state
	call	___sdcc_bcall_ehl
	add	sp, #4
	C$UtilEnemy.c$230$2_0$246	= .
	.globl	C$UtilEnemy.c$230$2_0$246
;UtilEnemy.c:230: break;
	jr	00132$
	C$UtilEnemy.c$231$2_0$246	= .
	.globl	C$UtilEnemy.c$231$2_0$246
;UtilEnemy.c:231: case TURN_OPPOSITE:
00126$:
	C$UtilEnemy.c$232$2_0$246	= .
	.globl	C$UtilEnemy.c$232$2_0$246
;UtilEnemy.c:232: switch(e_data->e_state){
	ld	a, c
	or	a,a
	jr	NZ, 00128$
	or	a,e
	jr	NZ, 00130$
	or	a,d
	jr	NZ, 00129$
	or	a,l
	jr	Z, 00132$
	C$UtilEnemy.c$233$3_0$249	= .
	.globl	C$UtilEnemy.c$233$3_0$249
;UtilEnemy.c:233: case WALK_DOWN: e_change_state(s_enemy, IDLE_UP, e_sprite_type); break;
	ldhl	sp,	#12
	ld	h, (hl)
	ld	l, #0x02
	push	hl
	ldhl	sp,	#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	e, #b_e_change_state
	ld	hl, #_e_change_state
	call	___sdcc_bcall_ehl
	add	sp, #4
	jr	00132$
	C$UtilEnemy.c$234$3_0$249	= .
	.globl	C$UtilEnemy.c$234$3_0$249
;UtilEnemy.c:234: case WALK_LEFT: e_change_state(s_enemy, IDLE_RIGHT, e_sprite_type); break;
00128$:
	ldhl	sp,	#12
	ld	h, (hl)
	ld	l, #0x05
	push	hl
	ldhl	sp,	#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	e, #b_e_change_state
	ld	hl, #_e_change_state
	call	___sdcc_bcall_ehl
	add	sp, #4
	jr	00132$
	C$UtilEnemy.c$235$3_0$249	= .
	.globl	C$UtilEnemy.c$235$3_0$249
;UtilEnemy.c:235: case WALK_UP: e_change_state(s_enemy, IDLE_DOWN, e_sprite_type); break;
00129$:
	ldhl	sp,	#12
	ld	h, (hl)
	ld	l, #0x03
	push	hl
	ldhl	sp,	#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	e, #b_e_change_state
	ld	hl, #_e_change_state
	call	___sdcc_bcall_ehl
	add	sp, #4
	jr	00132$
	C$UtilEnemy.c$236$3_0$249	= .
	.globl	C$UtilEnemy.c$236$3_0$249
;UtilEnemy.c:236: case WALK_RIGHT: e_change_state(s_enemy, IDLE_LEFT, e_sprite_type); break;
00130$:
	ldhl	sp,	#12
	ld	h, (hl)
	ld	l, #0x04
	push	hl
	ldhl	sp,	#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	e, #b_e_change_state
	ld	hl, #_e_change_state
	call	___sdcc_bcall_ehl
	add	sp, #4
	C$UtilEnemy.c$239$1_0$240	= .
	.globl	C$UtilEnemy.c$239$1_0$240
;UtilEnemy.c:239: }
00132$:
	C$UtilEnemy.c$241$1_0$240	= .
	.globl	C$UtilEnemy.c$241$1_0$240
;UtilEnemy.c:241: switch(e_data->e_state){
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	cp	a, #0x01
	jr	Z, 00137$
	cp	a, #0x02
	jr	Z, 00135$
	cp	a, #0x03
	jr	Z, 00136$
	cp	a, #0x04
	jr	Z, 00133$
	sub	a, #0x05
	jr	Z, 00134$
	jr	00139$
	C$UtilEnemy.c$242$2_0$250	= .
	.globl	C$UtilEnemy.c$242$2_0$250
;UtilEnemy.c:242: case IDLE_LEFT: 
00133$:
	C$UtilEnemy.c$243$2_0$250	= .
	.globl	C$UtilEnemy.c$243$2_0$250
;UtilEnemy.c:243: e_change_state(s_enemy, WALK_LEFT, e_sprite_type); break;
	ldhl	sp,	#12
	ld	a, (hl-)
	dec	hl
	ld	d, a
	ld	e, #0x06
	push	de
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	e, #b_e_change_state
	ld	hl, #_e_change_state
	call	___sdcc_bcall_ehl
	add	sp, #4
	jr	00139$
	C$UtilEnemy.c$244$2_0$250	= .
	.globl	C$UtilEnemy.c$244$2_0$250
;UtilEnemy.c:244: case IDLE_RIGHT: 
00134$:
	C$UtilEnemy.c$245$2_0$250	= .
	.globl	C$UtilEnemy.c$245$2_0$250
;UtilEnemy.c:245: e_change_state(s_enemy, WALK_RIGHT, e_sprite_type); break;
	ldhl	sp,	#12
	ld	a, (hl-)
	dec	hl
	ld	d, a
	ld	e, #0x07
	push	de
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	e, #b_e_change_state
	ld	hl, #_e_change_state
	call	___sdcc_bcall_ehl
	add	sp, #4
	jr	00139$
	C$UtilEnemy.c$246$2_0$250	= .
	.globl	C$UtilEnemy.c$246$2_0$250
;UtilEnemy.c:246: case IDLE_UP: 
00135$:
	C$UtilEnemy.c$247$2_0$250	= .
	.globl	C$UtilEnemy.c$247$2_0$250
;UtilEnemy.c:247: e_change_state(s_enemy, WALK_UP, e_sprite_type); break;
	ldhl	sp,	#12
	ld	a, (hl-)
	dec	hl
	ld	d, a
	ld	e, #0x08
	push	de
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	e, #b_e_change_state
	ld	hl, #_e_change_state
	call	___sdcc_bcall_ehl
	add	sp, #4
	jr	00139$
	C$UtilEnemy.c$248$2_0$250	= .
	.globl	C$UtilEnemy.c$248$2_0$250
;UtilEnemy.c:248: case IDLE_DOWN: 
00136$:
	C$UtilEnemy.c$249$2_0$250	= .
	.globl	C$UtilEnemy.c$249$2_0$250
;UtilEnemy.c:249: e_change_state(s_enemy, WALK_DOWN, e_sprite_type); break;
	ldhl	sp,	#12
	ld	a, (hl-)
	dec	hl
	ld	d, a
	ld	e, #0x09
	push	de
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	e, #b_e_change_state
	ld	hl, #_e_change_state
	call	___sdcc_bcall_ehl
	add	sp, #4
	jr	00139$
	C$UtilEnemy.c$250$2_0$250	= .
	.globl	C$UtilEnemy.c$250$2_0$250
;UtilEnemy.c:250: case GENERIC_WALK:
00137$:
	C$UtilEnemy.c$251$2_0$250	= .
	.globl	C$UtilEnemy.c$251$2_0$250
;UtilEnemy.c:251: e_change_state(s_enemy, WALK_DOWN, e_sprite_type); break;
	ldhl	sp,	#12
	ld	a, (hl-)
	dec	hl
	ld	d, a
	ld	e, #0x09
	push	de
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	e, #b_e_change_state
	ld	hl, #_e_change_state
	call	___sdcc_bcall_ehl
	add	sp, #4
	C$UtilEnemy.c$253$1_0$240	= .
	.globl	C$UtilEnemy.c$253$1_0$240
;UtilEnemy.c:253: }
00139$:
	C$UtilEnemy.c$254$1_0$240	= .
	.globl	C$UtilEnemy.c$254$1_0$240
;UtilEnemy.c:254: }
	add	sp, #4
	C$UtilEnemy.c$254$1_0$240	= .
	.globl	C$UtilEnemy.c$254$1_0$240
	XG$e_turn$0$0	= .
	.globl	XG$e_turn$0$0
	ret
	G$e_destroy$0$0	= .
	.globl	G$e_destroy$0$0
	C$UtilEnemy.c$256$1_0$252	= .
	.globl	C$UtilEnemy.c$256$1_0$252
;UtilEnemy.c:256: void e_destroy(Sprite* s_enemy, UINT8 e_sprite_type) BANKED{
;	---------------------------------
; Function e_destroy
; ---------------------------------
	b_e_destroy	= 255
_e_destroy::
	C$UtilEnemy.c$257$1_0$252	= .
	.globl	C$UtilEnemy.c$257$1_0$252
;UtilEnemy.c:257: e_change_state(s_enemy, DIE, e_sprite_type);
	ldhl	sp,	#8
	ld	a, (hl-)
	dec	hl
	ld	d, a
	ld	e, #0x0d
	push	de
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	e, #b_e_change_state
	ld	hl, #_e_change_state
	call	___sdcc_bcall_ehl
	add	sp, #4
	C$UtilEnemy.c$258$1_0$252	= .
	.globl	C$UtilEnemy.c$258$1_0$252
;UtilEnemy.c:258: }
	C$UtilEnemy.c$258$1_0$252	= .
	.globl	C$UtilEnemy.c$258$1_0$252
	XG$e_destroy$0$0	= .
	.globl	XG$e_destroy$0$0
	ret
	G$Update_UtilEnemy$0$0	= .
	.globl	G$Update_UtilEnemy$0$0
	C$UtilEnemy.c$260$1_0$254	= .
	.globl	C$UtilEnemy.c$260$1_0$254
;UtilEnemy.c:260: void UPDATE(){
;	---------------------------------
; Function Update_UtilEnemy
; ---------------------------------
_Update_UtilEnemy::
	C$UtilEnemy.c$261$1_0$254	= .
	.globl	C$UtilEnemy.c$261$1_0$254
;UtilEnemy.c:261: }
	C$UtilEnemy.c$261$1_0$254	= .
	.globl	C$UtilEnemy.c$261$1_0$254
	XG$Update_UtilEnemy$0$0	= .
	.globl	XG$Update_UtilEnemy$0$0
	ret
	.area _CODE_255
	.area _INITIALIZER
	.area _CABS (ABS)
