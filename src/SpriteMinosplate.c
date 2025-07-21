#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"


const UINT8 a_minosplate_load[] = {2, 0,1};
const UINT8 a_minosplate[] = {1, 1};

UINT8 boss_minos_flag_orpheus_on_plate = 0u;

extern Sprite* s_minosscale;
extern Sprite* s_plate;

extern void minosscale_change_state(Sprite* arg_s_cerberus, SPRITE_STATES arg_new_state) BANKED;
extern void orpheus_change_state(Sprite* arg_s_orpheus, SPRITE_STATES arg_new_state) BANKED;
extern void e_destroy(Sprite* s_enemy) BANKED;
extern UINT8 is_enemy(UINT8 arg_sprite_type) BANKED;

/*
	SPRITE_STATES e_state;
	UINT8 tile_collision;
	INT8 vx;
	INT8 vy;
    UINT8 wait;
	UINT8 frmskip_wait;
	UINT8 e_configured;
	UINT8 frmskip;
 */
void minosplate_change_state(Sprite* arg_s_cerberus, SPRITE_STATES arg_new_state) BANKED;


void START() {
    THIS->lim_x = 10u;
    THIS->lim_y = 10u;
    SetSpriteAnim(THIS, a_minosplate_load, 24u);
    struct EnemyInfo* plate_data = (struct EnemyInfo*) THIS->custom_data;
    plate_data->e_state = WALK_DOWN;
    plate_data->wait = 60u;
    plate_data->e_configured = 0u;
    plate_data->frmskip_wait = 0;
    plate_data->frmskip = 4;
    boss_minos_flag_orpheus_on_plate = 0u;
}

void UPDATE() {
    struct EnemyInfo* plate_data = (struct EnemyInfo*) THIS->custom_data;
    switch(plate_data->e_state){
        case GENERIC_IDLE://loading
            plate_data->wait--;
            if(plate_data->wait == 0){
                minosplate_change_state(THIS, GENERIC_WALK);
            }
        break;
        case GENERIC_WALK://wait for heavy
            plate_data->frmskip_wait++;
            if(plate_data->frmskip_wait >= plate_data->frmskip){
                plate_data->frmskip_wait = 0;
                plate_data->wait--;
            }
            if(plate_data->wait == 0){
                switch(plate_data->e_configured){
                    case 0u: //nothing
                    case 2u: //common over
                        minosplate_change_state(THIS, WALK_UP);
                    break;
                    case 1u: //Orpheus over
                    break;
                }
            }
        break;
        case WALK_UP:
            plate_data->frmskip_wait++;
            if(plate_data->frmskip_wait >= plate_data->frmskip){
                plate_data->wait++;
                switch(plate_data->e_configured){
                    case 0u: //nothing
                    case 1u: //common over
                        THIS->x += plate_data->vx;
                        THIS->y += plate_data->vy;
                    break;
                    case 2u: //Orpheus over
                    break;
                }
                if(plate_data->wait == 60u){
                    minosscale_change_state(s_minosscale, GENERIC_IDLE);
                    SpriteManagerRemoveSprite(THIS);
                }
            }
        break;
        case WALK_DOWN:{
            /*
            plate_data->frmskip_wait++;
            if(plate_data->frmskip_wait >= plate_data->frmskip){
                plate_data->frmskip_wait = 0;
            */
            plate_data->vy = 1;
            TranslateSprite(THIS, 0, plate_data->vy << delta_time);
            UINT8 scroll_ms_tile;
            Sprite* imsspr;
            SPRITEMANAGER_ITERATE(scroll_ms_tile, imsspr) {
                if(CheckCollision(THIS, imsspr)) {
                    switch(imsspr->type){
                        case SpriteOrpheus:
                            //orpheus_change_state(imsspr, HIT);
                        break;
                        case SpriteMinosbalanceshadow:
                            THIS->y = imsspr->y;
                            SpriteManagerRemoveSprite(imsspr);
                            minosplate_change_state(THIS, GENERIC_IDLE);
                        break;
                        default:
                            THIS->y += plate_data->vy;
                        break;
                    }
                }
            }
            //}
        }break;
    }
}

void minosplate_change_state(Sprite* arg_s_cerberus, SPRITE_STATES arg_new_state) BANKED{
    struct EnemyInfo* plate_data = (struct EnemyInfo*) arg_s_cerberus->custom_data;
    switch(arg_new_state){
        case GENERIC_IDLE:
            plate_data->wait = 10u;
            //SetSpriteAnim(THIS, a_minosplate_load, 24u);
        break;
        case GENERIC_WALK:
            plate_data->wait = 80u;
            SetSpriteAnim(arg_s_cerberus, a_minosplate, 1u);
        break;
        case WALK_UP:
            plate_data->wait = 0u;
            plate_data->frmskip_wait = 0;
            plate_data->frmskip = 4;
            plate_data->vy = -1;
            plate_data->vx = 0;
        break;
    }
    plate_data->e_state = arg_new_state;
}

void DESTROY() {
    if(THIS->unique_id == s_plate->unique_id){
        s_plate = 0;
    }
    //destroy all the plates!
    UINT8 scroll_mp_tile;
    Sprite* impspr;
    SPRITEMANAGER_ITERATE(scroll_mp_tile, impspr) {
        switch(impspr->type){
            case SpriteMinosplate:{
                SpriteManagerRemoveSprite(impspr);
            }
        }
    }
}