#include "Banks/SetAutoBank.h"

#include "BankManager.h"
#include "ZGBMain.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"


const UINT8 i_heart[] = {2, 0,1};

void START() {
    THIS->lim_x = 1000;
    THIS->lim_y = 1000;
}

void UPDATE() {
    struct ItemInfo* i_data = (struct ItemInfo*) THIS->custom_data; 
    switch(i_data->i_configured){
        case 0u:
        break;
        case 1u:
            switch(i_data->item_type){
                case HEART: SetSpriteAnim(THIS, i_heart, 24u); break;
            }
            i_data->i_configured = 2;
        break;
    }
}

void DESTROY() {
}