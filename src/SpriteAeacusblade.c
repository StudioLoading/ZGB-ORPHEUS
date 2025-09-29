#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"
#include "CircleMath.h"

#define SCIMITAR_H_POSX 17
#define SCIMITAR_H_POSY 6
#define SCIMITAR_V_POSX 3
#define SCIMITAR_V_POSY 14


const UINT8 a_aeacusblade_v[] = {1, 1};
const UINT8 a_aeacusblade_h[] = {1, 3};
const UINT8 a_aeacusblade_rotating[] = {8, 1,2,3,2,1,2,3,2};
const UINT8 a_aeacusblade_hidden[] = {1, 0};

extern INT8 boss_hp_current;
extern UINT8 flag_aeacus_scimitar;
extern Sprite* s_aeacus_wing_left;
extern Sprite* s_aeacus_wing_right;

UINT8 old_frame = 10u;
UINT8 dont_collide_counter = 0u;
UINT8 dont_collide_counter_max = 40u;

void aeacusblade_rotation(Sprite* arg_s_aeacusblade) BANKED;
void aeacusblade_change_state(Sprite* arg_s_aeacusblade, SPRITE_STATES arg_new_state) BANKED;
void aeacusblade_check_sprite_coll(Sprite* arg_s_aeacusblade) BANKED;

extern void orpheus_change_state(Sprite* arg_s_orpheus, SPRITE_STATES arg_new_state) BANKED;
extern UINT8 aeacusbody_move_to_point(Sprite* aea_s_aeacusbody, UINT16 arg_final_posx, UINT16 arg_final_posy) BANKED;

void START() {
    THIS->lim_x = THIS->x;
    THIS->lim_y = THIS->y;
    SetSpriteAnim(THIS, a_aeacusblade_hidden, 12u);
    struct EnemyInfo* blade_data = (struct EnemyInfo*) THIS->custom_data;
    blade_data->e_state = GENERIC_IDLE;
    blade_data->frmskip_wait = 0;
    blade_data->frmskip = boss_hp_current + 3;
    blade_data->wait = 80u;
    blade_data->vx = 0;
    blade_data->vy = 0;
    blade_data->e_configured = 0;//H;V;CLOCK;COUNTERCLOCK;
    flag_aeacus_scimitar = 1u;
    old_frame = 10u;
    dont_collide_counter = 0u;
    if(_cpu != CGB_TYPE){
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
    struct EnemyInfo* blade_data = (struct EnemyInfo*) THIS->custom_data;
    switch(blade_data->e_state){
        case GENERIC_IDLE:
            blade_data->wait--;
            if(blade_data->wait == 0){
                aeacusblade_change_state(THIS, GENERIC_WALK);
            }
        break;
        case GENERIC_WALK:
            switch(blade_data->e_configured){
                case 0: break;
                case 1:{//HORIZONTAL
                    if(dont_collide_counter < dont_collide_counter_max){
                        dont_collide_counter++;
                    }
                    if(dont_collide_counter < dont_collide_counter_max || blade_data->tile_collision == 0){
                        blade_data->tile_collision = aeacusbody_move_to_point(THIS, SCIMITAR_H_POSX << 3, SCIMITAR_H_POSY << 3);
                    }else{
                        aeacusblade_rotation(THIS);
                        SetSpriteAnim(THIS, a_aeacusblade_rotating, 32u);
                        UINT8 arrived = aeacusbody_move_to_point(THIS, THIS->lim_x, THIS->lim_y);
                        if(arrived){
                            SpriteManagerRemoveSprite(THIS);
                        }
                    }
                }break;
                case 2u:{//VERTICAL
                    if(blade_data->tile_collision == 0){
                        blade_data->tile_collision = aeacusbody_move_to_point(THIS, SCIMITAR_V_POSX << 3, SCIMITAR_V_POSY << 3);
                    }else{
                        SetSpriteAnim(THIS, a_aeacusblade_rotating, 32u);
                        aeacusblade_rotation(THIS);
                        UINT8 arrived = aeacusbody_move_to_point(THIS, THIS->lim_x, THIS->lim_y);
                        if(arrived){
                            SpriteManagerRemoveSprite(THIS);
                        }
                    }
                }break;
                case 3u://CLOCK
                case 4u://COUNTERCLOCK
                    aeacusblade_rotation(THIS);
                    if(dont_collide_counter < dont_collide_counter_max){
                        dont_collide_counter++;
                    }
                    blade_data->frmskip_wait++;
                    if(blade_data->frmskip_wait >= blade_data->frmskip){
                        blade_data->frmskip_wait = 0;
                        UINT8 cos_position = blade_data->wait + 64u;
                        UINT16 new_posx = 64u + ((sine_wave[cos_position]) / 3);
                        UINT16 new_posy = 72u + ((sine_wave[blade_data->wait]) / 3);
                        if(dont_collide_counter < dont_collide_counter_max || blade_data->vx < (boss_hp_current + 3)){
                            blade_data->vx++;
                            THIS->x = new_posx;
                            THIS->y = new_posy;
                        }else{
                            INT16 vx = (INT16)new_posx - (INT16)THIS->x;
                            INT16 vy = (INT16)new_posy - (INT16)THIS->y;
                            UINT8 aeacusblade_coll = TranslateSprite(THIS, vx << delta_time, vy << delta_time);
                        }
                        if(blade_data->e_configured == 3){//CLOCKWISE
                            blade_data->wait = blade_data->wait + 5 + ((3 - boss_hp_current) << 3);
                        }else if(blade_data->e_configured == 4){//COUNTERCLOCK
                            blade_data->wait = blade_data->wait - (5 + ((3 - boss_hp_current) << 3));
                        }
                    }
                break;
            }
        break;
    }
    if(dont_collide_counter >= dont_collide_counter_max){
        aeacusblade_check_sprite_coll(THIS);
    }
}

void aeacusblade_check_sprite_coll(Sprite* arg_s_aeacusblade) BANKED{
    //SPRITE COLLISION
        UINT8 scroll_abl_tile;
        Sprite* iablspr;
        SPRITEMANAGER_ITERATE(scroll_abl_tile, iablspr) {
            if(CheckCollision(arg_s_aeacusblade, iablspr)) {
                switch(iablspr->type){
                    case SpriteAeacuswing:
                        SpriteManagerRemoveSprite(THIS);
                        //aeacusblade_change_state(arg_s_aeacusblade, JUMP);
                    break;
                    case SpriteOrpheus:
                    case SpriteOrpheuslyre:
                        orpheus_change_state(iablspr, HIT);
                    break;
                }
            }
        } 
}

void aeacusblade_change_state(Sprite* arg_s_aeacusblade, SPRITE_STATES arg_new_state) BANKED{
    struct EnemyInfo* blade_data = (struct EnemyInfo*)arg_s_aeacusblade->custom_data;
    if(blade_data->e_state == arg_new_state){return;}
    switch(arg_new_state){
        case GENERIC_IDLE:
            arg_s_aeacusblade->mirror = NO_MIRROR;
            arg_s_aeacusblade->x = arg_s_aeacusblade->lim_x;
            arg_s_aeacusblade->y = arg_s_aeacusblade->lim_y;
            SetSpriteAnim(arg_s_aeacusblade, a_aeacusblade_hidden, 12u);
            blade_data->wait = 80u;
            blade_data->vx = 0;
        break;
        case GENERIC_WALK:
            arg_s_aeacusblade->mirror = NO_MIRROR;
            switch(blade_data->e_configured){
                case 1:
                    SetSpriteAnim(arg_s_aeacusblade, a_aeacusblade_h, 1u);
                break;
                case 2:
                    arg_s_aeacusblade->mirror = HV_MIRROR;
                    SetSpriteAnim(arg_s_aeacusblade, a_aeacusblade_v, 1u);
                break;
                case 3:
                    blade_data->wait = 200u;
                    SetSpriteAnim(arg_s_aeacusblade, a_aeacusblade_rotating, 32u);
                case 4:
                    blade_data->wait = 160u;
                    SetSpriteAnim(arg_s_aeacusblade, a_aeacusblade_rotating, 32u);
                break;
            }
            struct EnemyInfo* aeacuswing_right_data = (struct EnemyInfo*)s_aeacus_wing_right->custom_data;
            aeacuswing_right_data->wait = 0;
            struct EnemyInfo* aeacuswing_left_data = (struct EnemyInfo*)s_aeacus_wing_left->custom_data;
            aeacuswing_left_data->wait = 0;
        break;
        case JUMP:
            arg_s_aeacusblade->mirror = NO_MIRROR;
            arg_s_aeacusblade->x = arg_s_aeacusblade->lim_x;
            arg_s_aeacusblade->y = arg_s_aeacusblade->lim_y;
            SetSpriteAnim(arg_s_aeacusblade, a_aeacusblade_hidden, 1u);
        break;
        case WALK_UP:
        break;
        case ATTACK:
        break;
    }   
    blade_data->e_state = arg_new_state;
    //CHECK COLLISION
    
    //SPRITE COLLISION
        UINT8 scroll_abl_tile;
        Sprite* iablspr;
        SPRITEMANAGER_ITERATE(scroll_abl_tile, iablspr) {
            if(CheckCollision(THIS, iablspr)) {
                if(iablspr->type == SpriteOrpheus){
                    orpheus_change_state(iablspr, HIT);
                }
            }
        }
}

void aeacusblade_rotation(Sprite* arg_s_aeacusblade) BANKED{
    if(old_frame != arg_s_aeacusblade->anim_frame){
        old_frame = arg_s_aeacusblade->anim_frame;
        switch(arg_s_aeacusblade->anim_frame){
            case 0u:
            case 1u:
            case 2u:
                arg_s_aeacusblade->mirror = NO_MIRROR;
            break;
            case 3u:
                THIS->y += 12u;
            case 4u:
                arg_s_aeacusblade->mirror = H_MIRROR;
            break;
            case 5u:
                arg_s_aeacusblade->mirror = HV_MIRROR;
            break;
            case 6u:
                THIS->y -= 12u;
            case 7u:
                //THIS->y -= 16u;
                arg_s_aeacusblade->mirror = V_MIRROR;
            break;

        }
    }
}

void DESTROY() {
    flag_aeacus_scimitar = 0u;
}