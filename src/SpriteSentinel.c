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

const UINT8 a_sentinel_hidden[] = {1, 0};
const UINT8 a_sentinel_up[] = {2, 1, 2};
const UINT8 a_sentinel_down[] = {2, 3, 4};
const UINT8 a_sentinel_h[] = {2, 5, 6};
const UINT8 a_sentinel_idle_up[] = {1, 1};
const UINT8 a_sentinel_idle_down[] = {1, 3};
const UINT8 a_sentinel_idle_h[] = {1, 5};
const UINT8 a_sentinel_repelled[] = {4, 1,5,3,6};

extern void e_start(struct EnemyInfo* e_data, SPRITE_STATES new_state) BANKED;
extern void e_change_state(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void e_management(Sprite* s_enemy) BANKED;
extern void e_check_sprite_collision(Sprite* s_enemy) BANKED;
extern void e_destroy(Sprite* s_enemy) BANKED;
extern void e_dog_management(Sprite* s_enemy) BANKED;

void sentinel_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;


void START(){
    SetSpriteAnim(THIS, a_sentinel_hidden, 6);
    struct EnemyInfo* e_data = (struct EnemyInfo*) THIS->custom_data;
    e_data->frmskip = 1u;
    e_data->wait = 0;
    e_start(e_data, WALK_DOWN);
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
    e_dog_management(THIS);
    e_check_sprite_collision(THIS);
}

void sentinel_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED{
     switch(new_state){
        case IDLE_UP: 
            SetSpriteAnim(s_enemy, a_sentinel_idle_up, 4);
        break;
        case WALK_UP: 
            SetSpriteAnim(s_enemy, a_sentinel_up, 6);
        break;
        case IDLE_DOWN: 
            SetSpriteAnim(s_enemy, a_sentinel_idle_down, 4);
        break;      
        case WALK_DOWN:
            SetSpriteAnim(s_enemy, a_sentinel_down, 6);
        break;
        case IDLE_LEFT: 
            s_enemy->mirror = V_MIRROR;
            SetSpriteAnim(s_enemy, a_sentinel_idle_h, 12);
        break;        
        case WALK_LEFT:
            s_enemy->mirror = V_MIRROR;
            SetSpriteAnim(s_enemy, a_sentinel_h, 12);
        break;
        case IDLE_RIGHT: 
            s_enemy->mirror = NO_MIRROR;
            SetSpriteAnim(s_enemy, a_sentinel_idle_h, 12);
        break;
        case WALK_RIGHT: 
            s_enemy->mirror = NO_MIRROR;
            SetSpriteAnim(s_enemy, a_sentinel_h, 12);
        break;
        case HIT:
            SetSpriteAnim(s_enemy, a_sentinel_repelled, 12);
        break;
        case PREATTACK_RIGHT:
            s_enemy->mirror = NO_MIRROR;
            SetSpriteAnim(s_enemy, a_sentinel_h, 12);
        break;
        case PREATTACK_UP:
            SetSpriteAnim(s_enemy, a_sentinel_up, 12);
        break;
        case PREATTACK_LEFT:
            s_enemy->mirror = V_MIRROR;
            SetSpriteAnim(s_enemy, a_sentinel_h, 12);
        break;
        case PREATTACK_DOWN:
            SetSpriteAnim(s_enemy, a_sentinel_down, 12);
        break;
    }
}

void DESTROY(){
    e_destroy(THIS);
}