#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"
#include "CircleMath.h"


const UINT8 a_aeacusblade_v_blink[] = {4, 1,1,1,0};
const UINT8 a_aeacusblade_rotating[] = {8, 1,2,3,2,1,2,3,2};
const UINT8 a_aeacusblade_hidden[] = {1, 0};

extern INT8 boss_hp_current;
extern UINT8 flag_aeacus_scimitar;
extern Sprite* s_aeacus_wing_left;
extern Sprite* s_aeacus_wing_right;

UINT8 old_frame = 10u;

void aeacusblade_rotation(Sprite* arg_s_aeacusblade) BANKED;
void aeacusblade_change_state(Sprite* arg_s_aeacusblade, SPRITE_STATES arg_new_state) BANKED;
void aeacusblade_check_sprite_coll(Sprite* arg_s_aeacusblade) BANKED;

extern void boss_hit() BANKED;
extern void orpheus_change_state(Sprite* arg_s_orpheus, SPRITE_STATES arg_new_state) BANKED;

void START() {
    THIS->lim_x = THIS->x;
    THIS->lim_y = THIS->y;
    SetSpriteAnim(THIS, a_aeacusblade_hidden, 12u);
    struct EnemyInfo* blade_data = (struct EnemyInfo*) THIS->custom_data;
    blade_data->e_state = GENERIC_IDLE;
    blade_data->frmskip_wait = 0;
    blade_data->frmskip = 8;
    blade_data->wait = 80u;
    blade_data->vx = 0;
    blade_data->e_configured = 0;//H;V;CLOCK;COUNTERCLOCK;
    flag_aeacus_scimitar = 1u;
    old_frame = 10u;
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
                case 1://HORIZONTAL
                break;
                case 2u://VERTICAL
                break;
                case 3u://CLOCK
                case 4u://COUNTERCLOCK
                    aeacusblade_rotation(THIS);
                    blade_data->frmskip_wait++;
                    if(blade_data->frmskip_wait >= blade_data->frmskip){
                        blade_data->frmskip_wait = 0;
                        UINT8 cos_position = blade_data->wait + 64u;
                        UINT16 new_posx = 64u + ((sine_wave[cos_position]) / 3);
                        UINT16 new_posy = 72u + ((sine_wave[blade_data->wait]) / 3);
                        if(blade_data->vx < 8){
                            blade_data->vx++;
                            THIS->x = new_posx;
                            THIS->y = new_posy;
                        }else{
                            INT16 vx = (INT16)new_posx - (INT16)THIS->x;
                            INT16 vy = (INT16)new_posy - (INT16)THIS->y;
                            UINT8 aeacusblade_coll = TranslateSprite(THIS, vx << delta_time, vy << delta_time);
                            if(vx || vy){
                                aeacusblade_check_sprite_coll(THIS);
                            }
                        }
                        if(blade_data->e_configured == 3){//CLOCKWISE
                            blade_data->wait = blade_data->wait + 5 + ((5 - boss_hp_current) << 3);
                        }else if(blade_data->e_configured == 4){//COUNTERCLOCK
                            blade_data->wait = blade_data->wait - (5 + ((5 - boss_hp_current) << 3));
                        }
                    }
                break;
            }
        break;
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
            boss_hit();
        break;
        case GENERIC_WALK:
            arg_s_aeacusblade->mirror = NO_MIRROR;
            if(blade_data->e_configured == 3){
                blade_data->wait = 200u;
            }else if(blade_data->e_configured == 4){
                blade_data->wait = 160u;
            }
            SetSpriteAnim(arg_s_aeacusblade, a_aeacusblade_rotating, 32u);
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