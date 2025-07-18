#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"


const UINT8 a_minosplate_load[] = {2, 0,1};
const UINT8 a_minosplate[] = {1, 1};

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
    plate_data->e_state = GENERIC_IDLE;
    plate_data->wait = 60u;
    plate_data->e_configured = 0u;
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
            plate_data->wait--;
            if(plate_data->wait == 0){
                switch(plate_data->e_configured){
                    case 0u: //nothing
                    case 1u: //common over
                    break;
                    case 2u: //Orpheus over
                    break;
                }
                minosplate_change_state(THIS, WALK_UP);
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
                if(plate_data->wait == 40u){
                    SpriteManagerRemoveSprite(THIS);
                }
            }
        break;
    }
}
void minosplate_change_state(Sprite* arg_s_cerberus, SPRITE_STATES arg_new_state) BANKED{
    struct EnemyInfo* plate_data = (struct EnemyInfo*) arg_s_cerberus->custom_data;
    switch(arg_new_state){
        case GENERIC_WALK:
            plate_data->wait = 250u;
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
}