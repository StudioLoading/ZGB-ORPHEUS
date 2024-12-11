#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

#define BOAT_COUNT_MAX 80

UINT8 boat_count = 0u;

void START() {
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
    boat_count++;
    if(boat_count > BOAT_COUNT_MAX){
        boat_count = 0;
    }
    switch(boat_count){
        case 40:
            THIS->y++;
        break;
        case 80:
            THIS->y--;
        break;
    }
}

void DESTROY() {
}