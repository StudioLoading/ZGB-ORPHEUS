#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

#define FRMSKIPMAX_MAX 8
#define FRMSKIPMAX_MED 6
#define FRMSKIPMAX_MIN 4

#define ATTACK_WAIT_MAX 250
#define ATTACK_WAIT_MED 200
#define ATTACK_WAIT_MIN 100
#define ATTACK_WAIT_MAX_RIGHT 140
#define ATTACK_WAIT_MED_RIGHT 100
#define ATTACK_WAIT_MIN_RIGHT 40

const UINT8 a_cerberushead_hidden[] = {1, 0};
const UINT8 a_cerberusheadleft[] = {1, 3};
const UINT8 a_cerberusheadleft_preattack[] = {1, 3};
const UINT8 a_cerberusheadleft_attack[] = {1, 2};
const UINT8 a_cerberusheadright[] = {1, 1};
const UINT8 a_cerberusheadright_walkdown[] = {1, 5};
const UINT8 a_cerberusheadright_preattack[] = {1, 1};
const UINT8 a_cerberusheadright_attack[] = {1, 6};
const UINT8 a_cerberushead_bite[] = {1, 2};
const UINT8 a_cerberusheadleft_hit[] = {2, 0,3};
const UINT8 a_cerberusheadright_hit[] = {2, 1,5};
const UINT8 a_cerberushead_dead[] = {1, 4};

UINT8 cerberus_walking_frmskip_x_current = 0u;
UINT8 cerberus_walking_frmskip_y_current = 0u;
INT16 cerberus_delta_walking_delta_x = 0;
INT16 cerberus_delta_walking_delta_y = 0;

extern UINT8 boss_breath_flag;
extern INT8 boss_breath_verse;
extern UINT8 boss_breath_flag_right;
extern INT8 boss_breath_verse_right;
extern INT8 boss_hp_current;
extern Sprite* s_orpheus;
extern Sprite* s_skeletoncerberus;
extern UINT8 is_skeletoncerberus_taken;
extern UINT16 boss_cerberus_startpos_x_left;
extern UINT16 boss_cerberus_startpos_y_left;
extern UINT16 boss_cerberus_startpos_x_right;
extern UINT16 boss_cerberus_startpos_y_right;
extern UINT8 redraw_hud;

void cerberus_change_state(Sprite* arg_s_cerberus, SPRITE_STATES arg_new_state) BANKED;
void cerberus_update_wait(Sprite* arg_cerberus_head) BANKED;
void cerberus_calculate_note_v(Sprite* arg_s_cerberus, INT8* arg_vx, INT8* arg_vy) BANKED;
void cerberus_walk_to(Sprite* arg_s_cerberus, UINT16 arg_final_posx, UINT16 arg_final_posy) BANKED;

extern Sprite* e_spawn_hitnote(INT16 arg_spawnx, UINT16 arg_spawny, NOTE_MOVEMENT_TYPE arg_movement_type) BANKED;
extern void e_change_state(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;

/*
CerberusInfo{
	SPRITE_STATES e_state;
	INT8 vx;
	INT8 vy;
    UINT8 wait;
	INT8 frmskip;
	INT8 frmskip_max;
	INT8 head_config;
*/
void START() {
    SetSpriteAnim(THIS, a_cerberushead_hidden, 1);
    struct CerberusInfo* head_info = (struct CerberusInfo*)THIS->custom_data;
    head_info->head_config = 0;
    head_info->frmskip = 0;
    head_info->frmskip_max = FRMSKIPMAX_MAX;
    head_info->e_state = GENERIC_IDLE;
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
    struct CerberusInfo* head_info = (struct CerberusInfo*)THIS->custom_data;
    switch(head_info->head_config){
        case 0: return; break;
        case 1: //set left
            SetSpriteAnim(THIS, a_cerberusheadleft, 1);
            head_info->wait = ATTACK_WAIT_MAX;
            head_info->head_config = 4;
        break;
        case 2: //set right
            SetSpriteAnim(THIS, a_cerberusheadright, 1);
            head_info->wait = ATTACK_WAIT_MAX_RIGHT;
            head_info->head_config = 5;
        break;
        case 4: //is left
        case 6: //is right walking
            switch(head_info->e_state){
                case GENERIC_IDLE:
                    if(boss_breath_flag){
                        THIS->y += boss_breath_verse;
                        boss_breath_flag = 0;
                    }
                    head_info->frmskip++;
                    if(head_info->frmskip == head_info->frmskip_max){
                        head_info->frmskip = 0;
                    }
                    head_info->wait--;
                    if(head_info->wait == 0){
                        cerberus_change_state(THIS, PREATTACK_DOWN);
                    }
                break;
                case PREATTACK_DOWN:
                    head_info->wait--;
                    if(head_info->wait == 0){
                        cerberus_change_state(THIS, ATTACK);
                    }
                break;
                case ATTACK:
                    head_info->wait--;
                    if(head_info->wait == 0){
                        cerberus_change_state(THIS, GENERIC_IDLE);
                    }
                break;
                case WALK_DOWN:
                    cerberus_walk_to(THIS, s_skeletoncerberus->x, s_skeletoncerberus->y);
                break;
                case WALK_UP:
                    head_info->wait--;
                    if(head_info->wait){
                        s_skeletoncerberus->x = THIS->x;
                        s_skeletoncerberus->y = THIS->y + 10u;
                        if(head_info->head_config == 4){
                            cerberus_walk_to(THIS, boss_cerberus_startpos_x_left, boss_cerberus_startpos_y_left);
                        }else if(head_info->head_config == 6){
                            cerberus_walk_to(THIS, boss_cerberus_startpos_x_right, boss_cerberus_startpos_y_right);
                        }
                    }else{
                        if(head_info->head_config == 4){
                            THIS->x = boss_cerberus_startpos_x_left;
                            THIS->y = boss_cerberus_startpos_y_left;
                        }else{
                            THIS->x = boss_cerberus_startpos_x_right;
                            THIS->y = boss_cerberus_startpos_y_right;
                        }
                        cerberus_change_state(THIS, HIT);
                    }
                break;
                case HIT:
                    head_info->wait--;
                    if(head_info->wait == 0){
                        if(boss_hp_current == 3 || boss_hp_current == 1){
                            THIS->y += 3;
                            cerberus_change_state(THIS, DIE);
                        }else{
                            cerberus_change_state(THIS, GENERIC_IDLE);
                        }
                    }
                break;
            }
        break;
        case 5: //is right
            switch(head_info->e_state){
                case GENERIC_IDLE:
                    if(boss_breath_flag_right){
                        THIS->y += boss_breath_verse_right;
                        boss_breath_flag_right = 0;
                    }
                    head_info->frmskip++;
                    if(head_info->frmskip == head_info->frmskip_max){
                        head_info->frmskip = 0;
                    }
                    head_info->wait--;
                    if(head_info->wait == 0){
                        cerberus_change_state(THIS, PREATTACK_DOWN);
                    }
                break;
                case PREATTACK_DOWN:
                    head_info->wait--;
                    if(head_info->wait == 0){
                        cerberus_change_state(THIS, ATTACK);
                    }
                break;
                case ATTACK:
                    head_info->wait--;
                    if(head_info->wait == 0){
                        cerberus_change_state(THIS, GENERIC_IDLE);
                    }
                break;
                case WALK_DOWN:
                    head_info->wait--;
                    if(head_info->wait == 0){
                        cerberus_change_state(THIS, GENERIC_IDLE);
                    }
                break;
            }
        break;
    }
    UINT8 scroll_ch_tile;
    Sprite* ichspr;
    SPRITEMANAGER_ITERATE(scroll_ch_tile, ichspr) {
        if(ichspr->type == SpriteSkeletoncerberus){
            switch(head_info->e_state){
                case WALK_DOWN:
                    if(CheckCollision(THIS, ichspr)) {
                        is_skeletoncerberus_taken = 2u;
                        cerberus_change_state(THIS, WALK_UP);
                    }
                break;
                case GENERIC_IDLE:{                    
                    INT16 delta_ch_sk_x = (INT16)THIS->x - (UINT16)ichspr->x;
                    INT16 delta_ch_sk_y = (UINT16)ichspr->y - (INT16)THIS->y;
                    if(delta_ch_sk_y < 44){
                        if(delta_ch_sk_x < 8 && delta_ch_sk_x > -8){
                            if(is_skeletoncerberus_taken == 0){
                                is_skeletoncerberus_taken = 1u;
                                cerberus_change_state(THIS, WALK_DOWN);
                            }
                        }
                    }
                }break;
            }
        }
    }
}

void cerberus_walk_to(Sprite* arg_s_cerberus, UINT16 arg_final_posx, UINT16 arg_final_posy) BANKED{
    INT8 delta_walking_delta_x_verse = 1;
    if(arg_s_cerberus->x > arg_final_posx){
        delta_walking_delta_x_verse = -1;
    }
    INT8 delta_walking_delta_y_verse = 1;
    if(arg_s_cerberus->y > arg_final_posy){
        delta_walking_delta_y_verse = -1;
    }
    struct CerberusInfo* head_info = (struct CerberusInfo*)arg_s_cerberus->custom_data;
    head_info->vx = 1 * delta_walking_delta_x_verse;
    head_info->vy = 1 * delta_walking_delta_y_verse;
    INT8 actual_cerberus_vx = head_info->vx;
    INT8 actual_cerberus_vy = head_info->vy;
    INT8 delta_factor_y = 0;
    INT8 delta_factor_x = 0;
    if(cerberus_delta_walking_delta_x > cerberus_delta_walking_delta_y){
        delta_factor_y = cerberus_delta_walking_delta_x / cerberus_delta_walking_delta_y;
        INT16 r_y = cerberus_delta_walking_delta_x % cerberus_delta_walking_delta_y;
        if(r_y > (cerberus_delta_walking_delta_y >> 1)){
            delta_factor_y += delta_factor_y;
        }
    }else{
        delta_factor_x = cerberus_delta_walking_delta_y / cerberus_delta_walking_delta_x;
        INT16 r_x = cerberus_delta_walking_delta_y % cerberus_delta_walking_delta_x;
        if(r_x > (cerberus_delta_walking_delta_x >> 1)){
            delta_factor_x += delta_factor_x;
        }
    }
    //e scopro ogni quanti x deve fare una y
    INT8 cerberus_walking_frmskip_x_max = delta_factor_x;
    INT8 cerberus_walking_frmskip_y_max = delta_factor_y;
    if(delta_factor_y < 0){
        cerberus_walking_frmskip_y_max = -delta_factor_y;
    }
    if(delta_factor_x < 0){
        cerberus_walking_frmskip_x_max = -delta_factor_x;    
    }
    if(cerberus_walking_frmskip_x_max > 0 && (INT8)cerberus_walking_frmskip_x_current < cerberus_walking_frmskip_x_max){//ecco che devo fare una y
        actual_cerberus_vx = 0;
    }
    if(cerberus_walking_frmskip_y_max > 0 && (INT8)cerberus_walking_frmskip_y_current < cerberus_walking_frmskip_y_max){
        actual_cerberus_vy = 0;
    }
    if((INT8)cerberus_walking_frmskip_x_current == cerberus_walking_frmskip_x_max){
        cerberus_walking_frmskip_x_current = 0;
    }
    if((INT8)cerberus_walking_frmskip_y_current == cerberus_walking_frmskip_y_max){
        cerberus_walking_frmskip_y_current = 0;
    }
    cerberus_walking_frmskip_x_current++;
    cerberus_walking_frmskip_y_current++;
    if(actual_cerberus_vx != 0 || actual_cerberus_vy != 0){
        UINT8 gator_coll_tile = TranslateSprite(arg_s_cerberus, actual_cerberus_vx << delta_time, actual_cerberus_vy << delta_time);
    }
}

void cerberus_change_state(Sprite* arg_s_cerberus, SPRITE_STATES arg_new_state) BANKED{
    struct CerberusInfo* head_info = (struct CerberusInfo*)arg_s_cerberus->custom_data;
    switch(arg_new_state){
        case PREATTACK_DOWN:
            head_info->wait = 20u;
            switch(head_info->head_config){
                case 4://is left
                    SetSpriteAnim(arg_s_cerberus, a_cerberusheadleft_preattack, 1);
                break;
                case 5://is center
                    SetSpriteAnim(arg_s_cerberus, a_cerberusheadright_preattack, 1);
                break;
            }
        break;
        case ATTACK:{
            head_info->wait = 20u;
            switch(head_info->head_config){
                case 4://is left
                    SetSpriteAnim(arg_s_cerberus, a_cerberusheadleft_attack, 1u);
                break;
                case 5://is right
                    SetSpriteAnim(arg_s_cerberus, a_cerberusheadright_attack, 1u);
                break;
            }
            Sprite* s_hitnote = 0;
            switch(head_info->head_config){
                case 4://is left
                    s_hitnote = e_spawn_hitnote(arg_s_cerberus->x + 4u, arg_s_cerberus->y + 16u, NOTE_MOV_D);
                break;
                case 5://is right
                    s_hitnote = e_spawn_hitnote(arg_s_cerberus->x + 16u, arg_s_cerberus->y + 16u, NOTE_MOV_D);
                break;
            }
            struct NoteInfo* e_hitnotedata = (struct NoteInfo*) s_hitnote->custom_data;
            INT8 calculated_note_vx = 0;
            INT8 calculated_note_vy = 2;
            cerberus_calculate_note_v(arg_s_cerberus, &calculated_note_vx, &calculated_note_vy);
            e_hitnotedata->vx = calculated_note_vx;
            e_hitnotedata->vy = calculated_note_vy;
            e_hitnotedata->frmskip_max = 4;
        }break;
        case GENERIC_IDLE:
            cerberus_update_wait(arg_s_cerberus);
            switch(head_info->head_config){
                case 4://is left
                    SetSpriteAnim(THIS, a_cerberusheadleft, 1);
                break;
                case 5://is right
                    SetSpriteAnim(THIS, a_cerberusheadright, 1);
                break;
            }
        break;
        case WALK_UP:
            head_info->wait = 30;
            switch(head_info->head_config){
                case 4://is left
                case 6://is right walking
                    SetSpriteAnim(arg_s_cerberus, a_cerberusheadleft, 1);
                break;
                case 5://is right
                    SetSpriteAnim(arg_s_cerberus, a_cerberusheadright, 1);
                break;
            }
        break;
        case HIT:
            head_info->wait = 100;
            e_change_state(s_skeletoncerberus, DIE);
            SetSpriteAnim(arg_s_cerberus, a_cerberusheadleft_hit, 40u);
            boss_hp_current--;
            redraw_hud = 1;
            if(head_info->head_config == 6){
                SpriteManagerRemoveSprite(arg_s_cerberus);
            }
        break;
        case WALK_DOWN:
            switch(head_info->head_config){
                case 4://is left
                case 6://is right walking
                    SetSpriteAnim(arg_s_cerberus, a_cerberusheadleft_attack, 1);
                break;
                case 5:{//is right
                    head_info->wait = 100;
                    SetSpriteAnim(arg_s_cerberus, a_cerberusheadright_walkdown, 1);
                    Sprite* s_righthead_walking = SpriteManagerAdd(SpriteCerberushead, arg_s_cerberus->x + 8, arg_s_cerberus->y + 4);
                    struct CerberusInfo* headright_info = (struct CerberusInfo*)s_righthead_walking->custom_data;
                    headright_info->head_config = 6;
                    cerberus_change_state(s_righthead_walking, WALK_DOWN);
                }break;
            }
        break;
        case DIE:
            if(head_info->head_config == 4){
                SetSpriteAnim(arg_s_cerberus, a_cerberushead_dead, 1);
            }
        break;
    }
    head_info->e_state = arg_new_state;
}

void cerberus_calculate_note_v(Sprite* arg_s_cerberus, INT8* arg_vx, INT8* arg_vy) BANKED{
    INT16 delta_x = (INT16)arg_s_cerberus->x - (INT16)s_orpheus->x;
    if(delta_x < 0){
        delta_x = -delta_x;
    }
    if(delta_x > 16){
        *arg_vx = -2;
        *arg_vy = 2;
    }else if(delta_x > 8){
        *arg_vx = -1;
        *arg_vy = 3;
    }else if(delta_x > 4){
        *arg_vx = -1;
        *arg_vy = 4;
    }
    if(arg_s_cerberus->x < s_orpheus->x){
        *arg_vx = -*arg_vx;
        *arg_vy = *arg_vy;
    }
}

void cerberus_update_wait(Sprite* arg_cerberus_head) BANKED{
    struct CerberusInfo* head_info = (struct CerberusInfo*)arg_cerberus_head->custom_data;
    switch(head_info->head_config){
        case 4://is left
            head_info->wait = ATTACK_WAIT_MAX;
            switch(boss_hp_current){
                case 4: case 3:
                    head_info->wait = ATTACK_WAIT_MED;
                break;
                case 2: case 1:
                    head_info->wait = ATTACK_WAIT_MIN;
                break;
            }
        break;
        case 5://is center
            head_info->wait = ATTACK_WAIT_MAX_RIGHT;
            switch(boss_hp_current){
                case 4: case 3:
                    head_info->wait = ATTACK_WAIT_MED_RIGHT;
                break;
                case 2: case 1:
                    head_info->wait = ATTACK_WAIT_MIN_RIGHT;
                break;
            }
        break;
    }
}

void DESTROY() {
}