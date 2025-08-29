#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"


const UINT8 a_hadesskull[] = {2, 1,2};
const UINT8 a_hadesskull_still[] = {1, 3};
const UINT8 a_hadesskull_looking[] = {8, 2,1,3,3,3,3,3,3};
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
extern Sprite* s_orpheus;
extern UINT16 saved_orpheus_posx;
extern UINT16 saved_orpheus_posy;

HADES_STATE hades_state = HADES_IDLE;
UINT8 hadesskull_arrived = 0;

void hades_change_state(Sprite* arg_s_hadesskull, SPRITE_STATES arg_new_state) BANKED;
void hades_regenerate_claws() BANKED;
void hades_skull_reset_data(Sprite* arg_s_hadesskull) BANKED;

extern void hadesclaw_change_state(Sprite* arg_s_claw) BANKED;
extern void hadesclaw_set_finalposs(UINT16 arg_leftposx, UINT16 arg_leftposy, UINT16 arg_rightposx, UINT16 arg_rightposy) BANKED;
extern void spawn_ball(UINT8 arg_type, UINT16 arg_spawnfireball_x, UINT16 arg_spawnfireball_y, UINT8 arg_direction) BANKED;
extern UINT8 aeacusbody_move_to_point(Sprite* aea_s_aeacusbody, UINT16 arg_final_posx, UINT16 arg_final_posy) BANKED;

void START() {
    THIS->lim_x = THIS->x;
    THIS->lim_y = THIS->y;
    SetSpriteAnim(THIS, a_hadesskull, 60u);
    struct EnemyInfo* hadesskull_data = (struct EnemyInfo*)THIS->custom_data;
    hadesskull_data->frmskip_wait = 0;
    hadesskull_data->frmskip = 0;
    hadesskull_arrived = 0;
    hades_skull_reset_data(THIS);
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
    struct EnemyInfo* hadesskull_data = (struct EnemyInfo*)THIS->custom_data;
    struct EnemyInfo* claw_left_data = 0;
    struct EnemyInfo* claw_right_data = 0;
    if(s_hades_claw_left && s_hades_claw_right){
        claw_left_data = (struct EnemyInfo*)s_hades_claw_left->custom_data;
        claw_right_data = (struct EnemyInfo*)s_hades_claw_right->custom_data;
    }
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
                                hades_change_state(THIS, HADES_CLAW_LEFT_CIRCLE);
                            }
                        break;
                    }
                }break;
                case HADES_CLAW_LEFT_CIRCLE:
                    if((claw_left_data->e_state == HADESCLAW_WAIT || claw_left_data->e_state == HADESCLAW_HIDDEN) && claw_left_data->wait == 0){
                        hades_change_state(THIS, HADES_SUMMON);
                    }
                break;
                case HADES_SUMMON:{
                    if((claw_left_data->e_state == HADESCLAW_WAIT || claw_left_data->e_state == HADESCLAW_HIDDEN) && (claw_right_data->e_state == HADESCLAW_WAIT || claw_right_data->e_state == HADESCLAW_HIDDEN)){
                        flag_hades_summon = 1u;
                        hades_change_state(THIS, HADES_CLAW_RIGHT_CIRCLE);
                    }
                }break;
                case HADES_CLAW_RIGHT_CIRCLE:
                    if((claw_right_data->e_state == HADESCLAW_WAIT || claw_right_data->e_state == HADESCLAW_HIDDEN) && claw_right_data->wait == 0){
                        hades_change_state(THIS, HADES_CLAW_DEATHLY_HUG);
                    }
                break;
                case HADES_CLAW_DEATHLY_HUG:{
                    if((claw_left_data->e_state == HADESCLAW_WAIT || claw_left_data->e_state == HADESCLAW_HIDDEN) && (claw_right_data->e_state == HADESCLAW_WAIT || claw_right_data->e_state == HADESCLAW_HIDDEN) && claw_left_data->wait == 0 && claw_right_data->wait == 0){
                        hades_change_state(THIS, HADES_IDLE);
                    }
                }break;
            }
        }break;
        case 4:
        case 3:{
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
                        hades_change_state(THIS, HADES_FIREBALL_DOUBLE);
                    }
                }break;
                case HADES_FIREBALL_DOUBLE:{
                    switch(hadesskull_data->e_state){
                        case GENERIC_IDLE:{
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
                                saved_orpheus_posx = s_orpheus->x + 4u;
                                saved_orpheus_posy = s_orpheus->y - 8u;
                                SetSpriteAnim(THIS, a_hadesskull_looking, 12u);
                                hadesskull_data->e_state = PREATTACK_DOWN;
                            }
                        }break;
                        case PREATTACK_DOWN:
                            hadesskull_data->wait--;
                            if(hadesskull_data->wait == 120){
                                spawn_ball(SpriteFireball, THIS->x + 4u, THIS->y + 24u, J_DOWN + J_DOWN + J_RIGHT);
                            }
                            if(hadesskull_data->wait == 90){
                                spawn_ball(SpriteFireball, THIS->x + 4u, THIS->y + 24u, 0);
                            }else if(hadesskull_data->wait == 60){
                                spawn_ball(SpriteFireball, THIS->x + 4u, THIS->y + 24u, J_DOWN + J_DOWN + J_LEFT);
                            }else if(hadesskull_data->wait < 10){
                                hadesskull_data->e_state = GENERIC_WALK;
                            }
                        break;
                        case GENERIC_WALK:
                            hadesskull_data->e_state = GENERIC_IDLE;
                            hades_change_state(THIS, HADES_IDLE);
                        break;
                    }
                }break;
            }
        }break;
        case 2:{
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
                                flag_hades_summon = 1u;
                                hades_change_state(THIS, HADES_FIREBALL_DOUBLE);
                            }
                        break;
                    }
                }break;
                case HADES_FIREBALL_DOUBLE:{
                    switch(hadesskull_data->e_state){
                        case GENERIC_IDLE:{
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
                                saved_orpheus_posx = s_orpheus->x + 4u;
                                saved_orpheus_posy = s_orpheus->y - 8u;
                                SetSpriteAnim(THIS, a_hadesskull_looking, 12u);
                                hadesskull_data->e_state = PREATTACK_DOWN;
                            }
                        }break;
                        case PREATTACK_DOWN:
                            hadesskull_data->wait--;
                            if(hadesskull_data->wait == 120){
                                spawn_ball(SpriteFireball, THIS->x + 4u, THIS->y + 24u, J_DOWN + J_DOWN + J_RIGHT);
                            }
                            if(hadesskull_data->wait == 90){
                                spawn_ball(SpriteFireball, THIS->x + 4u, THIS->y + 24u, 0);
                            }else if(hadesskull_data->wait == 60){
                                spawn_ball(SpriteFireball, THIS->x + 4u, THIS->y + 24u, J_DOWN + J_DOWN + J_LEFT);
                            }else if(hadesskull_data->wait < 10){
                                hades_change_state(THIS, HADES_SUMMON);
                            }
                        break;
                    }
                }break;
                case HADES_SUMMON:{
                    hadesskull_data->wait--;
                    if(hadesskull_data->wait > 100){
                        saved_orpheus_posx = s_orpheus->x + 4u;
                        saved_orpheus_posy = s_orpheus->y - 8u;
                        SetSpriteAnim(THIS, a_hadesskull_looking, 12u);
                    }else if(hadesskull_data->wait == 0){
                        flag_hades_summon = 1;
                        SetSpriteAnim(THIS, a_hadesskull_still, 1);
                        hadesskull_data->vx = 2;
                        hadesskull_data->vy = 2;
                        hadesskull_data->frmskip_wait = 0;
                        hadesskull_data->frmskip = 0;
                        hades_change_state(THIS, HADES_FIREBALL_QUADRUPLE);
                    }
                }break;
                case HADES_FIREBALL_QUADRUPLE:{
                    switch(hadesskull_data->e_state){
                        case GENERIC_IDLE:{
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
                                saved_orpheus_posx = s_orpheus->x + 4u;
                                saved_orpheus_posy = s_orpheus->y - 8u;
                                SetSpriteAnim(THIS, a_hadesskull_looking, 12u);
                                hadesskull_data->wait = 180;
                                hadesskull_data->e_state = PREATTACK_DOWN;
                            }
                        }break;
                        case PREATTACK_DOWN:{
                            hadesskull_data->wait--;
                            if(hadesskull_data->wait == 120){
                                spawn_ball(SpriteFireball, THIS->x + 4u, THIS->y + 24u, J_DOWN + J_LEFT);
                            }else if(hadesskull_data->wait == 100){
                                spawn_ball(SpriteFireball, THIS->x + 4u, THIS->y + 24u, J_DOWN + J_DOWN + J_LEFT);
                            }else if(hadesskull_data->wait == 80){
                                spawn_ball(SpriteFireball, THIS->x + 4u, THIS->y + 24u, J_DOWN);
                            }else if(hadesskull_data->wait == 60){
                                spawn_ball(SpriteFireball, THIS->x + 4u, THIS->y + 24u, J_DOWN + J_DOWN + J_RIGHT);
                            }else if(hadesskull_data->wait == 40){
                                spawn_ball(SpriteFireball, THIS->x + 4u, THIS->y + 24u, J_DOWN + J_RIGHT);
                            }else if(hadesskull_data->wait < 10){
                                hadesskull_data->e_state = GENERIC_IDLE;
                                hades_change_state(THIS, HADES_HEADBUTT);
                            }
                        }break;
                    }
                }break;
                case HADES_HEADBUTT:{
                    switch(hadesskull_data->e_state){
                        case GENERIC_IDLE:{
                            hadesskull_data->frmskip_wait++;
                            if(hadesskull_data->frmskip_wait == hadesskull_data->frmskip){
                                hadesskull_data->frmskip_wait = 0;
                                if(boss_breath_flag){
                                    THIS->y += boss_breath_verse;
                                    //boss_breath_flag = 0;
                                }
                            }
                            hadesskull_data->wait--;
                            if(hadesskull_data->wait > 100){
                                saved_orpheus_posx = s_orpheus->x + 4u;
                                saved_orpheus_posy = s_orpheus->y - 8u;
                                SetSpriteAnim(THIS, a_hadesskull_looking, 12u);
                            }else if(hadesskull_data->wait == 0){
                                SetSpriteAnim(THIS, a_hadesskull_still, 12u);
                                hadesskull_data->e_state = ATTACK;
                            }
                        }break;
                        case ATTACK:{
                            if(hadesskull_arrived){
                                hadesskull_data->frmskip_wait = 0;
                                hadesskull_data->frmskip = 0;
                                UINT8 hadesskull_arrived_back = aeacusbody_move_to_point(THIS, THIS->lim_x, THIS->lim_y);
                                if(hadesskull_arrived_back){
                                    hades_skull_reset_data(THIS);
                                    hades_change_state(THIS, HADES_IDLE);
                                }
                            }else{
                                hadesskull_arrived = aeacusbody_move_to_point(THIS, saved_orpheus_posx, saved_orpheus_posy);
                            }
                        }break;
                    }
                }break;
            }
        }break;
    }
    //anytime, if both hands are damaged (custom_data->vy==1) force to HADES_IDLE
    if(claw_left_data && claw_right_data && claw_left_data->vy && claw_right_data->vy){
        hades_change_state(THIS, HADES_IDLE);
        if(boss_hp_current > 2){
            hades_regenerate_claws();
        }else if(s_hades_claw_left && s_hades_claw_right){
            SpriteManagerRemoveSprite(s_hades_claw_left);
            SpriteManagerRemoveSprite(s_hades_claw_right);
            s_hades_claw_left = 0;
            s_hades_claw_right = 0;
        }
        hades_skull_reset_data(THIS);
    }
}

void hades_skull_reset_data(Sprite* arg_s_hadesskull) BANKED{
    struct EnemyInfo* hadesskull_data = (struct EnemyInfo*)arg_s_hadesskull->custom_data;
    hadesskull_data->e_state = GENERIC_IDLE;
    if(boss_hp_current > 2){
        hadesskull_data->frmskip = 8;
    }
    hadesskull_data->frmskip_wait = 0;
    hadesskull_data->wait = 80 + (boss_hp_current << 3);
}

void hades_regenerate_claws() BANKED{
    SpriteManagerRemoveSprite(s_hades_claw_left);
    SpriteManagerRemoveSprite(s_hades_claw_right);
    s_hades_claw_left = SpriteManagerAdd(SpriteHadesclaw, 42u, 42u);
    s_hades_claw_right = SpriteManagerAdd(SpriteHadesclaw, 100u, 42u);
    s_hades_claw_right->mirror = V_MIRROR;
    hadesclaw_set_finalposs(42u - 10u, 42u, 100u + 10u, 42u);
}

void hades_change_state(Sprite* arg_s_hadesskull, SPRITE_STATES arg_new_state) BANKED{
    hades_state = arg_new_state;
    struct EnemyInfo* hadesskull_data = (struct EnemyInfo*)arg_s_hadesskull->custom_data;
    hadesskull_data->wait = 60 + (boss_hp_current << 3);;
    THIS->x = THIS->lim_x;
    THIS->y = THIS->lim_y;
    SetSpriteAnim(arg_s_hadesskull, a_hadesskull, 60u);
    if(boss_hp_current > 2){
        struct EnemyInfo* claw_left_data = (struct EnemyInfo*)s_hades_claw_left->custom_data;
        if(claw_left_data->e_state != HADESCLAW_HIDDEN){
            claw_left_data->e_state = HADESCLAW_IDLE;
        }
        struct EnemyInfo* claw_right_data = (struct EnemyInfo*)s_hades_claw_right->custom_data;
        if(claw_right_data->e_state != HADESCLAW_HIDDEN){
            claw_right_data->e_state = HADESCLAW_IDLE;
        }
        hadesclaw_change_state(s_hades_claw_left);
        hadesclaw_change_state(s_hades_claw_right);
    }
}

void DESTROY() {
}