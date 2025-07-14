#include "Banks/SetAutoBank.h"

#include "SGB.h"
#include "BankManager.h"
#include "ZGBMain.h"
#include "Keys.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

const UINT8 a_revenant_hidden[] = {1, 0};
const UINT8 a_revenant_up[] = {4, 1,2,3,2};
const UINT8 a_revenant_down[] = {4, 1,2,3,2};
const UINT8 a_revenant_h[] = {4, 1,2,3,2};
const UINT8 a_revenant_repelled[] = {2, 0,1};
const UINT8 a_revenant_attack[] = {2, 1,3};

extern void e_start(struct EnemyInfo* e_data, SPRITE_STATES new_state) BANKED;
extern void e_change_state(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void e_management(Sprite* s_enemy) BANKED;
extern void e_check_sprite_collision(Sprite* s_enemy) BANKED;
extern void e_destroy(Sprite* s_enemy) BANKED;

void revenant_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;


void START(){
    SetSpriteAnim(THIS, a_revenant_hidden, 6);
    struct EnemyInfo* e_data = (struct EnemyInfo*) THIS->custom_data;
    e_data->frmskip = 8u;
    e_start(e_data, IDLE_DOWN);
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
    e_change_state(THIS, IDLE_DOWN);
}

void UPDATE(){
    struct EnemyInfo* e_data = (struct EnemyInfo*) THIS->custom_data;
    if(e_data->e_configured == 0){
        return;
    }
    e_management(THIS);
    if(e_data->e_state == ATTACK){
        e_check_sprite_collision(THIS);
    }
}

void revenant_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED{
    switch(new_state){
        case IDLE_UP: case WALK_UP: 
            SetSpriteAnim(s_enemy, a_revenant_up, 16);
        break;
        case IDLE_DOWN: case WALK_DOWN:
            SetSpriteAnim(s_enemy, a_revenant_down, 16);
        break;
        case IDLE_LEFT: case WALK_LEFT:
            s_enemy->mirror = NO_MIRROR;
            SetSpriteAnim(s_enemy, a_revenant_h, 16);
        break;
        case IDLE_RIGHT: case WALK_RIGHT: 
            s_enemy->mirror = V_MIRROR;
            SetSpriteAnim(s_enemy, a_revenant_h, 16);
        break;
        case HIT:
            SetSpriteAnim(s_enemy, a_revenant_repelled, 16);
        break;
        case ATTACK:
            SetSpriteAnim(s_enemy, a_revenant_attack, 32);
        break;
    }
}

void DESTROY(){
    e_destroy(THIS);
}