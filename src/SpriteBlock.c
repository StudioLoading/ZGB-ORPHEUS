#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

#define COUNTER_MAX 8

void START() {
    THIS->lim_x = 1000u;
    THIS->lim_y = 1000u;
    struct ItemInfo* i_data = (struct ItemInfo*) THIS->custom_data;
    i_data->item_type = BLOCK;
    i_data->i_configured = 2;
    i_data->counter_x = 0;
    i_data->counter_y = 0;
    i_data->counter_verso = 0;
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
    struct ItemInfo* i_data = (struct ItemInfo*) THIS->custom_data;
    INT8 vx = 0;
    INT8 vy = 0;
    if(i_data->counter_x >= COUNTER_MAX){
        vx = i_data->counter_verso;
        i_data->counter_x = 0;
    }
    if(i_data->counter_y >= COUNTER_MAX){
        vy = i_data->counter_verso;
        i_data->counter_y = 0;
    }
    if(vx != 0 || vy != 0){
        UINT8 block_tile_coll = TranslateSprite(THIS, vx << delta_time, vy << delta_time);
    }
}

void DESTROY() {
}