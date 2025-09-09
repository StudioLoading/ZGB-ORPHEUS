#include "Banks/SetAutoBank.h"

#include "BankManager.h"
#include "ZGBMain.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"


const UINT8 a_carteltext[] = {4, 0,1,1,1};

void START() {
    SetSpriteAnim(THIS, a_carteltext, 12u);
}

void UPDATE() {
}

void DESTROY() {
}