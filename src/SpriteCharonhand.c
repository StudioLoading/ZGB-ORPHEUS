#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"
#include "CircleMath.h"

extern INT8 boss_hp_max;
extern INT8 boss_hp_current;
extern struct CharonInfo charon_info;
extern Sprite* s_orpheus;
extern Sprite* s_charon;
extern UINT8 charon_attack_type;

const UINT8 a_charonhand[] = {1, 1};
const UINT8 a_charonhand_blink[] = {2, 0,1};

extern void orpheus_change_state(Sprite* arg_s_orpheus, SPRITE_STATES arg_new_state) BANKED;
extern void spawn_death_animation(UINT16 spawnx, UINT16 spawny) BANKED;


void START() {
    struct EnemyInfo* charonhand_data = (struct EnemyInfo*)THIS->custom_data;
    charonhand_data->wait = 0u;
    charonhand_data->e_configured = 0u;
    SetSpriteAnim(THIS, a_charonhand, 1u);
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
    if(THIS->x < 8){ THIS->x = 8u; }
    if(THIS->x > 150){ THIS->x = 150u; }
    if(THIS->y < 4){ THIS->y = 4u; }
    if(THIS->y > 137){ THIS->y = 137u;}
    struct EnemyInfo* charonhand_data = (struct EnemyInfo*)THIS->custom_data;
    switch(charon_info.e_state){
        case PREATTACK_UP:{
            if(charonhand_data->frmskip == 0){//right hand
                THIS->lim_x = THIS->x - 8;
            }else{
                THIS->lim_x = THIS->x + 12;
            }
            THIS->lim_y = THIS->y;
            UINT8 cos_position = charonhand_data->wait + 64u;
            THIS->x = THIS->lim_x + ((sine_wave[cos_position]) >> 3) - 2;
            THIS->y = THIS->lim_y + ((sine_wave[charonhand_data->wait]) >> 3) - 2;
            if(charonhand_data->frmskip == 0){//right hand, moves counterclock
                charonhand_data->wait -= (12 / boss_hp_current);
            }else{
                charonhand_data->wait += (12 / boss_hp_current);
            }
        }break;
        case PREATTACK_DOWN:{
            switch(charonhand_data->e_configured){
                case 0:{
                    if(charonhand_data->frmskip == 0){//right hand
                	    THIS->lim_x = THIS->x - 8;
                    }else{
                        THIS->lim_x = THIS->x + 12;
                    }
		            THIS->lim_y = THIS->y;
                    charonhand_data->e_configured = 1;
                }
                break;
                case 1:{
                    UINT8 cos_position = charonhand_data->wait + 64u;
                    THIS->x = THIS->lim_x + ((sine_wave[cos_position]) >> 3) - 2;
                    THIS->y = THIS->lim_y + ((sine_wave[charonhand_data->wait]) >> 3) - 2;
                    if(charonhand_data->frmskip == 0){//right hand, moves counterclock
                        charonhand_data->wait -= (12 / boss_hp_current);
                    }else{
                        charonhand_data->wait += (12 / boss_hp_current);
                    }
                    charonhand_data->frmskip_wait--;
                    INT16 hand_orpheus_deltax = (INT16)THIS->x - (INT16)s_orpheus->x;
                    //RESTORE POSITION
                    if(charonhand_data->frmskip_wait == 0 || (charonhand_data->frmskip_wait < 20 && hand_orpheus_deltax < 2)){
                        if(charonhand_data->frmskip == 0){//right hand
                            THIS->x = THIS->lim_x + 8u;
                        }else{
                            THIS->x = THIS->lim_x -12u;
                        }
                        THIS->y = THIS->lim_y;
                        SetSpriteAnim(THIS, a_charonhand_blink, 24u);
                        charonhand_data->frmskip_wait = 80u;
                        if(boss_hp_current < 3){charonhand_data->frmskip_wait = 40u;}
                        charonhand_data->e_configured = 2;
                    }
                }
                break;
                case 2:
                    charonhand_data->frmskip_wait--;
                    if(charonhand_data->frmskip_wait == 0){
                        charonhand_data->e_configured = 3;//READY TO ATTACK!
                    }
                break;
            }
        }break;
        case ATTACK:{
            switch(charonhand_data->e_configured){
                case 0:
                    SetSpriteAnim(THIS, a_charonhand, 1u);
                    THIS->lim_x = THIS->x;//save final attack position
                    THIS->lim_y = THIS->y;
                    charonhand_data->e_configured = 1;
                break;
                case 1:{
                    switch(charon_attack_type){
                        case 0:
                            charonhand_data->vy = 1;
                            charonhand_data->vx = 0;
                        break;
                        case 1:
                            charonhand_data->vy = 2;
                            charonhand_data->vx = -1;
                            if(charonhand_data->frmskip == 0){//right hand
                                charonhand_data->vx = 1;
                            }
                        break;
                        case 2:
                            charonhand_data->vy = 3;
                            charonhand_data->vx = 0;
                        break;
                        case 3:
                            charonhand_data->vy = 3;
                            charonhand_data->vx = -2;
                            if(charonhand_data->frmskip == 0){//right hand
                                charonhand_data->vx = 2;
                            }
                        break;
                        case 4:
                            charonhand_data->vy = 4;
                            charonhand_data->vx = -2;
                            if(charonhand_data->frmskip == 0){//right hand
                                charonhand_data->vx = 2;
                            }
                        break;
                    }
                    UINT8 hand_coll = TranslateSprite(THIS, charonhand_data->vx << delta_time, charonhand_data->vy << delta_time);
                    if(hand_coll == 111u || hand_coll == 110u){
                        THIS->x += charonhand_data->vx;
                        THIS->y += charonhand_data->vy;
                    }else if(hand_coll){//THIS->y > 136u
                        charonhand_data->e_configured = 2;
                    }
                }
                break;
                case 2:{
                    if(charonhand_data->frmskip == 0){
                        THIS->x = s_charon->x + 17u;
                        THIS->y = s_charon->y+1;
                    }else{
                        THIS->x = s_charon->x - 9u;
                        THIS->y = s_charon->y+1;
                    }
                    charonhand_data->e_configured = 3;
                }
                break;
                case 3:{//attack finished, go back to charon
                }break;
            }
            //SPRITE COLLISION
            UINT8 scroll_ch_tile;
            Sprite* ichspr;
            SPRITEMANAGER_ITERATE(scroll_ch_tile, ichspr) {
                if(CheckCollision(THIS, ichspr)) {
                    switch(ichspr->type){
                        case SpriteOrpheus:{
                            orpheus_change_state(s_orpheus, HIT);
                        }break;
                        case SpriteItem:{
                            SpriteManagerRemoveSprite(ichspr);
                            boss_hp_current = boss_hp_max;
                            spawn_death_animation(THIS->x + 8u, THIS->y + 20u);
                        }break;
                    }
                }
            }
        }break;
    }
}

void DESTROY() {
}