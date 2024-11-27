#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

#define COUNTER_MAX 8

extern UINT16 idle_countdown;

const UINT8 a_note_0[] = {1, 0};
const UINT8 a_note_1[] = {1, 1};
const UINT8 a_note_2[] = {1, 2};

void START() {
    SetSpriteAnim(THIS, a_note_0, 1u);
    struct EnemyInfo* note_data = (struct EnemyInfo*) THIS->custom_data;
    note_data->e_state = WALK_RIGHT;
	note_data->tile_collision = 0;
	note_data->vy = 0;
    note_data->wait = 0;
	note_data->frmskip_wait = 0u;
	note_data->e_configured = 0u;
	note_data->frmskip = 4u;
    note_data->vx = 1;
    THIS->lim_x = 20u;
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
    struct EnemyInfo* note_data = (struct EnemyInfo*) THIS->custom_data;
    switch(note_data->e_configured){
        case 0: return; break;
        case 1:
            SetSpriteAnim(THIS, a_note_0, 1u);
	        note_data->e_configured = 4u;
        break;
        case 2:
            SetSpriteAnim(THIS, a_note_1, 1u);
	        note_data->e_configured = 4u;
        break;
        case 3:
            SetSpriteAnim(THIS, a_note_2, 1u);
	        note_data->e_configured = 4u;
        break;
        case 4:
            note_data->frmskip_wait++;
            if(note_data->frmskip_wait < note_data->frmskip){
                return;
            }
            note_data->frmskip_wait = 0u;
            note_data->wait++;
            if(note_data->wait > 16){
                note_data->vy = 1;
            }else if(note_data->wait > 2){
                note_data->vy = -1;
            }else{
                note_data->vy = 0;
            }
            if(note_data->wait > 30){note_data->wait = 0;}
            UINT8 ghost_collision = TranslateSprite(THIS, note_data->vx << delta_time, note_data->vy << delta_time);
        break;
    }
}

void DESTROY() {
}