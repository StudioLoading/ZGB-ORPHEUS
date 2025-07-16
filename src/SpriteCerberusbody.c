#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"


const UINT8 a_cerberusbody[] = {1, 1};
const UINT8 a_cerberusbody_hit[] = {2, 0,1};

extern UINT8 boss_intro;

void START() {
    SetSpriteAnim(THIS, a_cerberusbody, 1);
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
}

void DESTROY() {
}