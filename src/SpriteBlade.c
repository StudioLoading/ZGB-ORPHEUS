#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "CircleMath.h"
#include "custom_datas.h"

const UINT8 a_blade[] = {4, 0,1,2,3};

extern void orpheus_change_state(Sprite* arg_s_orpheus, SPRITE_STATES arg_new_state) BANKED;


void START() {
    THIS->lim_x = THIS->x;
    SetSpriteAnim(THIS, a_blade, 64u);
    struct NoteInfo* bladedata = (struct NoteInfo*) THIS->custom_data;
    bladedata->frmskip = 0;
    bladedata->frmskip_max = 12;
    bladedata->wait = 0;
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
    struct NoteInfo* bladedata = (struct NoteInfo*) THIS->custom_data;
    bladedata->frmskip++;
    if(bladedata->frmskip >= bladedata->frmskip_max){
        bladedata->frmskip = 0;
        UINT8 cos_position = bladedata->wait + 64u;
        THIS->x = THIS->lim_x + ((sine_wave[cos_position]) >> 3);
        //THIS->y = THIS->lim_y + ((sine_wave[bladedata->wait]) >> 3);
        bladedata->wait += 3;
    }
    //SPRITE COLLISION
        UINT8 scroll_bl_tile;
        Sprite* iblspr;
        SPRITEMANAGER_ITERATE(scroll_bl_tile, iblspr) {
            if(CheckCollision(THIS, iblspr)) {
                if(iblspr->type == SpriteOrpheus){
                    orpheus_change_state(iblspr, HIT);
                }
            }
        }
}

void DESTROY() {
}