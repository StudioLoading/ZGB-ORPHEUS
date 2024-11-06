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

const UINT8 a_skeleton_hidden[] = {1, 0};
const UINT8 a_skeleton_up[] = {2, 1, 2};
const UINT8 a_skeleton_down[] = {2, 3, 4};
const UINT8 a_skeleton_h[] = {2, 5, 6};
const UINT8 a_skeleton_repelled[] = {4, 1,5,3,6};

extern void e_start(struct EnemyInfo* e_data, SPRITE_STATES new_state) BANKED;
extern void e_change_state(Sprite* s_enemy, SPRITE_STATES new_state, UINT8 sprite_type) BANKED;
extern void e_update_anim(struct EnemyInfo* e_data, UINT8 sprite_type) BANKED;
extern void e_management(Sprite* s_enemy) BANKED;
extern void e_destroy(Sprite* s_enemy, UINT8 e_sprite_type) BANKED;

void skeleton_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;


void START(){
    SetSpriteAnim(THIS, a_skeleton_hidden, 6);
    struct EnemyInfo* e_data = (struct EnemyInfo*) THIS->custom_data;
    e_data->frmskip = 16u;
    e_start(e_data, IDLE_DOWN);
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
    e_change_state(THIS, WALK_DOWN, THIS->type);
}

void UPDATE(){
    struct EnemyInfo* e_data = (struct EnemyInfo*) THIS->custom_data;
    if(e_data->e_configured == 0){
        return;
    }
    e_management(THIS);
}

void skeleton_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED{
    switch(new_state){
        case IDLE_UP: case WALK_UP: 
            SetSpriteAnim(s_enemy, a_skeleton_up, 6);
        break;
        case IDLE_DOWN: case WALK_DOWN:
            SetSpriteAnim(s_enemy, a_skeleton_down, 6);
        break;
        case IDLE_LEFT: case WALK_LEFT:
            s_enemy->mirror = V_MIRROR;
            SetSpriteAnim(s_enemy, a_skeleton_h, 8);
        break;
        case IDLE_RIGHT: case WALK_RIGHT: 
            s_enemy->mirror = NO_MIRROR;
            SetSpriteAnim(s_enemy, a_skeleton_h, 8);
        break;
        case HIT:
            SetSpriteAnim(s_enemy, a_skeleton_repelled, 12);
        break;
    }
}

void DESTROY(){
    e_destroy(THIS, THIS->type);
}