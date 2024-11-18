#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

#define COUNTER_MAX 8

const UINT8 a_block[] = {1, 0};
const UINT8 a_door_enemy[] = {1, 1};
const UINT8 a_door[] = {1, 2};
const UINT8 a_door_key[] = {1, 3};


void START() {
    THIS->lim_x = 1000u;
    THIS->lim_y = 1000u;
    struct ItemInfo* i_data = (struct ItemInfo*) THIS->custom_data;
    i_data->item_type = BLOCK;
    i_data->i_configured = 0;
    i_data->counter_x = 0;
    i_data->counter_y = 0;
    i_data->counter_verso = 0;
    /*if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }*/
}

void UPDATE() {
    struct ItemInfo* i_data = (struct ItemInfo*) THIS->custom_data;
    switch(i_data->i_configured){
        case 0u: return; break;
        case 1u: // ANIMATIONS according to item_type
            switch(i_data->item_type){
                case BLOCK: SetSpriteAnim(THIS, a_block, 1u); i_data->i_configured = 2; break;
                case DOOR:  SetSpriteAnim(THIS, a_door, 1u); i_data->i_configured = 3; break;
                case DOOR_KEY:  SetSpriteAnim(THIS, a_door_key, 1u); i_data->i_configured = 3; break;
                case DOOR_ENEMY:  SetSpriteAnim(THIS, a_door_enemy, 1u); i_data->i_configured = 3; break;
            }
        break;
        case 2u:// PUSHABLE BLOCK
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
                TranslateSprite(THIS, vx << delta_time, vy << delta_time);
            }
        break;
        case 3u: // STOP REASONING
        break;
    }
}

void DESTROY() {
}