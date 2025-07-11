#ifndef ZGBMAIN_H
#define ZGBMAIN_H

#define STATES \
_STATE(StateCredit)\
_STATE(StateIntro)\
_STATE(StateStart)\
_STATE(StateTutorial)\
_STATE(StateCartel)\
_STATE(StateHades00)\
_STATE(StateBoss00)\
_STATE(StateEnddemo)\
STATE_DEF_END

#define SPRITES \
_SPRITE_DMG(SpriteNote, note)\
_SPRITE_DMG(SpriteButterfly, butterfly)\
_SPRITE_DMG(SpriteDog, dog)\
_SPRITE_DMG(SpriteDogexclamation, dogexclamation)\
_SPRITE_DMG(SpriteOrpheus, orpheus)\
_SPRITE_DMG(SpriteOrpheuslyre, orpheuslyre)\
_SPRITE_DMG(SpriteOrpheusnote, orpheusnote)\
_SPRITE_DMG(SpriteCamera, camera)\
_SPRITE_DMG(SpriteItem, item)\
_SPRITE_DMG(SpriteLyre, lyre)\
_SPRITE_DMG(SpriteGate, gate)\
_SPRITE_DMG(SpriteBlock, block)\
_SPRITE_DMG(SpriteSkeleton, enemyskeletor)\
_SPRITE_DMG(SpriteSkeletonshield, enemyskeletorshield)\
_SPRITE_DMG(SpriteInfernalimp, enemyinfernalimp)\
_SPRITE_DMG(SpriteLostsoul, enemylostsoul)\
_SPRITE_DMG(SpriteGhost, ghost)\
_SPRITE_DMG(SpriteDeath, death)\
_SPRITE_DMG(SpriteCharon, charon)\
_SPRITE_DMG(SpriteCharonhand, charonhand)\
_SPRITE_DMG(SpriteCharonboat, charonboat)\
_SPRITE_DMG(SpriteBlade, enemyblade)\
_SPRITE_DMG(SpriteFireball, fireball)\
_SPRITE_DMG(SpriteStone, stone)\
_SPRITE_DMG(SpriteTartarus, enemytartarus)\
_SPRITE_DMG(SpriteOoze, enemyooze)\
_SPRITE_DMG(SpriteSentinel, enemysentinel)\
_SPRITE_DMG(SpriteSiren, enemysiren)\
SPRITE_DEF_END

#include "ZGBMain_Init.h"

#endif