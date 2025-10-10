#include "Banks/SetAutoBank.h"

#include "BankManager.h"
#include "ZGBMain.h"
#include "Keys.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

const UINT8 a_eg_hadesclaw[] = {1, 1};
const UINT8 a_eg_hadesclaw_blink[] = {2, 0,1};

void eg_hadesclaw_appear(Sprite* arg_s_eg_hadesclaw) BANKED;

 
void START(){
    THIS->lim_x = 1000;
    THIS->lim_y = 1000;
    SetSpriteAnim(THIS, a_eg_hadesclaw_blink, 24);
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void eg_hadesclaw_appear(Sprite* arg_s_eg_hadesclaw) BANKED{
    SetSpriteAnim(arg_s_eg_hadesclaw, a_eg_hadesclaw, 1);
}


void UPDATE() {

}

void DESTROY() {

}