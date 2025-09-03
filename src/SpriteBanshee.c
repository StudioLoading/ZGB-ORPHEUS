#include "Banks/SetAutoBank.h"

#include "BankManager.h"
#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

const UINT8 a_banshee_hidden[] = {1, 0};
const UINT8 a_banshee_up[] = {2, 1,2};
const UINT8 a_banshee_down[] = {2, 3,4};
const UINT8 a_banshee_h[] = {2, 5,6};
const UINT8 a_banshee_repelled[] = {4, 1,5,3,6};

const UINT8 a_banshee_attack[] = {1, 3};

extern void e_start(struct EnemyInfo* e_data, SPRITE_STATES new_state) BANKED;
extern void e_change_state(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void e_management(Sprite* s_enemy) BANKED;
extern void e_check_sprite_collision(Sprite* s_enemy) BANKED;
extern void e_destroy(Sprite* s_enemy) BANKED;

void banshee_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;


void START(){
    SetSpriteAnim(THIS, a_banshee_hidden, 6);
    struct EnemyInfo* e_data = (struct EnemyInfo*) THIS->custom_data;
    e_data->frmskip = 8u;
    e_start(e_data, IDLE_DOWN);
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
    e_change_state(THIS, WALK_DOWN);
}

void UPDATE(){
    struct EnemyInfo* e_data = (struct EnemyInfo*) THIS->custom_data;
    if(e_data->e_configured == 0){
        return;
    }
    e_management(THIS);
    e_check_sprite_collision(THIS);
}

void banshee_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED{
    switch(new_state){
        case IDLE_UP: case WALK_UP: 
            SetSpriteAnim(s_enemy, a_banshee_up, 8);
        break;
        case IDLE_DOWN: case WALK_DOWN:
            SetSpriteAnim(s_enemy, a_banshee_down, 8);
        break;
        case IDLE_LEFT: case WALK_LEFT:
            s_enemy->mirror = V_MIRROR;
            SetSpriteAnim(s_enemy, a_banshee_h, 8);
        break;
        case IDLE_RIGHT: case WALK_RIGHT: 
            s_enemy->mirror = NO_MIRROR;
            SetSpriteAnim(s_enemy, a_banshee_h, 8);
        break;
        case HIT:
            SetSpriteAnim(s_enemy, a_banshee_repelled, 16);
        break;
        case ATTACK:
            SetSpriteAnim(s_enemy, a_banshee_attack, 1);
        break;
    }
}

void DESTROY(){
    e_destroy(THIS);
}