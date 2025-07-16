#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

#define FRMSKIPMAX_MAX 8
#define FRMSKIPMAX_MED 6
#define FRMSKIPMAX_MIN 4

extern UINT8 boss_breath_flag;
extern INT8 boss_breath_verse;
const UINT8 a_cerberushead_hidden[] = {1, 0};
const UINT8 a_cerberusheadleft[] = {1, 3};
const UINT8 a_cerberusheadcenter[] = {1, 1};
const UINT8 a_cerberushead_bite[] = {1, 2};
const UINT8 a_cerberushead_hit[] = {2, 0,2};
const UINT8 a_cerberushead_dead[] = {1, 4};

/*
CerberusInfo{
	SPRITE_STATES e_state;
	INT8 vx;
	INT8 vy;
    INT8 wait;
	INT8 frmskip;
	INT8 frmskip_max;
	INT8 head_config;
*/
void START() {
    SetSpriteAnim(THIS, a_cerberushead_hidden, 1);
    struct CerberusInfo* head_info = (struct CerberusInfo*)THIS->custom_data;
    head_info->head_config = 0;
    head_info->frmskip = 0;
    head_info->frmskip_max = FRMSKIPMAX_MAX;
    head_info->e_state = GENERIC_IDLE;
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
    struct CerberusInfo* head_info = (struct CerberusInfo*)THIS->custom_data;
    switch(head_info->head_config){
        case 0: return; break;
        case 1: //set left
            SetSpriteAnim(THIS, a_cerberusheadleft, 1);
            head_info->head_config = 4;
        break;
        case 2: //set center
            SetSpriteAnim(THIS, a_cerberusheadcenter, 1);
            head_info->head_config = 5;
        break;
        case 4: //is left
            switch(head_info->e_state){
                case GENERIC_IDLE:
                    if(boss_breath_flag){
                        THIS->y += boss_breath_verse;
                        boss_breath_flag = 0;
                    }
                    head_info->frmskip++;
                    if(head_info->frmskip == head_info->frmskip_max){
                        head_info->frmskip = 0;
                    }
                break;
            }
        break;
        case 5: //is center
        break;
    }
}

void DESTROY() {
}