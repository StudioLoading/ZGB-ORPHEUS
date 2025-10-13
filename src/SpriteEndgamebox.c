#include "Banks/SetAutoBank.h"

#include "BankManager.h"
#include "ZGBMain.h"
#include "Keys.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"
#include "Dialog.h"


const UINT8 a_eg_box_absorb[] = {4, 2,3,4,1};

void eg_box_absorb(Sprite* arg_s_box) BANKED;

void START(){
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void eg_box_absorb(Sprite* arg_s_box) BANKED{
    SetSpriteAnim(arg_s_box, a_eg_box_absorb, 24u);

}

void UPDATE() {

}

void DESTROY() {

}