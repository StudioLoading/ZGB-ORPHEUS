#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"


const UINT8 a_hadesclaw[] = {1, 1};
const UINT8 a_hadesclaw_blink[] = {2, 0,1};

extern UINT8 boss_breath_flag;
extern INT8 boss_breath_verse;

void START() {
    THIS->lim_x = THIS->x;
    THIS->lim_y = THIS->y;
    SetSpriteAnim(THIS, a_hadesclaw, 1u);
    struct EnemyInfo* hadesclaw_data = (struct EnemyInfo*)THIS->custom_data; 
    hadesclaw_data->e_state = GENERIC_IDLE;
    hadesclaw_data->frmskip = 8;
    hadesclaw_data->frmskip_wait = 0;
    hadesclaw_data->wait = 200;
}

void UPDATE() {
    struct EnemyInfo* hadesclaw_data = (struct EnemyInfo*)THIS->custom_data; 
    switch(hadesclaw_data->e_state){
        case GENERIC_IDLE:
            hadesclaw_data->frmskip_wait++;
            if(hadesclaw_data->frmskip_wait == hadesclaw_data->frmskip){
                hadesclaw_data->frmskip_wait = 0;
                if(boss_breath_flag){
                    THIS->y += boss_breath_verse;
                    //boss_breath_flag = 0;
                }
            }
            hadesclaw_data->wait--;
            if(hadesclaw_data->wait == 0){
                //hades_change_state(THIS, GENERIC_WALK);
            }
        break;
    }
}

void DESTROY() {
}