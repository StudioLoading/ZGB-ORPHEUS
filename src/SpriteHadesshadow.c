#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

const UINT8 a_hadesshadow[] = {2, 0,1,1,1};

void START() {
    SetSpriteAnim(THIS, a_hadesshadow, 16u);
}

void UPDATE() {
    struct EnemyInfo* hadesshadow_data = (struct EnemyInfo*)THIS->custom_data; 
    hadesshadow_data->wait--;
    if(hadesshadow_data->wait == 0){
        SpriteManagerRemoveSprite(THIS);
    }
}

void DESTROY() {
}