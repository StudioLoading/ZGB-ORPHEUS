#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"


const UINT8 a_cerberushead_hidden[] = {1, 0};
const UINT8 a_cerberusheadleft[] = {1, 3};
const UINT8 a_cerberusheadright[] = {1, 3};
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
        case 3: //set right
            SetSpriteAnim(THIS, a_cerberusheadright, 1);
            head_info->head_config = 6;
        break;
        case 4: //is left
        break;
        case 5: //is center
        break;
        case 6: //is right
        break;
    }
}

void DESTROY() {
}