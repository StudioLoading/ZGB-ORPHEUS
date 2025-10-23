#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "BankManager.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"


const UINT8 i_death_skull[] = {6, 1,2,3,4,5,6};
const UINT8 i_death_puff[] = {3, 4,5,6};

Sprite* s_puff_left_0 = 0;
Sprite* s_puff_left_1 = 0;
Sprite* s_puff_right_0 = 0;
Sprite* s_puff_right_1 = 0;
UINT8 init_puffs = 0u;

void death_check_collision(Sprite* arg_s_death) BANKED;

extern Sprite* s_orpheus;
extern void orpheus_change_state(Sprite* arg_s_orpheus, SPRITE_STATES arg_new_state) BANKED;
extern void radamanthus_hit(Sprite* s_enemy) BANKED;


void START() {
    struct EnemyInfo* d_data = (struct EnemyInfo*) THIS->custom_data;
    d_data->frmskip = 0;
    d_data->frmskip_wait = 3;
    d_data->wait = 0u;
    d_data->vx = 0u;
    d_data->vy = 0u;
    if(init_puffs == 0u){
        init_puffs = 1u;
        s_puff_left_0 = SpriteManagerAdd(SpriteDeath, THIS->x-4, THIS->y);
        struct EnemyInfo* pl0_data = (struct EnemyInfo*)s_puff_left_0->custom_data;
        pl0_data->tile_collision = DEATH_PUFF_LEFT_0;
        pl0_data->e_configured = 1u;
        s_puff_right_0 = SpriteManagerAdd(SpriteDeath, THIS->x+4, THIS->y);
        struct EnemyInfo* pr0_data = (struct EnemyInfo*)s_puff_right_0->custom_data;
        pr0_data->tile_collision = DEATH_PUFF_RIGHT_0;
        pr0_data->e_configured = 1u;
        if(_cpu == CGB_TYPE){
            s_puff_right_1 = SpriteManagerAdd(SpriteDeath, THIS->x+4, THIS->y - 4);
            struct EnemyInfo* pr1_data = (struct EnemyInfo*)s_puff_right_1->custom_data;
            pr1_data->tile_collision = DEATH_PUFF_RIGHT_1;
            pr1_data->e_configured = 1u;
            s_puff_left_1 = SpriteManagerAdd(SpriteDeath, THIS->x-4, THIS->y - 4);
            struct EnemyInfo* pl1_data = (struct EnemyInfo*)s_puff_left_1->custom_data;
            pl1_data->tile_collision = DEATH_PUFF_LEFT_1;
            pl1_data->e_configured = 1u;
        }    
    }
    if(_cpu != CGB_TYPE){
        OBP1_REG = PAL_DEF(0, 0, 1, 3);
        SPRITE_SET_PALETTE(THIS,1);
    }
}

void UPDATE() {
    struct EnemyInfo* d_data = (struct EnemyInfo*) THIS->custom_data;
    d_data->frmskip++;
    if(d_data->frmskip < d_data->frmskip_wait){
        return;
    }
    switch(d_data->e_configured){
        case 0u: //do nothing
            return;
        break;
        case 1u: //set animation
            switch(d_data->tile_collision){
                case DEATH_SKULL:
                    SetSpriteAnim(THIS, i_death_skull, 2u);
                break;
                case DEATH_PUFF_LEFT_0:
                case DEATH_PUFF_LEFT_1:
                case DEATH_PUFF_RIGHT_0:
                case DEATH_PUFF_RIGHT_1:
                    SetSpriteAnim(THIS, i_death_puff, 4u);
                break;
            }
            d_data->e_configured = 2u;
        break;
        case 2u: //behave
            switch(d_data->tile_collision){
                case DEATH_SKULL:
                    if(d_data->wait < 4u){
                        d_data->vy = -2;
                    }else if(d_data->wait < 6u){
                        d_data->vy = -1;
                    }else if(d_data->wait < 12u){
                        d_data->vy = 0;
                    }else if(d_data->wait < 14u){
                        d_data->vy = 1;
                    }else if(d_data->wait < 17u){
                        d_data->vy = 1;
                    }else{
                        d_data->e_configured = 3u;
                    }
                    THIS->y += d_data->vy;
                break;
                case DEATH_PUFF_LEFT_0:
                    if(d_data->wait < 4u){
                        d_data->vx = -1;
                        d_data->vy = -2;
                    }else if(d_data->wait < 6u){
                        d_data->vy = -1;
                    }else if(d_data->wait < 12u){
                        d_data->vx = -0;
                        d_data->vy = 0;
                    }else if(d_data->wait < 14u){
                        d_data->vx = 0;
                        d_data->vy = 1;
                    }else if(d_data->wait < 18u){
                        d_data->vx = -1;
                        d_data->vy = 2;
                    }else{
                        d_data->e_configured = 3u;
                    }
                break;
                case DEATH_PUFF_LEFT_1:
                    if(d_data->wait < 4u){
                        d_data->vx = 0;
                        d_data->vy = -2;
                    }else if(d_data->wait < 6u){
                        d_data->vx = -1;
                        d_data->vy = -1;
                    }else if(d_data->wait < 12u){
                        d_data->vx = -0;
                        d_data->vy = 0;
                    }else if(d_data->wait < 14u){
                        d_data->vx = -1;
                        d_data->vy = 1;
                    }else if(d_data->wait < 18u){
                        d_data->vx = 0;
                        d_data->vy = 2;
                    }else{
                        d_data->e_configured = 3u;
                    }
                break;
                case DEATH_PUFF_RIGHT_0:
                    if(d_data->wait < 4u){
                        d_data->vx = 1;
                        d_data->vy = -2;
                    }else if(d_data->wait < 6u){
                        d_data->vy = -1;
                    }else if(d_data->wait < 12u){
                        d_data->vx = 0;
                        d_data->vy = 0;
                    }else if(d_data->wait < 14u){
                        d_data->vx = 0;
                        d_data->vy = 1;
                    }else if(d_data->wait < 18u){
                        d_data->vx = 1;
                        d_data->vy = 2;
                    }else{
                        d_data->e_configured = 3u;
                    }
                break;
                case DEATH_PUFF_RIGHT_1:
                    if(d_data->wait < 4u){
                        d_data->vx = 0;
                        d_data->vy = -2;
                    }else if(d_data->wait < 6u){
                        d_data->vx = 1;
                        d_data->vy = -1;
                    }else if(d_data->wait < 12u){
                        d_data->vx = -0;
                        d_data->vy = 0;
                    }else if(d_data->wait < 14u){
                        d_data->vx = 1;
                        d_data->vy = 1;
                    }else if(d_data->wait < 18u){
                        d_data->vx = 0;
                        d_data->vy = 2;
                    }else{
                        d_data->e_configured = 3u;
                    }
                break;
            }
            THIS->x += d_data->vx;
            THIS->y += d_data->vy;
            death_check_collision(THIS);
        break;
        case 3u: //remove
            SpriteManagerRemoveSprite(THIS);
        break;
    }
    d_data->frmskip = 0;
    d_data->wait++;
}

void death_check_collision(Sprite* arg_s_death) BANKED{
    UINT8 scroll_abl_tile;
    Sprite* iablspr;
    SPRITEMANAGER_ITERATE(scroll_abl_tile, iablspr) {
        if(CheckCollision(arg_s_death, iablspr)) {
            switch(iablspr->type){
                case SpriteOrpheus:
                case SpriteOrpheuslyre:
                    orpheus_change_state(s_orpheus, HIT);
                break;
                case SpriteRadamanthus:
                    radamanthus_hit(iablspr);
                break;
            }
        }
    }
}

void DESTROY() {
    init_puffs = 0u;
}