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
#include "Dialog.h"

#define POWER_MAX 40
#define COUNTDOWN_SKIP_ATTRACT 1
#define COUNTDOWN_SKIP_REPELL 2
#define COUNTDOWN_SKIP_SLEEP 4

UINT8 J_INT=J_A;//0x10;
UINT8 J_ATK=J_B;//0x20;

const UINT8 a_orpheus_idleup[] = {1, 5};
const UINT8 a_orpheus_idledown[] = {2, 2, 3};
const UINT8 a_orpheus_idleh[] = {4, 10,10,10,9};
const UINT8 a_orpheus_walk_up[] = {2, 5, 6};
const UINT8 a_orpheus_walk_down[] = {2, 2, 3};
const UINT8 a_orpheus_walk_h[] = {4, 9, 10, 9, 8};
const UINT8 a_orpheus_hit_down[] = {2, 0, 2};
const UINT8 a_orpheus_hit_up[] = {2, 0, 5};
const UINT8 a_orpheus_hit_h[] = {2, 0, 9};

struct OrpheusInfo* orpheus_info;
SPRITE_STATES new_state = 0;
UINT8 orpheus_power_max = 0;
UINT8 orpheus_hp_max = 4u;
INT8 orpheus_hp = 3;
INT8 orpheus_hit_countdown = 0;
INT8 a_walk_counter_x = 0;
INT8 a_walk_counter_y = 0;
UINT8 orpheus_hitted = 0;
INT8 hit_frameskip = 0;
INT8 hit_frameskip_max = 0;
SPRITE_STATES orpheus_state_before = 0;
INT8 push_vx = 0;
INT8 push_vy = 0;
UINT8 orpheus_wait = 0u;
UINT8 orpheus_attack_cooldown = 0u;
INT8 countdown = 0;
UINT8 countdown_step = 0;
INT8 countdown_verso = 0;
INT8 countdown_step_currentmax = 0; //cambia a seconda della canzone suonata
UINT8 colliding_block = 0u;

extern UINT8 redraw_hud;
extern UINT8 move_camera_up;
extern UINT8 move_camera_down;
extern UINT8 move_camera_left;
extern UINT8 move_camera_right;
extern SONG song_selection;
extern UINT8 tutorial_go;
extern UINT8 in_dialog;
extern UINT8 has_lyre;

void orhpeus_change_state(SPRITE_STATES new_state) BANKED;
void orpheus_update_position() BANKED;
void orpheus_hit() BANKED;
void orpheus_recharge() BANKED;
void orpheus_pickup(Sprite* itemsprite) BANKED;
extern void init_write_dialog(UINT8 nlines) BANKED;
extern UINT8 prepare_dialog(WHOSTALKING arg_whostalking) BANKED;
extern void go_to_next_map() BANKED;
extern void go_to_prev_map() BANKED;

extern void e_change_state(Sprite* s_enemy, SPRITE_STATES new_state, UINT8 e_sprite_type) BANKED;

void START() {
    THIS->lim_x = 100;
    THIS->lim_y = 100;
    SetSpriteAnim(THIS, a_orpheus_idleup, 8u);
    orpheus_info = (struct OrpheusInfo*) THIS->custom_data;
    orpheus_info->vx = 0;
    orpheus_info->vy = 0;
    orpheus_info->tile_collision = 0u;
    orpheus_info->ow_state = GENERIC_IDLE;
    orpheus_info->charming = 0;
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
    orpheus_hitted = 0u;
    orpheus_hit_countdown = 0;
    a_walk_counter_x = 0;
    a_walk_counter_y = 0;
    hit_frameskip = 0;
    hit_frameskip_max = 0;
    orpheus_wait = 0u;
	countdown_step = COUNTDOWN_SKIP_ATTRACT;
    orpheus_power_max = POWER_MAX;
	countdown = orpheus_power_max;
    countdown_verso = 0;
    orhpeus_change_state(IDLE_DOWN);
}

void UPDATE() {
    colliding_block = 0u;
    //CAMERA MOVEMENT ON CHANGING MAP
        if(a_walk_counter_y < 0){
            a_walk_counter_y++;
            orhpeus_change_state(WALK_UP);
            if(a_walk_counter_y == 0){
                orhpeus_change_state(IDLE_UP);    
            }
            orpheus_update_position();
            return;
        }else if(a_walk_counter_y > 0){
            a_walk_counter_y--;
            orhpeus_change_state(WALK_DOWN);
            if(a_walk_counter_y == 0){
                orhpeus_change_state(IDLE_DOWN);    
            }
            orpheus_update_position();
            return;
        }else if(a_walk_counter_x < 0){
            a_walk_counter_x++;
            orhpeus_change_state(WALK_LEFT);
            if(a_walk_counter_x == 0){
                orhpeus_change_state(IDLE_LEFT);    
            }
            orpheus_update_position();
            return;
        }else if(a_walk_counter_x > 0){
            a_walk_counter_x--;
            orhpeus_change_state(WALK_RIGHT);
            if(a_walk_counter_x == 0){
                orhpeus_change_state(IDLE_RIGHT);    
            }
            orpheus_update_position();
            return;
        }
        if(move_camera_up || move_camera_down  
            || move_camera_left || move_camera_right){
                return;
        }
    //MOVEMENTS
        if(in_dialog == 1){
            switch(orpheus_info->ow_state){
                case WALK_UP: orhpeus_change_state(IDLE_UP); break;
                case WALK_DOWN: orhpeus_change_state(IDLE_DOWN); break;
                case WALK_LEFT: orhpeus_change_state(IDLE_LEFT); break;
                case WALK_RIGHT: orhpeus_change_state(IDLE_RIGHT); break;
            }
        }
        if(tutorial_go == 0 || in_dialog){ return;}
        new_state = orpheus_info->ow_state;
        if((orpheus_info->ow_state != HIT || orpheus_hit_countdown < 10) && orpheus_info->ow_state != ATTACK){
            if(KEY_PRESSED(J_DOWN)){new_state = WALK_DOWN;}
            else if(KEY_PRESSED(J_UP)){new_state = WALK_UP;}
            else if(KEY_PRESSED(J_LEFT)){new_state = WALK_LEFT;}
            else if(KEY_PRESSED(J_RIGHT)){new_state = WALK_RIGHT;}
            else if(KEY_RELEASED(J_DOWN)){new_state = IDLE_DOWN;}
            else if(KEY_RELEASED(J_UP)){new_state = IDLE_UP;}
            else if(KEY_RELEASED(J_LEFT)){new_state = IDLE_LEFT;}
            else if(KEY_RELEASED(J_RIGHT)){new_state = IDLE_RIGHT;}
        }
    //ATTACK MANAGEMENT J_ATK
        if(orpheus_info->ow_state != HIT && orpheus_info->ow_state != ATTACK){
			if (KEY_TICKED(J_ATK)) { //countdown == orpheus_power_max && ){
                if(has_lyre){
                    orpheus_state_before = orpheus_info->ow_state;
                    new_state = ATTACK;
                }else{
			        init_write_dialog(prepare_dialog(MISSING_LYRE));
                }
			}
        }
    orhpeus_change_state(new_state);
    //BEHAVE
        switch(new_state){
            case IDLE_DOWN: case IDLE_LEFT: case IDLE_RIGHT: case IDLE_UP:
                orpheus_recharge();
            break;
            case WALK_DOWN: case WALK_UP:
            case WALK_LEFT: case WALK_RIGHT:
                orpheus_update_position();
            break;
            case HIT:
                hit_frameskip--;
                if(hit_frameskip == 0){
                    hit_frameskip_max++;
                    hit_frameskip = hit_frameskip_max;
                    if(push_vx != 0 || push_vy != 0){
                        orpheus_info->vx = push_vx;
                        orpheus_info->vy = push_vy;
                    }else{
                        switch(orpheus_state_before){
                            case WALK_DOWN: case IDLE_DOWN:
                                orpheus_info->vy = -1;
                                orpheus_info->vx = 0;
                            break;
                            case WALK_UP: case IDLE_UP:
                                orpheus_info->vy = 1;
                                orpheus_info->vx = 0;
                            break;
                            case WALK_LEFT: case IDLE_LEFT:
                                orpheus_info->vy = 0;
                                orpheus_info->vx = 1;
                            break;
                            case WALK_RIGHT: case IDLE_RIGHT:
                                orpheus_info->vy = 0;
                                orpheus_info->vx = -1;
                            break;
                        }
                    }
                    orpheus_update_position();
                }
                if(orpheus_hit_countdown > 0){//going backwards
                    orpheus_hit_countdown--;
                }else if(orpheus_hit_countdown <= 0){//hit effect ends
                    // || orpheus_hitted != 0){
                    orpheus_hit_countdown = 0;
                    orpheus_hitted = 0u;
                    push_vx = 0;
                    push_vy = 0;
                    switch(orpheus_state_before){
                        case WALK_DOWN: case IDLE_DOWN:
                            orhpeus_change_state(IDLE_DOWN);
                        break;
                        case WALK_UP: case IDLE_UP: case GENERIC_IDLE: case GENERIC_WALK:
                            orhpeus_change_state(IDLE_UP);
                        break;
                        case WALK_LEFT: case IDLE_LEFT:
                            orhpeus_change_state(IDLE_LEFT);
                        break;
                        case WALK_RIGHT: case IDLE_RIGHT:
                            orhpeus_change_state(IDLE_RIGHT);
                        break;
                    }
                }
            break;
            case ATTACK:
                orpheus_wait--;
                if(orpheus_wait <= 1){
                    orhpeus_change_state(orpheus_state_before);
                    return;
                }
            break;
        }
    //SPRITE COLLISION
        UINT8 scroll_o_tile;
        Sprite* iospr;
        SPRITEMANAGER_ITERATE(scroll_o_tile, iospr) {
            if(orpheus_info->ow_state == ATTACK){
                switch(iospr->type){
                    case SpriteSkeleton:
                        e_change_state(iospr, HIT, iospr->type);
                    break;
                }
            }
            if(CheckCollision(THIS, iospr)) {
                switch(iospr->type){
                    case SpriteLyre:
                    case SpriteItem:
                        orpheus_pickup(iospr);
                    break;
                    case SpriteSkeleton:
                        if(orpheus_info->ow_state != HIT){
                            struct EnemyInfo* e_data = (struct EnemyInfo*) iospr->custom_data;
                            if(e_data->vx != orpheus_info->vx && orpheus_info->vy == 0){
                                push_vx = e_data->vx;
                            }
                            if(e_data->vy != orpheus_info->vy && orpheus_info->vx == 0){
                                push_vy = e_data->vy;
                            }
                            orhpeus_change_state(HIT);
                        }
                    break;
                    case SpriteBlock:{
                        if(has_lyre == 0 && KEY_PRESSED(J_INT)){
                            init_write_dialog(prepare_dialog(MISSING_LYRE_FEEL_WEAK));
                            return;
                        }
                        INT8 deltax = THIS->x - iospr->x;
                        INT8 deltay = THIS->y - iospr->y;
                        struct ItemInfo* block_data = (struct ItemInfo*) iospr->custom_data;
                        if(THIS->x > iospr->x && orpheus_info->ow_state == WALK_LEFT){
                            block_data->counter_verso = -1;                            
                            if(KEY_PRESSED(J_INT)){
                                block_data->counter_x++;
                            }else if(KEY_RELEASED(J_INT)){
                                block_data->counter_x = 0;
                                block_data->counter_y = 0;
                            }
                            if(orpheus_info->vx < 0 && deltay > -14 && deltay < 8){
                                THIS->x++;
                                colliding_block = 1u;
                            }
                        }else if(THIS->x < iospr->x && orpheus_info->ow_state == WALK_RIGHT){
                            block_data->counter_verso = 1;
                            if(KEY_PRESSED(J_INT)){
                                block_data->counter_x++;
                            }else if(KEY_RELEASED(J_INT)){
                                block_data->counter_x = 0;
                                block_data->counter_y = 0;
                            }
                            if(orpheus_info->vx > 0 && deltay > -14 && deltay < 8){
                                THIS->x--;
                                colliding_block = 1u;
                            }   
                        }
                        if(THIS->y < iospr->y && orpheus_info->ow_state == WALK_DOWN){
                            block_data->counter_verso = 1;
                            if(KEY_PRESSED(J_INT)){
                                block_data->counter_y++;
                            }else if(KEY_RELEASED(J_INT)){
                                block_data->counter_x = 0;
                                block_data->counter_y = 0;
                            }
                            if(orpheus_info->vy > 0 && deltax > -8 && deltax < 16){
                                THIS->y--;
                                colliding_block = 1u;
                            }
                        }else if(THIS->y > iospr->y && orpheus_info->ow_state == WALK_UP){
                            block_data->counter_verso = -1;
                            if(KEY_PRESSED(J_INT)){
                                block_data->counter_y++;
                            }else if(KEY_RELEASED(J_INT)){
                                block_data->counter_x = 0;
                                block_data->counter_y = 0;
                            }
                            if(orpheus_info->vy < 0 && deltay > 6){
                                THIS->y++;
                                colliding_block = 1u;
                            }
                        }
                    }break;                    
                }
            }
        }
}

void orpheus_recharge() BANKED{
	if(countdown_verso != 0){
		countdown_step--;
		if(countdown_step == 0){
            countdown_step = countdown_step_currentmax;
			countdown += countdown_verso;
			if(countdown == orpheus_power_max){//RICHARGE COMPLETA
				orpheus_info->charming = -1;
                countdown_verso = 0;
                orpheus_info->charming = 0;
			}
			redraw_hud = 1;
		}
	}
}

void orpheus_update_position() BANKED{
    if(colliding_block == 1){
        orpheus_info->vx = 0;
        orpheus_info->vy = 0;
    }
    orpheus_info->tile_collision = TranslateSprite(THIS, orpheus_info->vx << delta_time, orpheus_info->vy << delta_time);
    if(orpheus_info->tile_collision){
        //CHECK COLLISION WITH DAMAGE TILES
        switch(current_state){
            case StateLevel00:
                switch(orpheus_info->tile_collision){
                    case 38u: //spini
                        orhpeus_change_state(HIT);
                    break;
                    case 11u:
                    case 12u:
                        go_to_next_map();
                    break;
                }
            break;
            case StateLevel01:
                switch(orpheus_info->tile_collision){
                    case 72u:
                    case 73u:
                        go_to_prev_map();
                    break;
                }
            break;
        }
    }
}

void orhpeus_change_state(SPRITE_STATES new_state) BANKED{
    if(orpheus_info->ow_state == new_state){
        return;
    };
    switch(new_state){
        case IDLE_DOWN:
            orpheus_info->vy = 0;
            orpheus_info->vx = 0;
            SetSpriteAnim(THIS, a_orpheus_idledown, 4u);
        break;
        case IDLE_UP:
            orpheus_info->vy = 0;
            orpheus_info->vx = 0;
            SetSpriteAnim(THIS, a_orpheus_idleup, 4u);
        break;
        case IDLE_LEFT:
            orpheus_info->vy = 0;
            orpheus_info->vx = 0;
            SetSpriteAnim(THIS, a_orpheus_idleh, 4u);
            THIS->mirror = V_MIRROR;
        break;
        case IDLE_RIGHT:
            orpheus_info->vx = 0;
            orpheus_info->vy = 0;
            SetSpriteAnim(THIS, a_orpheus_idleh, 4u);
            THIS->mirror = NO_MIRROR;
        break;
        case WALK_DOWN:
            orpheus_info->vx = 0;
            orpheus_info->vy = 1;
            SetSpriteAnim(THIS, a_orpheus_walk_down, 12u);
        break;
        case WALK_UP:
            orpheus_info->vx = 0;
            orpheus_info->vy = -1;
            SetSpriteAnim(THIS, a_orpheus_walk_up, 8u);
        break;
        case WALK_LEFT:
            orpheus_info->vx = -1;
            orpheus_info->vy = 0;
            SetSpriteAnim(THIS, a_orpheus_walk_h, 12u);
            THIS->mirror = V_MIRROR;
        break;
        case WALK_RIGHT:
            orpheus_info->vx = 1;
            orpheus_info->vy = 0;
            SetSpriteAnim(THIS, a_orpheus_walk_h, 12u);
            THIS->mirror = NO_MIRROR;
        break;
        case HIT:
            hit_frameskip_max = 1;
            hit_frameskip = 1;
            switch(orpheus_info->ow_state){
                case WALK_DOWN:
                case IDLE_DOWN:
                    SetSpriteAnim(THIS, a_orpheus_hit_down, 24u);
                break;
                case WALK_UP:
                case IDLE_UP:
                    SetSpriteAnim(THIS, a_orpheus_hit_up, 24u);
                break;
                case WALK_LEFT: case WALK_RIGHT:
                case IDLE_LEFT: case IDLE_RIGHT:
                    SetSpriteAnim(THIS, a_orpheus_hit_h, 24u);
                break;
            }
            orpheus_state_before = orpheus_info->ow_state;
            orpheus_hit();
        break;
        case ATTACK:
            countdown = 0;
            countdown_verso = 1;
            redraw_hud = 1;
            orpheus_info->charming = 1;
            switch(song_selection){
                case ATTRACT://charm
                    countdown_step_currentmax = COUNTDOWN_SKIP_ATTRACT;
                    orpheus_wait = 20u;
                    orpheus_attack_cooldown = 120u;
                break;
                case REPEL://repell
                    countdown_step_currentmax = COUNTDOWN_SKIP_REPELL;
                    orpheus_wait = 20u;
                    orpheus_attack_cooldown = 120u;
                break;
                case SLEEP://attract
                    countdown_step_currentmax = COUNTDOWN_SKIP_SLEEP;
                    orpheus_wait = 30u;
                    orpheus_attack_cooldown = 200u;
                break;
            }
            countdown_step = countdown_step_currentmax;
        break;
    }
    orpheus_info->ow_state = new_state;
}

void orpheus_hit() BANKED{
    if(orpheus_hitted == 0u){
        orpheus_hp--;
        orpheus_hit_countdown = 32;
        orpheus_hitted = 1u;
        redraw_hud = 1;
    }
}

void orpheus_pickup(Sprite* itemsprite) BANKED{
    switch(itemsprite->type){
        case SpriteLyre:
            if(KEY_TICKED(J_INT)){
                has_lyre = 1u;
                init_write_dialog(prepare_dialog(FOUND_LYRE));
                SpriteManagerRemoveSprite(itemsprite);
                orhpeus_change_state(IDLE_DOWN);
            }
            if(KEY_TICKED(J_ATK)){
                init_write_dialog(prepare_dialog(PRESS_INTERACT));
            }
        break;
        case SpriteItem:
            struct ItemInfo* i_data = (struct ItemInfo*) itemsprite->custom_data;
            if(i_data->i_configured == 2){
                switch(i_data->item_type){
                    case HEART:
                        if(orpheus_hp < orpheus_hp_max){
                            orpheus_hp++;
                            redraw_hud = 1;
                        }
                        SpriteManagerRemoveSprite(itemsprite);
                    break;
                }
            }
        break;
    }
}

void DESTROY() {
}