#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"
#include "CircleMath.h"


const UINT8 dog_up[] = {2, 5,6};
const UINT8 dog_h[] = {4, 2,3,4,3};
const UINT8 dog_down[] = {2, 0,1};

const UINT8 dog_idleup[] = {2, 5,6};
const UINT8 dog_idleh[] = {1, 2};
const UINT8 dog_idledown[] = {2, 0,1};

void START() {
    THIS->lim_x = THIS->x;
    THIS->lim_y = THIS->y;
    SetSpriteAnim(THIS, dog_idledown, 4u);
    struct EnemyInfo* dog_data = (struct EnemyInfo*) THIS->custom_data;
    dog_data->e_state = GENERIC_IDLE;
    dog_data->wait = 120u;
    dog_data->frmskip = 2u;
    dog_data->frmskip_wait = 0u;
    dog_data->e_configured = 0u;
    dog_data->vx = 1;
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
    struct EnemyInfo* dog_data = (struct EnemyInfo*) THIS->custom_data;
    if(dog_data->e_configured == 0){ return; }
    dog_data->frmskip_wait--;
    if(dog_data->frmskip_wait > 0){
        return;
    }
    dog_data->frmskip_wait = dog_data->frmskip;
    switch(dog_data->e_state){
        case GENERIC_IDLE:
            dog_data->wait--;
            if(dog_data->wait == 0){
                dog_data->e_configured++;
                if(dog_data->e_configured > 3u){
                    dog_data->e_configured = 1u;
                }
                dog_data->wait = 80;
                if(dog_data->e_configured == 2){
                    dog_data->wait = 120;
                }
                SetSpriteAnim(THIS, dog_h, 24u);
                if(dog_data->vx == 1){ dog_data->vx = -1;}
                else{dog_data->vx = 1;}
                dog_data->vy = 0;
                dog_data->e_state = GENERIC_WALK;
            }
        break;
        case GENERIC_WALK:{
            UINT8 cos_position = dog_data->tile_collision + 64u;
            if(dog_data->e_configured == 1){
                THIS->x = THIS->lim_x + (dog_data->vx * ((sine_wave[cos_position]) >> 2));
                THIS->y = THIS->lim_y + ((sine_wave[dog_data->tile_collision]) >> 3);
            }else if(dog_data->e_configured == 2){
                THIS->x = THIS->lim_x + (dog_data->vx * ((sine_wave[cos_position]) >> 4));
                THIS->y = THIS->lim_y + ((sine_wave[dog_data->tile_collision]) >> 2);
            }
            dog_data->tile_collision += 3u;
            dog_data->wait--;
            if(dog_data->wait <= 10){
                dog_data->wait = 180u;
                if(dog_data->e_configured == 2){
                    dog_data->wait = 60u;
                }
                SetSpriteAnim(THIS, dog_idledown, 4u);
                dog_data->e_state = GENERIC_IDLE;
            }
        }break;
    }
}

void DESTROY() {
}