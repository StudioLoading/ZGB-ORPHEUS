#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

#define COUNTER_MAX 8

const UINT8 a_ghost[] = {2, 0,1};
struct EnemyInfo* ghost_data = 0;

void START() {
    SetSpriteAnim(THIS, a_ghost, 56u);
    ghost_data = (struct EnemyInfo*) THIS->custom_data;
    ghost_data->e_state = WALK_RIGHT;
	ghost_data->tile_collision = 0;
	ghost_data->vx = -1;
	ghost_data->vy = 0;
    ghost_data->wait = 0;
	ghost_data->frmskip_wait = 0u;
	ghost_data->e_configured = 1u;
	ghost_data->frmskip = 6u;

}

void UPDATE() {
    ghost_data->frmskip_wait++;
    if(ghost_data->frmskip_wait < ghost_data->frmskip){
        return;
    }
    ghost_data->frmskip_wait = 0u;
    ghost_data->wait++;
    if(ghost_data->wait > 16){
        ghost_data->vy = 1;
    }else if(ghost_data->wait > 2){
        ghost_data->vy = -1;
    }else{
        ghost_data->vy = 0;
    }
    if(ghost_data->wait > 30){ghost_data->wait = 0;}
    UINT8 ghost_collision = TranslateSprite(THIS, ghost_data->vx << delta_time, ghost_data->vy << delta_time);
    if(ghost_collision){
        THIS->x += ghost_data->vx;
        THIS->y += ghost_data->vy;
    }    
}

void DESTROY() {
}