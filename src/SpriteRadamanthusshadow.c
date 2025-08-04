#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"
#include "CircleMath.h"


const UINT8 a_radamanthusshadow_hidden[] = {1, 0};
const UINT8 a_radamanthusshadow[] = {1, 1};
const UINT8 a_radamanthusshadow_blink[] = {2, 0,1};

extern INT8 boss_hp_current;

INT16 shadow_blinking_hp = 0;

void shadow_bounce(Sprite* arg_s_shadow, UINT8 arg_tile_collided) BANKED;
void radamanthusshadow_move(Sprite* arg_s_shadow) BANKED;
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
};

typedef enum{
	MOVEMENT_NONE,
	MOVEMENT_H,
	MOVEMENT_V,
	MOVEMENT_DIAGONAL,
	MOVEMENT_CLOCKWISE,
	MOVEMENT_COUNTERCLOCKWISE
}MOVEMENT_TYPE;

*/

void START() {
    SetSpriteAnim(THIS, a_radamanthusshadow_hidden, 1u);
    struct EnemyInfo* e_data = (struct EnemyInfo*) THIS->custom_data;
    e_data->e_configured = 0;
    e_data->wait = 0;
    e_data->e_state = GENERIC_IDLE;
    e_data->frmskip_wait = 0;
    e_data->frmskip = boss_hp_current;
    e_data->tile_collision = MOVEMENT_NONE;//MOVEMENT_TYPE
    shadow_blinking_hp = 30 << boss_hp_current;
}

void UPDATE() {
    struct EnemyInfo* e_data = (struct EnemyInfo*) THIS->custom_data;
    switch(e_data->e_configured){
        case 0: return; break;
        case 1:{
            switch(e_data->tile_collision){
                case MOVEMENT_NONE:
                    e_data->vx = 0;
                    e_data->vy = 0;
                break;
                case MOVEMENT_H_LEFT:
                    e_data->vx = -1;
                    e_data->vy = 0;
                break;
                case MOVEMENT_H_RIGHT:
                    e_data->vx = 1;
                    e_data->vy = 0;
                break;
                case MOVEMENT_V_UP:
                    e_data->vx = 0;
                    e_data->vy = -1;
                break;
                case MOVEMENT_V_DOWN:
                    e_data->vx = 0;
                    e_data->vy = 1;
                break;
                case MOVEMENT_DIAGONAL_NWSE:
                    e_data->vx = 1;
                    e_data->vy = 1;
                break;
                case MOVEMENT_DIAGONAL_SENW:
                    e_data->vx = -1;
                    e_data->vy = -1;
                break;
                case MOVEMENT_DIAGONAL_NESW:
                    e_data->vx = -1;
                    e_data->vy = 1;
                break;
                case MOVEMENT_DIAGONAL_SWNE:
                    e_data->vx = 1;
                    e_data->vy = -1;
                break;
            }
            e_data->e_configured = 2;
            e_data->wait = 40;
        }break;
        case 2:
            e_data->wait--;
            if(e_data->wait <= 0){
                e_data->wait = 0;
                SetSpriteAnim(THIS, a_radamanthusshadow, 1u);
                e_data->e_configured = 3;
            }        
        break;
        case 3:
            radamanthusshadow_move(THIS);
            shadow_blinking_hp--;
            if(shadow_blinking_hp <= 0){
                shadow_blinking_hp = 40;
                e_data->e_configured = 4;
                e_data->wait = 60;
                SetSpriteAnim(THIS, a_radamanthusshadow_blink, 24u);
            }
        break;
        case 4:
            e_data->frmskip_wait++;
            if(e_data->frmskip_wait >= e_data->frmskip){
                e_data->frmskip_wait = 0;
                e_data->wait --;
                if(e_data->wait <= 0){
                    SpriteManagerAdd(SpriteRadamanthusbrick, THIS->x, 0);
                    SetSpriteAnim(THIS, a_radamanthusshadow_hidden, 1u);
                    e_data->tile_collision++;
                    if(e_data->tile_collision > MOVEMENT_COUNTERCLOCKWISE){
                        e_data->tile_collision = MOVEMENT_H_LEFT;
                    }
                    e_data->wait = 255;
                    e_data->e_configured = 5;
                }
            }
        break;
        case 5:
            e_data->wait--;
            if(e_data->wait == 0){
                shadow_blinking_hp = 30 << boss_hp_current;
                e_data->e_configured = 1;
            }
        break;
    }
}

void radamanthusshadow_move(Sprite* arg_s_shadow) BANKED{
    struct EnemyInfo* e_data = (struct EnemyInfo*) arg_s_shadow->custom_data;
    e_data->frmskip_wait++;
    if(e_data->frmskip_wait >= e_data->frmskip){
        e_data->frmskip_wait = 0;
        UINT8 shadow_tile_collision = 0u;
        switch(e_data->tile_collision){
            case MOVEMENT_NONE: break;
            case MOVEMENT_H_LEFT:
            case MOVEMENT_H_RIGHT:
            case MOVEMENT_V_UP:
            case MOVEMENT_V_DOWN:
            case MOVEMENT_DIAGONAL_NESW:
            case MOVEMENT_DIAGONAL_SWNE:
            case MOVEMENT_DIAGONAL_NWSE:
            case MOVEMENT_DIAGONAL_SENW:
                shadow_tile_collision = TranslateSprite(arg_s_shadow, e_data->vx << delta_time, e_data->vy << delta_time);
            break;
            case MOVEMENT_CLOCKWISE:{
                UINT8 cos_position = e_data->wait + 64u;
                UINT16 new_posx = 64u + ((sine_wave[cos_position]) / 3);
                UINT16 new_posy = 72u + ((sine_wave[e_data->wait]) / 3);
                e_data->vx = (INT16)new_posx - (INT16)arg_s_shadow->x;
                e_data->vy = (INT16)new_posy - (INT16)arg_s_shadow->y;
                shadow_tile_collision = TranslateSprite(arg_s_shadow, e_data->vx << delta_time, e_data->vy << delta_time);
                e_data->wait = e_data->wait + 8;
            }break;
            case MOVEMENT_COUNTERCLOCKWISE:{
                UINT8 cos_position = e_data->wait + 64u;
                UINT16 new_posx = 64u + ((sine_wave[cos_position]) / 3);
                UINT16 new_posy = 72u + ((sine_wave[e_data->wait]) / 3);
                e_data->vx = (INT16)new_posx - (INT16)arg_s_shadow->x;
                e_data->vy = (INT16)new_posy - (INT16)arg_s_shadow->y;
                shadow_tile_collision = TranslateSprite(arg_s_shadow, e_data->vx << delta_time, e_data->vy << delta_time);
                e_data->wait = e_data->wait - 8;
            }break;
        }
        if(shadow_tile_collision){//BOUNCE!!!
            shadow_bounce(arg_s_shadow, shadow_tile_collision);
        }
    }
}

void shadow_bounce(Sprite* arg_s_shadow, UINT8 arg_tile_collided) BANKED{
    struct EnemyInfo* e_data = (struct EnemyInfo*) arg_s_shadow->custom_data;
    switch(e_data->tile_collision){
        case MOVEMENT_CLOCKWISE:
        case MOVEMENT_COUNTERCLOCKWISE:
            //do nothing
        break;
        case MOVEMENT_H_LEFT:
            e_data->tile_collision = MOVEMENT_H_RIGHT;
        break;
        case MOVEMENT_H_RIGHT:
            e_data->tile_collision = MOVEMENT_H_LEFT;
        break;
        case MOVEMENT_V_UP:
            e_data->tile_collision = MOVEMENT_V_DOWN;
        break;
        case MOVEMENT_V_DOWN:
            e_data->tile_collision = MOVEMENT_V_UP;
        break;
        case MOVEMENT_DIAGONAL_NWSE:{
            switch(arg_tile_collided){
                case 11://south wall
                    e_data->tile_collision = MOVEMENT_DIAGONAL_SWNE;
                break;
                case 9://east wall
                    e_data->tile_collision = MOVEMENT_DIAGONAL_NESW;
                break;
            }
        }break;
        case MOVEMENT_DIAGONAL_SENW:{
            switch(arg_tile_collided){
                case 19://west wall
                    e_data->tile_collision = MOVEMENT_DIAGONAL_SWNE;
                break;
                default:
                    e_data->tile_collision = MOVEMENT_DIAGONAL_NESW;
                break;
            }
        }break;
        case MOVEMENT_DIAGONAL_NESW:{
            switch(arg_tile_collided){
                case 11://south wall
                    e_data->tile_collision = MOVEMENT_DIAGONAL_SENW;
                break;
                case 9://east wall
                break;
                case 19://west
                    e_data->tile_collision = MOVEMENT_DIAGONAL_NWSE;
                break;
                default://up
                break;
            }
        }break;
        case MOVEMENT_DIAGONAL_SWNE:{
            switch(arg_tile_collided){
                case 11://south wall
                break;
                case 9://east wall
                    e_data->tile_collision = MOVEMENT_DIAGONAL_SENW;
                break;
                case 19://west
                break;
                default://up
                    e_data->tile_collision = MOVEMENT_DIAGONAL_NWSE;
                break;
            }
        }break;
    }
    e_data->e_configured = 1;
}

void DESTROY() {
}