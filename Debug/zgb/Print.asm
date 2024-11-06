;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module Print
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _uitoa
	.globl _itoa
	.globl _UpdateMapTile
	.globl _font_offset
	.globl _print_target
	.globl _print_y
	.globl _print_x
	.globl _Printf
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
G$print_x$0_0$0==.
_print_x::
	.ds 1
G$print_y$0_0$0==.
_print_y::
	.ds 1
G$print_target$0_0$0==.
_print_target::
	.ds 1
G$font_offset$0_0$0==.
_font_offset::
	.ds 2
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
	G$Printf$0$0	= .
	.globl	G$Printf$0$0
	C$Print.c$13$0_0$190	= .
	.globl	C$Print.c$13$0_0$190
;C:/ZGB-2023.0/common/src/Print.c:13: void Printf(const char* txt, ...){
;	---------------------------------
; Function Printf
; ---------------------------------
_Printf::
	add	sp, #-13
	C$Print.c$15$2_0$190	= .
	.globl	C$Print.c$15$2_0$190
;C:/ZGB-2023.0/common/src/Print.c:15: unsigned char c = 0;
	ldhl	sp,	#10
	ld	(hl), #0x00
	C$Print.c$19$1_0$190	= .
	.globl	C$Print.c$19$1_0$190
;C:/ZGB-2023.0/common/src/Print.c:19: va_start(list, txt); 
	ldhl	sp,#17
	ld	c, l
	ld	b, h
	ldhl	sp,	#11
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	C$Print.c$20$5_0$198	= .
	.globl	C$Print.c$20$5_0$198
;C:/ZGB-2023.0/common/src/Print.c:20: while(*txt) {
00134$:
	ldhl	sp,	#15
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	a, (bc)
	C$Print.c$21$2_0$191	= .
	.globl	C$Print.c$21$2_0$191
;C:/ZGB-2023.0/common/src/Print.c:21: if(*txt == ' ') {
	ld	c,a
	or	a,a
	jp	Z,00137$
	sub	a, #0x20
	jr	NZ, 00129$
	C$Print.c$22$3_0$192	= .
	.globl	C$Print.c$22$3_0$192
;C:/ZGB-2023.0/common/src/Print.c:22: c = 0;
	ldhl	sp,	#10
	ld	(hl), #0x00
	jp	00130$
00129$:
	C$Print.c$23$2_0$191	= .
	.globl	C$Print.c$23$2_0$191
;C:/ZGB-2023.0/common/src/Print.c:23: } else if(*txt >= 'A' && *txt <= 'Z'){
	ld	a, c
	xor	a, #0x80
	sub	a, #0xc1
	jr	C, 00125$
	ld	e, c
	ld	a,#0x5a
	ld	d,a
	sub	a, c
	bit	7, e
	jr	Z, 00302$
	bit	7, d
	jr	NZ, 00303$
	cp	a, a
	jr	00303$
00302$:
	bit	7, d
	jr	Z, 00303$
	scf
00303$:
	jr	C, 00125$
	C$Print.c$24$3_0$193	= .
	.globl	C$Print.c$24$3_0$193
;C:/ZGB-2023.0/common/src/Print.c:24: c = 1 + *txt - 'A';
	ld	a, c
	add	a, #0xc0
	ldhl	sp,	#10
	ld	(hl), a
	jp	00130$
00125$:
	C$Print.c$25$2_0$191	= .
	.globl	C$Print.c$25$2_0$191
;C:/ZGB-2023.0/common/src/Print.c:25: } else if(*txt >= 'a' && *txt <= 'z') {
	ldhl	sp,	#15
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	a, (bc)
	ld	c, a
	xor	a, #0x80
	sub	a, #0xe1
	jr	C, 00121$
	ld	e, c
	ld	a,#0x7a
	ld	d,a
	sub	a, c
	bit	7, e
	jr	Z, 00304$
	bit	7, d
	jr	NZ, 00305$
	cp	a, a
	jr	00305$
00304$:
	bit	7, d
	jr	Z, 00305$
	scf
00305$:
	jr	C, 00121$
	C$Print.c$26$3_0$194	= .
	.globl	C$Print.c$26$3_0$194
;C:/ZGB-2023.0/common/src/Print.c:26: c = 1 + *txt - 'a';
	ld	a, c
	add	a, #0xa0
	ldhl	sp,	#10
	ld	(hl), a
	jp	00130$
00121$:
	C$Print.c$27$2_0$191	= .
	.globl	C$Print.c$27$2_0$191
;C:/ZGB-2023.0/common/src/Print.c:27: } else if(*txt >= '0' && *txt <= '9') {
	ldhl	sp,	#15
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	a, (bc)
	ld	c, a
	xor	a, #0x80
	sub	a, #0xb0
	jr	C, 00117$
	ld	e, c
	ld	a,#0x39
	ld	d,a
	sub	a, c
	bit	7, e
	jr	Z, 00306$
	bit	7, d
	jr	NZ, 00307$
	cp	a, a
	jr	00307$
00306$:
	bit	7, d
	jr	Z, 00307$
	scf
00307$:
	jr	C, 00117$
	C$Print.c$28$3_0$195	= .
	.globl	C$Print.c$28$3_0$195
;C:/ZGB-2023.0/common/src/Print.c:28: c = 27 + *txt - '0';
	ld	a, c
	add	a, #0xeb
	ldhl	sp,	#10
	ld	(hl), a
	jp	00130$
00117$:
	C$Print.c$30$3_0$196	= .
	.globl	C$Print.c$30$3_0$196
;C:/ZGB-2023.0/common/src/Print.c:30: switch(*txt) {
	ldhl	sp,	#15
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	a, (bc)
	cp	a, #0x21
	jr	Z, 00101$
	cp	a, #0x25
	jr	Z, 00109$
	cp	a, #0x27
	jr	Z, 00102$
	cp	a, #0x28
	jr	Z, 00103$
	cp	a, #0x29
	jr	Z, 00104$
	cp	a, #0x2c
	jr	Z, 00105$
	cp	a, #0x2e
	jr	Z, 00106$
	cp	a, #0x3a
	jr	Z, 00107$
	sub	a, #0x3f
	jr	Z, 00108$
	jp	00130$
	C$Print.c$31$4_0$197	= .
	.globl	C$Print.c$31$4_0$197
;C:/ZGB-2023.0/common/src/Print.c:31: case  '!': c= 37; break;
00101$:
	ldhl	sp,	#10
	ld	(hl), #0x25
	jp	00130$
	C$Print.c$32$4_0$197	= .
	.globl	C$Print.c$32$4_0$197
;C:/ZGB-2023.0/common/src/Print.c:32: case '\'': c= 38; break;
00102$:
	ldhl	sp,	#10
	ld	(hl), #0x26
	jp	00130$
	C$Print.c$33$4_0$197	= .
	.globl	C$Print.c$33$4_0$197
;C:/ZGB-2023.0/common/src/Print.c:33: case  '(': c= 39; break;
00103$:
	ldhl	sp,	#10
	ld	(hl), #0x27
	jp	00130$
	C$Print.c$34$4_0$197	= .
	.globl	C$Print.c$34$4_0$197
;C:/ZGB-2023.0/common/src/Print.c:34: case  ')': c= 40; break;
00104$:
	ldhl	sp,	#10
	ld	(hl), #0x28
	jp	00130$
	C$Print.c$35$4_0$197	= .
	.globl	C$Print.c$35$4_0$197
;C:/ZGB-2023.0/common/src/Print.c:35: case  ',': c= 41; break;
00105$:
	ldhl	sp,	#10
	ld	(hl), #0x29
	jp	00130$
	C$Print.c$36$4_0$197	= .
	.globl	C$Print.c$36$4_0$197
;C:/ZGB-2023.0/common/src/Print.c:36: case  '.': c= 42; break;
00106$:
	ldhl	sp,	#10
	ld	(hl), #0x2a
	jp	00130$
	C$Print.c$37$4_0$197	= .
	.globl	C$Print.c$37$4_0$197
;C:/ZGB-2023.0/common/src/Print.c:37: case  ':': c= 43; break;
00107$:
	ldhl	sp,	#10
	ld	(hl), #0x2b
	jp	00130$
	C$Print.c$38$4_0$197	= .
	.globl	C$Print.c$38$4_0$197
;C:/ZGB-2023.0/common/src/Print.c:38: case  '?': c= 44; break;
00108$:
	ldhl	sp,	#10
	ld	(hl), #0x2c
	jp	00130$
	C$Print.c$39$4_0$197	= .
	.globl	C$Print.c$39$4_0$197
;C:/ZGB-2023.0/common/src/Print.c:39: case  '%':
00109$:
	C$Print.c$40$4_0$197	= .
	.globl	C$Print.c$40$4_0$197
;C:/ZGB-2023.0/common/src/Print.c:40: switch(*(txt + 1)) {
	inc	bc
	ld	a, (bc)
	cp	a, #0x64
	jr	Z, 00111$
	cp	a, #0x69
	jr	Z, 00111$
	cp	a, #0x73
	jp	Z,00113$
	sub	a, #0x75
	jr	Z, 00112$
	jp	00130$
	C$Print.c$42$5_0$198	= .
	.globl	C$Print.c$42$5_0$198
;C:/ZGB-2023.0/common/src/Print.c:42: case 'i':
00111$:
	C$Print.c$43$5_0$198	= .
	.globl	C$Print.c$43$5_0$198
;C:/ZGB-2023.0/common/src/Print.c:43: itoa(va_arg(list, INT16), tmp, 10);
	ldhl	sp,	#11
	ld	a, (hl+)
	ld	c, a
	ld	a, (hl-)
	ld	b, a
	inc	bc
	inc	bc
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	dec	bc
	dec	bc
	ld	l, c
	ld	h, b
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	a, #0x0a
	push	af
	inc	sp
	ld	hl, #1
	add	hl, sp
	push	hl
	push	bc
	call	_itoa
	add	sp, #5
	C$Print.c$44$5_0$198	= .
	.globl	C$Print.c$44$5_0$198
;C:/ZGB-2023.0/common/src/Print.c:44: Printf(tmp);
	ld	hl, #0
	add	hl, sp
	push	hl
	call	_Printf
	pop	hl
	C$Print.c$45$5_0$198	= .
	.globl	C$Print.c$45$5_0$198
;C:/ZGB-2023.0/common/src/Print.c:45: txt += 2;
	ldhl	sp,#15
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0002
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#17
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#16
	ld	(hl), a
	C$Print.c$46$5_0$198	= .
	.globl	C$Print.c$46$5_0$198
;C:/ZGB-2023.0/common/src/Print.c:46: continue;
	jp	00134$
	C$Print.c$48$5_0$198	= .
	.globl	C$Print.c$48$5_0$198
;C:/ZGB-2023.0/common/src/Print.c:48: case 'u':
00112$:
	C$Print.c$49$5_0$198	= .
	.globl	C$Print.c$49$5_0$198
;C:/ZGB-2023.0/common/src/Print.c:49: uitoa(va_arg(list, INT16), tmp, 10);
	ldhl	sp,	#11
	ld	a, (hl+)
	ld	c, a
	ld	a, (hl-)
	ld	b, a
	inc	bc
	inc	bc
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	dec	bc
	dec	bc
	ld	l, c
	ld	h, b
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	a, #0x0a
	push	af
	inc	sp
	ld	hl, #1
	add	hl, sp
	push	hl
	push	bc
	call	_uitoa
	add	sp, #5
	C$Print.c$50$5_0$198	= .
	.globl	C$Print.c$50$5_0$198
;C:/ZGB-2023.0/common/src/Print.c:50: Printf(tmp);
	ld	hl, #0
	add	hl, sp
	push	hl
	call	_Printf
	pop	hl
	C$Print.c$51$5_0$198	= .
	.globl	C$Print.c$51$5_0$198
;C:/ZGB-2023.0/common/src/Print.c:51: txt += 2;
	ldhl	sp,#15
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0002
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#17
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#16
	ld	(hl), a
	C$Print.c$52$5_0$198	= .
	.globl	C$Print.c$52$5_0$198
;C:/ZGB-2023.0/common/src/Print.c:52: continue;
	jp	00134$
	C$Print.c$54$5_0$198	= .
	.globl	C$Print.c$54$5_0$198
;C:/ZGB-2023.0/common/src/Print.c:54: case 's':
00113$:
	C$Print.c$55$5_0$198	= .
	.globl	C$Print.c$55$5_0$198
;C:/ZGB-2023.0/common/src/Print.c:55: Printf(va_arg(list, char*));
	ldhl	sp,	#11
	ld	a, (hl+)
	ld	c, a
	ld	a, (hl-)
	ld	b, a
	inc	bc
	inc	bc
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	dec	bc
	dec	bc
	ld	l, c
	ld	h, b
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	push	bc
	call	_Printf
	pop	hl
	C$Print.c$56$5_0$198	= .
	.globl	C$Print.c$56$5_0$198
;C:/ZGB-2023.0/common/src/Print.c:56: txt += 2;
	ldhl	sp,#15
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0002
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#17
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#16
	ld	(hl), a
	C$Print.c$57$5_0$198	= .
	.globl	C$Print.c$57$5_0$198
;C:/ZGB-2023.0/common/src/Print.c:57: continue;
	jp	00134$
	C$Print.c$60$2_0$191	= .
	.globl	C$Print.c$60$2_0$191
;C:/ZGB-2023.0/common/src/Print.c:60: }
00130$:
	C$Print.c$62$2_0$191	= .
	.globl	C$Print.c$62$2_0$191
;C:/ZGB-2023.0/common/src/Print.c:62: if(print_target == PRINT_BKG)
	ld	a, (#_print_target)
	or	a, a
	jr	NZ, 00132$
	C$Print.c$63$2_0$191	= .
	.globl	C$Print.c$63$2_0$191
;C:/ZGB-2023.0/common/src/Print.c:63: UpdateMapTile(print_target, 0x1F & (print_x + scroll_offset_x), 0x1F & (print_y + scroll_offset_y), font_offset, c, 0);
	ld	a, (#_print_y)
	ld	hl, #_scroll_offset_y
	add	a, (hl)
	and	a, #0x1f
	ld	b, a
	ld	a, (#_print_x)
	ld	hl, #_scroll_offset_x
	add	a, (hl)
	and	a, #0x1f
	ld	e, a
	ld	hl, #0x0000
	push	hl
	ldhl	sp,	#12
	ld	a, (hl)
	push	af
	inc	sp
	ld	hl, #_font_offset
	ld	l, (hl)
;	spillPairReg hl
;	spillPairReg hl
	ld	a, (_font_offset + 1)
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	push	hl
	push	bc
	inc	sp
	ld	a, (#_print_target)
	call	_UpdateMapTile
	jr	00133$
00132$:
	C$Print.c$65$2_0$191	= .
	.globl	C$Print.c$65$2_0$191
;C:/ZGB-2023.0/common/src/Print.c:65: UpdateMapTile(print_target, print_x, print_y, font_offset, c, 0);
	ld	de, #0x0000
	push	de
	ldhl	sp,	#12
	ld	a, (hl)
	push	af
	inc	sp
	ld	hl, #_font_offset
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	a, (#_print_y)
	push	af
	inc	sp
	ld	hl, #_print_x
	ld	e, (hl)
	ld	a, (#_print_target)
	call	_UpdateMapTile
00133$:
	C$Print.c$67$2_0$191	= .
	.globl	C$Print.c$67$2_0$191
;C:/ZGB-2023.0/common/src/Print.c:67: print_x ++;
	ld	hl, #_print_x
	inc	(hl)
	C$Print.c$68$2_0$191	= .
	.globl	C$Print.c$68$2_0$191
;C:/ZGB-2023.0/common/src/Print.c:68: txt ++;
	ldhl	sp,	#15
	inc	(hl)
	jp	NZ,00134$
	inc	hl
	inc	(hl)
	jp	00134$
00137$:
	C$Print.c$71$1_0$190	= .
	.globl	C$Print.c$71$1_0$190
;C:/ZGB-2023.0/common/src/Print.c:71: }
	add	sp, #13
	C$Print.c$71$1_0$190	= .
	.globl	C$Print.c$71$1_0$190
	XG$Printf$0$0	= .
	.globl	XG$Printf$0$0
	ret
	.area _CODE
	.area _INITIALIZER
FPrint$__xinit_print_x$0_0$0 == .
__xinit__print_x:
	.db #0x00	; 0
FPrint$__xinit_print_y$0_0$0 == .
__xinit__print_y:
	.db #0x00	; 0
FPrint$__xinit_print_target$0_0$0 == .
__xinit__print_target:
	.db #0x00	; 0
FPrint$__xinit_font_offset$0_0$0 == .
__xinit__font_offset:
	.dw #0x0000
	.area _CABS (ABS)
