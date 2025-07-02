#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"
#include "CircleMath.h"

extern INT8 boss_hp_current;
extern struct CharonInfo charon_info;

const UINT8 a_charonhand[] = {1, 1};
const UINT8 a_charonhand_blink[] = {2, 0,1};

/*
struct EnemyInfo{
	SPRITE_STATES e_state;
	UINT8 tile_collision;
	INT8 vx;
	INT8 vy;
    UINT8 wait;
	UINT8 frmskip_wait;
	UINT8 e_configured;
	UINT8 frmskip;
}; */
void START() {
    struct EnemyInfo* charonhand_data = (struct EnemyInfo*)THIS->custom_data;
    charonhand_data->wait = 0u;
    charonhand_data->e_configured = 0u;
    SetSpriteAnim(THIS, a_charonhand, 1u);
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
    struct EnemyInfo* charonhand_data = (struct EnemyInfo*)THIS->custom_data;
    switch(charon_info.e_state){
        case PREATTACK_UP:{
            switch(charonhand_data->e_configured){
                case 0:{
                    if(charonhand_data->frmskip == 0){//right hand
                	    THIS->lim_x = THIS->x - 8;
                    }else{
                        THIS->lim_x = THIS->x + 12;
                    }
		            THIS->lim_y = THIS->y;
                    charonhand_data->e_configured = 1;
                }
                break;
                case 1:{
                    UINT8 cos_position = charonhand_data->wait + 64u;
                    THIS->x = THIS->lim_x + ((sine_wave[cos_position]) >> 3) - 2;
                    THIS->y = THIS->lim_y + ((sine_wave[charonhand_data->wait]) >> 3) - 2;
                    if(charonhand_data->frmskip == 0){//right hand, moves counterclock
                        charonhand_data->wait -= (12 / boss_hp_current);
                    }else{
                        charonhand_data->wait += (12 / boss_hp_current);
                    }
                    charonhand_data->frmskip_wait--;
                    if(charonhand_data->frmskip_wait == 0){
                        if(charonhand_data->frmskip == 0){//right hand
                            THIS->x = THIS->lim_x + 8u;
                        }else{
                            THIS->x = THIS->lim_x -12u;
                        }
                        THIS->y = THIS->lim_y;
                        SetSpriteAnim(THIS, a_charonhand_blink, 24u);
                        charonhand_data->frmskip_wait = 30u;
                        charonhand_data->e_configured = 2;
                    }
                }
                break;
                case 2:
                    charonhand_data->frmskip_wait--;
                    if(charonhand_data->frmskip_wait == 0){
                        charonhand_data->e_configured = 3;//READY TO ATTACK!
                    }
                break;
            }
        }
        break;
        case ATTACK:
            if(charonhand_data->e_configured == 0){
                SetSpriteAnim(THIS, a_charonhand, 1u);
                charonhand_data->e_configured = 1;
            }else if(charonhand_data->e_configured == 1){
                TranslateSprite(THIS, 0, 1 << delta_time);
            }
        break;
    }
}

void DESTROY() {
}