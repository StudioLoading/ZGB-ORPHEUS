#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"


const UINT8 a_charon[] = {10, 1,2,2,3,4,5,4,5,4,5};

UINT8 charon_bounce_count = 0;
Sprite* s_charon_boat = 0;
Sprite* s_charon_hand_left = 0;
Sprite* s_charon_hand_right = 0;

void START() {
    SetSpriteAnim(THIS, a_charon, 8);
    s_charon_boat = SpriteManagerAdd(SpriteCharonboat, ((UINT16) 10u << 3), ((UINT16) 6u << 3));
    s_charon_hand_left = SpriteManagerAdd(SpriteCharonhand, THIS->x - 6u, THIS->y + 4u);
    s_charon_hand_right = SpriteManagerAdd(SpriteCharonhand, THIS->x + 8u, THIS->y + 4u);
    s_charon_hand_right->mirror = V_MIRROR;
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
    charon_bounce_count++;
    if(charon_bounce_count < 10){
        if(charon_bounce_count % 6 == 0){
            THIS->y--;
        }
    }else if(charon_bounce_count < 20){
        if(charon_bounce_count % 4 == 0){
            THIS->y--;
        }
    }else if(charon_bounce_count < 34){
        if(charon_bounce_count % 6 == 0){
            THIS->y--;
        }
    }else if(charon_bounce_count < 40){
    }else if(charon_bounce_count < 48){
        if(charon_bounce_count % 6 == 0){
            THIS->y++;
        }
    }else if(charon_bounce_count < 58){
        if(charon_bounce_count % 4 == 0){
            THIS->y++;
        }
    }else if(charon_bounce_count < 64){
        if(charon_bounce_count % 6 == 0){
            THIS->y++;
        }
    }else if(charon_bounce_count < 80){       
    }else{
        charon_bounce_count = 0u;
    }
    if(s_charon_boat){
        THIS->x = s_charon_boat->x + 7u;
    }
    if(s_charon_hand_left){
        s_charon_hand_left->x = THIS->x - 9u;
        s_charon_hand_left->y = THIS->y+1;
    }
    if(s_charon_hand_right){
        s_charon_hand_right->x = THIS->x + 17u;
        s_charon_hand_right->y = THIS->y+1;
    }
}

void DESTROY() {
}