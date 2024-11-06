;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module ZGBMain_Init
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _InitSprites
	.globl _Destroy_SpriteSkeleton
	.globl _Update_SpriteSkeleton
	.globl _Start_SpriteSkeleton
	.globl _Destroy_SpriteCamera
	.globl _Update_SpriteCamera
	.globl _Start_SpriteCamera
	.globl _Destroy_SpriteOrpheus
	.globl _Update_SpriteOrpheus
	.globl _Start_SpriteOrpheus
	.globl _InitStates
	.globl _Update_UtilEnemy
	.globl _Start_UtilEnemy
	.globl _Update_StateGame
	.globl _Start_StateGame
	.globl _spritePalsOffset
	.globl _spriteIdxs
	.globl _spriteDatas
	.globl _spriteDestroyFuncs
	.globl _spriteUpdateFuncs
	.globl _spriteStartFuncs
	.globl _spriteDataBanks
	.globl _spriteBanks
	.globl _updateFuncs
	.globl _startFuncs
	.globl _stateBanks
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
G$stateBanks$0_0$0==.
_stateBanks::
	.ds 2
G$startFuncs$0_0$0==.
_startFuncs::
	.ds 4
G$updateFuncs$0_0$0==.
_updateFuncs::
	.ds 4
G$spriteBanks$0_0$0==.
_spriteBanks::
	.ds 3
G$spriteDataBanks$0_0$0==.
_spriteDataBanks::
	.ds 3
G$spriteStartFuncs$0_0$0==.
_spriteStartFuncs::
	.ds 6
G$spriteUpdateFuncs$0_0$0==.
_spriteUpdateFuncs::
	.ds 6
G$spriteDestroyFuncs$0_0$0==.
_spriteDestroyFuncs::
	.ds 6
G$spriteDatas$0_0$0==.
_spriteDatas::
	.ds 6
G$spriteIdxs$0_0$0==.
_spriteIdxs::
	.ds 3
G$spritePalsOffset$0_0$0==.
_spritePalsOffset::
	.ds 3
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
	G$InitStates$0$0	= .
	.globl	G$InitStates$0$0
	C$ZGBMain_Init.c$16$0_0$158	= .
	.globl	C$ZGBMain_Init.c$16$0_0$158
;C:/ZGB-2023.0/common/src/ZGBMain_Init.c:16: void InitStates() {
;	---------------------------------
; Function InitStates
; ---------------------------------
_InitStates::
	C$ZGBMain_Init.c$17$1_0$158	= .
	.globl	C$ZGBMain_Init.c$17$1_0$158
;C:/ZGB-2023.0/common/src/ZGBMain_Init.c:17: STATES
	ld	hl, #_startFuncs
	ld	(hl), #<(_Start_StateGame)
	inc	hl
	ld	(hl), #>(_Start_StateGame)
	ld	hl, #_updateFuncs
	ld	(hl), #<(_Update_StateGame)
	inc	hl
	ld	(hl), #>(_Update_StateGame)
	ld	bc, #_stateBanks+0
	ld	a, #<(___bank_StateGame)
	ld	(bc), a
	ld	hl, #(_startFuncs + 2)
	ld	(hl), #<(_Start_UtilEnemy)
	inc	hl
	ld	(hl), #>(_Start_UtilEnemy)
	ld	hl, #(_updateFuncs + 2)
	ld	(hl), #<(_Update_UtilEnemy)
	inc	hl
	ld	(hl), #>(_Update_UtilEnemy)
	inc	bc
	ld	a, #<(___bank_UtilEnemy)
	ld	(bc), a
	C$ZGBMain_Init.c$18$1_0$158	= .
	.globl	C$ZGBMain_Init.c$18$1_0$158
;C:/ZGB-2023.0/common/src/ZGBMain_Init.c:18: }
	C$ZGBMain_Init.c$18$1_0$158	= .
	.globl	C$ZGBMain_Init.c$18$1_0$158
	XG$InitStates$0$0	= .
	.globl	XG$InitStates$0$0
	ret
	G$InitSprites$0$0	= .
	.globl	G$InitSprites$0$0
	C$ZGBMain_Init.c$49$1_0$159	= .
	.globl	C$ZGBMain_Init.c$49$1_0$159
;C:/ZGB-2023.0/common/src/ZGBMain_Init.c:49: void InitSprites() {
;	---------------------------------
; Function InitSprites
; ---------------------------------
_InitSprites::
	C$ZGBMain_Init.c$50$1_0$159	= .
	.globl	C$ZGBMain_Init.c$50$1_0$159
;C:/ZGB-2023.0/common/src/ZGBMain_Init.c:50: SPRITES
	ld	a, #<(___bank_SpriteOrpheus)
	ld	(#_spriteBanks),a
	ld	hl, #_spriteStartFuncs
	ld	(hl), #<(_Start_SpriteOrpheus)
	inc	hl
	ld	(hl), #>(_Start_SpriteOrpheus)
	ld	hl, #_spriteUpdateFuncs
	ld	(hl), #<(_Update_SpriteOrpheus)
	inc	hl
	ld	(hl), #>(_Update_SpriteOrpheus)
	ld	hl, #_spriteDestroyFuncs
	ld	a, #<(_Destroy_SpriteOrpheus)
	ld	(hl+), a
	ld	(hl), #>(_Destroy_SpriteOrpheus)
	ld	bc, #_spriteDataBanks+0
	ld	a, #<(___bank_orpheus)
	ld	(bc), a
	ld	hl, #_spriteDatas
	ld	a, #<(_orpheus)
	ld	(hl+), a
	ld	(hl), #>(_orpheus)
	ld	de, #_spriteBanks + 1
	ld	a, #<(___bank_SpriteCamera)
	ld	(de), a
	ld	hl, #(_spriteStartFuncs + 2)
	ld	(hl), #<(_Start_SpriteCamera)
	inc	hl
	ld	(hl), #>(_Start_SpriteCamera)
	ld	hl, #(_spriteUpdateFuncs + 2)
	ld	(hl), #<(_Update_SpriteCamera)
	inc	hl
	ld	(hl), #>(_Update_SpriteCamera)
	ld	hl, #(_spriteDestroyFuncs + 2)
	ld	(hl), #<(_Destroy_SpriteCamera)
	inc	hl
	ld	(hl), #>(_Destroy_SpriteCamera)
	ld	e, c
	ld	d, b
	inc	de
	ld	a, #<(___bank_camera)
	ld	(de), a
	ld	hl, #(_spriteDatas + 2)
	ld	(hl), #<(_camera)
	inc	hl
	ld	(hl), #>(_camera)
	ld	de, #_spriteBanks + 2
	ld	a, #<(___bank_SpriteSkeleton)
	ld	(de), a
	ld	hl, #(_spriteStartFuncs + 4)
	ld	(hl), #<(_Start_SpriteSkeleton)
	inc	hl
	ld	(hl), #>(_Start_SpriteSkeleton)
	ld	hl, #(_spriteUpdateFuncs + 4)
	ld	(hl), #<(_Update_SpriteSkeleton)
	inc	hl
	ld	(hl), #>(_Update_SpriteSkeleton)
	ld	hl, #(_spriteDestroyFuncs + 4)
	ld	a, #<(_Destroy_SpriteSkeleton)
	ld	(hl+), a
	ld	(hl), #>(_Destroy_SpriteSkeleton)
	inc	bc
	inc	bc
	ld	a, #<(___bank_enemyskeletor)
	ld	(bc), a
	ld	hl, #(_spriteDatas + 4)
	ld	a, #<(_enemyskeletor)
	ld	(hl+), a
	ld	(hl), #>(_enemyskeletor)
	C$ZGBMain_Init.c$51$1_0$159	= .
	.globl	C$ZGBMain_Init.c$51$1_0$159
;C:/ZGB-2023.0/common/src/ZGBMain_Init.c:51: }
	C$ZGBMain_Init.c$51$1_0$159	= .
	.globl	C$ZGBMain_Init.c$51$1_0$159
	XG$InitSprites$0$0	= .
	.globl	XG$InitSprites$0$0
	ret
	.area _CODE_1
	.area _INITIALIZER
	.area _CABS (ABS)
