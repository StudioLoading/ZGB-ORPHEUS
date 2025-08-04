#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"


const UINT8 a_radamanthusbrick[] = {1, 1};
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
*/

extern Sprite* s_orpheus;
extern Sprite* s_radamanthusshadow;
extern UINT8 flag_camera_shake_h;

extern void spawn_death_animation(UINT16 spawnx, UINT16 spawny) BANKED;
extern void boss_hit() BANKED;
extern void orpheus_change_state(Sprite* arg_s_orpheus, SPRITE_STATES arg_new_state) BANKED;

void START() {
    SetSpriteAnim(THIS, a_radamanthusbrick, 1u);
    struct EnemyInfo* brick_data = (struct EnemyInfo*) THIS->custom_data;
    brick_data->vx = 0;
    brick_data->vy = 2;
    brick_data->frmskip_wait = 0;
    brick_data->frmskip = 0;
    brick_data->e_configured = 1;
}

void UPDATE() {
    struct EnemyInfo* brick_data = (struct EnemyInfo*) THIS->custom_data;
    brick_data->frmskip_wait++;
    if(brick_data->frmskip_wait > brick_data->frmskip){
        brick_data->frmskip_wait = 0;
        brick_data->tile_collision = TranslateSprite(THIS, brick_data->vx << delta_time, brick_data->vy << delta_time);
        if(brick_data->tile_collision){
            THIS->x += brick_data->vx;
            THIS->y += brick_data->vy;
        }
    }
    UINT8 scroll_brick_tile;
    Sprite* ibrickspr;
    SPRITEMANAGER_ITERATE(scroll_brick_tile, ibrickspr) {
        if(CheckCollision(THIS, ibrickspr)) {
            switch(ibrickspr->type){
                case SpriteOrpheus:
                case SpriteOrpheuslyre:
                    if((s_radamanthusshadow->y - THIS->y) < 16){
                        orpheus_change_state(s_orpheus, HIT);
                    }
                break;
                case SpriteRadamanthus:
                    if((s_radamanthusshadow->y - THIS->y) < 16){
                        boss_hit();
                        flag_camera_shake_h = 1u;
                        SpriteManagerRemoveSprite(THIS);
                    }
                break;
                case SpriteRadamanthusshadow:
                    SpriteManagerRemoveSprite(THIS);                 
                break;
            }
        }
    }
}

void DESTROY() {
    spawn_death_animation(THIS->x + 4u, THIS->y + 8u);
}