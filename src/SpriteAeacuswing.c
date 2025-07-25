#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"


const UINT8 a_aeacuswing_opened[] = {1, 1};
const UINT8 a_aeacuswing_watch[] = {1, 1};
const UINT8 a_aeacuswing_covered[] = {1, 3};
const UINT8 a_aeacuswing_fly[] = {5, 1,1,1,2,3};
const UINT8 a_aeacuswing_hit[] = {2, 0,1};
const UINT8 a_aeacuswing_hidden[] = {1, 0};

extern Sprite* s_awacus_body;
extern UINT8 aeacusbody_arrived;
extern UINT8 aeacusbody_arrived_back;
extern AEACUS_PHASE aeacus_phase;
extern Sprite* s_aeacus_wing_left;
extern Sprite* s_aeacus_wing_right;

void START() {
    THIS->lim_x = 10u;
    THIS->lim_y = 10u;
    SetSpriteAnim(THIS, a_aeacuswing_fly, 10u);
    struct EnemyInfo* aeacuswing_data = (struct EnemyInfo*)THIS->custom_data;
    aeacuswing_data->e_configured = 0;
    aeacuswing_data->frmskip_wait = 0;
    aeacuswing_data->frmskip = 24u;
    aeacuswing_data->vx = 0;
    aeacuswing_data->vy = 0;
}

void UPDATE() {
    struct EnemyInfo* aeacuswing_data = (struct EnemyInfo*)THIS->custom_data;
    switch(aeacuswing_data->e_configured){
        case 0u:
        break;
        case 1u:{//left
            if(THIS->mirror != NO_MIRROR){
				THIS->mirror = NO_MIRROR;
            }
            THIS->x = s_awacus_body->x - 18u;
            THIS->y = s_awacus_body->y + 4u;
        }break;
        case 2u:{//right
            if(THIS->mirror != V_MIRROR){
				THIS->mirror = V_MIRROR;
            }
            THIS->x = s_awacus_body->x + 10u;
            THIS->y = s_awacus_body->y + 4u;
            THIS->anim_speed = s_aeacus_wing_left->anim_speed;
            THIS->anim_frame = s_aeacus_wing_left->anim_frame;
        }break;
        case 3u:{//left closed
            THIS->x = s_awacus_body->x - 4;
            THIS->y = s_awacus_body->y + 8u;
            THIS->mirror = HV_MIRROR;
            SetSpriteAnim(THIS, a_aeacuswing_covered, 1u);
            if(aeacuswing_data->wait == 0){                
                SetSpriteAnim(THIS, a_aeacuswing_fly, 10u);
                THIS->anim_speed = s_aeacus_wing_right->anim_speed;
                THIS->anim_frame = s_aeacus_wing_right->anim_frame;
                THIS->mirror = NO_MIRROR;
                aeacuswing_data->e_configured = 1u;
            }
        }break;
        case 4u:{//right closed
            THIS->x = s_awacus_body->x - 5;
            THIS->y = s_awacus_body->y + 9u;
            THIS->mirror = H_MIRROR;
            SetSpriteAnim(THIS, a_aeacuswing_covered, 1u);
            if(aeacuswing_data->wait == 0){                
                SetSpriteAnim(THIS, a_aeacuswing_fly, 10u);
                THIS->anim_speed = s_aeacus_wing_left->anim_speed;
                THIS->anim_frame = s_aeacus_wing_left->anim_frame;
				THIS->mirror = V_MIRROR;
                aeacuswing_data->e_configured = 2u;
            }
        }break;
    }
    switch(THIS->anim_frame){
        case 0:
        case 1:
            THIS->y++;
        break;
        case 3:
            THIS->y-=2;
        break;
        case 4:
            THIS->y+=2;
            THIS->y--;
        break;
    }
    switch(aeacus_phase){
        case AEA_IDLE:{
            SetSpriteAnim(THIS, a_aeacuswing_fly, 16u);
            THIS->anim_speed = 16u;
            /*if(aeacuswing_data->e_configured == 2){
                THIS->anim_speed = s_aeacus_wing_left->anim_speed;
                THIS->anim_frame = s_aeacus_wing_left->anim_frame;
            }*/
        }break;
        case AEA_BODY_WATCH:{
            SetSpriteAnim(s_aeacus_wing_right, a_aeacuswing_watch, 16u);
            SetSpriteAnim(s_aeacus_wing_left, a_aeacuswing_watch, 16u);
        }break;
        case AEA_BODY_FLY:{
            if(aeacusbody_arrived == 0){
                SetSpriteAnim(THIS, a_aeacuswing_opened, 1u);
            }else{//} if(aeacusbody_arrived_back == 0){
                SetSpriteAnim(THIS, a_aeacuswing_fly, 64u);
            }
        }break;
    }
}

void DESTROY() {
}