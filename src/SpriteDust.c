#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Sprite.h"
#include "SpriteManager.h"

const UINT8 dust_anim[] = {4, 0, 1, 2, 2};

void START(){
    SetSpriteAnim(THIS,dust_anim, 32u);
}

void UPDATE(){
    THIS->y--;
    if(THIS->anim_frame == 3){
        SpriteManagerRemoveSprite(THIS);
    }
}

void DESTROY(){
}