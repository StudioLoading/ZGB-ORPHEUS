#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "CircleMath.h"
#include "custom_datas.h"

extern Sprite* s_orpheus;
extern UINT8 flag_paused;

UINT8 frmskip = 0;
INT8 left_right = -2;
INT8 onote_hp = 64;

extern void orpheus_change_state(Sprite* arg_s_orpheus, SPRITE_STATES arg_new_state) BANKED;

void START() {
    THIS->lim_x = 10u;
    THIS->lim_y = 10u;
    onote_hp = 12;
    frmskip = 0;
    left_right = -2;
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
    if(flag_paused){ return; }
    struct NoteInfo* notedata = (struct NoteInfo*) THIS->custom_data;
    switch(notedata->is_enemy){
        case 0u:{//NOT AN ENEMY
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
        break;
        case 1u:{//ENEMY NOTE
            notedata->frmskip++;
            if(notedata->frmskip >= notedata->frmskip_max){
                UINT8 note_tile_coll = 0u;
                switch(notedata->movement){
                    case NOTE_MOV_SIN:
                        UINT8 cos_position = notedata->wait + 64u;
                        THIS->x = THIS->lim_x + ((sine_wave[cos_position]) >> 3);
                        THIS->y = THIS->lim_y + ((sine_wave[notedata->wait]) >> 3);
                        notedata->wait += 24;
                        THIS->lim_x += notedata->vx;
                        THIS->lim_y += notedata->vy;
                    break;
                    case NOTE_MOV_D:
                        note_tile_coll = TranslateSprite(THIS, notedata->vx << delta_time, notedata->vy << delta_time);
                    break;
                    case NOTE_MOV_H:
                        note_tile_coll = TranslateSprite(THIS, notedata->vx << delta_time, 0);
                    break;
                    case NOTE_MOV_V:
                        note_tile_coll = TranslateSprite(THIS, 0, notedata->vy << delta_time);
                    break;
                }
                notedata->frmskip = 0;
                //CHECK LIMITS
                    if(THIS->y < 24u || THIS->y > 128u || THIS->x < 8u || THIS->x > 144u || note_tile_coll){
                        SpriteManagerRemoveSprite(THIS);
                    }
            }
            //SPRITE COLLISION
            UINT8 scroll_enote_tile;
            Sprite* ienotespr;
            SPRITEMANAGER_ITERATE(scroll_enote_tile, ienotespr) {
                if(CheckCollision(THIS, ienotespr)) {
                    if(ienotespr->type == SpriteOrpheus){
                        orpheus_change_state(s_orpheus, HIT);
                        SpriteManagerRemoveSprite(THIS);
                    }
                }
            }
        }
        break;
    }

}

void DESTROY() {
}