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


const UINT8 a_eg_orpheus_idledown[] = {1, 1};
const UINT8 a_eg_orpheus_disappearing[] = {4, 1,2,0,2};
const UINT8 a_eg_orpheus_hidden[] = {1, 0};
const UINT8 a_eg_orpheus_idleup[] = {1, 6};
const UINT8 a_eg_orpheus_walk_h[] = {4, 3,4,3,5};
const UINT8 a_eg_orpheus_walk_up[] = {4, 6,7,6,8};

void eg_orpheus_go_up(Sprite* arg_s_eg_orpheus) BANKED;
void eg_orpheus_idle_up(Sprite* arg_s_eg_orpheus) BANKED;

void START(){
    THIS->lim_x = 1000;
    THIS->lim_y = 1000;
    SetSpriteAnim(THIS, a_eg_orpheus_walk_h, 8);
    THIS->mirror = V_MIRROR;
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void eg_orpheus_go_up(Sprite* arg_s_eg_orpheus) BANKED{
    SetSpriteAnim(arg_s_eg_orpheus, a_eg_orpheus_walk_up, 12u);
}
void eg_orpheus_idle_up(Sprite* arg_s_eg_orpheus) BANKED{
    SetSpriteAnim(arg_s_eg_orpheus, a_eg_orpheus_idleup, 1u);
}

void UPDATE() {

}

void DESTROY() {

}