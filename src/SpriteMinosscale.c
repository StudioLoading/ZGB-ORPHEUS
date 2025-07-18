#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

#define FRMSKIP_MAX 8<<3
#define PLATEPOSX_10 8<<3
#define PLATEPOSY_10 8<<3
#define PLATEPOSX_11 8<<3
#define PLATEPOSY_11 14<<3
#define PLATEPOSX_20 14<<3
#define PLATEPOSY_20 9<<3
#define PLATEPOSX_21 8<<3
#define PLATEPOSY_21 9<<3
#define PLATEPOSX_30 14<<3
#define PLATEPOSY_30 12<<3
#define PLATEPOSX_31 8<<3
#define PLATEPOSY_31 12<<3

const UINT8 a_minosscale_hidden[] = {1, 0};
const UINT8 a_minosscale_idle[] = {1, 1};
const UINT8 a_minosscale_rotating[] = {8, 1,2,3,2,1,2,3,2};
const UINT8 a_minosscale_preattack[] = {2, 0,1};

UINT16 minosscale_init_posx = 0u;
UINT16 minosscale_init_posy = 0u;
UINT8 platepos_counter = 0u;

extern UINT8 boss_breath_flag;
extern INT8 boss_breath_verse;
extern UINT8 boss_breath_flag_right;
extern INT8 boss_breath_verse_right;
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
void minosscale_change_state(Sprite* arg_s_cerberus, SPRITE_STATES arg_new_state) BANKED;
void minos_scale_rotation(Sprite* arg_s_minosscale) BANKED;

extern void spawn_death_animation(UINT16 spawnx, UINT16 spawny) BANKED;

void START() {
    THIS->lim_x = 1000u;
    THIS->lim_y = 1000u;
    SetSpriteAnim(THIS, a_minosscale_idle, 24u);
    struct EnemyInfo* minosscale_data = (struct EnemyInfo*) THIS->custom_data;
    minosscale_data->e_state = GENERIC_IDLE;
    minosscale_data->frmskip = FRMSKIP_MAX;
    minosscale_data->frmskip_wait = 0;
    minosscale_init_posx = THIS->x;
    minosscale_init_posy = THIS->y;
    platepos_counter = 1u;
}

void UPDATE() {
    struct EnemyInfo* minosscale_data = (struct EnemyInfo*) THIS->custom_data;
    switch(minosscale_data->e_state){
        case GENERIC_IDLE:
            if(boss_breath_flag){
                THIS->y += boss_breath_verse;
                boss_breath_flag = 0;
            }
            minosscale_data->frmskip_wait++;
            if(minosscale_data->frmskip_wait == minosscale_data->frmskip){
                minosscale_data->frmskip_wait = 0;
            }
            minosscale_data->wait--;
            if(minosscale_data->wait == 0){
                minosscale_change_state(THIS, GENERIC_WALK);
            }
        break;
        case GENERIC_WALK:
            minosscale_data->wait--;
            minos_scale_rotation(THIS);
            if(minosscale_data->wait < 40u){
                THIS->anim_speed = 16u;
            }else if(minosscale_data->wait < 20u){
                THIS->anim_speed = 8u;
            }
            if(minosscale_data->wait == 0){
                minosscale_change_state(THIS, WALK_UP);
            }
        break;
        case WALK_UP:
            minosscale_data->frmskip_wait++;
            if(minosscale_data->frmskip_wait == minosscale_data->frmskip){
                minosscale_data->frmskip_wait = 0;
                THIS->y--;
            }
            minosscale_data->wait--;
            if(minosscale_data->wait == 0){
                THIS->x = minosscale_init_posx;
                THIS->y = minosscale_init_posy;
                minosscale_change_state(THIS, ATTACK);
            }
        break;
        case ATTACK:
            //do nothing, just wait for the plates to disappear
        break;
    }
}

void minosscale_change_state(Sprite* arg_s_minosscale, SPRITE_STATES arg_new_state) BANKED{
    struct EnemyInfo* scale_info = (struct EnemyInfo*)arg_s_minosscale->custom_data;
    switch(arg_new_state){
        case GENERIC_IDLE:
            THIS->x = minosscale_init_posx;
            THIS->y = minosscale_init_posy;
        break;
        case GENERIC_WALK:
            scale_info->wait = 100u;
            SetSpriteAnim(arg_s_minosscale, a_minosscale_rotating, 40u);
        break;
        case WALK_UP:
            scale_info->wait = 100u;
            arg_s_minosscale->y += 4u;
            SetSpriteAnim(arg_s_minosscale, a_minosscale_preattack, 40u);
        break;
        case ATTACK:
            SetSpriteAnim(arg_s_minosscale, a_minosscale_idle, 1u);
            scale_info->wait = 200u;
            arg_s_minosscale->y += 6u;
            spawn_death_animation(arg_s_minosscale->x, arg_s_minosscale->y + 24u);
            minosscale_spawn_plates();
        break;
    }   
    scale_info->e_state = arg_new_state;
}

void minosscale_spawn_plates() BANKED{
    switch(platepos_counter){
        case 1u:
            SpriteManagerAdd(SpriteMinosplate, PLATEPOSX_10, PLATEPOSY_10);
            SpriteManagerAdd(SpriteMinosplate, PLATEPOSX_11, PLATEPOSY_11);
        break;
        case 2u:
            SpriteManagerAdd(SpriteMinosplate, PLATEPOSX_20, PLATEPOSY_20);
            SpriteManagerAdd(SpriteMinosplate, PLATEPOSX_21, PLATEPOSY_21);
        break;
        case 3u:
            SpriteManagerAdd(SpriteMinosplate, PLATEPOSX_30, PLATEPOSY_30);
            SpriteManagerAdd(SpriteMinosplate, PLATEPOSX_31, PLATEPOSY_31);
        break;
        default:
            platepos_counter = 0u;
        break;
    }
    platepos_counter++;
}

void minos_scale_rotation(Sprite* arg_s_minosscale) BANKED{
    switch(arg_s_minosscale->anim_frame){
        case 0u:
        case 1u:
        case 2u:
            arg_s_minosscale->mirror = NO_MIRROR;
        break;
        case 3u:
        case 4u:
            arg_s_minosscale->mirror = H_MIRROR;
        break;
        case 5u:
            arg_s_minosscale->mirror = HV_MIRROR;
        break;
        case 6u:
        case 7u:
            arg_s_minosscale->mirror = V_MIRROR;
        break;

    }
}

void DESTROY() {
}