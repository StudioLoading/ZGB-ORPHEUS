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

const UINT8 a_dog_hidden[] = {1, 0};
const UINT8 a_dog_up[] = {4, 5,6,5,6};
const UINT8 a_dog_idle_up[] = {4, 5,5,5,5};
const UINT8 a_dog_down[] = {2, 1,7};
const UINT8 a_dog_idle_down[] = {4, 1,1,1,1};
const UINT8 a_dog_h[] = {3, 4,3,2};
const UINT8 a_dog_idle_h[] = {1, 2};
const UINT8 a_dog_repelled[] = {2, 0,1};
const UINT8 a_dog_preattack_h[] = {8, 8,2,2,8,2,2,2,2};

extern void e_start(struct EnemyInfo* e_data, SPRITE_STATES new_state) BANKED;
extern void e_change_state(Sprite* s_enemy, SPRITE_STATES new_state, UINT8 sprite_type) BANKED;
extern void e_dog_management(Sprite* s_enemy) BANKED;
extern void e_destroy(Sprite* s_enemy, UINT8 e_sprite_type) BANKED;

void dog_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;


void START(){
    SetSpriteAnim(THIS, a_dog_hidden, 6);
    struct EnemyInfo* e_data = (struct EnemyInfo*) THIS->custom_data;
    e_data->frmskip = 1u;
    e_start(e_data, IDLE_DOWN);
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
    e_change_state(THIS, IDLE_RIGHT, THIS->type);
}

void UPDATE(){
    struct EnemyInfo* e_data = (struct EnemyInfo*) THIS->custom_data;
    if(e_data->e_configured == 0){
        return;
    }
    e_dog_management(THIS);
}

void dog_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED{
    switch(new_state){
        case IDLE_UP: 
            SetSpriteAnim(s_enemy, a_dog_idle_up, 4);
        break;
        case WALK_UP: 
            SetSpriteAnim(s_enemy, a_dog_up, 6);
        break;
        case IDLE_DOWN: 
            SetSpriteAnim(s_enemy, a_dog_idle_down, 4);
        break;      
        case WALK_DOWN:
            SetSpriteAnim(s_enemy, a_dog_down, 6);
        break;
        case IDLE_LEFT: 
            s_enemy->mirror = V_MIRROR;
            SetSpriteAnim(s_enemy, a_dog_idle_h, 12);
        break;        
        case WALK_LEFT:
            s_enemy->mirror = V_MIRROR;
            SetSpriteAnim(s_enemy, a_dog_h, 12);
        break;
        case IDLE_RIGHT: 
            s_enemy->mirror = NO_MIRROR;
            SetSpriteAnim(s_enemy, a_dog_idle_h, 12);
        break;
        case WALK_RIGHT: 
            s_enemy->mirror = NO_MIRROR;
            SetSpriteAnim(s_enemy, a_dog_h, 12);
        break;
        case HIT:
            SetSpriteAnim(s_enemy, a_dog_repelled, 12);
        break;
        case PREATTACK_RIGHT:
            s_enemy->mirror = NO_MIRROR;
            SetSpriteAnim(s_enemy, a_dog_preattack_h, 12);
        break;
        case PREATTACK_UP:
            SetSpriteAnim(s_enemy, a_dog_up, 12);
        break;
        case PREATTACK_LEFT:
            s_enemy->mirror = V_MIRROR;
            SetSpriteAnim(s_enemy, a_dog_preattack_h, 12);
        break;
        case PREATTACK_DOWN:
            SetSpriteAnim(s_enemy, a_dog_down, 12);
        break;
    }
}

void DESTROY(){
    e_destroy(THIS, THIS->type);
}