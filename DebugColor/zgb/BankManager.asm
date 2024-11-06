;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module BankManager
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _empty
	.globl _bank_stack
	.globl _bank_stackSTACK
	.globl _PushBank
	.globl _PopBank
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
G$bank_stackSTACK$0_0$0==.
_bank_stackSTACK::
	.ds 10
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
G$bank_stack$0_0$0==.
_bank_stack::
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
	G$empty$0$0	= .
	.globl	G$empty$0$0
	C$BankManager.c$5$0_0$126	= .
	.globl	C$BankManager.c$5$0_0$126
;C:/ZGB-2023.0/common/src/BankManager.c:5: void empty(void) __nonbanked {}
;	---------------------------------
; Function empty
; ---------------------------------
_empty::
	C$BankManager.c$5$0_0$126	= .
	.globl	C$BankManager.c$5$0_0$126
	XG$empty$0$0	= .
	.globl	XG$empty$0$0
	ret
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
	G$PushBank$0$0	= .
	.globl	G$PushBank$0$0
	C$BankManager.c$7$0_0$128	= .
	.globl	C$BankManager.c$7$0_0$128
;C:/ZGB-2023.0/common/src/BankManager.c:7: void PushBank(UINT8 b) OLDCALL{
;	---------------------------------
; Function PushBank
; ---------------------------------
_PushBank::
	C$BankManager.c$25$1_0$128	= .
	.globl	C$BankManager.c$25$1_0$128
;C:/ZGB-2023.0/common/src/BankManager.c:25: __endasm;
	ld	hl, #_bank_stack
	inc	(hl)
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	a, (#__current_bank)
	ld	(bc), a
	ldhl	sp, #2
	ld	a, (hl)
	ld	(#__current_bank), a
	ld	(#0x2000), a
	C$BankManager.c$26$1_0$128	= .
	.globl	C$BankManager.c$26$1_0$128
;C:/ZGB-2023.0/common/src/BankManager.c:26: }
	C$BankManager.c$26$1_0$128	= .
	.globl	C$BankManager.c$26$1_0$128
	XG$PushBank$0$0	= .
	.globl	XG$PushBank$0$0
	ret
	G$PopBank$0$0	= .
	.globl	G$PopBank$0$0
	C$BankManager.c$28$1_0$129	= .
	.globl	C$BankManager.c$28$1_0$129
;C:/ZGB-2023.0/common/src/BankManager.c:28: void PopBank() OLDCALL{
;	---------------------------------
; Function PopBank
; ---------------------------------
_PopBank::
	C$BankManager.c$42$1_0$129	= .
	.globl	C$BankManager.c$42$1_0$129
;C:/ZGB-2023.0/common/src/BankManager.c:42: __endasm;
	ld	hl, #_bank_stack
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	a, (bc)
	ld	(#__current_bank), a
	ld	(#0x2000), a
	dec	hl
	dec	(hl)
	C$BankManager.c$43$1_0$129	= .
	.globl	C$BankManager.c$43$1_0$129
;C:/ZGB-2023.0/common/src/BankManager.c:43: }
	C$BankManager.c$43$1_0$129	= .
	.globl	C$BankManager.c$43$1_0$129
	XG$PopBank$0$0	= .
	.globl	XG$PopBank$0$0
	ret
	.area _CODE
	.area _INITIALIZER
FBankManager$__xinit_bank_stack$0_0$0 == .
__xinit__bank_stack:
	.dw (_bank_stackSTACK - 1)
	.area _CABS (ABS)
