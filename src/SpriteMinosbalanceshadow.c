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
    struct EnemyInfo* balanceshadow_data = (struct EnemyInfo*) THIS->custom_data;
    balanceshadow_data->wait = 100u;
}

void UPDATE() {
    struct EnemyInfo* balanceshadow_data = (struct EnemyInfo*) THIS->custom_data;
    if(balanceshadow_data->wait <= 100u){
        balanceshadow_data->wait--;
        if(balanceshadow_data->wait == 0u){
            SpriteManagerAdd(SpriteMinosplate, THIS->x, 0);
            balanceshadow_data->wait = 101u;
        }
}
}

void DESTROY() {
}