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


const UINT8 a_eg_euridyce_idle_down[] = {1, 1};
const UINT8 a_eg_euridyce_idle_h[] = {1, 3};
const UINT8 a_eg_euridyce_disappearing[] = {4, 1,2,0,2};
const UINT8 a_eg_euridyce_hidden[] = {1, 0};
const UINT8 a_eg_euridyce_walk_h[] = {4, 3,4,3,5};
const UINT8 a_eg_euridyce_idle_up[] = {1, 6};
const UINT8 a_eg_euridyce_walk_down[] = {2, 1,2};
const UINT8 a_eg_euridyce_champion[] = {1, 7};

void eg_euridyce_idleup(Sprite* arg_s_eg_euridyce) BANKED;
void eg_euridyce_idledown(Sprite* arg_s_eg_euridyce) BANKED;
void eg_euridyce_idleh(Sprite* arg_s_eg_euridyce) BANKED;
void eg_euridyce_walkdown(Sprite* arg_s_eg_euridyce) BANKED;
void eg_euridyce_walkh(Sprite* arg_s_eg_euridyce) BANKED;
void eg_euridyce_champion(Sprite* arg_s_eg_euridyce) BANKED;

 
void START(){
    THIS->lim_x = 1000;
    THIS->lim_y = 1000;
    SetSpriteAnim(THIS, a_eg_euridyce_walk_h, 12);
    THIS->mirror = V_MIRROR;
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void eg_euridyce_idleup(Sprite* arg_s_eg_euridyce) BANKED{
    SetSpriteAnim(arg_s_eg_euridyce, a_eg_euridyce_idle_up, 4u);
}

void eg_euridyce_idledown(Sprite* arg_s_eg_euridyce) BANKED{
    SetSpriteAnim(arg_s_eg_euridyce, a_eg_euridyce_idle_down, 4u);
}
void eg_euridyce_walkdown(Sprite* arg_s_eg_euridyce) BANKED{
    SetSpriteAnim(arg_s_eg_euridyce, a_eg_euridyce_walk_down, 12u);
}
void eg_euridyce_walkh(Sprite* arg_s_eg_euridyce) BANKED{
    SetSpriteAnim(arg_s_eg_euridyce, a_eg_euridyce_walk_h, 12u);
}
void eg_euridyce_idleh(Sprite* arg_s_eg_euridyce) BANKED{
    SetSpriteAnim(arg_s_eg_euridyce, a_eg_euridyce_idle_h, 12u);
}
void eg_euridyce_champion(Sprite* arg_s_eg_euridyce) BANKED{
    SetSpriteAnim(arg_s_eg_euridyce, a_eg_euridyce_champion, 1u);
}

void UPDATE() {

}

void DESTROY() {

}