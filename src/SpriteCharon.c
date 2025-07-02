#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

#define CHARON_ATTACK_MAX 200
#define CHARON_ATTACK_MED 120
#define CHARON_ATTACK_MIN 80

#define CHARON_PREATTACK_MAX 16
#define CHARON_PREATTACK_MED 8
#define CHARON_PREATTACK_MIN 2

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
INT8 charon_vx = 0;
INT8 charon_vy = 0;
UINT8 charon_walking_frmskip_x_current = 0u;
UINT8 charon_walking_frmskip_y_current = 0u;
INT16 delta_walking_delta_x = 0;
INT16 delta_walking_delta_y = 0;
struct EnemyInfo* charonlefthand_data;
struct EnemyInfo* charonrighthand_data;

extern INT8 boss_hp_max;
extern INT8 boss_hp_current;

void charon_change_state(SPRITE_STATES arg_new_state) BANKED;
void charon_preattack_move() BANKED;

void START() {
    boss_hp_max = 5;
    boss_hp_current = 5;
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
                charon_attack_current++;
                if(charon_attack_current > charon_attack_max){
                    charon_change_state(PREATTACK_DOWN);
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
            break;
            case PREATTACK_DOWN: //move to 68;30
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
                    //MOVING TO KNOWN POINT
                    charon_preattack_move();
                }
                INT16 delta_final_x = (INT16)THIS->x - (INT16)charon_attack_posx;
                INT16 delta_final_y = (INT16)THIS->y - (INT16)charon_attack_posy;
                if((delta_final_x < 3 && delta_final_x > -3 && 
                    ((delta_final_y < 3 && delta_final_y > -3)) || THIS->y < 24u)){
                    charon_change_state(PREATTACK_UP);
                }
            break;
            case PREATTACK_UP:
                if(charonlefthand_data->e_configured == 3 && 
                    charonrighthand_data->e_configured == 3){
                        charonlefthand_data->e_configured = 0;
                        charonrighthand_data->e_configured = 0;
                        charon_change_state(ATTACK);
                    }
            break;
        }
}

void charon_preattack_move() BANKED{
    INT8 delta_walking_delta_x_verse = 1;
    if(THIS->x > charon_attack_posx){
        delta_walking_delta_x_verse = -1;
    }
    INT8 delta_walking_delta_y_verse = -1;
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
    if(charon_walking_frmskip_x_max > 0 && charon_walking_frmskip_x_current < charon_walking_frmskip_x_max){//ecco che devo fare una y
        actual_charon_vx = 0;
    }
    if(charon_walking_frmskip_y_max > 0 && charon_walking_frmskip_y_current < charon_walking_frmskip_y_max){
        actual_charon_vy = 0;
    }
    if(charon_walking_frmskip_x_current == charon_walking_frmskip_x_max){
        charon_walking_frmskip_x_current = 0;
    }
    if(charon_walking_frmskip_y_current == charon_walking_frmskip_y_max){
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
        case PREATTACK_DOWN://move to preattack position
        break;
        case GENERIC_WALK:// move left-right
        break;
        case PREATTACK_UP://make hands loop
            switch(boss_hp_current){
                case 5: case 4: case 2:
                    charonlefthand_data->frmskip_wait = 200;
                    charonrighthand_data->frmskip_wait = 160;
                break;
                case 1: case 3:
                    charonlefthand_data->frmskip_wait = 160;
                    charonrighthand_data->frmskip_wait = 100;
                break;
            }
        break;
    }
    charon_info.e_state = arg_new_state;
}

void DESTROY() {
}