#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "CircleMath.h"
#include "custom_datas.h"

#define CLAW_RAY 0 

const UINT8 a_hadesclaw[] = {1, 1};
const UINT8 a_hadesclaw_blink[] = {2, 0,1};

UINT16 final_left_posx = 0u;
UINT16 final_left_posy = 0u;
UINT16 final_right_posx = 0u;
UINT16 final_right_posy = 0u;
HADESCLAW_STATE claw_phase = HADESCLAW_IDLE;
extern HADES_STATE hades_state;

extern UINT8 boss_breath_flag;
extern INT8 boss_breath_verse;
extern INT8 boss_hp_current;
extern Sprite* s_orpheus;
extern UINT16 saved_orpheus_posx;
extern UINT16 saved_orpheus_posy;

extern void orpheus_change_state(Sprite* arg_s_orpheus, SPRITE_STATES arg_new_state) BANKED;

void hadesclaw_check_overlapping_and_spritecollision(Sprite* arg_s_claw) BANKED;
void hadesclaw_change_state(Sprite* arg_s_claw) BANKED;
void hadesclaw_rotate(Sprite* arg_s_claw) BANKED;
HADESCLAW_STATE hadesclaw_move_to_walk_left(Sprite* arg_s_claw) BANKED;
HADESCLAW_STATE hadesclaw_move_to_walk_right(Sprite* arg_s_claw) BANKED;
HADESCLAW_STATE hadesclaw_move_to_preattack(Sprite* arg_s_claw) BANKED;
HADESCLAW_STATE hadesclaw_move_to_deathlyhug(Sprite* arg_s_claw) BANKED;
HADESCLAW_STATE hadesclaw_move_to_clockwise(Sprite* arg_s_claw) BANKED;
HADESCLAW_STATE hadesclaw_move_to_counterclockwise(Sprite* arg_s_claw) BANKED;
HADESCLAW_STATE hadesclaw_move_to_idle(Sprite* arg_s_claw) BANKED;
HADESCLAW_STATE hadesclaw_move_to_wait(Sprite* arg_s_claw) BANKED;

void START() {
    THIS->lim_x = THIS->x;
    THIS->lim_y = THIS->y;
    SetSpriteAnim(THIS, a_hadesclaw, 1u);
    struct EnemyInfo* hadesclaw_data = (struct EnemyInfo*)THIS->custom_data; 
    hadesclaw_data->e_state = HADESCLAW_IDLE;
    hadesclaw_data->frmskip = 8;
    hadesclaw_data->frmskip_wait = 0;
    hadesclaw_data->vx = 0;
    hadesclaw_data->wait = 200;
    
}

void UPDATE() {
    struct EnemyInfo* hadesclaw_data = (struct EnemyInfo*)THIS->custom_data; 
    switch(hadesclaw_data->e_state){
        case HADESCLAW_WAIT:
        case HADESCLAW_IDLE:{
            hadesclaw_data->frmskip_wait++;
            if(hadesclaw_data->frmskip_wait == hadesclaw_data->frmskip){
                hadesclaw_data->frmskip_wait = 0;
                if(boss_breath_flag){
                    THIS->y += boss_breath_verse;
                }
            }
            if(hadesclaw_data->wait){
                hadesclaw_data->wait--;
            }
        }break;
        case HADESCLAW_WALK_LEFT:{
            hadesclaw_data->frmskip_wait++;
            if(hadesclaw_data->frmskip_wait == hadesclaw_data->frmskip){
                hadesclaw_data->frmskip_wait = 0;
                if(THIS->x > final_left_posx){
                    THIS->x--;
                }else{
                    hadesclaw_change_state(THIS);
                }
            }
        }break;
        case HADESCLAW_WALK_RIGHT:{
            hadesclaw_data->frmskip_wait++;
            if(hadesclaw_data->frmskip_wait == hadesclaw_data->frmskip){
                hadesclaw_data->frmskip_wait = 0;
                if(THIS->x < final_right_posx){
                    THIS->x++;
                }else{
                    hadesclaw_change_state(THIS);
                }
            }
        }break;
        case HADESCLAW_PREATTACK:{
            if(hadesclaw_data->wait){
                hadesclaw_data->wait--;
            }else{
                hadesclaw_change_state(THIS);
            }
        }break;
        case HADESCLAW_CLOCKWISE:{
            hadesclaw_data->frmskip_wait++;
            if(hadesclaw_data->frmskip_wait >= hadesclaw_data->frmskip){
                hadesclaw_data->frmskip_wait = 0;
                hadesclaw_rotate(THIS);
                hadesclaw_data->wait = hadesclaw_data->wait + (10 - boss_hp_current);
            }
        }break;
        case HADESCLAW_COUNTERCLOCKWISE:{
            hadesclaw_data->frmskip_wait++;
            if(hadesclaw_data->frmskip_wait >= hadesclaw_data->frmskip){
                hadesclaw_data->frmskip_wait = 0;
                hadesclaw_rotate(THIS);
                hadesclaw_data->wait = hadesclaw_data->wait - (10 - boss_hp_current);
            }
        }break;
    }
}

void hadesclaw_rotate(Sprite* arg_s_claw) BANKED{
    struct EnemyInfo* hadesclaw_data = (struct EnemyInfo*)arg_s_claw->custom_data; 
    UINT8 cos_position = hadesclaw_data->wait + 64u;
    INT8 delta_x = sine_wave[cos_position] / 3;
    INT8 delta_y = sine_wave[hadesclaw_data->wait] / 3;
    UINT16 new_posx = 72u + delta_x;
    UINT16 new_posy = 68u + delta_y;
    if(hadesclaw_data->vx < 10){
        hadesclaw_data->vx++;
        arg_s_claw->x = new_posx;
        arg_s_claw->y = new_posy;
    }else{
        INT16 vx = (INT16)new_posx - (INT16)arg_s_claw->x;
        INT16 vy = (INT16)new_posy - (INT16)arg_s_claw->y;
        TranslateSprite(arg_s_claw, vx << delta_time, vy << delta_time);
        if(vx || vy){
            hadesclaw_check_overlapping_and_spritecollision(arg_s_claw);
        }
    }
}

void hadesclaw_check_overlapping_and_spritecollision(Sprite* arg_s_claw) BANKED{
    //TODO check se è attaccato da canzone SLEEP e sta sopra le fiamme
    //se sono sotto una certa y, torna in idle
        if(arg_s_claw->y < 40u){
            hadesclaw_change_state(arg_s_claw);
            return;
        }
    //TODO se collide con HADESSKULL torna a lim_x;lim_y
    //SPRITE COLLISION
        UINT8 scroll_clbl_tile;
        Sprite* iclblspr;
        SPRITEMANAGER_ITERATE(scroll_clbl_tile, iclblspr) {
            if(CheckCollision(arg_s_claw, iclblspr)) {
                switch(iclblspr->type){
                    case SpriteOrpheus:
                    case SpriteOrpheuslyre:
                        orpheus_change_state(iclblspr, HIT);
                    break;
                    case SpriteHadesskull:
                        hadesclaw_change_state(arg_s_claw);
                    break;
                }
            }
        }
}

void hadesclaw_change_state(Sprite* arg_s_claw) BANKED{
    HADESCLAW_STATE claw_new_state = HADESCLAW_IDLE;
    struct EnemyInfo* claw_data = (struct EnemyInfo*)arg_s_claw->custom_data;
    switch(boss_hp_current){
        case 8:
            switch(hades_state){
                case HADES_CLAW_DEATHLY_HUG:
                    switch(claw_data->e_state){
                        case HADESCLAW_IDLE:
                            if(arg_s_claw->mirror == NO_MIRROR){
                                claw_new_state = hadesclaw_move_to_walk_left(arg_s_claw);
                            }else if(arg_s_claw->mirror == V_MIRROR){
                                claw_new_state = hadesclaw_move_to_walk_right(arg_s_claw);
                            }
                        break;
                        case HADESCLAW_WALK_LEFT:
                        case HADESCLAW_WALK_RIGHT:
                            claw_new_state = hadesclaw_move_to_preattack(arg_s_claw);
                        break;
                        case HADESCLAW_PREATTACK:
                            if(arg_s_claw->mirror == NO_MIRROR){
                                claw_new_state = hadesclaw_move_to_counterclockwise(arg_s_claw);
                            }else if(arg_s_claw->mirror == V_MIRROR){
                                claw_new_state = hadesclaw_move_to_clockwise(arg_s_claw);
                            }
                        break;
                        case HADESCLAW_CLOCKWISE:
                        case HADESCLAW_COUNTERCLOCKWISE:
                            claw_new_state = hadesclaw_move_to_wait(arg_s_claw);
                        break;
                        case HADESCLAW_WAIT:
                            claw_new_state = hadesclaw_move_to_idle(arg_s_claw);
                        break;
                    }
                break;
            }
        break;
    }
    claw_data->e_state = claw_new_state;
}

HADESCLAW_STATE hadesclaw_move_to_wait(Sprite* arg_s_claw) BANKED{
    SetSpriteAnim(arg_s_claw, a_hadesclaw, 1u);
    arg_s_claw->x = arg_s_claw->lim_x;
    arg_s_claw->y = arg_s_claw->lim_y;
    struct EnemyInfo* claw_data = (struct EnemyInfo*)arg_s_claw->custom_data; 
    claw_data->frmskip = boss_hp_current;
    return HADESCLAW_WAIT;
}
HADESCLAW_STATE hadesclaw_move_to_idle(Sprite* arg_s_claw) BANKED{
    SetSpriteAnim(arg_s_claw, a_hadesclaw, 1u);
    arg_s_claw->x = arg_s_claw->lim_x;
    arg_s_claw->y = arg_s_claw->lim_y;
    struct EnemyInfo* claw_data = (struct EnemyInfo*)arg_s_claw->custom_data; 
    claw_data->frmskip = boss_hp_current;
    return HADESCLAW_IDLE;
}
HADESCLAW_STATE hadesclaw_move_to_counterclockwise(Sprite* arg_s_claw) BANKED{
    SetSpriteAnim(arg_s_claw, a_hadesclaw, 1u);
    struct EnemyInfo* claw_data = (struct EnemyInfo*)arg_s_claw->custom_data;
    claw_data->wait = 120u;
    claw_data->frmskip = 2;
    claw_data->vx = 0;
    return HADESCLAW_COUNTERCLOCKWISE;
}

HADESCLAW_STATE hadesclaw_move_to_clockwise(Sprite* arg_s_claw) BANKED{
    SetSpriteAnim(arg_s_claw, a_hadesclaw, 1u);
    struct EnemyInfo* claw_data = (struct EnemyInfo*)arg_s_claw->custom_data;
    claw_data->wait = 20u;
    claw_data->frmskip = 2;
    claw_data->vx = 0;
    return HADESCLAW_CLOCKWISE;
}

HADESCLAW_STATE hadesclaw_move_to_walk_left(Sprite* arg_s_claw) BANKED{
    struct EnemyInfo* claw_data = (struct EnemyInfo*)arg_s_claw->custom_data; 
    SetSpriteAnim(arg_s_claw, a_hadesclaw, 1u);
    return HADESCLAW_WALK_LEFT;
}
HADESCLAW_STATE hadesclaw_move_to_walk_right(Sprite* arg_s_claw) BANKED{
    struct EnemyInfo* claw_data = (struct EnemyInfo*)arg_s_claw->custom_data; 
    SetSpriteAnim(arg_s_claw, a_hadesclaw, 1u);
    return HADESCLAW_WALK_RIGHT;
}

HADESCLAW_STATE hadesclaw_move_to_preattack(Sprite* arg_s_claw) BANKED{
    struct EnemyInfo* claw_data = (struct EnemyInfo*)arg_s_claw->custom_data; 
    SetSpriteAnim(arg_s_claw, a_hadesclaw_blink, 64u);
    claw_data->wait = 40 * boss_hp_current;
    saved_orpheus_posx = s_orpheus->x;
    saved_orpheus_posy = s_orpheus->y;
    return HADESCLAW_PREATTACK;
}

void DESTROY() {
}