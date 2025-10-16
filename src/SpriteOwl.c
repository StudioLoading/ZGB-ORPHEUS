#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "Dialog.h"
#include "custom_datas.h"

#define COUNTER_MAX 8

extern UINT16 idle_countdown;
extern MACROMAP current_map;

const UINT8 a_owl_idle[] = {1, 1};
const UINT8 a_owl_descend[] = {1, 3};
const UINT8 a_owl_fly[] = {4, 3,4,3,2};

extern UINT8 aeacusbody_move_to_point(Sprite* aea_s_aeacusbody, UINT16 arg_final_posx, UINT16 arg_final_posy) BANKED;
extern void spawn_item(ITEM_TYPE arg_item_type, UINT16 arg_spawnx, UINT16 arg_spawny, UINT8 arg_hp_max) BANKED;
extern UINT8 prepare_dialog(WHOSTALKING arg_whostalking) BANKED;
void orpheus_show_cartel() BANKED;

void START() {
    THIS->lim_x = 40u;
    THIS->lim_y = 16u;
    SetSpriteAnim(THIS, a_owl_idle, 1u);
    struct EnemyInfo* owl_data = (struct EnemyInfo*) THIS->custom_data;
	owl_data->e_state = IDLE_DOWN;
	owl_data->tile_collision = 0;
	owl_data->vx = -2;
	owl_data->vy = 1;
    owl_data->wait = 0;
	owl_data->frmskip_wait = 0u;
	owl_data->e_configured = 1u;
	owl_data->frmskip = 2u;
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
    struct EnemyInfo* owl_data = (struct EnemyInfo*) THIS->custom_data;
    switch(owl_data->e_configured){
        case 1:{
        }break;
        case 2:{
            owl_data->frmskip_wait++;
            if(owl_data->frmskip_wait < owl_data->frmskip){
                return;
            }
            owl_data->frmskip_wait = 0;
            TranslateSprite(THIS, owl_data->vx << delta_time, owl_data->vy << delta_time);
            UINT8 move_to_jump = 0u;
            if(owl_data->e_state == WALK_RIGHT && THIS->x > 80u){
                move_to_jump = 1u;
            }else if(owl_data->e_state == WALK_LEFT && THIS->x < 80u){
                move_to_jump = 1u;
            }
            if(move_to_jump){
                owl_data->vy = -2;
                owl_data->frmskip = 1;
                SetSpriteAnim(THIS, a_owl_fly, 40u);
                owl_data->e_state = JUMP;
            }
        }break;
        case 3:{//fly away
            spawn_item(HEART, THIS->x + 8u, THIS->y + 24u, 0);
            SetSpriteAnim(THIS, a_owl_fly, 40u);
            owl_data->frmskip = 1;
            owl_data->e_configured = 4;
        }break;
        case 4:{
            owl_data->frmskip_wait++;
            if(owl_data->frmskip_wait < owl_data->frmskip){
                return;
            }
            owl_data->frmskip_wait = 0;
            THIS->y--;
            if(THIS->y < 2u){
                SetSpriteAnim(THIS, a_owl_descend, 1u);
                owl_data->vx = 1;
                owl_data->vy = 2;
                THIS->mirror = V_MIRROR;
                owl_data->e_configured = 5;
            }
        }break;
        case 5:{
            owl_data->frmskip_wait++;
            if(owl_data->frmskip_wait < owl_data->frmskip){
                return;
            }
            owl_data->frmskip_wait = 0;
            UINT8 arrived = aeacusbody_move_to_point(THIS, 300u, 80u);
            if(arrived){
                SpriteManagerRemoveSprite(THIS);
            }
        }break;
        /*case 2:{
		    owl_data->frmskip_wait++;
            if(owl_data->frmskip_wait < 2){
                return;
            }
            owl_data->frmskip_wait = 0u;
            if(THIS->y > 78u){
                SpriteManagerRemoveSprite(THIS);
            }
            aeacusbody_move_to_point(THIS, 80u, 84u);
        }break;*/
    }
}

void owl_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED{
    switch(new_state){
        case IDLE_DOWN:
            SetSpriteAnim(s_enemy, a_owl_idle, 24u);
        break;
    }
}

void DESTROY() {
    idle_countdown = 800u;
    struct EnemyInfo* owl_data = (struct EnemyInfo*) THIS->custom_data;
    if((current_map == HADES_10 || current_map == HADES_22) && owl_data->e_configured > 3){
        orpheus_show_cartel();
    }
}