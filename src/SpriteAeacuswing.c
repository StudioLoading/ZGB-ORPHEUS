#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"


const UINT8 a_aeacuswing_opened[] = {1, 1};
const UINT8 a_aeacuswing_fly[] = {5, 1,1,1,2,3};
const UINT8 a_aeacuswing_hit[] = {2, 0,1};

void START() {
    THIS->lim_x = 10u;
    THIS->lim_y = 10u;
    SetSpriteAnim(THIS, a_aeacuswing_fly, 12u);
}

void UPDATE() {
}

void DESTROY() {
}