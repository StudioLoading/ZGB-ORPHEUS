#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"


const UINT8 a_fireball[] = {1, 1};

INT8 fireball_mirroring = 10;
UINT8 spawned_ball = 0u;

extern UINT8 is_skeletoncerberus_in_river;
extern AEACUS_PHASE aeacus_phase;
extern Sprite* s_awacus_body;
extern AEACUS_PHASE aeacus_phase;
extern UINT8 flag_paused;
extern UINT16 saved_orpheus_posx;
extern UINT16 saved_orpheus_posy;

extern void e_destroy(Sprite* s_enemy) BANKED;
extern void orpheus_change_state(Sprite* arg_s_orpheus, SPRITE_STATES arg_new_state) BANKED;
extern UINT8 is_enemy(UINT8 arg_sprite_type) BANKED;
extern UINT8 is_boss(UINT8 arg_sprite_type) BANKED;
extern void boss_hit() BANKED;
extern AEACUS_PHASE aea_move_to_hit(Sprite* arg_s_aeacusbody) BANKED;
extern UINT8 aeacusbody_move_to_point(Sprite* aea_s_aeacusbody, UINT16 arg_final_posx, UINT16 arg_final_posy) BANKED;

void START() {
    THIS->lim_x = 10u;
    THIS->lim_y = 10u;
    SetSpriteAnim(THIS, a_fireball, 24u);
    fireball_mirroring = 10;    
    struct EnemyInfo* fireball_data = (struct EnemyInfo*) THIS->custom_data;
    fireball_data->e_state = GENERIC_IDLE;
    fireball_data->e_configured = 0u;
    fireball_data->vx = 0;
    fireball_data->vy = 0;
    spawned_ball = 1u;
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
    if(flag_paused){ return; }
    struct EnemyInfo* fireball_data = (struct EnemyInfo*) THIS->custom_data;
    switch(fireball_data->e_configured){
        case 0: return; break;
        case 2://stone transformed into a fireball!
        case 1:{//vx and vy to be set externally
            fireball_mirroring--;
            if(fireball_mirroring <= 0){
                if(THIS->mirror == NO_MIRROR ){
                    THIS->mirror = V_MIRROR;
                    if(fireball_data->e_configured < 2){//if it's not superfireball
                        if(_cpu != CGB_TYPE){
                            SPRITE_SET_PALETTE(THIS,0);
                        }
                    }
                }else{
                    THIS->mirror = NO_MIRROR;
                    if(_cpu != CGB_TYPE){
                        SPRITE_SET_PALETTE(THIS,1);
                    }
                }
                fireball_mirroring = 10;
            }
            UINT8 t_fireball_coll = 0u;
            switch(fireball_data->e_state){
                case GENERIC_IDLE:{
                    t_fireball_coll = TranslateSprite(THIS,fireball_data->vx << delta_time, fireball_data->vy << delta_time);
                }break;
                case MOVE_TO_SAVED_ORPHEUS:{
                    fireball_data->wait = aeacusbody_move_to_point(THIS, saved_orpheus_posx, saved_orpheus_posy);
                    if(fireball_data->wait){
                        fireball_data->e_state = GENERIC_IDLE;
                    }
                }break;
            }
            if(t_fireball_coll){
                THIS->x += fireball_data->vx;
                THIS->y += fireball_data->vy;
            }else{
            //SPRITE COLLISION
                UINT8 scroll_fb_tile;
                Sprite* ifbspr;
                SPRITEMANAGER_ITERATE(scroll_fb_tile, ifbspr) {
                    if(CheckCollision(THIS, ifbspr)) {
                        if(ifbspr->type == SpriteOrpheus){
                            orpheus_change_state(ifbspr, HIT);
                        }else if(is_boss(ifbspr->type)){
                            if(ifbspr->type == SpriteAeacusbody){
                                aeacus_phase = aea_move_to_hit(s_awacus_body);
                            }else{
                                boss_hit();
                            }
                        }else if(is_enemy(ifbspr->type)){
                            if(ifbspr->type == SpriteSkeletoncerberus && is_skeletoncerberus_in_river == 0){

                            }else{
                                e_destroy(ifbspr);
                            }
                        }
                    }
                }
            }
        }break;
    }
}

void DESTROY() {
    spawned_ball = 0u;
}