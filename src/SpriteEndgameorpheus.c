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
const UINT8 a_eg_orpheus_walk_h[] = {4, 3,4,3,5};
const UINT8 a_eg_orpheus_walk_up[] = {4, 6,7,6,8};

void START(){
    THIS->lim_x = 1000;
    THIS->lim_y = 1000;
    SetSpriteAnim(THIS, a_eg_orpheus_walk_h, 8);
    THIS->mirror = V_MIRROR;
}

void UPDATE() {

}

void DESTROY() {

}