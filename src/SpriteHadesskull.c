#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"


const UINT8 a_hadesskull[] = {2, 1,2};
const UINT8 a_hadesskull_blink[] = {2, 0,1};

extern UINT8 boss_breath_flag;
extern INT8 boss_breath_verse;
extern Sprite* s_hades_claw_left;
extern Sprite* s_hades_claw_right;
extern INT8 boss_hp_current;
extern UINT8 flag_hades_summon;
extern UINT16 final_left_posx;
extern UINT16 final_left_posy;
extern UINT16 final_right_posx;
extern UINT16 final_right_posy;
extern UINT8 flag_camera_shake_h;

HADES_STATE hades_state = HADES_IDLE;

void hades_change_state(Sprite* arg_s_hadesskull, SPRITE_STATES arg_new_state) BANKED;
void hades_regerate_claws() BANKED;
void hades_skull_reset_data(Sprite* arg_s_hadesskull) BANKED;

extern void hadesclaw_change_state(Sprite* arg_s_claw) BANKED;
extern void hadesclaw_set_finalposs(UINT16 arg_leftposx, UINT16 arg_leftposy, UINT16 arg_rightposx, UINT16 arg_rightposy) BANKED;

void START() {
    THIS->lim_x = THIS->x;
    THIS->lim_y = THIS->y;
    SetSpriteAnim(THIS, a_hadesskull, 200u);
    hades_skull_reset_data(THIS);
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
    struct EnemyInfo* hadesskull_data = (struct EnemyInfo*)THIS->custom_data;
    struct EnemyInfo* claw_left_data = (struct EnemyInfo*)s_hades_claw_left->custom_data;
    struct EnemyInfo* claw_right_data = (struct EnemyInfo*)s_hades_claw_right->custom_data;
    switch(boss_hp_current){
        case 8:
        case 7:{
            switch(hades_state){
                case HADES_IDLE:{
                    switch(hadesskull_data->e_state){
                        case GENERIC_IDLE:
                            hadesskull_data->frmskip_wait++;
                            if(hadesskull_data->frmskip_wait == hadesskull_data->frmskip){
                                hadesskull_data->frmskip_wait = 0;
                                if(boss_breath_flag){
                                    THIS->y += boss_breath_verse;
                                    //boss_breath_flag = 0;
                                }
                            }
                            hadesskull_data->wait--;
                            if(hadesskull_data->wait == 0){
                                hades_change_state(THIS, HADES_CLAW_LEFT_CIRCLE);
                            }
                        break;
                    }
                }break;
                case HADES_CLAW_LEFT_CIRCLE:
                    if((claw_left_data->e_state == HADESCLAW_WAIT || claw_left_data->e_state == HADESCLAW_HIDDEN) && claw_left_data->wait == 0){
                        hades_change_state(THIS, HADES_CLAW_RIGHT_CIRCLE);
                    }
                break;
                case HADES_CLAW_RIGHT_CIRCLE:
                    if((claw_right_data->e_state == HADESCLAW_WAIT || claw_right_data->e_state == HADESCLAW_HIDDEN) && claw_right_data->wait == 0){
                        hades_change_state(THIS, HADES_IDLE);
                    }
                break;
            }
        }break;
        case 6:
        case 5:{
            switch(hades_state){
                case HADES_IDLE:{
                    switch(hadesskull_data->e_state){
                        case GENERIC_IDLE:
                            hadesskull_data->frmskip_wait++;
                            if(hadesskull_data->frmskip_wait == hadesskull_data->frmskip){
                                hadesskull_data->frmskip_wait = 0;
                                if(boss_breath_flag){
                                    THIS->y += boss_breath_verse;
                                    //boss_breath_flag = 0;
                                }
                            }
                            hadesskull_data->wait--;
                            if(hadesskull_data->wait == 0){
                                hades_change_state(THIS, HADES_CLAW_DEATHLY_HUG);
                            }
                        break;
                    }
                }break;
                case HADES_CLAW_DEATHLY_HUG:{
                    if((claw_left_data->e_state == HADESCLAW_WAIT || claw_left_data->e_state == HADESCLAW_HIDDEN) && (claw_right_data->e_state == HADESCLAW_WAIT || claw_right_data->e_state == HADESCLAW_HIDDEN) && claw_left_data->wait == 0 && claw_right_data->wait == 0){
                        hades_change_state(THIS, HADES_SUMMON);
                    }
                }break;
                case HADES_SUMMON:{
                    if((claw_left_data->e_state == HADESCLAW_WAIT || claw_left_data->e_state == HADESCLAW_HIDDEN) && (claw_right_data->e_state == HADESCLAW_WAIT || claw_right_data->e_state == HADESCLAW_HIDDEN)){
                        flag_hades_summon = 1u;
                        hades_change_state(THIS, HADES_IDLE);
                    }
                }break;
            }
        }break;
        case 4:{
            switch(hades_state){
                case HADES_IDLE:{
                    switch(hadesskull_data->e_state){
                        case GENERIC_IDLE:
                            hadesskull_data->frmskip_wait++;
                            if(hadesskull_data->frmskip_wait == hadesskull_data->frmskip){
                                hadesskull_data->frmskip_wait = 0;
                                if(boss_breath_flag){
                                    THIS->y += boss_breath_verse;
                                    //boss_breath_flag = 0;
                                }
                            }
                            hadesskull_data->wait--;
                            if(hadesskull_data->wait == 0){
                                hades_change_state(THIS, HADES_CLAW_STRAIGHT);
                            }
                        break;
                    }
                }break;
                case HADES_CLAW_STRAIGHT:{
                    if((claw_left_data->e_state == HADESCLAW_WAIT || claw_left_data->e_state == HADESCLAW_HIDDEN) && (claw_right_data->e_state == HADESCLAW_WAIT || claw_right_data->e_state == HADESCLAW_HIDDEN) && claw_left_data->wait == 0 && claw_right_data->wait == 0){
                        hades_change_state(THIS, HADES_FIREBALL_SINGLE);
                    }
                }break;
                case HADES_FIREBALL_SINGLE:{
                    if((claw_left_data->e_state == HADESCLAW_WAIT || claw_left_data->e_state == HADESCLAW_HIDDEN) && (claw_right_data->e_state == HADESCLAW_WAIT || claw_right_data->e_state == HADESCLAW_HIDDEN)){
                        flag_hades_summon = 1u;
                        hades_change_state(THIS, HADES_IDLE);
                    }
                }break;
            }
        }break;
    }
    //anytime, if both hands are damaged (custom_data->vy==1) force to HADES_IDLE
    if(claw_left_data->vy && claw_right_data->vy){
        hades_change_state(THIS, HADES_IDLE);
        if(boss_hp_current > 1){
            hades_regerate_claws();
        }
        hades_skull_reset_data(THIS);
        flag_camera_shake_h = 1;
    }
}

void hades_skull_reset_data(Sprite* arg_s_hadesskull) BANKED{
    struct EnemyInfo* hadesskull_data = (struct EnemyInfo*)arg_s_hadesskull->custom_data;
    hadesskull_data->e_state = GENERIC_IDLE;
    hadesskull_data->frmskip = 8;
    hadesskull_data->frmskip_wait = 0;
    hadesskull_data->wait = 200;
}

void hades_regerate_claws() BANKED{
    s_hades_claw_left = SpriteManagerAdd(SpriteHadesclaw, 42u, 42u);
    s_hades_claw_right = SpriteManagerAdd(SpriteHadesclaw, 100u, 42u);
    s_hades_claw_right->mirror = V_MIRROR;
    hadesclaw_set_finalposs(42u - 10u, 42u, 100u + 10u, 42u);
}

void hades_change_state(Sprite* arg_s_hadesskull, SPRITE_STATES arg_new_state) BANKED{
    hades_state = arg_new_state;
    struct EnemyInfo* hadesskull_data = (struct EnemyInfo*)arg_s_hadesskull->custom_data;
    hadesskull_data->wait = 200;
    THIS->x = THIS->lim_x;
    THIS->y = THIS->lim_y;
    //if(arg_new_state == HADES_SUMMON){
        //start claws from HADESCLAW_IDLE state
        struct EnemyInfo* claw_left_data = (struct EnemyInfo*)s_hades_claw_left->custom_data;
        if(claw_left_data->e_state != HADESCLAW_HIDDEN){
            claw_left_data->e_state = HADESCLAW_IDLE;
        }
        struct EnemyInfo* claw_right_data = (struct EnemyInfo*)s_hades_claw_right->custom_data;
        if(claw_right_data->e_state != HADESCLAW_HIDDEN){
            claw_right_data->e_state = HADESCLAW_IDLE;
        }
    //}
    hadesclaw_change_state(s_hades_claw_left);
    hadesclaw_change_state(s_hades_claw_right);
}

void DESTROY() {
}