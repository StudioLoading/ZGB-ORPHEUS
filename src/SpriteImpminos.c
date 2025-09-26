#include "Banks/SetAutoBank.h"

#include "BankManager.h"
#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

const UINT8 a_impminos_hidden[] = {1, 0};
const UINT8 a_impminos_up[] = {2, 1, 2};
const UINT8 a_impminos_down[] = {2, 3, 4};
const UINT8 a_impminos_h[] = {2, 5, 6};
const UINT8 a_impminos_repelled[] = {4, 1,5,3,6};

Sprite* s_plate = 0;
UINT8 flag_move_up = 0;

extern UINT8 flag_impminos_alive;
extern INT8 boss_hp_current;
extern UINT8 boss_minos_flag_orpheus_on_plate;

extern void e_start(struct EnemyInfo* e_data, SPRITE_STATES new_state) BANKED;
extern void e_change_state(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void e_management(Sprite* s_enemy) BANKED;
extern void e_check_sprite_collision(Sprite* s_enemy) BANKED;
extern void e_destroy(Sprite* s_enemy) BANKED;
extern void orpheus_change_state(Sprite* arg_s_orpheus, SPRITE_STATES arg_new_state) BANKED;
extern void boss_hit() BANKED;
extern void spawn_item(ITEM_TYPE arg_item_type, UINT16 arg_spawnx, UINT16 arg_spawny, UINT8 arg_hp_max) BANKED;

void impminos_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
void impminos_check_sprite_collision(Sprite* s_enemy) BANKED;


void START(){
    SetSpriteAnim(THIS, a_impminos_hidden, 6);
    struct EnemyInfo* e_data = (struct EnemyInfo*) THIS->custom_data;
    e_data->frmskip = 2u;
    if(boss_hp_current < 3){
        e_data->frmskip = 1u;
    }
    e_start(e_data, IDLE_DOWN);
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
    e_change_state(THIS, WALK_DOWN);
    s_plate = 0;
    flag_move_up = 0;
    flag_impminos_alive = 1u;
}

void UPDATE(){
    struct EnemyInfo* e_data = (struct EnemyInfo*) THIS->custom_data;
    if(e_data->e_configured == 0){
        return;
    }
    if(e_data->e_state != FROZEN){
        e_management(THIS);
    }else{
        struct EnemyInfo* plate_data = (struct EnemyInfo*) s_plate->custom_data;
        if(plate_data->e_state == WALK_UP || plate_data->e_state == GENERIC_IDLE){
            if(flag_move_up == 0){
                flag_move_up = 1;
                SetSpriteAnim(THIS, a_impminos_repelled, 24u);
            }
            THIS->x = s_plate->x - 4u;
            THIS->y = s_plate->y - 18u;
        }
        if(flag_move_up && plate_data->wait > 30){
            THIS->y--;
            if(THIS->y < 40u){
                THIS->y--;
            }
        }
        if(THIS->y < 3u){
            struct EnemyInfo* e_data = (struct EnemyInfo*) THIS->custom_data;
            if(e_data->e_state == FROZEN){//being launched by a minos plate
                if(boss_minos_flag_orpheus_on_plate == 1u){
                    THIS->x = ((UINT16) 9 << 3);
                    THIS->y = ((UINT16) 3 << 3);
                    boss_hit();
                    e_change_state(THIS, DIE);
                }
            }
        }
    }
    impminos_check_sprite_collision(THIS);
}

void impminos_check_sprite_collision(Sprite* s_enemy) BANKED{
    UINT8 scroll_e_tile;
    Sprite* iespr;
    SPRITEMANAGER_ITERATE(scroll_e_tile, iespr) {
        if(CheckCollision(s_enemy, iespr)) {
            switch(iespr->type){
                case SpriteOrpheus:
                case SpriteOrpheuslyre:{
                    struct EnemyInfo* e_data = (struct EnemyInfo*) s_enemy->custom_data;
                    if(e_data->e_state != FROZEN){
                        orpheus_change_state(iespr, HIT);
                    }
                }break;
                case SpriteMinosplate:
                    struct EnemyInfo* plate_data = (struct EnemyInfo*) iespr->custom_data;
                    if(plate_data->e_state == GENERIC_WALK){
                        if(plate_data->e_configured == 0u && s_plate == 0){
                            plate_data->e_configured = 2u;
                            THIS->x = iespr->x - 4u;
                            THIS->y = iespr->y - 18u;
                            s_plate = iespr;
                            e_change_state(s_enemy, FROZEN);
                        }
                    }
                break;
            }
        }
    }
}

void impminos_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED{
    switch(new_state){
        case IDLE_UP: case WALK_UP: 
            SetSpriteAnim(s_enemy, a_impminos_up, 10);
        break;
        case IDLE_DOWN: case WALK_DOWN:
            SetSpriteAnim(s_enemy, a_impminos_down, 10);
        break;
        case IDLE_LEFT: case WALK_LEFT:
            s_enemy->mirror = V_MIRROR;
            SetSpriteAnim(s_enemy, a_impminos_h, 10);
        break;
        case IDLE_RIGHT: case WALK_RIGHT: 
            s_enemy->mirror = NO_MIRROR;
            SetSpriteAnim(s_enemy, a_impminos_h, 10);
        break;
        case HIT:
        case FROZEN:
            SetSpriteAnim(s_enemy, a_impminos_repelled, 16);
        break;
    }
}

void DESTROY(){
    flag_impminos_alive = 0;
    spawn_item(HEART, THIS->x, THIS->y, 2);
    e_destroy(THIS);
}