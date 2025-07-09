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
extern void spawn_death_animation(UINT16 spawnx, UINT16 spawny) BANKED;


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
    SPRITE_SET_PALETTE(THIS,1);
    if(bladedata->frmskip >= bladedata->frmskip_max){
        bladedata->frmskip = 0;
        UINT8 cos_position = bladedata->wait + 64u;
        THIS->x = THIS->lim_x + ((sine_wave[cos_position]) >> 3);
        //THIS->y = THIS->lim_y + ((sine_wave[bladedata->wait]) >> 3);
        bladedata->wait += 3;
    }if(bladedata->frmskip < (bladedata->frmskip_max >> 1)){
        SPRITE_SET_PALETTE(THIS,0);
    }
    //CHECK TILE OVERLAPPING FOR PITS!
        UINT8 tile = GetScrollTile((THIS->x + 8) >> 3, (THIS->y+8) >> 3);
        if(tile == 20u || tile == 21u || tile == 66u || (tile >= 78u && tile <= 83u)){
            SpriteManagerRemoveSprite(THIS);
            return;
        }
    //SPRITE COLLISION
        UINT8 scroll_bl_tile;
        Sprite* iblspr;
        SPRITEMANAGER_ITERATE(scroll_bl_tile, iblspr) {
            if(CheckCollision(THIS, iblspr)) {
                if(iblspr->type == SpriteOrpheus){
                    orpheus_change_state(iblspr, HIT);
                }else if(iblspr->type == SpriteFireball){
                    struct EnemyInfo* fireball_data = (struct EnemyInfo*) iblspr->custom_data;
                    if(fireball_data->e_configured == 2){//super fireball!
                        SpriteManagerRemoveSprite(THIS);
                    }

            }
        }
    }
}

void DESTROY() {
    spawn_death_animation(THIS->x + 8u, THIS->y + 8u);
}