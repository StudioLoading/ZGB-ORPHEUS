#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "CircleMath.h"
#include "custom_datas.h"


const UINT8 a_blade[] = {4, 0,1,2,3};

void START() {
    THIS->lim_x = THIS->x;
    SetSpriteAnim(THIS, a_blade, 64u);
    struct NoteInfo* bladedata = (struct NoteInfo*) THIS->custom_data;
    bladedata->frmskip = 0;
    bladedata->frmskip_max = 12;
    bladedata->wait = 0;
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
}

void DESTROY() {
}