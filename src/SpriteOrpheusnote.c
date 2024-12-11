#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"


UINT8 frmskip = 0;
INT8 left_right = -2;
INT8 onote_hp = 64;

void START() {
    THIS->lim_x = 10u;
    THIS->lim_y = 10u;
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
    onote_hp = 8;
    frmskip = 0;
    left_right = -2;
}

void UPDATE() {
    if(frmskip < 4){
        frmskip++;
        return;
    }
    frmskip = 0;
    THIS->y--;
    left_right++;
    if(left_right == 8){
        left_right= -2;
    }
    if(left_right < 0){
        THIS->x--;
    }else if(left_right > 0){
        THIS->x++;
    }
    onote_hp--;
    if(onote_hp < 0){
        SpriteManagerRemoveSprite(THIS);
    }

}

void DESTROY() {
}