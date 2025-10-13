#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

#define COUNTER_MAX 8

extern UINT16 idle_countdown;

const UINT8 a_owl_idle[] = {6, 1,1,1,2,3,2};

extern UINT8 aeacusbody_move_to_point(Sprite* aea_s_aeacusbody, UINT16 arg_final_posx, UINT16 arg_final_posy) BANKED;

void START() {
    THIS->lim_x = 40u;
    THIS->lim_y = 16u;
    SetSpriteAnim(THIS, a_owl_idle, 32u);
    struct EnemyInfo* owl_data = (struct EnemyInfo*) THIS->custom_data;
    owl_data->e_state = WALK_RIGHT;
	owl_data->tile_collision = 0;
	owl_data->vy = 0;
    owl_data->wait = 0;
	owl_data->frmskip_wait = 0u;
	owl_data->e_configured = 1u;
	owl_data->frmskip = 4u;
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
    struct EnemyInfo* owl_data = (struct EnemyInfo*) THIS->custom_data;
    switch(owl_data->e_configured){
        case 2:{
		    owl_data->frmskip_wait++;
            if(owl_data->frmskip_wait < 2){
                return;
            }
            owl_data->frmskip_wait = 0u;
            if(THIS->y > 78u){
                SpriteManagerRemoveSprite(THIS);
            }
            aeacusbody_move_to_point(THIS, 80u, 84u);
        }break;
    }
}

void DESTROY() {
    idle_countdown = 800u;
}