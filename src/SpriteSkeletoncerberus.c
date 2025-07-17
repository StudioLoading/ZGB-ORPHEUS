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

const UINT8 a_skeletoncerberus_hidden[] = {1, 0};
const UINT8 a_skeletoncerberus_up[] = {2, 1, 2};
const UINT8 a_skeletoncerberus_down[] = {2, 1,2};
const UINT8 a_skeletoncerberus_h[] = {2, 1,2};
const UINT8 a_skeletoncerberus_repelled[] = {4, 0,1,0,2};
const UINT8 a_skeletoncerberus_river[] = {1, 3};

UINT8 is_skeletoncerberus_in_river = 0u;
UINT8 skeletoncerberus_floating = 0u;
UINT8 skeletoncerberus_frmskip = 0u;
UINT8 is_skeletoncerberus_taken = 0u;

extern MACROMAP current_map;
extern UINT8 river_verse;

extern void e_start(struct EnemyInfo* e_data, SPRITE_STATES new_state) BANKED;
extern void e_change_state(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void e_management(Sprite* s_enemy) BANKED;
extern void e_check_sprite_collision(Sprite* s_enemy) BANKED;
extern void e_destroy(Sprite* s_enemy) BANKED;

void skeletoncerberus_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;


void START(){
    SetSpriteAnim(THIS, a_skeletoncerberus_hidden, 6);
    struct EnemyInfo* e_data = (struct EnemyInfo*) THIS->custom_data;
    e_data->frmskip = 8u;
    e_start(e_data, IDLE_DOWN);
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
    e_change_state(THIS, WALK_DOWN);
    is_skeletoncerberus_in_river = 0u;
    skeletoncerberus_floating = 0u;
    skeletoncerberus_frmskip = 0u;
    is_skeletoncerberus_taken = 0u;
}

void UPDATE(){
    struct EnemyInfo* e_data = (struct EnemyInfo*) THIS->custom_data;
    if(e_data->e_configured == 0){
        return;
    }
    if(is_skeletoncerberus_in_river == 0){
        e_management(THIS);
        e_check_sprite_collision(THIS);
    }else if(is_skeletoncerberus_taken == 2){return;}
    
    UINT8 tile = GetScrollTile((THIS->x + 8) >> 3, (THIS->y+8) >> 3);
    if(tile == 0){
        tile = GetScrollTile((THIS->x + 8) >> 3, (THIS->y+14) >> 3);
    }
    if(tile >= 106u && tile <= 109u){//into the river!
        if(is_skeletoncerberus_in_river == 0){
            is_skeletoncerberus_in_river = 1u;
        }
        SetSpriteAnim(THIS, a_skeletoncerberus_river, 1u);
    }
    if(is_skeletoncerberus_in_river == 1){
        skeletoncerberus_floating++;
        if(skeletoncerberus_floating == 16){
            THIS->y--;
        }
        if(skeletoncerberus_floating == 31){
            THIS->y++;
            skeletoncerberus_floating = 0u;
        }
        skeletoncerberus_frmskip++;
        if(tile != 9u && tile != 19u){
            if(skeletoncerberus_frmskip == 2){
                skeletoncerberus_frmskip = 0;
                if(river_verse == 0){//to the left
                    THIS->x--;
                }else if(river_verse == 1){//to the right
                    THIS->x++;
                }
            }
        }else{
            e_change_state(THIS, DIE);
        }
    }
}

void skeletoncerberus_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED{
    switch(new_state){
        case IDLE_UP: case WALK_UP: 
            SetSpriteAnim(s_enemy, a_skeletoncerberus_up, 6);
        break;
        case IDLE_DOWN: case WALK_DOWN:
            SetSpriteAnim(s_enemy, a_skeletoncerberus_down, 6);
        break;
        case IDLE_LEFT: case WALK_LEFT:
            s_enemy->mirror = V_MIRROR;
            SetSpriteAnim(s_enemy, a_skeletoncerberus_h, 8);
        break;
        case IDLE_RIGHT: case WALK_RIGHT: 
            s_enemy->mirror = NO_MIRROR;
            SetSpriteAnim(s_enemy, a_skeletoncerberus_h, 8);
        break;
        case HIT:
            SetSpriteAnim(s_enemy, a_skeletoncerberus_repelled, 12);
        break;
    }
    if(current_map == BOSS_CERBERUS){
        UINT8 tile = GetScrollTile((THIS->x + 8) >> 3, (THIS->y+8) >> 3);
        if(tile == 0){
            tile = GetScrollTile((THIS->x + 8) >> 3, (THIS->y+14) >> 3);
        }
        if(tile >= 106u && tile <= 109u){//into the river!
            SetSpriteAnim(THIS, a_skeletoncerberus_river, 1u);
        }
    }
}

void DESTROY(){
    e_destroy(THIS);
}