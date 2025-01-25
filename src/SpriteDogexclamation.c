#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"


const UINT8 a_exclamation[] = {1, 1};

void START() {
    SetSpriteAnim(THIS, a_exclamation, 4u);
    struct ExclamationInfo*  exclamation_data= (struct ExclamationInfo*) THIS->custom_data;
    exclamation_data->counter = 120;
}

void UPDATE() {
    struct ExclamationInfo* exclamation_data = (struct ExclamationInfo*) THIS->custom_data;
    exclamation_data->counter--;
    if(exclamation_data->counter <= 0){
        SpriteManagerRemoveSprite(THIS);
    }
}

void DESTROY() {
}