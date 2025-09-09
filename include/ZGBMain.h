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
_SPRITE_DMG(SpriteLanguage, language)\
_SPRITE_DMG(SpriteNote, note)\
_SPRITE_DMG(SpriteCarteltext, carteltext)\
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
_SPRITE_DMG(SpriteImpminos, enemyimpminos)\
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
_SPRITE_DMG(SpriteShadow, enemyshadow)\
_SPRITE_DMG(SpriteBanshee, enemybanshee)\
_SPRITE_DMG(SpriteMagma, enemymagma)\
_SPRITE_DMG(SpriteFrost, enemyfrost)\
_SPRITE_DMG(SpriteSerpent, enemyserpent)\
_SPRITE_DMG(SpriteWyrmling, enemywyrmling)\
_SPRITE_DMG(SpriteDevourer, enemydevourer)\
_SPRITE_DMG(SpriteRevenant, enemyrevenant)\
_SPRITE_DMG(SpriteMinion, enemyminion)\
_SPRITE_DMG(SpriteCerberushead, cerberushead)\
_SPRITE_DMG(SpriteSkeletoncerberus, enemyskeletorcerberus)\
_SPRITE_DMG(SpriteMinosscale, minosscale)\
_SPRITE_DMG(SpriteMinosplate, minosplate)\
_SPRITE_DMG(SpriteMinosbalanceshadow, minosbalanceshadow)\
_SPRITE_DMG(SpriteAeacuswing, aeacuswing)\
_SPRITE_DMG(SpriteAeacusblade, aeacusblade)\
_SPRITE_DMG(SpriteAeacusbody, aeacusbody)\
_SPRITE_DMG(SpriteRadamanthus, radamanthus)\
_SPRITE_DMG(SpriteRadamanthusshadow, radamanthusshadow)\
_SPRITE_DMG(SpriteRadamanthusbrick, radamanthusbrick)\
_SPRITE_DMG(SpriteHadesskull, hadesskull)\
_SPRITE_DMG(SpriteHadesclaw, hadesclaw)\
_SPRITE_DMG(SpriteHadesshadow, hadesshadow)\
SPRITE_DEF_END

#include "ZGBMain_Init.h"

#endif