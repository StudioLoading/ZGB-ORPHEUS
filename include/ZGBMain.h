#ifndef ZGBMAIN_H
#define ZGBMAIN_H

#define STATES \
_STATE(StateStart)\
_STATE(StateTutorial)\
_STATE(StateHades00)\
_STATE(StateBoss00)\
STATE_DEF_END

#define SPRITES \
_SPRITE_DMG(SpriteOrpheus, orpheus)\
_SPRITE_DMG(SpriteCamera, camera)\
_SPRITE_DMG(SpriteItem, item)\
_SPRITE_DMG(SpriteLyre, lyre)\
_SPRITE_DMG(SpriteGate, gate)\
_SPRITE_DMG(SpriteBlock, block)\
_SPRITE_DMG(SpriteSkeleton, enemyskeletor)\
_SPRITE_DMG(SpriteGhost, ghost)\
_SPRITE_DMG(SpriteDeath, death)\
SPRITE_DEF_END

#include "ZGBMain_Init.h"

#endif