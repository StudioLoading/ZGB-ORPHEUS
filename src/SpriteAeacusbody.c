#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

#define AEACUSBODY_WAIT_MAX 200
#define AEACUSBODY_WAIT_MID 100
#define AEACUSBODY_WAIT_MIN 40

#define AEACUSBODY_WATCH_MAX 100
#define AEACUSBODY_WATCH_MID 80
#define AEACUSBODY_WATCH_MIN 60

const UINT8 a_aeacusbody_hidden[] = {1, 0};
const UINT8 a_aeacusbody_down[] = {1, 1};
const UINT8 a_aeacusbody_look[] = {14, 5,4,5,4,3,3,2,2,4,4,3,3,2,2};
const UINT8 a_aeacusbody_hit[] = {2, 0,1};
const UINT8 a_aeacusbody_attack[] = {2, 5,1};

UINT8 aeabody_idle_wait = 0u;
UINT8 aeabody_idle_wait_max = AEACUSBODY_WAIT_MAX;

AEACUS_PHASE aeacus_phase = AEA_IDLE;
UINT8 flag_aeacus_scimitar = 0u;
UINT16 saved_orpheus_posx = 0u;
UINT16 saved_orpheus_posy = 0u;
UINT8 aeacusbody_walking_frmskip_x_current = 0u;
UINT8 aeacusbody_walking_frmskip_y_current = 0u;
INT16 aeacusbody_delta_walking_delta_x = 0;
INT16 aeacusbody_delta_walking_delta_y = 0;
UINT8 aeacusbody_arrived = 0u;
UINT8 aeacusbody_arrived_back = 0u;

extern INT8 boss_hp_current;
extern Sprite* s_orpheus;
extern Sprite* s_aeacus_wing_left;
extern Sprite* s_aeacus_wing_right;

void aeacusbody_change_state(Sprite* arg_s_aeacusbody, SPRITE_STATES arg_new_state) BANKED;
UINT8 aeacusbody_move_to_point(Sprite* aea_s_aeacusbody, UINT16 arg_final_posx, UINT16 arg_final_posy) BANKED;

void aea_change_state(Sprite* arg_s_aeacusbody) BANKED;
AEACUS_PHASE aea_move_to_watch(Sprite* arg_s_aeacusbody) BANKED;
AEACUS_PHASE aea_move_to_scimitar_h(Sprite* arg_s_aeacusbody) BANKED;
AEACUS_PHASE aea_move_to_scimitar_v(Sprite* arg_s_aeacusbody) BANKED;
AEACUS_PHASE aea_move_to_scimitar_clock( Sprite* arg_s_aeacusbody) BANKED;
AEACUS_PHASE aea_move_to_scimitar_counterclock( Sprite* arg_s_aeacusbody) BANKED;
AEACUS_PHASE aea_move_to_fly(Sprite* arg_s_aeacusbody) BANKED;
AEACUS_PHASE aea_move_to_idle(Sprite* arg_s_aeacusbody) BANKED;
AEACUS_PHASE aea_move_to_hit(Sprite* arg_s_aeacusbody) BANKED;

extern void boss_hit() BANKED;
extern void orpheus_change_state(Sprite* arg_s_orpheus, SPRITE_STATES arg_new_state) BANKED;

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
void START() {
    THIS->lim_x = THIS->x;
    THIS->lim_y = THIS->y;
    struct EnemyInfo* aeacusbody_data = (struct EnemyInfo*)THIS->custom_data;
    aeacusbody_data->e_configured = 1;
    aeacusbody_data->e_state = GENERIC_IDLE;
    aeacusbody_data->frmskip_wait = 0;
    aeacusbody_data->frmskip = 0u;
    aeacusbody_data->vx = 0;
    aeacusbody_data->vy = 0;
    aeacusbody_arrived = 0u;
    aeacusbody_arrived_back = 0u;
    aeacusbody_change_state(THIS, JUMP);
}

void UPDATE() {
    struct EnemyInfo* aeacusbody_data = (struct EnemyInfo*)THIS->custom_data;
    if(aeacusbody_data->e_configured == 0){
        return;
    }
    switch(aeacus_phase){
        case AEA_IDLE:
            aeabody_idle_wait++;
            if(aeabody_idle_wait >= aeabody_idle_wait_max){
                aea_change_state(THIS);
            }
        break;
        case AEA_BODY_WATCH:
            aeabody_idle_wait++;
            if(aeabody_idle_wait >= aeabody_idle_wait_max){
                aea_change_state(THIS);
            }
        break;
        case AEA_BODY_FLY:{
            aeacusbody_data->frmskip_wait++;
            if(aeacusbody_data->frmskip_wait >= aeacusbody_data->frmskip){
                aeacusbody_data->frmskip_wait = 0;
                if(aeacusbody_arrived == 0){
                    aeacusbody_arrived = aeacusbody_move_to_point(THIS, saved_orpheus_posx, saved_orpheus_posy);
                    if(aeacusbody_arrived){
                        aeacusbody_data->frmskip = 0;
                    }
                }else{
                    aeacusbody_arrived_back = aeacusbody_move_to_point(THIS, THIS->lim_x, THIS->lim_y);
                }
            }
            if(aeacusbody_arrived && aeacusbody_arrived_back){
                aea_change_state(THIS);
            }
            //SPRITE COLLISION
                UINT8 scroll_aeabl_tile;
                Sprite* iaeablspr;
                SPRITEMANAGER_ITERATE(scroll_aeabl_tile, iaeablspr) {
                    if(CheckCollision(THIS, iaeablspr)) {
                        if(iaeablspr->type == SpriteOrpheus || iaeablspr->type == SpriteOrpheuslyre){
                            orpheus_change_state(iaeablspr, HIT);
                        }
                    }
                }
        }break;
        case AEA_SCIMITAR_HORIZONTAL:
        case AEA_SCIMITAR_COUNTERCLOCK:
        case AEA_SCIMITAR_VERTICAL:
        case AEA_SCIMITAR_CLOCK:
            if(flag_aeacus_scimitar == 0){
                aea_change_state(THIS);
            }
        break;
        case AEA_HIT:
            aeabody_idle_wait++;
            if(aeabody_idle_wait > aeabody_idle_wait_max){
                //force going back
                aeacusbody_arrived = 1;
                aeacusbody_arrived_back = 0;
                aeacusbody_data->e_configured = 1;
                aeacus_phase = aea_move_to_fly(THIS);
            }
        break;
    }
}

UINT8 aeacusbody_move_to_point(Sprite* aea_s_aeacusbody, UINT16 arg_final_posx, UINT16 arg_final_posy) BANKED{
    //arrived??
    aeacusbody_delta_walking_delta_x = (INT16)arg_final_posx - (INT16)aea_s_aeacusbody->x;
    if(aeacusbody_delta_walking_delta_x < 0){
        aeacusbody_delta_walking_delta_x = -aeacusbody_delta_walking_delta_x;
    }
    aeacusbody_delta_walking_delta_y = (INT16)arg_final_posy - (INT16)aea_s_aeacusbody->y;
    if(aeacusbody_delta_walking_delta_y < 0){
        aeacusbody_delta_walking_delta_y = -aeacusbody_delta_walking_delta_y;
    }
    if(aeacusbody_delta_walking_delta_x < 3 && aeacusbody_delta_walking_delta_y < 3){
        return 1u;
    }
    INT8 delta_walking_delta_x_verse = 1;
    if(aea_s_aeacusbody->x > arg_final_posx){
        delta_walking_delta_x_verse = -1;
    }
    INT8 delta_walking_delta_y_verse = 1;
    if(aea_s_aeacusbody->y > arg_final_posy){
        delta_walking_delta_y_verse = -1;
    }
    struct EnemyInfo* aeacusbody_data = (struct EnemyInfo*)aea_s_aeacusbody->custom_data;
    aeacusbody_data->vx = 1 * delta_walking_delta_x_verse;
    aeacusbody_data->vy = 1 * delta_walking_delta_y_verse;
    INT8 actual_aeabody_vx = aeacusbody_data->vx;
    INT8 actual_aeabody_vy = aeacusbody_data->vy;
    INT8 delta_factor_y = 0;
    INT8 delta_factor_x = 0;
    if(aeacusbody_delta_walking_delta_x > aeacusbody_delta_walking_delta_y){
        delta_factor_y = aeacusbody_delta_walking_delta_x / aeacusbody_delta_walking_delta_y;
        INT16 r_y = aeacusbody_delta_walking_delta_x % aeacusbody_delta_walking_delta_y;
        if(r_y > (aeacusbody_delta_walking_delta_y >> 1)){
            delta_factor_y += (delta_factor_y + (delta_factor_y >> 2));
        }
    }else{
        delta_factor_x = aeacusbody_delta_walking_delta_y / aeacusbody_delta_walking_delta_x;
        INT16 r_x = aeacusbody_delta_walking_delta_y % aeacusbody_delta_walking_delta_x;
        if(r_x > (aeacusbody_delta_walking_delta_x >> 1)){
            delta_factor_x += (delta_factor_x + (delta_factor_x >> 2));
        }
    }
    //e scopro ogni quanti x deve fare una y
    if(delta_factor_x > 0 && (INT8)aeacusbody_walking_frmskip_x_current < delta_factor_x){//ecco che devo fare una y
        actual_aeabody_vx = 0;
    }
    if(delta_factor_y > 0 && (INT8)aeacusbody_walking_frmskip_y_current < delta_factor_y){
        actual_aeabody_vy = 0;
    }
    if((INT8)aeacusbody_walking_frmskip_x_current == delta_factor_x){
        aeacusbody_walking_frmskip_x_current = 0;
    }
    if((INT8)aeacusbody_walking_frmskip_y_current == delta_factor_y){
        aeacusbody_walking_frmskip_y_current = 0;
    }
    aeacusbody_walking_frmskip_x_current++;
    aeacusbody_walking_frmskip_y_current++;
    if(actual_aeabody_vx || actual_aeabody_vy){
        UINT8 aeacusbody_coll_tile = TranslateSprite(aea_s_aeacusbody, actual_aeabody_vx << delta_time, actual_aeabody_vy << delta_time);
        if(aeacusbody_coll_tile){
            aea_s_aeacusbody->x += actual_aeabody_vx;
            aea_s_aeacusbody->y += actual_aeabody_vy;
        }
        aeacusbody_data->vx = actual_aeabody_vx;
        aeacusbody_data->vy = actual_aeabody_vy;
    }
    return 0;
}

void aea_change_state(Sprite* arg_s_aeacusbody) BANKED{
    AEACUS_PHASE aea_new_phase = AEA_IDLE;
    struct EnemyInfo* aeacusbody_data = (struct EnemyInfo*)arg_s_aeacusbody->custom_data;
    switch(boss_hp_current){
        case 5:
            switch(aeacus_phase){
                case AEA_IDLE:{
                    aea_new_phase = aea_move_to_scimitar_clock(arg_s_aeacusbody);
                }break;
                case AEA_SCIMITAR_CLOCK:{
                    aea_new_phase = aea_move_to_scimitar_counterclock(arg_s_aeacusbody);
                }break;
                case AEA_SCIMITAR_COUNTERCLOCK:{
                    aea_new_phase = aea_move_to_watch(arg_s_aeacusbody);
                }break;
                case AEA_BODY_WATCH:{
                    aea_new_phase = aea_move_to_fly(arg_s_aeacusbody);
                }break;
                case AEA_BODY_FLY:{
                    aea_new_phase = aea_move_to_idle(arg_s_aeacusbody);
                }break;
            }
        break;
        case 4:
            switch(aeacus_phase){
                case AEA_IDLE:{
                    aea_new_phase = aea_move_to_scimitar_v(arg_s_aeacusbody);
                }break;
                case AEA_SCIMITAR_VERTICAL:{
                    aea_new_phase = aea_move_to_scimitar_h(arg_s_aeacusbody);
                }break;
                case AEA_SCIMITAR_HORIZONTAL:{
                    aea_new_phase = aea_move_to_watch(arg_s_aeacusbody);
                }break;
                case AEA_BODY_WATCH:{
                    aea_new_phase = aea_move_to_fly(arg_s_aeacusbody);
                }break;
                case AEA_BODY_FLY:{
                    aea_new_phase = aea_move_to_idle(arg_s_aeacusbody);
                }break;
            }
        break;
        case 3:{
            switch(aeacus_phase){
                case AEA_IDLE:{
                    aea_new_phase = aea_move_to_watch(arg_s_aeacusbody);
                }break;
                case AEA_BODY_WATCH:{
                    aea_new_phase = aea_move_to_fly(arg_s_aeacusbody);
                }break;
                case AEA_BODY_FLY:{
                    aeacusbody_data->e_configured++;
                    switch(aeacusbody_data->e_configured){
                        case 2:
                            aea_new_phase = aea_move_to_scimitar_clock(arg_s_aeacusbody);
                        break;
                        case 3:
                            aea_new_phase = aea_move_to_watch(arg_s_aeacusbody);
                        break;
                        default:
                            aeacusbody_data->e_configured = 1;
                            aea_new_phase = aea_move_to_idle(arg_s_aeacusbody);
                        break;
                    }
                }break;
                case AEA_SCIMITAR_CLOCK:{
                    aea_new_phase = aea_move_to_scimitar_h(arg_s_aeacusbody);
                }break;
                case AEA_SCIMITAR_HORIZONTAL:{
                    aea_new_phase = aea_move_to_watch(arg_s_aeacusbody);
                }break;
            }
        }break;
        case 2:{
            switch(aeacus_phase){
                case AEA_IDLE:{
                    aea_new_phase = aea_move_to_watch(arg_s_aeacusbody);
                }break;
                case AEA_BODY_WATCH:{
                    aea_new_phase = aea_move_to_fly(arg_s_aeacusbody);
                }break;                
                case AEA_BODY_FLY:{
                    aeacusbody_data->e_configured++;
                    switch(aeacusbody_data->e_configured){
                        case 2:
                            aea_new_phase = aea_move_to_scimitar_clock(arg_s_aeacusbody);
                        break;
                        case 3:
                            aea_new_phase = aea_move_to_scimitar_counterclock(arg_s_aeacusbody);
                        break;
                        case 4:
                            aea_new_phase = aea_move_to_scimitar_h(arg_s_aeacusbody);
                        break;
                        case 5:
                            aea_new_phase = aea_move_to_scimitar_v(arg_s_aeacusbody);
                        break;
                        default:
                            aeacusbody_data->e_configured = 1;
                            aea_new_phase = aea_move_to_idle(arg_s_aeacusbody);
                        break;
                    }
                }break;
                case AEA_SCIMITAR_HORIZONTAL:
                case AEA_SCIMITAR_VERTICAL:
                case AEA_SCIMITAR_CLOCK:
                case AEA_SCIMITAR_COUNTERCLOCK:{
                    aea_new_phase = aea_move_to_watch(arg_s_aeacusbody);
                }break;
            }
        }break;
        case 1:{
            switch(aeacus_phase){
                case AEA_IDLE:{
                    aea_new_phase = aea_move_to_watch(arg_s_aeacusbody);
                }break;
                case AEA_BODY_WATCH:{
                    aea_new_phase = aea_move_to_fly(arg_s_aeacusbody);
                }break;                
                case AEA_BODY_FLY:{
                    aea_new_phase = aea_move_to_idle(arg_s_aeacusbody);
                }break;
            }
        }break;
    }
    aeacus_phase = aea_new_phase;
}

AEACUS_PHASE aea_move_to_hit(Sprite* arg_s_aeacusbody) BANKED{
    if(aeacus_phase == AEA_HIT){ return AEA_HIT; }
    boss_hit();
    aeabody_idle_wait = 0u;
    aeabody_idle_wait_max = 40;
    aeacusbody_change_state(arg_s_aeacusbody, HIT);
    return AEA_HIT;
}

AEACUS_PHASE aea_move_to_idle(Sprite* arg_s_aeacusbody) BANKED{
    aeacusbody_arrived = 0u;
    aeacusbody_arrived_back = 0u;
    struct EnemyInfo* aeacusbody_data = (struct EnemyInfo*)arg_s_aeacusbody->custom_data;
    aeacusbody_change_state(arg_s_aeacusbody, JUMP);
    return AEA_IDLE;
}

AEACUS_PHASE aea_move_to_fly(Sprite* arg_s_aeacusbody) BANKED{
    aeacusbody_change_state(arg_s_aeacusbody, ATTACK);
    aeabody_idle_wait = 0;
    aeabody_idle_wait_max = AEACUSBODY_WATCH_MAX;
    return AEA_BODY_FLY;
}

AEACUS_PHASE aea_move_to_watch(Sprite* arg_s_aeacusbody) BANKED{
    aeacusbody_change_state(arg_s_aeacusbody, PREATTACK_DOWN);
    aeacusbody_arrived = 0u;
    aeacusbody_arrived_back = 0u;
    aeabody_idle_wait = 0;
    aeabody_idle_wait_max = AEACUSBODY_WATCH_MAX;
    saved_orpheus_posx = s_orpheus->x + 4u;
    saved_orpheus_posy = s_orpheus->y - 8u;
    if(s_orpheus->y < 10u){
        saved_orpheus_posy = 1u;
    }
    aeacusbody_walking_frmskip_x_current = 0;
    aeacusbody_walking_frmskip_y_current = 0;
    return AEA_BODY_WATCH;
}

AEACUS_PHASE aea_move_to_scimitar_clock(Sprite* arg_s_aeacusbody) BANKED{
    struct EnemyInfo* aeacuswing_right_data = (struct EnemyInfo*)s_aeacus_wing_right->custom_data;
    aeacuswing_right_data->wait = 1;
    aeacuswing_right_data->e_configured = 4u;
    Sprite* s_aeacus_blade = SpriteManagerAdd(SpriteAeacusblade, 35u, 24u);
    s_aeacus_blade->mirror = H_MIRROR;
    struct EnemyInfo* blade_data = (struct EnemyInfo*) s_aeacus_blade->custom_data;
    blade_data->e_configured = 3;
    return AEA_SCIMITAR_CLOCK;
}

AEACUS_PHASE aea_move_to_scimitar_h(Sprite* arg_s_aeacusbody) BANKED{
    struct EnemyInfo* aeacuswing_right_data = (struct EnemyInfo*)s_aeacus_wing_right->custom_data;
    aeacuswing_right_data->wait = 1;
    aeacuswing_right_data->e_configured = 4u;
    Sprite* s_aeacus_blade = SpriteManagerAdd(SpriteAeacusblade, 35u, 40u);
    struct EnemyInfo* blade_data = (struct EnemyInfo*) s_aeacus_blade->custom_data;
    blade_data->e_configured = 1;
    return AEA_SCIMITAR_HORIZONTAL;
}

AEACUS_PHASE aea_move_to_scimitar_v(Sprite* arg_s_aeacusbody) BANKED{
    struct EnemyInfo* aeacuswing_left_data = (struct EnemyInfo*)s_aeacus_wing_left->custom_data;
    aeacuswing_left_data->wait = 1;
    aeacuswing_left_data->e_configured = 3u;
    Sprite* s_aeacus_blade = SpriteManagerAdd(SpriteAeacusblade, 34, 29u);
    s_aeacus_blade->mirror = H_MIRROR;
    struct EnemyInfo* blade_data = (struct EnemyInfo*) s_aeacus_blade->custom_data;
    blade_data->e_configured = 2;
    return AEA_SCIMITAR_VERTICAL;
}

AEACUS_PHASE aea_move_to_scimitar_counterclock( Sprite* arg_s_aeacusbody) BANKED{
    struct EnemyInfo* aeacuswing_left_data = (struct EnemyInfo*)s_aeacus_wing_left->custom_data;
    aeacuswing_left_data->wait = 1;
    aeacuswing_left_data->e_configured = 3u;
    Sprite* s_aeacus_blade = SpriteManagerAdd(SpriteAeacusblade, 31u, 29u);
    s_aeacus_blade->mirror = H_MIRROR;
    struct EnemyInfo* blade_data = (struct EnemyInfo*) s_aeacus_blade->custom_data;
    blade_data->e_configured = 4;
    return AEA_SCIMITAR_COUNTERCLOCK;
}

void aeacusbody_change_state(Sprite* arg_s_aeacusbody, SPRITE_STATES arg_new_state) BANKED{
    struct EnemyInfo* aeacusbody_data = (struct EnemyInfo*)arg_s_aeacusbody->custom_data;
    if(aeacusbody_data->e_state == arg_new_state){
        return;
    }
    switch(arg_new_state){
        case JUMP:
            arg_s_aeacusbody->x = arg_s_aeacusbody->lim_x;
            arg_s_aeacusbody->y = arg_s_aeacusbody->lim_y;
            SetSpriteAnim(arg_s_aeacusbody, a_aeacusbody_down, 1);
        break;
        case PREATTACK_DOWN:
            SetSpriteAnim(arg_s_aeacusbody, a_aeacusbody_look, 8u);
        break;
        case ATTACK:
            SetSpriteAnim(arg_s_aeacusbody, a_aeacusbody_attack, 64u);
        break;
        case HIT:
            SetSpriteAnim(arg_s_aeacusbody, a_aeacusbody_hit, 40u);
        break;
    }
    aeacusbody_data->e_state = arg_new_state;
}

void DESTROY() {
}