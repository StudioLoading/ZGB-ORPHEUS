#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"


const UINT8 a_stone[] = {1, 0};

INT8 stone_mirroring = 10;
extern UINT8 spawned_ball;
extern PUSHING orpheus_pushing;
extern UINT8 flag_paused;
extern Sprite* s_orpheus;

extern void e_destroy(Sprite* s_enemy) BANKED;
extern void orpheus_change_state(Sprite* arg_s_orpheus, SPRITE_STATES arg_new_state) BANKED;
extern void spawn_item(ITEM_TYPE arg_item_type, UINT16 arg_spawnx, UINT16 arg_spawny, UINT8 arg_hp_max) BANKED;
extern UINT8 is_enemy(UINT8 arg_sprite_type) BANKED;
extern void spawn_death_animation(UINT16 spawnx, UINT16 spawny) BANKED;

void START() {
    THIS->lim_x = 10u;
    THIS->lim_y = 10u;
    SetSpriteAnim(THIS, a_stone, 1u);
    stone_mirroring = 10;    
    struct EnemyInfo* stone_data = (struct EnemyInfo*) THIS->custom_data;
    stone_data->e_state = GENERIC_WALK;
    stone_data->e_configured = 0u;
    stone_data->vx = 0;
    stone_data->vy = 0;
    stone_data->wait = 40u;//cooldown for Orpheus not to be HIT
    spawned_ball = 1u;
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
    if(flag_paused){ return; }
    struct EnemyInfo* stone_data = (struct EnemyInfo*) THIS->custom_data;
    switch(stone_data->e_configured){
        case 0: return; break;
        case 1:{//vx and vy to be set externally
            stone_mirroring--;
            if(stone_data->wait){
                stone_data->wait--;
            }
            if(stone_mirroring <= 0){
                if(THIS->mirror == NO_MIRROR){
                    THIS->mirror = V_MIRROR;
                    SPRITE_SET_PALETTE(THIS,0);
                }else{
                    THIS->mirror = NO_MIRROR;
                    SPRITE_SET_PALETTE(THIS,1);
                }
                stone_mirroring = 10;
            }
            UINT8 t_stone_coll = TranslateSprite(THIS, stone_data->vx << delta_time, stone_data->vy << delta_time);
            if(t_stone_coll){
                stone_data->vx = 0;
                stone_data->vy = 0;
                SPRITE_SET_PALETTE(THIS,1);
                stone_data->e_configured = 2;
                if(orpheus_pushing == PUSH_DOWN || orpheus_pushing == PUSH_UP){
                    if(t_stone_coll){//sguillare lateralmente!
                        stone_data->e_configured = 1;
                        if(s_orpheus->x > THIS->x){//sguillo a sx
                            stone_data->vx = -1;
                        }else{//sguillo a dx
                            stone_data->vx = 1;
                        }
                    }
                }
            }else{
                UINT8 tile = GetScrollTile((THIS->x + 8) >> 3, (THIS->y+8) >> 3);
                if(tile == 66u){//pit! die and spawn heart
                    UINT16 heart_spawnx = THIS->x + 18u;
                    if(stone_data->vx > 0){
                        heart_spawnx = THIS->x - 10u;
                    }
                    spawn_item(HEART, heart_spawnx, THIS->y - 1u, 3);
                    SpriteManagerRemoveSprite(THIS);
                }else if(tile == 84u || tile == 85u || tile == 86u || tile == 87u){
                        stone_data->e_configured = 3;
                        //TRANSFORMS INTO A FIREBALL!
                        Sprite* s_fireball = SpriteManagerAdd(SpriteFireball, THIS->x, THIS->y);
                        struct EnemyInfo* fireball_data = (struct EnemyInfo*) s_fireball->custom_data;
                        fireball_data->vx = stone_data->vx;
                        fireball_data->vy = stone_data->vy;
                        fireball_data->e_configured = 2;
                        SpriteManagerRemoveSprite(THIS);
                }else{
                        //SPRITE COLLISION
                            UINT8 scroll_st_tile;
                            Sprite* istspr;
                            SPRITEMANAGER_ITERATE(scroll_st_tile, istspr) {
                                if(CheckCollision(THIS, istspr)) {
                                    if(istspr->type == SpriteOrpheus && stone_data->wait == 0){
                                        orpheus_change_state(istspr, HIT);
                                    } else if(is_enemy(istspr->type)){
                                        e_destroy(istspr);
                                    }
                                }
                            }
                    }
                }
        }break;
        case 2://stopped, can be rolled away by Orpheus
            switch(orpheus_pushing){
                case PUSH_LEFT: 
                    stone_data->vx = 1;
                    stone_data->vy = 0;
                    stone_data->e_configured = 1;
                    stone_data->wait = 40u;
                break;
                case PUSH_RIGHT: 
                    stone_data->vx = -1;
                    stone_data->vy = 0;
                    stone_data->e_configured = 1;
                    stone_data->wait = 40u;
                break;
                case PUSH_UP: 
                    stone_data->vx = 0;
                    stone_data->vy = -1;
                    stone_data->e_configured = 1;
                    stone_data->wait = 40u;
                break;
                case PUSH_DOWN: 
                    stone_data->vx = 0;
                    stone_data->vy = 1;
                    stone_data->e_configured = 1;
                    stone_data->wait = 40u;
                break;
            }
        break;
    }
}

void DESTROY() {
    struct EnemyInfo* stone_data = (struct EnemyInfo*) THIS->custom_data;
    if(stone_data->e_configured < 3){
        spawned_ball = 0u;
    }
    spawn_death_animation(THIS->x - 4u, THIS->y + 24u);
}