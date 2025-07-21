#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"


const UINT8 a_balanceshadow[] = {2, 0,1};

void START() {
    SetSpriteAnim(THIS, a_balanceshadow, 64u);
}

void UPDATE() {
}

void DESTROY() {
}