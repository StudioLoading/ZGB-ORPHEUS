#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"


const UINT8 a_hadesskull[] = {1, 1};
const UINT8 a_hadesskull_blink[] = {2, 0,1};

extern UINT8 boss_breath_flag;
extern INT8 boss_breath_verse;
extern Sprite* s_hades_claw_left;
extern Sprite* s_hades_claw_right;
HADES_STATE hades_state = HADES_IDLE;

void hades_change_state(Sprite* arg_s_hadesskull, SPRITE_STATES arg_new_state) BANKED;

extern void hadesclaw_change_state(Sprite* arg_s_claw) BANKED;


void START() {
    THIS->lim_x = THIS->x;
    THIS->lim_y = THIS->y;
    SetSpriteAnim(THIS, a_hadesskull, 1u);
    struct EnemyInfo* hadesskull_data = (struct EnemyInfo*)THIS->custom_data; 
    hadesskull_data->e_state = GENERIC_IDLE;
    hadesskull_data->frmskip = 8;
    hadesskull_data->frmskip_wait = 0;
    hadesskull_data->wait = 200;
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
    struct EnemyInfo* hadesskull_data = (struct EnemyInfo*)THIS->custom_data;
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
            struct EnemyInfo* claw_left_data = (struct EnemyInfo*)s_hades_claw_left->custom_data;
            struct EnemyInfo* claw_right_data = (struct EnemyInfo*)s_hades_claw_right->custom_data;
            if(claw_left_data->e_state == HADESCLAW_WAIT && claw_right_data->e_state == HADESCLAW_WAIT){
                hades_change_state(THIS, HADES_IDLE);
            }
        }break;
    }
}

void hades_change_state(Sprite* arg_s_hadesskull, SPRITE_STATES arg_new_state) BANKED{
    hades_state = arg_new_state;
    struct EnemyInfo* hadesskull_data = (struct EnemyInfo*)arg_s_hadesskull->custom_data;
    hadesskull_data->wait = 200;
    THIS->x = THIS->lim_x;
    THIS->y = THIS->lim_y;
    hadesclaw_change_state(s_hades_claw_left);
    hadesclaw_change_state(s_hades_claw_right);
}

void DESTROY() {
}