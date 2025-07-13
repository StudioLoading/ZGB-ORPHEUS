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
#define COUNTDOWN_SKIP_ATTRACT 2
#define COUNTDOWN_SKIP_REPELL 4
#define COUNTDOWN_SKIP_SLEEP 8

UINT8 J_INT=J_A;//0x10;
UINT8 J_ATK=J_B;//0x20;

const UINT8 a_orpheus_idleup[] = {1, 4};
const UINT8 a_orpheus_idledown[] = {2, 2, 3};
const UINT8 a_orpheus_idleh[] = {4, 10,10,10,9};
const UINT8 a_orpheus_walk_up[] = {4, 4,5,4,6};
const UINT8 a_orpheus_walk_down[] = {4, 1,2,1,3};
const UINT8 a_orpheus_walk_down_push[] = {2, 12,13};
const UINT8 a_orpheus_walk_h[] = {4, 9, 10, 9, 8};
const UINT8 a_orpheus_walk_h_push[] = {2, 7,11};
const UINT8 a_orpheus_hit_down[] = {2, 0, 2};
const UINT8 a_orpheus_hit_up[] = {2, 0, 5};
const UINT8 a_orpheus_hit_h[] = {2, 0, 9};
const UINT8 a_orpheus_push[] = {3, 7, 11,11};
const UINT8 a_orpheus_dead[] = {1, 0};
const UINT8 a_orpheus_attack_down[] = {1, 14};

struct OrpheusInfo* orpheus_info;
SPRITE_STATES new_state = 0;
INT8 orpheus_power_max = 0;
INT8 orpheus_hp_max = 4;
INT8 orpheus_hp = 3;
INT8 orpheus_hit_countdown = 0;
INT8 a_walk_counter_x = 0;
INT8 a_walk_counter_y = 0;
UINT8 orpheus_hitted = 0u;
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
INT8 orpheus_starting_up = 0u;
UINT8 inertia_x = 0u;
UINT8 inertia_y = 0u;
UINT16 idle_countdown = 800u;
Sprite* s_lyre = 0;
PUSHING orpheus_pushing = PUSH_NONE;

extern UINT8 redraw_hud;
extern UINT8 move_camera_up;
extern UINT8 move_camera_down;
extern UINT8 move_camera_left;
extern UINT8 move_camera_right;
extern SONG song_selection;
extern UINT8 tutorial_go;
extern UINT8 in_dialog;
extern UINT8 has_lyre;
extern MACROMAP prev_map;
extern MACROMAP current_map;
extern UINT8 orpheus_haskey;
extern MACROMAP solved_map;
extern INT8 restart_current_map;
extern UINT8 show_cartel;
extern UINT8 boss_intro;
extern UINT8 spikes_hit_flag;

void orpheus_behave() BANKED;
void orpheus_change_state(Sprite* arg_s_orpheus, SPRITE_STATES arg_new_state) BANKED;
void orpheus_update_position() BANKED;
void orpheus_hit() BANKED;
void orpheus_recharge() BANKED;
void orpheus_pickup(Sprite* itemsprite) BANKED;
void orpheus_check_tile_overlapping() BANKED;
extern void init_write_dialog(UINT8 nlines) BANKED;
extern UINT8 prepare_dialog(WHOSTALKING arg_whostalking) BANKED;
extern void go_to_next_map() BANKED;
extern void go_to_prev_map() BANKED;
extern void solve_current_map() BANKED;
extern void spawn_death_animation(UINT16 spawnx, UINT16 spawny) BANKED;
extern void e_change_state(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;

void START() {
    THIS->lim_x = 100;
    THIS->lim_y = 100;
    SetSpriteAnim(THIS, a_orpheus_idledown, 8u);
    orpheus_info = (struct OrpheusInfo*) THIS->custom_data;
    orpheus_info->vx = 0;
    orpheus_info->vy = 0;
    orpheus_info->tile_collision = 0u;
    orpheus_info->ow_state = IDLE_DOWN;
    orpheus_info->charming = 0;
    new_state = GENERIC_IDLE;
    orpheus_change_state(THIS, IDLE_DOWN);
    if(tutorial_go == 0 || (current_map == HADES_ZERO && THIS->y > 50u)){
        SetSpriteAnim(THIS, a_orpheus_idleup, 8u);
        orpheus_change_state(THIS, IDLE_UP);
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
    orpheus_starting_up = 20;
    inertia_x = 0u;
    inertia_y = 0u;
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
    if(orpheus_starting_up > 0){
        orpheus_starting_up--;
        return;
    }
    if(orpheus_info == 0){ return; }
    //CHECK DEATH
        if(orpheus_info->ow_state == DIE){ return; }
        if(orpheus_hp <= 0 && orpheus_info->ow_state != DIE){
            orpheus_change_state(THIS, DIE);
            return;
        }
        colliding_block = 0u;
    //CAMERA MOVEMENT ON CHANGING MAP
        if(a_walk_counter_y < 0){
            a_walk_counter_y++;
            orpheus_change_state(THIS, WALK_UP);
            if(a_walk_counter_y == 0){
                orpheus_change_state(THIS, IDLE_UP);    
            }
            orpheus_update_position();
            return;
        }else if(a_walk_counter_y > 0){
            a_walk_counter_y--;
            orpheus_change_state(THIS, WALK_DOWN);
            if(a_walk_counter_y == 0){
                orpheus_change_state(THIS, IDLE_DOWN);    
            }
            orpheus_update_position();
            return;
        }else if(a_walk_counter_x < 0){
            a_walk_counter_x++;
            orpheus_change_state(THIS, WALK_LEFT);
            if(a_walk_counter_x == 0){
                orpheus_change_state(THIS, IDLE_LEFT);    
            }
            orpheus_update_position();
            return;
        }else if(a_walk_counter_x > 0){
            a_walk_counter_x--;
            orpheus_change_state(THIS, WALK_RIGHT);
            if(a_walk_counter_x == 0){
                orpheus_change_state(THIS, IDLE_RIGHT);    
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
                case WALK_UP: orpheus_change_state(THIS, IDLE_UP); break;
                case WALK_DOWN: orpheus_change_state(THIS, IDLE_DOWN); break;
                case WALK_LEFT: orpheus_change_state(THIS, IDLE_LEFT); break;
                case WALK_RIGHT: orpheus_change_state(THIS, IDLE_RIGHT); break;
            }
            return;
        }
        if(tutorial_go == 0){return;}
        new_state = orpheus_info->ow_state;
        if(orpheus_info->ow_state != ATTACK){
            if((orpheus_hitted == 0 && orpheus_info->ow_state != HIT) || orpheus_hit_countdown < 30){
                if(orpheus_hit_countdown){
                    orpheus_hitted = 0;
                    orpheus_hit_countdown = 0;
                }
                if(KEY_PRESSED(J_DOWN)){new_state = WALK_DOWN;}
                else if(KEY_PRESSED(J_UP)){new_state = WALK_UP;}
                else if(KEY_PRESSED(J_LEFT)){new_state = WALK_LEFT;}
                else if(KEY_PRESSED(J_RIGHT)){new_state = WALK_RIGHT;}
                else if(KEY_RELEASED(J_DOWN)){new_state = IDLE_DOWN;}
                else if(KEY_RELEASED(J_UP)){new_state = IDLE_UP;}
                else if(KEY_RELEASED(J_LEFT)){new_state = IDLE_LEFT;}
                else if(KEY_RELEASED(J_RIGHT)){new_state = IDLE_RIGHT;}
            }
        }
    //INTERACT RELEASED
        if(KEY_RELEASED(J_INT)){
            orpheus_pushing = PUSH_NONE;
        }
    //ATTACK MANAGEMENT J_ATK
        if(orpheus_info->ow_state != HIT && orpheus_info->ow_state != ATTACK && countdown == orpheus_power_max){
			if(KEY_TICKED(J_ATK)){ //countdown == orpheus_power_max && ){
                if(has_lyre){
                    orpheus_state_before = orpheus_info->ow_state;
                    new_state = ATTACK;
                }else{
			        init_write_dialog(prepare_dialog(MISSING_LYRE));
                }
			}
        }
        orpheus_change_state(THIS, new_state);
    //BEHAVE
        orpheus_behave();
    //SPRITE COLLISION
        if(orpheus_hitted || orpheus_hp == 0) return;
        UINT8 scroll_o_tile;
        Sprite* iospr;
        SPRITEMANAGER_ITERATE(scroll_o_tile, iospr) {
            if(orpheus_info->ow_state == ATTACK){
                switch(iospr->type){
                    case SpriteSkeleton:
                    case SpriteInfernalimp:
                    case SpriteLostsoul:
                    case SpriteSentinel:
                    case SpriteShadow:
                    case SpriteBanshee:
                    case SpriteSerpent:
                        e_change_state(iospr, HIT);
                    break;
                    case SpriteTartarus:
                    case SpriteMagma:
                    case SpriteFrost:
                        if(song_selection != SLEEP){
                            e_change_state(iospr, HIT);
                        }
                    break;
                    case SpriteSkeletonshield:
                    case SpriteOoze:
                    case SpriteSiren:
                        if(song_selection == SLEEP){
                            e_change_state(iospr, HIT);
                        }
                    break;
                }
            }else{
                if(CheckCollision(THIS, iospr)) {
                    switch(iospr->type){
                        case SpriteLyre:
                        case SpriteItem:
                            orpheus_pickup(iospr);
                        break;
                        case SpriteOoze:
                        case SpriteSiren:{
                            struct EnemyInfo* e_data = (struct EnemyInfo*) iospr->custom_data;
                            if(e_data->e_state != ATTACK){
                                return;
                            }
                        }
                        case SpriteTartarus:
                        case SpriteMagma:
                        case SpriteFrost:
                            orpheus_hp = 0;
                            redraw_hud = 1u;
                        break;
                        case SpriteGhost:
                        case SpriteDog:
                        case SpriteSkeleton:
                        case SpriteBlade:
                        case SpriteFireball:
                        case SpriteSentinel:
                        case SpriteCharonhand:
                        case SpriteShadow:
                        case SpriteSerpent:
                            if(orpheus_info->ow_state != HIT && orpheus_info->ow_state != DIE){
                                struct EnemyInfo* e_data = (struct EnemyInfo*) iospr->custom_data;
                                if(e_data->vx != orpheus_info->vx && orpheus_info->vy == 0){
                                    push_vx = e_data->vx;
                                }
                                if(e_data->vy != orpheus_info->vy && orpheus_info->vx == 0){
                                    push_vy = e_data->vy;
                                }
                                orpheus_change_state(THIS, HIT);
                            }
                        break;
                        case SpriteOrpheusnote:{
                            struct NoteInfo* e_data = (struct NoteInfo*) iospr->custom_data;
                            if(e_data->is_enemy){
                                orpheus_change_state(THIS, HIT);
                            }
                        }
                        break;
                        case SpriteStone:
                        case SpriteGate:{
                            inertia_x = 0;
                            inertia_y = 0;
                            INT8 deltax = THIS->x - iospr->x;
                            INT8 deltay = THIS->y - iospr->y;
                            if(THIS->x > iospr->x && orpheus_info->ow_state == WALK_LEFT){                            
                                if(KEY_PRESSED(J_INT)){
                                    SetSpriteAnim(THIS, a_orpheus_walk_h_push, 8u);
                                    orpheus_pushing = PUSH_RIGHT;
                                }else if(KEY_RELEASED(J_INT)){
                                    orpheus_pushing = PUSH_NONE;
                                }
                                if(orpheus_info->vx < 0 && deltay > -14 && deltay < 8){
                                    THIS->x++;
                                    colliding_block = 1u;
                                }
                            }else if(THIS->x < iospr->x && orpheus_info->ow_state == WALK_RIGHT){
                                if(KEY_PRESSED(J_INT)){
                                    SetSpriteAnim(THIS, a_orpheus_walk_h_push, 8u);
                                    orpheus_pushing = PUSH_LEFT;
                                }else if(KEY_RELEASED(J_INT)){
                                    orpheus_pushing = PUSH_NONE;
                                }
                                if(orpheus_info->vx > 0 && deltay > -14 && deltay < 8){
                                    THIS->x--;
                                    colliding_block = 1u;
                                }   
                            }
                            if(THIS->y < iospr->y && orpheus_info->ow_state == WALK_DOWN){
                                if(KEY_PRESSED(J_INT)){
                                    SetSpriteAnim(THIS, a_orpheus_walk_down_push, 8u);
                                    orpheus_pushing = PUSH_DOWN;
                                }else if(KEY_RELEASED(J_INT)){
                                    orpheus_pushing = PUSH_NONE;
                                }
                                if(orpheus_info->vy > 0 && deltax > -8 && deltax < 16){
                                    THIS->y--;
                                    colliding_block = 1u;
                                }
                            }else if(THIS->y > iospr->y && orpheus_info->ow_state == WALK_UP){
                                if(KEY_PRESSED(J_INT)){
                                    orpheus_pushing = PUSH_UP;
                                }else if(KEY_RELEASED(J_INT)){
                                    orpheus_pushing = PUSH_NONE;
                                }
                                if(orpheus_info->vy < 0 && deltay > 6){
                                    THIS->y++;
                                    colliding_block = 1u;
                                }
                            }
                        }break;
                        case SpriteBlock:{
                            inertia_x = 0;
                            inertia_y = 0;
                            struct ItemInfo* block_data = (struct ItemInfo*) iospr->custom_data;
                            INT8 deltax = THIS->x - iospr->x;
                            INT8 deltay = THIS->y - iospr->y;
                            if(THIS->x > iospr->x && orpheus_info->ow_state == WALK_LEFT){
                                block_data->counter_verso = -1;                            
                                if(KEY_PRESSED(J_INT)){
                                    block_data->counter_x++;
                                    SetSpriteAnim(THIS, a_orpheus_walk_h_push, 8u);
                                    orpheus_pushing = PUSH_RIGHT;
                                }else if(KEY_RELEASED(J_INT)){
                                    block_data->counter_x = 0;
                                    block_data->counter_y = 0;
                                    orpheus_pushing = PUSH_NONE;
                                }
                                if(orpheus_info->vx < 0 && deltay > -14 && deltay < 8){
                                    THIS->x++;
                                    colliding_block = 1u;
                                }
                            }else if(THIS->x < iospr->x && orpheus_info->ow_state == WALK_RIGHT){
                                block_data->counter_verso = 1;
                                if(KEY_PRESSED(J_INT)){
                                    block_data->counter_x++;
                                    SetSpriteAnim(THIS, a_orpheus_walk_h_push, 8u);
                                    orpheus_pushing = PUSH_LEFT;
                                }else if(KEY_RELEASED(J_INT)){
                                    block_data->counter_x = 0;
                                    block_data->counter_y = 0;
                                    orpheus_pushing = PUSH_NONE;
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
                                    SetSpriteAnim(THIS, a_orpheus_walk_down_push, 8u);
                                    orpheus_pushing = PUSH_DOWN;
                                }else if(KEY_RELEASED(J_INT)){
                                    block_data->counter_x = 0;
                                    block_data->counter_y = 0;
                                    orpheus_pushing = PUSH_NONE;
                                }
                                if(orpheus_info->vy > 0 && deltax > -8 && deltax < 16){
                                    THIS->y--;
                                    colliding_block = 1u;
                                }
                            }else if(THIS->y > iospr->y && orpheus_info->ow_state == WALK_UP){
                                block_data->counter_verso = -1;
                                if(KEY_PRESSED(J_INT)){
                                    block_data->counter_y++;
                                    orpheus_pushing = PUSH_UP;
                                }else if(KEY_RELEASED(J_INT)){
                                    block_data->counter_x = 0;
                                    block_data->counter_y = 0;
                                    orpheus_pushing = PUSH_NONE;
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
}

void orpheus_check_tile_overlapping() BANKED{
    UINT8 tile = GetScrollTile((THIS->x + 8) >> 3, (THIS->y+8) >> 3);
    if(tile == 0){
        tile = GetScrollTile((THIS->x + 2) >> 3, (THIS->y+16) >> 3);
    }
    if(tile == 0){
        tile = GetScrollTile((THIS->x + 10) >> 3, (THIS->y+16) >> 3);
    }
    switch(current_state){
        case StateHades00:
            if(tile == 84u || tile == 85u || tile == 86u || tile == 87u){
                orpheus_change_state(THIS, HIT);
            }
            if(tile == 50u && spikes_hit_flag){
                orpheus_change_state(THIS, HIT);
            }
        break;
    }
}

void orpheus_behave() BANKED{   
    switch(new_state){
        case IDLE_DOWN: case IDLE_LEFT: case IDLE_RIGHT: case IDLE_UP:
            if(inertia_x > 31){
                inertia_x = 0;
                if(new_state == IDLE_LEFT){
                    orpheus_info->vx = -1;
                }else if(new_state == IDLE_RIGHT){
                    orpheus_info->vx = 1;
                }
            }else{
                inertia_x = 0;
                if(orpheus_info->vx != 0){orpheus_info->vx = 0;}
            } 
            if(inertia_y > 31){
                inertia_y = 0;
                if(new_state == IDLE_DOWN){
                    orpheus_info->vy = 1;
                }else if(new_state == IDLE_UP){
                    orpheus_info->vy = -1;
                }
            }else{
                inertia_y = 0;
                if(orpheus_info->vy != 0){orpheus_info->vy = 0;}
            } 
            if(orpheus_info->vx || orpheus_info->vy){//solo per inerzia
                orpheus_update_position();
            }
            orpheus_recharge();
            orpheus_check_tile_overlapping();
            idle_countdown--;
        break;
        case WALK_DOWN: case WALK_UP:
        case WALK_LEFT: case WALK_RIGHT:
            if(orpheus_info->vx != 0 && inertia_x > 0 && inertia_x < 32){
                inertia_x++;
            }
            if(orpheus_info->vy != 0 && inertia_y > 0 && inertia_y < 32){
                inertia_y++;
            }
            orpheus_check_tile_overlapping();
            orpheus_update_position();
        break;
        case HIT:
            if(inertia_x > 0){inertia_x = 0;}
            if(inertia_y > 0){inertia_y = 0;}
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
                if(orpheus_info->tile_collision == 0){//risk to enter a wall
                    orpheus_update_position();
                }
            }
            if(orpheus_hit_countdown > 0){//going backwards
                orpheus_hit_countdown--;
            }else if(orpheus_hit_countdown <= 0){//hit effect ends
                orpheus_hit_countdown = 0;
                orpheus_hitted = 0u;
                push_vx = 0;
                push_vy = 0;
                switch(orpheus_state_before){
                    case WALK_DOWN: case IDLE_DOWN:
                        orpheus_change_state(THIS, IDLE_DOWN);
                    break;
                    case WALK_UP: case IDLE_UP: case GENERIC_IDLE: case GENERIC_WALK:
                        orpheus_change_state(THIS, IDLE_UP);
                    break;
                    case WALK_LEFT: case IDLE_LEFT:
                        orpheus_change_state(THIS, IDLE_LEFT);
                    break;
                    case WALK_RIGHT: case IDLE_RIGHT:
                        orpheus_change_state(THIS, IDLE_RIGHT);
                    break;
                }
            }
        break;
        case ATTACK:
            if(inertia_x > 0){inertia_x = 0;}
            if(inertia_y > 0){inertia_y = 0;}
            orpheus_wait--;
            if(s_lyre && orpheus_wait == 35){
                Sprite* s_note = SpriteManagerAdd(SpriteOrpheusnote, s_lyre->x+12, s_lyre->y - 2);
                struct NoteInfo* notedata = (struct NoteInfo*) s_note->custom_data;
                notedata->is_enemy = 0u;
            }
            if(orpheus_wait <= 1){
                SpriteManagerRemoveSprite(s_lyre);
                switch(orpheus_state_before){
                    case WALK_UP: orpheus_state_before = IDLE_UP; break;
                    case WALK_DOWN: orpheus_state_before = IDLE_DOWN; break;
                    case WALK_LEFT: orpheus_state_before = IDLE_LEFT; break;
                    case WALK_RIGHT: orpheus_state_before = IDLE_RIGHT; break;
                }
                orpheus_change_state(THIS, orpheus_state_before);
                return;
            }
        break;
    }
}

void orpheus_recharge() BANKED{
	if(countdown_verso != 0){
		countdown_step--;
		if(countdown_step == 0){
            countdown_step = countdown_step_currentmax;
			countdown += countdown_verso;
			if(countdown == orpheus_power_max){//RICHARGE COMPLETA
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
    if(current_state == StateBoss00 && THIS->y > ((UINT16) 16u << 3) && orpheus_info->vy > 0){
        return;
    }
    if(orpheus_hitted && orpheus_info->tile_collision){
        return;
    }
    orpheus_info->tile_collision = TranslateSprite(THIS, orpheus_info->vx << delta_time, orpheus_info->vy << delta_time);
    //CHECK COLLISION WITH INTERACTIVE TILES
        if(orpheus_info->tile_collision){
            switch(current_state){
                case StateTutorial:
                    switch(orpheus_info->tile_collision){
                        case 6u: 
                        case 30u://CARTEL!
                            if(KEY_PRESSED(J_INT)){
                                prepare_dialog(TUTORIAL_PLAY);
                                SetState(StateCartel);
                            }
                        break;
                        case 11u:
                        case 12u:
                            go_to_next_map();
                        break;
                    }
                break;
                case StateHades00:
                    if(orpheus_info->ow_state == HIT){
                        THIS->x -= orpheus_info->vx;
                        THIS->y -= orpheus_info->vy;
                    }
                    switch(orpheus_info->tile_collision){
                        case 66u://PIT, INSTANT DEATH!
                            orpheus_hp = 0;
                            redraw_hud = 1u;
                        break;
                        case 6u://PREV MAP
                            case 7u:
                            case 8u:
                                go_to_prev_map();
                        break;
                        case 88u://NEXT MAP
                            case 90u: case 92u:
                            case 94u: case 96u: case 98u:
                            case 100u: case 102u: case 104u:
                                if(orpheus_haskey == 1u && KEY_PRESSED(J_INT) && solved_map < current_map){
                                    solve_current_map();
                                    redraw_hud = 1;
                                    orpheus_haskey = 0;
                                }
                                if(solved_map >= current_map){
                                    go_to_next_map();
                                }
                        break;
                        case 116u://CARTEL
                            case 118u:
                                if(KEY_PRESSED(J_INT)){
                                    show_cartel = 1;
                                }
                        break;
                    }
                break;
            }
        }
}

void orpheus_change_state(Sprite* arg_s_orpheus, SPRITE_STATES arg_new_state) BANKED{
    if(orpheus_info->ow_state == arg_new_state && colliding_block == 0 && arg_new_state != DIE){
        return;
    }
    if(orpheus_info->ow_state == DIE){
        return;
    }
    if(arg_new_state != IDLE_DOWN && arg_new_state != IDLE_UP
        && arg_new_state != IDLE_RIGHT && arg_new_state != IDLE_LEFT
        && idle_countdown != 800u){
        idle_countdown = 800u;
    }    
    switch(arg_new_state){
        case IDLE_DOWN:
            if(inertia_x == 0){
                orpheus_info->vx = 0;
                orpheus_info->vy = 0;
            }
            SetSpriteAnim(arg_s_orpheus, a_orpheus_idledown, 4u);
        break;
        case IDLE_UP:
            if(inertia_x == 0){
                orpheus_info->vx = 0;
                orpheus_info->vy = 0;
            }
            SetSpriteAnim(arg_s_orpheus, a_orpheus_idleup, 4u);
        break;
        case IDLE_LEFT:
            if(inertia_x == 0){
                orpheus_info->vx = 0;
                orpheus_info->vy = 0;
            }
            SetSpriteAnim(arg_s_orpheus, a_orpheus_idleh, 4u);
            arg_s_orpheus->mirror = V_MIRROR;
        break;
        case IDLE_RIGHT:
            if(inertia_x == 0){
                orpheus_info->vx = 0;
                orpheus_info->vy = 0;
            }
            SetSpriteAnim(arg_s_orpheus, a_orpheus_idleh, 4u);
            arg_s_orpheus->mirror = NO_MIRROR;
        break;
        case WALK_DOWN:
            inertia_y = 1;
            orpheus_info->vx = 0;
            orpheus_info->vy = 1;
            SetSpriteAnim(arg_s_orpheus, a_orpheus_walk_down, 12u);
        break;
        case WALK_UP:
            inertia_y = 1;
            orpheus_info->vx = 0;
            orpheus_info->vy = -1;
            SetSpriteAnim(arg_s_orpheus, a_orpheus_walk_up, 12u);
        break;
        case WALK_LEFT:
            inertia_x = 1;
            orpheus_info->vx = -1;
            orpheus_info->vy = 0;
            SetSpriteAnim(arg_s_orpheus, a_orpheus_walk_h, 12u);
            arg_s_orpheus->mirror = V_MIRROR;
        break;
        case WALK_RIGHT:
            inertia_x = 1;
            orpheus_info->vx = 1;
            orpheus_info->vy = 0;
            SetSpriteAnim(arg_s_orpheus, a_orpheus_walk_h, 12u);
            arg_s_orpheus->mirror = NO_MIRROR;
        break;
        case HIT:
            hit_frameskip_max = 1;
            hit_frameskip = 1;
            switch(orpheus_info->ow_state){
                case WALK_DOWN:
                case IDLE_DOWN:
                    SetSpriteAnim(arg_s_orpheus, a_orpheus_hit_down, 24u);
                break;
                case WALK_UP:
                case IDLE_UP:
                    SetSpriteAnim(arg_s_orpheus, a_orpheus_hit_up, 24u);
                break;
                case WALK_LEFT: case WALK_RIGHT:
                case IDLE_LEFT: case IDLE_RIGHT:
                    SetSpriteAnim(arg_s_orpheus, a_orpheus_hit_h, 24u);
                break;
                case ATTACK:
                    SetSpriteAnim(arg_s_orpheus, a_orpheus_hit_down, 24u);
                    SpriteManagerRemoveSprite(s_lyre);
                break;
            }
            if(orpheus_info->ow_state != ATTACK){
                orpheus_state_before = orpheus_info->ow_state;
            }
            orpheus_hit();
        break;
        case ATTACK:
            countdown = 0;
            countdown_verso = 1;
            redraw_hud = 1;
            orpheus_info->charming = 1;
            SetSpriteAnim(arg_s_orpheus, a_orpheus_attack_down, 1u);
            switch(song_selection){
                case ATTRACT://charm
                    countdown_step_currentmax = COUNTDOWN_SKIP_ATTRACT;
                    orpheus_wait = 120u;
                    orpheus_attack_cooldown = 120u;
                break;
                case REPEL://repell
                    countdown_step_currentmax = COUNTDOWN_SKIP_REPELL;
                    orpheus_wait = 120u;
                    orpheus_attack_cooldown = 120u;
                break;
                case SLEEP://attract
                    countdown_step_currentmax = COUNTDOWN_SKIP_SLEEP;
                    orpheus_wait = 120u;
                    orpheus_attack_cooldown = 200u;
                break;
            }
            countdown_step = countdown_step_currentmax;
            s_lyre = SpriteManagerAdd(SpriteOrpheuslyre, arg_s_orpheus->x-4, arg_s_orpheus->y);
            Sprite* s_note = SpriteManagerAdd(SpriteOrpheusnote, s_lyre->x+12, s_lyre->y - 2);
            struct NoteInfo* notedata = (struct NoteInfo*) s_note->custom_data;
            notedata->is_enemy = 0u;
        break;
        case DIE:{
            if(restart_current_map == 0u){
                restart_current_map = 1u;
            }
            orpheus_hp = 0;
            redraw_hud = 1;
            boss_intro = 0;
            SetSpriteAnim(arg_s_orpheus, a_orpheus_dead, 1u);
            if(orpheus_info->ow_state != arg_new_state){//make sure death anim once
                spawn_death_animation(arg_s_orpheus->x, arg_s_orpheus->y);
            }
        }break;
    }
    orpheus_info->ow_state = arg_new_state;
}

void orpheus_hit() BANKED{
    if(orpheus_hitted == 0u){
        orpheus_hp--;
        orpheus_hit_countdown = 80;
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
                orpheus_change_state(THIS, IDLE_DOWN);
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
                    case KEY:
                        orpheus_haskey = 1u;
                        redraw_hud = 1;
                        SpriteManagerRemoveSprite(itemsprite);
                    break;
                }
            }
        break;
    }
}

void DESTROY() {
}