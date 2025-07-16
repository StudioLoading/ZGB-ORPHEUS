#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

#define CHARON_ATTACK_MAX 400
#define CHARON_ATTACK_MED 200
#define CHARON_ATTACK_MIN 80

#define CHARON_PREATTACK_MAX 6
#define CHARON_PREATTACK_MED 2
#define CHARON_PREATTACK_MIN 1

const UINT8 a_charon[] = {10, 1,2,2,3,4,5,4,5,4,5};
const UINT8 a_charon_hit[] = {20, 0,1,0,2,0,2,0,3,0,4,0,5,0,4,0,5,0,4,0,5};

struct CharonInfo charon_info;
UINT8 charon_bounce_current = 0;
INT16 charon_attack_current = 0;
INT16 charon_attack_max = 0;
Sprite* s_charon_boat = 0;
Sprite* s_charon_hand_left = 0;
Sprite* s_charon_hand_right = 0;
INT8 charon_frmskip_current = 0;
INT8 charon_frmskip_max = 0;
UINT16 charon_attack_posx = 74u;
UINT16 charon_attack_posy = 26u;
UINT16 charon_walk_posy = 40u;
INT8 charon_vx = 0;
INT8 charon_vy = 0;
UINT8 charon_walking_frmskip_x_current = 0u;
UINT8 charon_walking_frmskip_y_current = 0u;
INT16 delta_walking_delta_x = 0;
INT16 delta_walking_delta_y = 0;
struct EnemyInfo* charonlefthand_data;
struct EnemyInfo* charonrighthand_data;
UINT8 charon_attack_type = 0u;
INT8 charon_hit_cooldown = 0;

extern struct OrpheusInfo* orpheus_info;
extern INT8 boss_hp_max;
extern INT8 boss_hp_current;
extern Sprite* s_orpheus;
extern UINT16 boat_walk_right_limit;
extern UINT16 boat_walk_left_limit;
extern SONG song_selection;
extern UINT8 boss_intro;
extern UINT8 death_countdown;

void charon_change_state(SPRITE_STATES arg_new_state) BANKED;
void charon_preattack_move(UINT16 arg_final_posx, UINT16 arg_final_posy) BANKED;

extern void boat_turn() BANKED;
extern void spawn_death_animation(UINT16 spawnx, UINT16 spawny) BANKED;

void START() {
    charon_attack_type = 0u;
    SetSpriteAnim(THIS, a_charon, 8);
    s_charon_hand_left = SpriteManagerAdd(SpriteCharonhand, THIS->x - 6u, THIS->y + 4u);
    charonlefthand_data = (struct EnemyInfo*)s_charon_hand_left->custom_data;
    charonlefthand_data->frmskip = 1u;
    s_charon_hand_right = SpriteManagerAdd(SpriteCharonhand, THIS->x + 8u, THIS->y + 4u);
    charonrighthand_data = (struct EnemyInfo*)s_charon_hand_right->custom_data;
    charonrighthand_data->frmskip = 0u;
    s_charon_boat = SpriteManagerAdd(SpriteCharonboat, THIS->x - 4u, THIS->y + 20u);
    s_charon_hand_right->mirror = V_MIRROR;
    charon_info.e_state = GENERIC_WALK;
    charon_info.countdown = 80u;
    charon_attack_max = CHARON_ATTACK_MAX;
    charon_attack_current = 0;
    charon_frmskip_max = CHARON_PREATTACK_MAX;
    charon_frmskip_current = charon_frmskip_max;
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
    //BOUNCING
        charon_bounce_current++;
        if(charon_bounce_current < 10){
            if(charon_bounce_current % 6 == 0){
                THIS->y--;
            }
        }else if(charon_bounce_current < 20){
            if(charon_bounce_current % 4 == 0){
                THIS->y--;
            }
        }else if(charon_bounce_current < 34){
            if(charon_bounce_current % 6 == 0){
                THIS->y--;
            }
        }else if(charon_bounce_current < 40){
        }else if(charon_bounce_current < 48){
            if(charon_bounce_current % 6 == 0){
                THIS->y++;
            }
        }else if(charon_bounce_current < 58){
            if(charon_bounce_current % 4 == 0){
                THIS->y++;
            }
        }else if(charon_bounce_current < 64){
            if(charon_bounce_current % 6 == 0){
                THIS->y++;
            }
        }else if(charon_bounce_current < 80){       
        }else{
            charon_bounce_current = 0u;
        }
    //CHARON POSITION
        switch(charon_info.e_state){
            case GENERIC_WALK:
                if(charon_hit_cooldown > 0){
                    charon_hit_cooldown--;
                }
                if(s_charon_boat){
                    THIS->x = s_charon_boat->x + 4u;
                }
                if(s_charon_hand_left){
                    s_charon_hand_left->x = THIS->x - 9u;
                    s_charon_hand_left->y = THIS->y+1;
                }
                if(s_charon_hand_right){
                    s_charon_hand_right->x = THIS->x + 17u;
                    s_charon_hand_right->y = THIS->y+1;
                }
                charon_attack_current++;
                if(charon_attack_current > charon_attack_max){
                    charon_attack_current = 0;
                    charon_change_state(PREATTACK_UP);
                }
            break;
            case PREATTACK_UP: //move to 68;30
                if(s_charon_hand_left){
                    s_charon_hand_left->x = THIS->x - 9u;
                    s_charon_hand_left->y = THIS->y+1;
                }
                if(s_charon_hand_right){
                    s_charon_hand_right->x = THIS->x + 17u;
                    s_charon_hand_right->y = THIS->y+1;
                }
                charon_frmskip_current--;
                UINT16 final_current_x = s_orpheus->x + 8;
                if(s_orpheus->x > boat_walk_right_limit){
                    final_current_x = boat_walk_right_limit - 2u;
                }else if(s_orpheus->x < boat_walk_left_limit){
                    final_current_x = boat_walk_left_limit + 2u;
                }
                if(charon_frmskip_current <= 0){
                    charon_frmskip_current = charon_frmskip_max;
                    //MOVING TO KNOWN POINT
                        charon_preattack_move(final_current_x, charon_attack_posy);
                }
                INT16 delta_final_x = (INT16)THIS->x - (INT16)final_current_x;
                INT16 delta_final_y = (INT16)THIS->y - (INT16)charon_attack_posy;
                if((delta_final_x < 3 && delta_final_x > -3 && 
                    ((delta_final_y < 3 && delta_final_y > -3)) || THIS->y < 24u)){
                    charon_change_state(PREATTACK_DOWN);
                }
            break;
            case PREATTACK_DOWN:
                if(charonlefthand_data->e_configured == 3 && 
                    charonrighthand_data->e_configured == 3){
                        charonlefthand_data->e_configured = 0;
                        charonrighthand_data->e_configured = 0;
                        if(boss_hp_current < 5){
                            charon_frmskip_max = CHARON_PREATTACK_MED;
                            if(boss_hp_current < 3){
                                charon_frmskip_max = CHARON_PREATTACK_MIN;
                            }
                        }
                        charon_change_state(ATTACK);
                    }
            break;
            case ATTACK:
                if(charonlefthand_data->e_configured == 3 && charonrighthand_data->e_configured == 3){
                    if(s_charon_hand_left){
                        s_charon_hand_left->x = THIS->x - 9u;
                        s_charon_hand_left->y = THIS->y+1;
                    }
                    if(s_charon_hand_right){
                        s_charon_hand_right->x = THIS->x + 17u;
                        s_charon_hand_right->y = THIS->y+1;
                    }
                    charon_frmskip_current--;
                    if(charon_frmskip_current <= 0){
                        charon_frmskip_current = charon_frmskip_max;
                        charon_preattack_move(THIS->x, charon_walk_posy);
                    }
                    INT16 delta_final_y = (INT16)charon_walk_posy - (INT16)THIS->y;
                    if(THIS->y == charon_walk_posy){
                        charon_change_state(GENERIC_WALK);
                    }
                }
            break;
            case HIT:{
                if(s_charon_hand_left){
                    s_charon_hand_left->x = THIS->x - 9u;
                    s_charon_hand_left->y = THIS->y+1;
                }
                if(s_charon_hand_right){
                    s_charon_hand_right->x = THIS->x + 17u;
                    s_charon_hand_right->y = THIS->y+1;
                }
                charon_info.wait--;
                if(charon_info.wait > 0){
                    charon_info.vx = 1;
                    switch(song_selection){
                        case ATTRACT:
                            if(THIS->x >= s_orpheus->x){
                                charon_info.vx = -1;
                            }
                        break;
                        case REPEL:
                            if(THIS->x <= s_orpheus->x){
                                charon_info.vx = -1;
                            }
                        break;
                        case SLEEP:
                            charon_change_state(GENERIC_WALK);
                            return;
                        break;
                    }
                    charon_info.tile_collision = TranslateSprite(THIS, charon_info.vx << delta_time, 0);
                    if(charon_info.tile_collision){//hit
                        charon_info.wait = 0;
                        boss_hp_current--;
                        SetSpriteAnim(THIS, a_charon_hit, 60u);
                        spawn_death_animation(THIS->x + 8u, THIS->y + 20u);
                        if(boss_hp_current <= 0){
                            charon_change_state(DIE);
                        }
                    }
                }
                if(charon_info.wait <= 0){
                    if(charon_info.tile_collision == 0){//no hit
                        charon_change_state(GENERIC_WALK);
                    }else{
                        charon_info.countdown--;
                        if((charon_info.countdown % 4) == 0){//as a frameskip
                            THIS->x -= charon_info.vx;
                            if(charon_info.countdown > 60){
                                THIS->y-=2;
                            }else if(charon_info.countdown > 40){
                                THIS->y++;
                            }
                        }
                        if(charon_info.countdown <= 0){
                            boat_turn();
                            charon_change_state(GENERIC_WALK);
                        }
                    }
                }
            }
            break;
            case DIE:
                if(s_charon_hand_left){
                    s_charon_hand_left->x = THIS->x - 9u;
                    s_charon_hand_left->y = THIS->y+1;
                }
                if(s_charon_hand_right){
                    s_charon_hand_right->x = THIS->x + 17u;
                    s_charon_hand_right->y = THIS->y+1;
                }
                charon_frmskip_current--;
                if(charon_frmskip_current <= 0){
                    charon_frmskip_current = charon_frmskip_max;
                    charon_preattack_move(72u, 40u);
                    if(THIS->x == 72u && boss_intro != 4){
                        boss_intro = 4;
                        death_countdown = 160u;
                        SpriteManagerRemoveSprite(s_charon_hand_left);
                        SpriteManagerRemoveSprite(s_charon_hand_right);
                    }
                }
            break;
        }
    //CHECK ORPHEUS ATTACKING
        if(orpheus_info->ow_state == ATTACK && charon_hit_cooldown == 0){
            if(charon_info.e_state == GENERIC_WALK){
                charon_change_state(HIT);
            }
        }
}

void charon_preattack_move(UINT16 arg_final_posx, UINT16 arg_final_posy) BANKED{
    INT8 delta_walking_delta_x_verse = 1;
    if(THIS->x > arg_final_posx){
        delta_walking_delta_x_verse = -1;
    }
    INT8 delta_walking_delta_y_verse = 1;
    if(THIS->y > arg_final_posy){
        delta_walking_delta_y_verse = -1;
    }
    charon_vx = 1 * delta_walking_delta_x_verse;
    charon_vy = 1 * delta_walking_delta_y_verse;
    INT8 actual_charon_vx = charon_vx;
    INT8 actual_charon_vy = charon_vy;
    INT8 delta_factor_y = 0;
    INT8 delta_factor_x = 0;
    if(delta_walking_delta_x > delta_walking_delta_y){
        delta_factor_y = delta_walking_delta_x / delta_walking_delta_y;
        INT16 r_y = delta_walking_delta_x % delta_walking_delta_y;
        if(r_y > (delta_walking_delta_y >> 1)){
            delta_factor_y += delta_factor_y;
        }
    }else{
        delta_factor_x = delta_walking_delta_y / delta_walking_delta_x;
        INT16 r_x = delta_walking_delta_y % delta_walking_delta_x;
        if(r_x > (delta_walking_delta_x >> 1)){
            delta_factor_x += delta_factor_x;
        }
    }
    //e scopro ogni quanti x deve fare una y
    INT8 charon_walking_frmskip_x_max = delta_factor_x;
    INT8 charon_walking_frmskip_y_max = delta_factor_y;
    if(delta_factor_y < 0){
        charon_walking_frmskip_y_max = -delta_factor_y;
    }
    if(delta_factor_x < 0){
        charon_walking_frmskip_x_max = -delta_factor_x;    
    }
    if(charon_walking_frmskip_x_max > 0 && (INT8)charon_walking_frmskip_x_current < charon_walking_frmskip_x_max){//ecco che devo fare una y
        actual_charon_vx = 0;
    }
    if(charon_walking_frmskip_y_max > 0 && (INT8)charon_walking_frmskip_y_current < charon_walking_frmskip_y_max){
        actual_charon_vy = 0;
    }
    if((INT8)charon_walking_frmskip_x_current == charon_walking_frmskip_x_max){
        charon_walking_frmskip_x_current = 0;
    }
    if((INT8)charon_walking_frmskip_y_current == charon_walking_frmskip_y_max){
        charon_walking_frmskip_y_current = 0;
    }
    charon_walking_frmskip_x_current++;
    charon_walking_frmskip_y_current++;
    if(actual_charon_vx != 0 || actual_charon_vy != 0){
        UINT8 gator_coll_tile = TranslateSprite(THIS, actual_charon_vx << delta_time, actual_charon_vy << delta_time);
    }
}

void charon_change_state(SPRITE_STATES arg_new_state) BANKED{
    switch(arg_new_state){
        /*case PREATTACK_DOWN://looping hands
        break;*/
        case GENERIC_WALK://move left-right
            charon_info.countdown = 80u;
            charonrighthand_data->e_configured = 0;
            charonlefthand_data->e_configured = 0;
            if(boss_hp_current < 5){
                charon_attack_max = CHARON_ATTACK_MED;
                if(boss_hp_current < 3){
                    charon_attack_max = CHARON_ATTACK_MIN;
                }
            }
            if(THIS->x < boat_walk_left_limit){
                THIS->x = boat_walk_left_limit+2;
            }
            if(THIS->x > boat_walk_right_limit){
                THIS->x = boat_walk_right_limit-2;
            }
            SetSpriteAnim(THIS, a_charon, 8);
        break;
        case PREATTACK_UP://moves to attack position
            switch(boss_hp_current){
                case 5: case 4: case 2:
                    charonlefthand_data->frmskip_wait = 200;
                    charonrighthand_data->frmskip_wait = 200;
                break;
                case 1: case 3:
                    charonlefthand_data->frmskip_wait = 100;
                    charonrighthand_data->frmskip_wait = 100;
                break;
            }
            charon_attack_type++;
            if(charon_attack_type > 4){
                charon_attack_type = 0;
            }
            SetSpriteAnim(THIS, a_charon_hit, 24u);
        break;
        case ATTACK:
            SetSpriteAnim(THIS, a_charon, 1u);
        break;
        case HIT:
            charon_hit_cooldown = 60;
            charon_info.wait_max = 40;
            charon_info.wait = charon_info.wait_max;
        break;
        case DIE:
            charon_frmskip_max = CHARON_PREATTACK_MAX;
            SetSpriteAnim(THIS, a_charon_hit, 12u);
        break;
    }
    charon_info.e_state = arg_new_state;
}

void DESTROY() {
}