#include "Banks/SetAutoBank.h"

#include "SGB.h"
#include "BankManager.h"
#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

const UINT8 a_radamanthus_hidden[] = {1, 0};
const UINT8 a_radamanthus_up[] = {2, 1, 2};
const UINT8 a_radamanthus_down[] = {4, 3,4,3,5};
const UINT8 a_radamanthus_h[] = {2, 1,2};
const UINT8 a_radamanthus_repelled[] = {6, 0,1,0,3,0,2};

extern INT8 boss_hp_current;
extern INT8 boss_hp_max;
extern Sprite* s_radamanthusshadow;

extern void e_start(struct EnemyInfo* e_data, SPRITE_STATES new_state) BANKED;
extern void e_change_state(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void e_management(Sprite* s_enemy) BANKED;
extern void e_check_sprite_collision(Sprite* s_enemy) BANKED;
extern void e_destroy(Sprite* s_enemy) BANKED;

void radamanthus_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;


void START(){
    SetSpriteAnim(THIS, a_radamanthus_hidden, 6);
    struct EnemyInfo* e_data = (struct EnemyInfo*) THIS->custom_data;
    e_data->frmskip = 1u;
    e_start(e_data, IDLE_DOWN);
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
    boss_hp_max = 3;
    boss_hp_current = 3;
    e_change_state(THIS, WALK_DOWN);
}

void UPDATE(){
    struct EnemyInfo* e_data = (struct EnemyInfo*) THIS->custom_data;
    if(e_data->e_configured == 0){
        return;
    }
    if(boss_hp_current > 0){
        e_management(THIS);
        e_check_sprite_collision(THIS);
    }else{
        SpriteManagerRemoveSprite(THIS);
    }
}

void radamanthus_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED{
    switch(new_state){
        case IDLE_UP: case WALK_UP: 
            SetSpriteAnim(s_enemy, a_radamanthus_up, 12);
        break;
        case IDLE_DOWN: case WALK_DOWN:
            SetSpriteAnim(s_enemy, a_radamanthus_down, 12);
        break;
        case IDLE_LEFT: case WALK_LEFT:
            s_enemy->mirror = V_MIRROR;
            SetSpriteAnim(s_enemy, a_radamanthus_h, 12);
        break;
        case IDLE_RIGHT: case WALK_RIGHT: 
            s_enemy->mirror = NO_MIRROR;
            SetSpriteAnim(s_enemy, a_radamanthus_h, 12);
        break;
        case HIT:
            SetSpriteAnim(s_enemy, a_radamanthus_repelled, 24);
        break;
    }
}

void DESTROY(){
    SpriteManagerRemoveSprite(s_radamanthusshadow);
    e_destroy(THIS);
}