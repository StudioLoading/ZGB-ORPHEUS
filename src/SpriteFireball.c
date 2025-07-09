#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"


const UINT8 a_fireball[] = {1, 1};

INT8 fireball_mirroring = 10;
UINT8 spawned_ball = 0u;

extern void e_destroy(Sprite* s_enemy, UINT8 e_sprite_type) BANKED;
extern void orpheus_change_state(Sprite* arg_s_orpheus, SPRITE_STATES arg_new_state) BANKED;

void START() {
    THIS->lim_x = 10u;
    THIS->lim_y = 10u;
    SetSpriteAnim(THIS, a_fireball, 24u);
    fireball_mirroring = 10;    
    struct EnemyInfo* fireball_data = (struct EnemyInfo*) THIS->custom_data;
    fireball_data->e_state = GENERIC_WALK;
    fireball_data->e_configured = 0u;
    fireball_data->vx = 0;
    fireball_data->vy = 0;
    spawned_ball = 1u;
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
    struct EnemyInfo* fireball_data = (struct EnemyInfo*) THIS->custom_data;
    switch(fireball_data->e_configured){
        case 0: return; break;
        case 2://stone transformed into a fireball!
        case 1:{//vx and vy to be set externally
            fireball_mirroring--;
            if(fireball_mirroring <= 0){
                if(THIS->mirror == NO_MIRROR){
                    THIS->mirror = V_MIRROR;
                    SPRITE_SET_PALETTE(THIS,0);
                }else{
                    THIS->mirror = NO_MIRROR;
                    SPRITE_SET_PALETTE(THIS,1);
                }
                fireball_mirroring = 10;
            }
            UINT8 t_fireball_coll = TranslateSprite(THIS,fireball_data->vx << delta_time, fireball_data->vy << delta_time);
            if(t_fireball_coll){
                THIS->x += fireball_data->vx;
                THIS->y += fireball_data->vy;
            }else{
            //SPRITE COLLISION
                UINT8 scroll_fb_tile;
                Sprite* ifbspr;
                SPRITEMANAGER_ITERATE(scroll_fb_tile, ifbspr) {
                    if(CheckCollision(THIS, ifbspr)) {
                        if(ifbspr->type == SpriteOrpheus){
                            orpheus_change_state(ifbspr, HIT);
                        }else if(ifbspr->type != SpriteFireball && ifbspr->type != SpriteBlade && ifbspr->type != SpriteDeath && ifbspr->type != SpriteOrpheusnote
                        && ifbspr->type != SpriteStone){
                            e_destroy(ifbspr, ifbspr->type);
                        }
                    }
                }
            }
        }break;
    }
}

void DESTROY() {
    spawned_ball = 0u;
}