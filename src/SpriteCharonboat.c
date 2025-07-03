#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

#define BOAT_COUNT_MAX 80
#define BOAT_FRMSKIP_MAX 1
#define BOAT_FRMSKIP_MID 2
#define BOAT_FRMSKIP_LOW 3


const UINT8 a_charonboat[] = {1, 1};
const UINT8 a_charonboat_blink[] = {2, 0,1};

UINT8 boat_count = 0u;
INT8 boat_vx = 1;
INT8 boat_vy = 0;
UINT16 boat_walk_right_limit = 103u;
UINT16 boat_walk_left_limit = 32u;
INT8 boat_frmskip = 0;
INT8 boat_frmskip_max = 0;

extern Sprite* s_charon;
extern struct CharonInfo charon_info;
extern UINT8 boss_intro;
extern INT8 boss_hp_current;

void boat_turn() BANKED;


void START() {
    SetSpriteAnim(THIS, a_charonboat, 1u);
    boat_frmskip_max = BOAT_FRMSKIP_LOW;
    boat_frmskip = boat_frmskip_max;
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
    //FLOATING
        boat_count++;
        if(boat_count > BOAT_COUNT_MAX){
            boat_count = 0;
        }
        switch(boat_count){
            case 40:
                THIS->y++;
            break;
            case 80:
                THIS->y--;
            break;
        }
        if(boss_intro < 3){return;}
        if(charon_info.e_state == HIT){
            SetSpriteAnim(THIS, a_charonboat_blink, 30u);
        }else{
            SetSpriteAnim(THIS, a_charonboat, 1u);
        }
        if(charon_info.e_state != GENERIC_WALK){
            THIS->x = s_charon->x - 4u;
            THIS->y = s_charon->y + 16u; 
            return;
        }
    //HORIZONTAL MOVEMENT
        if(THIS->x > boat_walk_right_limit){
            boat_turn();
            THIS->x = boat_walk_right_limit;
        }
        if(THIS->x < boat_walk_left_limit){
            boat_turn();
            THIS->x = boat_walk_left_limit;
        }
    //boat_frmskip_max
        if(boss_hp_current == 4){
            boat_frmskip_max = BOAT_FRMSKIP_MID;
        }else if(boss_hp_current > 2){
            boat_frmskip_max = BOAT_FRMSKIP_MAX;
        }else{//speed up the boat!
            boat_frmskip_max = BOAT_FRMSKIP_MAX;
            //boat_vx = boat_vx * 2;
        }
    //TRANSLATION
        boat_frmskip--;
        if(boat_frmskip <= 0){
            UINT8 boat_tile_coll = TranslateSprite(THIS, boat_vx << delta_time, boat_vy << delta_time);
            boat_frmskip = boat_frmskip_max;
        }
}

void boat_turn() BANKED{
    boat_vx = -boat_vx;
}

void DESTROY() {
}