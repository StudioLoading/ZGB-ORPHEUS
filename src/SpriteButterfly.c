#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"
#include "CircleMath.h"


const UINT8 a_butt_idle[] = {3, 0,1,0};
const UINT8 a_butt_fly[] = {4, 0,1,2,1};

void START() {
    THIS->lim_x = THIS->x;
    THIS->lim_y = THIS->y;
    SetSpriteAnim(THIS, a_butt_idle, 4u);
    struct EnemyInfo* butt_data = (struct EnemyInfo*) THIS->custom_data;
    butt_data->e_state = GENERIC_IDLE;
    butt_data->wait = 120u;
    butt_data->frmskip = 2u;
    butt_data->frmskip_wait = 0u;
    butt_data->e_configured = 0u;
    butt_data->vx = 1;
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
}

void UPDATE() {
    struct EnemyInfo* butt_data = (struct EnemyInfo*) THIS->custom_data;
    if(butt_data->e_configured == 0){ return; }
    butt_data->frmskip_wait--;
    if(butt_data->frmskip_wait > 0){
        return;
    }
    butt_data->frmskip_wait = butt_data->frmskip;
    switch(butt_data->e_state){
        case GENERIC_IDLE:
            butt_data->wait--;
            if(butt_data->wait == 0){
                butt_data->e_configured++;
                if(butt_data->e_configured > 3u){
                    butt_data->e_configured = 1u;
                }
                butt_data->wait = 80;
                if(butt_data->e_configured == 2){
                    butt_data->wait = 120;
                }
                SetSpriteAnim(THIS, a_butt_fly, 24u);
                if(butt_data->vx == 1){ butt_data->vx = -1;}
                else{butt_data->vx = 1;}
                butt_data->vy = 0;
                butt_data->e_state = GENERIC_WALK;
            }
        break;
        case GENERIC_WALK:{
            UINT8 cos_position = butt_data->tile_collision + 64u;
            if(butt_data->e_configured == 1){
                THIS->x = THIS->lim_x + (butt_data->vx * ((sine_wave[cos_position]) >> 2));
                THIS->y = THIS->lim_y + ((sine_wave[butt_data->tile_collision]) >> 3);
            }else if(butt_data->e_configured == 2){
                THIS->x = THIS->lim_x + (butt_data->vx * ((sine_wave[cos_position]) >> 4));
                THIS->y = THIS->lim_y + ((sine_wave[butt_data->tile_collision]) >> 2);
            }
            butt_data->tile_collision += 3u;
            butt_data->wait--;
            if(butt_data->wait <= 10){
                butt_data->wait = 180u;
                if(butt_data->e_configured == 2){
                    butt_data->wait = 60u;
                }
                SetSpriteAnim(THIS, a_butt_idle, 4u);
                butt_data->e_state = GENERIC_IDLE;
            }
        }break;
    }
}

void DESTROY() {
}