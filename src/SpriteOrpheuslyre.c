#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"


const UINT8 i_olyre[] = {4, 0,1,2,3};

void START() {
    THIS->lim_x = 10u;
    THIS->lim_y = 10u;
    SetSpriteAnim(THIS, i_olyre, 12u);
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
}

void DESTROY() {
}